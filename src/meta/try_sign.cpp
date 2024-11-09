export module xieite:try_sign;

import std;
import :is_uint;

export namespace xieite {
	template<typename T>
	using try_sign = std::conditional_t<xieite::is_uint<T>, std::make_signed<T>, std::type_identity<T>>::type;
}
