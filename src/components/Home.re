open Utils;

module Styles = {
  open Css;
  let homeContainer =
    style([
      display(flexBox),
      flexDirection(column),
      alignItems(center),
      justifyContent(center),
      flex(1),
    ]);
  let firstName =
    style([
      fontSize(em(5.)),
      color(white),
      marginTop(zero),
      marginBottom(em(0.1)),
      textAlign(`left),
    ]);
  let lastName = style([fontSize(em(1.)), textAlign(`left)]);
  let bio = style([fontSize(em(0.8)), margin(em(0.2))]);
  let drift = (reverse: int) =>
    keyframes([
      (0, [transform(translateX(px(reverse * (-5))))]),
      (50, [transform(translateX(px(reverse * 5)))]),
      (100, [transform(translateX(px(reverse * 0)))]),
    ]);
  let icons = style([margin(rem(0.5))]);
  let drifting = (~reverseDirection: bool) =>
    style([
      animationName(drift(reverseDirection ? (-1) : 1)),
      animationDuration(50000),
      animationIterationCount(`infinite),
    ]);
};

module Icons = {
  let component = ReasonReact.statelessComponent("Icons");
  let make = _children => {
    ...component,
    render: _self =>
      <div>
        <a href="github.com/Akin909">
          <FontAwesomeIcon
            icon={prefix: "fab", iconName: "github"}
            size="lg"
            className=Styles.icons
          />
        </a>
        <a href="linkedin.com">
          <FontAwesomeIcon
            icon={prefix: "fab", iconName: "linkedin"}
            size="lg"
            className=Styles.icons
          />
        </a>
        <a href="twitter.com">
          <FontAwesomeIcon
            icon={prefix: "fab", iconName: "twitter"}
            size="lg"
            className=Styles.icons
          />
        </a>
      </div>,
  };
};

let component = ReasonReact.statelessComponent("Home");

let appearIn = (delay: int, ~base=500, ()) =>
  string_of_int(delay + base) ++ "ms";

let renderBio = () => {
  let bio = [
    "Software developer,",
    "One time doctor,",
    "often times problem solver,",
    "occasionaly weeps with frustration",
  ];
  List.mapi(
    (index, item) =>
      <Transition
        key=(item ++ string_of_int(index))
        before=(reStyle(~opacity="0", ()))
        after=(
          reStyle(
            ~opacity="1",
            ~transition="opacity " ++ appearIn(1000 * index, ()) ++ " 2s",
            (),
          )
        )>
        <p key="1" className=Styles.bio> (str(item)) </p>
      </Transition>,
    bio,
  )
  |> Array.of_list
  |> ReasonReact.arrayToElement;
};

let make = _children => {
  ...component,
  render: _self =>
    <div className=Styles.homeContainer>
      <section>
        <header className=(Styles.drifting(~reverseDirection=true))>
          <Icons />
          <Transition
            before=(reStyle(~opacity="0", ()))
            after=(
              reStyle(
                ~opacity="1",
                ~transition="opacity " ++ appearIn(1000, ()),
                (),
              )
            )>
            <h1 key="1" className=Styles.firstName> (str("Akin")) </h1>
          </Transition>
          <Transition
            before=(reStyle(~opacity="0", ()))
            after=(
              reStyle(
                ~opacity="1",
                ~transition="opacity " ++ appearIn(5000, ()),
                (),
              )
            )>
            <h2 key="1" className=Styles.lastName> (str("Sowemimo")) </h2>
          </Transition>
        </header>
        <article className=(Styles.drifting(~reverseDirection=false))>
          (renderBio())
        </article>
      </section>
    </div>,
};
