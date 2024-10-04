export module xieite:functors.templatify;

import std;

export namespace xieite::functors {
	constexpr void templatify(auto lambda, const std::uint8_t value) {
		([lambda, value]<std::size_t... i>(std::index_sequence<i...>) {
			(..., [lambda, value] {
				static constexpr std::uint8_t index = static_cast<std::uint8_t>(i);
				if (value == index) {
					lambda.template operator()<index>();
				}
			});
		})(std::make_index_sequence<(1uz << std::numeric_limits<std::uint8_t>::digits)>());
	}
}
