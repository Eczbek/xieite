#ifndef XIEITE_HEADER_FUNCTORS_AGGREGATE_INITIALIZE
#	define XIEITE_HEADER_FUNCTORS_AGGREGATE_INITIALIZE

#	include "../concepts/aggregate_initializable.hpp"
#	include "../concepts/no_throw_aggregate_initializable.hpp"
#	include "../macros/forward.hpp"

namespace xieite::functors {
	template<typename Type>
	struct AggregateInitialize {
		template<typename... Arguments>
		requires(xieite::concepts::AggregateInitializable<Type, Arguments...>)
		[[nodiscard]] constexpr Type operator()(Arguments&&... arguments) const
		noexcept(xieite::concepts::NoThrowAggregateInitializable<Type, Arguments...>) {
			return Type { XIEITE_FORWARD(arguments)... };
		}
	};
}

#endif
