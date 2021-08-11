#!/usr/bin/env python3

#      _   _    ____          _           ____                                   #
#     / \ | |_ / ___|___   __| | ___ _ __/ ___|  ___ _ __ __ _ _ __   ___ _ __   #
#    / _ \| __| |   / _ \ / _` |/ _ \ '__\___ \ / __| '__/ _` | '_ \ / _ \ '__|  #
#   / ___ \ |_| |__| (_) | (_| |  __/ |   ___) | (__| | | (_| | |_) |  __/ |     #
#  /_/   \_\__|\____\___/ \__,_|\___|_|  |____/ \___|_|  \__,_| .__/ \___|_|     #
#                                                             |_|

import requests
import json
import os
import time
import subprocess
import platform
from bs4 import BeautifulSoup

# consts
runningpath = os.path.abspath(os.path.dirname(__file__))
parentfordername = "AtCoder"
cachefilename =  "data.json"
waitsec = 1
languagecorrespondence = [
  # from https://atcoder.jp/contests/APG4b/rules
  # The language extracts the characters before the parentheses
  # (language, expand)
  ("C","c"),
  ("C++", "cpp"),
  ("C++14", "cpp"),
  ("C++17", "cpp"),
  ("Java", "java"),
  ("Python", "py"),
  ("Bash", "sh"),
  ("bc", "bc"),
  ("Awk", "awk"),
  ("C#", "cs"),
  ("Clojure", "clj"),
  ("Crystal", "cr"),
  ("D", "d"),
  ("Dart", "dart"),
  ("dc", "dc"),
  ("Erlang", "erl"),
  ("Elixir", "ex"),
  ("F#", "fs"),
  ("Forth", "fs"),
  ("Fortran", "f08"),
  ("Go", "go"),
  ("Haskell", "hs"),
  ("Haxe", "hx"),
  ("Javascript", "js"),
  ("Julia", "jl"),
  ("Kotlin", "kt"),
  ("Lua", "lua"),
  ("Dash", "sh"),
  ("Nim", "nim"),
  ("Objective-C", "m"),
  ("Common Lisp" , "lisp"),
  ("OCaml", "ml"),
  ("Octave", "m"),
  ("Pascal", "pas"),
  ("Perl", "pl"),
  ("Raku", "p6"),
  ("PHP", "php"),
  ("Prolog", "pl"),
  ("PyPy2", "py"),
  ("PyPy3", "py"),
  ("Racket", "rkt"),
  ("Ruby", "rb"),
  ("Rust", "rs"),
  ("Scala", "scala"),
  ("Java", "java"),
  ("Scheme", "scm"),
  ("Standard ML", "sml"),
  ("Swift", "swift"),
  ("Text", "txt"),
  ("TypeScript", "tsc"),
  ("Visual Basic", "vb"),
  ("Zsh", "sh"),
  ("COBOL - Fixed", "cob"),
  ("COBOL - Free", "cob"),
  ("Brainfuck", "bf"),
  ("Ada2012", "adb"),
  ("Unlambda", "unl"),
  ("Cython", "pyx"),
  ("Sed", "sed"),
  ("Vim", "vim"),
]

def getSourceCodeFromURL(url) -> str:
  soup = BeautifulSoup(requests.get(url).content, "html.parser").find("pre")
  sourcecode = str(soup)

  #remove <pre .. >
  for i in range(len(sourcecode)):
    if sourcecode[i] == '>':
      sourcecode = sourcecode[i+1:]
      break

  #remove tail </pre>
  sourcecode = sourcecode[:-6]

  #replace some special chars
  # < &lt;
  sourcecode = sourcecode.replace("&lt;","<")

  # > &gt;
  sourcecode = sourcecode.replace("&gt;",">")

  # & &amp;
  sourcecode = sourcecode.replace("&amp;","&")

  #replace CRLF to LF
  sourcecode = sourcecode.replace("\r","")

  return sourcecode

def getTimeFromUnixTime(time) -> str:
  if(platform.system() == "Linux"):
    return str(subprocess.check_output(["date","--date=@" + str(time)]))
  else:
    return str(subprocess.check_output(["date","-r",str(time)]))
  return

def judgeWhichLanguage(language) -> str:
  language = language[:language.find("(")-1]
  for lang in languagecorrespondence:
    if lang[0] == language:
      return "." + lang[1]

  return ""

def addAndCommit(contestid,problemid,codeurl,epochsecond,language):
  pathtocontest = runningpath + "/" + parentfordername + "/" + str(contestid)
  contestfilename = str(problemid) + judgeWhichLanguage(language);

  os.makedirs(pathtocontest,exist_ok=True)

  with open(pathtocontest + "/" + contestfilename,"w") as codefile:
    print(getSourceCodeFromURL(codeurl),file=codefile)

  subprocess.run(["git","add",parentfordername+"/"+str(contestid)+"/"+contestfilename],cwd=runningpath)
  subprocess.run(["git","commit","-m",codeurl,"--date="+getTimeFromUnixTime(epochsecond)],cwd=runningpath)

def ifFileFound():
  oldjson = json.load(open(runningpath+"/"+cachefilename,'r'))

  username = oldjson[0]["user_id"]

  #thanks kenkoooo
  jsons = requests.get("https://kenkoooo.com/atcoder/atcoder-api/results?user="+username).json()
  print("Found new " + str(len(jsons)-len(oldjson)) + " codes")

  for jsn in jsons:
    time.sleep(waitsec)

    codeurl = "https://atcoder.jp/contests/"+ str(jsn["contest_id"]) + "/submissions/" + str(jsn["id"])

    if jsn["result"] != "AC":
      continue
    else:
      tr = False
      for olddates in oldjson:
        if olddates["id"] == jsn["id"]:
          tr=True

      if tr:
        continue

    addAndCommit(jsn["contest_id"],jsn["problem_id"][-1],codeurl,jsn["epoch_second"],jsn["language"])

  print("write json date")
  with open(runningpath+"/"+cachefilename,"w") as oldjsonfile:
    json.dump(jsons,oldjsonfile)

def ifFileNotFound():
  print("What is your AtCoder's name?: ",end="")
  username = str(input())

  #thanks kenkoooo
  jsons = requests.get("https://kenkoooo.com/atcoder/atcoder-api/results?user="+username).json()
  print("found " + str(len(jsons)) + "codes")

  for jsn in jsons:
    time.sleep(waitsec)

    codeurl = "https://atcoder.jp/contests/"+ str(jsn["contest_id"]) + "/submissions/" + str(jsn["id"])

    if jsn["result"] != "AC":
      continue

    addAndCommit(jsn["contest_id"],jsn["problem_id"],codeurl,jsn["epoch_second"],jsn["language"])

  print("write json date")
  with open(runningpath+"/"+cachefilename,"w") as oldjsonfile:
    json.dump(jsons,oldjsonfile)

  return

if __name__ == "__main__":
  if(os.path.isfile(runningpath+"/"+cachefilename)):
    print("Found cache file")
    ifFileFound()
  else:
    print("Not found cache file")
    ifFileNotFound()

  subprocess.run(["git","push"],cwd=runningpath)
