# Compiler
CXX = c++

# Compiler flags
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

# Executable name
TARGET = base

# Source files (explicitly listed)
SRCS = main.cpp Base.cpp

# Object files (replace .cpp with .o)
OBJS = $(SRCS:.cpp=.o)

# Default rule
all: $(TARGET)

# Link object files into executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile .cpp to .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Remove only object files (*.o)
clean:
	rm -f $(OBJS)

# Full clean, remove object files and the executable
fclean: clean
	rm -f $(NAME)

# Rebuild everything from scratch
re: fclean all

# Phony targets
.PHONY: all clean fclean re
