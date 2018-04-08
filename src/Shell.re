type errors = {
  invalid_dir: string,
  invalid_cmd: string,
  invalid_file: string,
};

let errorsMessages = {
  invalid_dir: "Sorry the directory is invalid",
  invalid_cmd: "Sorry that command is invalid",
  invalid_file: "Sorry that file is invalid",
};

type commandTypes = {
  ls: string,
  cat: string,
};

let commands = {ls: "ls", cat: "cat"};

let about = [|
  "I trained as a Medical Doctor at King's college london.",
  {j|Unfortunately after 8 years of studying, training, many an up and down
      I realised that it wasn't for me and parted ways with that time of my life.
        |j},
  {j| As understandeably unusual a choice as it might seem I much preferred tinkering with computers
      I'd spent much of my youth messing around with hardware but it wasn't really till the fateful summer having just
      decided to leave my job that I discovered github and the rest is history...
      |j},
  {j|Actually the rest is me meeting a bunch of other aspiring developers, our forming a group to teach each other
      then my finding out about founders and coders in London|j},
|];

type prompts = {
  text: array(string),
  id: int,
  exitCode: option(int),
  cmd: string,
  error: option(string),
};

let showPrompt = (~user="Akin_Sowemimo", ~dir="root", ()) =>
  "/Users/" ++ user ++ "/" ++ dir ++ ":";

type fileType = {
  about: array(string),
  comingSoon: array(string),
};

let filenames = [|"about.txt", "coming_soon.txt"|];

let files = {about, comingSoon: [|"coming soon"|]};

let history = [{text: [|""|], id: 1, cmd: "", exitCode: None, error: None}];

type exitResult =
  | ShellSuccess(array(string))
  | ShellReset(list(prompts))
  | ChangeShell(string)
  | ShellFailure(string);

let cat = (arg: string) =>
  switch (arg) {
  | "about.txt" => ShellSuccess(files.about)
  | "coming_soon.txt" => ShellSuccess(files.comingSoon)
  | _ => ShellFailure(errorsMessages.invalid_file)
  };

let helpprg = (arg: string) =>
  switch (arg) {
  | ""
  | _ => [|
      "--Commands: type a terminal command",
      "options are: cat 'arg', ls, help, clear",
    |]
  };

let chsh = (shell: string) =>
  switch (shell) {
  /* | "-h" => [|"available shells include -", " fish, zsh and bash"|] */
  | "fish" => "fish"
  | "zsh" => "zsh"
  | ""
  | _ => "bash"
  };

let parseInput = (input: string, arg: string) =>
  switch (input) {
  | "ls" => ShellSuccess(filenames)
  | "cat" => cat(arg)
  | "help" => ShellSuccess(helpprg(arg))
  | "chsh" => ChangeShell(chsh(arg))
  | "clear"
  | "cl" => ShellReset(history)
  | _ => ShellFailure(errorsMessages.invalid_cmd)
  };

let newPrompt = (~history, prevCmdExitStatus, id, cmd) => {
  let emptyPrompt = {
    text: [|""|],
    id: id + 1,
    cmd: "",
    error: None,
    exitCode: None,
  };
  switch (prevCmdExitStatus) {
  | ShellSuccess(result) => [
      {text: result, error: None, id, exitCode: Some(0), cmd},
      ...history,
    ]
  | ShellFailure(result) => [
      {text: [|""|], id, error: Some(result), exitCode: Some(1), cmd},
      ...history,
    ]
  | _ => [emptyPrompt, ...history]
  };
};
