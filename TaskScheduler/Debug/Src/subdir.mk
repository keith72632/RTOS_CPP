################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/syscalls.c \
../Src/sysmem.c 

CPP_SRCS += \
../Src/faults.cpp \
../Src/led.cpp \
../Src/main.cpp \
../Src/stack.cpp \
../Src/systick.cpp \
../Src/tasks.cpp \
../Src/timers.cpp \
../Src/usart.cpp 

C_DEPS += \
./Src/syscalls.d \
./Src/sysmem.d 

OBJS += \
./Src/faults.o \
./Src/led.o \
./Src/main.o \
./Src/stack.o \
./Src/syscalls.o \
./Src/sysmem.o \
./Src/systick.o \
./Src/tasks.o \
./Src/timers.o \
./Src/usart.o 

CPP_DEPS += \
./Src/faults.d \
./Src/led.d \
./Src/main.d \
./Src/stack.d \
./Src/systick.d \
./Src/tasks.d \
./Src/timers.d \
./Src/usart.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.cpp Src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F407VGTx -c -I../Inc -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/%.o: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F407VGTx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/faults.d ./Src/faults.o ./Src/led.d ./Src/led.o ./Src/main.d ./Src/main.o ./Src/stack.d ./Src/stack.o ./Src/syscalls.d ./Src/syscalls.o ./Src/sysmem.d ./Src/sysmem.o ./Src/systick.d ./Src/systick.o ./Src/tasks.d ./Src/tasks.o ./Src/timers.d ./Src/timers.o ./Src/usart.d ./Src/usart.o

.PHONY: clean-Src

