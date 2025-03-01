#pragma once

#include <functional>
#include <ranges>
#include "../ctnr/findmostconsecif.hpp"
#include "../pp/fn.hpp"
#include "../trait/isinvoc.hpp"
#include "../trait/isnoexinvoc.hpp"
#include "../trait/isnoexrange.hpp"

namespace x4 {
	template<std::ranges::forward_range R, x4::isinvoc<bool(std::ranges::range_common_reference_t<R>, std::ranges::range_common_reference_t<R>)> F = std::ranges::equal_to>
	requires(std::ranges::sized_range<R>)
	[[nodiscard]] constexpr std::ranges::subrange<std::ranges::iterator_t<R>> findmostconsec(R& range, std::ranges::range_common_reference_t<R> value, F&& cmp = {})
	noexcept(x4::isnoexinvoc<F, bool(std::ranges::range_common_reference_t<R>, std::ranges::range_common_reference_t<R>)> && x4::isnoexrange<R>) {
		return x4::findmostconsecif(range, X4FNLOC(std::invoke_r<bool>(cmp, value, $0)));
	}
}
