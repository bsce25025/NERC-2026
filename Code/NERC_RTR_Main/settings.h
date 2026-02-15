#ifndef SETTINGS_H
#define SETTINGS_H

#include <Arduino.h>

// ================================================================
// 1. HARDWARE PINS (Raspberry Pi Pico)
// ================================================================

// --- Motor A (Left) ---
#define PWMA 16
#define AIN1 17
#define AIN2 18

// --- Motor B (Right) ---
#define PWMB 19
#define BIN1 20
#define BIN2 21

// --- Sensors ---
const uint8_t SensorPins[] = {2, 3, 4, 5, 6, 7, 8, 9};
#define NUM_SENSORS 8
#define EMITTER_PIN 1  // Pin to turn IR LEDs on/off

// ================================================================
// 2. TUNING PARAMETERS
// ================================================================

// Speed
#define BASE_SPEED  160       // Target speed for straight lines
#define TURN_SPEED  140       // Speed for 90-degree turns
#define MAX_SPEED   255
#define BRAKE_SPEED 0

// PID Constants
#define KP 0.12   // Proportional
#define KD 1.8    // Derivative
#define KI 0.0    // Integral

// Logic Thresholds
#define THRESHOLD 700         // White/Black line (0-1000)
#define DELAY_TURN 400        //W8 before 90 degrees turn
#define INTERSECTION_DEBOUNCE 350 //ignore lines after turn

#endif