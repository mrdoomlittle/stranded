SHELL := /bin/bash
FFLY_DIR=firefly
FFLY_INC=-I$(FFLY_DIR)/inc
FFLY_LIB=-L$(FFLY_DIR)/lib
CURR_DIR=${CURDIR}

ARC=-DARC64
CUDA=-I/usr/local/cuda-8.0/include -L/usr/local/cuda-8.0/lib64

SE_CXXFLAGS=-L/usr/local/lib -I/usr/local/include -L/usr/local/lib/x86_64/sdk $(ARC) $(FFLY_INC) $(FFLY_LIB)
CL_CXXFLAGS=$(CUDA) -L/usr/local/lib -I/usr/local/include $(ARC) $(FFLY_INC) $(FFLY_LIB)

SE_LDFLAGS=-lffly_server -lto_string -lgetdigit -lintlen -lstrcmb -lpng16 -lboost_system -lemu2d -lOpenCL -lboost_filesystem -lpthread -lboost_thread
CL_LDFLAGS=-lffly_client -lto_string -lgetdigit -lintlen -lstrcmb -lemu2d -lpulse -lpulse-simple -lpng16 -lcuda -lcudart -lboost_system -lboost_filesystem -lpthread -lboost_thread -lX11 -lGL -lGLU -lglut
server:
	cd $(FFLY_DIR); make ffly_server; cd $(CURR_DIR);
	g++ -std=c++11 $(SE_CXXFLAGS) -o bin/stranded_server.exec src/stranded_server.cpp $(SE_LDFLAGS)

client:
	cd $(FFLY_DIR); make ffly_client; cd $(CURR_DIR);
	g++ -std=c++11 $(CL_CXXFLAGS) -o bin/stranded_client.exec src/stranded_client.cpp $(CL_LDFLAGS)


clean:
	if [ -d $(FFLY_DIR) ]; then \
		cd $(FFLY_DIR); make clean; cd $(CURR_DIR); \
	fi
	rm -f bin/*.exec src/*.o
