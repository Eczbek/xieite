#ifndef XIEITE_HEADER_MATH_ATTEMPTSIGN
#	define XIEITE_HEADER_MATH_ATTEMPTSIGN

#	include <concepts>
#	include <type_traits>

namespace xieite::math {
	template<typename Any>
	using AttemptSign = std::conditional_t<std::unsigned_integral<Any>, std::make_signed<Any>, std::type_identity<Any>>::type;
}

#endif
