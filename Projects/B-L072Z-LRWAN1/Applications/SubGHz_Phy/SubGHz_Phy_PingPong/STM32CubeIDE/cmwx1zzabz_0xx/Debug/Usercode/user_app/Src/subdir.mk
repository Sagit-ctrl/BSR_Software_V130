################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_app/Src/user_common.c \
C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_app/Src/user_lora.c \
C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_app/Src/user_main.c 

OBJS += \
./Usercode/user_app/Src/user_common.o \
./Usercode/user_app/Src/user_lora.o \
./Usercode/user_app/Src/user_main.o 

C_DEPS += \
./Usercode/user_app/Src/user_common.d \
./Usercode/user_app/Src/user_lora.d \
./Usercode/user_app/Src/user_main.d 


# Each subdirectory must supply rules for building sources it contributes
Usercode/user_app/Src/user_common.o: C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_app/Src/user_common.c Usercode/user_app/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DSTM32L072xx -DCMWX1ZZABZ0XX -c -I../../../SubGHz_Phy/App -I../../../SubGHz_Phy/Target -I../../../Core/Inc -I../../../../../../../../Utilities/misc -I../../../../../../../../Utilities/timer -I../../../../../../../../Utilities/trace/adv_trace -I../../../../../../../../Utilities/lpm/tiny_lpm -I../../../../../../../../Utilities/sequencer -I../../../../../../../../Drivers/BSP/B-L072Z-LRWAN1 -I../../../../../../../../Drivers/BSP/CMWX1ZZABZ_0xx -I../../../../../../../../Drivers/STM32L0xx_HAL_Driver/Inc -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Middlewares/Third_Party/SubGHz_Phy -I../../../../../../../../Middlewares/Third_Party/SubGHz_Phy/sx1276 -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_app/Inc" -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_change/Inc" -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_device/Inc" -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_generate/Inc" -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_util/Inc" -Os -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Usercode/user_app/Src/user_lora.o: C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_app/Src/user_lora.c Usercode/user_app/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DSTM32L072xx -DCMWX1ZZABZ0XX -c -I../../../SubGHz_Phy/App -I../../../SubGHz_Phy/Target -I../../../Core/Inc -I../../../../../../../../Utilities/misc -I../../../../../../../../Utilities/timer -I../../../../../../../../Utilities/trace/adv_trace -I../../../../../../../../Utilities/lpm/tiny_lpm -I../../../../../../../../Utilities/sequencer -I../../../../../../../../Drivers/BSP/B-L072Z-LRWAN1 -I../../../../../../../../Drivers/BSP/CMWX1ZZABZ_0xx -I../../../../../../../../Drivers/STM32L0xx_HAL_Driver/Inc -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Middlewares/Third_Party/SubGHz_Phy -I../../../../../../../../Middlewares/Third_Party/SubGHz_Phy/sx1276 -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_app/Inc" -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_change/Inc" -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_device/Inc" -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_generate/Inc" -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_util/Inc" -Os -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Usercode/user_app/Src/user_main.o: C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_app/Src/user_main.c Usercode/user_app/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DSTM32L072xx -DCMWX1ZZABZ0XX -c -I../../../SubGHz_Phy/App -I../../../SubGHz_Phy/Target -I../../../Core/Inc -I../../../../../../../../Utilities/misc -I../../../../../../../../Utilities/timer -I../../../../../../../../Utilities/trace/adv_trace -I../../../../../../../../Utilities/lpm/tiny_lpm -I../../../../../../../../Utilities/sequencer -I../../../../../../../../Drivers/BSP/B-L072Z-LRWAN1 -I../../../../../../../../Drivers/BSP/CMWX1ZZABZ_0xx -I../../../../../../../../Drivers/STM32L0xx_HAL_Driver/Inc -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Middlewares/Third_Party/SubGHz_Phy -I../../../../../../../../Middlewares/Third_Party/SubGHz_Phy/sx1276 -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_app/Inc" -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_change/Inc" -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_device/Inc" -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_generate/Inc" -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_util/Inc" -Os -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Usercode-2f-user_app-2f-Src

clean-Usercode-2f-user_app-2f-Src:
	-$(RM) ./Usercode/user_app/Src/user_common.cyclo ./Usercode/user_app/Src/user_common.d ./Usercode/user_app/Src/user_common.o ./Usercode/user_app/Src/user_common.su ./Usercode/user_app/Src/user_lora.cyclo ./Usercode/user_app/Src/user_lora.d ./Usercode/user_app/Src/user_lora.o ./Usercode/user_app/Src/user_lora.su ./Usercode/user_app/Src/user_main.cyclo ./Usercode/user_app/Src/user_main.d ./Usercode/user_app/Src/user_main.o ./Usercode/user_app/Src/user_main.su

.PHONY: clean-Usercode-2f-user_app-2f-Src

