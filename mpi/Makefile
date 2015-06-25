SRC 	= mpi1.c
EXE 	= mpi1
OBJ	   +=$(SRC:.c=.o)
CC		= mpicc
CFLAGS 	= -O3
LDFLAGS =
NPROC   = 2 

#-- Implicit rules ---
.c.o:
		$(CC) $(CFLAGS) -c $<

#-- Targets ---
all: $(EXE)

run: $(EXE)
	mpirun -np $(NPROC) $(EXE)

$(EXE):	$(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $@ $(LDFLAGS)

clean:
		rm -f *.o
