################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Sagit/Desktop/BSR_Software_V130/Usercode/user_device/Src/user_modem.c \
C:/Users/Sagit/Desktop/BSR_Software_V130/Usercode/user_device/Src/user_payload.c \
C:/Users/Sagit/Desktop/BSR_Software_V130/Usercode/user_device/Src/user_protocol.c 

OBJS += \
./Usercode/user_device/Src/user_modem.o \
./Usercode/user_device/Src/user_payload.o \
./Usercode/user_device/Src/user_protocol.o 

C_DEPS += \
./Usercode/user_device/Src/user_modem.d \
./Usercode/user_device/Src/user_payload.d \
./Usercode/user_device/Src/user_protocol.d 


# Each subdirectory must supply rules for building sources it contributes
Usercode/user_device/Src/user_modem.o: C:/Users/Sagit/Desktop/BSR_Software_V130/Usercode/user_device/Src/user_modem.c Usercode/user_device/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DSTM32L072xx -DCMWX1ZZABZ0XX -c -I../../../SubGHz_Phy/App -I../../../SubGHz_Phy/Target -I../../../Core/Inc -I../../../../../../../../Utilities/misc -I../../../../../../../../Utilities/timer -I../../../../../../../../Utilities/trace/adv_trace -I../../../../../../../../Utilities/lpm/tiny_lpm -I../../../../../../../../Utilities/sequencer -I../../../../../../../../Drivers/BSP/B-L072Z-LRWAN1 -I../../../../../../../../Drivers/BSP/CMWX1ZZABZ_0xx -I../../../../../../../../Drivers/STM32L0xx_HAL_Driver/Inc -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Middlewares/Third_Party/SubGHz_Phy -I../../../../../../../../Middlewares/Third_Party/SubGHz_Phy/sx1276 -I"C:/Users/Sagit/Desktop/BSR_Software_V130/Usercode/user_app/Inc" -I"C:/Users/Sagit/Desktop/BSR_Software_V130/Usercode/user_change/Inc" -I"C:/Users/Sagit/Desktop/BSR_Software_V130/Usercode/user_device/Inc" -I"C:/Users/Sagit/Desktop/BSR_Software_V130/Usercode/user_generate/Inc" -I"C:/Users/Sagit/Desktop/BSR_Software_V130/Usercode/user_util/Inc" -Os -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Usercode/user_device/Src/user_payload.o: C:/Users/Sagit/Desktop/BSR_Software_V130/Usercode/user_device/Src/user_payload.c Usercode/user_device/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DSTM32L072xx -DCMWX1ZZABZ0XX -c -I../../../SubGHz_Phy/App -I../../../SubGHz_Phy/Target -I../../../Core/Inc -I../../../../../../../../Utilities/misc -I../../../../../../../../Utilities/timer -I../../../../../../../../Utilities/trace/adv_trace -I../../../../../../../../Utilities/lpm/tiny_lpm -I../../../../../../../../Utilities/sequencer -I../../../../../../../../Drivers/BSP/B-L072Z-LRWAN1 -I../../../../../../../../Drivers/BSP/CMWX1ZZABZ_0xx -I../../../../../../../../Drivers/STM32L0xx_HAL_Driver/Inc -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Middlewares/Third_Party/SubGHz_Phy -I../../../../../../../../Middlewares/Third_Party/SubGHz_Phy/sx1276 -I"C:/Users/Sagit/Desktop/BSR_Software_V130/Usercode/user_app/Inc" -I"C:/Users/Sagit/Desktop/BSR_Software_V130/Usercode/user_change/Inc" -I"C:/Users/Sagit/Desktop/BSR_Software_V130/Usercode/user_device/Inc" -I"C:/Users/Sagit/Desktop/BSR_Software_V130/Usercode/user_generate/Inc" -I"C:/Users/Sagit/Desktop/BSR_Software_V130/Usercode/user_util/Inc" -Os -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Usercode/user_device/Src/user_protocol.o: C:/Users/Sagit/Desktop/BSR_Software_V130/Usercode/user_device/Src/user_protocol.c Usercode/user_device/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DSTM32L072xx -DCMWX1ZZABZ0XX -c -I../../../SubGHz_Phy/App -I../../../SubGHz_Phy/Target -I../../../Core/Inc -I../../../../../../../../Utilities/misc -I../../../../../../../../Utilities/timer -I../../../../../../../../Utilities/trace/adv_trace -I../../../../../../../../Utilities/lpm/tiny_lpm -I../../../../../../../../Utilities/sequencer -I../../../../../../../../Drivers/BSP/B-L072Z-LRWAN1 -I../../../../../../../../Drivers/BSP/CMWX1ZZABZ_0xx -I../../../../../../../../Drivers/STM32L0xx_HAL_Driver/Inc -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Middlewares/Third_Party/SubGHz_Phy -I../../../../../../../../Middlewares/Third_Party/SubGHz_Phy/sx1276 -I"C:/Users/Sagit/Desktop/BSR_Software_V130/Usercode/user_app/Inc" -I"C:/Users/Sagit/Desktop/BSR_Software_V130/Usercode/user_change/Inc" -I"C:/Users/Sagit/Desktop/BSR_Software_V130/Usercode/user_device/Inc" -I"C:/Users/Sagit/Desktop/BSR_Software_V130/Usercode/user_generate/Inc" -I"C:/Users/Sagit/Desktop/BSR_Software_V130/Usercode/user_util/Inc" -Os -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Usercode-2f-user_device-2f-Src

clean-Usercode-2f-user_device-2f-Src:
	-$(RM) ./Usercode/user_device/Src/user_modem.cyclo ./Usercode/user_device/Src/user_modem.d ./Usercode/user_device/Src/user_modem.o ./Usercode/user_device/Src/user_modem.su ./Usercode/user_device/Src/user_payload.cyclo ./Usercode/user_device/Src/user_payload.d ./Usercode/user_device/Src/user_payload.o ./Usercode/user_device/Src/user_payload.su ./Usercode/user_device/Src/user_protocol.cyclo ./Usercode/user_device/Src/user_protocol.d ./Usercode/user_device/Src/user_protocol.o ./Usercode/user_device/Src/user_protocol.su

.PHONY: clean-Usercode-2f-user_device-2f-Src

