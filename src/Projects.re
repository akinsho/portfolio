open Utils;

open CommonStyles;

let hpo = requireAssetUri("./assets/hpo.png");

let onivim = requireAssetUri("./assets/oni-logo.png");

importCss("./css/projects.css");

let component = ReasonReact.statelessComponent("Projects");

module Styles = {
  open Css;
  let container =
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
      /* Css.float(`left), */
    ]);
  let cards =
    style([
      display(flexBox),
      flexDirection(row),
      flexWrap(wrap),
      children([margin(em(2.)), flexBasis(`percent(35.))]),
    ]);
  let line = style([display(block)]);
  let intro = style([fontStyle(italic), fontWeight(800)]);
  let title =
    style([height(em(5.)), verticalAlign(middle), textAlign(center)]);
};

module Card = {
  open Css;
  let card =
    style([
      flex(1),
      height(auto),
      backgroundColor(whitesmoke),
      marginTop(em(1.)),
      marginBottom(em(1.)),
      borderRadius(px(5)),
      color(black),
      fontSize(rem(1.2)),
      overflow(hidden),
    ]);
  let content =
    style([margin(zero), ...CommonStyles.flexCenter(~columnStyle=true)]);
  let contentBody = style([]);
  let details =
    style([
      lineHeight(1.5),
      width(`percent(100.)),
      padding(em(1.)),
      boxSizing(borderBox),
    ]);
  let imageContainer =
    style([
      width(`percent(100.)),
      backgroundColor(hex("EFEFEF")),
      minHeight(`percent(40.)),
      ...CommonStyles.flexCenter(~columnStyle=true),
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
      <span className=Styles.line key=(string_of_int(index))>
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
  render: _self =>
    <div className=Styles.container>
      <h1 className=(combineClasses([pageTitle, Styles.title]))>
        (str("Projects"))
      </h1>
      <section className=Styles.cards>
        <Card title="Onivim">
          <div className=Card.content>
            <div className=Card.imageContainer>
              <img className=Styles.image src=onivim alt="onivim logo" />
            </div>
            <div className=Card.details>
              <p className=Styles.intro>
                (str("A Modal Editor for the Modern age"))
              </p>
              <p className=Card.contentBody> (renderText(oniDetails)) </p>
            </div>
          </div>
        </Card>
        <Card title="Human Phenotype Ontology">
          <div className=Card.content>
            <div className=Card.imageContainer>
              <img className=Styles.image src=hpo alt="onivim logo" />
            </div>
            <div className=Card.details>
              <p className=Styles.intro>
                (str("A data visualization of the human phenotype ontology"))
              </p>
              <p className=Card.contentBody>
                (renderText(phenotypeDetails))
              </p>
            </div>
          </div>
        </Card>
        <Card title="Human Phenotype Ontology">
          <div className=Card.content>
            <div className=Card.imageContainer>
              <img className=Styles.image src=hpo alt="onivim logo" />
            </div>
            <div className=Card.details>
              <p className=Styles.intro>
                (str("A data visualization of the human phenotype ontology"))
              </p>
              <p className=Card.contentBody>
                (renderText(phenotypeDetails))
              </p>
            </div>
          </div>
        </Card>
      </section>
    </div>,
};
