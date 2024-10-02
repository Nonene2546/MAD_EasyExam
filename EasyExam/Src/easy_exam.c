/*
 * easy_exam.h
 *
 *  Created on: Dec 2, 2024
 *      Author: Chaks
 */

#include "easy_exam.h"
#include "main.h"

void EE_Set_LED(uint8_t value){
	// 0b zzzz zzzz <- value
	HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, (value & 0x01) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, (value & 0x02) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, (value & 0x04) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, (value & 0x08) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, (value & 0x10) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, (value & 0x20) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, (value & 0x40) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED7_GPIO_Port, LED7_Pin, (value & 0x80) ? GPIO_PIN_SET : GPIO_PIN_RESET);
}

void EE_Set_Builtin_LED(uint8_t value){
	// 0b xxxx xzzz <- value, PB0 = LSB
	HAL_GPIO_WritePin(LD1_GPIO_Port, LD1_Pin, (value & 0x01) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, (value & 0x02) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, (value & 0x04) ? GPIO_PIN_SET : GPIO_PIN_RESET);
}

void EE_Button_IRQHandler(uint16_t GPIO_Pin){
	if (GPIO_Pin == Button_Red_Pin){
		EE_ButtonRed_IRQ();
	}
	else if(GPIO_Pin == Button_Yellow_Pin){
		EE_ButtonYellow_IRQ();
	}
	else if(GPIO_Pin == Button_Green_Pin){
		EE_ButtonGreen_IRQ();
	}
	else if(GPIO_Pin == Button_Blue_Pin){
		EE_ButtonBlue_IRQ();
	}
	else if(GPIO_Pin == UserButton_Pin){
		EE_UserButton_IRQ();
	}
}

void EE_ADC_CpltCallback(ADC_HandleTypeDef* hadc){
	for (int channel = 0; channel < NUM_CHANNELS; channel++) {
		uint32_t sum = 0;
		for (int sample = 0; sample < NUM_SAMPLING; sample++) {
			sum += adcBuffer[sample * NUM_CHANNELS + channel];
		}
		adcAverages[channel] = sum / NUM_SAMPLING;
	}
	EE_Custom_ADC_CpltCallback(adcAverages);
}

void EE_ADC_Start(ADC_HandleTypeDef* hadc){
	HAL_ADC_Start_DMA(hadc, (uint32_t*)adcBuffer, NUM_SAMPLING * NUM_CHANNELS);
}

void EE_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	if(htim->Instance == TIM2){
		EE_TIM2_PeriodCallback();
	}
	else if(htim->Instance == TIM5){
		EE_TIM5_PeriodCallback();
	}
}

void EE_Set_TIM_Interval(TIM_HandleTypeDef *htim, uint32_t interval){
	// interval (ms) min 1 ms
	__HAL_TIM_SET_AUTORELOAD(htim, (10*interval) - 1);
}

void EE_Set_TIM_Freq(TIM_HandleTypeDef *htim, float freq){
	// freq (Hz) max 5000 Hz
	__HAL_TIM_SET_AUTORELOAD(htim, (10000/freq) - 1);
}


