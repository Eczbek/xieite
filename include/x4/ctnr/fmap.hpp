#pragma once

#include <array>
#include <concepts>
#include <functional>
#include <initializer_list>
#include <memory>
#include <stdexcept>
#include <ranges>
#include <unordered_map>
#include <utility>
#include "../ctnr/mkarr.hpp"
#include "../pp/fwd.hpp"

namespace x4 {
	template<typename K, typename V, std::size_t size, typename Hash = std::hash<K>, typename Cmp = std::ranges::equal_to, typename Alloc = std::allocator<std::pair<const K, V*>>>
	struct fmap {
	public:
		[[nodiscard]] fmap() = default;

		template<std::ranges::input_range R>
		requires(std::convertible_to<std::ranges::range_value_t<R>, std::pair<K, V>>)
		[[nodiscard]] explicit constexpr fmap(R&& entries) noexcept
		: array(x4::mkarr<std::pair<K, V>, size>(X4FWD(entries))) {}

		[[nodiscard]] explicit(false) constexpr fmap(std::initializer_list<std::pair<K, V>> entries) noexcept
		: array(x4::mkarr<std::pair<K, V>, size>(entries)) {}

		template<typename Self, std::convertible_to<K> KRef>
		[[nodiscard]] constexpr auto&& operator[](this Self&& self, KRef&& key) noexcept(false) {
			auto* value = X4FWD(self).get_val(X4FWD(key));
			if (!value) {
				throw std::out_of_range("must not access nonexistent key");
			}
			return std::forward_like<Self>(*value);
		}

		template<typename Self, std::convertible_to<K> KRef>
		[[nodiscard]] constexpr auto&& at(this Self&& self, KRef&& key) noexcept(false) {
			return std::forward_like<Self>(self[X4FWD(key)]);
		}

		template<std::convertible_to<K> KRef>
		[[nodiscard]] constexpr bool has(KRef&& key) const noexcept {
			return !!this->get_val(X4FWD(key));
		}

		[[nodiscard]] constexpr const std::array<std::pair<K, V>, size>& data() const noexcept {
			return this->array;
		}

	private:
		std::array<std::pair<K, V>, size> array;

		template<typename Map = std::unordered_map<K, V*, Hash, Cmp, Alloc>>
		[[nodiscard]] Map& get_map() const noexcept {
			static Map map = ([this] -> Map {
				Map map;
				map.reserve(this->array.size());
				for (const std::pair<K, V>& entry : this->array) {
					map.emplace(std::make_pair(entry.first, const_cast<V*>(std::addressof(entry.second))));
				}
				return map;
			})();
			return map;
		}

		template<typename Self, std::convertible_to<K> KRef>
		[[nodiscard]] constexpr auto* get_val(this Self&& self, KRef&& key) noexcept {
			if consteval {
				Cmp cmp;
				for (auto&& entry : self.array) {
					if (std::invoke(cmp, entry.first, key)) {
						return &entry.second;
					}
				}
				return nullptr;
			} else {
				return self.get_map().at(X4FWD(key));
			}
		}
	};
}
