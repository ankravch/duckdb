add_library(duckdb_query_node OBJECT select_node.cpp set_operation_node.cpp)
set(ALL_OBJECT_FILES ${ALL_OBJECT_FILES} $<TARGET_OBJECTS:duckdb_query_node> PARENT_SCOPE)
