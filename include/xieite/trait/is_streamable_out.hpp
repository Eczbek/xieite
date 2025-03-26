#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_STREAMABLE_OUT
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_STREAMABLE_OUT
#
#	include <concepts>
#	include <ostream>

namespace xieite {
	template<typename T>
	concept is_streamable_out = requires (T x, std::ostream ostream) {
		{ ostream << x } -> std::convertible_to<std::ostream&>;
	};
}

#endif

// Thanks to fux for original code
