open Utils;

module Styles = {
  open Css;
  let bio = style([width(`percent(80.)), padding(em(1.))]);
  let bioSection =
    style([
      padding(em(1.)),
      width(`percent(100.)),
      display(flexBox),
      flexDirection(column),
      justifyContent(center),
      alignItems(center),
    ]);
  let title = style([paddingLeft(em(1.))]);
  let container =
    style([
      width(`percent(100.)),
      ...CommonStyles.flexCenter(~columnStyle=true),
    ]);
};

let component = ReasonReact.statelessComponent("Bio");

let aboutMe = {
  let details = [
    "I trained as a Medical Doctor at King's college london.",
    {j|Unfortunately after 8 years of studying, training, many an up and down
    I realised that it wasn't for me and parted ways with that time of my life.
      |j},
    {j| As understandeably unusual a choice as it might seem I much preferred tinkering with computers
    I'd spent much of my youth messing around with hardware but it wasn't really till the fateful summer having just
    decided to leave my job that I discovered github and the rest is history...
    |j},
    {j|Actually the rest is me meeting a bunch of other aspiring developers, our forming a group to teach each other
    then my finding out about founders and coders in London|j},
  ];
  <article className=Styles.bio>
    (
      List.mapi(
        (index, item) => <p key=(string_of_int(index))> (str(item)) </p>,
        details,
      )
      |> Array.of_list
      |> ReasonReact.array
    )
  </article>;
};

let make = _children => {
  ...component,
  render: _self =>
    <div className=Styles.container>
      <div className=Styles.bioSection>
        <h1 className=Styles.title> (str("Bio")) </h1>
        <Terminal />
      </div>
    </div>,
};
