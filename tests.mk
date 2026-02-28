# tests.mk
TEST_CC = gcc

# Added -I./drivers and -I./tests/mocks so the compiler finds your headers
TEST_CFLAGS = -I. -I./drivers -I./tests/mocks -Wall -g --coverage 
TEST_LIBS = -lcunit -lgcov

TEST_BUILD_DIR = bin/tests
TEST_TARGET = $(TEST_BUILD_DIR)/unit_tests
INFO_FILE = $(TEST_BUILD_DIR)/coverage.info
REPORT_DIR = $(TEST_BUILD_DIR)/coverage_report

# Automatically find all C files in tests/ and drivers/
TEST_FILES = $(wildcard tests/*.c)
APP_LOGIC  = $(wildcard drivers/*.c)

TEST_SRCS = $(TEST_FILES) $(APP_LOGIC)
# This pattern handles files in multiple subdirectories correctly
TEST_OBJS = $(patsubst %.c,$(TEST_BUILD_DIR)/%.o,$(TEST_SRCS))

.PHONY: run_tests coverage clean_tests

# 1. Run the tests
run_tests: $(TEST_TARGET)
	@printf " RUNNING TESTS\n"
	@./$(TEST_TARGET)

# 2. Generate the LCOV report
coverage: run_tests
	@printf " GENERATING COVERAGE REPORT\n"
	@mkdir -p $(REPORT_DIR)
	@lcov --capture --directory $(TEST_BUILD_DIR) --output-file $(INFO_FILE) --no-external
	@# Filter out the test code itself so you only see coverage for your actual logic
	@lcov --remove $(INFO_FILE) '*/tests/*' --output-file $(INFO_FILE)
	@genhtml $(INFO_FILE) --output-directory $(REPORT_DIR)
	@echo "Report available at: $(REPORT_DIR)/index.html"

$(TEST_TARGET): $(TEST_OBJS)
	@mkdir -p $(TEST_BUILD_DIR)
	@printf " LD (TEST)\t$@\n"
	$(TEST_CC) $(TEST_OBJS) $(TEST_LIBS) -o $@

# Rule to compile objects while preserving folder structure in bin/tests
$(TEST_BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@printf " CC (TEST)\t$<\n"
	$(Q)$(TEST_CC) $(TEST_CFLAGS) -c $< -o $@

clean_tests:
	rm -rf $(TEST_BUILD_DIR)
