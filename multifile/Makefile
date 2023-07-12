build:
	@echo "Building files"
	g++ add.cpp -o add.o -c 
	g++ main.cpp -o main.o -c 
	g++ main.o add.o -o test

# -c stops g++ at compilation stage i.e linking won't work w/o all .o files

clean:
	rm *.o
	rm test
