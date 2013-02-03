################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Block.cpp \
../src/Bullet.cpp \
../src/Camera.cpp \
../src/CheckPointBlock.cpp \
../src/Config.cpp \
../src/Enemy.cpp \
../src/GameObject.cpp \
../src/Hero.cpp \
../src/Koopa.cpp \
../src/Main.cpp \
../src/Map.cpp \
../src/Mario.cpp \
../src/MovableObject.cpp \
../src/PhisicalObject.cpp \
../src/Physics.cpp \
../src/Sound.cpp \
../src/Stage.cpp \
../src/StaticEnemy.cpp \
../src/StaticObject.cpp \
../src/Timer.cpp \
../src/VisibleObject.cpp 

OBJS += \
./src/Block.o \
./src/Bullet.o \
./src/Camera.o \
./src/CheckPointBlock.o \
./src/Config.o \
./src/Enemy.o \
./src/GameObject.o \
./src/Hero.o \
./src/Koopa.o \
./src/Main.o \
./src/Map.o \
./src/Mario.o \
./src/MovableObject.o \
./src/PhisicalObject.o \
./src/Physics.o \
./src/Sound.o \
./src/Stage.o \
./src/StaticEnemy.o \
./src/StaticObject.o \
./src/Timer.o \
./src/VisibleObject.o 

CPP_DEPS += \
./src/Block.d \
./src/Bullet.d \
./src/Camera.d \
./src/CheckPointBlock.d \
./src/Config.d \
./src/Enemy.d \
./src/GameObject.d \
./src/Hero.d \
./src/Koopa.d \
./src/Main.d \
./src/Map.d \
./src/Mario.d \
./src/MovableObject.d \
./src/PhisicalObject.d \
./src/Physics.d \
./src/Sound.d \
./src/Stage.d \
./src/StaticEnemy.d \
./src/StaticObject.d \
./src/Timer.d \
./src/VisibleObject.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++0x -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


