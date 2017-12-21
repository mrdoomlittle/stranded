SHELL := /bin/bash
FFLY_DIR=../firefly
FFLY_INC=-I$(FFLY_DIR)/inc
FFLY_LIB=-L$(FFLY_DIR)/lib
CURR_DIR=${CURDIR}

ARC=-DARC64
FFLY_ARGS=--force-cuda --use-x11
client:
	cd $(FFLY_DIR); . ./compile.sh $(CURR_DIR)/bin/stranded_client.exec $(CURR_DIR)/src/stranded_client.cpp "--ffly-client $(FFLY_ARGS)" cd ../;
iclean:
	rm -f bin/*.exec src/*.o

clean:
	if [ -d $(FFLY_DIR) ]; then \
		cd $(FFLY_DIR); make clean; cd $(CURR_DIR); \
	fi
	rm -f bin/*.exec src/*.o
