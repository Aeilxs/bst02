CC=gcc
SRC_DIR=src
SRCS=$(wildcard $(SRC_DIR)/*.c)
BUILD_DIR=build
OBJS=$(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS))
CFLAGS=-Wall -Wextra
TARGET=bin_tree

BOLD=$(shell tput bold)
RESET=$(shell tput sgr0)

all: $(BUILD_DIR) $(TARGET)

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

$(TARGET): $(OBJS)
	@echo "$(BOLD)[linking]$(RESET) $^ => $(BUILD_DIR)/$@"
	@$(CC) $(OBJS) -o $(BUILD_DIR)/$(TARGET)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "$(BOLD)[compiling]$(RESET) $< => $@"
	@$(CC) $(CFLAGS) -c $< -o $@

.PHONY: run clean
run:
	@echo "$(BOLD)[run]$(RESET) ./$(BUILD_DIR)/$(TARGET)"
	@echo ""
	@./$(BUILD_DIR)/$(TARGET)

clean:
	@rm -rf $(BUILD_DIR)
	@echo "$(BOLD)[clean]$(RESET) $(BUILD_DIR)"
