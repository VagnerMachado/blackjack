################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Blackjack.cpp \
../src/Card.cpp \
../src/Deck.cpp \
../src/Driver.cpp \
../src/Hand.cpp \
../src/LinkedList.cpp \
../src/Node.cpp \
../src/Player.cpp 

OBJS += \
./src/Blackjack.o \
./src/Card.o \
./src/Deck.o \
./src/Driver.o \
./src/Hand.o \
./src/LinkedList.o \
./src/Node.o \
./src/Player.o 

CPP_DEPS += \
./src/Blackjack.d \
./src/Card.d \
./src/Deck.d \
./src/Driver.d \
./src/Hand.d \
./src/LinkedList.d \
./src/Node.d \
./src/Player.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


