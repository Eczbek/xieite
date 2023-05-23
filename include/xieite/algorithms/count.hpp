#ifndef XIEITE_HEADER_ALGORITHMS_COUNT
#	define XIEITE_HEADER_ALGORITHMS_COUNT

#	include <cstddef>

namespace xieite::algorithms {
	[[nodiscard]]
	constexpr std::size_t count(const auto&... arguments) noexcept {
		return sizeof...(arguments);
	}
}

#endif
