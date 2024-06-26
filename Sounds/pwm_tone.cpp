/* Includes ------------------------------------------------------------------*/
#include "pwm_tone.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/**
   * @brief     Tune Function
   * @param  name : Choose the PwmOut
                    period : this param is tune value. (C_3...B_5)
                    beat : this param is beat value. (1..16) 1 means 1/16 beat
   * @retval    None
   */
void Tune(PwmOut& name, int period, int beat)
{  
    int delay,count;
    delay = beat*63;
    name.period_us(period);
    name.write(0.50f); // 50% duty cycle

    //for (int i=0; i<10000000;i++){ __NOP();count++;}
    thread_sleep_for(delay);
    //wait_us(delay*1000); // 1 beat
    //name.period_us(0); // Sound off
    name=0;
}

/**
   * @brief     Auto tunes Function
   * @param  name : Choose the PwmOut
                    period : this param is tune value. (C_3...B_5)
                    beat : this param is beat value. (1..16) 1 means 1/16 beat
   * @retval    None
   */
void Auto_tunes(PwmOut& name, int period, int beat)
{    
    int delay;
    
    delay = beat*63;
    name.period_us(period);
    name.write(0.50f); // 50% duty cycle
    thread_sleep_for(delay);
    //wait_us(delay*1000);
}

/**
   * @brief     Stop tunes Function
   * @param  name : Choose the PwmOut
   * @retval    None
   */
void Stop_tunes(PwmOut& name)
{
    name.period_us(0);
}
