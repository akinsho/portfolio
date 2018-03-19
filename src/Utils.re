/* Aliases for long function names */
let str = ReasonReact.stringToElement;

let getElement = ReactDOMRe.domElementToObj;

let restyle = ReactDOMRe.Style.make;

[@bs.val] external requireAssetUri : string => string = "require";

/* Abstract types for font awesome methods - no official bindings */
type lib;

type listOfIcons;

type icon = {
  prefix: string,
  iconName: string,
};

[@bs.send] [@bs.return nullable]
external getAttribute : (Js.t('a), string) => option(string) =
  "getAttribute";

/* FONTAWESOME SETUP */
[@bs.module]
external fontAwesome : ReasonReact.reactClass =
  "@fortawesome/react-fontawesome";

[@bs.module "@fortawesome/fontawesome-free-brands"]
external brands : listOfIcons = "default";

[@bs.module "@fortawesome/fontawesome"] external library : lib = "";

[@bs.send] external add : (lib, listOfIcons) => unit = "add";

add(library, brands);

module FontAwesomeIcon = {
  let make = (~icon: icon, ~size: string, ~className: string, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=fontAwesome,
      ~props={"icon": icon, "size": size, "className": className},
      children,
    );
};

let linkedinLink = "https://www.linkedin.com/in/akin-sowemimo-831383131/";

let githubLink = "https://www.github.com/Akin909";

let twitterLink = "https://www.twitter.com/Akin_So";

let defaultFont = {| -apple-system, BlinkMacSystemFont,
                    "Segoe UI",Roboto, Helvetica, Arial, sans-serif,
                    "Apple Color Emoji","Segoe UI Emoji", "Segoe UI Symbol"
                  |};
