#ifndef DETAIL_XIEITE_HEADER_TRAIT_ADD_PTR
#	define DETAIL_XIEITE_HEADER_TRAIT_ADD_PTR
#
#	include <cstddef>
#	include <type_traits>
#	include "../meta/fold_for.hpp"

namespace DETAIL_XIEITE::add_ptr {
	inline constexpr auto impl = []<typename T, auto> {
		return std::add_pointer<typename T::type>();
	};
}

namespace xieite {
	template<typename T, std::size_t depth = 1>
	using add_ptr = xieite::fold_for<DETAIL_XIEITE::add_ptr::impl, std::remove_reference<T>, depth>;
}

#endif
