#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_SPECIAL
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_SPECIAL
#
#	include "../meta/wrap_type.hpp"
#	include "../trait/rm_cv.hpp"

namespace xieite {
	template<typename T, template<typename...> typename... Templates>
	concept is_special = (... && requires { ([]<typename... Args>(xieite::wrap_type<Templates<Args...>>) {})(xieite::wrap_type<xieite::rm_cv<T>>()); });
}

#endif

// https://cplusplus.github.io/CWG/issues/2988.html
// TODO: Remove after `std::specialization_of<>` is implemented
