#ifndef XIEITE_HEADER_ALGORITHMS_COUNT
#	define XIEITE_HEADER_ALGORITHMS_COUNT

#	include <cstddef>

namespace xieite::algorithms {
	template<typename... Values>
	[[nodiscard]]
	constexpr std::size_t count(const Values&... values) noexcept {
		return sizeof...(values);
	}
}

#endif
