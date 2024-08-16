#ifndef XIEITE_HEADER_TRAITS_FUNCTION_POINTER
#	define XIEITE_HEADER_TRAITS_FUNCTION_POINTER

#	include <tuple>

namespace xieite::detail {
	template<typename Function, typename Return, typename Arguments, bool variadic, bool noThrowQualified>
	struct FunctionPointerTraits {
		using Function = Function;
		using Return = Return;
		using Arguments = Arguments;

		static constexpr bool variadic = variadic;
		static constexpr bool noThrowQualified = noThrowQualified;
	};

	template<typename Class, typename Reference, typename Function, typename Return, typename Arguments, bool variadic, bool constantQualified, bool volatileQualified, bool leftValueQualified, bool rightValueQualified, bool noThrowQualified>
	struct MemberFunctionPointerTraits {
		using Class = Class;
		using Reference = Reference;
		using Function = Function;
		using Return = Return;
		using Arguments = Arguments;

		static constexpr bool variadic = variadic;
		static constexpr bool constantQualified = constantQualified;
		static constexpr bool volatileQualified = volatileQualified;
		static constexpr bool leftValueQualified = leftValueQualified;
		static constexpr bool rightValueQualified = rightValueQualified;
		static constexpr bool noThrowQualified = noThrowQualified;
	};
}

namespace xieite::traits {
	template<typename>
	struct FunctionPointer;

	template<typename Return, typename... Arguments>
	struct FunctionPointer<Return(*)(Arguments...)>
	: xieite::detail::FunctionPointerTraits<Return(Arguments...), Return, std::tuple<Arguments...>, false, false> {};

	template<typename Return, typename... Arguments>
	struct FunctionPointer<Return(*)(Arguments..., ...)>
	: xieite::detail::FunctionPointerTraits<Return(Arguments..., ...), Return, std::tuple<Arguments...>, true, false> {};

	template<typename Return, typename... Arguments>
	struct FunctionPointer<Return(*)(Arguments...) noexcept>
	: xieite::detail::FunctionPointerTraits<Return(Arguments...) noexcept, Return, std::tuple<Arguments...>, false, true> {};

