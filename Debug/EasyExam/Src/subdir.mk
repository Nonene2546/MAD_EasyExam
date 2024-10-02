################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../EasyExam/Src/easy_exam.c 

OBJS += \
./EasyExam/Src/easy_exam.o 

C_DEPS += \
./EasyExam/Src/easy_exam.d 


# Each subdirectory must supply rules for building sources it contributes
EasyExam/Src/%.o EasyExam/Src/%.su EasyExam/Src/%.cyclo: ../EasyExam/Src/%.c EasyExam/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F767xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Chaks/STM32CubeIDE/65010121_exam/base/Drivers/ILI9341" -I"C:/Users/Chaks/STM32CubeIDE/65010121_exam/base/EasyExam/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-EasyExam-2f-Src

clean-EasyExam-2f-Src:
	-$(RM) ./EasyExam/Src/easy_exam.cyclo ./EasyExam/Src/easy_exam.d ./EasyExam/Src/easy_exam.o ./EasyExam/Src/easy_exam.su

.PHONY: clean-EasyExam-2f-Src

