#ifndef MOTORS_H
#define MOTORS_H

#include "settings.h"

void initMotors() {
    pinMode(PWMA, OUTPUT); pinMode(AIN1, OUTPUT); pinMode(AIN2, OUTPUT);
    pinMode(PWMB, OUTPUT); pinMode(BIN1, OUTPUT); pinMode(BIN2, OUTPUT);
}

// Function to control motor speed and direction
// speed: -255 (Max Reverse) to 255 (Max Forward)
void setMotors(int speedLeft, int speedRight) {
    // Safety clamp
    speedLeft = constrain(speedLeft, -MAX_SPEED, MAX_SPEED);
    speedRight = constrain(speedRight, -MAX_SPEED, MAX_SPEED);

    // --- LEFT MOTOR ---
    if (speedLeft > 0) {
        digitalWrite(AIN1, HIGH); digitalWrite(AIN2, LOW);
        analogWrite(PWMA, speedLeft);
    } else {
        digitalWrite(AIN1, LOW); digitalWrite(AIN2, HIGH);
        analogWrite(PWMA, -speedLeft);
    }

    // --- RIGHT MOTOR ---
    // Note: If right wheel spins backward when it should go forward,
    // swap HIGH/LOW here!
    if (speedRight > 0) {
        digitalWrite(BIN1, LOW); digitalWrite(BIN2, HIGH); 
        analogWrite(PWMB, speedRight);
    } else {
        digitalWrite(BIN1, HIGH); digitalWrite(BIN2, LOW);
        analogWrite(PWMB, -speedRight);
    }
}

void stopMotors() {
    setMotors(0, 0);
}

#endif