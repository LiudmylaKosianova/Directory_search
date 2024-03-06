CC = gcc
CFLAGS = -Wall -g 

EXEC = directory_search
SRC = main.c directory_search.c 
OBJ = $(SRC:.c=.o)
DEPS = $(SRC:.c=.d)

all: $(EXEC)

%.o:%.c 
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

-include $(DEPS)

clean:
	$(RM) $(OBJ) $(DEPS) $(EXEC)

