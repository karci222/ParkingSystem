#test.py
try:
    import tkinter as tk  # for python 3
except:
    import Tkinter as tk  # for python 2
import pygubu

import sqlite3
import json
import urllib2
import requests
import time
con = sqlite3.connect('/home/pi/testDb1.db', timeout=30)


class Application:
    def __init__(self, master):
	

        #1: Create a builder
        self.builder = builder = pygubu.Builder()

        #2: Load an ui file
        builder.add_from_file('AdminSimpleApplication.ui')

        #3: Create the widget using a master as parent
        self.mainwindow = builder.get_object('Frame_13', master)
	
	builder.connect_callbacks(self)
	
	self.label1 = builder.get_object('number_of_spaces', master)
	self.label2 = builder.get_object('number_of_free_spaces', master)
	self.label3 = builder.get_object('number_of_occupied_spaces', master)
	self.button = builder.get_object('reload_button', master)
	print 'Built'	
	
	rows = self.get_number_of_spaces()
	for row in rows:
		val1 = row[0]
		print val1
	rows = self.get_number_of_free_spaces()
	for row in rows:
		val2 = row[0]
		print val2
	rows = self.get_number_of_occupied_spaces()
	for row in rows:
		val3 = row[0]	
		print val3

	self.label1.config(text=str(val1))
	self.label2.config(text=str(val2))
	self.label3.config(text=str(val3))
	self.button.config(command=self.on_reload_button_click)

    def on_reload_button_click(self):
	print 'Click!!'
	rows = self.get_number_of_spaces()
	for row in rows:
		val1 = row[0]
	rows = self.get_number_of_free_spaces()
	for row in rows:
		val2 = row[0]
	rows = self.get_number_of_occupied_spaces()
	for row in rows:
		val3 = row[0]	

	self.label1.config(text=str(val1))
	self.label2.config(text=str(val2))
	self.label3.config(text=str(val3))

    def get_number_of_spaces(self):
	cur = con.execute('SELECT COUNT(*) FROM SPACES_UPDATE')
	return cur
    def get_number_of_free_spaces(self):
	cur = con.execute('SELECT COUNT(*) FROM SPACES_UPDATE WHERE FREE=0')
	return cur
    def get_number_of_occupied_spaces(self):
	cur = con.execute('SELECT COUNT(*) FROM SPACES_UPDATE WHERE FREE=1')
	return cur
	
	

if __name__ == '__main__':
    root = tk.Tk()
    app = Application(root)
    root.mainloop()
