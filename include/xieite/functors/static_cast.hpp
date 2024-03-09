#ifndef XIEITE_HEADER_FUNCTORS_STATIC_CAST
#	define XIEITE_HEADER_FUNCTORS_STATIC_CAST

#	include <concepts>
#	include "../concepts/no_throw_convertible_to.hpp"
#	include "../macros/forward.hpp"

namespace xieite::functors {
	template<typename Target>
	struct StaticCast {
		template<std::convertible_to<Target> Source>
		constexpr Target operator()(Source&& value) const
		noexcept(xieite::concepts::NoThrowConvertibleTo<Source, Target>) {
			return static_cast<Target>(XIEITE_FORWARD(value));
		}
	};
}

#endif
