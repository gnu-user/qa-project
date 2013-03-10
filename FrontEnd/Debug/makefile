################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# Architecture specific build settings
UNAME := $(shell uname)
ARCH := $(shell getconf LONG_BIT)
LINK_PATH_32 := i686
LINK_PATH_64 := x86_64

# Set the build and linker specific settings
ifeq ($(UNAME),Linux)
BUILD_MSG := 'Invoking: GCC C++ Compiler'
LINK_MSG := 'Invoking: GCC C++ Linker'
BUILD_COMMAND := g++ -I"../lib/include" -O0 -g3 -pedantic -Wall -Wextra -c -fmessage-length=0 -std=c++0x
LINK_COMMAND := g++ -L"../lib/static/$(UNAME)/$(LINK_PATH_$(ARCH))" -static
endif
ifeq ($(UNAME),Darwin)
BUILD_MSG := 'Invoking: Clang C++ Compiler'
LINK_MSG := 'Invoking: Clang C++ Linker'
BUILD_COMMAND := clang++ -I"../lib/include" -O0 -g3 -pedantic -Wall -Wextra -c -fmessage-length=0 -U__STRICT_ANSI__ -std=c++0x -stdlib=libc++
LINK_COMMAND := clang++ -L"../lib/shared/$(UNAME)/$(LINK_PATH_$(ARCH))" -stdlib=libc++
endif

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
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
all: FrontEnd

# Tool invocations
FrontEnd: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo $(LINK_MSG)
	$(LINK_COMMAND) -o "FrontEnd" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C++_DEPS)$(C_DEPS)$(CC_DEPS)$(CPP_DEPS)$(EXECUTABLES)$(CXX_DEPS)$(C_UPPER_DEPS) FrontEnd
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
