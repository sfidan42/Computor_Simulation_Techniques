MK		=	make -s -C
TASKS	=	a b

all:
	@for task in $(TASKS); do echo "starting..."; $(MK) $$task; done

fclean:
	@for task in $(TASKS); do echo "cleaning..."; $(MK) $$task fclean; done
