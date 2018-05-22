// Generated by BUCKLESCRIPT VERSION 3.1.1, PLEASE EDIT WITH CARE
'use strict';

var Css = require("bs-css/src/Css.js");
var $$Array = require("bs-platform/lib/js/array.js");
var React = require("react");
var ReasonReact = require("reason-react/src/ReasonReact.js");
var Utils$Portfolio = require("./Utils.bs.js");
var CommonStyles$Portfolio = require("./CommonStyles.bs.js");

var hpo = require("./assets/hpo.gif");

var medspace = require("./assets/medspace.gif");

var onivim = require("./assets/oni-logo.png");

require("./css/projects.css");

var component = ReasonReact.statelessComponent("Projects");

var container = Css.style(/* :: */[
      Css.display(Css.flexBox),
      /* :: */[
        Css.flexDirection(Css.column),
        /* :: */[
          Css.justifyContent(Css.spaceAround),
          /* :: */[
            Css.alignItems(Css.center),
            /* :: */[
              Css.width(/* `percent */[
                    -119887163,
                    100
                  ]),
              /* :: */[
                Css.overflow(Css.scroll),
                /* :: */[
                  Css.height(Css.auto),
                  /* [] */0
                ]
              ]
            ]
          ]
        ]
      ]
    ]);

var image = Css.style(/* :: */[
      Css.width(Css.em(10)),
      /* :: */[
        Css.height(Css.auto),
        /* :: */[
          Css.margin(Css.em(1)),
          /* [] */0
        ]
      ]
    ]);

var cards = Css.style(/* :: */[
      Css.display(Css.flexBox),
      /* :: */[
        Css.flexDirection(Css.row),
        /* :: */[
          Css.flexWrap(Css.wrap),
          /* :: */[
            Css.width(/* `percent */[
                  -119887163,
                  100
                ]),
            /* :: */[
              Css.justifyContent(Css.center),
              /* :: */[
                Css.children(/* :: */[
                      Css.margin(Css.em(2)),
                      /* :: */[
                        Css.flexGrow(0),
                        /* :: */[
                          Css.flexBasis(/* `percent */[
                                -119887163,
                                42
                              ]),
                          /* [] */0
                        ]
                      ]
                    ]),
                /* [] */0
              ]
            ]
          ]
        ]
      ]
    ]);

var line = Css.style(/* :: */[
      Css.display(Css.block),
      /* [] */0
    ]);

var intro = Css.style(/* :: */[
      Css.fontWeight(800),
      /* [] */0
    ]);

var title = Css.style(/* :: */[
      Css.height(Css.em(5)),
      /* :: */[
        Css.verticalAlign(Css.middle),
        /* :: */[
          Css.textAlign(Css.center),
          /* [] */0
        ]
      ]
    ]);

var Styles = /* module */[
  /* container */container,
  /* image */image,
  /* cards */cards,
  /* line */line,
  /* intro */intro,
  /* title */title
];

var card = Css.style(/* :: */[
      Css.flex(1),
      /* :: */[
        Css.flexBasis(/* `percent */[
              -119887163,
              30
            ]),
        /* :: */[
          Css.height(Css.auto),
          /* :: */[
            Css.backgroundColor(Css.whitesmoke),
            /* :: */[
              Css.marginTop(Css.em(1)),
              /* :: */[
                Css.marginBottom(Css.em(1)),
                /* :: */[
                  Css.borderRadius(Css.px(5)),
                  /* :: */[
                    Css.color(Css.black),
                    /* :: */[
                      Css.fontSize(Css.rem(1.2)),
                      /* :: */[
                        Css.overflow(Css.hidden),
                        /* :: */[
                          Css.paddingBottom(Css.em(1)),
                          /* [] */0
                        ]
                      ]
                    ]
                  ]
                ]
              ]
            ]
          ]
        ]
      ]
    ]);

var content = Css.style(/* :: */[
      Css.margin(Css.zero),
      CommonStyles$Portfolio.flexCenter(true)
    ]);

var contentBody = Css.style(/* [] */0);

var details = Css.style(/* :: */[
      Css.lineHeight(1.5),
      /* :: */[
        Css.padding(Css.em(1)),
        /* :: */[
          Css.height(/* `percent */[
                -119887163,
                100
              ]),
          /* :: */[
            Css.width(/* `percent */[
                  -119887163,
                  100
                ]),
            /* :: */[
              Css.boxSizing(Css.borderBox),
              /* [] */0
            ]
          ]
        ]
      ]
    ]);

var imageContainer = Css.style(/* :: */[
      Css.margin(Css.zero),
      /* :: */[
        Css.width(/* `percent */[
              -119887163,
              100
            ]),
        /* :: */[
          Css.backgroundColor(Css.hex("EFEFEF")),
          /* :: */[
            Css.minHeight(/* `percent */[
                  -119887163,
                  40
                ]),
            CommonStyles$Portfolio.flexCenter(true)
          ]
        ]
      ]
    ]);

function joinText(text) {
  return Utils$Portfolio.str($$Array.fold_left((function (acc, line) {
                    return acc + ("\n" + line);
                  }), "", text));
}

var cardTitle = Css.style(/* :: */[
      Css.margin(Css.em(0.2)),
      /* [] */0
    ]);

