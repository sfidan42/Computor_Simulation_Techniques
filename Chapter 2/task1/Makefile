S		=	AutocorrelationTester.cpp FrequencyTester.cpp \
			RunsTester.cpp ChiSqrTest4GoodnFit.cpp \
			RNG.cpp SerialTester.cpp asa147.cpp
O		=	$(S:.cpp=.o)
SRC		=	$(addprefix src/, $(S))
OBJ		=	$(addprefix int/, $(O))
NAME	=	libtask.a
EXE		=	run
CPP		=	c++ -I. -Iinc -Wall -Wextra -Werror -std=c++17 -g
LD		=	-L . -l$(NAME:lib%.a=%)

all: $(EXE)
	@mkdir -p out
	@echo "Running tests... (check the files inside ./out)"
	@./$(EXE) 1 123456 100		> out/frequency_test.txt				|| echo "$(EXE) 1 failed"
	@./$(EXE) 2 123456 100		> out/serial_test.txt					|| echo "$(EXE) 2 failed"
	@./$(EXE) 3 123456 100		> out/autocorrelation_test.txt 			|| echo "$(EXE) 3 failed"
	@./$(EXE) 4 123456 4200		> out/runs_test.txt						|| echo "$(EXE) 4 failed"
	@./$(EXE) 5 123456 500000	> out/chi_sqr_test_for_good_n_fit.txt	|| echo "$(EXE) 5 failed"

int/%.o: src/%.cpp
	$(CPP) -c $< -o $@

int:
	mkdir -p int

$(NAME): int $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(EXE): main.cpp $(NAME)
	$(CPP) main.cpp $(LD) -o $@

clean:
	rm -rf int out

fclean: clean
	rm -rf $(EXE) $(NAME)

re: fclean all

.PHONY: all clean fclean re
