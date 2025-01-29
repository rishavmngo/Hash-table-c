CC = gcc
CFLAGS = -Wall -g -std=c99

BUILD_DIR = build

BUILD = $(BUILD_DIR)/program
SRC = $(wildcard *.c) 
OBJS = $(patsubst %.c,$(BUILD_DIR)/%.o,$(SRC))


all: $(BUILD)

$(BUILD): $(OBJS)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -MMD -MP  -c $< -o $@


clean:
	rm -rf $(BUILD_DIR)

-include $(OBJS:.o=.d)


.PHONY: all clean
