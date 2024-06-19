
/***   Included libraries  ***/
#include <Servo.h>
#include <BitbloqSoftwareSerial.h>

/***   Global variables and function definition  ***/
Servo ServoB;
Servo ServoF;
bqSoftwareSerial board_bluetooth(0, 1, 19200);
float steering_ = 0;
float stop_ = 0;

void forward() {
    ServoB.write(0);
}


void backwards() {
    ServoB.write(180);
}


void left() {
    if (steering_ == 0) {
        steering_ = 1;
        ServoF.write(180);
        delay(700);
        ServoF.write(90);
        steering_ = 2;
    }
}


void right() {
    if (steering_ == 0) {
        steering_ = 1;
        ServoF.write(0);
        delay(700);
        ServoF.write(90);
        steering_ = 2;
    }
}


void stop() {
    ServoB.write(90);
}


void left_stop() {
    if (steering_ == 2) {
        ServoF.write(0);
        delay(700);
        ServoF.write(90);
        steering_ = 0;
    }
}


void right_stop() {
    if (steering_ == 2) {
        ServoF.write(180);
        delay(700);
        ServoF.write(90);
        steering_ = 0;
    }
}


/***   Setup  ***/
void setup() {
    ServoB.attach(8);
    ServoF.attach(11);
    board_bluetooth.begin(19200);
}

/***   Loop  ***/
void loop() {
    String char_ = board_bluetooth.readString();
    if (char_ == "gas") {
        stop_ = 0;
        forward();
    }
    if (char_ == "back") {
        stop_ = 0;
        backwards();
    }
    if (char_ == "left") {
        left();
    }
    if (char_ == "right") {
        right();
    }
    if (char_ == "stop") {
        stop_ = 1;
        stop();
    }
    if (char_ == "left_stop") {
        left_stop();
    }
    if (char_ == "right_stop") {
        right_stop();
    }
}
