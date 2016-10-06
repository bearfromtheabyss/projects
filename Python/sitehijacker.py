"""
This program will automatically fetch all files from server that are accessible via HTTP GET
and will download those files to its own folder.

Functions:
+   Download scripts 
+   Download CSS files
+   Download HTML files

It will be good to add following function:
	1. Take the index.html file and find by regular expression the matching js files, css files and other that are used by the site.
	2. Add them to the list in txt file
	3. use this file to perform HTTP GET scanning on server
"""

from selenium import webdriver
import requests
import os
import re

#url = input('Enter url: ')
print("Welcome to SiteHijacker\nPlease wait while program downloads your site...")

#url = input('URL: ')
url = 'http://www.nauka.gov.pl/'
url += '/'
driver = webdriver.PhantomJS() #get webdriver objectdwada
driver.get(url)

def checkConnect(url, driver):
	req = requests.get(url)
	sc = req.status_code
	if sc == 200:
		print("Server response: You are now connected to -> ", driver.title);
	else:
		print("There was a problem while attempting to connect...")


def getScripts(url):
		jsFiles = ['script', 'main', 'all', 'js', 'modernizr', 'bootstrap.min', 'wow', 'classie', 
				   'jquery-ui.min', 'lightbox.min', 'animatescroll', 'jquery-2.2.3.min']
		print("\nGetting JS files...")
		for name in jsFiles:
			req = requests.get(url + 'js/' + name + '.js')
			if req.status_code == 200:
				print("Found something: ", req.url)
				save2file(driver, req.text, 'js', name)
			else:
				req = requests.get(url + 'assets/js/' + name + '.js')
				print("Found something: ", req.url)
				req.encoding = "utf-8"
				save2file(driver, req.text, 'js', name)
		return True

def getCSS(url):
		cssFiles = ['style']
		print("\nGetting CSS files...")
		for name in cssFiles:
			req = requests.get(url + 'css/' + name + '.css')
			if req.status_code == 200:
				print("Found something: ", req.url)
				save2file(driver, req.text, 'css', name)
			else:
				req = requests.get(url + 'assets/css/' + name + '.css')
				print("Found something: ", req.url)
				req.encoding = "utf-8"
				save2file(driver, req.text, 'css', name)
		return True

def getHTML(url):
		print("\nGetting HTML...")
		name = "index"
		req = requests.get(url)
		req.encoding = 'utf-8'
		save2file(driver, req.text, 'html', name)
		return True

def save2file(driver, text, type, name):
	mypath = "F:/python/" + driver.title
	
	if type == 'js':
		mypath += '/js/' #F:/python/nazwa_strony/js/nazwa.js
		if not os.path.isdir(mypath):
	   		os.makedirs(mypath)
		f = open(mypath + name + ".js", 'w')
		f.write(text)
		f.close()
	if type == 'css':
		mypath += '/css/'
		if not os.path.isdir(mypath):
	   		os.makedirs(mypath)
		f = open(mypath  + name + ".css", 'w')
		f.write(text)
		f.close()
	if type == 'html':
		if not os.path.isdir(mypath):
	   		os.makedirs(mypath)
		f = open(mypath + "/" + name + ".html", 'w')
		f.write(text)
		f.close()

	

checkConnect(url, driver)
if getScripts(url) == True:
	print("JS downloaded successfully.")
if getCSS(url) == True:
	print("CSS downloaded successfully.")
if getHTML(url) == True:
	print("HTML downloaded successfully.")



	





