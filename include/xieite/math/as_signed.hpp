#ifndef DETAIL_XIEITE_HEADER_MATH_AS_SIGNED
#	define DETAIL_XIEITE_HEADER_MATH_AS_SIGNED
#
#	include "../trait/is_arith.hpp"
#	include "../trait/try_signed.hpp"

namespace xieite {
	inline constexpr auto as_signed = []<xieite::is_arith Arith>(Arith x) /* static */ noexcept {
		return static_cast<xieite::try_signed<Arith>>(x);
	};
}

#endif

// https://gcc.gnu.org/bugzilla/show_bug.cgi?id=121900
