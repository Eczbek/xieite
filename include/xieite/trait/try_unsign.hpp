#ifndef DETAIL_XIEITE_HEADER_TRAIT_TRY_UNSIGN
#	define DETAIL_XIEITE_HEADER_TRAIT_TRY_UNSIGN
#
#	include <concepts>
#	include <type_traits>

namespace xieite {
	template<typename T>
	using try_unsign = std::conditional_t<std::signed_integral<T>, std::make_unsigned<T>, std::type_identity<T>>::type;
}

#endif
