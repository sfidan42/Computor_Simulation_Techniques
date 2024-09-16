MK		=	make -s -C
TASKS	=	task1 task2 task3

all:
	@for task in $(TASKS); do echo "starting..."; $(MK) $$task; done

clean:
	@for task in $(TASKS); do echo "cleaning..."; $(MK) $$task fclean; done
