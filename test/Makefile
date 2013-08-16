
GOOGLETEST_DIR=$(CURDIR)/googletest
DIRS = ./search ./tree ./math ./graph ./setlib

all:
	for dir in $(DIRS); do \
		cd $$dir && make GOOGLETEST_DIR=$(GOOGLETEST_DIR) ROOT_DIR=$(CURDIR) && cd - ; \
	done

clean:
	for dir in $(DIRS); do \
		cd $$dir && make clean && cd - ; \
	done

test:
	for dir in $(DIRS); do \
		cd $$dir && make test && cd - ; \
	done

test-only:
	for dir in $(DIRS); do \
		cd $$dir && make test-only && cd - ; \
	done

