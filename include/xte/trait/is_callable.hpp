#ifndef DETAIL_XTE_HEADER_TRAIT_IS_CALLABLE
#	define DETAIL_XTE_HEADER_TRAIT_IS_CALLABLE
#
#	include "../meta/fake.hpp"
#	include "../trait/is_castable.hpp"

namespace DETAIL_XTE::is_callable {
	template<typename, typename>
	constexpr bool impl = false;

	template<typename T, typename Return, typename... Args>
	constexpr bool impl<T, Return(Args...)> = requires {
		{ xte::fake<T>()(xte::fake<Args>()...) } -> xte::is_castable<Return>;
	};

	template<typename T, typename Return, typename... Args>
	constexpr bool impl<T, Return(Args...) noexcept> = requires {
		{ xte::fake<T>()(xte::fake<Args>()...) } noexcept -> xte::is_castable<Return>;
	};
}

namespace xte {
	template<typename T, typename Signature>
	concept is_callable = DETAIL_XTE::is_callable::impl<T, Signature>;
}

#endif
