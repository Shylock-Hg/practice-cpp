all: a.out
.PHONY:all clean

APP=newCurrency#currency

a.out : test_$(APP).o $(APP).o
	$(CXX) -g -o $@ test_$(APP).o $(APP).o

main.o : test_$(APP).cc $(APP).h
	$(CXX) -g -o $@ -c $<
currency.o : $(APP).cc $(APP).h
	$(CXX) -g -o $@ -c $<

clean :
	rm *.o a.out
