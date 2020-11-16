#!/bin/env python3

import requests
import json
import re
import time
import os
from bs4 import BeautifulSoup

def getSourceCodeFromURL(url):
  #Sorry for AtCoder Server
  time.sleep(1)

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
  print("What is your AtCoder's name?: ",end="")
  username = input();
  url = "https://kenkoooo.com/atcoder/atcoder-api/results?user="+username #thanks kenkoooo

  jsons = requests.get(url).json()

  for dates in jsons:
    codeurl = "https://atcoder.jp/contests/"+ str(dates["contest_id"]) + "/submissions/" + str(dates["id"])
    print(codeurl+"...")
    print(dates)

    pathtofolder = "result/" + str(dates["contest_id"])
    os.makedirs(pathtofolder,exist_ok=True)

    pathtocode = pathtofolder + "/" + str(dates["problem_id"][-1]) + ".cpp"
    with open(pathtocode,"w") as codefile:
      print(getSourceCodeFromURL(codeurl),file=codefile)

