#include <BitbloqSoftwareSerial.h>

bqSoftwareSerial board_bluetooth(0, 1, 19200);
String char_ = board_bluetooth.readString();
float stop_ = 0;
float steering_ = 0;

void forward() {
    if (stop_ == 0) {
        Servo_L.write(180);
        Servo_R.write(180);
    }
    else {
        Servo_L.write(90);
        Servo_R.write(90);
    }
}


void backwards() {
    if (stop_ == 0) {
        Servo_L.write(0);
        Servo_R.write(0);
    }
    else {
        Servo_L.write(90);
        Servo_R.write(90);
    }
}


void left() {
    if (steering_ == 0) {
        digitalWrite(Status_LED, LOW);
        steering_ = 1;
        Servo_Steering.write(-75);
        delay(200);
        Servo_Steering.write(0);
        steering_ = 0;
    }
    if (steering_ == 1) {
        digitalWrite(Status_LED, HIGH);
    }
}


void right() {
    if (steering_ == 0) {
        digitalWrite(Status_LED, LOW);
        steering_ = 1;
        Servo_Steering.write(75);
        delay(200);
        Servo_Steering.write(0);
        steering_ = 0;
    }
    if (steering_ == 1) {
        digitalWrite(Status_LED, HIGH);
    }
}


void setup() {
    board_bluetooth.begin(19200);
    digitalWrite(Status_LED, LOW);
    Servo_Steering.write(0);
}

void loop() {
    if (char_ == "stop") {
        stop_ = 1;
    }
    if (char_ == "forward") {
        forward();
        stop_ = 0;
    }
    if (char_ == "backwards") {
        backwards();
        stop_ = 0;
    }
    if (char_ == "left") {
        left();
    }
    if (char_ == "right") {
        right();
    }
}
