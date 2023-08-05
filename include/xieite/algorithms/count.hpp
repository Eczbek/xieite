#ifndef XIEITE_HEADER__ALGORITHMS__COUNT
#	define XIEITE_HEADER__ALGORITHMS__COUNT

#	include <cstddef>

namespace xieite::algorithms {
	template<typename... Values>
	[[nodiscard]]
	constexpr std::size_t count(const Values&...) noexcept {
		return sizeof...(Values);
	}
}

#endif
