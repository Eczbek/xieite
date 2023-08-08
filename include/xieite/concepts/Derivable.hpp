#ifndef XIEITE_HEADER__CONCEPTS__DERIVABLE
#	define XIEITE_HEADER__CONCEPTS__DERIVABLE

#	include <type_traits>

namespace xieite::concepts {
	template<typename Type>
	concept Derivable = std::is_class_v<Type> && !std::is_final_v<Type>;
}

#endif
