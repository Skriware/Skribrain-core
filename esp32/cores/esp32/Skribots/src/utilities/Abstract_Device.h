#ifndef Absteact_D_H
#define Abstract_D_H
#include "Arduino.h"
#include "PWM_Handler.h"
#define D_READ 		1
#define D_WRITE 	2
#define A_READ 		3
#define PWM_WRITE 	4
#define DAC_WRITE 	5
#define PULSE_IN	6

class Abstract_Device{
  public:
    Abstract_Device(byte n_channels, byte *pins, byte *ids);
    uint32_t 	performChannelAction(byte pin, byte input = 0);
  	uint32_t 	performComplexAction(byte *action_section);
  	byte*	performSPITransfer(byte *msg);
  	byte*	performI2CTransfer(byte addr, byte *msg);
  	void 		channel_Init();
  private:
  byte active_channels;
  byte *channel_pins;
  byte *channel_ids;
  byte output;
 };


#endif