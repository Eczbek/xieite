#ifndef XIEITE_HEADER__TRAITS__IS_STREAMABLE_OUT
#	define XIEITE_HEADER__TRAITS__IS_STREAMABLE_OUT

#	include <concepts>
#	include <ostream>
#	include <type_traits>

namespace xieite::traits {
	template<typename>
	struct IsStreamableOut
	: std::false_type {};

	template<typename Type>
	requires(requires(std::ostream& outputStream, Type value) {
		{ outputStream << value } -> std::convertible_to<std::ostream&>;
	})
	struct IsStreamableOut<Type>
	: std::true_type {};
}

// Thanks to fux for original code

#endif
