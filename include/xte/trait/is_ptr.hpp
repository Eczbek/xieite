#ifndef DETAIL_XTE_HEADER_TRAIT_IS_PTR
#	define DETAIL_XTE_HEADER_TRAIT_IS_PTR
#
#	include "../meta/fold.hpp"
#	include "../trait/remove_ptr.hpp"
#	include "../trait/remove_ref.hpp"
#	include "../util/types.hpp"

namespace DETAIL_XTE {
	template<typename>
	constexpr bool is_ptr = false;

	template<typename T>
	constexpr bool is_ptr<T*> = true;

	template<typename T>
	constexpr bool is_ptr<T* const> = true;

	template<typename T>
	constexpr bool is_ptr<T* volatile> = true;

	template<typename T>
	constexpr bool is_ptr<T* const volatile> = true;
}

namespace xte {
	template<typename T, xte::uz depth = 0>
	concept is_ptr = DETAIL_XTE::is_ptr<typename[:xte::fold<[]<auto x> {
		return ^^xte::remove_ptr<typename[:x:]>;
	}, ^^xte::remove_ref<T>, depth>:]>;
}

#endif
