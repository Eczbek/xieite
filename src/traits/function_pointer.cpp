export module xieite:traits.FunctionPointer;

import std;

template<typename Function_, typename Return_, typename Arguments_, bool variadic_, bool noThrowQualified_>
struct FunctionPointerTraits {
	using Function = Function_;
	using Return = Return_;
	using Arguments = Arguments_;

	static constexpr bool variadic = variadic_;
	static constexpr bool noThrowQualified = noThrowQualified_;
};

template<typename Class_, typename Reference_, typename Function_, typename Return_, typename Arguments_, bool variadic_, bool constantQualified_, bool volatileQualified_, bool leftValueQualified_, bool rightValueQualified_, bool noThrowQualified_>
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
	static constexpr bool noThrowQualified = noThrowQualified_;
};

export namespace xieite::traits {
	template<typename>
	struct FunctionPointer;

	template<typename Return, typename... Arguments>
	struct FunctionPointer<Return(*)(Arguments...)>
	: FunctionPointerTraits<Return(Arguments...), Return, std::tuple<Arguments...>, false, false> {};

	template<typename Return, typename... Arguments>
	struct FunctionPointer<Return(*)(Arguments..., ...)>
	: FunctionPointerTraits<Return(Arguments..., ...), Return, std::tuple<Arguments...>, true, false> {};

	template<typename Return, typename... Arguments>
	struct FunctionPointer<Return(*)(Arguments...) noexcept>
	: FunctionPointerTraits<Return(Arguments...) noexcept, Return, std::tuple<Arguments...>, false, true> {};

