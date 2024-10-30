export module xieite:is_ostream;

import std;

export namespace xieite {
	template<typename T>
	concept is_ostream = std::same_as<std::remove_cv_t<T>, std::ostream> || std::derived_from<std::remove_cv_t<T>, std::ostream>;
}
