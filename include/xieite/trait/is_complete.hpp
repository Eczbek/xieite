#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_COMPLETE
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_COMPLETE
#
#	include <type_traits>

namespace DETAIL_XIEITE::is_complete {
	template<typename T, auto>
	constexpr bool impl = requires { ([]<typename U, auto = sizeof(U)>(std::type_identity<U>) {})(std::type_identity<T>()); };
}

namespace xieite {
	template<typename T, auto = [] {}>
	concept is_complete = DETAIL_XIEITE::is_complete::impl<T, [] {}>;
}

#endif
