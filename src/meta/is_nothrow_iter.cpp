export module xieite:is_nothrow_iter;

import std;

export namespace xieite {
	template<typename T>
	concept is_nothrow_iter =
		std::input_or_output_iterator<T>
		&& std::is_nothrow_constructible_v<T, T>
		&& std::is_nothrow_assignable_v<T&, T>
		&& std::is_nothrow_cast_v<T, T>
		&& requires(T it) {
			requires(noexcept(++it));
			requires(noexcept(--it));
			requires(noexcept(it++));
			requires(noexcept(it--));
			requires(noexcept(*it));
		};
}
