//===----------------------------------------------------------------------===//
//                         DuckDB
//
// excel-extension.hpp
//
//
//===----------------------------------------------------------------------===//

#pragma once

#include "duckdb.hpp"
#include "duckdb/main/client_context.hpp"

namespace duckdb {

class EXCELExtension : public Extension {
public:
	void Load(DuckDB &db) override;
	std::string Name() override;
};

} // namespace duckdb