	template<typename Return, typename... Arguments>
	struct FunctionPointer<Return(*)(Arguments..., ...) noexcept>
	: xieite::detail::FunctionPointerTraits<Return(Arguments..., ...) noexcept, Return, std::tuple<Arguments...>, true, true> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments...)>
	: xieite::detail::MemberFunctionPointerTraits<Class, Class&, Return(Arguments...), Return, std::tuple<Arguments...>, false, false, false, false, false, false> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments..., ...)>
	: xieite::detail::MemberFunctionPointerTraits<Class, Class&, Return(Arguments..., ...), Return, std::tuple<Arguments...>, true, false, false, false, false, false> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments...) const>
	: xieite::detail::MemberFunctionPointerTraits<Class, const Class&, Return(Arguments...) const, Return, std::tuple<Arguments...>, false, true, false, false, false, false> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments..., ...) const>
	: xieite::detail::MemberFunctionPointerTraits<Class, const Class&, Return(Arguments..., ...) const, Return, std::tuple<Arguments...>, true, true, false, false, false, false> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments...) volatile>
	: xieite::detail::MemberFunctionPointerTraits<Class, volatile Class&, Return(Arguments...) volatile, Return, std::tuple<Arguments...>, false, false, true, false, false, false> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments..., ...) volatile>
	: xieite::detail::MemberFunctionPointerTraits<Class, volatile Class&, Return(Arguments..., ...) volatile, Return, std::tuple<Arguments...>, true, false, true, false, false, false> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments...) const volatile>
	: xieite::detail::MemberFunctionPointerTraits<Class, const volatile Class&, Return(Arguments...) const volatile, Return, std::tuple<Arguments...>, false, true, true, false, false, false> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments..., ...) const volatile>
	: xieite::detail::MemberFunctionPointerTraits<Class, const volatile Class&, Return(Arguments..., ...) const volatile, Return, std::tuple<Arguments...>, true, true, true, false, false, false> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments...) &>
	: xieite::detail::MemberFunctionPointerTraits<Class, Class&, Return(Arguments...) &, Return, std::tuple<Arguments...>, false, false, false, true, false, false> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments..., ...) &>
	: xieite::detail::MemberFunctionPointerTraits<Class, Class&, Return(Arguments..., ...) &, Return, std::tuple<Arguments...>, true, false, false, true, false, false> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments...) const &>
	: xieite::detail::MemberFunctionPointerTraits<Class, const Class&, Return(Arguments...) const &, Return, std::tuple<Arguments...>, false, true, false, true, false, false> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments..., ...) const &>
	: xieite::detail::MemberFunctionPointerTraits<Class, const Class&, Return(Arguments..., ...) const &, Return, std::tuple<Arguments...>, true, true, false, true, false, false> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments...) volatile &>
	: xieite::detail::MemberFunctionPointerTraits<Class, volatile Class&, Return(Arguments...) volatile &, Return, std::tuple<Arguments...>, false, false, true, true, false, false> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments..., ...) volatile &>
	: xieite::detail::MemberFunctionPointerTraits<Class, volatile Class&, Return(Arguments..., ...) volatile &, Return, std::tuple<Arguments...>, true, false, true, true, false, false> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments...) const volatile &>
	: xieite::detail::MemberFunctionPointerTraits<Class, const volatile Class&, Return(Arguments...) const volatile &, Return, std::tuple<Arguments...>, false, true, true, true, false, false> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments..., ...) const volatile &>
	: xieite::detail::MemberFunctionPointerTraits<Class, const volatile Class&, Return(Arguments..., ...) const volatile &, Return, std::tuple<Arguments...>, true, true, true, true, false, false> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments...) &&>
	: xieite::detail::MemberFunctionPointerTraits<Class, Class&&, Return(Arguments...) &&, Return, std::tuple<Arguments...>, false, false, false, false, true, false> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments..., ...) &&>
	: xieite::detail::MemberFunctionPointerTraits<Class, Class&&, Return(Arguments..., ...) &&, Return, std::tuple<Arguments...>, true, false, false, false, true, false> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments...) const &&>
	: xieite::detail::MemberFunctionPointerTraits<Class, const Class&&, Return(Arguments...) const &&, Return, std::tuple<Arguments...>, false, true, false, false, true, false> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments..., ...) const &&>
	: xieite::detail::MemberFunctionPointerTraits<Class, const Class&&, Return(Arguments..., ...) const &&, Return, std::tuple<Arguments...>, true, true, false, false, true, false> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments...) volatile &&>
	: xieite::detail::MemberFunctionPointerTraits<Class, volatile Class&&, Return(Arguments...) volatile &&, Return, std::tuple<Arguments...>, false, false, true, false, true, false> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments..., ...) volatile &&>
	: xieite::detail::MemberFunctionPointerTraits<Class, volatile Class&&, Return(Arguments..., ...) volatile &&, Return, std::tuple<Arguments...>, true, false, true, false, true, false> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments...) const volatile &&>
	: xieite::detail::MemberFunctionPointerTraits<Class, const volatile Class&&, Return(Arguments...) const volatile &&, Return, std::tuple<Arguments...>, false, true, true, false, true, false> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments..., ...) const volatile &&>
	: xieite::detail::MemberFunctionPointerTraits<Class, const volatile Class&&, Return(Arguments..., ...) const volatile &&, Return, std::tuple<Arguments...>, true, true, true, false, true, false> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments...) noexcept>
	: xieite::detail::MemberFunctionPointerTraits<Class, Class&, Return(Arguments...) noexcept, Return, std::tuple<Arguments...>, false, false, false, false, false, true> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments..., ...) noexcept>
	: xieite::detail::MemberFunctionPointerTraits<Class, Class&, Return(Arguments..., ...) noexcept, Return, std::tuple<Arguments...>, true, false, false, false, false, true> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments...) const noexcept>
	: xieite::detail::MemberFunctionPointerTraits<Class, const Class&, Return(Arguments...) const noexcept, Return, std::tuple<Arguments...>, false, true, false, false, false, true> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments..., ...) const noexcept>
	: xieite::detail::MemberFunctionPointerTraits<Class, const Class&, Return(Arguments..., ...) const noexcept, Return, std::tuple<Arguments...>, true, true, false, false, false, true> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments...) volatile noexcept>
	: xieite::detail::MemberFunctionPointerTraits<Class, volatile Class&, Return(Arguments...) volatile noexcept, Return, std::tuple<Arguments...>, false, false, true, false, false, true> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments..., ...) volatile noexcept>
	: xieite::detail::MemberFunctionPointerTraits<Class, volatile Class&, Return(Arguments..., ...) volatile noexcept, Return, std::tuple<Arguments...>, true, false, true, false, false, true> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments...) const volatile noexcept>
	: xieite::detail::MemberFunctionPointerTraits<Class, const volatile Class&, Return(Arguments...) const volatile noexcept, Return, std::tuple<Arguments...>, false, true, true, false, false, true> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments..., ...) const volatile noexcept>
	: xieite::detail::MemberFunctionPointerTraits<Class, const volatile Class&, Return(Arguments..., ...) const volatile noexcept, Return, std::tuple<Arguments...>, true, true, true, false, false, true> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments...) & noexcept>
	: xieite::detail::MemberFunctionPointerTraits<Class, Class&, Return(Arguments...) & noexcept, Return, std::tuple<Arguments...>, false, false, false, true, false, true> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments..., ...) & noexcept>
	: xieite::detail::MemberFunctionPointerTraits<Class, Class&, Return(Arguments..., ...) & noexcept, Return, std::tuple<Arguments...>, true, false, false, true, false, true> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments...) const & noexcept>
	: xieite::detail::MemberFunctionPointerTraits<Class, const Class&, Return(Arguments...) const & noexcept, Return, std::tuple<Arguments...>, false, true, false, true, false, true> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments..., ...) const & noexcept>
	: xieite::detail::MemberFunctionPointerTraits<Class, const Class&, Return(Arguments..., ...) const & noexcept, Return, std::tuple<Arguments...>, true, true, false, true, false, true> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments...) volatile & noexcept>
	: xieite::detail::MemberFunctionPointerTraits<Class, volatile Class&, Return(Arguments...) volatile & noexcept, Return, std::tuple<Arguments...>, false, false, true, true, false, true> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments..., ...) volatile & noexcept>
	: xieite::detail::MemberFunctionPointerTraits<Class, volatile Class&, Return(Arguments..., ...) volatile & noexcept, Return, std::tuple<Arguments...>, true, false, true, true, false, true> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments...) const volatile & noexcept>
	: xieite::detail::MemberFunctionPointerTraits<Class, const volatile Class&, Return(Arguments...) const volatile & noexcept, Return, std::tuple<Arguments...>, false, true, true, true, false, true> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments..., ...) const volatile & noexcept>
	: xieite::detail::MemberFunctionPointerTraits<Class, const volatile Class&, Return(Arguments..., ...) const volatile & noexcept, Return, std::tuple<Arguments...>, true, true, true, true, false, true> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments...) && noexcept>
	: xieite::detail::MemberFunctionPointerTraits<Class, Class&&, Return(Arguments...) && noexcept, Return, std::tuple<Arguments...>, false, false, false, false, true, true> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments..., ...) && noexcept>
	: xieite::detail::MemberFunctionPointerTraits<Class, Class&&, Return(Arguments..., ...) && noexcept, Return, std::tuple<Arguments...>, true, false, false, false, true, true> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments...) const && noexcept>
	: xieite::detail::MemberFunctionPointerTraits<Class, const Class&&, Return(Arguments...) const && noexcept, Return, std::tuple<Arguments...>, false, true, false, false, true, true> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments..., ...) const && noexcept>
	: xieite::detail::MemberFunctionPointerTraits<Class, const Class&&, Return(Arguments..., ...) const && noexcept, Return, std::tuple<Arguments...>, true, true, false, false, true, true> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments...) volatile && noexcept>
	: xieite::detail::MemberFunctionPointerTraits<Class, volatile Class&&, Return(Arguments...) volatile && noexcept, Return, std::tuple<Arguments...>, false, false, true, false, true, true> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments..., ...) volatile && noexcept>
	: xieite::detail::MemberFunctionPointerTraits<Class, volatile Class&&, Return(Arguments..., ...) volatile && noexcept, Return, std::tuple<Arguments...>, true, false, true, false, true, true> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments...) const volatile && noexcept>
	: xieite::detail::MemberFunctionPointerTraits<Class, const volatile Class&&, Return(Arguments...) const volatile && noexcept, Return, std::tuple<Arguments...>, false, true, true, false, true, true> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments..., ...) const volatile && noexcept>
	: xieite::detail::MemberFunctionPointerTraits<Class, const volatile Class&&, Return(Arguments..., ...) const volatile && noexcept, Return, std::tuple<Arguments...>, true, true, true, false, true, true> {};
}

#endif

// Thanks to halalaluyafail3 (https://github.com/Halalaluyafail3) for original code
