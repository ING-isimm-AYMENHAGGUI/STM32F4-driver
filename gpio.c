
/* Includes ------------------------------------------------------------------*/
#include "gpio.h"

volatile unsigned short int *RCC_GPIO_Clock = (unsigned short int *) 0x40023830; 
volatile unsigned short int *RCC_GPIO_Reset = (unsigned short int *) 0x40023810;

/**
  * @brief  Deinitializes the gpio_x peripheral registers to their default reset values.
  * @param  gpio_x: where x can be (A..G) to select the GPIO peripheral.
  * @retval None
  */
void GPIO_ClockEnable (unsigned int * gpio_x)
{

  if (gpio_x == GPIO_A)
  {
    *RCC_GPIO_Clock |= (1<<0) ;
  }
  else if (gpio_x == GPIO_B)
  {
    *RCC_GPIO_Clock |= (1<<1) ;
  }
  else if (gpio_x == GPIO_C)
  {
    *RCC_GPIO_Clock |= (1<<2) ;
  }
  else if (gpio_x == GPIO_D)
  {
    *RCC_GPIO_Clock |= (1<<3) ;
  }    
  else if (gpio_x == GPIO_E)
  {
    *RCC_GPIO_Clock |= (1<<4) ;
  } 
  else if (gpio_x == GPIO_F)
  {
    *RCC_GPIO_Clock |= (1<<5) ;
  }
  else
  {
    if (gpio_x == GPIO_G)
    {
      *RCC_GPIO_Clock |= (1<<6) ;
    }
  }
}
/**
  * @brief  Deinitializes the gpio_x peripheral registers to their default reset values.
  * @param  gpio_x: where x can be (A..G) to select the GPIO peripheral.
  * @retval None
  */
void GPIO_DeInit(unsigned int * gpio_x)
{
  /* Check the parameters */
    
  if (gpio_x == GPIO_A)
  {
    *RCC_GPIO_Reset |= (1<<0);
    *RCC_GPIO_Reset &= ~(1<<0);
  }
  else if (gpio_x == GPIO_B)
  {
    *RCC_GPIO_Reset |= (1<<1);
    *RCC_GPIO_Reset &= ~(1<<1);
  }
  else if (gpio_x == GPIO_C)
  {
    *RCC_GPIO_Reset |= (1<<2);
    *RCC_GPIO_Reset &= ~(1<<2);
  }
  else if (gpio_x == GPIO_D)
  {
    *RCC_GPIO_Reset |= (1<<3);
    *RCC_GPIO_Reset &= ~(1<<3);
  }    
  else if (gpio_x == GPIO_E)
  {
    *RCC_GPIO_Reset |= (1<<4);
    *RCC_GPIO_Reset &= ~(1<<4);
  } 
  else if (gpio_x == GPIO_F)
  {
    *RCC_GPIO_Reset |= (1<<5);
    *RCC_GPIO_Reset &= ~(1<<5);
  }
  else
  {
    if (gpio_x == GPIO_G)
    {
      *RCC_GPIO_Reset |= (1<<6);
      *RCC_GPIO_Reset &= ~(1<<6);
    }
  }
}

/**
  * @brief  Configure the gpio_x
  * @param  gpio_x: where x can be (A..G) to select the GPIO peripheral.
  * @param  Mode: can be INPUT, OUTPUT, AF or AN
  * @param  typeOutput: can be PP or OD
  * @param  pin: can be 0...15
  * @retval None
  */

void GPIO_Init(unsigned int * gpio_x, char Mode, char typeOutput, short int pin)
{
 
  // Determiner la valeur de masque pour pr�parer la configureation la pin PD12 
  unsigned int mask = ~(0x3<<(pin*2));
  *(gpio_x + MODER) &= mask;
  *(gpio_x + MODER) |= Mode << (pin*2);

   mask = ~(0x1<<(pin));
  if (typeOutput == PP)
    *(gpio_x + OTYPER) &= mask;
  else
  *(gpio_x + OTYPER) |= ~mask;
  
 }

  
/**
  * @brief  Reads the specified input port pin.
  * @param  gpio_x: where x can be (A..G) to select the GPIO peripheral.
  * @param  GPIO_Pin:  specifies the port bit to read.
  *   This parameter can be GPIO_Pin_x where x can be (0..15).
  * @retval The input port pin value.
  */
unsigned  char GPIO_ReadInputDataBit(unsigned int *  gpio_x, unsigned  short int GPIO_Pin)
{
  unsigned  char bitstatus = 0x00;
  
  if (((*(gpio_x + IDR)) & GPIO_Pin) != 0x00)
  {
    bitstatus = 0x01;
  }
  else
  {
    bitstatus = 0x00;
  }
  return bitstatus;
}

/**
  * @brief  Reads the specified GPIO input data port.
  * @param  gpio_x: where x can be (A..G) to select the GPIO peripheral.
  * @retval GPIO input data port value.
  */
unsigned  short int GPIO_ReadInputData(unsigned int *  gpio_x)
{
  return (*(gpio_x + IDR));
}

/**
  * @brief  Sets or clears the selected data port bit.
  * @param  gpio_x: where x can be (A..G) to select the GPIO peripheral.
  * @param  GPIO_Pin: specifies the port bit to be written.
  *   This parameter can be one of GPIO_Pin_x where x can be (0..15).
  * @param  BitVal: specifies the value to be written to the selected bit.
  *   This parameter can be one of the BitAction enum values:
  *     @arg Bit_RESET: to clear the port pin
  *     @arg Bit_SET: to set the port pin
  * @retval None
  */
void GPIO_WriteBit(unsigned int * gpio_x, unsigned  short int GPIO_Pin, char BitVal)
{
  if (BitVal !=0x0)
  {
    *(gpio_x + ODR) |= GPIO_Pin;
  }
  else
  {
    *(gpio_x + ODR) &= (~GPIO_Pin);
  }
}

/**
  * @brief  Writes data to the specified GPIO data port.
  * @param  gpio_x: where x can be (A..G) to select the GPIO peripheral.
  * @param  PortVal: specifies the value to be written to the port output data register.
  * @retval None
  */
void GPIO_Write(unsigned int * gpio_x, unsigned  short int PortVal)
{
  *(gpio_x + ODR) = PortVal;
}


