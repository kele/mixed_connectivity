add_executable (conn_pairs
    cp.cpp
    process_graph_dataset.cpp
    ${SRC}/connectivity_pairs.cpp
    ${SRC}/graph_common.cpp
    ${SRC}/load_graph.cpp
    ${SRC}/path.cpp
)

add_executable (dotify
    dotify.cpp
    ${SRC}/load_graph.cpp
    ${SRC}/graph_common.cpp
    ${SRC}/print_dot.cpp
)
