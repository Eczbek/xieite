#ifndef XIEITE_HEADER_TRAITS_FUNCTION_POINTER
#	define XIEITE_HEADER_TRAITS_FUNCTION_POINTER

#	include <tuple>

namespace xieite::traits {
	template<typename>
	struct FunctionPointer;

	template<typename Return, typename... Arguments, bool nonThrowing>
	struct FunctionPointer<Return(*)(Arguments...) noexcept(nonThrowing)> {
		using FunctionType = Return(Arguments...);
		using ReturnType = Return;
		using ArgumentTypes = std::tuple<Arguments...>;

		static constexpr bool isVariadic = false;
		static constexpr bool isNonThrowing = nonThrowing;
	};

	template<typename Return, typename... Arguments, bool nonThrowing>
	struct FunctionPointer<Return(*)(Arguments......) noexcept(nonThrowing)> {
		using FunctionType = Return(Arguments......);
		using ReturnType = Return;
		using ArgumentTypes = std::tuple<Arguments...>;

		static constexpr bool isVariadic = true;
		static constexpr bool isNonThrowing = nonThrowing;
	};

	template<typename Return, typename Class, typename... Arguments, bool nonThrowing>
	struct FunctionPointer<Return(Class::*)(Arguments...) noexcept(nonThrowing)> {
		using ClassType = Class;
		using ReferenceType = Class&;
		using FunctionType = Return(Arguments...);
		using ReturnType = Return;
		using ArgumentTypes = std::tuple<Arguments...>;

		static constexpr bool isVariadic = false;
		static constexpr bool isConstant = false;
		static constexpr bool isVolatile = false;
		static constexpr bool isLeftValueReference = false;
		static constexpr bool isRightValueReference = false;
		static constexpr bool isNonThrowing = nonThrowing;
	};

	template<typename Return, typename Class, typename... Arguments, bool nonThrowing>
	struct FunctionPointer<Return(Class::*)(Arguments......) noexcept(nonThrowing)> {
		using ClassType = Class;
		using ReferenceType = Class&;
		using FunctionType = Return(Arguments......);
		using ReturnType = Return;
		using ArgumentTypes = std::tuple<Arguments...>;

		static constexpr bool isVariadic = true;
		static constexpr bool isConstant = false;
		static constexpr bool isVolatile = false;
		static constexpr bool isLeftValueReference = false;
		static constexpr bool isRightValueReference = false;
		static constexpr bool isNonThrowing = nonThrowing;
	};

	template<typename Return, typename Class, typename... Arguments, bool nonThrowing>
	struct FunctionPointer<Return(Class::*)(Arguments...) const noexcept(nonThrowing)> {
		using ClassType = Class;
		using ReferenceType = const Class&;
		using FunctionType = Return(Arguments...) const;
		using ReturnType = Return;
		using ArgumentTypes = std::tuple<Arguments...>;

		static constexpr bool isVariadic = false;
		static constexpr bool isConstant = true;
		static constexpr bool isVolatile = false;
		static constexpr bool isLeftValueReference = false;
		static constexpr bool isRightValueReference = false;
		static constexpr bool isNonThrowing = nonThrowing;
	};

	template<typename Return, typename Class, typename... Arguments, bool nonThrowing>
	struct FunctionPointer<Return(Class::*)(Arguments......) const noexcept(nonThrowing)> {
		using ClassType = Class;
		using ReferenceType = const Class&;
		using FunctionType = Return(Arguments......) const;
		using ReturnType = Return;
		using ArgumentTypes = std::tuple<Arguments...>;

		static constexpr bool isVariadic = true;
		static constexpr bool isConstant = true;
		static constexpr bool isVolatile = false;
		static constexpr bool isLeftValueReference = false;
		static constexpr bool isRightValueReference = false;
		static constexpr bool isNonThrowing = nonThrowing;
	};

	template<typename Return, typename Class, typename... Arguments, bool nonThrowing>
	struct FunctionPointer<Return(Class::*)(Arguments...) volatile noexcept(nonThrowing)> {
		using ClassType = Class;
		using ReferenceType = volatile Class&;
		using FunctionType = Return(Arguments...) volatile;
		using ReturnType = Return;
		using ArgumentTypes = std::tuple<Arguments...>;

		static constexpr bool isVariadic = false;
		static constexpr bool isConstant = false;
		static constexpr bool isVolatile = true;
		static constexpr bool isLeftValueReference = false;
		static constexpr bool isRightValueReference = false;
		static constexpr bool isNonThrowing = nonThrowing;
	};

