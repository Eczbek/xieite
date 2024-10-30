export module xieite:copy_cvref;

import :copy_const;
import :copy_ref;
import :copy_volatile;

export namespace xieite {
	template<typename T, typename U>
	using copy_cvref = xieite::copy_ref<T, xieite::copy_volatile<T, xieite::copy_const<T, U>>>;
}
