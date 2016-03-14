FILE(GLOB TEST_SUITES test_*.cpp)
add_executable (test_all
    run.cpp
    ${TEST_SUITES}
    extraordinary_graphs.cpp
    ${SRC}/edge_connectivity.cpp
    ${SRC}/graph_common.cpp
    ${SRC}/flow.cpp
    ${SRC}/load_graph.cpp
    ${SRC}/mixed_paths.cpp
    ${SRC}/connectivity_pairs.cpp
    ${SRC}/path.cpp
)
