#ifndef XIEITE_HEADER_TYPES_ANYTHING
#	define XIEITE_HEADER_TYPES_ANYTHING

namespace xieite::types {
	struct Anything final {
		template<typename Any>
		constexpr operator Any&() const noexcept;

		template<typename Any>
		constexpr operator Any&&() const noexcept;
	};
}

#endif
