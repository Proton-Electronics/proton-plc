//#include "Arduino.h”
#include "Wire.h"
#include "variant.h"

Proton_Arduino_PLC::Proton_Arduino_PLC() {
    pinMode(D1, INPUT);
    pinMode(D2, INPUT);
    pinMode(D3, INPUT);
    pinMode(D4, INPUT);
    pinMode(D5, INPUT);
    pinMode(D6, INPUT);

    pinMode(A1, INPUT);
    pinMode(A2, INPUT);
    pinMode(A3, INPUT);
    pinMode(A4, INPUT);

    pinMode(AO1, OUTPUT);
    pinMode(AO2, OUTPUT);

    pinMode(REL1, OUTPUT);
    pinMode(REL2, OUTPUT);
    pinMode(REL3, OUTPUT);
    pinMode(REL4, OUTPUT);
    pinMode(REL5, OUTPUT);

    Serial.begin(115200);
    Wire.begin();
}