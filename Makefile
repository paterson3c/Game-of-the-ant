TARGET = juego
CFLAGS = -Wall -pedantic -I$(INC_DIR)
EXE = $(TARGET) enemy_test set_test space_test inventory_test link_test
CC = gcc

INC_DIR = inc
SRC_DIR = src
OBJ_DIR = obj
LIB_DIR = lib
DOC_DIR = doc

OBJS = $(OBJ_DIR)/game.o \
       $(OBJ_DIR)/graphic_engine.o \
	   $(OBJ_DIR)/command.o \
	   $(OBJ_DIR)/game_loop.o \
	   $(OBJ_DIR)/game_reader.o \
	   $(OBJ_DIR)/space.o \
	   $(OBJ_DIR)/object.o \
	   $(OBJ_DIR)/player.o \
	   $(OBJ_DIR)/enemy.o \
	   $(OBJ_DIR)/set.o \
	   $(OBJ_DIR)/inventory.o \
	   $(OBJ_DIR)/buff_debuff.o \
	   $(OBJ_DIR)/xp.o \
	   $(OBJ_DIR)/link.o \
	   $(OBJ_DIR)/main_test.o \



.PHONY: run runv clean clear test doc

all: $(EXE) $(DOC_DIR)/d_config-tmp
	doxygen $(DOC_DIR)/d_config-tmp

$(TARGET): $(OBJS) $(LIB_DIR)/libscreen.a
	$(CC) -o $@ $^

space_test: $(OBJ_DIR)/space_test.o $(OBJ_DIR)/space.o $(OBJ_DIR)/set.o
	$(CC) -o space_test $(OBJ_DIR)/space_test.o $(OBJ_DIR)/space.o $(OBJ_DIR)/set.o $(LIB_DIR)/libscreen.a

set_test: $(OBJ_DIR)/set_test.o $(OBJ_DIR)/set.o
	$(CC) -o set_test $(OBJ_DIR)/set_test.o $(OBJ_DIR)/set.o $(LIB_DIR)/libscreen.a

link_test: $(OBJ_DIR)/link_test.o $(OBJ_DIR)/link.o
	$(CC) -o link_test $(OBJ_DIR)/link_test.o $(OBJ_DIR)/link.o $(LIB_DIR)/libscreen.a

enemy_test: $(OBJ_DIR)/enemy_test.o $(OBJ_DIR)/enemy.o
	$(CC) -o enemy_test $(OBJ_DIR)/enemy_test.o $(OBJ_DIR)/enemy.o $(LIB_DIR)/libscreen.a

inventory_test: $(OBJ_DIR)/inventory_test.o $(OBJ_DIR)/inventory.o 
	$(CC) -o inventory_test $(OBJ_DIR)/inventory_test.o $(OBJ_DIR)/inventory.o $(OBJ_DIR)/set.o $(LIB_DIR)/libscreen.a

buff_debuff_test: $(OBJ_DIR)/buff_debuff_test.o $(OBJ_DIR)/buff_debuff.o 
	$(CC) -o buff_debuff_test $(OBJ_DIR)/buff_debuff_test.o $(OBJ_DIR)/buff_debuff.o $(LIB_DIR)/libscreen.a

xp_test: $(OBJ_DIR)/xp_test.o $(OBJ_DIR)/xp.o
	$(CC) -o xp_test $(OBJ_DIR)/xp_test.o $(OBJ_DIR)/xp.o $(LIB_DIR)/libscreen.a

$(DOC_DIR)/Doxyfile:
	doxygen -g $@

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c $(INC_DIR)/%.h
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

clean: 
	rm -f -r $(OBJ_DIR) $(DOC_DIR)/html $(DOC_DIR)/latex $(EXE) game.log 

run:
	./juego anthill_new2.dat

runv:
	valgrind --leak-check=full --track-origins=yes ./juego anthill_new2.dat