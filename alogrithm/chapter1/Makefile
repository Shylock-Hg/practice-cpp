all: app

APP=newCurrency#currency

app : test_$(APP).o $(APP).o
	$(CXX) -o $@ test_$(APP).o $(APP).o

main.o : test_$(APP).cc $(APP).h
	$(CXX) -o $@ -c $<
currency.o : $(APP).cc $(APP).h
	$(CXX) -o $@ -c $<
