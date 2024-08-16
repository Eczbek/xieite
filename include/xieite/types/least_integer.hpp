#ifndef XIEITE_HEADER_TYPES_LEAST_INTEGER
#	define XIEITE_HEADER_TYPES_LEAST_INTEGER

#	include <cstddef>
#	include <cstdint>
#	include <type_traits>
#	include "../bits/size.hpp"
#	include "../types/list.hpp"

namespace xieite::detail {
	template<std::size_t bits>
	struct LeastIntegerSelector {
		template<typename Type, typename...>
		struct Type
		: std::bool_constant<(bits <= xieite::bits::size<Type>)> {};
	};
}

namespace xieite::types {
	template<std::size_t bits>
	using LeastInteger = xieite::types::List<std::uint_least8_t, std::uint_least16_t, std::uint_least32_t, std::uint_least64_t>::Filter<xieite::detail::LeastIntegerSelector<bits>::template Type>::template At<0>;
}

#endif
