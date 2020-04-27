# Week 14: Final Project Presentation
## Final Project - Handwash Sensor
### Project Goal
The project aims to remind people to wash their hands during this special time. There are two features. Firstly, the device will detect the entrance and remind the user to wash their hands via the speaker. When the user is at the sink, the device will remind the user to wash their hands for at least 20 seconds. During washing, the LED light will stay in red color until the user finishes the washing process. The project successfully achieved both the described goals.

### Choices of Hardware and Software
Due to the shortage of Arduino parts during this special time period. I was not able to acquire the parts that I needed in the first place. I had to replace the RFID sensor to the LDR sensor to achieve a similar goal. While the LDR sensor is not used to detect object specifically, I change the measurement to measure the change of LDR Value. In this way, when the door is open or the user approaches the sink, the change of the LDR value will be sufficient to trigger the device. If available, the LDR sensor can be changed to a RFID sensor. In this way, the device can recognize difference entries.

### Schematic
(There's no option to add a Mp3 Shield)
![](images/final_schematic_.png)

### Assemble
#### Part List
* Arduino Uno
* Mp3 Shield
* Speaker
* LDR Sensor (Distance/RFID Sensor)
* RGB LED
#### Putting Together
* Solder the Mp3 Shield to female and male pins
* Record voice files for door entry and sink approachment
* Name the files as "trackXXX.mp3" eg. track001.mp3
* Assemble Mp3 Shield, RGB LED, and LDR Sensor 
#### Coding Time
* Test Mp3 Shield, RGB LED, and LDR Sensor <b>Separately</b> with the built-in libraries
* Download the code from the Final Folder and test it out
#### Ta-Da ✴️
* Enjoy your smart device and stay healthy!!


### Project Pictures
(The sink gif will last more than 30 seconds thus omitted)
![](images/final_demo.gif)
### Demo Video
Please check the video with both scenarios described and closed up pictures!

https://youtu.be/t-UoP0QwfdU

### Punch List
#### Essential
* Detect entry ✅
* Detect sink approachment ✅
* Make speaker play notification sound ✅
* Change LED light to green for clear status ✅
* Change LED light to red for warning status ✅
#### Nice-to-have
* Detect if the user has finished the entry ✅
* Return to default state automatically ✅
* Time the user to wash their hands for at least 20 seconds ✅


# Week 13: MVP Update
## Final Project - Handwash Sensor
### MVP Update
Due to the shortage of Arduino parts during this special time period. I was not able to acquire the parts that I needed in the first place. Therefore, I developed the project with the parts that I had from the Midterm. I replaced the RFID sensor to the LDR sensor to achieve a similar goal.
At the default state, the LED will be in green light to notify the safe state. When the user came back from the house, the LED will then change to red color and the MP3 shield will play pre-record voice notification via the speaker. After the user leave, the light will turn green again to detect the next person who is going to enter the house.

![](images/final_demo.gif)

# Week Ten - Week Fourteen
## Final Project - Handwash Sensor
### Project Brief
The final project will serve as a smart assistant to remind users to wash their hands during the pandemic season. Due to the shortage of parts, I will re-use parts from the midterm project to deliver a similar effect to the desired deliverable. The project will have two features. Firstly, the sensor will detect if the user has left the house. If so, the sensor will remind the user to wash their hands when they are back. The second feature will be a reminder at the sink. After the user is back, the sensor will remind the user to wash their hands until the user approaches the sensor and finish the handwashing process. 

The project aims to help people to stay safe during the coronavirus outbreak. With simple parts and assemble instructions, everyone can afford a smart reminder. 

### Scenarios
Here I illustrated two main features for the device.

![](images/final_scenario.png)

### MVP Version
The MVP will be divided into four pieces. The LDR sensor will serve as a substitute for the distance sensor / RFID due to the fact that it can be difficult to acquire them now. The LED will signify action detection. It will change to red color if anyone enters the house. I will keep using the speaker to trigger the sound notification.
* LDR (Distance sensor/RFID)
* LED Light
* Mp3 Shield
* Speaker

### Nice-to-have Features
* Identify who is back and remind them to wash their hands (Unique ID)
* Check if the user has washed their hands for at least 20 seconds
* Check if the user is washing in the right way

### Electric Schematic
This echematic diagram will satisfy both features with slight change of the code only. 

![](images/final_schematic.png)

### Pseudocode
#### 1. Re-enter Detection
If LDR Value >= Threshold_Enter<br/>
&nbsp;&nbsp;&nbsp;&nbsp;LED.light = Red<br/>
&nbsp;&nbsp;&nbsp;&nbsp;Speaker.play(Audio1.mp3)<br/>
else
&nbsp;&nbsp;&nbsp;&nbsp;LED.light = Green
#### 2. Handwashing Reminder
If LDR Value >= Threshold_Wash<br/>
&nbsp;&nbsp;&nbsp;&nbsp;LED.light = Red<br/>
&nbsp;&nbsp;&nbsp;&nbsp;Speaker.play(Audio2.mp3)<br/>
If TimeLapse >= 20 Seconds
&nbsp;&nbsp;&nbsp;&nbsp;LED.light = Green



# Week Four - Week Eight
## Midterm Project - Auto-humidifier
My first iteration works well as the final product. The device will not only ask Alexa to turn on the humidifier when it detects low humidity but also will tell the user how is the weather via the LDR sensor. Also, with the indication of LED, the user can immediately know if the current humidity is high or low. 

### Quick Demo
![](images/midterm.gif)

### Video Demo
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





