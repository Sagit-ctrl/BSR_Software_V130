################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_util/Src/user_event_drive.c \
C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_util/Src/user_flash.c \
C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_util/Src/user_lpm.c \
C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_util/Src/user_rtc.c \
C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_util/Src/user_string.c \
C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_util/Src/user_time.c \
C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_util/Src/user_timer.c \
C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_util/Src/user_util.c 

OBJS += \
./Usercode/user_util/Src/user_event_drive.o \
./Usercode/user_util/Src/user_flash.o \
./Usercode/user_util/Src/user_lpm.o \
./Usercode/user_util/Src/user_rtc.o \
./Usercode/user_util/Src/user_string.o \
./Usercode/user_util/Src/user_time.o \
./Usercode/user_util/Src/user_timer.o \
./Usercode/user_util/Src/user_util.o 

C_DEPS += \
./Usercode/user_util/Src/user_event_drive.d \
./Usercode/user_util/Src/user_flash.d \
./Usercode/user_util/Src/user_lpm.d \
./Usercode/user_util/Src/user_rtc.d \
./Usercode/user_util/Src/user_string.d \
./Usercode/user_util/Src/user_time.d \
./Usercode/user_util/Src/user_timer.d \
./Usercode/user_util/Src/user_util.d 


# Each subdirectory must supply rules for building sources it contributes
Usercode/user_util/Src/user_event_drive.o: C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_util/Src/user_event_drive.c Usercode/user_util/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DSTM32L072xx -DCMWX1ZZABZ0XX -DDEVICE_TYPE_STATION -c -I../../../SubGHz_Phy/App -I../../../SubGHz_Phy/Target -I../../../Core/Inc -I../../../../../../../../Utilities/misc -I../../../../../../../../Utilities/timer -I../../../../../../../../Utilities/trace/adv_trace -I../../../../../../../../Utilities/lpm/tiny_lpm -I../../../../../../../../Utilities/sequencer -I../../../../../../../../Drivers/BSP/B-L072Z-LRWAN1 -I../../../../../../../../Drivers/BSP/CMWX1ZZABZ_0xx -I../../../../../../../../Drivers/STM32L0xx_HAL_Driver/Inc -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Middlewares/Third_Party/SubGHz_Phy -I../../../../../../../../Middlewares/Third_Party/SubGHz_Phy/sx1276 -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_app/Inc" -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_change/Inc" -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_device/Inc" -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_generate/Inc" -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_util/Inc" -Os -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Usercode/user_util/Src/user_flash.o: C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_util/Src/user_flash.c Usercode/user_util/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DSTM32L072xx -DCMWX1ZZABZ0XX -DDEVICE_TYPE_STATION -c -I../../../SubGHz_Phy/App -I../../../SubGHz_Phy/Target -I../../../Core/Inc -I../../../../../../../../Utilities/misc -I../../../../../../../../Utilities/timer -I../../../../../../../../Utilities/trace/adv_trace -I../../../../../../../../Utilities/lpm/tiny_lpm -I../../../../../../../../Utilities/sequencer -I../../../../../../../../Drivers/BSP/B-L072Z-LRWAN1 -I../../../../../../../../Drivers/BSP/CMWX1ZZABZ_0xx -I../../../../../../../../Drivers/STM32L0xx_HAL_Driver/Inc -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Middlewares/Third_Party/SubGHz_Phy -I../../../../../../../../Middlewares/Third_Party/SubGHz_Phy/sx1276 -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_app/Inc" -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_change/Inc" -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_device/Inc" -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_generate/Inc" -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_util/Inc" -Os -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Usercode/user_util/Src/user_lpm.o: C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_util/Src/user_lpm.c Usercode/user_util/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DSTM32L072xx -DCMWX1ZZABZ0XX -DDEVICE_TYPE_STATION -c -I../../../SubGHz_Phy/App -I../../../SubGHz_Phy/Target -I../../../Core/Inc -I../../../../../../../../Utilities/misc -I../../../../../../../../Utilities/timer -I../../../../../../../../Utilities/trace/adv_trace -I../../../../../../../../Utilities/lpm/tiny_lpm -I../../../../../../../../Utilities/sequencer -I../../../../../../../../Drivers/BSP/B-L072Z-LRWAN1 -I../../../../../../../../Drivers/BSP/CMWX1ZZABZ_0xx -I../../../../../../../../Drivers/STM32L0xx_HAL_Driver/Inc -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Middlewares/Third_Party/SubGHz_Phy -I../../../../../../../../Middlewares/Third_Party/SubGHz_Phy/sx1276 -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_app/Inc" -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_change/Inc" -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_device/Inc" -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_generate/Inc" -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_util/Inc" -Os -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Usercode/user_util/Src/user_rtc.o: C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_util/Src/user_rtc.c Usercode/user_util/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DSTM32L072xx -DCMWX1ZZABZ0XX -DDEVICE_TYPE_STATION -c -I../../../SubGHz_Phy/App -I../../../SubGHz_Phy/Target -I../../../Core/Inc -I../../../../../../../../Utilities/misc -I../../../../../../../../Utilities/timer -I../../../../../../../../Utilities/trace/adv_trace -I../../../../../../../../Utilities/lpm/tiny_lpm -I../../../../../../../../Utilities/sequencer -I../../../../../../../../Drivers/BSP/B-L072Z-LRWAN1 -I../../../../../../../../Drivers/BSP/CMWX1ZZABZ_0xx -I../../../../../../../../Drivers/STM32L0xx_HAL_Driver/Inc -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Middlewares/Third_Party/SubGHz_Phy -I../../../../../../../../Middlewares/Third_Party/SubGHz_Phy/sx1276 -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_app/Inc" -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_change/Inc" -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_device/Inc" -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_generate/Inc" -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_util/Inc" -Os -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Usercode/user_util/Src/user_string.o: C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_util/Src/user_string.c Usercode/user_util/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DSTM32L072xx -DCMWX1ZZABZ0XX -DDEVICE_TYPE_STATION -c -I../../../SubGHz_Phy/App -I../../../SubGHz_Phy/Target -I../../../Core/Inc -I../../../../../../../../Utilities/misc -I../../../../../../../../Utilities/timer -I../../../../../../../../Utilities/trace/adv_trace -I../../../../../../../../Utilities/lpm/tiny_lpm -I../../../../../../../../Utilities/sequencer -I../../../../../../../../Drivers/BSP/B-L072Z-LRWAN1 -I../../../../../../../../Drivers/BSP/CMWX1ZZABZ_0xx -I../../../../../../../../Drivers/STM32L0xx_HAL_Driver/Inc -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Middlewares/Third_Party/SubGHz_Phy -I../../../../../../../../Middlewares/Third_Party/SubGHz_Phy/sx1276 -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_app/Inc" -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_change/Inc" -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_device/Inc" -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_generate/Inc" -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_util/Inc" -Os -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Usercode/user_util/Src/user_time.o: C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_util/Src/user_time.c Usercode/user_util/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DSTM32L072xx -DCMWX1ZZABZ0XX -DDEVICE_TYPE_STATION -c -I../../../SubGHz_Phy/App -I../../../SubGHz_Phy/Target -I../../../Core/Inc -I../../../../../../../../Utilities/misc -I../../../../../../../../Utilities/timer -I../../../../../../../../Utilities/trace/adv_trace -I../../../../../../../../Utilities/lpm/tiny_lpm -I../../../../../../../../Utilities/sequencer -I../../../../../../../../Drivers/BSP/B-L072Z-LRWAN1 -I../../../../../../../../Drivers/BSP/CMWX1ZZABZ_0xx -I../../../../../../../../Drivers/STM32L0xx_HAL_Driver/Inc -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Middlewares/Third_Party/SubGHz_Phy -I../../../../../../../../Middlewares/Third_Party/SubGHz_Phy/sx1276 -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_app/Inc" -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_change/Inc" -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_device/Inc" -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_generate/Inc" -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_util/Inc" -Os -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Usercode/user_util/Src/user_timer.o: C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_util/Src/user_timer.c Usercode/user_util/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DSTM32L072xx -DCMWX1ZZABZ0XX -DDEVICE_TYPE_STATION -c -I../../../SubGHz_Phy/App -I../../../SubGHz_Phy/Target -I../../../Core/Inc -I../../../../../../../../Utilities/misc -I../../../../../../../../Utilities/timer -I../../../../../../../../Utilities/trace/adv_trace -I../../../../../../../../Utilities/lpm/tiny_lpm -I../../../../../../../../Utilities/sequencer -I../../../../../../../../Drivers/BSP/B-L072Z-LRWAN1 -I../../../../../../../../Drivers/BSP/CMWX1ZZABZ_0xx -I../../../../../../../../Drivers/STM32L0xx_HAL_Driver/Inc -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Middlewares/Third_Party/SubGHz_Phy -I../../../../../../../../Middlewares/Third_Party/SubGHz_Phy/sx1276 -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_app/Inc" -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_change/Inc" -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_device/Inc" -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_generate/Inc" -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_util/Inc" -Os -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Usercode/user_util/Src/user_util.o: C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_util/Src/user_util.c Usercode/user_util/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DSTM32L072xx -DCMWX1ZZABZ0XX -DDEVICE_TYPE_STATION -c -I../../../SubGHz_Phy/App -I../../../SubGHz_Phy/Target -I../../../Core/Inc -I../../../../../../../../Utilities/misc -I../../../../../../../../Utilities/timer -I../../../../../../../../Utilities/trace/adv_trace -I../../../../../../../../Utilities/lpm/tiny_lpm -I../../../../../../../../Utilities/sequencer -I../../../../../../../../Drivers/BSP/B-L072Z-LRWAN1 -I../../../../../../../../Drivers/BSP/CMWX1ZZABZ_0xx -I../../../../../../../../Drivers/STM32L0xx_HAL_Driver/Inc -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Middlewares/Third_Party/SubGHz_Phy -I../../../../../../../../Middlewares/Third_Party/SubGHz_Phy/sx1276 -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_app/Inc" -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_change/Inc" -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_device/Inc" -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_generate/Inc" -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_util/Inc" -Os -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Usercode-2f-user_util-2f-Src

