add_library(duckdb_constraints OBJECT check_constraint.cpp not_null_constraint.cpp parsed_constraint.cpp)
set(ALL_OBJECT_FILES ${ALL_OBJECT_FILES} $<TARGET_OBJECTS:duckdb_constraints> PARENT_SCOPE)
