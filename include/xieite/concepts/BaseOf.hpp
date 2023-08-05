#ifndef XIEITE_HEADER__CONCEPTS__BASE_OF
#	define XIEITE_HEADER__CONCEPTS__BASE_OF

#	include <type_traits>

namespace xieite::concepts {
	template<typename Base, typename Derived>
	concept BaseOf = std::is_base_of_v<Base, Derived>;
}

#endif
