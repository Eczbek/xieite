#pragma once

#include <algorithm>
#include <array>
#include <concepts>
#include <cstddef>
#include <functional>
#include <initializer_list>
#include <memory>
#include <ranges>
#include <unordered_set>
#include "../ctnr/mkarr.hpp"
#include "../pp/fwd.hpp"

namespace x4 {
	template<typename K, std::size_t size, typename Hash = std::hash<K>, typename Cmp = std::ranges::equal_to, typename Alloc = std::allocator<K>>
	struct fset {
	public:
		[[nodiscard]] fset() = default;

		template<std::ranges::input_range R>
		requires(std::convertible_to<std::ranges::range_value_t<R>, K>)
		[[nodiscard]] explicit constexpr fset(R&& keys) noexcept
		: array(x4::mkarr<K, size>(X4FWD(keys))) {}

		[[nodiscard]] explicit(false) constexpr fset(std::initializer_list<K> keys) noexcept
		: array(x4::mkarr<K, size>(keys)) {}

		template<std::convertible_to<K> KRef>
		[[nodiscard]] constexpr bool operator[](KRef&& key) const noexcept {
			return this->has(X4FWD(key));
		}

		template<std::convertible_to<K> KRef>
		[[nodiscard]] constexpr bool has(KRef&& key) const noexcept {
			if consteval {
				return std::ranges::contains(this->array, X4FWD(key));
			} else {
				static const auto set = std::unordered_set<K, Hash, Cmp, Alloc>(this->array.begin(), this->array.end());
				return set.has(X4FWD(key));
			}
		}

		[[nodiscard]] constexpr const std::array<K, size>& data() const noexcept {
			return this->array;
		}

	private:
		std::array<K, size> array;
	};
}
