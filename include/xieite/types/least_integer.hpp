#ifndef XIEITE_HEADER_TYPES_LEAST_INTEGER
#	define XIEITE_HEADER_TYPES_LEAST_INTEGER

#	include <cstddef>
#	include <cstdint>
#	include <type_traits>
#	include "../bits/size.hpp"
#	include "../types/list.hpp"

namespace xieite::detail {
	template<std::size_t bits_>
	struct LeastIntegerSelector {
		template<typename Type_, typename...>
		struct Type
		: std::bool_constant<(bits_ <= xieite::bits::size<Type_>)> {};
	};
}

namespace xieite::types {
	template<std::size_t bits_>
	using LeastInteger = xieite::types::List<std::uint_least8_t, std::uint_least16_t, std::uint_least32_t, std::uint_least64_t>::Filter<xieite::detail::LeastIntegerSelector<bits_>::template Type>::template At<0>;
}

#endif
