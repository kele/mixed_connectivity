CXXFLAGS=-std=c++11 -g

test_graph: test_graph.cpp graph.hpp
	${CXX} ${CXXFLAGS} test_graph.cpp -o $@
	
test_subsets: test_subsets.cpp subsets.hpp
	${CXX} ${CXXFLAGS} test_subsets.cpp -o $@
