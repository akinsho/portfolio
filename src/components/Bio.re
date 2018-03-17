open Utils;

let component = ReasonReact.statelessComponent("Bio");

let make = _children => {
  ...component,
  render: _self => <div> (text("Bio")) </div>,
};
