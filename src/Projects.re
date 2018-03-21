open Utils;

open CommonStyles;

let hpo = requireAssetUri("./assets/hpo.png");

let medspace = requireAssetUri("./assets/medspace.gif");

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
    ]);
  let cards =
    style([
      display(flexBox),
      flexDirection(row),
      flexWrap(wrap),
      justifyContent(center),
      children([margin(em(2.)), flexGrow(0), flexBasis(`percent(42.))]),
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
      paddingBottom(em(1.)),
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
      margin(zero),
      width(`percent(100.)),
      backgroundColor(hex("EFEFEF")),
      minHeight(`percent(40.)),
      ...CommonStyles.flexCenter(~columnStyle=true),
    ]);
  let cardTitle = style([margin(em(0.2))]);
  let renderText = (details: array(string)) =>
    Array.mapi(
      (index, line) =>
        <span className=Styles.line key=(string_of_int(index))>
          (str(line))
        </span>,
      details,
    )
    |> ReasonReact.arrayToElement;
  let component = ReasonReact.statelessComponent("Card");
  let make =
      (
        ~title: string,
        ~img: string,
        ~body: array(string),
        ~header: string,
        ~alt: string,
        children,
      ) => {
    ...component,
    render: _self =>
      <article className=card>
        <div className=content>
          <figure className=imageContainer>
            <img className=Styles.image src=img alt />
            <caption className=cardTitle> (str(title)) </caption>
          </figure>
          <div className=details>
            <p className=Styles.intro> (str(header)) </p>
            <p className=contentBody> (renderText(body)) </p>
          </div>
        </div>
        (ReasonReact.arrayToElement(children))
      </article>,
  };
};

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

let medspaceDetails = [|
  {j| I worked with two other developers to create a prototype of a react app aimed at trying to increase
the understanding of children and young adults undergoing psychiatric treatment of the medication they were prescribed|j},
  {j|We worked closely with a psychiatrist and a therapist to collate a list of common medications and explain what these
  were and how they worked in an approachable fashion
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
        <Card
          title="Onivim"
          header="A Modal Editor for the Modern age"
          body=oniDetails
          img=onivim
          alt="onivim editor logo"
        />
        <Card
          title="Human Phenotype Ontology"
          body=phenotypeDetails
          header="A data visualization of the human phenotype ontology"
          img=hpo
          alt="HPO logo"
        />
        <Card
          title="Medspace"
          img=medspace
          body=medspaceDetails
          header="A web app aimed at helping children understand their medication"
          alt="GIF demoing medspace"
        />
      </section>
    </div>,
};
