#ifndef XIEITE_HEADER__TRAITS__IS_STREAMABLE_IN
#	define XIEITE_HEADER__TRAITS__IS_STREAMABLE_IN

#	include <concepts>
#	include <istream>
#	include <type_traits>

namespace xieite::traits {
	template<typename>
	struct IsStreamableIn
	: std::false_type {};

	template<typename Type>
	requires(requires(std::istream& inputStream, Type value) {
		{ inputStream >> value } -> std::convertible_to<std::istream&>;
	})
	struct IsStreamableIn<Type>
	: std::true_type {};
}

#endif
