#ifndef XIEITE_HEADER_TYPES_PLACEHOLDER
#	define XIEITE_HEADER_TYPES_PLACEHOLDER

namespace xieite::types {
	struct Placeholder {
		template<typename... Arguments>
		constexpr Placeholder(Arguments&&...) noexcept {}

		template<typename Type>
		constexpr operator Type&() const & noexcept;

		template<typename Type>
		constexpr operator Type&&() const && noexcept;
	};
}

#endif
