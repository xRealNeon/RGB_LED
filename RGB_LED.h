
#ifndef RGB_LED_h
#define RGB_LED_h

#if ARDUINO >= 100
#include <Arduino.h>
#else
#include <WProgram.h>
#include <wiring.h>
#endif

//colours
#define Black 0
#define White 1
#define Red 2
#define Green 3
#define Blue 4
#define Yellow 5
#define Purple 6
#define Aqua 7

//functions
#define Random -1
#define Solid 0
#define Fade 1
#define FadeRandom 3
#define Step1 4
#define Step2 5
#define StepRandom 6

//PERCENT FUNCTION
float linear(float x);
float quadratic(float x);
float cos(float x);
float waveup(float x);
float wavefaster(float x);

class RGB_LED
{
    public:
        // SETUP 
        RGB_LED(byte pinR,byte pinG,byte pinB);
        RGB_LED(bool inverted, byte pinR,byte pinG,byte pinB);
        void setCallback(float (*CallBack)(float x));

        // SET 
        void set(int Rvalue,int Gvalue,int Bvalue);
        void setSpeed(unsigned long speedValue);
        void setPercentFade(float FadeValue);
        void fadeTo(int Rvalue,int Gvalue,int Bvalue,unsigned long speedValue);
        void setFunction(byte functionValue);
        void setRandom();
        void setColour(byte colour);
        void fadeToColour(byte colour,unsigned long speedValue);
        void setFunctionCount(int FunctionCount);
        
        //GET
        unsigned long getSpeed();
        float getPercentFade();
        byte getFunction();
        int getCurrentRValue();
        int getCurrentGValue();
        int getCurrentBValue();
        int getFunctionCount();

        // CHECKING 
        boolean hasFinished();
        
        // COMMANDS 
        void run();
        void runOff();
        void stop();
        void delay(unsigned long delayValue);
        
    private:
        int Max_PWM;
        byte R_Pin;
        byte G_Pin;
        byte B_Pin;
        int R_Last_value;
        int G_Last_value;
        int B_Last_value;
        int R_Current_value;
        int G_Current_value;
        int B_Current_value;
        int R_Future_value;
        int G_Future_value;
        int B_Future_value;

        unsigned long Speed = 2000;
        unsigned long starting_time;
        int function=0;
        int count;
        bool invertedPins=false;
        
        float (*FadeFunctionCallBack) (float x);

        void writeOutput();
        void FunctionsFinished();
        void FadeFunction();
        void FadeRandomFunction();
        void StepRGBWFunction();
        void StepAllFunction();
        void StepRandomFunction();
};

#endif 
