#!/usr/bin/env python3

import requests
import json
import os

from util import getSourceCodeFromURL

if __name__ == "__main__":
  #ask name
  print("What is your AtCoder's name?: ",end="")
  username = str(input())

  #thanks kenkoooo
  jsons = requests.get("https://kenkoooo.com/atcoder/atcoder-api/results?user="+username).json()
  #put codes sum
  print("found " + str(len(jsons)) + "codes")

  #ask collect target
  print("Collect file include WA and some errors?[y/n]: ",end="")
  collectall=False
  if input() == "y":
    collectall=True
    print("Collect All")
  else:
    collectall=False
    print("Collect only AC file")

  for dates in jsons:
    #generate code url
    codeurl = "https://atcoder.jp/contests/"+ str(dates["contest_id"]) + "/submissions/" + str(dates["id"])

    #put url
    print(codeurl+": "+dates["result"])

    if not collectall and dates["result"] != "AC":
      continue

    #make folder
    pathtofolder = "result/" + str(dates["contest_id"])
    os.makedirs(pathtofolder,exist_ok=True)

    #touch file
    pathtocode = pathtofolder + "/" + str(dates["problem_id"][-1]) + ".cpp"
    with open(pathtocode,"w") as codefile:
      print(getSourceCodeFromURL(codeurl),file=codefile)
