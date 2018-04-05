open Utils;

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
    ]);
  let zoom =
    style([
      left(em(2.)),
      backgroundColor(hex("00d742")),
      borderColor(hex("049931")),
    ]);
  let quit =
    style([
      left(em(2.)),
      backgroundColor(hex("red")),
      borderColor(hex("049931")),
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
  | Default;

type state = {text: string};

let component = ReasonReact.reducerComponent("Terminal");

type selfType = ReasonReact.self(state, ReasonReact.noRetainedProps, action);

let make = _children => {
  let handleChange = (event, self: selfType) =>
    event |> getText |> (text => self.send(Change(text)));
  {
    ...component,
    initialState: () => {text: ""},
    reducer: (action, _state) =>
      switch (action) {
      | Default => ReasonReact.Update({text: Shell.showPrompt()})
      | Change(text) => ReasonReact.Update({text: text})
      },
    render: self =>
      <div className=Styles.container>
        <header className=Styles.header>
          <div className=Styles.buttonContainer>
            <button
              className=(
                CommonStyles.combineClasses([Styles.quit, Styles.buttons])
              )
            />
            <button
              className=(
                CommonStyles.combineClasses([Styles.minimize, Styles.buttons])
              )
            />
            <button
              className=(
                CommonStyles.combineClasses([Styles.zoom, Styles.buttons])
              )
            />
          </div>
          (str("Bash"))
        </header>
        <div className=Styles.content>
          <div> (str(Shell.showPrompt())) </div>
          <input
            className=Styles.input
            value=self.state.text
            onChange=(evt => handleChange(evt, self))
          />
        </div>
      </div>,
  };
};
