################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../jni/BBB_I2C.cpp \
../jni/I2C.cpp 

OBJS += \
./jni/BBB_I2C.o \
./jni/I2C.o 

CPP_DEPS += \
./jni/BBB_I2C.d \
./jni/I2C.d 


# Each subdirectory must supply rules for building sources it contributes
jni/%.o: ../jni/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/Users/cagdas/Dropbox/Workspace/BBBProjects/BeagleBoneBlack-I2C" -I/usr/local/arm/arm-none-linux-gnueabi/arm-none-linux-gnueabi/sysroot/usr/include -I/usr/local/arm/arm-none-linux-gnueabi -I/Library/Java/JavaVirtualMachines/jdk1.7.0_65.jdk/Contents/Home/include -I/Library/Java/JavaVirtualMachines/jdk1.7.0_65.jdk/Contents/Home/include/darwin -I/usr/local/arm/arm-none-linux-gnueabi/arm-none-linux-gnueabi -O0 -g3 -Wall -c -fmessage-length=0 -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


