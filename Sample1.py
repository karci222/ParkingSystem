
import bluepy.btle as btle
import time as time
import sqlite3 
import datetime

class TableRecord():
	def __init__(self, SPACE_NUM, REGION_NUM, FREE):
		self.SPACE_NUM = SPACE_NUM
		self.REGION_NUM = REGION_NUM
		self.FREE = FREE
	def addToDatabase(self, conn):
		print self.SPACE_NUM
		print self.REGION_NUM
		print self.FREE
		now = datetime.datetime.now()
		cur = conn.cursor()
		cur.execute('INSERT INTO SPACES(SPACE_NUM, REGION_NUM, FREE, STAMP) VALUES (?, ?, ?, ?)',  (self.SPACE_NUM, self.REGION_NUM, self.FREE, now)) 
		conn.commit()
		print "Adding to database"

class ScanDelegate(btle.DefaultDelegate):
    def __init__(self):
        btle.DefaultDelegate.__init__(self)

    def handleDiscovery(self, dev, isNewDev, isNewData):
        if isNewDev:
            print "Discovered device", dev.addr
	    if(dev.addr == "d4:12:82:58:bd:25"):
	    	print "Here"
            	p = btle.Peripheral (dev.addr, btle.ADDR_TYPE_RANDOM)
            	p.setDelegate(NotificationDelegate())
		chars = p.getCharacteristics()
		for charac in chars:
			print charac.uuid
			print charac.getHandle()
			print charac.supportsRead()
			print charac.propertiesToString()
            	print "there"
		while True:
			for charac in chars:
				if(charac.uuid == "0000ffee-0000-1000-8000-00805f9b34fb" or charac.uuid == "0000bab1-0000-1000-8000-00805f9b34fb" or charac.uuid == "0000bab2-0000-1000-8000-00805f9b34fb"):
					s = charac.read()
					val = 0
					for char in reversed(s): 
						val = val * 8 + ord(char) 
					print charac.uuid
					if (charac.uuid == "0000ffee-0000-1000-8000-00805f9b34fb"):
						FREE = val
					if (charac.uuid == "0000bab2-0000-1000-8000-00805f9b34fb"):
						SpaceNum = val
					if (charac.uuid == "0000bab1-0000-1000-8000-00805f9b34fb"):
						RegionNum = val
					print val

			i = 0			
			while i < SpaceNum:
				print "In while"
				spacei = FREE & 1
				FREE = FREE >> 1
				tableRec = TableRecord(i, RegionNum, spacei)
				tableRec.addToDatabase(con)
				i = i + 1

			time.sleep(0.7)
        elif isNewData:
            print "Received new data from", dev.addr

class NotificationDelegate(btle.DefaultDelegate):
    def __init__(self):
        btle.DefaultDelegate.__init__(self)
    def handleNotification(self, cHandle, data):
	print "notification"


con = sqlite3.connect('/home/pi/testDb1.db')

scanner = btle.Scanner().withDelegate(ScanDelegate())
devices = scanner.scan(10.0)




