#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_STREAM
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_STREAM
#
#	include "../trait/is_istream.hpp"
#	include "../trait/is_ostream.hpp"

namespace xieite {
	template<typename T>
	concept is_stream = xieite::is_istream<T> || xieite::is_ostream<T>;
}

#endif
