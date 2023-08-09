#ifndef XIEITE_HEADER__CONCEPTS__CONSTANT
#	define XIEITE_HEADER__CONCEPTS__CONSTANT

#	include <type_traits>

namespace xieite::concepts {
	template<typename Type>
	concept Constant = std::is_const_v<Type>;
}

#endif
