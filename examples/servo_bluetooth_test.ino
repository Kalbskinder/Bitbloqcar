#include <Servo.h>
#include <BitbloqSoftwareSerial.h>

Servo CRservo;
bqSoftwareSerial board_bluetooth(0, 1, 19200);

void setup() {
    CRservo.attach(11);
    board_bluetooth.begin(19200);
}

void loop() {
    auto char_ = board_bluetooth.readInt();
    if (char_ == 2) {
        CRservo.write(90);
        CRservo.write(180);
    }
    if (char_ == 1) {
        CRservo.write(90);
        CRservo.write(0);
    }
}
