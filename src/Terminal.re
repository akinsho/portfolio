open Utils;

open Shell;

module Styles = {
  open Css;
  let container =
    style([
      height(`percent(40.)),
      width(`percent(50.)),
      margin(em(1.)),
      paddingBottom(em(1.))
    ]);
  let header =
    style([
      width(`percent(100.)),
      height(em(1.)),
      textAlign(center),
      paddingTop(em(0.5)),
      paddingBottom(em(0.5)),
      color(black),
      backgroundColor(whitesmoke),
      borderTopLeftRadius(px(5)),
      borderTopRightRadius(px(5)),
      position(relative),
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
  let buttonContainer = style([left(zero), position(absolute)]);
  let buttons =
    style([
      height(em(1.5)),
      width(em(1.5)),
      borderRadius(`percent(50.)),
      border(px(1), solid, hex("000")),
      position(relative),
      top(em(0.3)),
      left(em(1.)),
      marginRight(em(0.5)),
      backgroundColor(hex("ff3b47")),
      borderColor(hex("9d252b")),
      display(inlineBlock),
      fontSize(em(0.6)),
      textAlign(center),
    ]);
  let minimize =
    style([
      left(em(2.)),
      backgroundColor(hex("ffc100")),
      borderColor(hex("9d802c")),
      color(transparent),
      hover([color(black)]),
    ]);
  let zoom =
    style([
      left(em(2.)),
      backgroundColor(hex("00d742")),
      borderColor(hex("049931")),
      color(transparent),
      hover([color(black)]),
    ]);
  let quit =
    style([
      left(em(2.)),
      backgroundColor(hex("red")),
      borderColor(hex("049931")),
      color(transparent),
      hover([color(black)]),
    ]);
  let input =
    style([
      borderWidth(zero),
      fontSize(em(1.)),
      backgroundColor(`transparent),
      color(white),
      outlineStyle(none),
    ]);
};

type action =
  | Change(string)
  | KeyDown(int);

type state = {
  input: string,
  history: list(prompts),
  currentId: int,
  focusedPromptRef: ref(option(ReasonReact.reactRef)),
};

type selfType = ReasonReact.self(state, ReasonReact.noRetainedProps, action);

let component = ReasonReact.reducerComponent("Terminal");

let make = _children => {
  let handleChange = (element, self: selfType) =>
    element |> getText |> (text => self.send(Change(text)));
  /* let setFocusedRef = (theRef, self: selfType) => */
  /*   self.state.focusedPromptRef := Js.Nullable.toOption(theRef); */
  let updateHistory = state =>
    List.map(
      prompt =>
        prompt.id === state.currentId ?
          {...prompt, text: state.input} : prompt,
      state.history,
    );
  let handleSubmit = (text: string, arg: string, state: state) => {
    let result = parseInput(text, arg);
    let newHistory = updateHistory(state);
    let nextId = state.currentId + 1;
    switch (result) {
    | ShellSuccess(result) =>
      ReasonReact.Update({
        ...state,
        currentId: nextId + 1,
        input: "",
        history: [
          {text: "", id: nextId + 1, error: None, exitCode: None},
          {
            text: Js.Array.join(result),
            error: None,
            id: nextId,
            exitCode: Some(0),
          },
          ...newHistory,
        ],
      })
    | ShellFailure(result) =>
      ReasonReact.Update({
        ...state,
        input: "",
        currentId: nextId + 1,
        history: [
          {text: "", id: nextId + 1, error: None, exitCode: None},
          {text: "", id: nextId, error: Some(result), exitCode: Some(1)},
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
    | (13, [text, arg]) => handleSubmit(text, arg, state)
    | (13, [text]) => handleSubmit(text, "", state)
    | (13, []) =>
      ReasonReact.Update({
        ...state,
        currentId: currentId + 1,
        history: [
          {text: "", id: currentId + 1, error: None, exitCode: None},
          ...history,
        ],
      })
    | _ => ReasonReact.NoUpdate
    };
  };
  {
    ...component,
    initialState: () => {
      input: "",
      history: [{text: "", id: 1, error: None, exitCode: None}],
      currentId: 1,
      focusedPromptRef: ref(None),
    },
    reducer: (action, state) =>
      switch (action) {
      | Change(text) => ReasonReact.Update({...state, input: text})
      | KeyDown(key) => handleKeyInput(state, key)
      },
    render: self =>
      <div
        className=Styles.container
        onKeyDown=(
          event => self.send(KeyDown(ReactEventRe.Keyboard.which(event)))
        )>
        <header className=Styles.header>
          <div className=Styles.buttonContainer>
            <button
              className=(
                CommonStyles.combineClasses([Styles.quit, Styles.buttons])
              )>
              (str("x"))
            </button>
            <button
              className=(
                CommonStyles.combineClasses([Styles.minimize, Styles.buttons])
              )>
              (str("-"))
            </button>
            <button
              className=(
                CommonStyles.combineClasses([Styles.zoom, Styles.buttons])
              )>
              (str("+"))
            </button>
          </div>
          (str("Bash"))
        </header>
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
                  <div> (str(text)) </div>
                  (
                    switch (error) {
                    | Some(error) => <p> (str(error)) </p>
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
            className=Styles.input
            value=self.state.input
            onChange=(evt => handleChange(evt, self))
          />
        </div>
      </div>,
  };
};
