#ifndef XIEITE_HEADER_TYPES_MAYBE_CONSTANT_QUALIFIED
#	define XIEITE_HEADER_TYPES_MAYBE_CONSTANT_QUALIFIED

#	include <type_traits>

namespace xieite::detail {
	template<typename, bool>
	struct MaybeConstantQualified;

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...), true>
	: std::type_identity<Return_(Class_::*)(Arguments_...) const> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...), false>
	: std::type_identity<Return_(Class_::*)(Arguments_...)> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...), true>
	: std::type_identity<Return_(Class_::*)(Arguments_..., ...) const> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...), false>
	: std::type_identity<Return_(Class_::*)(Arguments_..., ...)> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) const, true>
	: std::type_identity<Return_(Class_::*)(Arguments_...) const> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) const, false>
	: std::type_identity<Return_(Class_::*)(Arguments_...)> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) const, true>
	: std::type_identity<Return_(Class_::*)(Arguments_..., ...) const> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) const, false>
	: std::type_identity<Return_(Class_::*)(Arguments_..., ...)> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) volatile, true>
	: std::type_identity<Return_(Class_::*)(Arguments_...) const volatile> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) volatile, false>
	: std::type_identity<Return_(Class_::*)(Arguments_...) volatile> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) volatile, true>
	: std::type_identity<Return_(Class_::*)(Arguments_..., ...) const volatile> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) volatile, false>
	: std::type_identity<Return_(Class_::*)(Arguments_..., ...) volatile> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) const volatile, true>
	: std::type_identity<Return_(Class_::*)(Arguments_...) const volatile> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) const volatile, false>
	: std::type_identity<Return_(Class_::*)(Arguments_...) volatile> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) const volatile, true>
	: std::type_identity<Return_(Class_::*)(Arguments_..., ...) const volatile> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) const volatile, false>
	: std::type_identity<Return_(Class_::*)(Arguments_..., ...) volatile> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) &, true>
	: std::type_identity<Return_(Class_::*)(Arguments_...) const &> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) &, false>
	: std::type_identity<Return_(Class_::*)(Arguments_...) &> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) &, true>
	: std::type_identity<Return_(Class_::*)(Arguments_..., ...) const &> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) &, false>
	: std::type_identity<Return_(Class_::*)(Arguments_..., ...) &> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) const &, true>
	: std::type_identity<Return_(Class_::*)(Arguments_...) const &> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) const &, false>
	: std::type_identity<Return_(Class_::*)(Arguments_...) &> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) const &, true>
	: std::type_identity<Return_(Class_::*)(Arguments_..., ...) const &> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) const &, false>
	: std::type_identity<Return_(Class_::*)(Arguments_..., ...) &> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) volatile &, true>
	: std::type_identity<Return_(Class_::*)(Arguments_...) const volatile &> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) volatile &, false>
	: std::type_identity<Return_(Class_::*)(Arguments_...) volatile &> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) volatile &, true>
	: std::type_identity<Return_(Class_::*)(Arguments_..., ...) const volatile &> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) volatile &, false>
	: std::type_identity<Return_(Class_::*)(Arguments_..., ...) volatile &> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) const volatile &, true>
	: std::type_identity<Return_(Class_::*)(Arguments_...) const volatile &> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) const volatile &, false>
	: std::type_identity<Return_(Class_::*)(Arguments_...) volatile &> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) const volatile &, true>
	: std::type_identity<Return_(Class_::*)(Arguments_..., ...) const volatile &> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) const volatile &, false>
	: std::type_identity<Return_(Class_::*)(Arguments_..., ...) volatile &> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) &&, true>
	: std::type_identity<Return_(Class_::*)(Arguments_...) const &&> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) &&, false>
	: std::type_identity<Return_(Class_::*)(Arguments_...) &&> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) &&, true>
	: std::type_identity<Return_(Class_::*)(Arguments_..., ...) const &&> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) &&, false>
	: std::type_identity<Return_(Class_::*)(Arguments_..., ...) &&> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) const &&, true>
	: std::type_identity<Return_(Class_::*)(Arguments_...) const &&> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) const &&, false>
	: std::type_identity<Return_(Class_::*)(Arguments_...) &&> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) const &&, true>
	: std::type_identity<Return_(Class_::*)(Arguments_..., ...) const &&> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) const &&, false>
	: std::type_identity<Return_(Class_::*)(Arguments_..., ...) &&> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) volatile &&, true>
	: std::type_identity<Return_(Class_::*)(Arguments_...) const volatile &&> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) volatile &&, false>
	: std::type_identity<Return_(Class_::*)(Arguments_...) volatile &&> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) volatile &&, true>
	: std::type_identity<Return_(Class_::*)(Arguments_..., ...) const volatile &&> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) volatile &&, false>
	: std::type_identity<Return_(Class_::*)(Arguments_..., ...) volatile &&> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) const volatile &&, true>
	: std::type_identity<Return_(Class_::*)(Arguments_...) const volatile &&> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) const volatile &&, false>
	: std::type_identity<Return_(Class_::*)(Arguments_...) volatile &&> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) const volatile &&, true>
	: std::type_identity<Return_(Class_::*)(Arguments_..., ...) const volatile &&> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) const volatile &&, false>
	: std::type_identity<Return_(Class_::*)(Arguments_..., ...) volatile &&> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) noexcept, true>
	: std::type_identity<Return_(Class_::*)(Arguments_...) const noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) noexcept, false>
	: std::type_identity<Return_(Class_::*)(Arguments_...) noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) noexcept, true>
	: std::type_identity<Return_(Class_::*)(Arguments_..., ...) const noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) noexcept, false>
	: std::type_identity<Return_(Class_::*)(Arguments_..., ...) noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) const noexcept, true>
	: std::type_identity<Return_(Class_::*)(Arguments_...) const noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) const noexcept, false>
	: std::type_identity<Return_(Class_::*)(Arguments_...) noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) const noexcept, true>
	: std::type_identity<Return_(Class_::*)(Arguments_..., ...) const noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) const noexcept, false>
	: std::type_identity<Return_(Class_::*)(Arguments_..., ...) noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) volatile noexcept, true>
	: std::type_identity<Return_(Class_::*)(Arguments_...) const volatile noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) volatile noexcept, false>
	: std::type_identity<Return_(Class_::*)(Arguments_...) volatile noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) volatile noexcept, true>
	: std::type_identity<Return_(Class_::*)(Arguments_..., ...) const volatile noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) volatile noexcept, false>
	: std::type_identity<Return_(Class_::*)(Arguments_..., ...) volatile noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) const volatile noexcept, true>
	: std::type_identity<Return_(Class_::*)(Arguments_...) const volatile noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) const volatile noexcept, false>
	: std::type_identity<Return_(Class_::*)(Arguments_...) volatile noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) const volatile noexcept, true>
	: std::type_identity<Return_(Class_::*)(Arguments_..., ...) const volatile noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) const volatile noexcept, false>
	: std::type_identity<Return_(Class_::*)(Arguments_..., ...) volatile noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) & noexcept, true>
	: std::type_identity<Return_(Class_::*)(Arguments_...) const & noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) & noexcept, false>
	: std::type_identity<Return_(Class_::*)(Arguments_...) & noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) & noexcept, true>
	: std::type_identity<Return_(Class_::*)(Arguments_..., ...) const & noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) & noexcept, false>
	: std::type_identity<Return_(Class_::*)(Arguments_..., ...) & noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) const & noexcept, true>
	: std::type_identity<Return_(Class_::*)(Arguments_...) const & noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) const & noexcept, false>
	: std::type_identity<Return_(Class_::*)(Arguments_...) & noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) const & noexcept, true>
	: std::type_identity<Return_(Class_::*)(Arguments_..., ...) const & noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) const & noexcept, false>
	: std::type_identity<Return_(Class_::*)(Arguments_..., ...) & noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) volatile & noexcept, true>
	: std::type_identity<Return_(Class_::*)(Arguments_...) const volatile & noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) volatile & noexcept, false>
	: std::type_identity<Return_(Class_::*)(Arguments_...) volatile & noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) volatile & noexcept, true>
	: std::type_identity<Return_(Class_::*)(Arguments_..., ...) const volatile & noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) volatile & noexcept, false>
	: std::type_identity<Return_(Class_::*)(Arguments_..., ...) volatile & noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) const volatile & noexcept, true>
	: std::type_identity<Return_(Class_::*)(Arguments_...) const volatile & noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) const volatile & noexcept, false>
	: std::type_identity<Return_(Class_::*)(Arguments_...) volatile & noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) const volatile & noexcept, true>
	: std::type_identity<Return_(Class_::*)(Arguments_..., ...) const volatile & noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) const volatile & noexcept, false>
	: std::type_identity<Return_(Class_::*)(Arguments_..., ...) volatile & noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) && noexcept, true>
	: std::type_identity<Return_(Class_::*)(Arguments_...) const && noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) && noexcept, false>
	: std::type_identity<Return_(Class_::*)(Arguments_...) && noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) && noexcept, true>
	: std::type_identity<Return_(Class_::*)(Arguments_..., ...) const && noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) && noexcept, false>
	: std::type_identity<Return_(Class_::*)(Arguments_..., ...) && noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) const && noexcept, true>
	: std::type_identity<Return_(Class_::*)(Arguments_...) const && noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) const && noexcept, false>
	: std::type_identity<Return_(Class_::*)(Arguments_...) && noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) const && noexcept, true>
	: std::type_identity<Return_(Class_::*)(Arguments_..., ...) const && noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) const && noexcept, false>
	: std::type_identity<Return_(Class_::*)(Arguments_..., ...) && noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) volatile && noexcept, true>
	: std::type_identity<Return_(Class_::*)(Arguments_...) const volatile && noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) volatile && noexcept, false>
	: std::type_identity<Return_(Class_::*)(Arguments_...) volatile && noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) volatile && noexcept, true>
	: std::type_identity<Return_(Class_::*)(Arguments_..., ...) const volatile && noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) volatile && noexcept, false>
	: std::type_identity<Return_(Class_::*)(Arguments_..., ...) volatile && noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) const volatile && noexcept, true>
	: std::type_identity<Return_(Class_::*)(Arguments_...) const volatile && noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) const volatile && noexcept, false>
	: std::type_identity<Return_(Class_::*)(Arguments_...) volatile && noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) const volatile && noexcept, true>
	: std::type_identity<Return_(Class_::*)(Arguments_..., ...) const volatile && noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) const volatile && noexcept, false>
	: std::type_identity<Return_(Class_::*)(Arguments_..., ...) volatile && noexcept> {};
}

namespace xieite::types {
	template<typename Function_, bool constantQualified_>
	using MaybeConstantQualified = xieite::detail::MaybeConstantQualified<Function_, constantQualified_>::type;
}

#endif
