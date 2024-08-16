#ifndef XIEITE_HEADER_CONTAINERS_FORWARD_TUPLE
#	define XIEITE_HEADER_CONTAINERS_FORWARD_TUPLE

#	include <tuple>
#	include "../concepts/specialization_of.hpp"
#	include "../macros/forward.hpp"

namespace xieite::containers {
	template<xieite::concepts::SpecializationOf<std::tuple> Tuple>
	[[nodiscard]] constexpr auto forwardTuple(Tuple&& tuple) noexcept {
		return std::apply([](auto&&... values) -> auto {
			return std::forward_as_tuple(XIEITE_FORWARD(values)...);
		}, XIEITE_FORWARD(tuple));
	}
}

#endif
