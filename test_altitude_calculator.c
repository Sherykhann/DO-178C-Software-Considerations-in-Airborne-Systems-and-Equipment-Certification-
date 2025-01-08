

// altitude_calculator.c
#include <stdio.h>
#include <math.h>

#define SEA_LEVEL_PRESSURE 1013.25 // hPa, standard pressure at sea level
#define MAX_PRESSURE 1100.0 // hPa, maximum pressure for altitude calculation
#define MAX_ALTITUDE_FEET 40000 // feet, maximum allowable altitude

// Function to calculate altitude from pressure using the barometric formula
// Altitude = 44330 * (1 - (pressure / SEA_LEVEL_PRESSURE)^(1/5.255))
double calculate_altitude(double pressure) {
    if (pressure > MAX_PRESSURE) {
        printf("Warning: Pressure exceeds limit, unable to calculate altitude.\n");
        return -1; // Indicate error in altitude calculation
    }

    double altitude = 44330.0 * (1.0 - pow(pressure / SEA_LEVEL_PRESSURE, 0.1903));
    
    // Check if the altitude exceeds 40,000 feet
    if (altitude > MAX_ALTITUDE_FEET) {
        printf("Warning: Altitude exceeds maximum limit of 40,000 feet!\n");
        return -2; // Indicate that the altitude exceeds the maximum allowed
    }

    return altitude; // Return the calculated altitude in feet
}
Explanation of the Code:
calculate_altitude: This function calculates the altitude based on barometric pressure using the barometric formula. It also checks for warnings related to high pressure and high altitude.
Constants: SEA_LEVEL_PRESSURE is the standard pressure at sea level, and MAX_PRESSURE is the upper limit for valid pressure inputs. MAX_ALTITUDE_FEET is the maximum allowable altitude for the system.
Error Handling: The function returns -1 if the pressure exceeds the maximum limit and -2 if the altitude exceeds 40,000 feet.
