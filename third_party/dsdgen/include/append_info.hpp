#pragma once

#include "main/appender.hpp"
#include <memory>

namespace tpcds {

struct tpcds_table_def {
	const char *name;
	int fl_small;
	int fl_child;
};

#define CALL_CENTER 0
#define DBGEN_VERSION 24

struct tpcds_append_information {
	tpcds_append_information(duckdb::DuckDB &db, std::string schema_name, std::string table_name) : 
		appender(db, schema_name, table_name) {}

	duckdb::Appender appender;
	tpcds_table_def table_def;
	size_t col;
	size_t row;
};

} // namespace tpcds
