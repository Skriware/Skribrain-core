#include "Abstract_Device.h"


	Abstract_Device::Abstract_Device(byte n_channels, byte *pins, byte *ids){
		active_channels = n_channels;
		if(active_channels == 1){
		  channel_pins = pins;
		  channel_ids = ids;
		}else{
		  channel_pins = new byte[active_channels];
		  channel_ids	= new byte[active_channels];
		  for(byte rr = 0; rr < active_channels;rr++){
		  	channel_id[rr] = ids[rr];
		  	channel_pins[rr] = pins[rr];
		  }
		}
	}

    uint32_t 	Abstract_Device::performChannelAction(byte pin,byte input){
    	uint32_t output = 0;
    	byte channel_id = 0;
    	if(active_channels == 1){
    		channel_id = &channel_ids;
    	}else{
    		for(int yy = 0; yy < active_channels; yy+){
    			if(pin == channel_pins[yy]){
    				channel_id = yy;
    				break;
    			}
    		}
    	}

    	switch(channel_id){
    		case D_READ :
    			output = digitalRead(pin);
    		break;	
			case D_WRITE :
				digitalWrite(pin,input);
			break;	
			case A_READ :
				output = analogRead(pin);
			break;	
			case PWM_WRITE:
				analogWrite(pin,input);
			break;	
			case DAC_WRITE:
				dacWrite(pin, input);
			break;	
			case PULSE_IN:
				output = pulseIn(EchoPin,input,15000);
			break;	
    	}

    }
  	uint32_t 	Abstract_Device::performComplexAction(uint32_t action_hash);
  	void 		Abstract_Device::channel_Init();