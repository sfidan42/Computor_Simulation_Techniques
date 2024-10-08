S		=	Simulator.cpp Stage.cpp DataCollector.cpp
O		=	$(S:.cpp=.o)
SRC		=	$(addprefix src/, $(S))
OBJ		=	$(addprefix int/, $(O))
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
	@./$(EXE)
	@./$(EXE) > out/1_simulation.txt
	@echo "$(GREEN)MK > Running $(YELLOW)correlogram.py$(END)"
	@python3 correlogram.py > out/4_results.txt 2> /dev/null
	@echo "$(GREEN)MK > Results saved in $(YELLOW)out/*$(END)"

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

$(EXE): main.cpp $(NAME)
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
