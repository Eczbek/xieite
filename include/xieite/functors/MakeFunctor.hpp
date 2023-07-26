#ifndef XIEITE_HEADER_FUNCTORS_MAKEFUNCTOR
#	define XIEITE_HEADER_FUNCTORS_MAKEFUNCTOR

#	include <concepts>
#	include <xieite/concepts/Derivable.hpp>
#	include <xieite/types/Anything.hpp>

namespace xieite::functors {
	template<xieite::concepts::Derivable Any>
	struct MakeFunctor
	: Any {
		constexpr MakeFunctor(const Any&) noexcept {}

		constexpr void operator()(xieite::types::Anything) const noexcept {}
	};

	template<xieite::concepts::Derivable Function>
	requires std::invocable<Function, xieite::types::Anything>
	struct MakeFunctor<Function>
	: Function {
		constexpr MakeFunctor(const Function& function) noexcept
		: Function(function) {}

		using Function::operator();
	};
}

#endif
