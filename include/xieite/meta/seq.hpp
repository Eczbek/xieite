#ifndef DETAIL_XIEITE_HEADER_META_SEQ
#	define DETAIL_XIEITE_HEADER_META_SEQ
#
#	include "../trait/is_same.hpp"

namespace xieite {
	template<auto... i>
	requires(xieite::is_same<decltype(i)...>)
	struct seq {};
}

#endif
