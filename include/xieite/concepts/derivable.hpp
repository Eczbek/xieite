#ifndef XIEITE_HEADER_CONCEPTS_DERIVABLE
#	define XIEITE_HEADER_CONCEPTS_DERIVABLE

#	include <type_traits>

namespace xieite::concepts {
	template<typename Type_>
	concept Derivable = !std::is_final_v<Type_>;
}

#endif
