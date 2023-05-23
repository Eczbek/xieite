#ifndef XIEITE_HEADER_CONCEPTS_COPYASSIGNABLE
#	define XIEITE_HEADER_CONCEPTS_COPYASSIGNABLE

#	include <type_traits>

namespace xieite::concepts {
	template<typename Any>
	concept CopyAssignable = std::is_copy_assignable_v<Any>;
}

#endif
