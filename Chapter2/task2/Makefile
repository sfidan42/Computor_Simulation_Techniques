S		=	AutocorrelationTester.cpp FrequencyTester.cpp \
			RunsTester.cpp ChiSqrTest4GoodnFit.cpp \
			ARNG.cpp SerialTester.cpp asa147.cpp \
			CongruentialGen.cpp CompositeGen.cpp \
			TauswortheGen.cpp LaggedFibonacciGen.cpp \
			MersenneTwisterGen.cpp
O		=	$(S:.cpp=.o)
SRC		=	$(addprefix src/, $(S))
OBJ		=	$(addprefix int/, $(O))
NAME	=	libtask.a
EXE		=	run
CPP		=	c++ -I. -Iinc -Wall -Wextra -Werror -std=c++17 -g
LD		=	-L . -l$(NAME:lib%.a=%)

RED		=	\033[0;31m
GREEN	=	\033[0;32m
YELLOW	=	\033[0;33m
BLUE	=	\033[0;34m
CYAN	=	\033[0;36m
WHITE	=	\033[0;37m
END		=	\033[0m

all: $(EXE)
	@mkdir -p out
	@echo "$(RED)MK > Congruential Generator Testings:$(END)"
	@echo "$(GREEN)MK > Running $(CYAN)frequency test with 100 numbers$(END)"
	@./$(EXE) 1 123456 100 1		> out/congruential_frequency_test.txt					|| true
	@echo "$(GREEN)MK > Running $(CYAN)serial test with 100 numbers$(END)"
	@./$(EXE) 2 123456 100 1		> out/congruential_serial_test.txt						|| true
	@echo "$(GREEN)MK > Running $(CYAN)autocorrelation test with 100 numbers$(END)"
	@./$(EXE) 3 123456 100 1		> out/congruential_autocorrelation_test.txt 			|| true
	@echo "$(GREEN)MK > Running $(CYAN)runs test with 4200 numbers$(END)"
	@./$(EXE) 4 123456 4200 1		> out/congruential_runs_test.txt						|| true
	@echo "$(GREEN)MK > Running $(CYAN)chi-squared test for good number of fit with 5000 numbers$(END)"
	@./$(EXE) 5 3885576022 5000 1	> out/congruential_chi_sqr_test_for_good_n_fit.txt		|| true
	@echo "$(RED)MK > Composite Generator Testings:$(END)"
	@echo "$(GREEN)MK > Running $(CYAN)frequency test with 100 numbers$(END)"
	@./$(EXE) 1 3885576022 100 2	> out/composite_frequency_test.txt						|| true
	@echo "$(GREEN)MK > Running $(CYAN)serial test with 100 numbers$(END)"
	@./$(EXE) 2 3885576022 100 2	> out/composite_serial_test.txt							|| true
	@echo "$(GREEN)MK > Running $(CYAN)autocorrelation test with 100 numbers$(END)"
	@./$(EXE) 3 3885576022 100 2	> out/composite_autocorrelation_test.txt				|| true
	@echo "$(GREEN)MK > Running $(CYAN)runs test with 4200 numbers$(END)"
	@./$(EXE) 4 3885576022 4200 2	> out/composite_runs_test.txt							|| true
	@echo "$(GREEN)MK > Running $(CYAN)chi-squared test for good number of fit with 20000 numbers$(END)"
	@./$(EXE) 5 3885576022 20000 2	> out/composite_chi_sqr_test_for_good_n_fit.txt			|| true
	@echo "$(RED)MK > Tausworthe Generator Testings:$(END)"
	@echo "$(GREEN)MK > Running $(CYAN)frequency test with 100 numbers$(END)"
	@./$(EXE) 1 3885576022 100 3	> out/tausworthe_frequency_test.txt						|| true
	@echo "$(GREEN)MK > Running $(CYAN)serial test with 100 numbers$(END)"
	@./$(EXE) 2 1234567890 100 3	> out/tausworthe_serial_test.txt						|| true
	@echo "$(GREEN)MK > Running $(CYAN)autocorrelation test with 100 numbers$(END)"
	@./$(EXE) 3 1234567890 100 3	> out/tausworthe_autocorrelation_test.txt				|| true
	@echo "$(GREEN)MK > Running $(CYAN)runs test with 4200 numbers$(END)"
	@./$(EXE) 4 1234567890 4200 3	> out/tausworthe_runs_test.txt							|| true
	@echo "$(GREEN)MK > Running $(CYAN)chi-squared test for good number of fit with 5000 numbers$(END)"
	@./$(EXE) 5 1234567890 5000 3	> out/tausworthe_chi_sqr_test_for_good_n_fit.txt		|| true
	@echo "$(RED)MK > Lagged Fibonacci Generator Testings:$(END)"
	@echo "$(GREEN)MK > Running $(CYAN)frequency test with 100 numbers$(END)"
	@./$(EXE) 1 1234567890 100 4	> out/lagged_fibonacci_frequency_test.txt				|| true
	@echo "$(GREEN)MK > Running $(CYAN)serial test with 100 numbers$(END)"
	@./$(EXE) 2 1234567890 100 4	> out/lagged_fibonacci_serial_test.txt					|| true
	@echo "$(GREEN)MK > Running $(CYAN)autocorrelation test with 100 numbers$(END)"
	@./$(EXE) 3 1234567890 100 4	> out/lagged_fibonacci_autocorrelation_test.txt			|| true
	@echo "$(GREEN)MK > Running $(CYAN)runs test with 4200 numbers$(END)"
	@./$(EXE) 4 1234567890 4200 4	> out/lagged_fibonacci_runs_test.txt					|| true
	@echo "$(GREEN)MK > Running $(CYAN)chi-squared test for good number of fit with 5000 numbers$(END)"
	@./$(EXE) 5 1234567890 5000 4	> out/lagged_fibonacci_chi_sqr_test_for_good_n_fit.txt	|| true
	@echo "$(RED)MK > Mersenne Twister Generator Testings:$(END)"
	@echo "$(GREEN)MK > Running $(CYAN)frequency test with 100 numbers$(END)"
	@./$(EXE) 1 1234567890 100 5	> out/mersenne_twister_frequency_test.txt				|| true
	@echo "$(GREEN)MK > Running $(CYAN)serial test with 100 numbers$(END)"
	@./$(EXE) 2 1234567890 100 5	> out/mersenne_twister_serial_test.txt					|| true
	@echo "$(GREEN)MK > Running $(CYAN)autocorrelation test with 100 numbers$(END)"
	@./$(EXE) 3 1234567890 100 5	> out/mersenne_twister_autocorrelation_test.txt			|| true
	@echo "$(GREEN)MK > Running $(CYAN)runs test with 4200 numbers$(END)"
	@./$(EXE) 4 1234567890 4200 5	> out/mersenne_twister_runs_test.txt					|| true
	@echo "$(GREEN)MK > Running $(CYAN)chi-squared test for good number of fit with 5000 numbers$(END)"
	@./$(EXE) 5 3885576022 5000 5	> out/mersenne_twister_chi_sqr_test_for_good_n_fit.txt	|| true
	@echo "$(GREEN)MK > All tests finished.$(RED) Check the files inside the folder ./out$(END)"

int/%.o: src/%.cpp inc/%.hpp
	@echo "$(GREEN)MK > Compiling $(BLUE)$<$(END) -> $(YELLOW)$@$(END)"
	@$(CPP) -c $< -o $@

int:
	@mkdir -p int

$(NAME): int $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "$(GREEN)MK > Library created: $(YELLOW)$(NAME)$(END)"

$(EXE): main.cpp $(NAME)
	@$(CPP) main.cpp $(LD) -o $@
	@echo "$(GREEN)MK > Executable created: $(YELLOW)$(EXE)$(END)"

clean:
	@echo "$(RED)MK > Removing object files$(END)"
	@echo "$(RED)MK > Removing output files$(END)"
	@rm -rf int out

fclean: clean
	@echo "$(RED)MK > Removing the executable$(END)"
	@echo "$(RED)MK > Removing the archive file$(END)"
	@rm -f $(EXE) $(NAME)

re: fclean all

.PHONY: all clean fclean re
