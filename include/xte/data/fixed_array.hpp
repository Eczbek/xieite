#ifndef DETAIL_XTE_HEADER_DATA_FIXED_ARRAY
#	define DETAIL_XTE_HEADER_DATA_FIXED_ARRAY
#
#	include "../data/range_cmp.hpp"
#	include "../func/unfold.hpp"
#	include "../meta/wrap_value.hpp"
#	include "../preproc/fwd.hpp"
#	include "../preproc/returns.hpp"
#	include "../trait/drop_cvref.hpp"
#	include "../trait/is_castable.hpp"
#	include "../trait/is_derived_from_specialization_of.hpp"
#	include "../trait/is_same.hpp"
#	include "../trait/is_specialization_of.hpp"
#	include "../util/as.hpp"
#	include "../util/number_types.hpp"
#	include <compare>
#	include <concepts>
#	include <iterator>
#	include <ranges>
#	include <tuple>
#	include <type_traits>

namespace xte {
	template<typename T, xte::uz n>
	struct fixed_array {
		using size_type = xte::uz;
		using difference_type = xte::iptrdiff;
		using value_type = T;
		using reference = T&;
		using creference = const T&;
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
			return self.data();
		}

		[[nodiscard]] constexpr const T* cbegin() const noexcept {
			return this->begin();
		}

		[[nodiscard]] constexpr auto* end(this auto&& self) noexcept {
			return self.data() + n;
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
			return xte::as<decltype(self)>(self.data()[index]);
		}
		
		[[nodiscard]] constexpr auto&& back(this auto&& self, xte::uz index = 0) noexcept {
			return xte::as<decltype(self)>(self.data()[n - index - 1]);
		}

		[[nodiscard]] constexpr auto&& operator[](this auto&& self, xte::uz index) noexcept {
			return xte::as<decltype(self)>(self.data()[index]);
		}

		template<xte::uz index>
		[[nodiscard]] constexpr auto&& get(this auto&& self) noexcept {
			return XTE_FWD(self).data()[index];
		}
	};

	template<typename T>
	struct fixed_array<T, 0> {
		using size_type = xte::uz;
		using difference_type = xte::iptrdiff;
		using value_type = T;
		using reference = T&;
		using creference = const T&;
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
	};

	template<typename T, typename... Ts>
	fixed_array(T, Ts...) -> fixed_array<std::common_type_t<T, Ts...>, (sizeof...(Ts) + 1)>;

	template<typename T, xte::uz n, xte::uz m>
	[[nodiscard]] constexpr auto operator<=>(const xte::fixed_array<T, n>& lhs, const xte::fixed_array<T, m>& rhs) XTE_RETURNS(
		xte::range_cmp(lhs, rhs)
	)

	template<typename T, xte::uz n, xte::uz m>
	[[nodiscard]] constexpr auto operator==(const xte::fixed_array<T, n>& lhs, const xte::fixed_array<T, m>& rhs) XTE_RETURNS(
		(n == m) && std::is_eq(lhs <=> rhs)
	)

	template<typename Lhs, typename Rhs>
	requires(xte::is_derived_from_specialization_of<xte::drop_cvref<Lhs>, ^^xte::fixed_array>
		&& xte::is_derived_from_specialization_of<xte::drop_cvref<Rhs>, ^^xte::fixed_array>
		&& xte::is_same<typename Lhs::value_type, typename Rhs::value_type>)
	[[nodiscard]] constexpr auto operator+(Lhs&& lhs, Rhs&& rhs) XTE_RETURNS(
		xte::unfold<Lhs::size>([]<xte::uz... i>(auto&& lhs, auto&& rhs) XTE_RETURNS(
			xte::unfold<Rhs::size>([]<xte::uz... j>(auto&& lhs, auto&& rhs) XTE_RETURNS(
				xte::fixed_array { XTE_FWD(lhs)[i]..., XTE_FWD(rhs)[j]... }
			), XTE_FWD(lhs), XTE_FWD(rhs))
		), XTE_FWD(lhs), XTE_FWD(rhs))
	)
}

template<typename T, xte::uz n>
struct std::tuple_size<xte::fixed_array<T, n>> {
	static constexpr xte::uz value = n;
};

template<xte::uz index, typename T, xte::uz n>
struct std::tuple_element<index, xte::fixed_array<T, n>> {
	using type = T;
};

#endif
