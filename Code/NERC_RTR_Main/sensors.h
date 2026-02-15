#ifndef SENSORS_H
#define SENSORS_H

#include <QTRSensors.h>
<<<<<<< Updated upstream
#include "settings.h"

QTRSensors qtr;
unsigned int sensorValues[NUM_SENSORS];
=======
#include "config.h"

QTRSensors qtr;

uint16_t sensorValues[NUM_SENSORS]; 
>>>>>>> Stashed changes

void initSensors() {
    qtr.setTypeRC();
    qtr.setSensorPins(SensorPins, NUM_SENSORS);
    qtr.setEmitterPin(EMITTER_PIN);
}

void calibrateSensors() {
    Serial.println("Calibrating... Move robot across the line!");
    // Blink LED to indicate calibration mode
    pinMode(25, OUTPUT);
    digitalWrite(25, HIGH);

    for (uint16_t i = 0; i < 200; i++) {
        qtr.calibrate();
        delay(10);
    }
    
    digitalWrite(25, LOW);
    Serial.println("Calibration Complete.");
}

// Returns position from 0 to 7000 (3500 is center)
int getLinePosition() {
    return qtr.readLineBlack(sensorValues);
}

// Checks if we are at a grid intersection
// Returns: 0=None, 1=Intersection Detected
bool checkIntersection() {
    bool leftWing   = sensorValues[0] > THRESHOLD;
    bool rightWing  = sensorValues[7] > THRESHOLD;
    bool center     = sensorValues[3] > THRESHOLD && sensorValues[4] > THRESHOLD;

<<<<<<< Updated upstream
=======

>>>>>>> Stashed changes
    // Detect Cross (+) or T-Junction
    if ((leftWing && rightWing) || (leftWing && center && rightWing)) {
        return true;
    }
    return false;
}

#endif