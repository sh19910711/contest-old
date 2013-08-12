
GOOGLETEST_DIR=$(CURDIR)/googletest
DIRS = ./search ./tree

all:
	for dir in $(DIRS); do \
		cd $$dir && make GOOGLETEST_DIR=$(GOOGLETEST_DIR) && cd - ; \
	done

clean:
	for dir in $(DIRS); do \
		cd $$dir && make clean && cd - ; \
	done

test:
	for dir in $(DIRS); do \
		cd $$dir && make test && cd - ; \
	done


