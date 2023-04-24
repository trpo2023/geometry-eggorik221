APP_NAME = geometry
LIB_NAME =libgeometry

CC = gcc
CFLAGS = -Wall -Werror -I src
DEPSFLAG = -MMD

OBJ_DIR = obj
SRC_DIR = src
BIN_DIR = bin

PATH = $(BIN_DIR)/$(APP_NAME)
LIB_PATH = $(OBJ_DIR)/$(SRC_DIR)/$(LIB_NAME)/$(LIB_NAME).a

APP_SOURCE = $(wildcard $(SRC_DIR)/$(APP_NAME)/*.c)
APP_OBJ = $(patsubst %.c, $(OBJ_DIR)/%.o, $(APP_SOURCE))

LIB_SOURCE = $(wildcard $(SRC_DIR)/$(LIB_NAME)/*.c)
LIB_OBJ = $(patsubst %.c, $(OBJ_DIR)/%.o, $(LIB_SOURCE))

LIB_DEPS = $(patsubst %.o, $(OBJ_DIR)%.d, $(LIB_OBJ))
APP_DEPS = $(patsubst %.o, $(OBJ_DIR)%.d, $(APP_OBJ))

.PHONY: all clean
all: $(PATH)

-include $(LIB_DEPS) $(APP_DEPS)

$(PATH): $(APP_OBJ) $(LIB_PATH)
	$(CC) $(CFLAGS) -o $@ $^

$(LIB_PATH): $(LIB_OBJ)
	$(AR) rcs $@ $^

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) $(DEPSFLAG) -c -o $@ $<

clean:
	rm -f $(PATH) $(OBJ_DIR)/$(SRC_DIR)/*/*.[ado]

run:
	$(PATH) 