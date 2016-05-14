float getLight() {
  light = analogRead(LIGHT_INPUT);
  return light;
}

