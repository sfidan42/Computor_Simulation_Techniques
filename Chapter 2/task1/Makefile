S		=	AutocorrelationTester.cpp FrequencyTester.cpp \
			RunsTester.cpp ChiSqrTest4GoodnFit.cpp \
			RNG.cpp SerialTester.cpp
O		=	$(S:.cpp=.o)
SRC		=	$(addprefix src/, $(S))
OBJ		=	$(addprefix int/, $(O))
NAME	=	libtask.a
ALGIB	=	alglib-cpp/libalgib.a
EXE		=	run
CPP		=	c++ -I. -Iinc -Ialglib-cpp/src -Wall -Wextra -Werror -std=c++17 -g
LD		=	-L . -l$(NAME:lib%.a=%) -L alglib-cpp -lalgib

all: $(ALGIB) $(EXE)
	@./$(EXE) || echo "$(EXE) failed"

int/%.o: src/%.cpp
	$(CPP) -c $< -o $@

int:
	mkdir -p int

$(ALGIB):
	./alglib-src/setup.sh
	make -C alglib-cpp

$(NAME): int $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(EXE): main.cpp $(NAME) $(ALGIB)
	$(CPP) main.cpp $(LD) -o $@

clean:
	rm -rf int

fclean: clean
	rm -rf $(EXE) $(NAME) alglib-cpp

re: fclean all

.PHONY: all clean fclean re
