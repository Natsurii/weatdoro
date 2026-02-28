# Root Makefile

.PHONY: all test clean coverage

# 1. Build the STM32 Firmware (standard project)
all:
	$(MAKE) -C weatdoro

# 2. Run Unit Tests (using the tests.mk file)
test:
	$(MAKE) -f tests.mk run_tests

# 3. Generate Coverage Reports
coverage:
	$(MAKE) -f tests.mk coverage

# 4. Clean everything (both hardware build and test build)
clean:
	$(MAKE) -C weatdoro clean
	$(MAKE) -f tests.mk clean_tests
