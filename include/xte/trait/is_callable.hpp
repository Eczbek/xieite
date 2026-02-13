#ifndef DETAIL_XTE_HEADER_TRAIT_IS_CALLABLE
#	define DETAIL_XTE_HEADER_TRAIT_IS_CALLABLE
#
#	include "../meta/fake.hpp"
#	include "../trait/is_castable.hpp"

namespace DETAIL_XTE {
	template<typename, typename>
	constexpr bool is_callable = false;

	template<typename T, typename Return, typename... Args>
	constexpr bool is_callable<T, Return(Args...)> = requires {
		{ xte::fake<T>()(xte::fake<Args>()...) } -> xte::is_castable<Return>;
	};
}

namespace xte {
	template<typename T, typename Signature>
	concept is_callable = DETAIL_XTE::is_callable<T, Signature>;
}

#endif
