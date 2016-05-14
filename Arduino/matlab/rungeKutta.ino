#include <stdio.h>
#include <unistd.h>
#include <math.h>

const int n = 200;
float mu = 0.1916;
float beta = 0.0004;
float k1 = 3.7;
float k2 = 1;
float kl_alpha = 0.1;

float Sc_k1,Sc_k2,Sc_k3,Sc_k4,Soi_k1,Soi_k2,Soi_k3,Soi_k4,Xi_k1,Xi_k2,Xi_k3,Xi_k4,Vt_k1,Vt_k2,Vt_k3,Vt_k4,h;
float t[n];

//float V[1][n+1];
  
float V[n+1], X[n+1], O[n+1], S[n+1];

float Vt(float t, float V, float X, float O, float S);
float Xi(float t, float V, float X, float O, float S);
float Sc(float t, float V, float X, float O, float S);
float SOi(float t, float V, float X, float O, float S);

float Xi(float t, float V, float X, float O, float S){
  return ((mu-(Vt(t,V,X,O,S)/V))*X);
}

float Sc(float t, float V, float X, float O, float S){
  return ((-k1*mu*X) - (Vt(t,V,X,O,S)/V)*(0.2 - O));
}

float SOi(float t, float V, float X, float O, float S){
    return (-k2*mu*X) - ((beta*mu*X)*(Vt(t,V,X,O,S)/V)*(0.2 - S)) - (kl_alpha*(0.1 - S));
}

float Vt(float t, float V, float X, float O, float S){
  return sin(t);
}

void setupRungeKutta() {
  h = 0.1;
  V[0] = 3;
  X[0] = 5;
  O[0] = 5;
  S[0] = 5;
  delay(3000);
}

  void calcRungeKutta() {
    int i;
      for(i = 0; i < n; i++)
      {
          t[i] = h*i;
          Vt_k1 = h*Vt(t[i], V[i], X[i], O[i], S[i]);
          Vt_k2 = h*Vt(t[i] + 0.5*h, V[i]+0.5*Vt_k1, X[i]+0.5*Xi_k1, O[i]+0.5*Sc_k1, S[i]+0.5*Soi_k1);
          Vt_k3 = h*Vt(t[i] + 0.5*h, V[i]+0.5*Vt_k2, X[i]+0.5*Xi_k2, O[i]+0.5*Sc_k2, S[i]+0.5*Soi_k2);
          Vt_k4 = h*Vt(t[i] + h, V[i]+Vt_k3, X[i]+Xi_k3, O[i]+Sc_k3, S[i]+Soi_k3);
          V[i+1] = (V[i] + (1.0f/6)*(Vt_k1 + 2*Vt_k2 + 2*Vt_k3 + Vt_k4));
          Serial.print(V[i]);
          Serial.print(',');
      }
      Serial.print('\r');
      for(i = 0; i < n; i++)
      {
          t[i] = h*i;
          Xi_k1 = h*Xi(t[i], V[i], X[i], O[i], S[i]);
          Xi_k2 = h*Xi(t[i] + 0.5*h, V[i]+0.5*Vt_k1, X[i]+0.5*Xi_k1, O[i]+0.5*Sc_k1, S[i]+0.5*Soi_k1);
          Xi_k3 = h*Xi(t[i] + 0.5*h, V[i]+0.5*Vt_k2, X[i]+0.5*Xi_k2, O[i]+0.5*Sc_k2, S[i]+0.5*Soi_k2);
          Xi_k4 = h*Xi(t[i] + h, V[i]+Vt_k3, X[i]+Xi_k3, O[i]+Sc_k3, S[i]+Soi_k3);
          X[i+1] = (X[i] + (1.0f/6)*(Xi_k1 + 2*Xi_k2 + 2*Xi_k3 + Xi_k4));
          Serial.print(X[i]);
          Serial.print(',');
      }
      Serial.print('\r');
      for(i = 0; i < n; i++)
      {
          t[i] = h*i;
          Sc_k1 = h*Sc(t[i], V[i], X[i], O[i], S[i]);
          Sc_k2 = h*Sc(t[i] + 0.5*h, V[i]+0.5*Vt_k1, X[i]+0.5*Xi_k1, O[i]+0.5*Sc_k1, S[i]+0.5*Soi_k1);
          Sc_k3 = h*Sc(t[i] + 0.5*h, V[i]+0.5*Vt_k2, X[i]+0.5*Xi_k2, O[i]+0.5*Sc_k2, S[i]+0.5*Soi_k2);
          Sc_k4 = h*Sc(t[i] + h, V[i]+Vt_k3, X[i]+Xi_k3, O[i]+Sc_k3, S[i]+Soi_k3);
          O[i+1] = (O[i] + (1.0f/6)*(Sc_k1 + 2*Sc_k2 + 2*Sc_k3 + Sc_k4));
          Serial.print(O[i]);
          Serial.print(',');
      }
      Serial.print('\r');
            for(i = 0; i < n; i++)
      {
          t[i] = h*i;
          Soi_k1 = h*SOi(t[i], V[i], X[i], O[i], S[i]);
          Soi_k2 = h*SOi(t[i] + 0.5*h, V[i]+0.5*Vt_k1, X[i]+0.5*Xi_k1, O[i]+0.5*Sc_k1, S[i]+0.5*Soi_k1);
          Soi_k3 = h*SOi(t[i] + 0.5*h, V[i]+0.5*Vt_k2, X[i]+0.5*Xi_k2, O[i]+0.5*Sc_k2, S[i]+0.5*Soi_k2);
          Soi_k4 = h*SOi(t[i] + h, V[i]+Vt_k3, X[i]+Xi_k3, O[i]+Sc_k3, S[i]+Soi_k3);
          S[i+1] = (S[i] + (1.0f/6)*(Soi_k1 + 2*Soi_k2 + 2*Soi_k3 + Soi_k4));
          Serial.print(S[i]);
          Serial.print(',');
      }
      Serial.print('\r');
  }
