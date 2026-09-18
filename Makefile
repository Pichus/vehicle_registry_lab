TARGET_EXEC := vehicle_registry

BUILD_DIR := ./build
SRC_DIRS := ./src

CC := gcc-15
# https://stackoverflow.com/questions/3375697/what-are-the-useful-gcc-flags-for-c
CFLAGS := -Wall -Wextra -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wstrict-prototypes

$(BUILD_DIR)/$(TARGET_EXEC): $(BUILD_DIR)/main.o 
	$(CC) $(BUILD_DIR)/main.o -o $(BUILD_DIR)/$(TARGET_EXEC)

$(BUILD_DIR)/main.o: $(BUILD_DIR) $(SRC_DIRS)/main.c $(SRC_DIRS)/vehicle.h $(SRC_DIRS)/person.h
	$(CC) $(CFLAGS) -c $(SRC_DIRS)/main.c -o $(BUILD_DIR)/main.o

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)
