#ifndef ESPQRESPI_H
#define ESPQRESPI_H
/* ESP_QRcode. tft version for TFT_eSPI supported displays
 * include this .h if you have a TFT display
 */

#define TFTDISPLAY

#include <TFT_eSPI.h>
#include <SPI.h>
#include "qrcodedisplay.h"

class QRcode_eSPI : public QRcodeDisplay
{
	private:
		TFT_eSPI *display;
		int left = 0;
		int top = 0;
		int drawColor = TFT_BLACK;
		int backgroundColor = TFT_WHITE;
        void drawPixel(int x, int y, int color);
	public:
		
		QRcode_eSPI(TFT_eSPI *display);
		void create(String message);
		void init(int drawColor, int backgroundColor, int top, int left, int bottom, int right);
		void screenwhite();
		void screenupdate();
};
#endif