open Utils;

module Styles = {
  open Css;
  let navContainer =
    style([
      position(`absolute),
      height(em(3.0)),
      width(vw(100.0)),
      top(px(0)),
      fontSize(rem(0.8)),
      display(`flex),
    ]);
  let links =
    style([
      display(`flex),
      flexDirection(`row),
      alignSelf(`flexEnd),
      width(vw(40.0)),
    ]);
  let listItem =
    style([
      flex(1),
      fontSize(em(1.2)),
      hover([textDecoration(`underline)]),
      whiteSpace(`nowrap),
    ]);
};

let component = ReasonReact.statelessComponent("NavigationBar");

let make = _children => {
  ...component,
  render: _self =>
    <nav className=Styles.navContainer>
      <ul className=Styles.links style=(reStyle(~listStyleType="none", ()))>
        <li className=Styles.listItem> (text("Stuff I've done")) </li>
        <li className=Styles.listItem> (text("More about me")) </li>
        <li className=Styles.listItem>
          (text("Interests and Experience"))
        </li>
      </ul>
      <div> <i className="fas fa-camera-retro" /> </div>
    </nav>,
};
