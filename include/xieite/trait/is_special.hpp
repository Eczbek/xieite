#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_SPECIAL
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_SPECIAL
#
#	include "../meta/type_id.hpp"
#	include "../trait/rm_cv.hpp"

namespace xieite {
	template<typename T, template<typename...> typename... Templates>
	concept is_special = (... && requires { ([]<typename... Args>(xieite::type_id<Templates<Args...>>) {})(xieite::type_id<xieite::rm_cv<T>>()); });
}

#endif

// https://cplusplus.github.io/CWG/issues/2988.html
// TODO: Remove after `std::specialization_of<>` is implemented
