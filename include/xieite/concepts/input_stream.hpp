#ifndef XIEITE_HEADER_CONCEPTS_INPUT_STREAM
#	define XIEITE_HEADER_CONCEPTS_INPUT_STREAM

#	include <concepts>
#	include <istream>
#	include <type_traits>

namespace xieite::concepts {
	template<typename Type_>
	concept InputStream = std::same_as<std::remove_cvref_t<Type_>, std::istream> || std::derived_from<std::remove_cvref_t<Type_>, std::istream>;
}

#endif
