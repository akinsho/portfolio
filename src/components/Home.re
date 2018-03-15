open Utils;

module Styles = {
  open Css;
  global(
    "body, html",
    [
      padding(px(0)),
      margin(px(0)),
      fontFamily(defaultFont),
      fontSize(px(16)),
    ],
  );
  let homeContainer =
    style([
      display(flexBox),
      flexDirection(column),
      alignItems(center),
      justifyContent(center),
      height(vh(100.0)),
      fontSize(rem(1.5)),
      backgroundColor(hex("232529")),
      color(white),
    ]);
  let firstName =
    style([
      fontSize(em(5.0)),
      color(white),
      marginBottom(em(0.1)),
      textAlign(`left),
    ]);
  let lastName = style([fontSize(em(1.0)), textAlign(`left)]);
  let bio = style([fontSize(em(0.8)), margin(em(0.2))]);
  let drift = (reverse: int) =>
    keyframes([
      (0, [transform(translateX(px(reverse * (-5))))]),
      (50, [transform(translateX(px(reverse * 5)))]),
      (100, [transform(translateX(px(reverse * 0)))]),
    ]);
  let drifting = (~reverseDirection: bool) =>
    style([
      animationName(drift(reverseDirection ? (-1) : 1)),
      animationDuration(50000),
      animationIterationCount(`infinite),
    ]);
};

let component = ReasonReact.statelessComponent("Home");

let appearIn = (delay: int, ~base=500, ()) =>
  string_of_int(delay + base) ++ "ms";

/* Add subtle varying positioning */
let make = _children => {
  ...component,
  render: _self =>
    <div className=Styles.homeContainer>
      <Nav />
      <section>
        <header className=(Styles.drifting(~reverseDirection=true))>
          <Transition
            before=(reStyle(~opacity="0", ()))
            after=(
              reStyle(
                ~opacity="1",
                ~transition="opacity " ++ appearIn(1000, ()),
                (),
              )
            )>
            <h1 className=Styles.firstName> (text("Akin")) </h1>
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
            <h2 className=Styles.lastName> (text("Sowemimo")) </h2>
          </Transition>
        </header>
        <article className=(Styles.drifting(~reverseDirection=false))>
          <p className=Styles.bio> (text("Software Developer,")) </p>
          <p className=Styles.bio> (text("One time doctor,")) </p>
          <p className=Styles.bio> (text("often times problem solver,")) </p>
          <p className=Styles.bio>
            (text("occasionaly weeps with frustration"))
          </p>
        </article>
      </section>
    </div>,
};
