export module xieite:types.CollapseReference;

import std;

export namespace xieite::types {
	template<typename Source, typename Target>
	using CollapseReference = std::conditional_t<std::is_lvalue_reference_v<Source>, Target&, std::conditional_t<std::is_rvalue_reference_v<Source>, Target&&, Target>>;
}
