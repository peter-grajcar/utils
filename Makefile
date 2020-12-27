BIN_DIR     := ~/bin
CC          := gcc
CC_FLAGS    := -Wall -Wextra -Wpedantic -Wwarnings

.PHONY: install

install: quick-stats chardiff
	mkdir -p $(BIN_DIR)
	cp $? $(BIN_DIR)

chardiff: chardiff.c
	$(CC) $(CC_FLAGS) $< -o $@

