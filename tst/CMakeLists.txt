FILE(GLOB TEST_SUITES test_*.cpp)
add_executable (test_all
    run.cpp
    ${TEST_SUITES}
    ${SRC}/edge_connectivity.cpp
    ${SRC}/flow.cpp
    ${SRC}/load_graph.cpp
    ${SRC}/mixed_paths.cpp
    ${SRC}/path.cpp
)
