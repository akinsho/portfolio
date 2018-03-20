open Css;

let pageTitle = style([fontSize(em(1.2)), marginBottom(em(0.5))]);

/* Use a fold/reduce to take in a list of classes and concatenate them.. probs overkill */
let combineClasses = (classes: list(string)) =>
  ListLabels.fold_left(~f=(r, elem) => r ++ " " ++ elem, ~init="", classes);

type portfolioTheme = {bgColor: string};

/* TODO: Should not be using trimmed values which require knowledge of implementation
     e.g. to use bgColor value I have to know to use the hex method....
   */
let theme = {bgColor: "232529"};

let container =
  style([
    width(`percent(100.)),
    height(`percent(100.)),
    display(flexBox),
    alignItems(center),
    justifyContent(center),
  ]);
