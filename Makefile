CC=gcc
SRC=src
OBJ=obj
BIN=bin
MAINNAME=hello_triangle
MAINSRC=${SRC}/${MAINNAME}.c
MAINEXEC=${BIN}/${MAINNAME}
DEPS=$(SRC)/deps
DEPSSRCFILES=$(wildcard $(DEPS)/*.c)
DEPSOBJFILES=$(patsubst $(DEPS)/%.c, $(OBJ)/%.o, $(DEPSSRCFILES))
CFLAGS=-Wall
LDFLAGS=-lglfw -lGL -lX11 -lpthread -lXrandr -lXi -ldl -lm

run: $(MAINEXEC)
	$(MAINEXEC)

$(MAINEXEC): pre $(MAINSRC) $(DEPSOBJFILES)
	$(CC) $(CFLAGS) $(DEPSOBJFILES) $(MAINSRC) -o $(BIN)/$(MAINNAME) $(LDFLAGS) 

$(OBJ)/%.o: $(DEPS)/%.c
	$(CC) $(CFLAGS) -c $^ -o $@

pre:
	@mkdir -p $(OBJ)
	@mkdir -p $(BIN)
clean:
	@rm -rf $(OBJ)
	@rm -rf $(BIN)
.PHONY:
	build clean pre run