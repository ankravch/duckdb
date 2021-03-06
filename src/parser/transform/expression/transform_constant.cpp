#include "parser/expression/constant_expression.hpp"
#include "parser/transformer.hpp"

using namespace duckdb;
using namespace postgres;
using namespace std;

unique_ptr<ParsedExpression> Transformer::TransformValue(postgres::Value val) {
	switch (val.type) {
	case T_Integer:
		assert(val.val.ival <= numeric_limits<int32_t>::max());
		return make_unique<ConstantExpression>(SQLType(SQLTypeId::INTEGER), Value::INTEGER((int32_t)val.val.ival));
	case T_BitString: // FIXME: this should actually convert to BLOB
	case T_String:
		return make_unique<ConstantExpression>(SQLType(SQLTypeId::VARCHAR), Value(string(val.val.str)));
	case T_Float:
		return make_unique<ConstantExpression>(SQLType(SQLTypeId::DOUBLE), Value(stod(string(val.val.str))));
	case T_Null:
		return make_unique<ConstantExpression>(SQLType(SQLTypeId::SQLNULL), Value());
	default:
		throw NotImplementedException("Value not implemented!");
	}
}

unique_ptr<ParsedExpression> Transformer::TransformConstant(A_Const *c) {
	return TransformValue(c->val);
}
