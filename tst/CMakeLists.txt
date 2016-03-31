set(SOURCES
    run.cpp
    extraordinary_graphs.cpp
    ${SRC}/edge_connectivity.cpp
    ${SRC}/graph_common.cpp
    ${SRC}/flow.cpp
    ${SRC}/load_graph.cpp
    ${SRC}/mixed_paths.cpp
    ${SRC}/connectivity_pairs.cpp
    ${SRC}/path.cpp)


file(GLOB TEST_SUITES test_*.cpp)
add_executable (test_all
    ${TEST_SUITES}
    ${SOURCES}
)
set_target_properties(test_all PROPERTIES COMPILE_FLAGS "-DDEBUG")

file(GLOB PERF_TEST_SUITES perf_test_*.cpp)
add_executable (test_perf
    ${PERF_TEST_SUITES}
    ${SOURCES}
)
