METHOD ?= opt

appname := tt
full_appname := $(appname)-$(METHOD)

CXX := clang++
CXXFLAGS := -std=c++11

srcfiles := $(shell find . -name "*.C")
objects	 := $(patsubst %.C, %-$(METHOD).o, $(srcfiles))

all: $(full_appname)

$(appname)-opt: $(objects)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -g -fno-omit-frame-pointer -O3 -o $(full_appname) $(objects) $(LDLIBS)

$(appname)-dbg: $(objects)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -g -fno-omit-frame-pointer -o $(full_appname) $(objects) $(LDLIBS)

%-opt.o: %.C
	$(CXX) -c $(CXXFLAGS) $(LDFLAGS) -g -fno-omit-frame-pointer -O3 -MMD -MP -MF $@.d -MT $@ $< -o $@ $(LDLIBS)

%-dbg.o: %.C
	$(CXX) -c $(CXXFLAGS) $(LDFLAGS) -g -fno-omit-frame-pointer -MMD -MP -MF $@.d -MT $@ $< -o $@ $(LDLIBS)

clean:
	rm -f *.o
	rm -f $(objects)
	rm -f $(full_appname)
	rm -rf *.d
	rm -f *~*

-include $(patsubst %, %-opt.o.d, $(basename $(srcfiles)))
