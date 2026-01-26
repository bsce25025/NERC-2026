#ifndef NAVIGATION_H
#define NAVIGATION_H

#include "config.h"
#include "motors.h"
#include "sensors.h"

// ==========================================
// Intersection Handelling
// ==========================================

// 0=Straight, 1=Right, 2=Left, 3=Stop

int path[] = {
//for right start

};

int pathIndex = 0;
int lastError = 0;

// --- PID CONTROL ALGORITHM ---
void runPID(int position) {
    int error = position - 3500; // 3500 is center
    
    int P = error;
    int D = error - lastError;
    
    int correction = (KP * P) + (KD * D);
    lastError = error;

    int leftSpeed = BASE_SPEED + correction;
    int rightSpeed = BASE_SPEED - correction;

    setMotors(leftSpeed, rightSpeed);
}

// --- INTERSECTION HANDLER ---
void executeNextMove() {
    stopMotors();
    // delay(50); // Optional pause for stability

    int action = path[pathIndex];
    
    switch (action) {
        case 0: // STRAIGHT
            setMotors(BASE_SPEED, BASE_SPEED);
            delay(250); // Blind drive to clear lines
            break;
            
        case 1: // TURN RIGHT
            setMotors(BASE_SPEED, BASE_SPEED);
            delay(150); // Align center
            setMotors(TURN_SPEED, -TURN_SPEED);
            delay(DELAY_TURN); 
            break;
            
        case 2: // TURN LEFT
            setMotors(BASE_SPEED, BASE_SPEED);
            delay(150); // Align center
            setMotors(-TURN_SPEED, TURN_SPEED);
            delay(DELAY_TURN); 
            break;
            
        case 3: // STOP / PARKING
            stopMotors();
            while(true) {
                // Victory Blink
                digitalWrite(25, HIGH); delay(200);
                digitalWrite(25, LOW); delay(200);
            }
            break;
    }

    pathIndex++; // Next step
    
    // Recovery: Drive straight to find line again
    setMotors(BASE_SPEED, BASE_SPEED);
    delay(INTERSECTION_DEBOUNCE);
}

#endif