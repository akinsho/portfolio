// Generated by BUCKLESCRIPT VERSION 3.1.1, PLEASE EDIT WITH CARE
'use strict';

var Block = require("bs-platform/lib/js/block.js");

var about = /* array */[
  "I trained as a Medical Doctor at King's college london.",
  "Unfortunately after 8 years of studying, training, many an up and down\n      I realised that it wasn\'t for me and parted ways with that time of my life.\n        ",
  " As understandeably unusual a choice as it might seem I much preferred tinkering with computers\n      I\'d spent much of my youth messing around with hardware but it wasn\'t really till the fateful summer having just\n      decided to leave my job that I discovered github and the rest is history...\n      ",
  "Actually the rest is me meeting a bunch of other aspiring developers, our forming a group to teach each other\n      then my finding out about founders and coders in London"
];

function showPrompt($staropt$star, $staropt$star$1, _) {
  var user = $staropt$star ? $staropt$star[0] : "Akin_Sowemimo";
  var dir = $staropt$star$1 ? $staropt$star$1[0] : "root";
  return "/Users/" + (user + ("/" + (dir + ":")));
}

var filenames = /* array */[
  "about.txt",
  "coming_soon.txt"
];

var files_001 = /* comingSoon : array */["coming soon"];

var files = /* record */[
  /* about */about,
  files_001
];

var history_000 = /* record */[
  /* text : array */[""],
  /* id */1,
  /* exitCode : None */0,
  /* cmd */"",
  /* error : None */0
];

var history = /* :: */[
  history_000,
  /* [] */0
];

function cat(arg) {
  switch (arg) {
    case "about.txt" : 
        return /* ShellSuccess */Block.__(0, [about]);
    case "coming_soon.txt" : 
        return /* ShellSuccess */Block.__(0, [files_001]);
    default:
      return /* ShellFailure */Block.__(3, ["Sorry that file is invalid"]);
  }
}

function helpprg(arg) {
  if (arg === "") {
    return /* array */[
            "--Commands: type a terminal command",
            "options are: cat 'arg', ls, help, clear"
          ];
  } else {
    return /* array */[
            "--Commands: type a terminal command",
            "options are: cat 'arg', ls, help, clear"
          ];
  }
}

function chsh(shell) {
  switch (shell) {
    case "" : 
        return "bash";
    case "fish" : 
        return "fish";
    case "zsh" : 
        return "zsh";
    default:
      return "bash";
  }
}

function parseInput(input, arg) {
  switch (input) {
    case "cat" : 
        return cat(arg);
    case "chsh" : 
        return /* ChangeShell */Block.__(2, [chsh(arg)]);
    case "cl" : 
    case "clear" : 
        return /* ShellReset */Block.__(1, [history]);
    case "help" : 
        return /* ShellSuccess */Block.__(0, [helpprg(arg)]);
    case "ls" : 
        return /* ShellSuccess */Block.__(0, [filenames]);
    default:
      return /* ShellFailure */Block.__(3, ["Sorry that command is invalid"]);
  }
}

function newPrompt(history, prevCmdExitStatus, id, cmd) {
  var emptyPrompt_000 = /* text : array */[""];
  var emptyPrompt_001 = /* id */id + 1 | 0;
  var emptyPrompt = /* record */[
    emptyPrompt_000,
    emptyPrompt_001,
    /* exitCode : None */0,
    /* cmd */"",
    /* error : None */0
  ];
  switch (prevCmdExitStatus.tag | 0) {
    case 0 : 
        return /* :: */[
                /* record */[
                  /* text */prevCmdExitStatus[0],
                  /* id */id,
                  /* exitCode : Some */[0],
                  /* cmd */cmd,
                  /* error : None */0
                ],
                history
              ];
    case 1 : 
    case 2 : 
        return /* :: */[
                emptyPrompt,
                history
              ];
    case 3 : 
        return /* :: */[
                /* record */[
                  /* text : array */[""],
                  /* id */id,
                  /* exitCode : Some */[1],
                  /* cmd */cmd,
                  /* error : Some */[prevCmdExitStatus[0]]
                ],
                history
              ];
    
  }
}

var errorsMessages = /* record */[
  /* invalid_dir */"Sorry the directory is invalid",
  /* invalid_cmd */"Sorry that command is invalid",
  /* invalid_file */"Sorry that file is invalid"
];

var commands = /* record */[
  /* ls */"ls",
  /* cat */"cat"
];

exports.errorsMessages = errorsMessages;
exports.commands = commands;
exports.about = about;
exports.showPrompt = showPrompt;
exports.filenames = filenames;
exports.files = files;
exports.history = history;
exports.cat = cat;
exports.helpprg = helpprg;
exports.chsh = chsh;
exports.parseInput = parseInput;
exports.newPrompt = newPrompt;
/* No side effect */
