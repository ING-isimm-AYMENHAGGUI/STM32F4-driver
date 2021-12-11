

#include "gpio.h"

/* Private define ------------------------------------------------------------*/
#define NOMBRE_BOUCLES 10
                                                       
/* Private function prototypes -----------------------------------------------*/
void Delay(volatile unsigned  int  nCount);


/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */
int main(void)
{
  unsigned  int counter = 0x00;  

  /* Activer l'orloge pour le Port C */
  GPIO_ClockEnable(GPIO_D);

  /* re-intialiser les registers de port C */
  GPIO_DeInit(GPIO_D);
  
/* --- Configure PC8 et PC9 en mode Output Push pull avec un speed de 2MHz ---*/  

  GPIO_Init(GPIO_D, OUTPUT,  PP, 12);
  GPIO_Init(GPIO_D, OUTPUT,  PP, 13);
  GPIO_Init(GPIO_D, OUTPUT,  PP, 14);
  GPIO_Init(GPIO_D, OUTPUT,  PP, 15);

  for(counter=0; counter<NOMBRE_BOUCLES ; counter++)
  {
   /* Turn On LD3 and LD4 */
   GPIO_WriteBit(GPIO_D, GPIO_Pin_12, 0x01)  ;
   Delay(0x1FFFFF) ;
   GPIO_WriteBit(GPIO_D, GPIO_Pin_13, 0x01)  ;
   Delay(0x1FFFFF) ;
    GPIO_WriteBit(GPIO_D, GPIO_Pin_14, 0x01)  ;
    Delay(0x1FFFFF) ;
   GPIO_WriteBit(GPIO_D, GPIO_Pin_15, 0x01)  ;
    Delay(0x1FFFFF) ;
    Delay(0x1FFFFF) ;
    
    /* Turn off LD3 and LD4 */
   GPIO_WriteBit(GPIO_D, GPIO_Pin_12, 0x00)  ;
   Delay(0x1FFFFF) ;
   GPIO_WriteBit(GPIO_D, GPIO_Pin_13, 0x00)  ;
   Delay(0x1FFFFF) ;
   GPIO_WriteBit(GPIO_D, GPIO_Pin_14, 0x00)  ;
   Delay(0x1FFFFF) ;
   GPIO_WriteBit(GPIO_D, GPIO_Pin_15, 0x00)  ;
   Delay(0x1FFFFF) ;
   
    Delay(0x1FFFFF) ;
           
  }
  while(1);
}
/**
  * @brief  Inserts a delay time.
  * @param  nCount: specifies the delay time length.
  * @retval None
  */
void Delay(volatile unsigned  int  nCount)
{
  for(; nCount != 0; nCount--);
}

