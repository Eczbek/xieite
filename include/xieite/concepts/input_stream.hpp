#ifndef XIEITE_HEADER__CONCEPTS__INPUT_STREAM
#	define XIEITE_HEADER__CONCEPTS__INPUT_STREAM

#	include <concepts>
#	include <istream>

namespace xieite::concepts {
	template<typename Type>
	concept InputStream = std::same_as<Type, std::istream> || std::derived_from<Type, std::istream>;
}

#endif
