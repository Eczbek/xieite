export module xieite:rotate_swap;

import std;
import :repeat;

export namespace xieite {
	template<std::size_t n = 1, typename... Args>
	constexpr std::tuple<Args&...> rotate_swap(Args&... args)
	noexcept((... && (std::is_nothrow_move_constructible_v<Args> && std::is_nothrow_move_assignable_v<Args>))) {
		static constexpr std::size_t size = sizeof...(Args);
		auto args_tuple = std::tie(args...);
		if constexpr (size && (n % size)) {
			static constexpr std::size_t m = n % size;
			if constexpr ((m == 1) || (size % m)) {
				auto temp = std::move(std::get<0>(args_tuple));
				xieite::repeat<size - 1>([&args_tuple]<std::size_t i> -> void {
					std::get<i * m % size>(args_tuple) = std::move(std::get<(i * m % size + m) % size>(args_tuple));
				});
				std::get<size - m>(args_tuple) = std::move(temp);
			} else {
				xieite::repeat<m>([&args_tuple]<std::size_t i> -> void {
					auto temp = std::move(std::get<i>(args_tuple));
					xieite::repeat<size / m>([&args_tuple]<std::size_t j> -> void {
						std::get<i + j * m>(args_tuple) = std::move(std::get<(i + j * m + m) % size>(args_tuple));
					});
					std::get<size - m + i>(args_tuple) = std::move(temp);
				});
			}
		}
		return args_tuple;
	}
}
