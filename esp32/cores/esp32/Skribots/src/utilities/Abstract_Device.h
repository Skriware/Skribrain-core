#ifndef Absteact_D_H
#define Abstract_D_H
#include "Arduino.h"
#include "PWMHandler.h"
#include "SPIHandler.h"
#include "I2CHandler.h"
#define D_READ 		1
#define D_WRITE 	2
#define A_READ 		3
#define PWM_WRITE 	4
#define DAC_WRITE 	5
#define PULSE_IN	6
#define SPI			7
#define I2C			8

class Abstract_Device{
  public:
    Abstract_Device(byte n_channels, byte *pins, byte *ids);
    uint32_t 	performChannelAction(byte pin, byte input = 0);
  	uint32_t 	performComplexAction(uint32_t action_hash);
  	void 		channel_Init();
  private:
  byte active_channels;
  byte *channel_pins;
  byte *channel_ids;
  SPIHandler *spi = NULL;
  I2CHandler *i2c = NULL;

  
 };


#endif