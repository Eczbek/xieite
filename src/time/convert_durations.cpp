export module xieite:time.convertDurations;

import std;
import :concepts.Duration;

export namespace xieite::time {
	template<xieite::concepts::Duration Source, xieite::concepts::Duration... Targets>
	[[nodiscard]] constexpr std::tuple<Targets...> convertDurations(Source duration) noexcept {
		std::tuple<Targets...> results;
		(..., ([&duration, &results] {
			const Targets result = std::chrono::duration_cast<Targets>(duration);
			std::get<Targets>(results) = result;
			duration -= result;
		})());
		return results;
	}
}

// Stolen from orlac (https://github.com/vorlac)
