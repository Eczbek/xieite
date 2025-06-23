#ifndef DETAIL_XIEITE_HEADER_PP_AS
#	define DETAIL_XIEITE_HEADER_PP_AS
#
#	include <cstddef>
#	include "../pp/arrow.hpp"
#	include "../pp/fwd.hpp"
#
#	define XIEITE_AS ->*DETAIL_XIEITE::AS::impl()->*::new(DETAIL_XIEITE::AS::impl())

namespace DETAIL_XIEITE::AS {
	template<typename T>
	struct proxy {
		T&& x;

		template<typename U>
		[[nodiscard]] constexpr auto operator->*(U*)
			XIEITE_ARROW(static_cast<U>(XIEITE_FWD(this->x)))
	};

	struct impl {
		explicit impl() = default;

		friend constexpr auto operator->*(auto&& x, DETAIL_XIEITE::AS::impl) noexcept {
			return DETAIL_XIEITE::AS::proxy(XIEITE_FWD(x));
		}
	};
}

constexpr void* operator new(std::size_t, DETAIL_XIEITE::AS::impl) noexcept {
	return nullptr;
}

#endif
