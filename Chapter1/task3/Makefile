S		=	simulator.cpp stage.cpp
O		=	$(S:.cpp=.o)
SRC		=	$(addprefix src/, $(S))
OBJ		=	$(addprefix int/, $(O))
NAME	=	libtask3.a
EXE		=	task3

CPP		=	c++ -I. -Wall -Wextra -Werror -std=c++17 -g

all: $(EXE)
	./$(EXE) || echo "$(EXE) failed"

int/%.o: src/%.cpp
	$(CPP) -c $< -o $@

int:
	mkdir -p int

$(NAME): int $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(EXE): main.cpp $(NAME)
	$(CPP) main.cpp -o $@ -L. -l$(NAME:lib%.a=%)

clean:
	rm -rf int

fclean: clean
	rm -f $(EXE) $(NAME)

re: fclean all

.PHONY: all clean fclean re
