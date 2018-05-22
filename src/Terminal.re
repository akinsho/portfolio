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
      boxShadow(~x=px(-2), ~y=px(-2), ~blur=px(5), rgba(0, 0, 0, 0.5)),
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
  let prompt = style([color(deepskyblue), marginRight(em(0.2))]);
  let inputContainer = style([marginTop(em(1.)), marginBottom(em(1.))]);
};

type action =
  | Focus
  | Change(string)
  | KeyDown(int);

type state = {
  shell: string,
  input: string,
  history: list(prompts),
  currentId: int,
  focusedPromptRef: ref(option(Dom.element)),
};

type selfType = ReasonReact.self(state, ReasonReact.noRetainedProps, action);

let component = ReasonReact.reducerComponent("Terminal");

let setFocusedRef = (r, {ReasonReact.state}) =>
  state.focusedPromptRef := Js.Nullable.toOption(r);

let showLastHistoryItem = history => {
  let length = List.length(history);
  List.nth(history, length - 1);
};

let savePromptText = state =>
  List.map(
    prompt =>
      prompt.id === state.currentId ? {...prompt, cmd: state.input} : prompt,
    state.history,
  );

let updateHistory = (~state, ~id, prevCmdStatus, cmd) =>
  state
  |> savePromptText
  |> (history => newPrompt(~history, prevCmdStatus, id, cmd));

let showHelp = history =>
  List.length(history) >= 1 ?
    ReasonReact.null :
    str(
      {|So, I'm a terminal nerd..
        if you wanna to know a little bit more about me..
          try some commands out,
          if you're stuck try the "help" command|},
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

let make = _children => {
  let handleChange = (element, self: selfType) =>
    element |> getText |> (text => self.send(Change(text)));
  let handleSubmit = (text: string, arg: string, state) => {
    let cmd = text ++ " " ++ arg;
    let id = state.currentId + 1;
    let result = parseInput(text, arg);
    switch (result) {
    | ChangeShell(shell) =>
      ReasonReact.Update({
        ...state,
        shell,
        input: "",
        history: updateHistory(~state, ~id, ChangeShell(shell), cmd),
      })
    | ShellReset(reset) =>
      ReasonReact.Update({...state, currentId: 1, history: reset, input: ""})
    | ShellSuccess(result) =>
      ReasonReact.Update({
        ...state,
        currentId: id + 1,
        input: "",
        history: updateHistory(~state, ~id, ShellSuccess(result), cmd),
      })
    | ShellFailure(result) =>
      ReasonReact.Update({
        ...state,
        input: "",
        currentId: id + 1,
        history: updateHistory(~state, ~id, ShellFailure(result), cmd),
      })
    };
  };
  let handleKeyInput = (state, key: int) => {
    let {currentId, history} = state;
    /* the 0-index access is to convert a string to a "char" type */
    let result = split_on_char(" ".[0], state.input);
    switch (key, result) {
    | (38, _) =>
      history
      |> showLastHistoryItem
      |> (
        item =>
          ReasonReact.Update({...state, input: Js.Array.join(item.text)})
      )
    | (13, [""])
    | (13, []) =>
      ReasonReact.Update({
        ...state,
        currentId: currentId + 1,
        history: [
          {
            text: [|""|],
            id: currentId + 1,
            error: None,
            exitCode: None,
            cmd: "",
          },
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
      shell: "bash",
      input: "",
      history: [],
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
      <div className=Styles.container>
        <TitleBar shell=self.state.shell />
        /* Render Prompt then input then output */
        <div className=Styles.content>
          <p> (showHelp(self.state.history)) </p>
          (
            List.map(
              /* TODO: Use exit code to color text  */
              ({text, error}) =>
                <div>
                  <span className=Styles.prompt> (str(showPrompt())) </span>
                  <div> (renderText(text, Styles.inputContainer)) </div>
                  (
                    switch (error) {
                    | Some(error) => <p> (str("Error: " ++ error)) </p>
                    | None => ReasonReact.null
                    }
                  )
                </div>,
              self.state.history,
            )
            |> List.rev
            |> Array.of_list
            |> ReasonReact.array
          )
          <label
            onKeyDown=(
              event =>
                self.send(KeyDown(ReactEventRe.Keyboard.which(event)))
            )>
            <span className=Styles.prompt> (str(showPrompt())) </span>
            <input
              ref=(self.handle(setFocusedRef))
              onBlur=(_evt => self.send(Focus))
              className=Styles.input
              value=self.state.input
              onChange=(evt => handleChange(evt, self))
              autoFocus=true
              style=(restyle(~caretColor="#57D900", ()))
            />
          </label>
        </div>
      </div>,
  };
};
