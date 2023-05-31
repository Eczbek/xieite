#ifndef XIEITE_HEADER_FUNCTIONS_OPERATORPREFIX
#	define XIEITE_HEADER_FUNCTIONS_OPERATORPREFIX

#	warning "'xietie::functions::OperatorPrefix' is deprecated"

#	include <xieite/functions/Prefix.hpp>

namespace xieite::functions {
	template<typename Any1, typename any2>
	struct OperatorPrefix
	: xieite::functions::Prefix<Any1, decltype(any2)> {
		[[deprecated]]
		constexpr OperatorPrefix() noexcept
		: xieite::functions::Prefix<Any1, decltype(any2)>(any2) {}
	};
}

#endif
