################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Sagit/Desktop/BSR_Software_V130/Projects/B-L072Z-LRWAN1/Applications/SubGHz_Phy/SubGHz_Phy_PingPong/SubGHz_Phy/Target/b_l072z_lrwan1_bus.c 

OBJS += \
./Application/Target/b_l072z_lrwan1_bus.o 

C_DEPS += \
./Application/Target/b_l072z_lrwan1_bus.d 


# Each subdirectory must supply rules for building sources it contributes
Application/Target/b_l072z_lrwan1_bus.o: C:/Users/Sagit/Desktop/BSR_Software_V130/Projects/B-L072Z-LRWAN1/Applications/SubGHz_Phy/SubGHz_Phy_PingPong/SubGHz_Phy/Target/b_l072z_lrwan1_bus.c Application/Target/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DSTM32L072xx -DCMWX1ZZABZ0XX -c -I../../../SubGHz_Phy/App -I../../../SubGHz_Phy/Target -I../../../Core/Inc -I../../../../../../../../Utilities/misc -I../../../../../../../../Utilities/timer -I../../../../../../../../Utilities/trace/adv_trace -I../../../../../../../../Utilities/lpm/tiny_lpm -I../../../../../../../../Utilities/sequencer -I../../../../../../../../Drivers/BSP/B-L072Z-LRWAN1 -I../../../../../../../../Drivers/BSP/CMWX1ZZABZ_0xx -I../../../../../../../../Drivers/STM32L0xx_HAL_Driver/Inc -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Middlewares/Third_Party/SubGHz_Phy -I../../../../../../../../Middlewares/Third_Party/SubGHz_Phy/sx1276 -I"C:/Users/Sagit/Desktop/BSR_Software_V130/Usercode/user_app/Inc" -I"C:/Users/Sagit/Desktop/BSR_Software_V130/Usercode/user_change/Inc" -I"C:/Users/Sagit/Desktop/BSR_Software_V130/Usercode/user_device/Inc" -I"C:/Users/Sagit/Desktop/BSR_Software_V130/Usercode/user_generate/Inc" -I"C:/Users/Sagit/Desktop/BSR_Software_V130/Usercode/user_util/Inc" -Os -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Application-2f-Target

clean-Application-2f-Target:
	-$(RM) ./Application/Target/b_l072z_lrwan1_bus.cyclo ./Application/Target/b_l072z_lrwan1_bus.d ./Application/Target/b_l072z_lrwan1_bus.o ./Application/Target/b_l072z_lrwan1_bus.su

.PHONY: clean-Application-2f-Target

