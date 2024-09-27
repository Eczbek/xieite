export module xieite:types.CopyReference;

import std;

export namespace xieite::types {
	template<typename Source, typename Target>
	using CopyReference = std::conditional_t<std::is_lvalue_reference_v<Source>, std::add_lvalue_reference_t<std::remove_reference_t<Target>>, std::conditional_t<std::is_rvalue_reference_v<Source>, std::add_rvalue_reference_t<std::remove_reference_t<Target>>, std::type_identity_t<std::remove_reference_t<Target>>>>;
}