	template<typename Return, typename Class, typename... Arguments, bool nonThrowing>
	struct FunctionPointer<Return(Class::*)(Arguments......) volatile noexcept(nonThrowing)> {
		using ClassType = Class;
		using ReferenceType = volatile Class&;
		using FunctionType = Return(Arguments......) volatile;
		using ReturnType = Return;
		using ArgumentTypes = std::tuple<Arguments...>;

		static constexpr bool isVariadic = true;
		static constexpr bool isConstant = false;
		static constexpr bool isVolatile = true;
		static constexpr bool isLeftValueReference = false;
		static constexpr bool isRightValueReference = false;
		static constexpr bool isNonThrowing = nonThrowing;
	};

	template<typename Return, typename Class, typename... Arguments, bool nonThrowing>
	struct FunctionPointer<Return(Class::*)(Arguments...) const volatile noexcept(nonThrowing)> {
		using ClassType = Class;
		using ReferenceType = const volatile Class&;
		using FunctionType = Return(Arguments...) const volatile;
		using ReturnType = Return;
		using ArgumentTypes = std::tuple<Arguments...>;

		static constexpr bool isVariadic = false;
		static constexpr bool isConstant = true;
		static constexpr bool isVolatile = true;
		static constexpr bool isLeftValueReference = false;
		static constexpr bool isRightValueReference = false;
		static constexpr bool isNonThrowing = nonThrowing;
	};

	template<typename Return, typename Class, typename... Arguments, bool nonThrowing>
	struct FunctionPointer<Return(Class::*)(Arguments......) const volatile noexcept(nonThrowing)> {
		using ClassType = Class;
		using ReferenceType = const volatile Class&;
		using FunctionType = Return(Arguments......) const volatile;
		using ReturnType = Return;
		using ArgumentTypes = std::tuple<Arguments...>;

		static constexpr bool isVariadic = true;
		static constexpr bool isConstant = true;
		static constexpr bool isVolatile = true;
		static constexpr bool isLeftValueReference = false;
		static constexpr bool isRightValueReference = false;
		static constexpr bool isNonThrowing = nonThrowing;
	};

	template<typename Return, typename Class, typename... Arguments, bool nonThrowing>
	struct FunctionPointer<Return(Class::*)(Arguments...)& noexcept(nonThrowing)> {
		using ClassType = Class;
		using ReferenceType = Class&;
		using FunctionType = Return(Arguments...)&;
		using ReturnType = Return;
		using ArgumentTypes = std::tuple<Arguments...>;

		static constexpr bool isVariadic = false;
		static constexpr bool isConstant = false;
		static constexpr bool isVolatile = false;
		static constexpr bool isLeftValueReference = true;
		static constexpr bool isRightValueReference = false;
		static constexpr bool isNonThrowing = nonThrowing;
	};

	template<typename Return, typename Class, typename... Arguments, bool nonThrowing>
	struct FunctionPointer<Return(Class::*)(Arguments......)& noexcept(nonThrowing)> {
		using ClassType = Class;
		using ReferenceType = Class&;
		using FunctionType = Return(Arguments......)&;
		using ReturnType = Return;
		using ArgumentTypes = std::tuple<Arguments...>;

		static constexpr bool isVariadic = true;
		static constexpr bool isConstant = false;
		static constexpr bool isVolatile = false;
		static constexpr bool isLeftValueReference = true;
		static constexpr bool isRightValueReference = false;
		static constexpr bool isNonThrowing = nonThrowing;
	};

	template<typename Return, typename Class, typename... Arguments, bool nonThrowing>
	struct FunctionPointer<Return(Class::*)(Arguments...) const& noexcept(nonThrowing)> {
		using ClassType = Class;
		using ReferenceType = const Class&;
		using FunctionType = Return(Arguments...) const&;
		using ReturnType = Return;
		using ArgumentTypes = std::tuple<Arguments...>;

		static constexpr bool isVariadic = false;
		static constexpr bool isConstant = true;
		static constexpr bool isVolatile = false;
		static constexpr bool isLeftValueReference = true;
		static constexpr bool isRightValueReference = false;
		static constexpr bool isNonThrowing = nonThrowing;
	};

	template<typename Return, typename Class, typename... Arguments, bool nonThrowing>
	struct FunctionPointer<Return(Class::*)(Arguments......) const& noexcept(nonThrowing)> {
		using ClassType = Class;
		using ReferenceType = const Class&;
		using FunctionType = Return(Arguments......) const&;
		using ReturnType = Return;
		using ArgumentTypes = std::tuple<Arguments...>;

