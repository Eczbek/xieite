export module xieite:conv_dur;

import std;
import :is_dur;

export namespace xieite {
	template<xieite::is_dur T, xieite::is_dur... Us>
	[[nodiscard]] constexpr std::tuple<Us...> conv_dur(T dur) noexcept {
		std::tuple<Us...> results;
		(..., (dur -= std::get<Us>(results) = std::chrono::duration_cast<Us>(dur)));
		return results;
	}
}

// Stolen from orlac (https://github.com/vorlac)
