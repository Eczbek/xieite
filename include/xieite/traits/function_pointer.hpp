#ifndef XIEITE_HEADER_TRAITS_FUNCTION_POINTER
#	define XIEITE_HEADER_TRAITS_FUNCTION_POINTER

#	include <tuple>

namespace xieite::detail {
	template<typename Function_, typename Return_, typename Arguments_, bool variadic_, bool nonThrowing_>
	struct FunctionPointerTraits {
		using Function = Function_;
		using Return = Return_;
		using Arguments = Arguments_;

		static constexpr bool variadic = variadic_;
		static constexpr bool nonThrowing = nonThrowing_;
	};

	template<typename Class_, typename Reference_, typename Function_, typename Return_, typename Arguments_, bool variadic_, bool constantQualified_, bool volatileQualified_, bool leftValueQualified_, bool rightValueQualified_, bool nonThrowing_>
	struct MemberFunctionPointerTraits {
		using Class = Class_;
		using Reference = Reference_;
		using Function = Function_;
		using Return = Return_;
		using Arguments = Arguments_;

		static constexpr bool variadic = variadic_;
		static constexpr bool constantQualified = constantQualified_;
		static constexpr bool volatileQualified = volatileQualified_;
		static constexpr bool leftValueQualified = leftValueQualified_;
		static constexpr bool rightValueQualified = rightValueQualified_;
		static constexpr bool nonThrowing = nonThrowing_;
	};
}

namespace xieite::traits {
	template<typename>
	struct FunctionPointer;

	template<typename Return_, typename... Arguments_>
	struct FunctionPointer<Return_(*)(Arguments_...)>
	: xieite::detail::FunctionPointerTraits<Return_(Arguments_...), Return_, std::tuple<Arguments_...>, false, false> {};

	template<typename Return_, typename... Arguments_>
	struct FunctionPointer<Return_(*)(Arguments_..., ...)>
	: xieite::detail::FunctionPointerTraits<Return_(Arguments_..., ...), Return_, std::tuple<Arguments_...>, true, false> {};

	template<typename Return_, typename... Arguments_>
	struct FunctionPointer<Return_(*)(Arguments_...) noexcept>
	: xieite::detail::FunctionPointerTraits<Return_(Arguments_...) noexcept, Return_, std::tuple<Arguments_...>, false, true> {};

