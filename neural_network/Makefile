
build:
	@echo "Building files"
	g++ edge.cpp -o edge.o -c -std=c++20  -g
	g++ perceptron.cpp -o perceptron.o -c -std=c++20 -g
	g++ neural_network.cpp -o neural_network.o -c -std=c++20 -g
	g++ edge.o perceptron.o neural_network.o -o test -std=c++20 -g 

# -c stops g++ at compilation stage i.e linking won't work w/o all .o files

clean:
	rm *.o
	rm test
