
std-objs = ../../../common/src/Common.o ../../../hardware/src/Hw.o
simu-objs = ../src/Simu.o

test-objs = test.o BufferSave.o
test-ext-objs = $(simu-objs)
	
testsimulator-objs = testsimulator.o BufferSave.o
testsimulator-ext-objs = $(simu-objs) $(std-objs)

testsimuhwinterface-objs = testsimuhwinterface.o BufferSave.o
testsimuhwinterface-ext-objs = $(simu-objs) $(std-objs)

INC = -I../include -I../../../common/include -I../../../hardware/include 
CXXFLAGS += $(INC) -Wall -pthread
LDFLAGS = -pthread

all: 	clean test testsimulator testsimuhwinterface

test:	$(test-objs)
	$(CXX) $(LDFLAGS) -o $@ $+ $(test-ext-objs) $(std-objs)

testsimulator: $(testsimulator-objs)
	$(CXX) $(LDFLAGS) -o $@ $+ $(testsimulator-ext-objs) 

testsimuhwinterface: $(testsimuhwinterface-objs)
	$(CXX) $(LDFLAGS) -o $@ $+ $(testsimuhwinterface-ext-objs) 

clean: 
	rm -f $(test-objs) test *.edf
	rm -f $(testsimulator-objs) testsimulator
	rm -f $(testsimuhwinterface-objs) testsimuhwinterface
