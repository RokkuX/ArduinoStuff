#include "KevinCar.h" //previous file must be included
#include "Arduino.h"

KevinCar::KevinCar()
{
    Serial.begin(9600);
    _vue        =80;
    _M1A        =6;
    _M1B        =9;
    _M2A        =10;
    _M2B        =11;
    _leftS      =4;
    _centerS    =5;
    _rightS     =8;
    _L;
    _C;
    _R;

	pinMode(_M1A,OUTPUT);
    pinMode(_M1B,OUTPUT);
    pinMode(_M2A,OUTPUT);
    pinMode(_M2B,OUTPUT); 
    pinMode(_leftS,INPUT);
    pinMode(_centerS,INPUT);
    pinMode(_rightS,INPUT);

    analogWrite(_M1A,255);
    analogWrite(_M1B,255);
    analogWrite(_M2A,255);
    analogWrite(_M2B,255);    

    Serial.println("Setup ready");
}

void KevinCar::move_forward(int val)
{
        if(val<80)
        {
            analogWrite(_M1A,0);
            analogWrite(_M1B,_vue);
            analogWrite(_M2A,0);
            analogWrite(_M2B,_vue);  
        }else{
            analogWrite(_M1A,0);
            analogWrite(_M1B,val);
            analogWrite(_M2A,0);
            analogWrite(_M2B,val);
        }
	    
}

void KevinCar::move_left(int val)
{
       if(val<80)
        {
            analogWrite(_M1A,_vue);
            analogWrite(_M1B,0);
            analogWrite(_M2A,0);
            analogWrite(_M2B,_vue);  
        }else{
            analogWrite(_M1A,val);
            analogWrite(_M1B,0);
            analogWrite(_M2A,0);
            analogWrite(_M2B,val);
        }

}

void KevinCar::move_right(int val)
{
        if(val<80)
        {
            analogWrite(_M1A,0);
            analogWrite(_M1B,_vue);
            analogWrite(_M2A,_vue);
            analogWrite(_M2B,0);  
        }else{
            analogWrite(_M1A,0);
            analogWrite(_M1B,val);
            analogWrite(_M2A,val);
            analogWrite(_M2B,0);
        }

}

void KevinCar::move_backward(int val)
{
        if(val<80)
        {
            analogWrite(_M1A,_vue);
            analogWrite(_M1B,0);
            analogWrite(_M2A,_vue);
            analogWrite(_M2B,0);  
        }else{
            analogWrite(_M1A,val);
            analogWrite(_M1B,0);
            analogWrite(_M2A,val);
            analogWrite(_M2B,0);
        }
        
}

void KevinCar::stop()
{
    analogWrite(_M1A,255);
    analogWrite(_M1B,255);
    analogWrite(_M2A,255);
    analogWrite(_M2B,255);
}

void KevinCar::during(int wt)
{
    wt=wt*1000;
    delay(wt);
}

int KevinCar::read_lineL()
{
    Serial.println(digitalRead(_leftS));
    return _L;
}

int KevinCar::read_lineC()
{
    Serial.println(digitalRead(_centerS));
    return _C;
}

int KevinCar::read_lineR()
{
    Serial.println(digitalRead(_rightS));
    return _R;
}