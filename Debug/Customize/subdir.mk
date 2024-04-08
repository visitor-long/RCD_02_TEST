################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Customize/led.c \
../Customize/pwm_in.c 

OBJS += \
./Customize/led.o \
./Customize/pwm_in.o 

C_DEPS += \
./Customize/led.d \
./Customize/pwm_in.d 


# Each subdirectory must supply rules for building sources it contributes
Customize/%.o Customize/%.su Customize/%.cyclo: ../Customize/%.c Customize/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xE -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/wolf.long/Documents/STM32_Project/RCD_02_TEST/Customize" -I"C:/Users/wolf.long/Documents/GitHub/RCD_02_TEST/Customize" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Customize

clean-Customize:
	-$(RM) ./Customize/led.cyclo ./Customize/led.d ./Customize/led.o ./Customize/led.su ./Customize/pwm_in.cyclo ./Customize/pwm_in.d ./Customize/pwm_in.o ./Customize/pwm_in.su

.PHONY: clean-Customize