		static constexpr bool isVariadic = true;
		static constexpr bool isConstant = true;
		static constexpr bool isVolatile = false;
		static constexpr bool isLeftValueReference = true;
		static constexpr bool isRightValueReference = false;
		static constexpr bool isNonThrowing = nonThrowing;
	};

	template<typename Return, typename Class, typename... Arguments, bool nonThrowing>
	struct FunctionPointer<Return(Class::*)(Arguments...) volatile& noexcept(nonThrowing)> {
		using ClassType = Class;
		using ReferenceType = volatile Class&;
		using FunctionType = Return(Arguments...) volatile&;
		using ReturnType = Return;
		using ArgumentTypes = std::tuple<Arguments...>;

		static constexpr bool isVariadic = false;
		static constexpr bool isConstant = false;
		static constexpr bool isVolatile = true;
		static constexpr bool isLeftValueReference = true;
		static constexpr bool isRightValueReference = false;
		static constexpr bool isNonThrowing = nonThrowing;
	};

	template<typename Return, typename Class, typename... Arguments, bool nonThrowing>
	struct FunctionPointer<Return(Class::*)(Arguments......) volatile& noexcept(nonThrowing)> {
		using ClassType = Class;
		using ReferenceType = volatile Class&;
		using FunctionType = Return(Arguments......) volatile&;
		using ReturnType = Return;
		using ArgumentTypes = std::tuple<Arguments...>;

		static constexpr bool isVariadic = true;
		static constexpr bool isConstant = false;
		static constexpr bool isVolatile = true;
		static constexpr bool isLeftValueReference = true;
		static constexpr bool isRightValueReference = false;
		static constexpr bool isNonThrowing = nonThrowing;
	};

	template<typename Return, typename Class, typename... Arguments, bool nonThrowing>
	struct FunctionPointer<Return(Class::*)(Arguments...) const volatile& noexcept(nonThrowing)> {
		using ClassType = Class;
		using ReferenceType = const volatile Class&;
		using FunctionType = Return(Arguments...) const volatile&;
		using ReturnType = Return;
		using ArgumentTypes = std::tuple<Arguments...>;

		static constexpr bool isVariadic = false;
		static constexpr bool isConstant = true;
		static constexpr bool isVolatile = true;
		static constexpr bool isLeftValueReference = true;
		static constexpr bool isRightValueReference = false;
		static constexpr bool isNonThrowing = nonThrowing;
	};

	template<typename Return, typename Class, typename... Arguments, bool nonThrowing>
	struct FunctionPointer<Return(Class::*)(Arguments......) const volatile& noexcept(nonThrowing)> {
		using ClassType = Class;
		using ReferenceType = const volatile Class&;
		using FunctionType = Return(Arguments......) const volatile&;
		using ReturnType = Return;
		using ArgumentTypes = std::tuple<Arguments...>;

		static constexpr bool isVariadic = true;
		static constexpr bool isConstant = true;
		static constexpr bool isVolatile = true;
		static constexpr bool isLeftValueReference = true;
		static constexpr bool isRightValueReference = false;
		static constexpr bool isNonThrowing = nonThrowing;
	};

	template<typename Return, typename Class, typename... Arguments, bool nonThrowing>
	struct FunctionPointer<Return(Class::*)(Arguments...)&& noexcept(nonThrowing)> {
		using ClassType = Class;
		using ReferenceType = Class&&;
		using FunctionType = Return(Arguments...)&&;
		using ReturnType = Return;
		using ArgumentTypes = std::tuple<Arguments...>;

		static constexpr bool isVariadic = false;
		static constexpr bool isConstant = false;
		static constexpr bool isVolatile = false;
		static constexpr bool isLeftValueReference = false;
		static constexpr bool isRightValueReference = true;
		static constexpr bool isNonThrowing = nonThrowing;
	};

	template<typename Return, typename Class, typename... Arguments, bool nonThrowing>
	struct FunctionPointer<Return(Class::*)(Arguments......)&& noexcept(nonThrowing)> {
		using ClassType = Class;
		using ReferenceType = Class&&;
		using FunctionType = Return(Arguments......)&&;
		using ReturnType = Return;
		using ArgumentTypes = std::tuple<Arguments...>;

		static constexpr bool isVariadic = true;
		static constexpr bool isConstant = false;
		static constexpr bool isVolatile = false;
		static constexpr bool isLeftValueReference = false;
		static constexpr bool isRightValueReference = true;
		static constexpr bool isNonThrowing = nonThrowing;
	};

