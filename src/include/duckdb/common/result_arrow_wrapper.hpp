//===----------------------------------------------------------------------===//
//                         DuckDB
//
// duckdb/common/result_arrow_wrapper.hpp
//
//
//===----------------------------------------------------------------------===//

#pragma once

#include "duckdb/main/query_result.hpp"
#include "duckdb/common/arrow_wrapper.hpp"

namespace duckdb {
class ResultArrowArrayStreamWrapper {
public:
	explicit ResultArrowArrayStreamWrapper(unique_ptr<QueryResult> result, idx_t batch_size);
	ArrowArrayStream stream;
	unique_ptr<QueryResult> result;
	std::string last_error;
	idx_t batch_size;
	vector<LogicalType> column_types;
	vector<string> column_names;

private:
	static int MyStreamGetSchema(struct ArrowArrayStream *stream, struct ArrowSchema *out);
	static int MyStreamGetNext(struct ArrowArrayStream *stream, struct ArrowArray *out);
	static void MyStreamRelease(struct ArrowArrayStream *stream);
	static const char *MyStreamGetLastError(struct ArrowArrayStream *stream);
};
} // namespace duckdb