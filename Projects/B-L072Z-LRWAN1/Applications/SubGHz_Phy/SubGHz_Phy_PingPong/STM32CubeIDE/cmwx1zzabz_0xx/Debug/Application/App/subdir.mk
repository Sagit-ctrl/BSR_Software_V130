################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/MDBK/Desktop/BSR_Software_V130/Projects/B-L072Z-LRWAN1/Applications/SubGHz_Phy/SubGHz_Phy_PingPong/SubGHz_Phy/App/app_subghz_phy.c \
C:/Users/MDBK/Desktop/BSR_Software_V130/Projects/B-L072Z-LRWAN1/Applications/SubGHz_Phy/SubGHz_Phy_PingPong/SubGHz_Phy/App/subghz_phy_app.c 

OBJS += \
./Application/App/app_subghz_phy.o \
./Application/App/subghz_phy_app.o 

C_DEPS += \
./Application/App/app_subghz_phy.d \
./Application/App/subghz_phy_app.d 


# Each subdirectory must supply rules for building sources it contributes
Application/App/app_subghz_phy.o: C:/Users/MDBK/Desktop/BSR_Software_V130/Projects/B-L072Z-LRWAN1/Applications/SubGHz_Phy/SubGHz_Phy_PingPong/SubGHz_Phy/App/app_subghz_phy.c Application/App/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DSTM32L072xx -DCMWX1ZZABZ0XX -c -I../../../SubGHz_Phy/App -I../../../SubGHz_Phy/Target -I../../../Core/Inc -I../../../../../../../../Utilities/misc -I../../../../../../../../Utilities/timer -I../../../../../../../../Utilities/trace/adv_trace -I../../../../../../../../Utilities/lpm/tiny_lpm -I../../../../../../../../Utilities/sequencer -I../../../../../../../../Drivers/BSP/B-L072Z-LRWAN1 -I../../../../../../../../Drivers/BSP/CMWX1ZZABZ_0xx -I../../../../../../../../Drivers/STM32L0xx_HAL_Driver/Inc -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Middlewares/Third_Party/SubGHz_Phy -I../../../../../../../../Middlewares/Third_Party/SubGHz_Phy/sx1276 -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_app/Inc" -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_change/Inc" -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_device/Inc" -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_generate/Inc" -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_util/Inc" -Os -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Application/App/subghz_phy_app.o: C:/Users/MDBK/Desktop/BSR_Software_V130/Projects/B-L072Z-LRWAN1/Applications/SubGHz_Phy/SubGHz_Phy_PingPong/SubGHz_Phy/App/subghz_phy_app.c Application/App/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DSTM32L072xx -DCMWX1ZZABZ0XX -c -I../../../SubGHz_Phy/App -I../../../SubGHz_Phy/Target -I../../../Core/Inc -I../../../../../../../../Utilities/misc -I../../../../../../../../Utilities/timer -I../../../../../../../../Utilities/trace/adv_trace -I../../../../../../../../Utilities/lpm/tiny_lpm -I../../../../../../../../Utilities/sequencer -I../../../../../../../../Drivers/BSP/B-L072Z-LRWAN1 -I../../../../../../../../Drivers/BSP/CMWX1ZZABZ_0xx -I../../../../../../../../Drivers/STM32L0xx_HAL_Driver/Inc -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Middlewares/Third_Party/SubGHz_Phy -I../../../../../../../../Middlewares/Third_Party/SubGHz_Phy/sx1276 -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_app/Inc" -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_change/Inc" -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_device/Inc" -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_generate/Inc" -I"C:/Users/MDBK/Desktop/BSR_Software_V130/Usercode/user_util/Inc" -Os -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Application-2f-App

clean-Application-2f-App:
	-$(RM) ./Application/App/app_subghz_phy.cyclo ./Application/App/app_subghz_phy.d ./Application/App/app_subghz_phy.o ./Application/App/app_subghz_phy.su ./Application/App/subghz_phy_app.cyclo ./Application/App/subghz_phy_app.d ./Application/App/subghz_phy_app.o ./Application/App/subghz_phy_app.su

.PHONY: clean-Application-2f-App

