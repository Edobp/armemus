#include "tm4c123gh6pm.h"

void Delay(void);
int main(void)
{
  SYSCTL_RCGCGPIO_R = 0x20;//habilita GPIO F
  GPIO_PORTF_DIR_R = 0x0F;//especifica si es E o S
  GPIO_PORTF_DEN_R = 0xFF;//configuracion del puerto F como digital

  while(1)
  {
	 GPIO_PORTF_DATA_R ^= 0x02;
   Delay();     
  }
}
void Delay(void){
  unsigned long volatile time;
  time = 727240*100/91;
  while(time){
    time--;
  }
}

