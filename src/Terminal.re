open Utils;

open Shell;

module Styles = {
  open Css;
  let container =
    style([
      height(`percent(40.)),
      width(`percent(50.)),
      margin(em(1.)),
      paddingBottom(em(1.)),
    ]);
  let content =
    style([
      width(`percent(100.)),
      backgroundColor(purple),
      height(`percent(100.)),
      borderBottomLeftRadius(px(5)),
      borderBottomRightRadius(px(5)),
      padding(em(1.0)),
      boxSizing(borderBox),
      overflow(scroll),
    ]);
  let input =
    style([
      borderWidth(zero),
      fontSize(em(1.)),
      backgroundColor(`transparent),
      color(white),
      outlineStyle(none),
    ]);
  let inputContainer = style([marginTop(em(1.)), marginBottom(em(1.))]);
};

type action =
  | Focus
  | Change(string)
  | KeyDown(int);

type state = {
  input: string,
  history: list(prompts),
  currentId: int,
  focusedPromptRef: ref(option(Dom.element)),
};

type selfType = ReasonReact.self(state, ReasonReact.noRetainedProps, action);

let component = ReasonReact.reducerComponent("Terminal");

let setFocusedRef = (r, {ReasonReact.state}) =>
  state.focusedPromptRef := Js.Nullable.toOption(r);

let updateHistory = state =>
  List.map(
    prompt =>
      prompt.id === state.currentId ?
        {...prompt, text: [|state.input|]} : prompt,
    state.history,
  );

/* Side Effect Ahoy */
let scrollIntoView = el =>
  switch (el) {
  | Some(el) => getElement(el)##scrollIntoView()
  | None => ()
  };

let focusElement = el =>
  switch (el) {
  | Some(el) => getElement(el)##focus()
  | None => ()
  };

/* ******************************* */
let make = _children => {
  let handleChange = (element, self: selfType) =>
    element |> getText |> (text => self.send(Change(text)));
  let handleSubmit = (text: string, arg: string, state) => {
    let result = parseInput(text, arg);
    let newHistory = updateHistory(state);
    let outputId = state.currentId + 1;
    switch (result) {
    | ShellReset(reset) =>
      ReasonReact.Update({
        currentId: 1,
        history: reset,
        input: "",
        focusedPromptRef: ref(None),
      })
    | ShellSuccess(result) =>
      ReasonReact.Update({
        ...state,
        currentId: outputId + 1,
        input: "",
        history: [
          {text: [|""|], id: outputId + 1, error: None, exitCode: None},
          {text: result, error: None, id: outputId, exitCode: Some(0)},
          ...newHistory,
        ],
      })
    | ShellFailure(result) =>
      ReasonReact.Update({
        ...state,
        input: "",
        currentId: outputId + 1,
        history: [
          {text: [|""|], id: outputId + 1, error: None, exitCode: None},
          {
            text: [|""|],
            id: outputId,
            error: Some(result),
            exitCode: Some(1),
          },
          ...newHistory,
        ],
      })
    };
  };
  let handleKeyInput = (state: state, key: int) => {
    let {currentId, history} = state;
    /* the 0-index access is to convert a string to a "char" type */
    let result = split_on_char(" ".[0], state.input);
    switch (key, result) {
    | (13, [""])
    | (13, []) =>
      ReasonReact.Update({
        ...state,
        currentId: currentId + 1,
        history: [
          {text: [|""|], id: currentId + 1, error: None, exitCode: None},
          ...history,
        ],
      })
    | (13, [text, arg]) => handleSubmit(text, arg, state)
    | (13, [text]) => handleSubmit(text, "", state)
    | _ => ReasonReact.NoUpdate
    };
  };
  {
    ...component,
    initialState: () => {
      input: "",
      history: [
        {
          text: [|
            "Find out more about me, use the 'help' command to learn more",
          |],
          id: 1,
          error: None,
          exitCode: None,
        },
      ],
      currentId: 1,
      focusedPromptRef: ref(None),
    },
    didUpdate: ({newSelf}) =>
      scrollIntoView(newSelf.state.focusedPromptRef^),
    reducer: (action, state) =>
      switch (action) {
      | Change(text) => ReasonReact.Update({...state, input: text})
      | KeyDown(key) => handleKeyInput(state, key)
      | Focus =>
        ReasonReact.SideEffects(
          (({state}) => focusElement(state.focusedPromptRef^)),
        )
      },
    render: self =>
      <div
        className=Styles.container
        onKeyDown=(
          event => self.send(KeyDown(ReactEventRe.Keyboard.which(event)))
        )>
        <TitleBar />
        <div className=Styles.content>
          (
            List.map(
              ({exitCode, text, error}) =>
                <div>
                  (
                    switch (exitCode) {
                    | Some(_exitCode) => ReasonReact.nullElement
                    | None => str(showPrompt())
                    }
                  )
                  <div> (renderText(text, Styles.inputContainer)) </div>
                  (
                    switch (error) {
                    | Some(error) => <p> (str("Error: " ++ error)) </p>
                    | None => ReasonReact.nullElement
                    }
                  )
                </div>,
              self.state.history,
            )
            |> List.rev
            |> Array.of_list
            |> ReasonReact.arrayToElement
          )
          <input
            ref=(self.handle(setFocusedRef))
            onBlur=(_evt => self.send(Focus))
            className=Styles.input
            value=self.state.input
            onChange=(evt => handleChange(evt, self))
            autoFocus=Js.true_
          />
        </div>
      </div>,
  };
};
