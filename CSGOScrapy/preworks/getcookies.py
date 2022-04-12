from selenium import webdriver
from time import sleep
import json

driver=webdriver.Chrome()

driver.get('https://buff.163.com/market/csgo#tab=selling&page_num=1&category_group=pistol&max_price=30')

sleep(60)

with open('coockies.json','w+',encoding='utf-8') as f:
	f.write(json.dumps(driver.get_cookies()))
	f.close()
driver.quit()