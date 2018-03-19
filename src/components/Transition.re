/* CREDIT: Cheng Lou */
type action =
  | Style(ReactDOMRe.Style.t);

let component = ReasonReact.reducerComponent("Transition");

let make = (~before, ~after, children) => {
  ...component,
  reducer: (action, _state) =>
    switch (action) {
    | Style(a) => ReasonReact.Update(a)
    },
  initialState: () => before,
  didMount: _self =>
    ReasonReact.SideEffects(
      self =>
        ignore(Js.Global.setTimeout(() => self.send(Style(after)), 0)),
    ),
  render: ({state}) =>
    <div style=state> (ReasonReact.arrayToElement(children)) </div>,
};
