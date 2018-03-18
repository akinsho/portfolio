open Utils;

let component = ReasonReact.statelessComponent("Projects");

module Styles = {
  open Css;
  let projectContainer =
    style([
      display(flexBox),
      flexDirection(column),
      justifyContent(spaceAround),
      alignItems(center),
      width(`percent(100.)),
      minHeight(`percent(100.)),
    ]);
  let pageTitle = style([fontSize(em(1.2)), marginBottom(em(0.5))]);
};

module Card = {
  open Css;
  let card =
    style([
      width(`percent(50.)),
      backgroundColor(whitesmoke),
      height(`percent(50.)),
      borderRadius(px(8)),
      color(black),
      padding(em(1.)),
    ]);
  let component = ReasonReact.statelessComponent("Card");
  let make = (~title: string, children) => {
    ...component,
    render: _self =>
      <article className=card>
        <h1> (str(title)) </h1>
        (ReasonReact.arrayToElement(children))
      </article>,
  };
};

let make = _children => {
  ...component,
  render: _self =>
    <div className=Styles.projectContainer>
      <h1 className=Styles.pageTitle> (str("Projects")) </h1>
      <Card title="Onivim"> (str("A modal editor for the modern age")) </Card>
    </div>,
};
