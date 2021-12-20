################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Employee.cpp \
../src/Example1.cpp \
../src/Example2.cpp \
../src/Skill.cpp \
../src/SkillAssociation.cpp \
../src/SkillManager.cpp \
../src/main.cpp 

OBJS += \
./src/Employee.o \
./src/Example1.o \
./src/Example2.o \
./src/Skill.o \
./src/SkillAssociation.o \
./src/SkillManager.o \
./src/main.o 

CPP_DEPS += \
./src/Employee.d \
./src/Example1.d \
./src/Example2.d \
./src/Skill.d \
./src/SkillAssociation.d \
./src/SkillManager.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


