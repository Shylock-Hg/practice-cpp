target = a.out

all: $(target)

objs = Vector.o test_Vector.o

$(target): $(objs)
	$(CXX) -o $(target) $(objs)

Vector.o : Vector.cc Vector.h
	$(CXX) -c $< -o $@

test_Vector.o : test_Vector.cc Vector.h
	$(CXX) -c $< -o $@


clean :
	-rm -rf *.o $(target)

test :
	./$(target)
