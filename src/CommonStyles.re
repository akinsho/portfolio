open Css;

let pageTitle = style([fontSize(em(1.2)), marginBottom(em(0.5))]);

let flexCenter = (~columnStyle: bool) =>
  [
    display(flexBox),
    alignItems(center),
    justifyContent(center),
    flexDirection(columnStyle ? column : row),
  ];

/* Use a fold/reduce to take in a list of classes and concatenate them.. probs overkill */
let combineClasses = (classes: list(string)) =>
  ListLabels.fold_left(~f=(r, elem) => r ++ " " ++ elem, ~init="", classes);

type themeProps = {
  background: Css.color,
};

let theme = {
  background: hex("232529"),
}
