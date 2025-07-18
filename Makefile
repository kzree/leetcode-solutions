# Makefile
CFLAGS = -std=c99 -Wall -Wextra -g
CXXFLAGS = -std=c++17 -Wall -Wextra -g
SRCDIR = c_cpp

# Default rule - compile any target by looking in c_cpp folder
%: 
	@if [ -f "$(SRCDIR)/$@.cpp" ]; then \
		echo "Compiling $(SRCDIR)/$@.cpp"; \
		filename=$$(basename $@); \
		g++ $(CXXFLAGS) -o $$filename $(SRCDIR)/$@.cpp; \
	elif [ -f "$(SRCDIR)/$@.c" ]; then \
		echo "Compiling $(SRCDIR)/$@.c"; \
		filename=$$(basename $@); \
		gcc $(CFLAGS) -o $$filename $(SRCDIR)/$@.c; \
	else \
		echo "Error: Could not find $(SRCDIR)/$@.cpp or $(SRCDIR)/$@.c"; \
		exit 1; \
	fi

# Clean up executables in root
clean:
	find . -maxdepth 1 -type f -executable -not -name "*.sh" -not -name "Makefile" -delete

# Help message
help:
	@echo "Usage examples:"
	@echo "  make easy/palindrome     - compiles c_cpp/easy/palindrome.c to ./palindrome"
	@echo "  make medium/add_two      - compiles c_cpp/medium/add_two.c to ./add_two"
	@echo "  make hard/median         - compiles c_cpp/hard/median.c to ./median"
	@echo "  make clean               - removes all executables from root"
	@echo ""
	@echo "All executables are created in the root directory"

.PHONY: clean help
