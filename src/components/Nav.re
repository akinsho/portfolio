open Utils;

open CommonStyles;

importCss("./../css/nav.scss");

open Css;

let navContainer =
  style([
    top(zero),
    position(sticky),
    height(auto),
    width(`percent(100.)),
    fontSize(rem(0.8)),
    display(`flex),
    zIndex(2),
    backgroundColor(hex(theme.bgColor)),
  ]);

let links =
  style([
    display(`flex),
    flexDirection(row),
    alignSelf(flexEnd),
    width(`percent(100.)),
  ]);

let linkText = style([paddingTop(em(0.5)), paddingBottom(em(0.5))]);

let listItem =
  style([
    position(relative),
    marginLeft(em(1.)),
    marginRight(em(1.)),
    fontSize(em(1.2)),
    whiteSpace(nowrap),
    padding(em(0.5)),
    firstChild([marginLeft(zero)]),
    /* transition(~duration=200, ~delay=50, ~timingFunction=easeInOut, "all"), */
    /* hover([backgroundColor(white), color(hex(theme.bgColor))]), */
  ]);

let component = ReasonReact.statelessComponent("NavigationBar");

let make = _children => {
  ...component,
  render: self => {
    let navigate = id =>
      self.handle(
        (id, _self) =>
          switch (id) {
          | Some(id) => ReasonReact.Router.push(id)
          | None => ReasonReact.Router.push("/")
          },
        id,
      );
    <nav className=navContainer>
      <ul className=links style=(restyle(~listStyleType="none", ()))>
        <li
          onClick=(_evt => navigate(None))
          className=(combineClasses([listItem, "nav__link"]))>
          <span className=linkText> (str("Home")) </span>
        </li>
        <li
          id="projects"
          onClick=(_evt => navigate(Some("projects")))
          className=listItem>
          <span className=linkText> (str("Projects")) </span>
        </li>
        <li
          id="bio"
          onClick=(_evt => navigate(Some("bio")))
          className=listItem>
          <span className=linkText> (str("More about me")) </span>
        </li>
        <li
          id="interests"
          onClick=(_evt => navigate(Some("interests")))
          className=listItem>
          <span className=linkText> (str("Interests and Experience")) </span>
        </li>
      </ul>
    </nav>;
  },
};
