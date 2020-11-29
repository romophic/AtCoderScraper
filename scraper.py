#!/usr/bin/env python3

import requests
import json
import os
import time
import subprocess

from bs4 import BeautifulSoup

def getSourceCodeFromURL(url):
  #get source code from url
  soup = BeautifulSoup(requests.get(url).content, "html.parser").find("pre")
  sourcecode = str(soup)

  #make it clean
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


if __name__ == "__main__":
  parentfordername = "result"

  #ask name
  print("What is your AtCoder's name?: ",end="")
  username = str(input())

  #thanks kenkoooo
  jsons = requests.get("https://kenkoooo.com/atcoder/atcoder-api/results?user="+username).json()
  #put how many codes
  print("found " + str(len(jsons)) + "codes")

  for dates in jsons:
    break
    #generate code url
    codeurl = "https://atcoder.jp/contests/"+ str(dates["contest_id"]) + "/submissions/" + str(dates["id"])

    #put url
    print(codeurl+": "+dates["result"])

    if dates["result"] != "AC":
      continue

    #make folder
    pathtofolder = parentfordername+"/" + str(dates["contest_id"])
    os.makedirs(pathtofolder,exist_ok=True)

    #touch file
    pathtocode = pathtofolder + "/" + str(dates["problem_id"][-1]) + ".cpp"
    with open(pathtocode,"w") as codefile:
      print(getSourceCodeFromURL(codeurl),file=codefile)

    #commit to git
    git_add_code="git add " + pathtocode
    git_commit_code="git commit -m \""+codeurl+"\" --date=\"" + str(subprocess.check_output(["date","-r",str(dates["epoch_second"])]))+"\""
    os.system(git_add_code)
    os.system(git_commit_code)


  #write json date
  print("write json date")
  with open("olddate.json","w") as oldjsonfile:
    print(jsons,file=oldjsonfile)
