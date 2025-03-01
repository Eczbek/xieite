#pragma once

#include <cstddef>
#include <tuple>
#include <utility>
#include "../fn/repeat.hpp"
#include "../trait/hasnoexmvass.hpp"
#include "../trait/hasnoexmvctor.hpp"

namespace x4 {
	template<std::size_t n = 1, typename... Args>
	constexpr std::tuple<Args&...> rot_swap(Args&... args)
	noexcept((... && (x4::hasnoexmvctor<Args> && x4::hasnoexmvass<Args>))) {
		static constexpr std::size_t size = sizeof...(Args);
		if constexpr (size && (n % size)) {
			static constexpr std::size_t m = n % size;
			if constexpr ((m == 1) || (size % m)) {
				auto temp = std::move(args...[0]);
				x4::repeat<size - 1>([&args...]<std::size_t i> -> void {
					args...[i * m % size] = std::move(args...[(i * m % size + m) % size]);
				});
				args...[size - m] = std::move(temp);
			} else {
				x4::repeat<m>([&args...]<std::size_t i> -> void {
					auto temp = std::move(args...[i]);
					x4::repeat<size / m>([&args...]<std::size_t j> -> void {
						args...[i + j * m] = std::move(args...[(i + j * m + m) % size]);
					});
					args...[size - m + i] = std::move(temp);
				});
			}
		}
		return std::tie(args...);
	}
}
