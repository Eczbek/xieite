export module xieite:same_const;

import :is_const;
import :set_const;

export namespace xieite {
	template<typename T, typename U>
	using same_const = xieite::set_const<U, xieite::is_const<T>>;
}
