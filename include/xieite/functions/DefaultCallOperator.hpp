#ifndef XIEITE_HEADER_FUNCTIONS_OPTIONALCALLOPERATOR
#	define XIEITE_HEADER_FUNCTIONS_OPTIONALCALLOPERATOR

#	include <concepts>
#	include <xieite/concepts/Derivable.hpp>
#	include <xieite/types/Anything.hpp>

namespace xieite::functions {
	template<xieite::concepts::Derivable Any>
	struct DefaultCallOperator
	: Any {
		constexpr DefaultCallOperator(const Any&) noexcept {}

		constexpr void operator()(xieite::types::Anything) const noexcept {}
	};

	template<xieite::concepts::Derivable Function>
	requires(std::invocable<Function, xieite::types::Anything>)
	struct DefaultCallOperator<Function>
	: Function {
		constexpr DefaultCallOperator(const Function& function) noexcept
		: Function(function) {}

		using Function::operator();
	};
}

#endif
