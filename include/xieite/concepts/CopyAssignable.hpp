#ifndef XIEITE_HEADER__CONCEPTS__COPY_ASSIGNABLE
#	define XIEITE_HEADER__CONCEPTS__COPY_ASSIGNABLE

#	include <type_traits>

namespace xieite::concepts {
	template<typename Type>
	concept CopyAssignable = std::is_copy_assignable_v<Type>;
}

#endif
