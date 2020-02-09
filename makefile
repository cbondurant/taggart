OBJDIR = obj
SRCDIR = src
INCLUDEDIR = include
OBJS = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(wildcard $(SRCDIR)/*.cpp))


.PHONY: all clean

all: taggart

taggart: $(OBJS)
	$(CXX) -I $(INCLUDEDIR) -o $@ $^

$(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	$(CXX) -I $(INCLUDEDIR) -o $@ -c $^ -g

clean:
	rm -f obj/* taggart
