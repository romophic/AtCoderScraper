import requests
import time
from bs4 import BeautifulSoup

def getSourceCodeFromURL(url):
  #Sorry for AtCoder Server
  time.sleep(0)

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
