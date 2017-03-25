SHELL := /bin/bash
FFLY_DIR=../firefly
FFLY_INC=-I$(FFLY_DIR)/inc
FFLY_LIB=-L$(FFLY_DIR)/lib
CURR_DIR=${CURDIR}

ARC=-DARC64

server:
	cd $(FFLY_DIR); make ffly_server; cd $(CURR_DIR);
#	g++ -std=c++11 $(SE_CXXFLAGS) -o bin/stranded_server.exec src/stranded_server.cpp $(SE_LDFLAGS)

client:
	cd $(FFLY_DIR); . ./compile.sh $(CURR_DIR)/bin/stranded_client.exec $(CURR_DIR)/src/stranded_client.cpp FFLY_CLIENT ffly_client -DOBJ_MANAGER cd ../;
	echo "$(CXXFLAGS)"
#	cd $(FFLY_DIR); make ffly_client; cd $(CURR_DIR);
#	g++ -std=c++11 $(CL_CXXFLAGS) -o bin/stranded_client.exec src/stranded_client.cpp $(CL_LDFLAGS)

iclean:
	rm -f bin/*.exec src/*.o

clean:
	if [ -d $(FFLY_DIR) ]; then \
		cd $(FFLY_DIR); make clean; cd $(CURR_DIR); \
	fi
	rm -f bin/*.exec src/*.o
