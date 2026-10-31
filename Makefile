CXX ?= clang++
CXXFLAGS ?= -std=c++17 -Wall -Wextra -O2
CPPFLAGS += -Isrc -Ithird_party

RAYLIB_CFLAGS ?= $(shell pkg-config --cflags raylib 2>/dev/null || echo "-I$(shell brew --prefix raylib 2>/dev/null || echo /opt/homebrew)/include")
RAYLIB_LIBS ?= $(shell pkg-config --libs raylib 2>/dev/null || echo "-L$(shell brew --prefix raylib 2>/dev/null || echo /opt/homebrew)/lib -lraylib")
FRAMEWORKS = -framework Cocoa -framework IOKit -framework OpenGL -framework CoreVideo

TARGET = pets
BUILD_DIR = build
SRCS = $(shell find src -type f \( -name '*.cpp' -o -name '*.mm' \))
OBJS = $(addprefix $(BUILD_DIR)/,$(addsuffix .o,$(basename $(SRCS))))
DEPS = $(OBJS:.o=.d)

.PHONY: all clean run compile-commands
all: $(TARGET) compile-commands

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) $(RAYLIB_LIBS) $(FRAMEWORKS) -o $@

$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p "$(@D)"
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(RAYLIB_CFLAGS) -MMD -MP -c $< -o $@

$(BUILD_DIR)/%.o: %.mm
	@mkdir -p "$(@D)"
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(RAYLIB_CFLAGS) -MMD -MP -c $< -o $@

compile-commands:
	@python3 scripts/generate_compile_commands.py --cxx "$(CXX)" --flags "$(CPPFLAGS) $(CXXFLAGS) $(RAYLIB_CFLAGS)"

run: all
	./$(TARGET)

clean:
	rm -rf $(BUILD_DIR) $(TARGET)

-include $(DEPS)
