type errors = {
  invalid_dir: string, invalid_cmd: string,
  invalid_file: string,
};

let errorsMessages = {
  invalid_dir: "Sorry the directory is invalid",
  invalid_cmd: "Sorry that command is invalid",
  invalid_file: "Sorry that file is invalid",
};

let prompt = "/Users/akin_sowemimo/root";

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

let showPrompt = () => prompt ++ ":";

type fileType = {about: array(string)};

let files = {about: about};

let ls = () => files;
