#!/usr/bin/env python3

import requests
import json
import os
import time
import subprocess
import platform

from bs4 import BeautifulSoup

parentfordername = os.path.dirname(__file__) + "/AtCoder"
cachefilename = os.path.dirname(__file__) + "/data.json"

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

def getTimeFromUnixTime(time):
  if(platform.system() == "Linux"):
    return str(subprocess.check_output(["date","--date=@" + str(time)]))
  else:
    return str(subprocess.check_output(["date","-r",str(time)]))

def ifFileFound():
  #get old data
  oldjson = json.load(open(cachefilename))

  #set name
  username = oldjson[0]["user_id"]

  #thanks kenkoooo
  jsons = requests.get("https://kenkoooo.com/atcoder/atcoder-api/results?user="+username).json()
  #put how many codes
  print("Found new " + str(len(jsons)-len(oldjson)) + " codes")

  for dates in jsons:
    #generate code url
    codeurl = "https://atcoder.jp/contests/"+ str(dates["contest_id"]) + "/submissions/" + str(dates["id"])

    #result
    print(codeurl+": ",end="")
    if dates["result"] != "AC":
      print("WA")
      continue
    else:
      tr = False
      for olddates in oldjson:
        if olddates["id"] == dates["id"]:
          tr=True
          print("Same")

      if tr:
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
    git_commit_code="git commit -m \""+codeurl+"\" --date=\""+getTimeFromUnixTime(dates["epoch_second"])+"\""
    os.system(git_add_code)
    os.system(git_commit_code)

  #write json date
  print("write json date")
  with open(cachefilename,"w") as oldjsonfile:
    json.dump(jsons,oldjsonfile)

def ifFileNotFound():
  #ask name
  print("What is your AtCoder's name?: ",end="")
  username = str(input())

  #thanks kenkoooo
  jsons = requests.get("https://kenkoooo.com/atcoder/atcoder-api/results?user="+username).json()
  #put how many codes
  print("found " + str(len(jsons)) + "codes")

  for dates in jsons:
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
    git_add_code=["git","add",pathtocode]
    git_commit_code=["git","commit","-m","\""+codeurl+"\"","--date=\""+getTimeFromUnixTime(dates["epoch_second"])+"\""]

    subprocess.run(git_add_code,cwd=os.path.dirname(__file__))
    subprocess.run(git_commit_code,cwd=os.path.dirname(__file__))

  #write json date
  print("write json date")
  with open(cachefilename,"w") as oldjsonfile:
    json.dump(jsons,oldjsonfile)

  return

if __name__ == "__main__":
  if(os.path.isfile(cachefilename)):
    print("Found cache file")
    ifFileFound()
  else:
    print("Not found cache file")
    ifFileNotFound()

  subprocess.run(["git","push"],cwd=os.path.dirname(__file__))
