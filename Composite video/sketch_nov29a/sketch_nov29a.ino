#include <Adafruit_GFX.h>
#include <Adafruit_CompositeVideo.h>

Adafruit_NTSC40x24 display;

display.begin();

display.drawLine(0, 0, 39, 23, 128); // Gray line, corner-to-corner
display.setTextColor(255);           // White text
display.print("Hello World");
