target = test

all: $(target)

objs = Vector.o test_Vector.o

test: $(objs)
	$(CXX) -o $(target) $(objs)

Vector.o : Vector.cc Vector.h
	$(CXX) -c $< -o $@

test_Vector.o : test_Vector.cc Vector.h
	$(CXX) -c $< -o $@



