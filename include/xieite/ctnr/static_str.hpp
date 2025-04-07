#ifndef DETAIL_XIEITE_HEADER_CTNR_STATIC_STR
#	define DETAIL_XIEITE_HEADER_CTNR_STATIC_STR
#
#	include <string>
#	include "../ctnr/fixed_str.hpp"

namespace xieite {
	template<xieite::fixed_str fstr, typename Traits = std::char_traits<typename decltype(fstr)::value_type>>
	constexpr auto static_str = fstr.template view<Traits>();
}

#endif
