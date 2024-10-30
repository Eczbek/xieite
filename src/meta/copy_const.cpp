export module xieite:copy_const;

import :is_const;
import :maybe_const;

export namespace xieite {
	template<typename T, typename U>
	using copy_const = xieite::maybe_const<U, xieite::is_const<T>>;
}
