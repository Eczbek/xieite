#ifndef DETAIL_XTE_HEADER_DATA_FIXED_ARRAY
#	define DETAIL_XTE_HEADER_DATA_FIXED_ARRAY
#
#	include "../data/range_cmp.hpp"
#	include "../func/unfold.hpp"
#	include "../meta/wrap_value.hpp"
#	include "../preproc/arrow.hpp"
#	include "../preproc/fwd.hpp"
#	include "../trait/is_instance_of.hpp"
#	include "../trait/is_same.hpp"
#	include "../trait/is_same_ignore_cvref.hpp"
#	include "../util/like.hpp"
#	include "../util/numbers.hpp"
#	include <compare>
#	include <concepts>
#	include <iterator>
#	include <ranges>
#	include <tuple>
#	include <type_traits>

namespace xte {
	template<typename T, xte::uz n>
	struct fixed_array {
		using value_type = T;
		using size_type = xte::uz;
		using difference_type = xte::iptrdiff;
		using reference = T&;
		using const_reference = const T&;
		using pointer = T*;
		using const_pointer = const T*;
		using iterator = T*;
		using const_iterator = const T*;
		using reverse_iterator = std::reverse_iterator<T*>;
		using const_reverse_iterator = std::reverse_iterator<const T*>;

		[:^^T[n]:] _data;

		[[nodiscard]] constexpr auto* data(this auto&& self) noexcept {
			return self._data;
		}

		static constexpr auto size = xte::wrap_value<n>();

		[[nodiscard]] constexpr auto* begin(this auto&& self) noexcept {
			return self._data;
		}

		[[nodiscard]] constexpr const T* cbegin() const noexcept {
			return this->begin();
		}

		[[nodiscard]] constexpr auto* end(this auto&& self) noexcept {
			return self._data + n;
		}

		[[nodiscard]] constexpr const T* cend() const noexcept {
			return this->end();
		}

		[[nodiscard]] constexpr auto rbegin(this auto&& self) noexcept {
			return std::reverse_iterator(self.end());
		}

		[[nodiscard]] constexpr auto crbegin() const noexcept {
			return this->rbegin();
		}

		[[nodiscard]] constexpr auto rend(this auto&& self) noexcept {
			return std::reverse_iterator(self.begin());
		}

		[[nodiscard]] constexpr auto crend() const noexcept {
			return this->rend();
		}

		[[nodiscard]] constexpr auto&& front(this auto&& self, xte::uz index = 0) noexcept {
			return xte::like<decltype(self)>(self._data[index]);
		}
		
		[[nodiscard]] constexpr auto&& back(this auto&& self, xte::uz index = 0) noexcept {
			return xte::like<decltype(self)>(self._data[n - index - 1]);
		}

		[[nodiscard]] constexpr auto&& operator[](this auto&& self, xte::uz index) noexcept {
			return XTE_FWD(self)._data[index];
		}

		template<xte::uz index>
		[[nodiscard]] constexpr auto&& get(this auto&& self) noexcept {
			return XTE_FWD(self)._data[index];
		}

		template<xte::is_same_ignore_cvref<xte::fixed_array<T, n>> Lhs, xte::is_instance_of<^^xte::fixed_array> Rhs>
		requires(xte::is_same<T, typename Rhs::type>)
		[[nodiscard]] friend constexpr auto operator+(Lhs&& lhs, Rhs&& rhs) XTE_ARROW(
			xte::unfold<n>([]<xte::uz... i>(auto&& lhs, auto&& rhs) XTE_ARROW(
				xte::unfold<Rhs::size>([]<xte::uz... j>(auto&& lhs, auto&& rhs) XTE_ARROW(
					xte::fixed_array { XTE_FWD(lhs)._data[i]..., XTE_FWD(rhs)._data[j]... }
				), XTE_FWD(lhs), XTE_FWD(rhs))
			), XTE_FWD(lhs), XTE_FWD(rhs))
		)
	};

	template<typename T>
	struct fixed_array<T, 0> {
		using value_type = T;
		using size_type = xte::uz;
		using difference_type = xte::iptrdiff;
		using reference = T&;
		using const_reference = const T&;
		using pointer = T*;
		using const_pointer = const T*;
		using iterator = T*;
		using const_iterator = const T*;
		using reverse_iterator = const T*;
		using const_reverse_iterator = const T*;

		[[nodiscard]] constexpr const T* data() const noexcept {
			return nullptr;
		}

		static constexpr auto size = xte::wrap_value<0uz>();

		[[nodiscard]] constexpr const T* begin() const noexcept {
			return nullptr;
		}

		[[nodiscard]] constexpr const T* cbegin() const noexcept {
			return nullptr;
		}

		[[nodiscard]] constexpr const T* rbegin() const noexcept {
			return nullptr;
		}

		[[nodiscard]] constexpr const T* crbegin() const noexcept {
			return nullptr;
		}

		[[nodiscard]] constexpr const T* end() const noexcept {
			return nullptr;
		}

		[[nodiscard]] constexpr const T* cend() const noexcept {
			return nullptr;
		}

		[[nodiscard]] constexpr const T* rend() const noexcept {
			return nullptr;
		}

		[[nodiscard]] constexpr const T* crend() const noexcept {
			return nullptr;
		}

		template<xte::is_same<xte::fixed_array<T, 0>> Lhs, xte::is_instance_of<^^xte::fixed_array> Rhs>
		requires(xte::is_same<T, typename Rhs::type>)
		[[nodiscard]] friend constexpr auto operator+(const Lhs&, Rhs&& rhs) XTE_ARROW(
			auto(XTE_FWD(rhs))
		)
	};

	template<typename T, typename... Ts>
	fixed_array(T, Ts...) -> fixed_array<std::common_type_t<T, Ts...>, -~sizeof...(Ts)>;
}


template<typename T, xte::uz n, xte::uz m>
[[nodiscard]] constexpr auto operator<=>(const xte::fixed_array<T, n>& lhs, const xte::fixed_array<T, m>& rhs) XTE_ARROW(
	xte::range_cmp(lhs, rhs)
)

template<typename T, xte::uz n, xte::uz m>
[[nodiscard]] constexpr auto operator==(const xte::fixed_array<T, n>& lhs, const xte::fixed_array<T, m>& rhs) XTE_ARROW(
	(n == m) && std::is_eq(lhs <=> rhs)
)

template<typename T, xte::uz n>
struct std::tuple_size<xte::fixed_array<T, n>> {
	static constexpr xte::uz value = n;
};

template<xte::uz index, typename T, xte::uz n>
struct std::tuple_element<index, xte::fixed_array<T, n>> {
	using type = T;
};

#	define XTE_MAKE_FIXED_ARRAY(...) \
		(xte::unfold<std::ranges::size((__VA_ARGS__))>( \
			DETAIL_XTE::fixed_array::make, \
			(__VA_ARGS__), \
			std::ranges::begin((__VA_ARGS__)) \
		))

namespace DETAIL_XTE::fixed_array {
	inline constexpr auto make = []<xte::uz... i>(auto&& range, auto iter) static XTE_ARROW(
		xte::fixed_array { ([](auto& iter) XTE_ARROW_IF(i, ++iter, xte::like<decltype(range)>(*iter)))(iter)... }
	);
}

#endif
