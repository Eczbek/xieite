#ifndef XIEITE_HEADER_CONCEPTS_INPUT_STREAM
#	define XIEITE_HEADER_CONCEPTS_INPUT_STREAM

#	include <concepts>
#	include <istream>
#	include <type_traits>

namespace xieite::concepts {
	template<typename Type>
	concept InputStream = std::same_as<std::remove_cvref_t<Type>, std::istream> || std::derived_from<std::remove_cvref_t<Type>, std::istream>;
}

#endif
