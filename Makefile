MK			=	make -s -C
CHAPTERS	=	Chapter1 Chapter2 Chapter3

all:
	@for chp in $(CHAPTERS); do echo "running simulation..."; $(MK) $$chp; done

clean:
	@for chp in $(CHAPTERS); do echo "cleaning..."; $(MK) $$chp clean; done
