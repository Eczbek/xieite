#ifndef XIEITE_HEADER_FUNCTIONS_OPERATORINFIX
#	define XIEITE_HEADER_FUNCTIONS_OPERATORINFIX

#	warning "'xietie::functions::OperatorInfix' is deprecated"

#	include <xieite/functions/Infix.hpp>

namespace xieite::functions {
	template<typename Any1, typename any2>
	struct OperatorInfix
	: xieite::functions::Infix<Any1, decltype(any2)> {
		[[deprecated]]
		constexpr OperatorInfix() noexcept
		: xieite::functions::Infix<Any1, decltype(any2)>(any2) {}
	};
}

#endif
