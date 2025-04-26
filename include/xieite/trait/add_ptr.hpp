#ifndef DETAIL_XIEITE_HEADER_TRAIT_ADD_PTR
#	define DETAIL_XIEITE_HEADER_TRAIT_ADD_PTR
#
#	include <cstddef>
#	include <type_traits>
#	include "../fn/unroll.hpp"
#	include "../meta/fold.hpp"

namespace DETAIL_XIEITE::add_ptr {
	template<typename T, std::size_t depth>
	struct impl : decltype(xieite::unroll<depth>([]<std::size_t... i> static {
		return xieite::fold<
			[]<typename U, typename> static {
				return std::add_pointer<typename U::type>();
			},
			std::remove_reference<T>,
			decltype(i)...
		>();
	})) {};
}

namespace xieite {
	template<typename T, std::size_t depth = 1>
	using add_ptr = DETAIL_XIEITE::add_ptr::impl<T, depth>::type;
}

#endif
