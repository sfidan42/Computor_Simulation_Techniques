MK		=	make -s -C
TASKS	=	task1 task2 task3

all:
	@for task in $(TASKS); do echo "running simulation..."; $(MK) $$task; done

clean:
	@for task in $(TASKS); do echo "cleaning..."; $(MK) $$task fclean; done
