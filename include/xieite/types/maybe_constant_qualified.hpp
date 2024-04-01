#ifndef XIEITE_HEADER_TYPES_MAYBE_CONSTANT_QUALIFIED
#	define XIEITE_HEADER_TYPES_MAYBE_CONSTANT_QUALIFIED

#	include "../types/wrapper.hpp"

namespace xieite::detail {
	template<typename, bool>
	struct MaybeConstantQualified;

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...), true>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_...) const> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...), false>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_...)> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...), true>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_..., ...) const> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...), false>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_..., ...)> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) const, true>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_...) const> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) const, false>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_...)> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) const, true>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_..., ...) const> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) const, false>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_..., ...)> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) volatile, true>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_...) volatile const> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) volatile, false>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_...) volatile> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) volatile, true>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_..., ...) volatile const> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) volatile, false>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_..., ...) volatile> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) volatile const, true>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_...) volatile const> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) volatile const, false>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_...) volatile> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) volatile const, true>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_..., ...) volatile const> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) volatile const, false>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_..., ...) volatile> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) &, true>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_...) const &> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) &, false>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_...) &> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) &, true>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_..., ...) const &> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) &, false>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_..., ...) &> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) const &, true>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_...) const &> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) const &, false>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_...) &> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) const &, true>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_..., ...) const &> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) const &, false>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_..., ...) &> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) volatile &, true>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_...) volatile const &> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) volatile &, false>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_...) volatile &> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) volatile &, true>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_..., ...) volatile const &> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) volatile &, false>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_..., ...) volatile &> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) volatile const &, true>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_...) volatile const &> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) volatile const &, false>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_...) volatile &> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) volatile const &, true>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_..., ...) volatile const &> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) volatile const &, false>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_..., ...) volatile &> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) &&, true>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_...) const &&> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) &&, false>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_...) &&> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) &&, true>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_..., ...) const &&> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) &&, false>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_..., ...) &&> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) const &&, true>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_...) const &&> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) const &&, false>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_...) &&> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) const &&, true>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_..., ...) const &&> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) const &&, false>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_..., ...) &&> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) volatile &&, true>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_...) volatile const &&> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) volatile &&, false>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_...) volatile &&> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) volatile &&, true>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_..., ...) volatile const &&> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) volatile &&, false>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_..., ...) volatile &&> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) volatile const &&, true>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_...) volatile const &&> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) volatile const &&, false>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_...) volatile &&> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) volatile const &&, true>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_..., ...) volatile const &&> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) volatile const &&, false>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_..., ...) volatile &&> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) noexcept, true>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_...) const noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) noexcept, false>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_...) noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) noexcept, true>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_..., ...) const noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) noexcept, false>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_..., ...) noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) const noexcept, true>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_...) const noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) const noexcept, false>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_...) noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) const noexcept, true>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_..., ...) const noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) const noexcept, false>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_..., ...) noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) volatile noexcept, true>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_...) volatile const noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) volatile noexcept, false>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_...) volatile noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) volatile noexcept, true>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_..., ...) volatile const noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) volatile noexcept, false>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_..., ...) volatile noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) volatile const noexcept, true>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_...) volatile const noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) volatile const noexcept, false>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_...) volatile noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) volatile const noexcept, true>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_..., ...) volatile const noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) volatile const noexcept, false>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_..., ...) volatile noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) & noexcept, true>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_...) const & noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) & noexcept, false>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_...) & noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) & noexcept, true>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_..., ...) const & noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) & noexcept, false>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_..., ...) & noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) const & noexcept, true>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_...) const & noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) const & noexcept, false>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_...) & noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) const & noexcept, true>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_..., ...) const & noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) const & noexcept, false>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_..., ...) & noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) volatile & noexcept, true>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_...) volatile const & noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) volatile & noexcept, false>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_...) volatile & noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) volatile & noexcept, true>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_..., ...) volatile const & noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) volatile & noexcept, false>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_..., ...) volatile & noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) volatile const & noexcept, true>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_...) volatile const & noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) volatile const & noexcept, false>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_...) volatile & noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) volatile const & noexcept, true>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_..., ...) volatile const & noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) volatile const & noexcept, false>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_..., ...) volatile & noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) && noexcept, true>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_...) const && noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) && noexcept, false>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_...) && noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) && noexcept, true>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_..., ...) const && noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) && noexcept, false>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_..., ...) && noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) const && noexcept, true>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_...) const && noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) const && noexcept, false>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_...) && noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) const && noexcept, true>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_..., ...) const && noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) const && noexcept, false>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_..., ...) && noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) volatile && noexcept, true>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_...) volatile const && noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) volatile && noexcept, false>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_...) volatile && noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) volatile && noexcept, true>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_..., ...) volatile const && noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) volatile && noexcept, false>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_..., ...) volatile && noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) volatile const && noexcept, true>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_...) volatile const && noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_...) volatile const && noexcept, false>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_...) volatile && noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) volatile const && noexcept, true>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_..., ...) volatile const && noexcept> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct MaybeConstantQualified<Return_(Class_::*)(Arguments_..., ...) volatile const && noexcept, false>
	: xieite::types::Wrapper<Return_(Class_::*)(Arguments_..., ...) volatile && noexcept> {};
}

namespace xieite::types {
	template<typename Function_, bool constantQualified_>
	using MaybeConstantQualified = xieite::detail::MaybeConstantQualified<Function_, constantQualified_>::Type;
}

#endif
