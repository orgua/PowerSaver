#ifndef PowerSaver_h
#define PowerSaver_h

#include "Arduino.h"


/*  Include the following Lines in main program after including <powerSaver.h>:

#ifndef WDT_VECT_DEFINED
#define WDT_VECT_DEFINED
ISR(WDT_vect)
{
    ++vector_wdt_called;
};
#endif // WDT_VECT_DEFINED

*/


#define USE_WDT // activate WDT after sleep - you have to call sleep at least every "WDT_TIME" or reset gets triggered
#include <avr/wdt.h>
static const uint8_t    WDT_TIME            = (WDTO_1S);
static volatile uint8_t vector_wdt_called   = 0;

#include <avr/sleep.h>
#include <util/atomic.h>

class PowerSaver
{
  public:
    PowerSaver();
    void sleepInterruptSetup();
    void turnOffSPI();
	void turnOnSPI();
	void turnOffGPIO();
	void turnOffDigitalInput();
	void turnOffTWI();
	void turnOffTimer();
	void turnOffTimer0();
	void turnOffTimer1();
	void turnOffTimer2();
	void turnOffUART();
    void turnOffADC();
	void turnOnADC();
    void turnOffBOD();
	void turnOffWDT();
	void turnOnWDTInterrupt();
	void goodNight();

	void sleep(const uint8_t);
	uint8_t delay(const uint16_t);

  private:
    // instance has no control over these
    PowerSaver(const PowerSaver&);            // declaration only for copy constructor
    PowerSaver& operator=(const PowerSaver&);  // declaration only for copy assignment --> make it uncopyable

    void watchdogInterrupts(const uint8_t);
    void powerDown();

	uint8_t d1;
	uint8_t p1;
	uint8_t adc;
	uint8_t i2c;
};


#endif
