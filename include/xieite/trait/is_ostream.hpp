#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_OSTREAM
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_OSTREAM
#
#	include <concepts>
#	include <ostream>
#	include <type_traits>

namespace xieite {
	template<typename T>
	concept is_ostream = std::same_as<std::remove_cv_t<T>, std::ostream> || std::derived_from<std::remove_cv_t<T>, std::ostream>;
}

#endif
