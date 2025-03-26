#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_STREAMABLE_IN
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_STREAMABLE_IN
#
#	include <concepts>
#	include <istream>

namespace xieite {
	template<typename T>
	concept is_streamable_in = requires (T x, std::istream istream) {
		{ istream >> x } -> std::convertible_to<std::istream&>;
	};
}

#endif
