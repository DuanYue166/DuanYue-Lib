from lib2to3.pgen2 import driver
from selenium import webdriver
import json
from time import sleep 
  
 
chrome_options = webdriver.ChromeOptions()
 
chrome_options.add_argument('--headless')
 
chrome_options.add_argument('--disable-gpu')
 
chrome_options.add_argument('--no-sandbox') # 这个配置很重要
 
driver = webdriver.Chrome(chrome_options=chrome_options)    # 如果没有把chromedriver加入到PATH中，就需要指明路径
# driver=webdriver.Chrome()
 
driver.get('https://buff.163.com/market/csgo#tab=selling&page_num=1')

print("#1")
with open('coockies.json','r') as f:
	cookies_list=json.load(f)
	for cookie in cookies_list:
		driver.add_cookie(cookie)
	f.close()

print("#2")
driver.refresh()
sleep(2)

print("#3")
page_source=driver.page_source
with open('page1.html','w+',encoding='utf-8') as f:
	f.write(page_source)
	f.close()

driver.quit()