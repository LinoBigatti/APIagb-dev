#Makefile for APIagb.

#Basic DevkitARM rules.

.SUFFIXES:

ifeq ($(strip $(DEVKITARM)),)
$(error "Please set DEVKITARM in your environment. export DEVKITARM=<path to>devkitARM)
endif

include $(DEVKITARM)/gba_rules

#Options.

include_no_format = libinclude
INCLUDE = $(include_no_format:%=-I%)

#Compiler.

platform = arm-none-eabi-
CC = $(platform)gcc
AS = $(platform)as
AR = $(platform)ar

#Compiler options.

ARM := -marm -mlong-calls
THUMB := -mthumb -mthumb-interwork
CFLAGS := -g -Wall -O2 -mcpu=arm7tdmi -mtune=arm7tdmi -fomit-frame-pointer -ffast-math $(THUMB)
CFLAGS  += $(INCLUDE)
ARMFLAGS := -g $(ARM)
THUMBFLAGS := -g $(THUMB)
ARFLAGS := -ruv

#Source files and builded files.

LIBCSRC = $(shell find libsrc/ -name "*.c")
LIBTHUMBSRC = $(shell find libsrc/ -name "*.thumb")
LIBARMSRC = $(shell find libsrc/ -name "*.arm")

LIBCOBJS = $(LIBCSRC:libsrc/%.c=libbuild/%.c.o)
LIBTHUMBOBJS = $(LIBTHUMBSRC:libsrc/%.thumb=libbuild/%.thumb.o)
LIBARMOBJS = $(LIBARMSRC:libsrc/%.arm=libbuild/%.arm.o)
LIBOBJS = $(LIBCOBJS) $(LIBTHUMBOBJS) $(LIBARMOBJS)

#Target rules.

all : err_no_target

lib : APIagb

Mode3ImageDemo :
	@cd demostrations/Mode3ImageDemo && $(MAKE)
	@echo $@ compiled and builded.

Mode3ImageDemo_clean :
	@cd demostrations/Mode3ImageDemo && $(MAKE) clean

Mode3Demo :
	@cd demostrations/Mode3Demo && $(MAKE)
	@echo $@ compiled and builded.

Mode3Demo_clean :
	@cd demostrations/Mode3Demo && $(MAKE) clean

Mode4ImageDemo :
	@cd demostrations/Mode4ImageDemo && $(MAKE)
	@echo $@ compiled and builded.

Mode4ImageDemo_clean :
	@cd demostrations/Mode4ImageDemo && $(MAKE) clean

Mode4Demo :
	@cd demostrations/Mode4Demo && $(MAKE)
	@echo $@ compiled and builded.

Mode4Demo_clean :
	@cd demostrations/Mode4Demo && $(MAKE) clean

Mode5ImageDemo :
	@cd demostrations/Mode5ImageDemo && $(MAKE)
	@echo $@ compiled and builded.

Mode5ImageDemo_clean :
	@cd demostrations/Mode5ImageDemo && $(MAKE) clean

Mode5Demo :
	@cd demostrations/Mode5Demo && $(MAKE)
	@echo $@ compiled and builded.

Mode5Demo_clean :
	@cd demostrations/Mode5Demo && $(MAKE) clean

InputDemo :
	@cd demostrations/InputDemo && $(MAKE)
	@echo $@ compiled and builded.

InputDemo_clean :
	@cd demostrations/InputDemo && $(MAKE) clean

SpriteDemo :
	@cd demostrations/SpriteDemo && $(MAKE)
	@echo $@ compiled and builded.

SpriteDemo_clean :
	@cd demostrations/SpriteDemo && $(MAKE) clean

BgDemo :
	@cd demostrations/BgDemo && $(MAKE)
	@echo $@ compiled and builded.

BgDemo_clean :
	@cd demostrations/BgDemo && $(MAKE) clean

ExtendedBgDemo :
	@cd demostrations/ExtendedBgDemo && $(MAKE)
	@echo $@ compiled and builded.

ExtendedBgDemo_clean :
	@cd demostrations/ExtendedBgDemo && $(MAKE) clean

#Build API.
APIagb : $(LIBCOBJS) $(LIBTHUMBOBJS) $(LIBARMOBJS)
	@$(AR) $(ARFLAGS) libAPIagb.a $^
	@echo "libAPIagb.a compiled and archived."

$(LIBCOBJS) : libbuild/%.c.o : libsrc/%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo C object $@ compiled from $<.

$(LIBTHUMBOBJS) : libbuild/%.thumb.o : libsrc/%.thumb
	@$(AS) $(THUMBFLAGS) $< -o $@
	@echo THUMB object $@ compiled from $<.

$(LIBARMOBJS) : libbuild/%.arm.o : libsrc/%.arm
	@$(AS) $(ARMFLAGS) $< -o $@
	@echo ARM object $@ compiled from $<.

#Cleaning.

.PHONY : clean
clean :
	@rm -f $(LIBOBJS)
	@rm -f libAPIagb.a
	@echo Cleaned.

#Errors.

err_no_target:
	@echo "APIagb: Error: No target specified. Please use \"make <target>\"."
	@echo "Supported targets:"
	@echo "APIagb: Build APIagb."
	@echo "lib: Build APIagb."
	@echo "Mode3ImageDemo: Build the image demo for Mode 3."
	@echo "Mode3Demo: Build the demo for Mode 3."
	@echo "Mode4ImageDemo: Build the image demo for Mode 4."
	@echo "Mode4Demo: Build the demo for Mode 4."
	@echo "Mode5ImageDemo: Build the image demo for Mode 5."
	@echo "Mode5Demo: Build the demo for Mode 5."
	@echo "InputDemo: Build the demo for the input handlers."
	@echo "SpriteDemo: Build the demo for the sprite handlers."
	@echo "BgDemo: Build the demo for the bg handlers."