//===----------------------------------------------------------------------===//
//                         DuckDB
//
// common/enums/order_type.hpp
//
//
//===----------------------------------------------------------------------===//

#pragma once

#include "common/constants.hpp"

namespace duckdb {

enum class OrderType : uint8_t { INVALID = 0, ASCENDING = 1, DESCENDING = 2 };

}
