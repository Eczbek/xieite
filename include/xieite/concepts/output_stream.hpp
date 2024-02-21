#ifndef XIEITE_HEADER_CONCEPTS_OUTPUT_STREAM
#	define XIEITE_HEADER_CONCEPTS_OUTPUT_STREAM

#	include <concepts>
#	include <ostream>
#	include <type_traits>

namespace xieite::concepts {
	template<typename Type>
	concept OutputStream = std::same_as<std::remove_cvref_t<Type>, std::ostream> || std::derived_from<std::remove_cvref_t<Type>, std::ostream>;
}

#endif
