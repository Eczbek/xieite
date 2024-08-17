#ifndef XIEITE_HEADER_CONCEPTS_AGGREGATE_INITIALIZABLE
#	define XIEITE_HEADER_CONCEPTS_AGGREGATE_INITIALIZABLE

namespace xieite::concepts {
	template<typename Type, typename... Arguments>
	concept AggregateInitializable = requires(Arguments... arguments) {
		Type { arguments... };
	};
}

#endif
