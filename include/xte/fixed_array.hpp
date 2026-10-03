#ifndef DETAIL_XTE_HEADER_FIXED_ARRAY
#	define DETAIL_XTE_HEADER_FIXED_ARRAY
#
#	include "./aliases.hpp"
#	include "./class_traits.hpp"
#	include "./func/unfold.hpp"
#	include "./macros.hpp"
#	include "./meta/wrap.hpp"
#	include "./qual_traits.hpp"
#	include "./range_compare.hpp"
#	include <compare>
#	include <concepts>
#	include <iterator>
#	include <ranges>
#	include <tuple>
#	include <type_traits>

namespace xte {
	template<typename item_type, xte::uz n>
	struct fixed_array {
		using value_type = item_type;
		using reference = item_type&;
		using const_reference = const item_type&;
		using pointer = item_type*;
		using const_pointer = const item_type*;
		using iterator = item_type*;
		using const_iterator = const item_type*;
		using reverse_iterator = std::reverse_iterator<item_type*>;
		using const_reverse_iterator = std::reverse_iterator<const item_type*>;
		using size_type = xte::uz;
		using difference_type = xte::iptrdiff;

		[:^^item_type[n]:] _data;

		[[nodiscard]] constexpr auto* data(this auto&& self) noexcept {
			return self._data;
		}

		static constexpr auto size = xte::wrap_value<n>();

		template<xte::uz m>
		[[nodiscard]] friend constexpr auto operator<=>(xte::fixed_array<item_type, n> const& lhs, xte::fixed_array<item_type, m> const& rhs) XTE_RETURNS(
			xte::range_compare(lhs, rhs)
		)

		template<xte::uz m>
		[[nodiscard]] friend constexpr auto operator==(xte::fixed_array<item_type, n> const& lhs, xte::fixed_array<item_type, m> const& rhs) XTE_RETURNS(
			(n == m) && std::is_eq(lhs <=> rhs)
		)

		[[nodiscard]] constexpr auto* begin(this auto&& self) noexcept {
			return self.data();
		}

		[[nodiscard]] constexpr item_type const* cbegin() const noexcept {
			return this->begin();
		}

		[[nodiscard]] constexpr auto* end(this auto&& self) noexcept {
			return self.data() + n;
		}

		[[nodiscard]] constexpr item_type const* cend() const noexcept {
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
			return xte::like<decltype(self)>(self.data()[index]);
		}
		
		[[nodiscard]] constexpr auto&& back(this auto&& self, xte::uz index = 0) noexcept {
			return xte::like<decltype(self)>(self.data()[n - index - 1]);
		}

		[[nodiscard]] constexpr auto&& operator[](this auto&& self, xte::uz index) noexcept {
			return xte::like<decltype(self)>(self.data()[index]);
		}

		template<xte::uz index>
		[[nodiscard]] constexpr auto&& get(this auto&& self) noexcept {
			return XTE_FWD(self).data()[index];
		}
	};

	template<typename item_type>
	struct fixed_array<item_type, 0> {
		using value_type = item_type;
		using reference = item_type&;
		using const_reference = const item_type&;
		using pointer = item_type*;
		using const_pointer = const item_type*;
		using iterator = item_type*;
		using const_iterator = const item_type*;
		using reverse_iterator = std::reverse_iterator<item_type*>;
		using const_reverse_iterator = std::reverse_iterator<const item_type*>;
		using size_type = xte::uz;
		using difference_type = xte::iptrdiff;

		[[nodiscard]] constexpr item_type const* data() const noexcept {
			return nullptr;
		}

		static constexpr auto size = xte::wrap_value<0uz>();

		[[nodiscard]] constexpr item_type const* begin() const noexcept {
			return nullptr;
		}

		[[nodiscard]] constexpr item_type const* cbegin() const noexcept {
			return nullptr;
		}

		[[nodiscard]] constexpr item_type const* rbegin() const noexcept {
			return nullptr;
		}

		[[nodiscard]] constexpr item_type const* crbegin() const noexcept {
			return nullptr;
		}

		[[nodiscard]] constexpr item_type const* end() const noexcept {
			return nullptr;
		}

		[[nodiscard]] constexpr item_type const* cend() const noexcept {
			return nullptr;
		}

		[[nodiscard]] constexpr item_type const* rend() const noexcept {
			return nullptr;
		}

		[[nodiscard]] constexpr item_type const* crend() const noexcept {
			return nullptr;
		}
	};

	template<typename item_type, typename... item_types>
	fixed_array(item_type, item_types...) -> fixed_array<std::common_type_t<item_type, item_types...>, (sizeof...(item_types) + 1)>;

	template<typename lhs_type, typename rhs_type>
	requires(xte::is_derived_from_specialization_of<xte::drop_cvref<lhs_type>, ^^xte::fixed_array>
		&& xte::is_derived_from_specialization_of<xte::drop_cvref<rhs_type>, ^^xte::fixed_array>
		&& xte::is_same<typename lhs_type::value_type, typename rhs_type::value_type>)
	[[nodiscard]] constexpr auto operator+(lhs_type&& lhs, rhs_type&& rhs) XTE_RETURNS(
		xte::unfold<lhs_type::size>([]<xte::uz... i>(auto&& lhs, auto&& rhs) XTE_RETURNS(
			xte::unfold<rhs_type::size>([]<xte::uz... j>(auto&& lhs, auto&& rhs) XTE_RETURNS(
				xte::fixed_array { XTE_FWD(lhs)[i]..., XTE_FWD(rhs)[j]... }
			), XTE_FWD(lhs), XTE_FWD(rhs))
		), XTE_FWD(lhs), XTE_FWD(rhs))
	)
}

template<typename item_type, xte::uz n>
struct std::tuple_size<xte::fixed_array<item_type, n>> {
	static constexpr xte::uz value = n;
};

template<xte::uz index, typename item_type, xte::uz n>
struct std::tuple_element<index, xte::fixed_array<item_type, n>> {
	using type = item_type;
};

#endif
