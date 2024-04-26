 #include "mbed.h"
 #include "pwm_tone.h"
 #include "motor.h"
 #define TIME_PERIOD 2             //Constant compiler Values here 2 equates to 2ms or 500Hz base Frequency
 PwmOut buzzer(D5);
  
 void tone1(void){
    Tune(buzzer,1e6/C6,4);
    buzzer.period_ms(TIME_PERIOD);
 }
 
void tone2(void){
    Tune(buzzer,1e6/E6,4);
    buzzer.period_ms(TIME_PERIOD);
 }

void close_encounter(int s){
    Tune(buzzer,1e6/Dd5,s*2); //It's a close encounter of the 3rd kind of!!!
    Tune(buzzer,1e6/E5,s*2);
    Tune(buzzer,1e6/C5,s*2);
    Tune(buzzer,1e6/C4,s*2);
    Tune(buzzer,1e6/G4,s*4);
    buzzer.period_ms(TIME_PERIOD);
 }
 
 void jingle_bells(int s){
    Tune(buzzer,1e6/E4,s*2); //Jingle Bells!!!
    Tune(buzzer,1e6/E4,s*2);
    Tune(buzzer,1e6/E4,s*4);
  
    Tune(buzzer,1e6/E4,s*2);
    Tune(buzzer,1e6/E4,s*2);
    Tune(buzzer,1e6/E4,s*4);
    
    Tune(buzzer,1e6/E4,s*2);
    Tune(buzzer,1e6/G4,s*2);
    Tune(buzzer,1e6/C4,s*3);
    Tune(buzzer,1e6/E4,s*1);
    
    Tune(buzzer,1e6/E4,s*8);
  
    Tune(buzzer,1e6/F4,s*2);
    Tune(buzzer,1e6/F4,s*2);
    Tune(buzzer,1e6/F4,s*3);
    Tune(buzzer,1e6/F4,s*1);
    
    Tune(buzzer,1e6/F4,s*2);
    Tune(buzzer,1e6/E4,s*2);
    Tune(buzzer,1e6/E4,s*2);
    Tune(buzzer,1e6/E4,s*1);
    Tune(buzzer,1e6/E4,s*1);
    
    Tune(buzzer,1e6/E4,s*2);
    Tune(buzzer,1e6/Dd4,s*2);
    Tune(buzzer,1e6/Dd4,s*2);
    Tune(buzzer,1e6/E4,s*2);
  
    Tune(buzzer,1e6/Dd4,s*4);
    Tune(buzzer,1e6/G4,s*4);
    buzzer.period_ms(TIME_PERIOD);
  }
void twinkle(int s){
    Tune(buzzer,1e6/C4,s*2); //Twinkle Little Star!!!!!
    Tune(buzzer,1e6/C4,s*2);
    Tune(buzzer,1e6/G4,s*2);
    Tune(buzzer,1e6/G4,s*2);
  
    Tune(buzzer,1e6/Aa4,s*2);
    Tune(buzzer,1e6/Aa4,s*2);
    Tune(buzzer,1e6/G4,s*4);
    
    Tune(buzzer,1e6/F4,s*2);
    Tune(buzzer,1e6/F4,s*2);
    Tune(buzzer,1e6/E4,s*2);
    Tune(buzzer,1e6/E4,s*2);

    Tune(buzzer,1e6/Dd4,s*2);
    Tune(buzzer,1e6/Dd4,s*2);
    Tune(buzzer,1e6/C4,s*4);
    buzzer.period_ms(TIME_PERIOD);
  }
void mario1(int s){
    Tune(buzzer,1e6/E5,s*2);
    Tune(buzzer,1e6/E5,s*2);
    Tune(buzzer,1e6/E5,s*2);
    Tune(buzzer,1e6/C5,s*2);
    Tune(buzzer,1e6/E5,s*2);
    Tune(buzzer,1e6/G5,s*2);
    Tune(buzzer,1e6/E5,s*4);
    buzzer.period_ms(TIME_PERIOD);
}

void mario2(int s){
    Tune(buzzer,1e6/G3,s*0.5);
    Tune(buzzer,1e6/C4,s*0.5);
    Tune(buzzer,1e6/E4,s*0.5);
    Tune(buzzer,1e6/G4,s*0.5);
    Tune(buzzer,1e6/C5,s*0.5);
    Tune(buzzer,1e6/E5,s*0.5);
    Tune(buzzer,1e6/G5,s*1.8);
    Tune(buzzer,1e6/E5,s*1.2);

    Tune(buzzer,1e6/G3s,s*0.5);
    Tune(buzzer,1e6/C4,s*0.5);
    Tune(buzzer,1e6/D4s,s*0.5);
    Tune(buzzer,1e6/G4s,s*0.5);
    Tune(buzzer,1e6/C5,s*0.5);
    Tune(buzzer,1e6/D5s,s*0.5);
    Tune(buzzer,1e6/G5s,s*1.8);
    Tune(buzzer,1e6/D5s,s*1.2);

    Tune(buzzer,1e6/A3s,s*0.5);
    Tune(buzzer,1e6/D4,s*0.5);
    Tune(buzzer,1e6/F4,s*0.5);
    Tune(buzzer,1e6/A4s,s*0.5);
    Tune(buzzer,1e6/D5,s*0.5);
    Tune(buzzer,1e6/F5,s*0.5);
    Tune(buzzer,1e6/A5s,s*2.2);
    Tune(buzzer,1e6/C6,s*3.5);
    buzzer.period_ms(TIME_PERIOD);
}