#ifndef XIEITE_HEADER_FUNCTIONS_OPERATORSUFFIX
#	define XIEITE_HEADER_FUNCTIONS_OPERATORSUFFIX

#	warning "'xietie::functions::OperatorSuffix' is deprecated"

#	include <xieite/functions/Suffix.hpp>

namespace xieite::functions {
	template<typename Any1, typename any2>
	struct OperatorSuffix
	: xieite::functions::Suffix<Any1, decltype(any2)> {
		[[deprecated]]
		constexpr OperatorSuffix() noexcept
		: xieite::functions::Suffix<Any1, decltype(any2)>(any2) {}
	};
}

#endif
