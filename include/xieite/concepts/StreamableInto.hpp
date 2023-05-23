#ifndef XIEITE_HEADER_CONCEPTS_STREAMABLEINTO
#	define XIEITE_HEADER_CONCEPTS_STREAMABLEINTO

#	include <concepts>
#	include <istream>

namespace xieite::concepts {
	template<typename Any>
	concept StreamableInto = requires(std::istream& inputStream, Any value) {
		{ inputStream >> value } -> std::convertible_to<std::istream&>;
	};
}

#endif
