let text = ReasonReact.stringToElement;

let getElement = ReactDOMRe.domElementToObj;

let reStyle = ReactDOMRe.Style.make;

[@bs.send] [@bs.return nullable]
external getAttribute : (Js.t('a), string) => option(string) =
  "getAttribute";

let defaultFont = {| -apple-system, BlinkMacSystemFont,
\"Segoe UI\",Roboto, Helvetica, Arial, sans-serif,
  \"Apple Color Emoji\",\"Segoe UI Emoji\", \"Segoe UI Symbol\"
  |};
