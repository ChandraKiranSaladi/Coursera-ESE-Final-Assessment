#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# Simple Make file which supports Host (Linux) and Cross platform: ARM
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#	   <FILE>.o - Builds <FILE>.o object file
#	   <FILE>.i - Generate the preprocessed output of the <FILE>.i
#      <FILE>.asm - Generate assembly output of <FILE>.asm	
#	      
#      compile-all : Compiles all files, doesn't build
#	   build: Compile all object files and link into a final executable
#	   clean: removes all generated files.
# Platform Overrides:
#      CPU -  ARM Cortex Architecture(cortex-m4) 
#	   ARCH - ARM Architecture (thumb)
#	   SPECS - Specs file to give the linker (nosys.specs)
#
#------------------------------------------------------------------------------
include sources.mk

ifeq ($(PLATFORM),MSP432)
		CC = arm-none-eabi-gcc
		LD = arm-none-eabi-ld
		LINKER_FILE = msp432p401r.lds
		LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)

		# Architectures Specific Flags ARM
		CPU = cortex-m4
		ARCH = thumb
		SPECS = nosys.specs
		FPU = fpv4-sp-d16
		ARMFLAGS = -mcpu=$(CPU) -m$(ARCH) --specs=$(SPECS) -march=armv7e-m -mfloat-abi=hard -mfpu=$(FPU)		
		OBJDUMP = arm-none-eabi-objdump

		#Size Utility
		SIZE = arm-none-eabi-size 
else
		CC = gcc
		LD = ld
		#Size Utility
		SIZE = size
		LDFLAGS = -Wl,-Map=$(TARGET).map
		OBJDUMP = objdump
endif

#Verbose Flag enabled in Cmd, prints debug information

VPATH = ./src
 
ifeq ($(VERBOSE),VERBOSE)
		VER = -g
endif



# Compiler Flags and Defines
	#-D$(PLATFORM) is put inside the CFLAGS. 

TARGET = final

CFLAGS = -Wall -Werror $(VER) -O0 -std=c99 $(INCLUDEHEADER) -D$(PLATFORM) $(ARMFLAGS) -D$(VERBOSE) -D$(COURSE1)

CPPFLAGS = -E
MAIN = main

OBJS = $(SOURCES:.c=.o)

PREPRO = $(SOURCES:.c=.i)

ASMS = $(SOURCES:.c=.asm)

DEPS = $(SOURCES:.c=.d)

FILES = *.asm *.i *.o *.d

%.o : %.c
	$(CC) -c $< $(CFLAGS) -o $@

#%.i : %.c
#	$(CC) $(INCLUDES) $(CPPFLAGS) $< $(CFLAGS) -o $@

#%.asm : %.c
#	$(CC) $(INCLUDES) -S $< $(CFLAGS) -o $@

#$(TARGET).asm : $(TARGET).out
#	$(OBJDUMP) -d $(TARGET).out >> $@

#%.d : %.c
#	$(CC) $(INCLUDES) -M $< $(CFLAGS) -o $@

.PHONY: compile-all
compile-all: $(OBJS)
	$(CC) $(INCLUDES) $(OBJS) -c $(CFLAGS) -o $(TARGET).o


# $ make build PLATFORM=HOST, $ make build PLATFORM=MSP432, builds and generates all the files necessary.
.PHONY: build
build: $(TARGET).out  #$(TARGET).asm


$(TARGET).out: $(OBJS) #$(DEPS) 
	$(CC) $(CFLAGS) $(INCLUDES) $(LDFLAGS) -o $@ $(OBJS)
#	$(SIZE) -Atd $(TARGET).out
#	$(SIZE) $(TARGET).out

#$ make clean,  cleans all the generated files.
.PHONY: clean
clean:
	rm -f $(TARGET).asm $(FILES) $(TARGET).out $(TARGET).map $(PREPRO) $(ASMS) $(DEPS) $(OBJS)

