
#include <Servo.h>
#include <BitbloqSoftwareSerial.h>

Servo CRservo;
bqSoftwareSerial board_bluetooth(0, 1, 19200);
float steering_ = 0;

void left() {
    if (steering_ == 0) {
        steering_ = 1;
        CRservo.write(180);
        delay(200);
        CRservo.write(90);
        CRservo.write(0);
        delay(200);
        CRservo.write(90);
        steering_ = 1;
    }
}


void right() {
    if (steering_ == 0) {
        steering_ = 1;
        CRservo.write(0);
        delay(200);
        CRservo.write(90);
        CRservo.write(180);
        delay(200);
        CRservo.write(90);
        steering_ = 1;
    }
}


void setup() {
    CRservo.attach(4);
    board_bluetooth.begin(19200);
}

void loop() {
    auto char_ = board_bluetooth.readInt();
    if (char_ == 3) {
        left();
    }
    if (char_ == 4) {
        right();
    }
}