	template<typename Return, typename... Arguments>
	struct FunctionPointer<Return(*)(Arguments..., ...) noexcept>
	: FunctionPointerTraits<Return(Arguments..., ...) noexcept, Return, std::tuple<Arguments...>, true, true> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments...)>
	: MemberFunctionPointerTraits<Class, Class&, Return(Arguments...), Return, std::tuple<Arguments...>, false, false, false, false, false, false> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments..., ...)>
	: MemberFunctionPointerTraits<Class, Class&, Return(Arguments..., ...), Return, std::tuple<Arguments...>, true, false, false, false, false, false> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments...) const>
	: MemberFunctionPointerTraits<Class, const Class&, Return(Arguments...) const, Return, std::tuple<Arguments...>, false, true, false, false, false, false> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments..., ...) const>
	: MemberFunctionPointerTraits<Class, const Class&, Return(Arguments..., ...) const, Return, std::tuple<Arguments...>, true, true, false, false, false, false> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments...) volatile>
	: MemberFunctionPointerTraits<Class, volatile Class&, Return(Arguments...) volatile, Return, std::tuple<Arguments...>, false, false, true, false, false, false> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments..., ...) volatile>
	: MemberFunctionPointerTraits<Class, volatile Class&, Return(Arguments..., ...) volatile, Return, std::tuple<Arguments...>, true, false, true, false, false, false> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments...) const volatile>
	: MemberFunctionPointerTraits<Class, const volatile Class&, Return(Arguments...) const volatile, Return, std::tuple<Arguments...>, false, true, true, false, false, false> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments..., ...) const volatile>
	: MemberFunctionPointerTraits<Class, const volatile Class&, Return(Arguments..., ...) const volatile, Return, std::tuple<Arguments...>, true, true, true, false, false, false> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments...) &>
	: MemberFunctionPointerTraits<Class, Class&, Return(Arguments...) &, Return, std::tuple<Arguments...>, false, false, false, true, false, false> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments..., ...) &>
	: MemberFunctionPointerTraits<Class, Class&, Return(Arguments..., ...) &, Return, std::tuple<Arguments...>, true, false, false, true, false, false> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments...) const &>
	: MemberFunctionPointerTraits<Class, const Class&, Return(Arguments...) const &, Return, std::tuple<Arguments...>, false, true, false, true, false, false> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments..., ...) const &>
	: MemberFunctionPointerTraits<Class, const Class&, Return(Arguments..., ...) const &, Return, std::tuple<Arguments...>, true, true, false, true, false, false> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments...) volatile &>
	: MemberFunctionPointerTraits<Class, volatile Class&, Return(Arguments...) volatile &, Return, std::tuple<Arguments...>, false, false, true, true, false, false> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments..., ...) volatile &>
	: MemberFunctionPointerTraits<Class, volatile Class&, Return(Arguments..., ...) volatile &, Return, std::tuple<Arguments...>, true, false, true, true, false, false> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments...) const volatile &>
	: MemberFunctionPointerTraits<Class, const volatile Class&, Return(Arguments...) const volatile &, Return, std::tuple<Arguments...>, false, true, true, true, false, false> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments..., ...) const volatile &>
	: MemberFunctionPointerTraits<Class, const volatile Class&, Return(Arguments..., ...) const volatile &, Return, std::tuple<Arguments...>, true, true, true, true, false, false> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments...) &&>
	: MemberFunctionPointerTraits<Class, Class&&, Return(Arguments...) &&, Return, std::tuple<Arguments...>, false, false, false, false, true, false> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments..., ...) &&>
	: MemberFunctionPointerTraits<Class, Class&&, Return(Arguments..., ...) &&, Return, std::tuple<Arguments...>, true, false, false, false, true, false> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments...) const &&>
	: MemberFunctionPointerTraits<Class, const Class&&, Return(Arguments...) const &&, Return, std::tuple<Arguments...>, false, true, false, false, true, false> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments..., ...) const &&>
	: MemberFunctionPointerTraits<Class, const Class&&, Return(Arguments..., ...) const &&, Return, std::tuple<Arguments...>, true, true, false, false, true, false> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments...) volatile &&>
	: MemberFunctionPointerTraits<Class, volatile Class&&, Return(Arguments...) volatile &&, Return, std::tuple<Arguments...>, false, false, true, false, true, false> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments..., ...) volatile &&>
	: MemberFunctionPointerTraits<Class, volatile Class&&, Return(Arguments..., ...) volatile &&, Return, std::tuple<Arguments...>, true, false, true, false, true, false> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments...) const volatile &&>
	: MemberFunctionPointerTraits<Class, const volatile Class&&, Return(Arguments...) const volatile &&, Return, std::tuple<Arguments...>, false, true, true, false, true, false> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments..., ...) const volatile &&>
	: MemberFunctionPointerTraits<Class, const volatile Class&&, Return(Arguments..., ...) const volatile &&, Return, std::tuple<Arguments...>, true, true, true, false, true, false> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments...) noexcept>
	: MemberFunctionPointerTraits<Class, Class&, Return(Arguments...) noexcept, Return, std::tuple<Arguments...>, false, false, false, false, false, true> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments..., ...) noexcept>
	: MemberFunctionPointerTraits<Class, Class&, Return(Arguments..., ...) noexcept, Return, std::tuple<Arguments...>, true, false, false, false, false, true> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments...) const noexcept>
	: MemberFunctionPointerTraits<Class, const Class&, Return(Arguments...) const noexcept, Return, std::tuple<Arguments...>, false, true, false, false, false, true> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments..., ...) const noexcept>
	: MemberFunctionPointerTraits<Class, const Class&, Return(Arguments..., ...) const noexcept, Return, std::tuple<Arguments...>, true, true, false, false, false, true> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments...) volatile noexcept>
	: MemberFunctionPointerTraits<Class, volatile Class&, Return(Arguments...) volatile noexcept, Return, std::tuple<Arguments...>, false, false, true, false, false, true> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments..., ...) volatile noexcept>
	: MemberFunctionPointerTraits<Class, volatile Class&, Return(Arguments..., ...) volatile noexcept, Return, std::tuple<Arguments...>, true, false, true, false, false, true> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments...) const volatile noexcept>
	: MemberFunctionPointerTraits<Class, const volatile Class&, Return(Arguments...) const volatile noexcept, Return, std::tuple<Arguments...>, false, true, true, false, false, true> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments..., ...) const volatile noexcept>
	: MemberFunctionPointerTraits<Class, const volatile Class&, Return(Arguments..., ...) const volatile noexcept, Return, std::tuple<Arguments...>, true, true, true, false, false, true> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments...) & noexcept>
	: MemberFunctionPointerTraits<Class, Class&, Return(Arguments...) & noexcept, Return, std::tuple<Arguments...>, false, false, false, true, false, true> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments..., ...) & noexcept>
	: MemberFunctionPointerTraits<Class, Class&, Return(Arguments..., ...) & noexcept, Return, std::tuple<Arguments...>, true, false, false, true, false, true> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments...) const & noexcept>
	: MemberFunctionPointerTraits<Class, const Class&, Return(Arguments...) const & noexcept, Return, std::tuple<Arguments...>, false, true, false, true, false, true> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments..., ...) const & noexcept>
	: MemberFunctionPointerTraits<Class, const Class&, Return(Arguments..., ...) const & noexcept, Return, std::tuple<Arguments...>, true, true, false, true, false, true> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments...) volatile & noexcept>
	: MemberFunctionPointerTraits<Class, volatile Class&, Return(Arguments...) volatile & noexcept, Return, std::tuple<Arguments...>, false, false, true, true, false, true> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments..., ...) volatile & noexcept>
	: MemberFunctionPointerTraits<Class, volatile Class&, Return(Arguments..., ...) volatile & noexcept, Return, std::tuple<Arguments...>, true, false, true, true, false, true> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments...) const volatile & noexcept>
	: MemberFunctionPointerTraits<Class, const volatile Class&, Return(Arguments...) const volatile & noexcept, Return, std::tuple<Arguments...>, false, true, true, true, false, true> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments..., ...) const volatile & noexcept>
	: MemberFunctionPointerTraits<Class, const volatile Class&, Return(Arguments..., ...) const volatile & noexcept, Return, std::tuple<Arguments...>, true, true, true, true, false, true> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments...) && noexcept>
	: MemberFunctionPointerTraits<Class, Class&&, Return(Arguments...) && noexcept, Return, std::tuple<Arguments...>, false, false, false, false, true, true> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments..., ...) && noexcept>
	: MemberFunctionPointerTraits<Class, Class&&, Return(Arguments..., ...) && noexcept, Return, std::tuple<Arguments...>, true, false, false, false, true, true> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments...) const && noexcept>
	: MemberFunctionPointerTraits<Class, const Class&&, Return(Arguments...) const && noexcept, Return, std::tuple<Arguments...>, false, true, false, false, true, true> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments..., ...) const && noexcept>
	: MemberFunctionPointerTraits<Class, const Class&&, Return(Arguments..., ...) const && noexcept, Return, std::tuple<Arguments...>, true, true, false, false, true, true> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments...) volatile && noexcept>
	: MemberFunctionPointerTraits<Class, volatile Class&&, Return(Arguments...) volatile && noexcept, Return, std::tuple<Arguments...>, false, false, true, false, true, true> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments..., ...) volatile && noexcept>
	: MemberFunctionPointerTraits<Class, volatile Class&&, Return(Arguments..., ...) volatile && noexcept, Return, std::tuple<Arguments...>, true, false, true, false, true, true> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments...) const volatile && noexcept>
	: MemberFunctionPointerTraits<Class, const volatile Class&&, Return(Arguments...) const volatile && noexcept, Return, std::tuple<Arguments...>, false, true, true, false, true, true> {};

	template<typename Return, typename Class, typename... Arguments>
	struct FunctionPointer<Return(Class::*)(Arguments..., ...) const volatile && noexcept>
	: MemberFunctionPointerTraits<Class, const volatile Class&&, Return(Arguments..., ...) const volatile && noexcept, Return, std::tuple<Arguments...>, true, true, true, false, true, true> {};
}

// Thanks to halalaluyafail3 (https://github.com/Halalaluyafail3) for original code
