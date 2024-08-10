#ifndef XIEITE_HEADER_TYPES_ANY
#	define XIEITE_HEADER_TYPES_ANY

namespace xieite::types {
	struct Any {
		Any(auto&&...) noexcept;

		template<typename Type_>
		explicit(false) constexpr operator Type_&() const & noexcept;

		template<typename Type_>
		explicit(false) constexpr operator Type_&&() const && noexcept;
	};
}

#endif