var component$1 = ReasonReact.statelessComponent("Card");

function make(title, img, body, header, alt, children) {
  return /* record */[
          /* debugName */component$1[/* debugName */0],
          /* reactClassInternal */component$1[/* reactClassInternal */1],
          /* handedOffState */component$1[/* handedOffState */2],
          /* willReceiveProps */component$1[/* willReceiveProps */3],
          /* didMount */component$1[/* didMount */4],
          /* didUpdate */component$1[/* didUpdate */5],
          /* willUnmount */component$1[/* willUnmount */6],
          /* willUpdate */component$1[/* willUpdate */7],
          /* shouldUpdate */component$1[/* shouldUpdate */8],
          /* render */(function () {
              return React.createElement("article", {
                          className: card
                        }, React.createElement("div", {
                              className: content
                            }, React.createElement("figure", {
                                  className: imageContainer,
                                  style: Utils$Portfolio.restyle(/* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* Some */["cover"], /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* () */0)
                                }, React.createElement("img", {
                                      className: image,
                                      alt: alt,
                                      src: img
                                    }), React.createElement("figcaption", {
                                      className: cardTitle
                                    }, Utils$Portfolio.str(title))), React.createElement("div", {
                                  className: CommonStyles$Portfolio.combineClasses(/* :: */[
                                        details,
                                        /* :: */[
                                          "ellipsis",
                                          /* [] */0
                                        ]
                                      ])
                                }, React.createElement("p", {
                                      className: intro
                                    }, React.createElement("i", undefined, Utils$Portfolio.str(header))), React.createElement("p", {
                                      className: contentBody
                                    }, joinText(body)))), children);
            }),
          /* initialState */component$1[/* initialState */10],
          /* retainedProps */component$1[/* retainedProps */11],
          /* reducer */component$1[/* reducer */12],
          /* subscriptions */component$1[/* subscriptions */13],
          /* jsElementWrapped */component$1[/* jsElementWrapped */14]
        ];
}

var Card = /* module */[
  /* card */card,
  /* content */content,
  /* contentBody */contentBody,
  /* details */details,
  /* imageContainer */imageContainer,
  /* joinText */joinText,
  /* cardTitle */cardTitle,
  /* component */component$1,
  /* make */make
];

var oniDetails = /* array */[
  "I collaborate on the Onivim project on github.",
  "Oni is an attempt to modernise modal editing using vim.",
  "Whilst taking inspiration from more modern editors like VSCode and Atom.",
  "As a collaborator I triage and respond to issues, contribute new functionality and fix bugs",
  "It uses React, Redux, RxJs, TypeScript, Electron"
];

var phenotypeDetails = /* array */[
  " The object of this project was to create a data visualization of a section of the\n  human phenotype ontology (HPO)",
  " The HPO is fancy term for the classification of human disease, aka the main classification\n    of lungs diseases would be pulmonary pathology and this would then have loads of subclasses\n  ",
  " This involved parsing an enormous OBO file (an obscure academic format for phenotypic data) into\n  json and then rendering this data with a data visualisation library\n    "
];

var medspaceDetails = /* array */[
  " I worked with two other developers to create a prototype of a react app aimed at trying to increase\nthe understanding of children and young adults undergoing psychiatric treatment of the medication they were prescribed",
  "We worked closely with a psychiatrist and a therapist to collate a list of common medications and explain what these\n  were and how they worked in an approachable fashion\n  "
];

function make$1() {
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
                        }, React.createElement("h1", {
                              className: CommonStyles$Portfolio.combineClasses(/* :: */[
                                    CommonStyles$Portfolio.pageTitle,
                                    /* :: */[
                                      title,
                                      /* [] */0
                                    ]
                                  ])
                            }, Utils$Portfolio.str("Projects")), React.createElement("section", {
                              className: cards
                            }, ReasonReact.element(/* None */0, /* None */0, make("Onivim", onivim, oniDetails, "A Modal Editor for the Modern age", "onivim editor logo", /* array */[])), ReasonReact.element(/* None */0, /* None */0, make("Human Phenotype Ontology", hpo, phenotypeDetails, "A data visualization of the human phenotype ontology", "HPO logo", /* array */[])), ReasonReact.element(/* None */0, /* None */0, make("Medspace", medspace, medspaceDetails, "A web app aimed at helping children understand their medication", "GIF demoing medspace", /* array */[]))));
            }),
          /* initialState */component[/* initialState */10],
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */component[/* reducer */12],
          /* subscriptions */component[/* subscriptions */13],
          /* jsElementWrapped */component[/* jsElementWrapped */14]
        ];
}

var settings = /* record */[
  /* dots */true,
  /* infinite */true,
  /* speed */500,
  /* slidesToShow */1,
  /* slidesToScroll */1
];

exports.hpo = hpo;
exports.medspace = medspace;
exports.onivim = onivim;
exports.component = component;
exports.Styles = Styles;
exports.Card = Card;
exports.oniDetails = oniDetails;
exports.phenotypeDetails = phenotypeDetails;
exports.medspaceDetails = medspaceDetails;
exports.settings = settings;
exports.make = make$1;
/* hpo Not a pure module */
