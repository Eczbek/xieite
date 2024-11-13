export module xieite:is_istream;

import std;

export namespace xieite {
	template<typename T>
	concept is_istream = std::same_as<std::remove_cv_t<T>, std::istream> || std::derived_from<std::remove_cv_t<T>, std::istream>;
}
