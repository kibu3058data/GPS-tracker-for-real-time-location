#include <SoftwareSerial.h>
#include <TinyGPS++.h>

#include <ESP8266WiFi.h>

// Replace with your Wi-Fi credentials


// Replace with your Firebase project details


// GPS module connection pins
  // Create a SoftwareSerial instance for the GPS module
TinyGPSPlus gps;  // Create a TinyGPSPlus object
 // Create a FirebaseData object to communicate with the Firebase Realtime Database

void setup() {
  Serial.begin(9600);  // Initialize serial communication for debugging// Initialize serial communication with the GPS module
    // Connect to Wi-Fi // Initialize Firebase
}

void loop() {
    // Check if Firebase connection is ready
    while (Serial.available() > 0) {
      if (gps.encode(Serial.read())) {  // Parse GPS data
        if (gps.location.isUpdated()) {  // Check if new location is available
          float latitude = gps.location.lat();  // Retrieve latitude
          float longitude = gps.location.lng();  // Retrieve longitude
          Serial.println(latitude);
          Serial.println(longitude);

           // Store location in Firebase
        }
      }
    }
  
}

