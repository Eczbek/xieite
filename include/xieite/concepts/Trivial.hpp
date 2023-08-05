#ifndef XIEITE_HEADER__CONCEPTS__TRIVIAL
#	define XIEITE_HEADER__CONCEPTS__TRIVIAL

#	include <type_traits>

namespace xieite::concepts {
	template<typename Type>
	concept Trivial = std::is_trivial_v<Type>;
}

#endif
