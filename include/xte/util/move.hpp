#ifndef DETAIL_XTE_HEADER_UTIL_MOVE
#	define DETAIL_XTE_HEADER_UTIL_MOVE
#
#	include "../trait/remove_ref.hpp"

namespace xte {
	template<typename T>
	[[nodiscard]] constexpr xte::remove_ref<T>&& move(T&& x) noexcept {
		return static_cast<xte::remove_ref<T>&&>(x);
	}
}

#endif
