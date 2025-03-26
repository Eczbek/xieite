#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_DUR
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_DUR
#
#	include <chrono>
#	include <type_traits>
#	include "../trait/is_arith.hpp"
#	include "../trait/is_ratio.hpp"
#	include "../trait/rm_cv.hpp"

namespace xieite {
	template<typename T>
	concept is_dur = requires { ([]<xieite::is_arith U, xieite::is_ratio V>(std::type_identity<std::chrono::duration<U, V>>) {})(std::type_identity<xieite::rm_cv<T>>()); };
}

#endif
