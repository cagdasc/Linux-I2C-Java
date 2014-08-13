################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include jni/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: libI2CJava.so

dependents:
	-cd /Users/cagdas/Dropbox/Workspace/BBBProjects/BeagleBoneBlack-I2C/Debug && $(MAKE) all

# Tool invocations
libI2CJava.so: $(OBJS) $(USER_OBJS) /Users/cagdas/Dropbox/Workspace/BBBProjects/BeagleBoneBlack-I2C/Debug/libBeagleBoneBlack-I2C.a
	@echo 'Building target: $@'
	@echo 'Invoking: Cross G++ Linker'
	g++ -L"/Users/cagdas/Dropbox/Workspace/BBBProjects/BeagleBoneBlack-I2C/Debug" -shared -o "libI2CJava.so" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C++_DEPS)$(OBJS)$(C_DEPS)$(CC_DEPS)$(LIBRARIES)$(CPP_DEPS)$(CXX_DEPS)$(C_UPPER_DEPS) libI2CJava.so
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:
/Users/cagdas/Dropbox/Workspace/BBBProjects/BeagleBoneBlack-I2C/Debug/libBeagleBoneBlack-I2C.a:

-include ../makefile.targets
