#ifndef XIEITE_HEADER_TYPES_LONGER
#	define XIEITE_HEADER_TYPES_LONGER

#	include <concepts>
#	include <cstdint>
#	include <stdfloat>
#	include <type_traits>
#	include "../concepts/arithmetic.hpp"
#	include "../math/signed_128.hpp"
#	include "../math/unsigned_128.hpp"
#	include "../types/list.hpp"

namespace xieite::types {
	template<xieite::concepts::Arithmetic Type>
	requires(!std::same_as<std::remove_cvref_t<Type>, std::float128_t>)
	using Longer = xieite::types::List<std::uint8_t, std::uint16_t, std::int16_t, std::uint32_t, std::int32_t, std::uint64_t, std::int64_t, xieite::math::Unsigned128, xieite::math::Signed128, std::float16_t, std::float32_t, std::float64_t, long double, std::float128_t>::At<xieite::types::List<bool, std::uint8_t, std::int8_t, std::uint16_t, std::int16_t, std::uint32_t, std::int32_t, std::uint64_t, std::int64_t, std::bfloat16_t, std::float16_t, std::float32_t, std::float64_t, long double>::find<std::remove_cvref_t<Type>>>;
}

#endif
