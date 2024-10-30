export module xieite:copy_volatile;

import :is_volatile;
import :maybe_volatile;

export namespace xieite {
	template<typename T, typename U>
	using copy_volatile = xieite::maybe_volatile<U, xieite::is_volatile<T>>;
}
