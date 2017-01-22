################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../cpp-concurrency/asyncnet/asyncnet/test.cpp 

OBJS += \
./cpp-concurrency/asyncnet/asyncnet/test.o 

CPP_DEPS += \
./cpp-concurrency/asyncnet/asyncnet/test.d 


# Each subdirectory must supply rules for building sources it contributes
cpp-concurrency/asyncnet/asyncnet/%.o: ../cpp-concurrency/asyncnet/asyncnet/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


