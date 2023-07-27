#ifndef XIEITE_HEADER_CONCEPTS_DERIVABLE
#	define XIEITE_HEADER_CONCEPTS_DERIVABLE

#	include <type_traits>

namespace xieite::concepts {
	template<typename Any>
	concept Derivable = std::is_class_v<Any> && !std::is_final_v<Any>;
}

// This is undefined behavior if the parameter type is incomplete (e.g. `struct Foo;`)

#endif
