#ifndef DETAIL_XIEITE_HEADER_META_DECAY_AS_TUPLE
#	define DETAIL_XIEITE_HEADER_META_DECAY_AS_TUPLE
#
#	include <tuple>
#	include <type_traits>
#	include "../pp/fwd.hpp"

namespace xieite {
	template<typename... Args>
	[[nodiscard]] constexpr std::tuple<std::decay_t<Args>...> decay_as_tuple(Args&&... args) noexcept {
		return std::tuple<std::decay_t<Args>...>(XIEITE_FWD(args)...);
	}
}

#endif
