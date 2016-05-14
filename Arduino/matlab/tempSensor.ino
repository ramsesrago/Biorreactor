  float getTemperature() {
    readTemp = analogRead(TEMP_INPUT);
    float R = 1023.0/((float)readTemp) - 1.0;
    R = R0 * R;
    temperature = 1.0/(log(R/R0)/b + 1/298.15) - 273.15;
    return temperature;
  }
