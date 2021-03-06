/*
 * PinRegistry.h
 *
 * Created: 2014-11-08 7:40:07 PM
 *  Author: amate_000
 */ 


#ifndef PINREGISTRY_H_
#define PINREGISTRY_H_

class PinRegistry {
	public:
		static const int PWM_R = 6;
		static const int IN1_R = 9;
		static const int IN2_R = 10;
		
		static const int PWM_L = 5;
		static const int IN1_L = 7;
		static const int IN2_L = 8;
		
		static const int DIST_TRIG = 2;
		static const int DIST_ECHO = 3;
};



#endif /* PINREGISTRY_H_ */