#include <Arduino.h>
#include "qrencode.h"
#include "qrcode_espi_extended.h"


QRcode_eSPI::QRcode_eSPI(TFT_eSPI *display) {
    this->display = display;
}


void QRcode_eSPI::init(int drawColor = TFT_BLACK, int backgroundColor = TFT_WHITE, int top = 0, int left = 0, int bottom = 0, int right = 0) {
    //display->init();
    this->top = top;
    this->left = left;
    this->screenwidth = right <= left ? display->width() : right - left;
     this->screenheight = bottom <= top ? display->height() : bottom - top;
    this->drawColor = drawColor;
    this->backgroundColor = backgroundColor;
    int min = screenwidth;
    if (screenheight<screenwidth)
        min = screenheight;
    multiply = min/WD;
    offsetsX = (screenwidth-(WD*multiply))/2;
    offsetsY = (screenheight-(WD*multiply))/2;
}

void QRcode_eSPI::create(String message) {
  display->startWrite();
  QRcodeDisplay::create(message);
  display->endWrite();
}

void QRcode_eSPI::screenwhite() {
    display->fillScreen(backgroundColor);
}

void QRcode_eSPI::screenupdate() {
    // No hay que hacer nada
}

void QRcode_eSPI::drawPixel(int x, int y, int color) {
    if(color==1) {
        color = drawColor;
    } else {
        color = backgroundColor;
    }
    int xpos = x+left;
    int ypos = y+top;
    display->drawPixel(xpos,ypos,color);
    if (this->multiply>1) {
        display->fillRect(xpos,ypos,multiply,multiply,color);
    }
}