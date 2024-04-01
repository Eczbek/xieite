#ifndef XIEITE_HEADER_TYPES_WRAPPER
#	define XIEITE_HEADER_TYPES_WRAPPER

namespace xieite::types {
	template<typename Type_>
	struct Wrapper {
		using Type = Type_;
	};
}

#endif
