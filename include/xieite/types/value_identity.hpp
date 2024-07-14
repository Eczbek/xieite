#ifndef XIEITE_HEADER_TYPES_VALUE_IDENTITY
#   define XIEITE_HEADER_TYPES_VALUE_IDENTITY

namespace xieite::types {
	template<auto value_>
	struct ValueIdentity {
		static constexpr auto value = value_;
	};
}

#endif
