FILES_RT = RT.cpp

build : rt run

rt : $(FILES_RT)
	gcc $(FILES_RT) -o rt -lm

run :
	./rt