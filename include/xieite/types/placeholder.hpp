#ifndef XIEITE_HEADER_TYPES_PLACEHOLDER
#	define XIEITE_HEADER_TYPES_PLACEHOLDER

namespace xieite::types {
	struct Placeholder {
		template<typename... Arguments_>
		constexpr Placeholder(Arguments_&&...) noexcept {}

		template<typename Type_>
		operator Type_&() const & noexcept;

		template<typename Type_>
		operator Type_&&() const && noexcept;
	};
}

#endif
