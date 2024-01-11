#ifndef XIEITE_HEADER_TYPES_LONGER_INTEGER
#	define XIEITE_HEADER_TYPES_LONGER_INTEGER

#	include <concepts>
#	include <cstdint>
#	include <type_traits>

namespace xieite::types {
	template<std::integral Type>
	using LongerInteger = std::conditional_t<std::same_as<Type, bool>, std::uint8_t, std::conditional_t<std::same_as<Type, std::uint8_t>, std::uint16_t, std::conditional_t<std::same_as<Type, std::int8_t>, std::int16_t, std::conditional_t<std::same_as<Type, std::uint16_t>, std::uint32_t, std::conditional_t<std::same_as<Type, std::int16_t>, std::int32_t, std::conditional_t<std::unsigned_integral<Type>, std::uint64_t, std::int64_t>>>>>>;
}

#endif
