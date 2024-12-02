export module xieite:rot_swap;

import std;
import :is_nothrow_mv_assign;
import :is_nothrow_mv_ctor;
import :repeat;

export namespace xieite {
	template<std::size_t n = 1, typename... Args>
	constexpr std::tuple<Args&...> rot_swap(Args&... args)
	noexcept((... && (xieite::is_nothrow_mv_ctor<Args> && xieite::is_nothrow_mv_assign<Args>))) {
		static constexpr std::size_t size = sizeof...(Args);
		if constexpr (size && (n % size)) {
			static constexpr std::size_t m = n % size;
			if constexpr ((m == 1) || (size % m)) {
				auto temp = std::move(args...[0]);
				xieite::repeat<size - 1>([&args...]<std::size_t i> -> void {
					args...[i * m % size] = std::move(args...[(i * m % size + m) % size]);
				});
				args...[size - m] = std::move(temp);
			} else {
				xieite::repeat<m>([&args...]<std::size_t i> -> void {
					auto temp = std::move(args...[i]);
					xieite::repeat<size / m>([&args...]<std::size_t j> -> void {
						args...[i + j * m] = std::move(args...[(i + j * m + m) % size]);
					});
					args...[size - m + i] = std::move(temp);
				});
			}
		}
		return std::tie(args...);
	}
}
