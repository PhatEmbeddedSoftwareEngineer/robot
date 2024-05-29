#include <Arduino.h>

#define pinDirOne 2 // chan DIR1
#define pinPwmOne 4 // chan PWM1
#define pinDirTwo 15 // chan DIR2
#define pinPwmTwo 5 // chan PWM2

#define pinDirThree 21 
#define pinPwmThree 3
#define pinDirFour 23
#define pinPwmFour 14



class pwm
{
public:
    unsigned int prevT =0; // previous time 
    float eprev=0; // bien de luu giu gia tri loi cu
    float eintegral = 0; // bien de luu giu gia tri loi tich phan

    // PID Constant
    float kp =1.5;
    float kd = 0.00025;
    float ki = 0.00000001;

    uint8_t speedA;
    uint8_t speedB;

    /***
     * ham khoi tao chan control driver
    */
    void initPwm();

    /**
     * ham dung de dieu khien dong co
    */
    void motorPower(int numDir, int numPwm,int speed,int state);
    /**
     * function PID
    */

    float PIDCalculate(int target,int encoder,int dirPin, int pwmPin,int state);

};
extern pwm _pwm;

