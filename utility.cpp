#include "utility.h"
String serialToString() {
  String message = "";
  while (Serial.available()) {
    message += (char)Serial.read();
    delay(1);
  }
  return message;
}
int splitString(String str, String sp, String* out) {
  int count = 1;
  int lastindex = str.indexOf(sp);
  while (lastindex != -1) {
    count++;
    lastindex = str.indexOf(sp, lastindex + 1);
  }
  if (out) {
    int laststart = 0;
    int lastend = str.indexOf(sp);
    int index = 0;
    while (lastend != -1) {
      out[index++] = str.substring(laststart, lastend);
      laststart = lastend + 1;
      lastend = str.indexOf(sp, laststart);
    }
    out[index] = str.substring(laststart);
  }

  return count;
}
