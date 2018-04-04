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
      backgroundColor(whitesmoke),
      borderTopLeftRadius(px(50)),
      borderTopRightRadius(px(50)),
    ]);
  let content =
    style([
      width(`percent(100.)),
      backgroundColor(purple),
      height(`percent(100.)),
    ]);
};

let component = ReasonReact.statelessComponent("Terminal");

let make = _children => {
  ...component,
  render: _self =>
    <div className=Styles.container>
      <header className=Styles.header> (str("title")) </header>
      <div className=Styles.content> (str("text")) </div>
    </div>,
};
