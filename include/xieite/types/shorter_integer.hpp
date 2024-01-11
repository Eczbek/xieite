#ifndef XIEITE_HEADER_TYPES_SHORTER_INTEGER
#	define XIEITE_HEADER_TYPES_SHORTER_INTEGER

#	include <concepts>
#	include <cstdint>
#	include <type_traits>

namespace xieite::types {
	template<std::integral Type>
	using ShorterInteger = std::conditional_t<std::same_as<Type, std::uint64_t>, std::uint32_t, std::conditional_t<std::same_as<Type, std::int64_t>, std::int32_t, std::conditional_t<std::same_as<Type, std::uint32_t>, std::uint16_t, std::conditional_t<std::same_as<Type, std::int32_t>, std::int16_t, std::conditional_t<std::same_as<Type, std::uint16_t>, std::uint8_t, std::conditional_t<std::same_as<Type, std::int16_t>, std::int8_t, bool>>>>>>;
}

#endif
