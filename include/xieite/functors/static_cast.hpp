#ifndef XIEITE_HEADER_FUNCTORS_STATIC_CAST
#	define XIEITE_HEADER_FUNCTORS_STATIC_CAST

#	include <concepts>
#	include "../concepts/no_throw_convertible_to.hpp"
#	include "../macros/forward.hpp"

namespace xieite::functors {
	template<typename Target_>
	struct StaticCast {
		template<std::convertible_to<Target_> Source_>
		constexpr Target_ operator()(Source_&& value) const
		noexcept(xieite::concepts::NoThrowConvertibleTo<Source_, Target_>) {
			return static_cast<Target_>(XIEITE_FORWARD(value));
		}
	};
}

#endif
