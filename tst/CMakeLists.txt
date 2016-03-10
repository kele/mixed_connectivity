add_executable (test_all_paths test_all_paths.cpp
    ${SRC}/path.cpp)

add_executable (test_connectivity_all test_connectivity_all.cpp
    ${SRC}/edge_connectivity.cpp
    ${SRC}/flow.cpp)

add_executable (test_edge_connectivity test_edge_connectivity.cpp
    ${SRC}/edge_connectivity.cpp
    ${SRC}/flow.cpp)

add_executable (test_ford_fulkerson test_ford_fulkerson.cpp
    ${SRC}/flow.cpp)

add_executable (test_graph test_graph.cpp)

add_executable (test_mixed_paths test_mixed_paths.cpp
    ${SRC}/mixed_paths.cpp
    ${SRC}/edge_connectivity.cpp
    ${SRC}/path.cpp
    ${SRC}/flow.cpp)

add_executable (test_subsets test_subsets.cpp)

add_executable (test_load_graph test_load_graph.cpp 
    ${SRC}/load_graph.cpp
    ${SRC}/load_graph.hpp
    )
