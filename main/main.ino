
#include <Servo.h>
#include <BitbloqSoftwareSerial.h>

Servo ServoL;
Servo ServoR;
Servo ServoF;
bqSoftwareSerial board_bluetooth(0, 1, 19200);
float steering_ = 0;
float stop_ = 0;

void forward() {
    while (stop_ == 0) {
        ServoL.write(180);
        ServoR.write(180);
    }
    if (stop_ == 1) {
        ServoL.write(90);
        ServoR.write(90);
    }
}


void backwards() {
    while (stop_ == 0) {
        ServoL.write(0);
        ServoR.write(0);
    }
    if (stop_ == 1) {
        ServoL.write(90);
        ServoR.write(90);
    }
}


void left() {
    if (steering_ == 0) {
        steering_ = 1;
        ServoF.write(180);
        delay(200);
        ServoF.write(90);
        ServoF.write(0);
        delay(200);
        ServoF.write(90);
        steering_ = 0;
    }
}


void right() {
    if (steering_ == 0) {
        steering_ = 1;
        ServoF.write(0);
        delay(200);
        ServoF.write(90);
        ServoF.write(0);
        delay(200);
        ServoF.write(90);
        steering_ = 0;
    }
}


void setup() {
    ServoL.attach(8);
    ServoR.attach(9);
    ServoF.attach(11);
    board_bluetooth.begin(19200);
}

void loop() {
    auto char_ = board_bluetooth.readInt();
    if (char_ == 1) {
        stop_ = 0;
        forward();
    }
    if (char_ == 2) {
        stop_ = 0;
        backwards();
    }
    if (char_ == 3) {
        left();
    }
    if (char_ == 4) {
        right();
    }
    if (char_ == 5) {
        stop_ = 1;
    }
}
