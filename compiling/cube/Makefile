SRC 	= cube.c
EXE 	= cube
OBJ	   +=$(SRC:.c=.o)
CC		= gcc
CFLAGS 	= -O3
LDFLAGS = 

#-- Implicit rules ---
.c.o:
		$(CC) $(CFLAGS) -c $<

#-- Targets ---
all: $(EXE)

run: $(EXE)
		./$(EXE)

$(EXE):	$(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $@ $(LDFLAGS)

clean:
		rm -f *.o