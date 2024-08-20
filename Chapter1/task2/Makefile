S		=	queues.cpp simulator.cpp token.cpp
O		=	$(S:.cpp=.o)
SRC		=	$(addprefix src/, $(S))
OBJ		=	$(addprefix int/, $(O))
NAME	=	libtask2.a
EXE		=	task2

CPP		=	c++ -I. -Wall -Wextra -Werror -std=c++17 -g

all: $(EXE)
	./$(EXE) || echo "task2 failed"

int/%.o: src/%.cpp
	$(CPP) -c $< -o $@

int:
	mkdir -p int

$(NAME): int $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(EXE): main.cpp $(NAME)
	$(CPP) main.cpp -o $@ -L. -ltask2

clean:
	rm -rf int

fclean: clean
	rm -f $(EXE) $(NAME)

re: fclean all

.PHONY: all clean fclean re
