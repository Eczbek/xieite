#ifndef XIEITE_HEADER_CONCEPTS_STREAMABLEOUT
#	define XIEITE_HEADER_CONCEPTS_STREAMABLEOUT

#	include <concepts>
#	include <ostream>

namespace xieite::concepts {
	template<typename Any>
	concept StreamableOut = requires(std::ostream& outputStream, Any value) {
		{ outputStream << value } -> std::convertible_to<std::ostream&>;
	};
}

// Thanks to fux for original code

#endif
