add_executable (test_all_paths test_all_paths.cpp
    ${PROJECT_SOURCE_DIR}/path.cpp)

add_executable (test_connectivity_all test_connectivity_all.cpp
    ${PROJECT_SOURCE_DIR}/edge_connectivity.cpp
    ${PROJECT_SOURCE_DIR}/flow.cpp)

add_executable (test_edge_connectivity test_edge_connectivity.cpp
    ${PROJECT_SOURCE_DIR}/edge_connectivity.cpp
    ${PROJECT_SOURCE_DIR}/flow.cpp)

add_executable (test_ford_fulkerson test_ford_fulkerson.cpp
    ${PROJECT_SOURCE_DIR}/flow.cpp)

add_executable (test_graph test_graph.cpp)

add_executable (test_mixed_paths test_mixed_paths.cpp
    ${PROJECT_SOURCE_DIR}/mixed_paths.cpp
    ${PROJECT_SOURCE_DIR}/edge_connectivity.cpp
    ${PROJECT_SOURCE_DIR}/path.cpp
    ${PROJECT_SOURCE_DIR}/flow.cpp)

add_executable (test_subsets test_subsets.cpp)
