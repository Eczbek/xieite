#ifndef XIEITE_HEADER_TYPES_ANY
#	define XIEITE_HEADER_TYPES_ANY

namespace xieite::types {
	struct Any {
		explicit(false) Any(auto&&...) noexcept;

		template<typename Type>
		explicit(false) constexpr operator Type&() const & noexcept;

		template<typename Type>
		explicit(false) constexpr operator Type&&() const && noexcept;
	};
}

#endif
