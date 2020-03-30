TARGETS := glut_main
OBJECTS := glut_main.o app.o gl_draw.o glut_callback.o zebra.o lion.o critter.o simulator.o
CXXFLAGS := -Wall -Werror
LDFLAGS := -lglut -lGLU -lGL
UNAME := $(shell uname)
ifeq ($(UNAME), Darwin)

LDFLAGS := -framework OpenGL -framework GLUT 
CXXFLAGS := $(CXXFLAGS) -Wno-deprecated

CXX := g++
# debuGging
CXXFLAGS := -std=c++11 -g
#CXXFLAGS := -std=c++11 
#CXXFLAGS := -std=c++11 -O
GTEST_DIR := ../googletest/

# OS X specific options

endif

all: $(TARGETS)

check: $(TARGETS)
	./glut_main


glut_main: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

unit-test: critter.o lion.o zebra.o test_1_LionIsACritter.o test_2_ZebraIsACritter.o test_3_CritterMethods.o test_4_LionEats.o test_5_ZebraEats.o test_6_PositionAvailable.o test_7_LionMoves.o test_8_Reproduces.o
	$(CXX) -o $@ $^ -L. -lgtest -lpthread

# $@ == target (left hand side of colon)
# $^ == all dependencies (right hand side of colon)
main: main.o critter.o lion.o zebra.o
	$(CXX) $(CXXFLAGS) -o $@ $^

# $< == first dependency (first on the right side of the colon)
main.o: main.cpp critter.h lion.h zebra.h
	$(CXX) $(CXXFLAGS) -c $<

simulator.o: simulator.cpp simulator.h 
	$(CXX) $(CXXFLAGS) -c $<

critter.o: critter.cpp critter.h
	$(CXX) $(CXXFLAGS) -c $<

lion.o: lion.cpp lion.h
	$(CXX) $(CXXFLAGS) -c $<

zebra.o: zebra.cpp zebra.h
	$(CXX) $(CXXFLAGS) -c $<

glut_main.o: glut_main.cpp glut_app.h
	$(CXX) $(CXXFLAGS) -c $<

app.o: app.cpp glut_app.h simulator.h
	$(CXX) $(CXXFLAGS) -c $<

gl_draw.o: gl_draw.cpp glut_app.h
	$(CXX) $(CXXFLAGS) -c $<

glut_callback.o: glut_callback.cpp glut_app.h
	$(CXX) $(CXXFLAGS) -c $<


test_1_LionIsACritter.o: test_1_LionIsACritter.cpp critter.h lion.h
	$(CXX) $(CXXFLAGS) -I$(GTEST_DIR)/include -c $<

test_2_ZebraIsACritter.o: test_2_ZebraIsACritter.cpp zebra.h
	$(CXX) $(CXXFLAGS) -I$(GTEST_DIR)/include -c $<

test_3_CritterMethods.o: test_3_CritterMethods.cpp zebra.h
	$(CXX) $(CXXFLAGS) -I$(GTEST_DIR)/include -c $<

test_4_LionEats.o: test_4_LionEats.cpp zebra.h lion.h
	$(CXX) $(CXXFLAGS) -I$(GTEST_DIR)/include -c $<

test_5_ZebraEats.o: test_5_ZebraEats.cpp zebra.h lion.h
	$(CXX) $(CXXFLAGS) -I$(GTEST_DIR)/include -c $<

test_6_PositionAvailable.o: test_6_PositionAvailable.cpp lion.h zebra.h
	$(CXX) $(CXXFLAGS) -I$(GTEST_DIR)/include -c $<

test_7_LionMoves.o: test_7_LionMoves.cpp zebra.h lion.h
	$(CXX) $(CXXFLAGS) -I$(GTEST_DIR)/include -c $< 

test_8_Reproduces.o: test_8_Reproduces.cpp zebra.h lion.h
	$(CXX) $(CXXFLAGS) -I$(GTEST_DIR)/include -c $<

libgtest.a:
	$(CXX) -isystem $(GTEST_DIR)/include -I$(GTEST_DIR) -pthread -c $(GTEST_DIR)/src/gtest-all.cc
	$(CXX) -isystem $(GTEST_DIR)/include -I$(GTEST_DIR) -pthread -c $(GTEST_DIR)/src/gtest_main.cc
	ar -rv libgtest.a gtest-all.o gtest_main.o

memtest:main
	valgrind --leak-check=full ./main

clean:
	-rm -f *.o
	-rm -f $(TARGETS)
	-rm -f *~
	#-rm -f libgtest.a