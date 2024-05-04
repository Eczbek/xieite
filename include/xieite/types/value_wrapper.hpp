#ifndef XIEITE_HEADER_TYPES_VALUE_WRAPPER
#   define XIEITE_HEADER_TYPES_VALUE_WRAPPER

namespace xieite::types {
	template<auto value_>
	struct ValueWrapper {
		static constexpr auto value = value_;
	};
}

#endif
