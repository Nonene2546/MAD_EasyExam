/*
 * easy_exam.h
 *
 *  Created on: Dec 2, 2024
 *      Author: Chaks
 */

#ifndef EASY_EXAM_H
#define EASY_EXAM_H

#include "stm32f7xx_hal.h"

// ADC variable
#define NUM_CHANNELS 2
#define NUM_SAMPLING  64

static uint32_t adcBuffer[NUM_CHANNELS * NUM_SAMPLING];
static uint32_t adcAverages[NUM_CHANNELS];

// Function prototypes

// LED
void EE_Set_LED(uint8_t value);

// Builtin LED
void EE_Set_LD1(_Bool value);

// Button
void EE_Button_IRQHandler(uint16_t GPIO_Pin);
void EE_ButtonRed_IRQ();
void EE_ButtonYellow_IRQ();
void EE_ButtonGreen_IRQ();
void EE_ButtonBlue_IRQ();
void EE_UserButton_IRQ();

// ADC
void EE_ADC_CpltCallback(ADC_HandleTypeDef* hadc);
void EE_Custom_ADC_CpltCallback(uint32_t adc[NUM_CHANNELS]);
void EE_ADC_Init(ADC_HandleTypeDef* hadc);

// Timer
void EE_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);
void EE_TIM2_PeriodCallback();
void EE_TIM5_PeriodCallback();
void EE_Set_TIM_Interval(TIM_HandleTypeDef *htim, uint32_t interval);
void EE_Set_TIM_Freq(TIM_HandleTypeDef *htim, float freq);


#endif  // EASY_EXAM_H
