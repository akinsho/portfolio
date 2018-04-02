// Generated by BUCKLESCRIPT VERSION 2.2.3, PLEASE EDIT WITH CARE
'use strict';

var Css = require("bs-css/src/Css.js");
var Block = require("bs-platform/lib/js/block.js");
var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var ReasonReact = require("reason-react/src/ReasonReact.js");
var Bio$Portfolio = require("./Bio.bs.js");
var Nav$Portfolio = require("./Nav.bs.js");
var Home$Portfolio = require("./Home.bs.js");
var Utils$Portfolio = require("./Utils.bs.js");
var Projects$Portfolio = require("./Projects.bs.js");
var Interests$Portfolio = require("./Interests.bs.js");
var CommonStyles$Portfolio = require("./CommonStyles.bs.js");

Css.$$global("body, html", /* :: */[
      Css.padding(Css.zero),
      /* :: */[
        Css.margin(Css.zero),
        /* :: */[
          Css.fontFamily(Utils$Portfolio.defaultFont),
          /* :: */[
            Css.fontSize(Css.px(16)),
            /* :: */[
              Css.boxSizing(Css.borderBox),
              /* [] */0
            ]
          ]
        ]
      ]
    ]);

var container = Css.style(/* :: */[
      Css.display(Css.flexBox),
      /* :: */[
        Css.flexDirection(Css.column),
        /* :: */[
          Css.alignItems(Css.center),
          /* :: */[
            Css.justifyContent(Css.center),
            /* :: */[
              Css.height(Css.vh(100.0)),
              /* :: */[
                Css.fontSize(Css.rem(1.5)),
                /* :: */[
                  Css.color(Css.white),
                  /* :: */[
                    Css.marginTop(Css.em(1)),
                    /* :: */[
                      Css.backgroundColor(CommonStyles$Portfolio.theme[/* background */0]),
                      /* [] */0
                    ]
                  ]
                ]
              ]
            ]
          ]
        ]
      ]
    ]);

var Styles = /* module */[/* container */container];

var component = ReasonReact.reducerComponent("Router");

function route(url, self) {
  var match = url[/* path */0];
  if (match) {
    switch (match[0]) {
      case "bio" : 
          if (match[1]) {
            return Curry._1(self[/* send */4], /* ShowHome */1);
          } else {
            return Curry._1(self[/* send */4], /* ShowBio */2);
          }
      case "interests" : 
          if (match[1]) {
            return Curry._1(self[/* send */4], /* ShowHome */1);
          } else {
            return Curry._1(self[/* send */4], /* ShowInterests */3);
          }
      case "projects" : 
          if (match[1]) {
            return Curry._1(self[/* send */4], /* ShowHome */1);
          } else {
            return Curry._1(self[/* send */4], /* ShowProjects */0);
          }
      default:
        return Curry._1(self[/* send */4], /* ShowHome */1);
    }
  } else {
    return Curry._1(self[/* send */4], /* ShowHome */1);
  }
}

function make() {
  var newrecord = component.slice();
  newrecord[/* didMount */4] = (function () {
      var url = ReasonReact.Router[/* dangerouslyGetInitialUrl */3](/* () */0);
      return /* SideEffects */Block.__(2, [(function (self) {
                    return route(url, self);
                  })]);
    });
  newrecord[/* render */9] = (function (param) {
      var tmp;
      switch (param[/* state */2]) {
        case 0 : 
            tmp = ReasonReact.element(/* None */0, /* None */0, Home$Portfolio.make(/* array */[]));
            break;
        case 1 : 
            tmp = ReasonReact.element(/* None */0, /* None */0, Bio$Portfolio.make(/* array */[]));
            break;
        case 2 : 
            tmp = ReasonReact.element(/* None */0, /* None */0, Interests$Portfolio.make(/* array */[]));
            break;
        case 3 : 
            tmp = ReasonReact.element(/* None */0, /* None */0, Projects$Portfolio.make(/* array */[]));
            break;
        
      }
      return React.createElement("div", {
                  className: container,
                  style: Utils$Portfolio.restyle(/* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* Some */["optimizeLegibility"], /* None */0, /* None */0, /* None */0, /* () */0)
                }, ReasonReact.element(/* None */0, /* None */0, Nav$Portfolio.make(/* array */[])), tmp);
    });
  newrecord[/* initialState */10] = (function () {
      return /* HomePage */0;
    });
  newrecord[/* reducer */12] = (function (action, _) {
      switch (action) {
        case 0 : 
            return /* Update */Block.__(0, [/* ProjectsPage */3]);
        case 1 : 
            return /* Update */Block.__(0, [/* HomePage */0]);
        case 2 : 
            return /* Update */Block.__(0, [/* BioPage */1]);
        case 3 : 
            return /* Update */Block.__(0, [/* InterestsPage */2]);
        
      }
    });
  newrecord[/* subscriptions */13] = (function (self) {
      return /* :: */[
              /* Sub */[
                (function () {
                    return ReasonReact.Router[/* watchUrl */1]((function (url) {
                                  return route(url, self);
                                }));
                  }),
                ReasonReact.Router[/* unwatchUrl */2]
              ],
              /* [] */0
            ];
    });
  return newrecord;
}

exports.Styles = Styles;
exports.component = component;
exports.route = route;
exports.make = make;
/*  Not a pure module */
