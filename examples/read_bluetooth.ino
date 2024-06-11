#include <BitbloqSoftwareSerial.h>

void setup() {
    board_bluetooth.begin(19200);
}

void loop() {
    auto char_ = board_bluetooth.readInt();
    if (char_ == 1) {

    }
}
