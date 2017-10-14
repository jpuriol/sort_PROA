GTEST_DIR = ../googletest/googletest

USER_DIR = .

CPPFLAGS += -std=c++11 -isystem $(GTEST_DIR)/include

CXXFLAGS += -g -Wall -Wextra -pthread

TESTS = sort_test

GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h


all : $(TESTS)

clean :
	rm -f $(TESTS) gtest.a gtest_main.a *.o


GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

gtest-all.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest-all.cc

gtest_main.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest_main.cc

gtest.a : gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

gtest_main.a : gtest-all.o gtest_main.o
	$(AR) $(ARFLAGS) $@ $^


sort.o : $(USER_DIR)/sort.cpp $(USER_DIR)/sort.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/sort.cpp

sort_test.o : $(USER_DIR)/sort_test.cpp \
                     $(USER_DIR)/sort.h $(GTT_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/sort_test.cpp

sort_test : sort.o sort_test.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@
