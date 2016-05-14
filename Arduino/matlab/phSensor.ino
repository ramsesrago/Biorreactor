int getPH() {
  PH = analogRead(PH_INPUT);
  PH = map(PH, 0, 1023, 1, 14);
  return PH;
}
