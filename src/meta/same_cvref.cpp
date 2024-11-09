export module xieite:same_cvref;

import :same_const;
import :same_ref;
import :same_volat;

export namespace xieite {
	template<typename T, typename U>
	using same_cvref = xieite::same_ref<T, xieite::same_volat<T, xieite::same_const<T, U>>>;
}