	template<typename Return_, typename... Arguments_>
	struct FunctionPointer<Return_(*)(Arguments_..., ...) noexcept>
	: xieite::detail::FunctionPointerTraits<Return_(Arguments_..., ...) noexcept, Return_, std::tuple<Arguments_...>, true, true> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct FunctionPointer<Return_(Class_::*)(Arguments_...)>
	: xieite::detail::MemberFunctionPointerTraits<Class_, Class_&, Return_(Arguments_...), Return_, std::tuple<Arguments_...>, false, false, false, false, false, false> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct FunctionPointer<Return_(Class_::*)(Arguments_..., ...)>
	: xieite::detail::MemberFunctionPointerTraits<Class_, Class_&, Return_(Arguments_..., ...), Return_, std::tuple<Arguments_...>, true, false, false, false, false, false> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct FunctionPointer<Return_(Class_::*)(Arguments_...) const>
	: xieite::detail::MemberFunctionPointerTraits<Class_, const Class_&, Return_(Arguments_...) const, Return_, std::tuple<Arguments_...>, false, true, false, false, false, false> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct FunctionPointer<Return_(Class_::*)(Arguments_..., ...) const>
	: xieite::detail::MemberFunctionPointerTraits<Class_, const Class_&, Return_(Arguments_..., ...) const, Return_, std::tuple<Arguments_...>, true, true, false, false, false, false> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct FunctionPointer<Return_(Class_::*)(Arguments_...) volatile>
	: xieite::detail::MemberFunctionPointerTraits<Class_, volatile Class_&, Return_(Arguments_...) volatile, Return_, std::tuple<Arguments_...>, false, false, true, false, false, false> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct FunctionPointer<Return_(Class_::*)(Arguments_..., ...) volatile>
	: xieite::detail::MemberFunctionPointerTraits<Class_, volatile Class_&, Return_(Arguments_..., ...) volatile, Return_, std::tuple<Arguments_...>, true, false, true, false, false, false> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct FunctionPointer<Return_(Class_::*)(Arguments_...) volatile const>
	: xieite::detail::MemberFunctionPointerTraits<Class_, volatile const Class_&, Return_(Arguments_...) volatile const, Return_, std::tuple<Arguments_...>, false, true, true, false, false, false> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct FunctionPointer<Return_(Class_::*)(Arguments_..., ...) volatile const>
	: xieite::detail::MemberFunctionPointerTraits<Class_, volatile const Class_&, Return_(Arguments_..., ...) volatile const, Return_, std::tuple<Arguments_...>, true, true, true, false, false, false> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct FunctionPointer<Return_(Class_::*)(Arguments_...) &>
	: xieite::detail::MemberFunctionPointerTraits<Class_, Class_&, Return_(Arguments_...) &, Return_, std::tuple<Arguments_...>, false, false, false, true, false, false> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct FunctionPointer<Return_(Class_::*)(Arguments_..., ...) &>
	: xieite::detail::MemberFunctionPointerTraits<Class_, Class_&, Return_(Arguments_..., ...) &, Return_, std::tuple<Arguments_...>, true, false, false, true, false, false> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct FunctionPointer<Return_(Class_::*)(Arguments_...) const &>
	: xieite::detail::MemberFunctionPointerTraits<Class_, const Class_&, Return_(Arguments_...) const &, Return_, std::tuple<Arguments_...>, false, true, false, true, false, false> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct FunctionPointer<Return_(Class_::*)(Arguments_..., ...) const &>
	: xieite::detail::MemberFunctionPointerTraits<Class_, const Class_&, Return_(Arguments_..., ...) const &, Return_, std::tuple<Arguments_...>, true, true, false, true, false, false> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct FunctionPointer<Return_(Class_::*)(Arguments_...) volatile &>
	: xieite::detail::MemberFunctionPointerTraits<Class_, volatile Class_&, Return_(Arguments_...) volatile &, Return_, std::tuple<Arguments_...>, false, false, true, true, false, false> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct FunctionPointer<Return_(Class_::*)(Arguments_..., ...) volatile &>
	: xieite::detail::MemberFunctionPointerTraits<Class_, volatile Class_&, Return_(Arguments_..., ...) volatile &, Return_, std::tuple<Arguments_...>, true, false, true, true, false, false> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct FunctionPointer<Return_(Class_::*)(Arguments_...) volatile const &>
	: xieite::detail::MemberFunctionPointerTraits<Class_, volatile const Class_&, Return_(Arguments_...) volatile const &, Return_, std::tuple<Arguments_...>, false, true, true, true, false, false> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct FunctionPointer<Return_(Class_::*)(Arguments_..., ...) volatile const &>
	: xieite::detail::MemberFunctionPointerTraits<Class_, volatile const Class_&, Return_(Arguments_..., ...) volatile const &, Return_, std::tuple<Arguments_...>, true, true, true, true, false, false> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct FunctionPointer<Return_(Class_::*)(Arguments_...) &&>
	: xieite::detail::MemberFunctionPointerTraits<Class_, Class_&&, Return_(Arguments_...) &&, Return_, std::tuple<Arguments_...>, false, false, false, false, true, false> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct FunctionPointer<Return_(Class_::*)(Arguments_..., ...) &&>
	: xieite::detail::MemberFunctionPointerTraits<Class_, Class_&&, Return_(Arguments_..., ...) &&, Return_, std::tuple<Arguments_...>, true, false, false, false, true, false> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct FunctionPointer<Return_(Class_::*)(Arguments_...) const &&>
	: xieite::detail::MemberFunctionPointerTraits<Class_, const Class_&&, Return_(Arguments_...) const &&, Return_, std::tuple<Arguments_...>, false, true, false, false, true, false> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct FunctionPointer<Return_(Class_::*)(Arguments_..., ...) const &&>
	: xieite::detail::MemberFunctionPointerTraits<Class_, const Class_&&, Return_(Arguments_..., ...) const &&, Return_, std::tuple<Arguments_...>, true, true, false, false, true, false> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct FunctionPointer<Return_(Class_::*)(Arguments_...) volatile &&>
	: xieite::detail::MemberFunctionPointerTraits<Class_, volatile Class_&&, Return_(Arguments_...) volatile &&, Return_, std::tuple<Arguments_...>, false, false, true, false, true, false> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct FunctionPointer<Return_(Class_::*)(Arguments_..., ...) volatile &&>
	: xieite::detail::MemberFunctionPointerTraits<Class_, volatile Class_&&, Return_(Arguments_..., ...) volatile &&, Return_, std::tuple<Arguments_...>, true, false, true, false, true, false> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct FunctionPointer<Return_(Class_::*)(Arguments_...) volatile const &&>
	: xieite::detail::MemberFunctionPointerTraits<Class_, volatile const Class_&&, Return_(Arguments_...) volatile const &&, Return_, std::tuple<Arguments_...>, false, true, true, false, true, false> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct FunctionPointer<Return_(Class_::*)(Arguments_..., ...) volatile const &&>
	: xieite::detail::MemberFunctionPointerTraits<Class_, volatile const Class_&&, Return_(Arguments_..., ...) volatile const &&, Return_, std::tuple<Arguments_...>, true, true, true, false, true, false> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct FunctionPointer<Return_(Class_::*)(Arguments_...) noexcept>
	: xieite::detail::MemberFunctionPointerTraits<Class_, Class_&, Return_(Arguments_...) noexcept, Return_, std::tuple<Arguments_...>, false, false, false, false, false, true> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct FunctionPointer<Return_(Class_::*)(Arguments_..., ...) noexcept>
	: xieite::detail::MemberFunctionPointerTraits<Class_, Class_&, Return_(Arguments_..., ...) noexcept, Return_, std::tuple<Arguments_...>, true, false, false, false, false, true> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct FunctionPointer<Return_(Class_::*)(Arguments_...) const noexcept>
	: xieite::detail::MemberFunctionPointerTraits<Class_, const Class_&, Return_(Arguments_...) const noexcept, Return_, std::tuple<Arguments_...>, false, true, false, false, false, true> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct FunctionPointer<Return_(Class_::*)(Arguments_..., ...) const noexcept>
	: xieite::detail::MemberFunctionPointerTraits<Class_, const Class_&, Return_(Arguments_..., ...) const noexcept, Return_, std::tuple<Arguments_...>, true, true, false, false, false, true> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct FunctionPointer<Return_(Class_::*)(Arguments_...) volatile noexcept>
	: xieite::detail::MemberFunctionPointerTraits<Class_, volatile Class_&, Return_(Arguments_...) volatile noexcept, Return_, std::tuple<Arguments_...>, false, false, true, false, false, true> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct FunctionPointer<Return_(Class_::*)(Arguments_..., ...) volatile noexcept>
	: xieite::detail::MemberFunctionPointerTraits<Class_, volatile Class_&, Return_(Arguments_..., ...) volatile noexcept, Return_, std::tuple<Arguments_...>, true, false, true, false, false, true> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct FunctionPointer<Return_(Class_::*)(Arguments_...) volatile const noexcept>
	: xieite::detail::MemberFunctionPointerTraits<Class_, volatile const Class_&, Return_(Arguments_...) volatile const noexcept, Return_, std::tuple<Arguments_...>, false, true, true, false, false, true> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct FunctionPointer<Return_(Class_::*)(Arguments_..., ...) volatile const noexcept>
	: xieite::detail::MemberFunctionPointerTraits<Class_, volatile const Class_&, Return_(Arguments_..., ...) volatile const noexcept, Return_, std::tuple<Arguments_...>, true, true, true, false, false, true> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct FunctionPointer<Return_(Class_::*)(Arguments_...) & noexcept>
	: xieite::detail::MemberFunctionPointerTraits<Class_, Class_&, Return_(Arguments_...) & noexcept, Return_, std::tuple<Arguments_...>, false, false, false, true, false, true> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct FunctionPointer<Return_(Class_::*)(Arguments_..., ...) & noexcept>
	: xieite::detail::MemberFunctionPointerTraits<Class_, Class_&, Return_(Arguments_..., ...) & noexcept, Return_, std::tuple<Arguments_...>, true, false, false, true, false, true> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct FunctionPointer<Return_(Class_::*)(Arguments_...) const & noexcept>
	: xieite::detail::MemberFunctionPointerTraits<Class_, const Class_&, Return_(Arguments_...) const & noexcept, Return_, std::tuple<Arguments_...>, false, true, false, true, false, true> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct FunctionPointer<Return_(Class_::*)(Arguments_..., ...) const & noexcept>
	: xieite::detail::MemberFunctionPointerTraits<Class_, const Class_&, Return_(Arguments_..., ...) const & noexcept, Return_, std::tuple<Arguments_...>, true, true, false, true, false, true> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct FunctionPointer<Return_(Class_::*)(Arguments_...) volatile & noexcept>
	: xieite::detail::MemberFunctionPointerTraits<Class_, volatile Class_&, Return_(Arguments_...) volatile & noexcept, Return_, std::tuple<Arguments_...>, false, false, true, true, false, true> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct FunctionPointer<Return_(Class_::*)(Arguments_..., ...) volatile & noexcept>
	: xieite::detail::MemberFunctionPointerTraits<Class_, volatile Class_&, Return_(Arguments_..., ...) volatile & noexcept, Return_, std::tuple<Arguments_...>, true, false, true, true, false, true> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct FunctionPointer<Return_(Class_::*)(Arguments_...) volatile const & noexcept>
	: xieite::detail::MemberFunctionPointerTraits<Class_, volatile const Class_&, Return_(Arguments_...) volatile const & noexcept, Return_, std::tuple<Arguments_...>, false, true, true, true, false, true> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct FunctionPointer<Return_(Class_::*)(Arguments_..., ...) volatile const & noexcept>
	: xieite::detail::MemberFunctionPointerTraits<Class_, volatile const Class_&, Return_(Arguments_..., ...) volatile const & noexcept, Return_, std::tuple<Arguments_...>, true, true, true, true, false, true> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct FunctionPointer<Return_(Class_::*)(Arguments_...) && noexcept>
	: xieite::detail::MemberFunctionPointerTraits<Class_, Class_&&, Return_(Arguments_...) && noexcept, Return_, std::tuple<Arguments_...>, false, false, false, false, true, true> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct FunctionPointer<Return_(Class_::*)(Arguments_..., ...) && noexcept>
	: xieite::detail::MemberFunctionPointerTraits<Class_, Class_&&, Return_(Arguments_..., ...) && noexcept, Return_, std::tuple<Arguments_...>, true, false, false, false, true, true> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct FunctionPointer<Return_(Class_::*)(Arguments_...) const && noexcept>
	: xieite::detail::MemberFunctionPointerTraits<Class_, const Class_&&, Return_(Arguments_...) const && noexcept, Return_, std::tuple<Arguments_...>, false, true, false, false, true, true> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct FunctionPointer<Return_(Class_::*)(Arguments_..., ...) const && noexcept>
	: xieite::detail::MemberFunctionPointerTraits<Class_, const Class_&&, Return_(Arguments_..., ...) const && noexcept, Return_, std::tuple<Arguments_...>, true, true, false, false, true, true> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct FunctionPointer<Return_(Class_::*)(Arguments_...) volatile && noexcept>
	: xieite::detail::MemberFunctionPointerTraits<Class_, volatile Class_&&, Return_(Arguments_...) volatile && noexcept, Return_, std::tuple<Arguments_...>, false, false, true, false, true, true> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct FunctionPointer<Return_(Class_::*)(Arguments_..., ...) volatile && noexcept>
	: xieite::detail::MemberFunctionPointerTraits<Class_, volatile Class_&&, Return_(Arguments_..., ...) volatile && noexcept, Return_, std::tuple<Arguments_...>, true, false, true, false, true, true> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct FunctionPointer<Return_(Class_::*)(Arguments_...) volatile const && noexcept>
	: xieite::detail::MemberFunctionPointerTraits<Class_, volatile const Class_&&, Return_(Arguments_...) volatile const && noexcept, Return_, std::tuple<Arguments_...>, false, true, true, false, true, true> {};

	template<typename Return_, typename Class_, typename... Arguments_>
	struct FunctionPointer<Return_(Class_::*)(Arguments_..., ...) volatile const && noexcept>
	: xieite::detail::MemberFunctionPointerTraits<Class_, volatile const Class_&&, Return_(Arguments_..., ...) volatile const && noexcept, Return_, std::tuple<Arguments_...>, true, true, true, false, true, true> {};
}

#endif

// Thanks to halalaluyafail3 (https://github.com/Halalaluyafail3) for original code
