// include SPI, MP3 and SD libraries
#include <SPI.h>
#include <Adafruit_VS1053.h>
#include <SD.h>

// These are the pins used for the breakout example
#define BREAKOUT_RESET  9      // VS1053 reset pin (output)
#define BREAKOUT_CS     10     // VS1053 chip select pin (output)
#define BREAKOUT_DCS    8      // VS1053 Data/command select pin (output)
// These are the pins used for the music maker shield
#define SHIELD_RESET  -1      // VS1053 reset pin (unused!)
#define SHIELD_CS     7      // VS1053 chip select pin (output)
#define SHIELD_DCS    6      // VS1053 Data/command select pin (output)

// These are common pins between breakout and shield
#define CARDCS 4     // Card chip select pin
// DREQ should be an Int pin, see http://arduino.cc/en/Reference/attachInterrupt
#define DREQ 3       // VS1053 Data request, ideally an Interrupt pin

Adafruit_VS1053_FilePlayer musicPlayer = 
  // create breakout-example object!
  //Adafruit_VS1053_FilePlayer(BREAKOUT_RESET, BREAKOUT_CS, BREAKOUT_DCS, DREQ, CARDCS);
  // create shield-example object!
  Adafruit_VS1053_FilePlayer(SHIELD_RESET, SHIELD_CS, SHIELD_DCS, DREQ, CARDCS);

#define RGB_R_PIN 9
#define RGB_G_PIN 10
#define RGB_B_PIN 11

#define LDR_PIN A0

// Toggle the if statement to run only once in one action 
bool music1Played = false;

// LDR value to determine base brightness
int ldrBase;

// Threshold of brightness to determine an action
int ldrThreshold = 10;
  
void setup() {
  Serial.begin(9600);

  // Define RGB output and LDR input pins
  pinMode(RGB_R_PIN, OUTPUT);
  pinMode(RGB_G_PIN, OUTPUT);
  pinMode(RGB_B_PIN, OUTPUT);
  pinMode(LDR_PIN, INPUT);

  // Read LDR base brightness
  ldrBase = analogRead(LDR_PIN);
  Serial.print("Base ldr value:");
  Serial.println(ldrBase);

  if (! musicPlayer.begin()) { // initialise the music player
     Serial.println(F("Couldn't find VS1053, do you have the right pins defined?"));
     while (1);
  }
  Serial.println(F("VS1053 found"));
  
//   if (!SD.begin(CARDCS)) {
//    Serial.println(F("SD failed, or not present"));
//    while (1);  // don't do anything more
//  }
  
  // Set volume for left, right channels. lower numbers == louder volume!
  musicPlayer.setVolume(20,20);

  // If DREQ is on an interrupt pin (on uno, #2 or #3) we can do background
  // audio playing
  musicPlayer.useInterrupt(VS1053_FILEPLAYER_PIN_INT);  // DREQ int

  Serial.println("finish setup");
}

void loop() {
  Serial.println("looping");

  // check the brightness via LDR
  int ldrValue = analogRead(LDR_PIN);

  Serial.print("ldr value: ");
  Serial.println(ldrValue);
  // check if the light change over the threshold
  if(ldrValue <= (ldrBase - ldrThreshold) || ldrValue >= (ldrBase + ldrThreshold)) {
    writeRGBLight(255, 0, 0);
    if(!music1Played) {
      Serial.println(F("Playing track 001"));
      musicPlayer.playFullFile("/track001.mp3");
      music1Played = true;

      // File is playing in the background
      if (musicPlayer.stopped()) {
        Serial.println("Done playing music1");
      }
    }
  } else{
      writeRGBLight(0, 255, 0);
      music1Played = false;
  }

  delay(1000);
}


void writeRGBLight(int r, int g, int b) {
  analogWrite(RGB_R_PIN, r);
  analogWrite(RGB_G_PIN, g);
  analogWrite(RGB_B_PIN, b);
}
