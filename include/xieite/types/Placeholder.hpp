#ifndef XIEITE_HEADER__TYPES__PLACEHOLDER
#	define XIEITE_HEADER__TYPES__PLACEHOLDER

namespace xieite::types {
	struct Placeholder {
		template<typename Type>
		constexpr operator Type&() const noexcept;

		template<typename Type>
		constexpr operator Type&&() const noexcept;
	};
}

#endif
