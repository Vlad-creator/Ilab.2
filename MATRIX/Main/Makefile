CXX = g++
CXXFLAGS = -lgtest -lgtest_main -lpthread

all:
	@ $(CXX) -o main main_matrix.cpp $(CXXFLAGS)
	@ $(CXX) -o ../tests/check ../tests/check_answer.cpp $(CXXFLAGS)
	@ $(CXX) -o ../tests/e2e_tests ../tests/E2E_tests.cpp $(CXXFLAGS)
	@ $(CXX) -o ../tests/unit_tests ../tests/test_matrix.cpp $(CXXFLAGS)
main:
	@ $(CXX) -o main main_matrix.cpp $(CXXFLAGS)
unit_tests:
	@ $(CXX) -o ../tests/unit_tests ../tests/test_matrix.cpp $(CXXFLAGS)
e2e_tests:
	@ $(CXX) -o ../tests/check ../tests/check_answer.cpp $(CXXFLAGS)
	@ $(CXX) -o ../tests/e2e_tests ../tests/E2E_tests.cpp $(CXXFLAGS)




