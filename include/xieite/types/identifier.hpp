#ifndef XIEITE_HEADER_TYPES_IDENTIFIER
#	define XIEITE_HEADER_TYPES_IDENTIFIER

#	include <cstddef>
#	include "../functors/counter.hpp"

namespace xieite::detail {
	inline constexpr auto typeIdentifierCounterTag = [] {};
}

namespace xieite::types {
	template<typename>
	inline constexpr std::size_t identifier = xieite::functors::counter<xieite::detail::typeIdentifierCounterTag, [] {}>();
}

#endif
