#ifndef KevinCar_h
#define KevinCar_h //define class 
#include "Arduino.h" //Adds functions as delay...

class KevinCar
{
	public: //Functions the user can see
		KevinCar();
		void move_forward(int val);
		void move_left(int val);
		void move_right(int val);
		void move_backward(int val);
		void stop();
		void during(int wt);
		int read_lineL();
		int read_lineC();
		int read_lineR();
	private: //Librarie's interval variables
		int _M1A;
		int _M1B;
		int _M2A;
		int _M2B;
		int _vue;
		int _leftS;
    	int _centerS;
    	int _rightS;		
    	int _L;
    	int _C;
    	int _R;
};

#endif