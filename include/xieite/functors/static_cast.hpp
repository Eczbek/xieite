#ifndef XIEITE_HEADER_FUNCTORS_STATIC_CAST
#	define XIEITE_HEADER_FUNCTORS_STATIC_CAST

#	include <concepts>
#	include "../concepts/no_throw_convertible_to.hpp"

namespace xieite::functors {
	template<typename TypeFrom, typename TypeTo>
	requires(std::convertible_to<TypeFrom, TypeTo>)
	[[nodiscard]] constexpr TypeTo staticCast(TypeFrom&& value)
	noexcept(xieite::concepts::NoThrowConvertibleTo<TypeFrom, TypeTo>) {
		return static_cast<TypeTo>(value);
	}
}

#endif
