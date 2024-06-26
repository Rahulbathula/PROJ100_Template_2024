#include "mbed.h"
#include "motor.h"
#include "tunes.h"
#include "pwm_tone.h"
#include "PROJ100_Encoder.h"
#include "PROJ100_Encoder_Tests.h"
#include <cstdio>

#define TIME_PERIOD 10             //Constant compiler Values here 10 equates to 10ms or 100Hz base Frequency
#define ENCODER_PIN_LEFT            D8
#define ENCODER_PIN_RIGHT           D6 
#define PULSES_PER_ROTATION         23
#define DEBOUNCE_US                 30000

DigitalIn microswitch1(D4);         //Instance of the DigitalIn class called 'microswitch1'
DigitalIn microswitch2(D3);         //Instance of the DigitalIn class called 'microswitch2'
DigitalIn myButton(USER_BUTTON);    //Instance of the DigitalIn class called 'myButton'   
DigitalOut greenLED(LED1);          //Instance of the DigitalOut class called 'greenLED'

Motor Wheel(D13,D11,D9,D10);      //Instance of the Motor Class called 'Wheel' see motor.h and motor.cpp

PROJ100_Encoder right_encoder (ENCODER_PIN_RIGHT,PULSES_PER_ROTATION);  //Instance of the PROJ100Encoder class called 'right_encoder'
PROJ100_Encoder left_encoder(ENCODER_PIN_LEFT,PULSES_PER_ROTATION);     //Instance of the PROJ100Encoder class called 'left_encoder'

UnbufferedSerial ser(USBTX,USBRX,115200);   // Serial object for printing info

