#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_SPECIAL
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_SPECIAL
#
#	include <type_traits>
#	include "../trait/rm_cv.hpp"

namespace xieite {
	template<typename T, template<typename...> typename... Templates>
	concept is_special = (... && requires { ([]<typename... Args>(std::type_identity<Templates<Args...>>) {})(std::type_identity<xieite::rm_cv<T>>()); });
}

#endif

// https://cplusplus.github.io/CWG/issues/2988.html
// TODO: Remove after `std::specialization_of<>` is implemented
