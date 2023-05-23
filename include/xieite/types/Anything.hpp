#ifndef XIEITE_HEADER_TYPES_ANYTHING
#	define XIEITE_HEADER_TYPES_ANYTHING

namespace xieite::types {
	struct Anything final {
		template<typename Any>
		constexpr operator Any&();

		template<typename Any>
		constexpr operator Any&&();
	};
}

#endif
