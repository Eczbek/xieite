#ifndef XIEITE_HEADER_CONCEPTS_TRIVIAL
#	define XIEITE_HEADER_CONCEPTS_TRIVIAL

#	include <type_traits>

namespace xieite::concepts {
	template<typename Any>
	concept Trivial = std::is_trivial_v<Any>;
}

#endif
