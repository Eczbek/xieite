export module xieite:is_cvref;

import :is_cvlref;
import :is_cvrref;

export namespace xieite {
	template<typename T>
	concept is_cvref = xieite::is_cvlref<T> || xieite::is_cvrref<T>;
}