int main ()
{
    // Clear the terminal and print an intro
    printf("\033[2J\033[1;1H\r\n");
    printf("Plymouth University PROJ100 2023/24 Optical Encoder Demonstration\n\r");

    // Set the PWM frequency
    Wheel.Period_in_ms(TIME_PERIOD);                

    // Ensure our motors and encoders are stopped at the beginning
    right_encoder.stop();
    left_encoder.stop();
    Wheel.Stop();

    // The encoder pulses can be noisy and so are debounced within the class
    // You can experiment with changing the debouce time if you wish
    left_encoder.setDebounceTimeUs(DEBOUNCE_US);
    right_encoder.setDebounceTimeUs(DEBOUNCE_US);

    // Wait for the blue button to be pressed
    printf("Press Blue Button To Begin\n\r");
    while (myButton == 0){greenLED = !greenLED; ThisThread::sleep_for(100ms);}
    wait_us(0000);
    // Start the encoders
    left_encoder.start();
    right_encoder.start();

    /*********************ENCODER TESTS***************/
    // These contain while(1) loops so ensure that they are removed or commented out when running your own code
    // If these lines are left in the lines below will never run
    /*************************************************/

    Timer ButtonTimer;      // To measure the Timing of the Button pressed
    int Buttonpressed = 0;  //to check if button is pressed
    int Buttonreleased = 0; // to check if button is released
    // simple_test();
    //speed_test();
    printf("stage1");
    int buttonDuration = ButtonTimer.read_us();
    ButtonTimer.reset();
    
    while(!myButton);                // Wait here until button is pressed
    wait_us(100000);
    ButtonTimer.start();            //  start timer here
    printf("stage3\n");
    //printf("%f" , buttonDuration );

     
    while(myButton);    // wait for release
    ButtonTimer.stop();
    buttonDuration = ButtonTimer.read_us();
    printf("%d" , buttonDuration );

    wait_us(10000);
    if (buttonDuration < 3000000) {                 //if button is pressed less than 3sec
    printf("bead\n");

    //printf("%d", right_encoder );

    wait_us(1000000);
    Wheel.Speed(1.0f, 1.0f);        //front
    wait_us(2100000);
    Wheel.Speed(0.0f, 0.0f);
    wait_us(500000);
    Wheel.Speed(-1.0f, -1.0f);      // come back
    wait_us(1500000);
    Wheel.Speed(0.0f, 0.0f);
    wait_us(100000);
    Wheel.Speed(1.0f, -1.0f);      //turn right
    wait_us(500000);               //1sec - 0.5sec
    Wheel.Speed(0.0f, 0.0f);
    wait_us(100000);
    Wheel.Speed(1.0f, 1.0f);        ///going for 2nd
    wait_us(1000000);
    Wheel.Speed(0.0f, 0.0f);
    wait_us(100000);
    Wheel.Speed(-1.0f, 1.0f);        //turning for the second row
    wait_us(500000);
    Wheel.Speed(0.0f, 0.0f);
    wait_us(100000);

    Wheel.Speed(1.0f, 1.0f);        // go for second row
    wait_us(1800000);
    Wheel.Speed(0.0f, 0.0f);        // wait
    wait_us(500000);
    Wheel.Speed(-1.0f, -1.0f);      // come back
    wait_us(1500000);
    Wheel.Speed(0.0f, 0.0f);
    wait_us(100000);
    Wheel.Speed(1.0f, -1.0f);      //turn right
    wait_us(500000);               //1sec - 0.5sec
    Wheel.Speed(0.0f, 0.0f);
    wait_us(100000);
    Wheel.Speed(1.0f, 1.0f);
    wait_us(900000);
    Wheel.Speed(0.0f, 0.0f);
    wait_us(500000);
    Wheel.Speed(-1.0f, 1.0f);        //turning for the 3rd row
    wait_us(500000);
    Wheel.Speed(0.0f, 0.0f);
    wait_us(100000);

    Wheel.Speed(1.0f, 1.0f);        // go for 3rd row
    wait_us(1800000);
    Wheel.Speed(0.0f, 0.0f);        // wait
    wait_us(500000);
    Wheel.Speed(-1.0f, -1.0f);      // come back
    wait_us(1500000);
    Wheel.Speed(0.0f, 0.0f);
    wait_us(100000);
    Wheel.Speed(1.0f, -1.0f);      //turn right
    wait_us(500000);               //1sec - 0.5sec
    Wheel.Speed(0.0f, 0.0f);
    wait_us(100000);
    Wheel.Speed(1.0f, 1.0f);
    wait_us(900000);
    Wheel.Speed(-1.0f, 1.0f);        //turning for the 4th row
    wait_us(1000000);
    Wheel.Speed(0.0f, 0.0f);
    wait_us(100000);

    Wheel.Speed(1.0f, 1.0f);        // go for 4th row
    wait_us(1800000);
    Wheel.Speed(0.0f, 0.0f);        // wait
    wait_us(500000);
    Wheel.Speed(-1.0f, -1.0f);      // come back
    wait_us(1500000);
    Wheel.Speed(0.0f, 0.0f);
    wait_us(100000);
    Wheel.Speed(1.0f, -1.0f);      //turn right
    wait_us(500000);               //1sec - 0.5sec
    Wheel.Speed(0.0f, 0.0f);
    wait_us(100000);
    Wheel.Speed(1.0f, 1.0f);
    wait_us(500000);
    Wheel.Speed(0.0f, 0.0f);
    wait_us(100000);
    Wheel.Speed(-1.0f, 1.0f);        //turning for the 4th row
    wait_us(500000);
    Wheel.Speed(0.0f, 0.0f);
    wait_us(100000);
    Wheel.Speed(1.0f, 1.0f);        // go for 5th row
    wait_us(1800000);
    Wheel.Speed(0.0f, 0.0f);        // wait
    wait_us(500000);
    Wheel.Speed(-1.0f, -1.0f);      // come back
    wait_us(1500000);


    }
    else if (3000000 < buttonDuration < 6000000) {
    printf("1 meter\n");
    
                
    int lcounter = 0;        // Variable to hold a count of the number of pulses received
    int rcounter = 0;        // Variable to hold a count of the number of pulses received

    float current_l_pwm = 0.7f;
    float current_r_pwm = 0.7f;
    // Apply power to the left motor only
    
    // This loops runs forever
    while(1){
        Wheel.Speed(0.8f,0.7f);
        // Check to see if we have received a new pulse
        if(left_encoder.pulseReceived()>0){
            lcounter++;            
        }

        if(right_encoder.pulseReceived()>0){
            rcounter++;
        }

        if (lcounter < rcounter) {
            Wheel.Speed(Wheel.getSpeedRight(),Wheel.getSpeedLeft()+0.1);
            if (lcounter == 1.0 || rcounter == 1.0 ) {
            Wheel.Speed(Wheel.getSpeedRight()-0.2,Wheel.getSpeedLeft()-0.2);
            }
        }

        if (rcounter < lcounter) {
            Wheel.Speed(Wheel.getSpeedLeft(),Wheel.getSpeedRight()+0.1);
            if (lcounter == 1.0 || rcounter == 1.0 ) {
            Wheel.Speed(Wheel.getSpeedRight()-0.2,Wheel.getSpeedLeft()-0.2);
            }
        }

         // for 1 sec it turns 180
        if (0 <= lcounter <= 122) {
        Wheel.Speed(Wheel.getSpeedRight(),Wheel.getSpeedLeft());
        }
        else if (lcounter > 123) {
        Wheel.Speed(0.0f, 0.0f);
        }

    }

    
    }
    else if (buttonDuration > 6000000) {
    printf("1 meter\n");
    
                
    int lcounter = 0;        // Variable to hold a count of the number of pulses received
    int rcounter = 0;        // Variable to hold a count of the number of pulses received

    float current_l_pwm = 0.7f;
    float current_r_pwm = 0.7f;
    // Apply power to the left motor only
    
    // This loops runs forever
    while(1){
        Wheel.Speed(0.8f,0.7f);
        // Check to see if we have received a new pulse
        if(left_encoder.pulseReceived()>0){
            lcounter++;            
        }

        if(right_encoder.pulseReceived()>0){
            rcounter++;
        }

        if (lcounter < rcounter) {
            Wheel.Speed(Wheel.getSpeedRight(),Wheel.getSpeedLeft()+0.1);
            if (lcounter == 1.0 || rcounter == 1.0 ) {
            Wheel.Speed(Wheel.getSpeedRight()-0.2,Wheel.getSpeedLeft()-0.2);
            }
        }

        if (rcounter < lcounter) {
            Wheel.Speed(Wheel.getSpeedLeft(),Wheel.getSpeedRight()+0.1);
            if (lcounter == 1.0 || rcounter == 1.0 ) {
            Wheel.Speed(Wheel.getSpeedRight()-0.2,Wheel.getSpeedLeft()-0.2);
            }
        }

         // for 1 sec it turns 180
        if (0 <= rcounter <= 122) {
        Wheel.Speed(Wheel.getSpeedRight(),Wheel.getSpeedLeft());
        }
        if (rcounter == 123) {
        Wheel.Speed(0.0f, 0.0f);
        wait_us(100000);
        Wheel.Speed(1.0f, -1.0f);
        wait_us(1000000);
        }
        if (124 <= rcounter <= 242) {
        Wheel.Speed(Wheel.getSpeedRight(),Wheel.getSpeedLeft());
        }
        if (rcounter == 243) {
        Wheel.Speed(0.0f, 0.0f);
        wait_us(100000);
        Wheel.Speed(1.0f, -1.0f);
        wait_us(1000000);
        Wheel.Speed(0.0f, 0.0f);
        wait_us(100000);
        mario2(4);
        //tone       
        }

    }



}


}