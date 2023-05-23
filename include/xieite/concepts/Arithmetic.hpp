#ifndef XIEITE_HEADER_CONCEPTS_ARITHMETIC
#	define XIEITE_HEADER_CONCEPTS_ARITHMETIC

#	include <type_traits>

namespace xieite::concepts {
	template<typename Any>
	concept Arithmetic = std::is_arithmetic_v<Any>;
}

#endif
