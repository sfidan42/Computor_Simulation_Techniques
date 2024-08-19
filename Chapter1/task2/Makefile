S		=	queues.cpp simulator.cpp token.cpp
O		=	$(S:.cpp=.o)
SRC		=	$(addprefix src/, $(S))
OBJ		=	$(addprefix int/, $(O))
NAME	=	libtask2.a
EXE		=	task2

all: $(EXE)
	./$(EXE)

int/%.o: src/%.cpp
	c++ -c -I. -Wall -Wextra -Werror -std=c++17 $< -o $@

int:
	mkdir -p int

$(NAME): int $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(EXE): main.cpp $(NAME)
	c++ -Wall -Wextra -Werror -std=c++17 main.cpp -o $@ -L. -ltask2

clean:
	rm -rf int

fclean: clean
	rm -f $(EXE) $(NAME)

re: fclean all

.PHONY: all clean fclean re
