#include "adc.h"
#include "stdio.h"
#include "string.h"

extern ADC_HandleTypeDef hadc1;
extern UART_HandleTypeDef huart2;


uint16_t value_adc = 0, temp = 0;
float voltage = 0 ;
char buf_temp[100];


int adc_value(uint32_t *data )
{

		  HAL_ADC_Start(&hadc1);
	  // ADC poll for conversion
	  HAL_ADC_PollForConversion(&hadc1, 5);
	  // get the ADC conversion value
	  value_adc = HAL_ADC_GetValue(&hadc1);
	  // end ADC convertion
	  HAL_ADC_Stop(&hadc1);
	  // convert ADC value into voltage
	  voltage = (value_adc*3.3)/4096;
		HAL_Delay(10);
	  // convert the voltage into temperature
	  
	   temp = voltage*100;
	  

		HAL_Delay(10);
	  //convert the integer value to string,
	  //to display in the LCD
	
		  	int len = sprintf(buf_temp," voltage is %.2f ",voltage);
				int len1 = strlen(buf_temp);
	      HAL_UART_Transmit(&huart2, (uint8_t*) buf_temp, len1, -1);
		  
			HAL_Delay (50);
	 
}