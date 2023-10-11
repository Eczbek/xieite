#ifndef XIEITE_HEADER_CONCEPTS_OUTPUT_STREAM
#	define XIEITE_HEADER_CONCEPTS_OUTPUT_STREAM

#	include <concepts>
#	include <ostream>

namespace xieite::concepts {
	template<typename Type>
	concept OutputStream = std::same_as<Type, std::ostream> || std::derived_from<Type, std::ostream>;
}

#endif
