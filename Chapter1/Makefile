MK		=	make -s -C
TASKS	=	task1 task2

all:
	@for task in $(TASKS); do echo "running simulation..."; $(MK) $$task; done

clean:
	$(MK) task1 clean
	$(MK) task2 fclean