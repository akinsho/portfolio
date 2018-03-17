open Utils;

let component = ReasonReact.statelessComponent("Interests");

let make = _children => {
  ...component,
  render: _self => <div> (text("Interests")) </div>,
};
