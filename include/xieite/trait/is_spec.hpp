#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_SPEC
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_SPEC
#
#	include <type_traits>

namespace xieite {
	template<typename T, template<typename...> typename... Ms>
	concept is_spec = (... && requires { ([]<typename... Args>(std::type_identity<Ms<Args...>>) {})(std::type_identity<T>()); });
}

#endif

// TODO: Remove after `std::specialization_of<>` is implemented
