// Generated by BUCKLESCRIPT VERSION 3.1.1, PLEASE EDIT WITH CARE
'use strict';

var Css = require("bs-css/src/Css.js");
var List = require("bs-platform/lib/js/list.js");
var $$Array = require("bs-platform/lib/js/array.js");
var React = require("react");
var ReasonReact = require("reason-react/src/ReasonReact.js");
var Utils$Portfolio = require("./Utils.bs.js");
var Terminal$Portfolio = require("./Terminal.bs.js");
var CommonStyles$Portfolio = require("./CommonStyles.bs.js");

var bio = Css.style(/* :: */[
      Css.width(/* `percent */[
            -119887163,
            80
          ]),
      /* :: */[
        Css.padding(Css.em(1)),
        /* [] */0
      ]
    ]);

var bioSection = Css.style(/* :: */[
      Css.padding(Css.em(1)),
      /* :: */[
        Css.width(/* `percent */[
              -119887163,
              100
            ]),
        /* :: */[
          Css.display(Css.flexBox),
          /* :: */[
            Css.flexDirection(Css.column),
            /* :: */[
              Css.justifyContent(Css.center),
              /* :: */[
                Css.alignItems(Css.center),
                /* [] */0
              ]
            ]
          ]
        ]
      ]
    ]);

var title = Css.style(/* :: */[
      Css.paddingLeft(Css.em(1)),
      /* [] */0
    ]);

var container = Css.style(/* :: */[
      Css.width(/* `percent */[
            -119887163,
            100
          ]),
      CommonStyles$Portfolio.flexCenter(true)
    ]);

var Styles = /* module */[
  /* bio */bio,
  /* bioSection */bioSection,
  /* title */title,
  /* container */container
];

var component = ReasonReact.statelessComponent("Bio");

var aboutMe = React.createElement("article", {
      className: bio
    }, $$Array.of_list(List.mapi((function (index, item) {
                return React.createElement("p", {
                            key: String(index)
                          }, Utils$Portfolio.str(item));
              }), /* :: */[
              "I trained as a Medical Doctor at King's college london.",
              /* :: */[
                "Unfortunately after 8 years of studying, training, many an up and down\n    I realised that it wasn\'t for me and parted ways with that time of my life.\n      ",
                /* :: */[
                  " As understandeably unusual a choice as it might seem I much preferred tinkering with computers\n    I\'d spent much of my youth messing around with hardware but it wasn\'t really till the fateful summer having just\n    decided to leave my job that I discovered github and the rest is history...\n    ",
                  /* :: */[
                    "Actually the rest is me meeting a bunch of other aspiring developers, our forming a group to teach each other\n    then my finding out about founders and coders in London",
                    /* [] */0
                  ]
                ]
              ]
            ])));

function make() {
  return /* record */[
          /* debugName */component[/* debugName */0],
          /* reactClassInternal */component[/* reactClassInternal */1],
          /* handedOffState */component[/* handedOffState */2],
          /* willReceiveProps */component[/* willReceiveProps */3],
          /* didMount */component[/* didMount */4],
          /* didUpdate */component[/* didUpdate */5],
          /* willUnmount */component[/* willUnmount */6],
          /* willUpdate */component[/* willUpdate */7],
          /* shouldUpdate */component[/* shouldUpdate */8],
          /* render */(function () {
              return React.createElement("div", {
                          className: container
                        }, React.createElement("div", {
                              className: bioSection
                            }, React.createElement("h1", {
                                  className: title
                                }, Utils$Portfolio.str("Bio")), ReasonReact.element(/* None */0, /* None */0, Terminal$Portfolio.make(/* array */[]))));
            }),
          /* initialState */component[/* initialState */10],
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */component[/* reducer */12],
          /* subscriptions */component[/* subscriptions */13],
          /* jsElementWrapped */component[/* jsElementWrapped */14]
        ];
}

exports.Styles = Styles;
exports.component = component;
exports.aboutMe = aboutMe;
exports.make = make;
/* bio Not a pure module */
