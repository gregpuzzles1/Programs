DIR_Config   = ./lib/Config
DIR_LCD      = ./lib/LCD1602
DIR_Examples = ./examples
DIR_BIN      = ./bin

OBJ_C = $(wildcard ${DIR_LCD}/*.c ${DIR_Config}/*.c ${DIR_Examples}/*.c)
OBJ_O = $(patsubst %.c,${DIR_BIN}/%.o,$(notdir ${OBJ_C}))

TARGET = main

USELIB = USE_WIRINGPI_LIB
# USELIB = USE_DEV_LIB

DEBUG = -D $(USELIB)
ifeq ($(USELIB), USE_WIRINGPI_LIB)
    LIB = -lwiringPi -lm 
else ifeq ($(USELIB), USE_DEV_LIB)
    LIB = -llgpio -lm 
endif


CC = gcc
MSG = -g -O0 -Wall
CFLAGS += $(MSG) $(DEBUG)

${TARGET}:${OBJ_O}
	$(CC) $(CFLAGS) $(OBJ_O) -o $@ $(LIB)
    
${DIR_BIN}/%.o:$(DIR_Examples)/%.c
	$(CC) $(CFLAGS) -c  $< -o $@ -I $(DIR_Config) -I $(DIR_LCD)
    
${DIR_BIN}/%.o:$(DIR_LCD)/%.c
	$(CC) $(CFLAGS) -c  $< -o $@ -I $(DIR_Config)

${DIR_BIN}/%.o:$(DIR_Config)/%.c
	$(CC) $(CFLAGS) -c  $< -o $@ $(LIB)
	
clean :
	rm $(DIR_BIN)/*.* 
	rm $(TARGET) 
