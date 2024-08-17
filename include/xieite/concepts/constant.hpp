#ifndef XIEITE_HEADER_CONCEPTS_CONSTANT
#	define XIEITE_HEADER_CONCEPTS_CONSTANT

#	include <type_traits>

namespace xieite::concepts {
	template<typename Type>
	concept Constant = std::is_const_v<std::remove_reference_t<Type>>;
}

#endif
