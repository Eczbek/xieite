#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_DUR
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_DUR
#
#	include <chrono>
#	include <type_traits>
#	include "../trait/is_arith.hpp"
#	include "../trait/is_ratio.hpp"
#	include "../trait/rm_cv.hpp"

namespace DETAIL_XIEITE::is_dur {
	template<typename>
	constexpr bool impl = false;

	template<xieite::is_arith T, xieite::is_ratio U>
	constexpr bool impl<std::chrono::duration<T, U>> = true;
}

namespace xieite {
	template<typename T>
	concept is_dur = DETAIL_XIEITE::is_dur::impl<xieite::rm_cv<T>>;
}

#endif
