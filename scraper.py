#!/usr/bin/env python3

import requests
import json
import os
import time
import subprocess
import platform

from bs4 import BeautifulSoup

runningpath = os.path.abspath(os.path.dirname(__file__))
parentfordername = "AtCoder"
cachefilename =  "data.json"

print("running in: " + runningpath)
print("parentfordername: " + parentfordername)
print("cachefilename:  " + cachefilename)

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
  return

def addAndCommit(contestid,problemid,codeurl,epochsecond):
  pathtocontest = runningpath + "/" + parentfordername + "/" + str(contestid)
  contestfilename = str(problemid) + ".cpp"

  #make folder
  os.makedirs(pathtocontest,exist_ok=True)

  #make file
  with open(pathtocontest + "/" + contestfilename,"w") as codefile:
    print(getSourceCodeFromURL(codeurl),file=codefile)

  subprocess.run(["git","add",parentfordername+"/"+str(contestid)+"/"+contestfilename],cwd=runningpath)
  subprocess.run(["git","commit","-m",codeurl,"--date="+getTimeFromUnixTime(epochsecond)],cwd=runningpath)
  return

def ifFileFound():
  #get old data
  oldjson = json.load(open(runningpath+"/"+cachefilename,'r'))

  #set name
  username = oldjson[0]["user_id"]

  #thanks kenkoooo
  jsons = requests.get("https://kenkoooo.com/atcoder/atcoder-api/results?user="+username).json()
  #put how many codes
  print("Found new " + str(len(jsons)-len(oldjson)) + " codes")

  for json in jsons:
    #generate code url
    codeurl = "https://atcoder.jp/contests/"+ str(json["contest_id"]) + "/submissions/" + str(json["id"])

    #result
    print(codeurl+": ",end="")
    if json["result"] != "AC":
      print("WA")
      continue
    else:
      tr = False
      for olddates in oldjson:
        if olddates["id"] == json["id"]:
          tr=True
          print("Same")

      if tr:
        continue

    addAndCommit(json["contest_id"],json["problem_id"][-1],codeurl,json["epoch_second"])

  #write json date
  print("write json date")
  with open(runningpath+"/"+cachefilename,"w") as oldjsonfile:
    json.dump(jsons,oldjsonfile)

def ifFileNotFound():
  #ask name
  print("What is your AtCoder's name?: ",end="")
  username = str(input())

  #thanks kenkoooo
  jsons = requests.get("https://kenkoooo.com/atcoder/atcoder-api/results?user="+username).json()
  #put how many codes
  print("found " + str(len(jsons)) + "codes")

  for json in jsons:
    #generate code url
    codeurl = "https://atcoder.jp/contests/"+ str(json["contest_id"]) + "/submissions/" + str(json["id"])

    #put url
    print(codeurl+": "+json["result"])

    if json["result"] != "AC":
      continue

    print(json["contest_id"])
    print(json["problem_id"])
    print(codeurl)
    print(json["epoch_second"])

    addAndCommit(json["contest_id"],json["problem_id"],codeurl,json["epoch_second"])

  #write json date
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
