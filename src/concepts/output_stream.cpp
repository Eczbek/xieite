export module xieite:concepts.OutputStream;

import std;

export namespace xieite::concepts {
	template<typename Type>
	concept OutputStream = std::same_as<std::remove_cv_t<Type>, std::ostream> || std::derived_from<std::remove_cv_t<Type>, std::ostream>;
}
