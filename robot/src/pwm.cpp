#include "pwm.h"
#include "encoder.h"

/***
 * ham nay dung de khoi tao cac chan su dung cho esp32
*/

void pwm::initPwm()
{
    /**
     * mach lai dong co 1
    */
    pinMode(pinDirOne,OUTPUT);
    pinMode(pinPwmOne,OUTPUT);
    pinMode(pinDirTwo,OUTPUT);
    pinMode(pinPwmTwo,OUTPUT);
    pinMode(pinDirThree,OUTPUT);
    pinMode(pinPwmThree,OUTPUT);
    pinMode(pinDirFour,OUTPUT);
    pinMode(pinPwmFour,OUTPUT);
    Serial.println("khoi tao xong 4 chan dieu khien driver");
    
}

/**
 * ham nay dung de dieu khien dong co
*/

void pwm::motorPower(int numDir, int numPwm, int speed,int state)
{
    digitalWrite(numDir,state);
    analogWrite(numPwm,speed);
}

float pwm::PIDCalculate(int target,int encoder,int dirPin, int pwmPin,int state)
{
    // time different
    unsigned int currT = micros(); // thoi gian hien tai
    /*deltaT la khoang cach giua thoi gian hien tai voi thoi gian qua khu*/
    double deltaT = ((double)(currT - prevT))/(1.0e6);
    /*cap nhat thoi gian hien tai la thoi gian qua khu*/
    prevT = currT;
    // error 
    int error = encoder-target;

    // dao ham
    double dedt = (error - eprev)/(deltaT);

    // tich phan
    eintegral = eintegral + error*deltaT;

    // control signal 

    double ctrlSignal = kp*error + kd*dedt + ki*eintegral;

    // motor power
    int pwr = (int)fabs(ctrlSignal);
    if(pwr > 255)
        pwr = 255;
    
    /**
     * phan nay them de dieu khien 2 dong co
    */
    if(encoder > target)
    {
        pwr=0;
    }
    

    int dir =1;
    if(ctrlSignal < 0)
        dir =0;
    
    // cap nhat gia tri loi 
    eprev = error;
    return ctrlSignal;

}

pwm _pwm;
