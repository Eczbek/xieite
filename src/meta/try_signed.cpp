export module xieite:try_signed;

import std;
import :is_uint;

export namespace xieite {
	template<typename T>
	using try_signed = std::conditional_t<xieite::is_uint<T>, std::make_signed<T>, std::type_identity<T>>::type;
}
