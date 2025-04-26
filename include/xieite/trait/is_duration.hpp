#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_DURATION
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_DURATION
#
#	include <chrono>
#	include <type_traits>
#	include "../trait/is_arith.hpp"
#	include "../trait/is_ratio.hpp"
#	include "../trait/rm_cv.hpp"

namespace xieite {
	template<typename T>
	concept is_duration = requires { ([]<xieite::is_arith Arith0, xieite::is_ratio Arith1>(std::type_identity<std::chrono::duration<Arith0, Arith1>>) {})(std::type_identity<xieite::rm_cv<T>>()); };
}

#endif

// https://cplusplus.github.io/CWG/issues/2988.html
