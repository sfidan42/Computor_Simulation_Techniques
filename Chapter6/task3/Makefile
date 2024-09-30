S		=	Simulator.cpp Stage.cpp DataCollector.cpp
O		=	$(S:.cpp=.o)
H		=	$(S:.cpp=.hpp)
SRC		=	$(addprefix src/, $(S))
OBJ		=	$(addprefix int/, $(O))
HDR		=	$(addprefix inc/, $(H))
NAME	=	libtask.a
EXE		=	run
CPP		=	c++ -I. -Iinc -Wall -Wextra -Werror -std=c++17 -g
LD		=	-L . -ltask

RED		=	\033[0;31m
GREEN	=	\033[0;32m
YELLOW	=	\033[0;33m
BLUE	=	\033[0;34m
CYAN	=	\033[0;36m
WHITE	=	\033[0;37m
END		=	\033[0m

all: out $(EXE)
	@echo "$(GREEN)MK > Running $(YELLOW)$(EXE)$(END)"
	@./$(EXE) > out/output.txt
	@echo "$(GREEN)MK > Running $(YELLOW)correlogram.py$(END)"
	@python3 correlogram.py > out/results.txt
	@echo "$(GREEN)MK > Results saved in $(YELLOW)out/*$(END)"
	@echo "$(GREEN)MK > Calculating $(END)"
	@echo -n "$(GREEN)MK > $(YELLOW)W1 = 1 / [(β1µ1 /(α1 + β1 )) - λ ]: $(END)"
	@echo "1 / (1/2.5 * 1/20 / (1/200 + 1/2.5) - 1/40)" | bc -l
	@echo -n "$(GREEN)MK > $(YELLOW)W2 = 1 / [(β2µ2 /(α2 + β2 )) - λ ]: $(END)"
	@echo "1 / (1/5 * 1/30 / (1/300 + 1/5) - 1/40)" | bc -l
	@echo "$(GREEN)MK > Plotting the scatter plot of waiting time vs. queue size$(END)"
	@python3 plot.py

int/%.o: src/%.cpp inc/%.hpp
	@echo "$(GREEN)MK > Compiling $(BLUE)$<$(END) -> $(YELLOW)$@$(END)"
	@$(CPP) -c $< -o $@

out:
	@mkdir -p out

int:
	@mkdir -p int

$(NAME): int $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "$(GREEN)MK > Library created: $(YELLOW)$(NAME)$(END)"

$(EXE): main.cpp $(NAME) $(HDR)
	@$(CPP) main.cpp $(LD) -o $(EXE)
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
