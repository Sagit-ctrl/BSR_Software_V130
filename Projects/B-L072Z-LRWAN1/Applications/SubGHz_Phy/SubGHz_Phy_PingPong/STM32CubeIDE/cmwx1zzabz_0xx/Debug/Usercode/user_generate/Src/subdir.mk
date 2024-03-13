################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_generate/Src/adc.c \
C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_generate/Src/gpio.c \
C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_generate/Src/i2c.c \
C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_generate/Src/lptim.c \
C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_generate/Src/usart.c 

OBJS += \
./Usercode/user_generate/Src/adc.o \
./Usercode/user_generate/Src/gpio.o \
./Usercode/user_generate/Src/i2c.o \
./Usercode/user_generate/Src/lptim.o \
./Usercode/user_generate/Src/usart.o 

C_DEPS += \
./Usercode/user_generate/Src/adc.d \
./Usercode/user_generate/Src/gpio.d \
./Usercode/user_generate/Src/i2c.d \
./Usercode/user_generate/Src/lptim.d \
./Usercode/user_generate/Src/usart.d 


# Each subdirectory must supply rules for building sources it contributes
Usercode/user_generate/Src/adc.o: C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_generate/Src/adc.c Usercode/user_generate/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DSTM32L072xx -DCMWX1ZZABZ0XX -c -I../../../SubGHz_Phy/App -I../../../SubGHz_Phy/Target -I../../../Core/Inc -I../../../../../../../../Utilities/misc -I../../../../../../../../Utilities/timer -I../../../../../../../../Utilities/trace/adv_trace -I../../../../../../../../Utilities/lpm/tiny_lpm -I../../../../../../../../Utilities/sequencer -I../../../../../../../../Drivers/BSP/B-L072Z-LRWAN1 -I../../../../../../../../Drivers/BSP/CMWX1ZZABZ_0xx -I../../../../../../../../Drivers/STM32L0xx_HAL_Driver/Inc -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Middlewares/Third_Party/SubGHz_Phy -I../../../../../../../../Middlewares/Third_Party/SubGHz_Phy/sx1276 -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_app/Inc" -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_change/Inc" -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_device/Inc" -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_generate/Inc" -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_util/Inc" -Os -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Usercode/user_generate/Src/gpio.o: C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_generate/Src/gpio.c Usercode/user_generate/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DSTM32L072xx -DCMWX1ZZABZ0XX -c -I../../../SubGHz_Phy/App -I../../../SubGHz_Phy/Target -I../../../Core/Inc -I../../../../../../../../Utilities/misc -I../../../../../../../../Utilities/timer -I../../../../../../../../Utilities/trace/adv_trace -I../../../../../../../../Utilities/lpm/tiny_lpm -I../../../../../../../../Utilities/sequencer -I../../../../../../../../Drivers/BSP/B-L072Z-LRWAN1 -I../../../../../../../../Drivers/BSP/CMWX1ZZABZ_0xx -I../../../../../../../../Drivers/STM32L0xx_HAL_Driver/Inc -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Middlewares/Third_Party/SubGHz_Phy -I../../../../../../../../Middlewares/Third_Party/SubGHz_Phy/sx1276 -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_app/Inc" -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_change/Inc" -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_device/Inc" -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_generate/Inc" -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_util/Inc" -Os -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Usercode/user_generate/Src/i2c.o: C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_generate/Src/i2c.c Usercode/user_generate/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DSTM32L072xx -DCMWX1ZZABZ0XX -c -I../../../SubGHz_Phy/App -I../../../SubGHz_Phy/Target -I../../../Core/Inc -I../../../../../../../../Utilities/misc -I../../../../../../../../Utilities/timer -I../../../../../../../../Utilities/trace/adv_trace -I../../../../../../../../Utilities/lpm/tiny_lpm -I../../../../../../../../Utilities/sequencer -I../../../../../../../../Drivers/BSP/B-L072Z-LRWAN1 -I../../../../../../../../Drivers/BSP/CMWX1ZZABZ_0xx -I../../../../../../../../Drivers/STM32L0xx_HAL_Driver/Inc -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Middlewares/Third_Party/SubGHz_Phy -I../../../../../../../../Middlewares/Third_Party/SubGHz_Phy/sx1276 -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_app/Inc" -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_change/Inc" -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_device/Inc" -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_generate/Inc" -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_util/Inc" -Os -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Usercode/user_generate/Src/lptim.o: C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_generate/Src/lptim.c Usercode/user_generate/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DSTM32L072xx -DCMWX1ZZABZ0XX -c -I../../../SubGHz_Phy/App -I../../../SubGHz_Phy/Target -I../../../Core/Inc -I../../../../../../../../Utilities/misc -I../../../../../../../../Utilities/timer -I../../../../../../../../Utilities/trace/adv_trace -I../../../../../../../../Utilities/lpm/tiny_lpm -I../../../../../../../../Utilities/sequencer -I../../../../../../../../Drivers/BSP/B-L072Z-LRWAN1 -I../../../../../../../../Drivers/BSP/CMWX1ZZABZ_0xx -I../../../../../../../../Drivers/STM32L0xx_HAL_Driver/Inc -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Middlewares/Third_Party/SubGHz_Phy -I../../../../../../../../Middlewares/Third_Party/SubGHz_Phy/sx1276 -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_app/Inc" -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_change/Inc" -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_device/Inc" -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_generate/Inc" -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_util/Inc" -Os -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Usercode/user_generate/Src/usart.o: C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_generate/Src/usart.c Usercode/user_generate/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DSTM32L072xx -DCMWX1ZZABZ0XX -c -I../../../SubGHz_Phy/App -I../../../SubGHz_Phy/Target -I../../../Core/Inc -I../../../../../../../../Utilities/misc -I../../../../../../../../Utilities/timer -I../../../../../../../../Utilities/trace/adv_trace -I../../../../../../../../Utilities/lpm/tiny_lpm -I../../../../../../../../Utilities/sequencer -I../../../../../../../../Drivers/BSP/B-L072Z-LRWAN1 -I../../../../../../../../Drivers/BSP/CMWX1ZZABZ_0xx -I../../../../../../../../Drivers/STM32L0xx_HAL_Driver/Inc -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Middlewares/Third_Party/SubGHz_Phy -I../../../../../../../../Middlewares/Third_Party/SubGHz_Phy/sx1276 -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_app/Inc" -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_change/Inc" -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_device/Inc" -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_generate/Inc" -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_util/Inc" -Os -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Usercode-2f-user_generate-2f-Src

clean-Usercode-2f-user_generate-2f-Src:
	-$(RM) ./Usercode/user_generate/Src/adc.cyclo ./Usercode/user_generate/Src/adc.d ./Usercode/user_generate/Src/adc.o ./Usercode/user_generate/Src/adc.su ./Usercode/user_generate/Src/gpio.cyclo ./Usercode/user_generate/Src/gpio.d ./Usercode/user_generate/Src/gpio.o ./Usercode/user_generate/Src/gpio.su ./Usercode/user_generate/Src/i2c.cyclo ./Usercode/user_generate/Src/i2c.d ./Usercode/user_generate/Src/i2c.o ./Usercode/user_generate/Src/i2c.su ./Usercode/user_generate/Src/lptim.cyclo ./Usercode/user_generate/Src/lptim.d ./Usercode/user_generate/Src/lptim.o ./Usercode/user_generate/Src/lptim.su ./Usercode/user_generate/Src/usart.cyclo ./Usercode/user_generate/Src/usart.d ./Usercode/user_generate/Src/usart.o ./Usercode/user_generate/Src/usart.su

.PHONY: clean-Usercode-2f-user_generate-2f-Src

