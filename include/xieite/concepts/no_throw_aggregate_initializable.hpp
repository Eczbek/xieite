#ifndef XIEITE_HEADER_CONCEPTS_NO_THROW_AGGREGATE_INITIALIZABLE
#	define XIEITE_HEADER_CONCEPTS_NO_THROW_AGGREGATE_INITIALIZABLE

namespace xieite::concepts {
	template<typename Type, typename... Arguments>
	concept NoThrowAggregateInitializable = requires(Arguments... arguments) {
		Type { arguments... };
		requires(noexcept(Type { arguments... }));
	};
}

#endif
