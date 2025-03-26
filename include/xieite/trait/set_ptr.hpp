#ifndef DETAIL_XIEITE_HEADER_TRAIT_SET_PTR
#	define DETAIL_XIEITE_HEADER_TRAIT_SET_PTR
#
#	include <cstddef>
#	include "../trait/add_ptr.hpp"
#	include "../trait/rm_ptr.hpp"

namespace xieite {
	template<typename T, std::size_t n = 1>
	using set_ptr = xieite::add_ptr<xieite::rm_ptr<T, -1uz>, n>;
}

#endif
