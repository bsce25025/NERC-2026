#include "settings.h"
#include "motors.h"
#include "sensors.h"
#include "navigation.h"

void setup() {
    Serial.begin(115200);
    
    // Initialize Modules
    initMotors();
    initSensors();

    delay(1000);
    calibrateSensors();
    
    delay(2000); // Wait 2s
}

void loop() {
    // 1. Read Sensors
    int position = getLinePosition();

    // 2. Check Logic
    if (checkIntersection()) {
        executeNextMove();
    } 
    //Run PID
    else {
        runPID(position);
    }
}