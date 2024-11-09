export module xieite:same_volat;

import :is_volat;
import :set_volat;

export namespace xieite {
	template<typename T, typename U>
	using same_volat = xieite::set_volat<U, xieite::is_volat<T>>;
}
