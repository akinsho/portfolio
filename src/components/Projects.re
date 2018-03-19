open Utils;

let onivim = requireAssetUri("./../assets/oni-logo.png");

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
  let image =
    style([
      width(em(10.)),
      height(auto),
      margin(em(1.)),
      Css.float(`left),
    ]);
  let projectDetails = style([lineHeight(1.5)]);
  let projectLine = style([margin(em(0.5))]);
};

module Card = {
  open Css;
  let card =
    style([
      width(`percent(50.)),
      backgroundColor(whitesmoke),
      height(auto),
      borderRadius(px(8)),
      color(black),
      padding(em(1.5)),
      fontSize(rem(1.2)),
    ]);
  let cardTitle = style([paddingLeft(em(2.)), margin(em(0.2))]);
  let component = ReasonReact.statelessComponent("Card");
  let make = (~title: string, children) => {
    ...component,
    render: _self =>
      <article className=card>
        <h1 className=cardTitle> (str(title)) </h1>
        (ReasonReact.arrayToElement(children))
      </article>,
  };
};

let oniDetails = {
  let details = [|
    "I collaborate on the Onivim project on github",
    "Oni is an attempt to modernise modal editing using vim",
    "whilst taking inspiration from more modern editors like vscode",
    "It uses React, Redux, RxJs, TypeScript, Electron",
  |];
  Array.mapi(
    (index, line) =>
      <p className=Styles.projectLine key=(string_of_int(index))>
        (str(line))
      </p>,
    details,
  )
  |> ReasonReact.arrayToElement;
};

let make = _children => {
  ...component,
  render: _self =>
    <div className=Styles.projectContainer>
      <h1 className=CommonStyles.pageTitle> (str("Projects")) </h1>
      <Card title="Onivim">
        <img className=Styles.image src=onivim alt="onivim logo" />
        <article className=Styles.projectDetails>
          <p> (str("A modal editor for the modern age")) </p>
          oniDetails
        </article>
      </Card>
    </div>,
};
