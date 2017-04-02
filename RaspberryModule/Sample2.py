import sqlite3
import json
import urllib2
import requests
import time


class Updater():
	def __init__(self, application_id, secret_id, api_version = "v1", time_out = 30, verbose = True):
		self.application_id = application_id
		self.secret_id = secret_id
		self.api_version = api_version
		self.time_out = time_out
		self.base_url = "http://api.backendless.com/"+self.api_version
		self.generalHeaders = {'application-id': self.application_id,
                                'secret-key': self.secret_id,
                                'Content-type':'application/json',
                                'application-type': 'REST'}
		print self.generalHeaders
		self.verbose = verbose
		self.user_token = ""
		self.active_login = False
	def post1(self, url, headers, data):
		print data
		response = ""
		print url
		try:
			response = requests.post(url, data=json.dumps(data), headers=headers, timeout=15)
		except Exception as e:
			print e
		return response
	def put(self, url, headers, data):
		print url
		response = ""
		try:
			response = requests.put(url, headers=headers, data=json.dumps(data))
		except Exception as e:
			print e
		return response

	def get(self, url, headers):
		response = ""
		print url
		try:
			response = requests.get(url, headers=headers)
		except Exception as e:
			print e
		return response
	def getDataFromTable(self, REGION_NUM):	
	   try:
		cur = con.execute('SELECT * FROM SPACES_UPDATE WHERE REGION_NUM = ?', REGION_NUM)		
		return cur
	   except Exception as e:
		print e
	def getNumberOfRegions(self):
	   try:
		cur = con.execute('SELECT REGION_NUM FROM SPACES_UPDATE REGION_NUM')
		return cur
	   except Exception as e:
		print e
updater = Updater(  "A7B592CB-6F8B-B207-FFE8-3706A8A51100",   "AA29AB77-265B-016D-FF75-597FA2F18A00")
while True:
   con = sqlite3.connect('/home/pi/testDb1.db', timeout=30)
   cursor1 = updater.getNumberOfRegions()
   for row1 in cursor1:
	REGN = row1[0]   
   	string = updater.base_url + "/data/SPACES?where=REGION_NUM%3D" + str(REGN)
	print string
   	try:
		
		response = updater.get(string, 		updater.generalHeaders)
		print response

		data = response.json()
		arr = {}
		arr2 = [0, 0, 0, 0]
		




		for obj in data['data']:
			print "OBJECT:"
			print obj['REGION_NUM']
			print obj['SPACE_NUM']
			arr2[obj['SPACE_NUM']] = 1
			print obj['FREE']
			print obj['objectId']
			key = obj['SPACE_NUM']
			val = obj['objectId']
			arr.update({key:val})


		print arr2
		print arr
		cursor = updater.getDataFromTable(str(REGN))
		for row in cursor:
			print row [0] #ID
			print row [1] #SPACE_NUM 
			print row [2] #REGION_NUM
			print row [3] #FREE
			val1 = row[1]
			val2 = row[2]
			val3 = row[3]
			val4 = row[4]
			if(arr2[row[1]] == 0):
			#post data online
				dataToPost = { 'SPACE_NUM': val1,
						'REGION_NUM': val2,
						'FREE': val3,
						'UPDATE_TIME': row[4]
					}
				print dataToPost
				
				resp = updater.post1(updater.base_url + "/data/SPACES", updater.generalHeaders, dataToPost)
				print resp
			else:
				dataToPost = { 'FREE': val3,
					'UPDATE_TIME': val4
					}
				resp = updater.put(updater.base_url + "/data/SPACES/" + arr[val1], updater.generalHeaders, dataToPost)
				print resp
		
   	except Exception as e:
		print e
	time.sleep(25)
