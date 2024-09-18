module;

#include <xieite/defer.hpp>
#include <xieite/evaluate.hpp>

export module xieite:containers.tupleify;

import std;
import :concepts.Aggregate;
import :types.arity;
import :types.CollapseReference;

#define XIEITE_TEMPORARY_GET($type, $count) _##$count
#define XIEITE_TEMPORARY_SET($type, $count) std::forward_like<xieite::types::CollapseReference<decltype(_##$count), $type>>(_##$count)

#define XIEITE_TEMPORARY_LOOP_OUTER($type, $value, ...) XIEITE_EVALUATE(XIEITE_TEMPORARY_LOOP_OUTER_HELPER($type, $value, __VA_ARGS__))
#define XIEITE_TEMPORARY_LOOP_OUTER_HELPER($type, $value, $first, ...) \
	__VA_OPT__(XIEITE_DEFER(XIEITE_TEMPORARY_LOOP_OUTER_INDIRECT)()($type, $value, __VA_ARGS__)) \
	else if constexpr (xieite::types::arity<$type> == ($first + 1)) { \
		auto&& [XIEITE_TEMPORARY_LOOP_INNER(XIEITE_TEMPORARY_GET, $type, $first, __VA_ARGS__)] = $value; \
		return std::make_tuple(XIEITE_TEMPORARY_LOOP_INNER(XIEITE_TEMPORARY_SET, $type, $first, __VA_ARGS__)); \
	}
#define XIEITE_TEMPORARY_LOOP_OUTER_INDIRECT() XIEITE_TEMPORARY_LOOP_OUTER_HELPER

#define XIEITE_TEMPORARY_LOOP_INNER($type, $macro, ...) XIEITE_TEMPORARY_LOOP_INNER_HELPER($type, $macro, __VA_ARGS__)
#define XIEITE_TEMPORARY_LOOP_INNER_HELPER($type, $macro, $first, ...) __VA_OPT__(XIEITE_DEFER(XIEITE_TEMPORARY_LOOP_INNER_INDIRECT)()($type, $macro, __VA_ARGS__),) $macro($type, $first)
#define XIEITE_TEMPORARY_LOOP_INNER_INDIRECT() XIEITE_TEMPORARY_LOOP_INNER_HELPER

namespace xieite::containers {
	template<xieite::concepts::Aggregate Structure>
	[[nodiscard]] constexpr auto tupleify(Structure&& value) noexcept {
		if constexpr (std::is_empty_v<Structure>) {
			return std::make_tuple();
		} XIEITE_TEMPORARY_LOOP_OUTER(Structure, value, 255, 254, 253, 252, 251, 250, 249, 248, 247, 246, 245, 244, 243, 242, 241, 240, 239, 238, 237, 236, 235, 234, 233, 232, 231, 230, 229, 228, 227, 226, 225, 224, 223, 222, 221, 220, 219, 218, 217, 216, 215, 214, 213, 212, 211, 210, 209, 208, 207, 206, 205, 204, 203, 202, 201, 200, 199, 198, 197, 196, 195, 194, 193, 192, 191, 190, 189, 188, 187, 186, 185, 184, 183, 182, 181, 180, 179, 178, 177, 176, 175, 174, 173, 172, 171, 170, 169, 168, 167, 166, 165, 164, 163, 162, 161, 160, 159, 158, 157, 156, 155, 154, 153, 152, 151, 150, 149, 148, 147, 146, 145, 144, 143, 142, 141, 140, 139, 138, 137, 136, 135, 134, 133, 132, 131, 130, 129, 128, 127, 126, 125, 124, 123, 122, 121, 120, 119, 118, 117, 116, 115, 114, 113, 112, 111, 110, 109, 108, 107, 106, 105, 104, 103, 102, 101, 100, 99, 98, 97, 96, 95, 94, 93, 92, 91, 90, 89, 88, 87, 86, 85, 84, 83, 82, 81, 80, 79, 78, 77, 76, 75, 74, 73, 72, 71, 70, 69, 68, 67, 66, 65, 64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)
	}
}

#undef XIEITE_TEMPORARY_GET
#undef XIEITE_TEMPORARY_SET
#undef XIEITE_TEMPORARY_LOOP_OUTER
#undef XIEITE_TEMPORARY_LOOP_OUTER_HELPER
#undef XIEITE_TEMPORARY_LOOP_OUTER_INDIRECT
#undef XIEITE_TEMPORARY_LOOP_INNER
#undef XIEITE_TEMPORARY_LOOP_INNER_HELPER
#undef XIEITE_TEMPORARY_LOOP_INNER_INDIRECT
