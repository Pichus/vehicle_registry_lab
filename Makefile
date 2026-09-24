TARGET_EXEC := vehicle_registry

BUILD_DIR := ./build
SRC_DIR := ./src

CC := gcc-15
# https://stackoverflow.com/questions/3375697/what-are-the-useful-gcc-flags-for-c
CFLAGS := -MMD -MP -Wall -Wextra -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wstrict-prototypes

SOURCE_FILES := $(wildcard $(SRC_DIR)/*.c)

OBJECT_FILES := $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SOURCE_FILES)) 

DEPENDENCY_FILES := $(patsubst $(BUILD_DIR)/%.o, $(BUILD_DIR)/%.d, $(OBJECT_FILES));

$(BUILD_DIR)/$(TARGET_EXEC): $(OBJECT_FILES) 
	$(CC) $(OBJECT_FILES) -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR) 
	$(CC) $(CFLAGS) -c $< -o $@ 

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

-include $(DEPENDENCY_FILES)

clean:
	rm -rf $(BUILD_DIR)
