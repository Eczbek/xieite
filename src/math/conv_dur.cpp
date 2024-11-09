export module xieite:conv_dur;

import std;
import :is_dur;

export namespace xieite {
	template<xieite::is_dur T, xieite::is_dur... Us>
	[[nodiscard]] constexpr std::tuple<Us...> conv_dur(T dur) noexcept {
		std::tuple<Us...> results;
		(..., ([&dur, &results] -> void {
			const Us result = std::chrono::duration_cast<Us>(dur);
			std::get<Us>(results) = result;
			dur -= result;
		})());
		return results;
	}
}

// Stolen from orlac (https://github.com/vorlac)
