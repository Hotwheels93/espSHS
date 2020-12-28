import time
import board
import adafruit_dht
import mysql.connector
import datetime

# Change to your database
mydb = mysql.connector.connect(
  host="YOURDBHOSTNAME",
  user="DBUser",
  password="DBPassword",
  database="DBName"
)

dhtDevice = adafruit_dht.DHT22(board.D14, use_pulseio=False)

while True:
    try:
        temperature_c = dhtDevice.temperature
        humidity = dhtDevice.humidity
        #Insert into db
        mycursor = mydb.cursor()
        sql = """UPDATE current_temperature SET temperature = %s, humidity=%s WHERE id =%s"""
        val = (temperature_c, humidity, 1)
        mycursor.execute(sql, val)
        mydb.commit()
        print("DHT22 Data:", datetime.datetime.now())
        print("Temperature: ", temperature_c)
        print("Humidity:", humidity)
        print(mycursor.rowcount, "Data successfully updated.")
        print("")
    except RuntimeError as error:
        print(error.args[0])
        time.sleep(2.0)
        continue
    except Exception as error:
        dhtDevice.exit()
        raise error
    time.sleep(20.0)
