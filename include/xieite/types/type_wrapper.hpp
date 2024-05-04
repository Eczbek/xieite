#ifndef XIEITE_HEADER_TYPES_TYPE_WRAPPER
#   define XIEITE_HEADER_TYPES_TYPE_WRAPPER

namespace xieite::types {
	template<typename Type_>
	struct TypeWrapper {
		using Type = Type_;
	};
}

#endif
