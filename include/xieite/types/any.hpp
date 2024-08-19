#ifndef XIEITE_HEADER_TYPES_ANY
#	define XIEITE_HEADER_TYPES_ANY

namespace xieite::types {
	struct Any {
		explicit(false) Any(auto&&...) noexcept;

		explicit(false) operator decltype(auto)() const noexcept;
	};
}

#endif
