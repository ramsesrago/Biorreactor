class PID {
  
  public:
     double error;
     double sample;
     double lastSample;
     double kP, kI, kD;      
     double P, I, D;
     double pid;
     double setPoint;
     long lastProcess;
  
    PID(double _kP, double _kI, double _kD, double setPoint);
  
    void addNewSample(double _sample);  
    double process();
};
