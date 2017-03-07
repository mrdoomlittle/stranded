all : src/stranded.o src/stranded.co
	g++ -o bin/stranded.exec src/stranded.o src/stranded.co -Wall -I/usr/local/cuda-8.0/include -L/usr/local/cuda-8.0/lib64 -lcuda -lcudart \
        -lboost_system -lboost_filesystem -lpthread -lboost_thread -lsfml-graphics -lsfml-window -lsfml-system

src/stranded.o: src/stranded.cpp
	g++ -c -std=c++14 -Wall src/stranded.cpp -o src/stranded.o

src/stranded.co: src/stranded.cu
	nvcc -c -std=c++11 -I/usr/local/cuda-8.0/include -L/usr/local/cuda-8.0/lib64 src/stranded.cu -o src/stranded.co
clean-soft :
	rm -f src/*.*o*
