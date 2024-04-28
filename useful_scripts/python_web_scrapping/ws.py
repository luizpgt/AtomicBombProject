from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
from time import sleep

browser = webdriver.Firefox()
file1 = open('myfile.txt', 'w')
#browser.get('https://boards.4channel.org/vt/thread/55649282')
browser.get('https://www.erome.com/a/H3z4Kpjp')
#assert '4chan' in browser.title
#content = browser.find_element(By.CLASS_NAME, 'content')
sleep(5)
#elem = browser.find_element(By.NAME, 'p')  # Find the search box
#elem.send_keys('seleniumhq' + Keys.RETURN)
#elems = browser.find_elements(By.CLASS_NAME, 'fileThumb')
elems = browser.find_elements(By.TAG_NAME, 'img')
for elem in elems:
    href=elem.get_attribute("src")
    file1.write(str(href))
    file1.write("\n")
    print(href)
#browser.quit()
file1.close()
