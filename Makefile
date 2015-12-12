CXXFLAGS=-std=c++11 -g -I.

bin/test_graph: tst/test_graph.cpp graph.hpp bin
	${CXX} ${CXXFLAGS} tst/test_graph.cpp -o $@
	
bin/test_subsets: tst/test_subsets.cpp subsets.hpp bin
	${CXX} ${CXXFLAGS} tst/test_subsets.cpp -o $@

bin/test_ford_fulkerson: tst/test_ford_fulkerson.cpp ford_fulkerson.hpp bin
	${CXX} ${CXXFLAGS} tst/test_ford_fulkerson.cpp -o $@

bin/test_edge_connectivity: tst/test_edge_connectivity.cpp edge_connectivity.hpp edge_connectivity.cpp bin
	${CXX} ${CXXFLAGS} edge_connectivity.cpp tst/test_edge_connectivity.cpp -o $@

bin/test_connectivity_all: tst/test_connectivity_all.cpp edge_connectivity.hpp edge_connectivity.cpp bin
	${CXX} ${CXXFLAGS} edge_connectivity.cpp tst/test_connectivity_all.cpp -o $@

bin:
	mkdir bin

clean:
	rm -rf bin

.PHONY: run_tests
run_tests:
	for x in ./bin/*; do ./$$x; done
