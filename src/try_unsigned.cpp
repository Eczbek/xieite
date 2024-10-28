export module xieite:try_unsigned;

import std;

export namespace xieite {
	template<typename T>
	using try_unsigned = std::conditional_t<std::signed_integral<T>, std::make_unsigned<T>, std::type_identity<T>>::type;
}
