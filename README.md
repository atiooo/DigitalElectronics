# Week Four - Week Eight
## Midterm Project - Auto-humidifier
My first iteration works well as the final product. The device will not only ask Alexa to turn on the humidifier when it detects low humidity but also will tell the user how is the weather via the LDR sensor. Also, with the indication of LED, the user can immediately know if the current humidity is high or low. 

![](images/midterm_video.png)

Please refer this link to the complete video demo:
https://youtu.be/iU1KX62NXqY

### Electric Schematic
![](images/wk3_schematic.png)  

### Code
The code is available in the midterm folder. :)

### Punch List
#### Essential
* Detect the humidity ✅
* Detect the temperature ✅
* Make speaker play a recorded sound ✅
* Make the RGB light for low and high humidity ✅

### Steps
#### Preparation
* DHT22 Sensor * 1
* Adafruit Mp3 Shield * 1
* LDR Sensor * 1
* RGB LED * 1
* Micro SD Card > 64MB * 1
* Speaker * 1
#### Assemble
* Solder the Mp3 Shield to female and male pins
* Record voice files for weather and humidity
* Name the files as "trackXXX.mp3" eg. track001.mp3
* Assemble DHT22, Mp3 Shield, RGB LED, and LDR Sensor 
#### Coding Time
* Test DHT22, Mp3 Shield, RGB LED, and LDR Sensor <b>Separately</b> with the built-in libraries
* Download the code from the Midterm Folder and test it out
#### Ta-Da ✴️
* Enjoy your smart device!


# Week Three
## Midterm Project - Auto-humidifier
![](images/wk3_proj.png)
### Project Description
I would like to create a device that will ask Alexa to turn on the humidifier when it detects low humidity and temperature. The input sensors will be a humidity sensor and a temperature sensor. The output sources will be a speaker and a RGB light. The speaker will tell Alexa to turn on the sensor while the LED will let the user know if the humidity is low, medium or high. 

The code will be based on receiving return values from these two sensors. Based on if statements, we will be able to categorize each return value and determine if we should turn on the humidifier or not. Also, we want to change the RGB light accordingly. 

### Electric Schematic
![](images/wk3_schematic.png)  

### Punch List
#### Essential
* Detect the humidity
* Detect the temperature
* Make speaker play a recorded sound
* Make the RGB light for low, med and high humidity

#### Nice-to-have
* Display the current humidity and temperature
* Draw an image for screen saver based on today's humidity and temperature
* Ask Alexa to do other works based on these two values

# Week Two
## Arduino project I found interesting:
https://www.youtube.com/watch?v=lkl6yVauCKg&feature=youtu.be

![](images/wk2_glasses.png)


## Description: 
This is a Arduino Data Glasses that work together with the Multimeter Owon B35T. With the glasses, the engineer can easily get the voltage without looking at the multimeter, which make their live much easier.

# Week One
My favorite processing sketch from last semester





