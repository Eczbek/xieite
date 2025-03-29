#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_SPEC
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_SPEC
#
#	include <type_traits>
#	include "../trait/rm_cv.hpp"

namespace DETAIL_XIEITE::is_spec {
	template<typename, template<typename...> typename>
	constexpr bool impl = false;

	template<typename T, template<typename...> typename M, typename... Args>
	constexpr bool impl<M<Args...>, M> = true;
}

namespace xieite {
	template<typename T, template<typename...> typename... Ms>
	concept is_spec = (... && DETAIL_XIEITE::is_spec::impl<xieite::rm_cv<T>, Ms>);
}

#endif

// TODO: Remove after `std::specialization_of<>` is implemented
