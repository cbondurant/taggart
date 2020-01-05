OBJDIR = obj
SRCDIR = src
INCLUDEDIR = include
OBJS = $(patsubst $(SRCDIR)/%.cpp, %.o, $(wildcard $(SRCDIR)/*.cpp))


.PHONY: all clean

all: taggart

taggart: $(OBJS)
	$(CXX) -o $@ $(patsubst %, $(OBJDIR)/%, $^) -I $(INCLUDEDIR)

%.o : $(SRCDIR)/%.cpp
	$(CXX) -o $(OBJDIR)/$@ -c $^ -I $(INCLUDEDIR)

clean:
	rm -f $(TARGETS) $(OBJ)
