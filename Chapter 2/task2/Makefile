S		=	AutocorrelationTester.cpp FrequencyTester.cpp \
			RunsTester.cpp ChiSqrTest4GoodnFit.cpp \
			ARNG.cpp SerialTester.cpp asa147.cpp \
			CongruentialGen.cpp
O		=	$(S:.cpp=.o)
SRC		=	$(addprefix src/, $(S))
OBJ		=	$(addprefix int/, $(O))
NAME	=	libtask.a
EXE		=	run
CPP		=	c++ -I. -Iinc -Wall -Wextra -Werror -std=c++17 -g
LD		=	-L . -l$(NAME:lib%.a=%)

all: $(EXE)
	@mkdir -p out
	@echo "MK > Running tests..."
	@echo "MK > Running frequency test with 100 numbers using congruential generator"
	@./$(EXE) 1 123456 100 0	> out/congruential_frequency_test.txt				|| true
	@echo "MK > Running serial test with 100 numbers"
	@./$(EXE) 2 123456 100 0	> out/congruential_serial_test.txt					|| true
	@echo "MK > Running autocorrelation test with 100 numbers"
	@./$(EXE) 3 123456 100 0	> out/congruential_autocorrelation_test.txt 			|| true
	@echo "MK > Running runs test with 4200 numbers"
	@./$(EXE) 4 123456 4200 0	> out/congruential_runs_test.txt						|| true
	@echo "MK > Running chi-squared test for good number of fit with 500000 numbers"
	@./$(EXE) 5 123456 50000 0	> out/congruential_chi_sqr_test_for_good_n_fit.txt	|| true
	@echo "MK > Finished. Check the files inside the folder ./out"
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
