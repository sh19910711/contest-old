
DIRS=./binary_indexed_tree

all:
	for dir in $(DIRS); do \
		cd $$dir && make && cd - ; \
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

