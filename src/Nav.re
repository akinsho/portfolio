open Utils;

open Css;

importCss("./css/nav.scss");

let navContainer =
  style([
    zIndex(2),
    position(absolute),
    height(em(3.)),
    width(vw(100.)),
    top(zero),
    fontSize(rem(0.8)),
    display(`flex),
    backgroundColor(CommonStyles.theme.background),
  ]);

let links =
  style([
    display(`flex),
    flexDirection(row),
    alignSelf(flexEnd),
    width(`percent(100.)),
  ]);

let listItem =
  style([
    marginLeft(em(1.)),
    marginRight(em(1.)),
    fontSize(em(1.2)),
    whiteSpace(nowrap),
    hover([textDecoration(underline)]),
    firstChild([marginLeft(zero)]),
  ]);

let component = ReasonReact.statelessComponent("NavigationBar");

let make = _children => {
  ...component,
  render: _self => {
    let navigate = event => {
      let id =
        getElement(ReactEventRe.Mouse.target(event))
        |> (element => getAttribute(element, "id"));
      switch (id) {
      | Some(id) => ReasonReact.Router.push(id)
      | None => ReasonReact.Router.push("/")
      };
    };
    <nav className=navContainer>
      <ul className=links style=(restyle(~listStyleType="none", ()))>
        <li
          onClick=navigate
          className=(CommonStyles.combineClasses([listItem, "nav__link"]))>
          (str("Home"))
        </li>
        <li id="projects" onClick=navigate className=listItem>
          (str("Projects"))
        </li>
        <li id="bio" onClick=navigate className=listItem>
          (str("More about me"))
        </li>
        <li id="interests" onClick=navigate className=listItem>
          (str("Interests and Experience"))
        </li>
      </ul>
    </nav>;
  },
};
