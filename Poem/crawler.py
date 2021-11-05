import requests
import xml.dom.minidom
import time
import os

# url="https://v2.jinrishici.com/one.svg?font-size=50&spacing=1&color=purple"
url="https://v1.jinrishici.com/rensheng.txt"
head={"user-agent":"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/95.0.4638.69 Safari/537.36"}
proxies={"http":"","https":""}

temp=open("temp","r")
i=int(temp.read())
temp.close()
las=time.time()
while(i<=20000):
	if(time.time()-las>1):
		las=time.time()
		p=i/20000*100
		os.system("cls")
		print("%.2lf%%" % p)
	res=requests.get(url=url,headers=head,proxies=proxies)
	if(res.status_code!=200):
		os.system("cls")
		print("Access failed with #%d" % res.status_code)
		exit()
	with open("poems.dat","a+",encoding="utf-8") as f:
		f.write("%s\n" % res.text)
		f.close()
	res.close()
	i+=1
	temp=open("temp","w+")
	temp.write(str(i))
	temp.close()
	time.sleep(0.3)
print("Done!")
'''
for i in range(1,2001):
	res=requests.get(url=url,headers=head)
	with open("text.xml","w+",encoding="utf-8") as f:
		f.write(res.text)
		f.close()
	res.close()

	root=xml.dom.minidom.parse("text.xml")
	collection=root.documentElement
	g=collection.getElementsByTagName("g")
	text=g[0].getElementsByTagName("text")
	with open("poems.dat","a+",encoding='utf-8') as f:
		f.write("%s\n" % text[0].childNodes[0].data)
		
	time.sleep(1)
'''