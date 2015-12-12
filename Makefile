CXXFLAGS=-std=c++11 -g

test_graph: test_graph.cpp graph.hpp
	${CXX} ${CXXFLAGS} test_graph.cpp -o bin/$@
	
test_subsets: test_subsets.cpp subsets.hpp
	${CXX} ${CXXFLAGS} test_subsets.cpp -o bin/$@

test_ford_fulkerson: test_ford_fulkerson.cpp ford_fulkerson.hpp
	${CXX} ${CXXFLAGS} test_ford_fulkerson.cpp -o bin/$@

test_edge_connectivity: test_edge_connectivity.cpp edge_connectivity.hpp edge_connectivity.cpp
	${CXX} ${CXXFLAGS} edge_connectivity.cpp test_edge_connectivity.cpp -o bin/$@

test_connectivity_all: test_connectivity_all.cpp edge_connectivity.hpp edge_connectivity.cpp
	${CXX} ${CXXFLAGS} edge_connectivity.cpp test_connectivity_all.cpp -o bin/$@

.PHONY: run_tests
run_tests:
	for x in ./bin/*; do ./$$x; done
