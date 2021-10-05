#!/usr/bin/env python3

import requests

head={"user-agent":"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/91.0.4472.124 Safari/537.36"}
# url="https://api.ixiaowai.cn/api/api.php"		#
url="https://api.ixiaowai.cn/gqapi/gqapi.php"

res=requests.get(url=url,headers=head)
print(res.status_code)
with open("bg.jpg","wb+")as f:
	f.write(res.content)
	f.close()
res.close()