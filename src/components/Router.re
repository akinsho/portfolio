open Utils;

module Styles = {
  open Css;
  global(
    "body, html",
    [
      padding(zero),
      margin(zero),
      fontFamily(defaultFont),
      fontSize(px(16)),
    ],
  );
  let container =
    style([
      display(flexBox),
      flexDirection(column),
      alignItems(center),
      justifyContent(center),
      height(vh(100.0)),
      fontSize(rem(1.5)),
      backgroundColor(hex("232529")),
      color(white),
    ]);
};

type action =
  | ShowProjects
  | ShowHome
  | ShowBio
  | ShowInterests;

type state =
  | HomePage
  | BioPage
  | InterestsPage
  | ProjectsPage;

let component = ReasonReact.reducerComponent("Router");

let make = _children => {
  ...component,
  initialState: () => HomePage,
  reducer: (action, _state) =>
    switch (action) {
    | ShowHome => ReasonReact.Update(HomePage)
    | ShowProjects => ReasonReact.Update(ProjectsPage)
    | ShowBio => ReasonReact.Update(BioPage)
    | ShowInterests => ReasonReact.Update(InterestsPage)
    },
  subscriptions: self => [
    Sub(
      () =>
        ReasonReact.Router.watchUrl(url =>
          switch (url.path) {
          | ["bio"] => self.send(ShowBio)
          | ["projects"] => self.send(ShowProjects)
          | ["interests"] => self.send(ShowInterests)
          | _ => self.send(ShowHome)
          }
        ),
      ReasonReact.Router.unwatchUrl,
    ),
  ],
  render: ({state}) =>
    <div className=Styles.container>
      <Nav />
      (
        switch (state) {
        | HomePage => <Home />
        | ProjectsPage => <Projects />
        | InterestsPage => <Interests />
        | BioPage => <Bio />
        }
      )
    </div>,
};