BIN_DIR     := ~/bin
CC          := gcc
CC_FLAGS    := -Wall -Wextra -Wpedantic -Werror

.PHONY: install

install: quick-stats chardiff srt-merge
	mkdir -p $(BIN_DIR)
	cp $? $(BIN_DIR)

chardiff: chardiff.c
	$(CC) $(CC_FLAGS) $< -o $@

srt-merge: srt-merge.c
	$(CC) $(CC_FLAGS) $< -o $@

