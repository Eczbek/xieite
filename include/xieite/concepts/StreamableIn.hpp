#ifndef XIEITE_HEADER_CONCEPTS_STREAMABLEIN
#	define XIEITE_HEADER_CONCEPTS_STREAMABLEIN

#	include <concepts>
#	include <istream>

namespace xieite::concepts {
	template<typename Any>
	concept StreamableIn = requires(std::istream& inputStream, Any value) {
		{ inputStream >> value } -> std::convertible_to<std::istream&>;
	};
}

#endif
