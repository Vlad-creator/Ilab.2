CXX = g++
CXXFLAGS = -lgtest -lgtest_main -lpthread

all:
	@ $(CXX) Matrix/main.cpp -o Matrix/main $(CXXFLAGS)
	@ $(CXX) test_gen/gtest.cpp -o test_gen/gtest $(CXXFLAGS)
	@ $(CXX) test_gen/gtest_e2e.cpp -o test_gen/gtest_e2e $(CXXFLAGS)

main:
	@ $(CXX) Matrix/main.cpp -o Matrix/main $(CXXFLAGS)

gtest:
	@ $(CXX) test_gen/gtest.cpp -o test_gen/gtest $(CXXFLAGS)

gtest_e2e:
	@ $(CXX) test_gen/gtest_e2e.cpp -o test_gen/gtest_e2e $(CXXFLAGS)
