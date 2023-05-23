#ifndef XIEITE_HEADER_CONCEPTS_ENUMERATOR
#	define XIEITE_HEADER_CONCEPTS_ENUMERATOR

#	include <type_traits>

namespace xieite::concepts {
	template<typename Any>
	concept Enumerator = std::is_enum_v<Any>;
}

#endif
