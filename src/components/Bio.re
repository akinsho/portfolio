open Utils;

let component = ReasonReact.statelessComponent("Bio");

let make = _children => {
  ...component,
  render: _self => <div> (str("Bio")) </div>,
};