	template<typename Return, typename Class, typename... Arguments, bool nonThrowing>
	struct FunctionPointer<Return(Class::*)(Arguments...) const&& noexcept(nonThrowing)> {
		using ClassType = Class;
		using ReferenceType = const Class&&;
		using FunctionType = Return(Arguments...) const&&;
		using ReturnType = Return;
		using ArgumentTypes = std::tuple<Arguments...>;

		static constexpr bool isVariadic = false;
		static constexpr bool isConstant = true;
		static constexpr bool isVolatile = false;
		static constexpr bool isLeftValueReference = false;
		static constexpr bool isRightValueReference = true;
		static constexpr bool isNonThrowing = nonThrowing;
	};

	template<typename Return, typename Class, typename... Arguments, bool nonThrowing>
	struct FunctionPointer<Return(Class::*)(Arguments......) const&& noexcept(nonThrowing)> {
		using ClassType = Class;
		using ReferenceType = const Class&&;
		using FunctionType = Return(Arguments......) const&&;
		using ReturnType = Return;
		using ArgumentTypes = std::tuple<Arguments...>;

		static constexpr bool isVariadic = true;
		static constexpr bool isConstant = true;
		static constexpr bool isVolatile = false;
		static constexpr bool isLeftValueReference = false;
		static constexpr bool isRightValueReference = true;
		static constexpr bool isNonThrowing = nonThrowing;
	};

	template<typename Return, typename Class, typename... Arguments, bool nonThrowing>
	struct FunctionPointer<Return(Class::*)(Arguments...) volatile&& noexcept(nonThrowing)> {
		using ClassType = Class;
		using ReferenceType = volatile Class&&;
		using FunctionType = Return(Arguments...) volatile&&;
		using ReturnType = Return;
		using ArgumentTypes = std::tuple<Arguments...>;

		static constexpr bool isVariadic = false;
		static constexpr bool isConstant = false;
		static constexpr bool isVolatile = true;
		static constexpr bool isLeftValueReference = false;
		static constexpr bool isRightValueReference = true;
		static constexpr bool isNonThrowing = nonThrowing;
	};

	template<typename Return, typename Class, typename... Arguments, bool nonThrowing>
	struct FunctionPointer<Return(Class::*)(Arguments......) volatile&& noexcept(nonThrowing)> {
		using ClassType = Class;
		using ReferenceType = volatile Class&&;
		using FunctionType = Return(Arguments......) volatile&&;
		using ReturnType = Return;
		using ArgumentTypes = std::tuple<Arguments...>;

		static constexpr bool isVariadic = true;
		static constexpr bool isConstant = false;
		static constexpr bool isVolatile = true;
		static constexpr bool isLeftValueReference = false;
		static constexpr bool isRightValueReference = true;
		static constexpr bool isNonThrowing = nonThrowing;
	};

	template<typename Return, typename Class, typename... Arguments, bool nonThrowing>
	struct FunctionPointer<Return(Class::*)(Arguments...) const volatile&& noexcept(nonThrowing)> {
		using ClassType = Class;
		using ReferenceType = const volatile Class&&;
		using FunctionType = Return(Arguments...) const volatile&&;
		using ReturnType = Return;
		using ArgumentTypes = std::tuple<Arguments...>;

		static constexpr bool isVariadic = false;
		static constexpr bool isConstant = true;
		static constexpr bool isVolatile = true;
		static constexpr bool isLeftValueReference = false;
		static constexpr bool isRightValueReference = true;
		static constexpr bool isNonThrowing = nonThrowing;
	};

	template<typename Return, typename Class, typename... Arguments, bool nonThrowing>
	struct FunctionPointer<Return(Class::*)(Arguments......) const volatile&& noexcept(nonThrowing)> {
		using ClassType = Class;
		using ReferenceType = const volatile Class&&;
		using FunctionType = Return(Arguments......) const volatile&&;
		using ReturnType = Return;
		using ArgumentTypes = std::tuple<Arguments...>;

		static constexpr bool isVariadic = true;
		static constexpr bool isConstant = true;
		static constexpr bool isVolatile = true;
		static constexpr bool isLeftValueReference = false;
		static constexpr bool isRightValueReference = true;
		static constexpr bool isNonThrowing = nonThrowing;
	};
}

#endif

// Thanks to halalaluyafail3 (https://github.com/Halalaluyafail3) for the original, terribly unreadable, code
