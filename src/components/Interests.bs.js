// Generated by BUCKLESCRIPT VERSION 2.2.2, PLEASE EDIT WITH CARE
'use strict';

var React = require("react");
var ReasonReact = require("reason-react/src/ReasonReact.js");
var Utils$Portfolio = require("../Utils.bs.js");

var component = ReasonReact.statelessComponent("Interests");

function make() {
  var newrecord = component.slice();
  newrecord[/* render */9] = (function () {
      return React.createElement("div", undefined, Utils$Portfolio.str("Interests"));
    });
  return newrecord;
}

exports.component = component;
exports.make = make;
/* component Not a pure module */
