open Utils;

open Shell;

module Styles = {
  open Css;
  let container =
    style([
      height(`percent(40.)),
      width(`percent(50.)),
      margin(em(1.)),
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
    ]);
  let buttonContainer = style([left(zero), position(absolute)]);
  let buttons =
    style([
      height(em(1.5)),
      width(em(1.5)),
      borderRadius(`percent(50.)),
      border(px(1), solid, hex("000")),
      position(relative),
      top(em(0.5)),
      left(em(1.)),
      marginRight(em(0.5)),
      backgroundColor(hex("ff3b47")),
      borderColor(hex("9d252b")),
      display(inlineBlock),
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
  history: list(prompts),
  currentId: int,
};

type selfType = ReasonReact.self(state, ReasonReact.noRetainedProps, action);

let component = ReasonReact.reducerComponent("Terminal");

let make = _children => {
  let handleChange = (event, self: selfType) =>
    event |> getText |> (text => self.send(Change(text)));
  let updateHistory = (id: int, history: list(prompts), text: string) =>
    List.map(
      prompt => prompt.id === id ? {...prompt, text} : prompt,
      history,
    );
  {
    ...component,
    initialState: () => {history: [{text: "", id: 1}], currentId: 1},
    reducer: (action, state) =>
      switch (action) {
      | Change(text) =>
        ReasonReact.Update({
          ...state,
          history: updateHistory(state.currentId, state.history, text),
        })
      | KeyDown(key) =>
        key === 13 ?
          ReasonReact.Update({
            ...state,
            history: [{text: "", id: state.currentId + 1}, ...state.history],
          }) :
          ReasonReact.NoUpdate
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
              prompt =>
                <div>
                  (str(showPrompt()))
                  <input
                    className=Styles.input
                    value=prompt.text
                    id=(string_of_int(prompt.id))
                    onChange=(evt => handleChange(evt, self))
                  />
                </div>,
              self.state.history,
            )
            |> List.rev
            |> Array.of_list
            |> ReasonReact.arrayToElement
          )
        </div>
      </div>,
  };
};
