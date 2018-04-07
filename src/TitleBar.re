open Css;

open Utils;

let component = ReasonReact.statelessComponent("Titlebar");

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

let make = (_) => {
  ...component,
  render: (_) =>
    <header className=header>
      <div className=buttonContainer>
        <button className=(CommonStyles.combineClasses([quit, buttons]))>
          (str("x"))
        </button>
        <button className=(CommonStyles.combineClasses([minimize, buttons]))>
          (str("-"))
        </button>
        <button className=(CommonStyles.combineClasses([zoom, buttons]))>
          (str("+"))
        </button>
      </div>
      (str("Bash"))
    </header>,
};
