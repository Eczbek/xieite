export module xieite:types.CollapseReference;

import std;
import :types.CopyConstant;
import :types.CopyVolatile;

export namespace xieite::types {
	template<typename Source, typename Target>
	using CollapseReference = xieite::types::CopyVolatile<Source, xieite::types::CopyConstant<Source, std::conditional_t<std::is_lvalue_reference_v<Source>, std::add_lvalue_reference_t<Target>, std::add_rvalue_reference_t<Target>>>>;
}
