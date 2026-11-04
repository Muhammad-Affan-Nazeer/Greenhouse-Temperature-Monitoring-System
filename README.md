# Greenhouse-Temperature-Monitoring-System
A greenhouse manager uses multiple temperature sensors to monitor the temperature inside a greenhouse.

Each sensor records the temperature in degrees Celsius at the end of every hour. The readings are stored in a two-dimensional array, where each row represents a sensor and each column represents an hourly reading.
The manager wants to analyze the recorded temperatures to identify potentially dangerous conditions for the plants.

Write a C program using functions and a two-dimensional array to perform the following tasks:
1. Input Data: Input the number of sensors and the number of hourly readings from the user. Store the temperature readings for every sensor and every hour in a two-dimensional array.
2. Input Function: Write a function to input all temperature readings into the two-dimensional array.
3. Sensor Analysis Function: Write a function that receives the readings of a sensor and calculates the following:
  -Total of all temperature readings.
  -Average temperature, displayed up to two decimal places.
  -Highest and lowest temperature readings.
  -Number of critical readings (temperature of 40°C or above).
  -Number of warning readings (temperature between 35°C and 39°C, inclusive).
  -Longest streak of consecutive hours during which the temperature remained at 35°C or above.
4. Individual Reports: Display a separate report for each sensor containing all thecalculated statistics.
5. Highest Average Function: Write a separate function to determine and return the sensor number with the highest average temperature.
6. Final Report: Display the sensor number with the highest average temperature along with its average reading.
7. Final Report: Display the sensor number with the highest average temperature along with its average reading.
