S		=	alglibinternal.cpp		integration.cpp		optimization.cpp	alglibmisc.cpp \
			interpolation.cpp		solvers.cpp 		ap.cpp				kernels_avx2.cpp \
			specialfunctions.cpp	dataanalysis.cpp	kernels_fma.cpp		statistics.cpp \
			diffequations.cpp		kernels_sse2.cpp	fasttransforms.cpp 	linalg.cpp
SRC		=	$(addprefix src/, $(S))
OBJ		=	$(addprefix int/, $(S:.cpp=.o))
NAME	=	libalgib.a
CPP		=	c++ -Wall -Wextra -std=c++17

all: $(NAME)

int:
	mkdir -p int

int/%.o: src/%.cpp
	$(CPP) -c $< -o $@

$(NAME): int $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -rf int

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re