#ifndef DETAIL_XIEITE_HEADER_DATA_FIND_MOST_CONSEC_IF
#	define DETAIL_XIEITE_HEADER_DATA_FIND_MOST_CONSEC_IF
#
#	include <functional>
#	include <ranges>
#	include "../trait/is_lref_invoc.hpp"
#	include "../trait/is_noex_lref_invoc.hpp"
#	include "../trait/is_noex_range.hpp"

namespace xieite {
	template<
		std::ranges::forward_range Range,
		xieite::is_lref_invoc<bool(
			std::ranges::subrange<std::ranges::iterator_t<Range>>
		)> Pred
	> [[nodiscard]] constexpr std::ranges::subrange<std::ranges::iterator_t<Range>>
	find_most_consec_if(
		Range& range,
		std::ranges::range_size_t<Range> subrange_size,
		Pred&& pred = {}
	) noexcept(
		xieite::is_noex_range<Range>
		&& xieite::is_noex_lref_invoc<Pred, bool(
			std::ranges::subrange<std::ranges::iterator_t<Range>>
		)>
	) {
		auto most_begin = std::ranges::end(range);
		auto most_end = most_begin;
		std::ranges::range_size_t<Range> most_consec = 0;

		auto current_begin = std::ranges::begin(range);
		std::ranges::range_size_t<Range> current_consec = 0;

		auto begin = current_begin;
		auto end = begin;
		// FIXME: Explicitly compare i-- against 0?
		for (auto i = subrange_size; i--; ++end) {
			if (end == std::ranges::end(range)) {
				return std::ranges::subrange(end, end);
			}
		}
		while (true) {
			// NOTE(Hurubon): I added this variable.
			const auto slice = std::ranges::subrange(begin, end);
			const bool match = std::invoke_r<bool>(pred, slice);
			// FIXME(Hurubon): if (match && ++current_consec > most_consec)
			if (match) {
				if (++current_consec > most_consec) {
					most_begin = current_begin;
					most_end = end;
					most_consec = current_consec;
				}
			}
			// FIXME(Hurubon): Explicitly compare i-- against 0?
			for (auto i = match ? subrange_size : 1; i--; ) {
				if (end == std::ranges::end(range)) {
					return std::ranges::subrange(most_begin, most_end);
				}
				// FIXME(Hurubon): Put these in the iteration step of the for loop?
				++begin;
				++end;
			}
			if (!match) {
				current_begin = begin;
				current_consec = 0;
			}
		};
	}

	template<
		std::ranges::forward_range Range,
		xieite::is_lref_invoc<bool(
			std::ranges::range_common_reference_t<Range>
		)> Pred = std::identity
	> [[nodiscard]] constexpr std::ranges::subrange<std::ranges::iterator_t<Range>>
	find_most_consec_if(
		Range& range,
		Pred&& pred = {}
	) noexcept(
		xieite::is_noex_range<Range>
		&& xieite::is_noex_lref_invoc<Pred, bool(
			std::ranges::range_common_reference_t<Range>
		)>
	) {
		return xieite::find_most_consec_if(
			range,
			1,
			// FIXME(Hurubon): Make an alias for this lambda?
			[&](auto&& subrange) {
				return std::invoke_r<bool>(pred, subrange.front());
			}
		);
	}
}

#endif
