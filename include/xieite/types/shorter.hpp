#ifndef XIEITE_HEADER_TYPES_SHORTER
#	define XIEITE_HEADER_TYPES_SHORTER

#	include <concepts>
#	include <cstdint>
#	include <stdfloat>
#	include <type_traits>
#	include "../concepts/numeric.hpp"
#	include "../concepts/same_as_any.hpp"
#	include "../math/signed_128.hpp"
#	include "../math/unsigner_128.hpp"
#	include "../types/list.hpp"

namespace xieite::types {
	template<typename Type>
	requires((xieite::concepts::Numeric<Type> || xieite::concepts::SameAsAny<std::remove_cvref_t<Type>, xieite::math::Unsigned128, xieite::math::Signed128>) && !std::same_as<std::remove_cvref_t<Type>, std::bfloat16_t>)
	using Shorter = xieite::types::List<std::uint64_t, std::int64_t, std::uint32_t, std::int32_t, std::uint16_t, std::int16_t, std::uint8_t, std::int8_t, bool, bool, long double, std::float64_t, std::float32_t, std::float16_t, std::bfloat16_t>::At<xieite::types::List<xieite::math::Unsigned128, xieite::math::Signed128, std::uint64_t, std::int64_t, std::uint32_t, std::int32_t, std::uint16_t, std::int16_t, std::uint8_t, std::int8_t, std::float128_t, long double, std::float64_t, std::float32_t, std::float16_t>::find<std::remove_cvref_t<Type>>>;
}

#endif
