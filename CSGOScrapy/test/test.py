from lib2to3.pgen2 import driver
from selenium import webdriver
import json
from time import sleep

driver=webdriver.Chrome()

driver.get('https://buff.163.com/market/csgo#tab=selling&page_num=1')

with open('coockies.json','r') as f:
    cookies_list=json.load(f)
    for cookie in cookies_list:
        driver.add_cookie(cookie)
    f.close()

driver.refresh()
sleep(2)

page_source=driver.page_source
with open('page1.html','w+',encoding='utf-8') as f:
    f.write(page_source)
    f.close()

driver.quit()