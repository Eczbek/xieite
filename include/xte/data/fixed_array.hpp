#ifndef DETAIL_XTE_HEADER_DATA_FIXED_ARRAY
#	define DETAIL_XTE_HEADER_DATA_FIXED_ARRAY
#
#	include "../func/unfold.hpp"
#	include "../meta/wrap_value.hpp"
#	include "../preproc/arrow.hpp"
#	include "../preproc/fwd.hpp"
#	include "../trait/is_instance_of.hpp"
#	include "../trait/is_same.hpp"
#	include "../trait/is_same_ignore_cvref.hpp"
#	include "../util/like.hpp"
#	include "../util/types.hpp"
#	include <concepts>
#	include <ranges>
#	include <tuple>
#	include <type_traits>

namespace xte {
	template<typename T, xte::uz n>
	struct fixed_array {
		using type = T;

		static constexpr auto size = xte::wrap_value<n>();

		[:^^T[n]:] _data;

		[[nodiscard]] constexpr auto&& operator[](this auto&& self, xte::uz index) noexcept {
			return XTE_FWD(self)._data[index];
		}

		[[nodiscard]] constexpr auto* data(this auto&& self) noexcept {
			return self._data;
		}

		[[nodiscard]] constexpr auto* begin(this auto&& self) noexcept {
			return self.data();
		}

		[[nodiscard]] constexpr auto* end(this auto&& self) noexcept {
			return self.data() + n;
		}

		template<xte::uz index>
		[[nodiscard]] constexpr auto&& get(this auto&& self) noexcept {
			return XTE_FWD(self)[index];
		}

		template<xte::is_same_ignore_cvref<xte::fixed_array<T, n>> Lhs, xte::is_instance_of<^^xte::fixed_array> Rhs>
		requires(xte::is_same<T, typename Rhs::type>)
		[[nodiscard]] friend constexpr auto operator+(Lhs&& lhs, Rhs&& rhs) XTE_ARROW(
			xte::unfold<n>([]<xte::uz... i>(auto&& lhs, auto&& rhs) XTE_ARROW(
				xte::unfold<Rhs::size>([]<xte::uz... j>(auto&& lhs, auto&& rhs) XTE_ARROW(
					xte::fixed_array { XTE_FWD(lhs)[i]..., XTE_FWD(rhs)[j]... }
				), XTE_FWD(lhs), XTE_FWD(rhs))
			), XTE_FWD(lhs), XTE_FWD(rhs))
		)
	};

	template<typename T>
	struct fixed_array<T, 0> {
		using type = T;

		static constexpr auto size = xte::wrap_value<0uz>();

		[[nodiscard]] constexpr const T* data() noexcept {
			return nullptr;
		}

		[[nodiscard]] constexpr const T* begin() noexcept {
			return nullptr;
		}

		[[nodiscard]] constexpr const T* end() noexcept {
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
		xte::fixed_array {
			([](auto& iter) XTE_ARROW_IF(i, ++iter, xte::like<decltype(range)&&>(*iter)))(iter)...
		}
	);
}

#endif
