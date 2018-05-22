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
  didMount: self =>
        ignore(Js.Global.setTimeout(() => self.send(Style(after)), 0)),
  render: ({state}) =>
    <div style=state> (ReasonReact.array(children)) </div>,
};

