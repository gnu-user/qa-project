################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/AddCredit.cpp \
../src/AvailableTickets.cpp \
../src/Buy.cpp \
../src/Create.cpp \
../src/CurrentUserAccounts.cpp \
../src/DailyTransaction.cpp \
../src/Delete.cpp \
../src/Exception.cpp \
../src/FrontEnd.cpp \
../src/Login.cpp \
../src/Logout.cpp \
../src/Refund.cpp \
../src/Sell.cpp \
../src/Ticket.cpp \
../src/Transaction.cpp \
../src/User.cpp \
../src/Validate.cpp 

OBJS += \
./src/AddCredit.o \
./src/AvailableTickets.o \
./src/Buy.o \
./src/Create.o \
./src/CurrentUserAccounts.o \
./src/DailyTransaction.o \
./src/Delete.o \
./src/Exception.o \
./src/FrontEnd.o \
./src/Login.o \
./src/Logout.o \
./src/Refund.o \
./src/Sell.o \
./src/Ticket.o \
./src/Transaction.o \
./src/User.o \
./src/Validate.o 

CPP_DEPS += \
./src/AddCredit.d \
./src/AvailableTickets.d \
./src/Buy.d \
./src/Create.d \
./src/CurrentUserAccounts.d \
./src/DailyTransaction.d \
./src/Delete.d \
./src/Exception.d \
./src/FrontEnd.d \
./src/Login.d \
./src/Logout.d \
./src/Refund.d \
./src/Sell.d \
./src/Ticket.d \
./src/Transaction.d \
./src/User.d \
./src/Validate.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"../lib/include" -O0 -g3 -pedantic -Wall -Wextra -c -fmessage-length=0 -std=c++0x -v -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


