#Makefile for a medium-sized project.

#Basic DevkitARM rules.

.SUFFIXES:

ifeq ($(strip $(DEVKITARM)),)
$(error "Please set DEVKITARM in your environment. export DEVKITARM=<path to>devkitARM)
endif

include $(DEVKITARM)/gba_rules

#Options.

TARGET = Mode5Demo
SRC_BASE = src
include_no_format = include ../../libinclude
INCLUDE = $(include_no_format:%=-I%)
BUILD = build
START = main
SPECS = gba

#Functions.

rwildcard = $(shell find $1 -name "$2")

#Source files and builded files.

CSRC = $(call rwildcard,$(SRC_BASE)/,*.c)
CXXSRC = $(call rwildcard, $(SRC_BASE)/,*.cpp)
ASSRC = $(call rwildcard,$(SRC_BASE)/,*.s)

COBJS = $(CSRC:$(SRC_BASE)/%.c=$(BUILD)/%.c.o)
CXXOBJS = $(CXXSRC:$(SRC_BASE)/%.cpp=$(BUILD)/%.cpp.o)
ASOBJS = $(ASSRC:$(SRC_BASE)/%.s=$(BUILD)/%.s.o)
OBJS = $(CXXOBJS) $(COBJS) $(ASOBJS)

#Compiler.

platform = arm-none-eabi-
CC = $(platform)gcc
CXX = $(platform)g++
AS = $(platform)as
OBJCOPY = $(platform)objcopy
ifeq ($(strip $(CXXSRC)),)
LD = $(platform)gcc
else
LD = $(platform)g++
endif

#Compiler options.

ARCH = -mthumb -mthumb-interwork
CFLAGS := -g -Wall -O2 -mcpu=arm7tdmi -mtune=arm7tdmi -fomit-frame-pointer -ffast-math $(ARCH)
CFLAGS  += $(INCLUDE)
CXXFLAGS := $(CFLAGS) -fno-rtti -fno-exceptions
ASFLAGS := -g $(ARCH)
LDFLAGS = -g $(ARCH) -Wl,-Map,$(TARGET).map --entry $(START) -specs=$(SPECS).specs -lAPIagb -L../.. -L.

#Building rules.

all : $(TARGET).gba

$(TARGET).gba : $(BUILD)/$(TARGET).elf
	@$(OBJCOPY) -v -O binary $(BUILD)/$(TARGET).elf $(TARGET).gba
	@echo GBA ROM $@ copied and cleaned from $^.
	@gbafix $(TARGET).gba
	@echo Header fixed. You are good to go!

$(BUILD)/$(TARGET).elf : $(OBJS)
	@$(LD) $(OBJS) $(LDFLAGS) -o $(BUILD)/$(TARGET).elf
	@echo $@ linked from $^.

$(OBJS) : $(BUILD)/%.c.o : $(SRC_BASE)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo C object $@ compiled from $<.

$(CXXOBJS) : $(BUILD)/%.cpp.o : $(SRC_BASE)/%.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo C++ object $@ compiled from $<.

$(ASOBJS) : $(BUILD)/%.s.o : $(SRC_BASE)/%.s
	@$(AS) $(ASFLAGS) $< -o $@
	@echo ASM object $@ compiled from $<.

#Cleaning.

.PHONY : clean
clean :
	@rm -f $(OBJS)
	@rm -f *.gba
	@rm -f $(BUILD)/*.elf
	@rm -f *.map
	@echo Cleaned.
