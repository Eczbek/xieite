#ifndef DETAIL_XTE_HEADER_FUNDAMENTAL_TRAITS
#	define DETAIL_XTE_HEADER_FUNDAMENTAL_TRAITS
#
#	include "./aliases.hpp"
#	include "./meta/wrap.hpp"
#	include "./qual_traits.hpp"
#	include <compare>
#	include <concepts>
#	include <meta>
#	include <type_traits>

namespace DETAIL_XTE::fundamental_traits {
	template<typename>
	constexpr bool is_ptr = false;

	template<typename type>
	constexpr bool is_ptr<type*> = true;

	template<typename type, xte::uz depth>
	constexpr auto add_ptr = ^^typename[:DETAIL_XTE::fundamental_traits::add_ptr<type, (depth - 1)>:]*;

	template<typename type, xte::uz depth>
	constexpr auto add_ptr<type&, depth> = ^^typename[:DETAIL_XTE::fundamental_traits::add_ptr<xte::drop_ref<type>, (depth - 1)>:]*&;

	template<typename type, xte::uz depth>
	constexpr auto add_ptr<type&&, depth> = ^^typename[:DETAIL_XTE::fundamental_traits::add_ptr<xte::drop_ref<type>, (depth - 1)>:]*&&;

	template<typename type>
	constexpr auto add_ptr<type, 0> = ^^type;

	template<typename type, xte::uz>
	constexpr auto drop_ptr = ^^type;

	template<typename type, xte::uz depth>
	requires(depth > 0)
	constexpr auto drop_ptr<type*, depth> = DETAIL_XTE::fundamental_traits::drop_ptr<type, (depth - 1)>;

	template<typename type, xte::uz depth>
	requires(depth > 0)
	constexpr auto drop_ptr<type*&, depth> = DETAIL_XTE::fundamental_traits::drop_ptr<type&, (depth - 1)>;

	template<typename type, xte::uz depth>
	requires(depth > 0)
	constexpr auto drop_ptr<type*&&, depth> = DETAIL_XTE::fundamental_traits::drop_ptr<type&&, (depth - 1)>;
}

namespace xte {
	template<typename type>
	concept is_void = std::is_void_v<type>;

	template<typename type>
	concept is_unsigned_int = std::unsigned_integral<type> && !xte::is_same_drop_cv<type, bool>;

	template<typename type>
	concept is_signed_int = std::signed_integral<type>;

	template<typename type>
	concept is_int = xte::is_unsigned_int<type> || xte::is_signed_int<type>;

	template<typename type>
	concept is_float = std::floating_point<type>;

	template<typename type>
	concept is_arithmetic = xte::is_int<type> || xte::is_float<type>;

	template<typename type>
	concept is_arithmetic_or_bool = xte::is_arithmetic<type> || xte::is_same_drop_cv<type, bool>;

	template<typename type>
	concept is_char = xte::is_same_any_drop_cv<type, char, wchar_t, char8_t, char16_t, char32_t>;

	template<typename type, xte::uz depth = 0>
	concept is_ptr = DETAIL_XTE::fundamental_traits::is_ptr<xte::drop_cvref<typename[:DETAIL_XTE::fundamental_traits::drop_ptr<type, depth>:]>>;

	template<typename type>
	concept is_order = xte::is_same_any_drop_cv<type, std::strong_ordering, std::weak_ordering, std::partial_ordering>;

	template<typename type, xte::uz depth = 1>
	using add_ptr = [:DETAIL_XTE::fundamental_traits::add_ptr<type, depth>:];

	template<typename type, xte::uz size>
	requires(size > 0)
	using add_array = type[size];

	template<typename type>
	using add_unsized_array = type[];

	template<typename type, xte::uz depth = 1>
	using drop_ptr = [:DETAIL_XTE::fundamental_traits::drop_ptr<type, depth>:];

	template<typename type>
	using try_unsigned = [:xte::is_signed_int<type> ? ^^std::make_unsigned<type> : ^^xte::wrap_type<type>:]::type;

	template<typename type>
	using try_signed = [:xte::is_unsigned_int<type> ? ^^std::make_signed<type> : ^^xte::wrap_type<type>:]::type;

	template<typename type>
	constexpr xte::uz ptr_depth = ([] {
		auto info = std::meta::remove_cvref(^^type);
		xte::uz depth = 0;
		while (std::meta::is_pointer_type(info)) {
			info = std::meta::remove_pointer(info);
			++depth;
		}
		return depth;
	})();

	[[nodiscard]] constexpr auto as_unsigned(xte::is_arithmetic auto value) noexcept {
		return static_cast<xte::try_unsigned<decltype(value)>>(value);
	};

	[[nodiscard]] constexpr auto as_signed(xte::is_arithmetic auto value) noexcept {
		return static_cast<xte::try_signed<decltype(value)>>(value);
	};

	template<xte::is_int target_type>
	[[nodiscard]] constexpr target_type sign_cast(xte::is_int auto value) noexcept {
		if constexpr (xte::is_unsigned_int<target_type>) {
			return static_cast<target_type>(xte::as_unsigned(value));
		} else {
			return static_cast<target_type>(xte::as_signed(value));
		}
	};
}

#endif
