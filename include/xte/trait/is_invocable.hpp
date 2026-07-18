#ifndef DETAIL_XTE_HEADER_TRAIT_IS_INVOCABLE
#	define DETAIL_XTE_HEADER_TRAIT_IS_INVOCABLE
#
#	include <type_traits>

namespace DETAIL_XTE::is_invocable {
	template<typename, typename>
	constexpr bool impl = false;

	template<typename T, typename return_type, typename... arg_types>
	constexpr bool impl<T, return_type(arg_types...)> = std::is_invocable_r_v<return_type, T, arg_types...>;
}

namespace xte {
	template<typename T, typename signature_type>
	concept is_invocable = DETAIL_XTE::is_invocable::impl<T, signature_type>;
}

#endif
