#include<Arduino.h>

// 7447 pins
int pA = 2;
int pB = 3;
int pC = 4;
int pD = 5;

void setup()
{
  pinMode(pA, OUTPUT);
  pinMode(pB, OUTPUT);
  pinMode(pC, OUTPUT);
  pinMode(pD, OUTPUT);
}

void loop()
{
  // Inputs
  int A = 0;
  int B = 0;
  int C = 1;

  // Step 1: XOR
  int X1 = A ^ B;

  // Step 2: XNOR (NOT of XOR)
  int X2 = !(A ^ B);

  // Step 3: Final XNOR with C
  int F = !(X1 ^ X2 ^ C);

  // Send to 7447
  if(F == 0)
  {
    digitalWrite(pA, LOW);
    digitalWrite(pB, LOW);
    digitalWrite(pC, LOW);
    digitalWrite(pD, LOW);
  }
  else
  {
    digitalWrite(pA, HIGH);
    digitalWrite(pB, LOW);
    digitalWrite(pC, LOW);
    digitalWrite(pD, LOW);
  }

  delay(1000);
}
