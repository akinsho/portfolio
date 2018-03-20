open Utils;

let hpo = requireAssetUri("./assets/hpo.png");

let onivim = requireAssetUri("./assets/oni-logo.png");

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
      overflow(scroll),
      height(auto),
    ]);
  let image =
    style([
      width(em(10.)),
      height(auto),
      margin(em(1.)),
      Css.float(`left),
    ]);
  let projectDetails = style([lineHeight(1.5)]);
  let projectLine = style([display(block)]);
  let projectIntro = style([fontStyle(italic), fontWeight(800)]);
};

module Card = {
  open Css;
  let card =
    style([
      width(`percent(50.)),
      backgroundColor(whitesmoke),
      height(auto),
      marginTop(em(1.)),
      marginBottom(em(1.)),
      borderRadius(px(8)),
      color(black),
      padding(em(1.5)),
      fontSize(rem(1.2)),
    ]);
  let cardTitle = style([margin(em(0.2))]);
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

let renderText = (details: array(string)) =>
  Array.mapi(
    (index, line) =>
      <span className=Styles.projectLine key=(string_of_int(index))>
        (str(line))
      </span>,
    details,
  )
  |> ReasonReact.arrayToElement;

let oniDetails = [|
  "I collaborate on the Onivim project on github.",
  "Oni is an attempt to modernise modal editing using vim.",
  "Whilst taking inspiration from more modern editors like VSCode and Atom.",
  "As a collaborator I triage and respond to issues, contribute new functionality and fix bugs",
  "It uses React, Redux, RxJs, TypeScript, Electron",
|];

let phenotypeDetails = [|
  {j| The object of this project was to create a data visualization of a section of the
  human phenotype ontology (HPO)|j},
  {j| The HPO is fancy term for the classification of human disease, aka the main classification
    of lungs diseases would be pulmonary pathology and this would then have loads of subclasses
  |j},
  {j| This involved parsing an enormous OBO file (an obscure academic format for phenotypic data) into
  json and then rendering this data with a data visualisation library
    |j},
|];

let make = _children => {
  ...component,
  /* didMount: _self => {/* ReasonReact.SideEffects(self => Js.Fetch) */}, */
  render: _self =>
    <div className=Styles.projectContainer>
      <h1 className=CommonStyles.pageTitle> (str("Projects")) </h1>
      <Card title="Onivim">
        <img className=Styles.image src=onivim alt="onivim logo" />
        <article className=Styles.projectDetails>
          <p className=Styles.projectIntro>
            (str("A Modal Editor for the Modern age"))
          </p>
          (renderText(oniDetails))
        </article>
      </Card>
      <Card title="Human Phenotype Ontology">
        <img className=Styles.image src=hpo alt="onivim logo" />
        <article className=Styles.projectDetails>
          <p className=Styles.projectIntro>
            (str("A data visualization of the human phenotype ontology"))
          </p>
          (renderText(phenotypeDetails))
        </article>
      </Card>
    </div>,
};