clean-Usercode-2f-user_util-2f-Src:
	-$(RM) ./Usercode/user_util/Src/user_event_drive.cyclo ./Usercode/user_util/Src/user_event_drive.d ./Usercode/user_util/Src/user_event_drive.o ./Usercode/user_util/Src/user_event_drive.su ./Usercode/user_util/Src/user_flash.cyclo ./Usercode/user_util/Src/user_flash.d ./Usercode/user_util/Src/user_flash.o ./Usercode/user_util/Src/user_flash.su ./Usercode/user_util/Src/user_lpm.cyclo ./Usercode/user_util/Src/user_lpm.d ./Usercode/user_util/Src/user_lpm.o ./Usercode/user_util/Src/user_lpm.su ./Usercode/user_util/Src/user_rtc.cyclo ./Usercode/user_util/Src/user_rtc.d ./Usercode/user_util/Src/user_rtc.o ./Usercode/user_util/Src/user_rtc.su ./Usercode/user_util/Src/user_string.cyclo ./Usercode/user_util/Src/user_string.d ./Usercode/user_util/Src/user_string.o ./Usercode/user_util/Src/user_string.su ./Usercode/user_util/Src/user_time.cyclo ./Usercode/user_util/Src/user_time.d ./Usercode/user_util/Src/user_time.o ./Usercode/user_util/Src/user_time.su ./Usercode/user_util/Src/user_timer.cyclo ./Usercode/user_util/Src/user_timer.d ./Usercode/user_util/Src/user_timer.o ./Usercode/user_util/Src/user_timer.su ./Usercode/user_util/Src/user_util.cyclo ./Usercode/user_util/Src/user_util.d ./Usercode/user_util/Src/user_util.o ./Usercode/user_util/Src/user_util.su

.PHONY: clean-Usercode-2f-user_util-2f-Src

