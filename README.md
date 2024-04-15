# QRcode_eSPI_extended

Subclass that you can use jointly with https://github.com/yoprogramo/QRcodeDisplay to generate QRcodes in TFT displays like ST7735 and any other supported by TFT_eSPI

forked from [yoprogramo/QRcode_eSPI](https://github.com/yoprogramo/QRcode_eSPI)

## Changes

This fork allows control over the colour, size and placement of the QR code.

The `init` method accepts six parameters - 
* `drawColour` - The color used to draw the QR code
* `backgroundColor` - The color set as the background for the display before drawing the QR code
* `top` - The top edge co-ordinate of the QR code
* `left` - The left edge co-ordinate of the QR code
* `bottom` - The bottom edge co-ordinate of the QR code
* `right` - The right edge co-ordinate of the QR code

Calling `init` with no arguments will default to a black QR code on a white background that uses the entire screen - ie. No change from the standard result of calling `init()`

To use it:

## In platform.io: 

Add as dependencies:

 * yoprogramo/QRcodeDisplay
 * yoprogramo/QRcode_eSPI
 * bodmer/TFT_eSPI

You can configure in platformio.ini the data about hardware model and connections

 ## In arduino ide 
 
 Open Library Manager (menu Sketch > Include Library > Manage Libraries…) then install the following libraries:

 * QRcodeDisplay
 * QRcode_eSPI
 * TFT_eSPI

Create or update your user_setup to match your hardware specifications.

Creating a QRcode is just as simple as:

 ```

#include <SPI.h>
#include <TFT_eSPI.h>
#include <qrcode_espi_extended.h>

TFT_eSPI display = TFT_eSPI();
QRcode_eSPI qrcode (&display);


void setup() {

    display.begin();
    qrcode.init(TFT_WHITE,TFT_BLUE,40,60,200,260);
    qrcode.create("Hello world.");

}

 ```
This will draw a white QR code on a blue backround in the square (40,60)-(200,260).


Main code provided by Ruslan Baybekov (https://github.com/oxyii)

For other displays, please refer the main repository: https://github.com/yoprogramo/QRcodeDisplay
