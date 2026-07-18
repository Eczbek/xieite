#ifndef DETAIL_XTE_HEADER_TRAIT_IS_CALLABLE
#	define DETAIL_XTE_HEADER_TRAIT_IS_CALLABLE
#
#	include "../meta/fake.hpp"
#	include "../trait/is_castable.hpp"

namespace DETAIL_XTE::is_callable {
	template<typename, typename>
	constexpr bool impl = false;

	template<typename T, typename return_type, typename... arg_types>
	constexpr bool impl<T, return_type(arg_types...)> = requires {
		{ xte::fake<T>()(xte::fake<arg_types>()...) } -> xte::is_castable<return_type>;
	};

	template<typename T, typename return_type, typename... arg_types>
	constexpr bool impl<T, return_type(arg_types...) noexcept> = requires {
		{ xte::fake<T>()(xte::fake<arg_types>()...) } noexcept -> xte::is_castable<return_type>;
	};
}

namespace xte {
	template<typename T, typename signature_type>
	concept is_callable = DETAIL_XTE::is_callable::impl<T, signature_type>;
}

#endif
