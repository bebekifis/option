GCC=g++
INC=-I ./

all: demo

demo: demo.cpp options.cpp
	$(GCC) $^ -o $@ $(INC)
	
.PHONY : clean
clean :
-rm demo