#ifndef DETAIL_XIEITE_HEADER_PP_AS
#	define DETAIL_XIEITE_HEADER_PP_AS
#
#	include <new>
#	include "../pp/fwd.hpp"
#
#	define XIEITE_AS ->*DETAIL_XIEITE::AS::impl()->*::new(::std::nothrow)

namespace DETAIL_XIEITE::AS {
	template<typename T>
	struct proxy {
		T&& lhs;

		template<typename U>
		[[nodiscard]] constexpr auto operator->*(U* rhs) noexcept {
			delete rhs;
			return static_cast<U>(XIEITE_FWD(this->lhs));
		}
	};

	struct impl {
		friend constexpr auto operator->*(auto&& lhs, DETAIL_XIEITE::AS::impl) noexcept {
			return DETAIL_XIEITE::AS::proxy { XIEITE_FWD(lhs) };
		}
	};
}

#endif
