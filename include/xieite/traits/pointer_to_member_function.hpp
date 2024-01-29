#ifndef XIEITE_HEADER_TRAITS_POINTER_TO_MEMBER_FUNCTION
#	define XIEITE_HEADER_TRAITS_POINTER_TO_MEMBER_FUNCTION

#	include <tuple>

namespace xieite::traits {
	template<typename>
	struct PointerToMemberFunction;

	template<typename Return, typename Class, typename... Arguments>
	struct PointerToMemberFunction<Return(Class::*)(Arguments...)> {
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
		static constexpr bool isNonThrowing = false;
	};

	template<typename Return, typename Class, typename... Arguments>
	struct PointerToMemberFunction<Return(Class::*)(Arguments......)> {
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
		static constexpr bool isNonThrowing = false;
	};

	template<typename Return, typename Class, typename... Arguments>
	struct PointerToMemberFunction<Return(Class::*)(Arguments...) const> {
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
		static constexpr bool isNonThrowing = false;
	};

	template<typename Return, typename Class, typename... Arguments>
	struct PointerToMemberFunction<Return(Class::*)(Arguments......) const> {
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
		static constexpr bool isNonThrowing = false;
	};

	template<typename Return, typename Class, typename... Arguments>
	struct PointerToMemberFunction<Return(Class::*)(Arguments...) volatile> {
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
		static constexpr bool isNonThrowing = false;
	};

	template<typename Return, typename Class, typename... Arguments>
	struct PointerToMemberFunction<Return(Class::*)(Arguments......) volatile> {
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
		static constexpr bool isNonThrowing = false;
	};

	template<typename Return, typename Class, typename... Arguments>
	struct PointerToMemberFunction<Return(Class::*)(Arguments...) const volatile> {
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
		static constexpr bool isNonThrowing = false;
	};

	template<typename Return, typename Class, typename... Arguments>
	struct PointerToMemberFunction<Return(Class::*)(Arguments......) const volatile> {
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
		static constexpr bool isNonThrowing = false;
	};

	template<typename Return, typename Class, typename... Arguments>
	struct PointerToMemberFunction<Return(Class::*)(Arguments...)&> {
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
		static constexpr bool isNonThrowing = false;
	};

	template<typename Return, typename Class, typename... Arguments>
	struct PointerToMemberFunction<Return(Class::*)(Arguments......)&> {
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
		static constexpr bool isNonThrowing = false;
	};

	template<typename Return, typename Class, typename... Arguments>
	struct PointerToMemberFunction<Return(Class::*)(Arguments...) const&> {
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
		static constexpr bool isNonThrowing = false;
	};

	template<typename Return, typename Class, typename... Arguments>
	struct PointerToMemberFunction<Return(Class::*)(Arguments......) const&> {
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
		static constexpr bool isNonThrowing = false;
	};

	template<typename Return, typename Class, typename... Arguments>
	struct PointerToMemberFunction<Return(Class::*)(Arguments...) volatile&> {
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
		static constexpr bool isNonThrowing = false;
	};

	template<typename Return, typename Class, typename... Arguments>
	struct PointerToMemberFunction<Return(Class::*)(Arguments......) volatile&> {
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
		static constexpr bool isNonThrowing = false;
	};

	template<typename Return, typename Class, typename... Arguments>
	struct PointerToMemberFunction<Return(Class::*)(Arguments...) const volatile&> {
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
		static constexpr bool isNonThrowing = false;
	};

	template<typename Return, typename Class, typename... Arguments>
	struct PointerToMemberFunction<Return(Class::*)(Arguments......) const volatile&> {
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
		static constexpr bool isNonThrowing = false;
	};

	template<typename Return, typename Class, typename... Arguments>
	struct PointerToMemberFunction<Return(Class::*)(Arguments...)&&> {
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
		static constexpr bool isNonThrowing = false;
	};

	template<typename Return, typename Class, typename... Arguments>
	struct PointerToMemberFunction<Return(Class::*)(Arguments......)&&> {
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
		static constexpr bool isNonThrowing = false;
	};

	template<typename Return, typename Class, typename... Arguments>
	struct PointerToMemberFunction<Return(Class::*)(Arguments...) const&&> {
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
		static constexpr bool isNonThrowing = false;
	};

	template<typename Return, typename Class, typename... Arguments>
	struct PointerToMemberFunction<Return(Class::*)(Arguments......) const&&> {
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
		static constexpr bool isNonThrowing = false;
	};

	template<typename Return, typename Class, typename... Arguments>
	struct PointerToMemberFunction<Return(Class::*)(Arguments...) volatile&&> {
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
		static constexpr bool isNonThrowing = false;
	};

	template<typename Return, typename Class, typename... Arguments>
	struct PointerToMemberFunction<Return(Class::*)(Arguments......) volatile&&> {
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
		static constexpr bool isNonThrowing = false;
	};

	template<typename Return, typename Class, typename... Arguments>
	struct PointerToMemberFunction<Return(Class::*)(Arguments...) const volatile&&> {
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
		static constexpr bool isNonThrowing = false;
	};

	template<typename Return, typename Class, typename... Arguments>
	struct PointerToMemberFunction<Return(Class::*)(Arguments......) const volatile&&> {
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
		static constexpr bool isNonThrowing = false;
	};

	template<typename Return, typename Class, typename... Arguments>
	struct PointerToMemberFunction<Return(Class::*)(Arguments...) noexcept> {
		using ClassType = Class;
		using ReferenceType = Class&;
		using FunctionType = Return(Arguments...) noexcept;
		using ReturnType = Return;
		using ArgumentTypes = std::tuple<Arguments...>;

		static constexpr bool isVariadic = false;
		static constexpr bool isConstant = false;
		static constexpr bool isVolatile = false;
		static constexpr bool isLeftValueReference = false;
		static constexpr bool isRightValueReference = false;
		static constexpr bool isNonThrowing = true;
	};

	template<typename Return, typename Class, typename... Arguments>
	struct PointerToMemberFunction<Return(Class::*)(Arguments......) noexcept> {
		using ClassType = Class;
		using ReferenceType = Class&;
		using FunctionType = Return(Arguments......) noexcept;
		using ReturnType = Return;
		using ArgumentTypes = std::tuple<Arguments...>;

		static constexpr bool isVariadic = true;
		static constexpr bool isConstant = false;
		static constexpr bool isVolatile = false;
		static constexpr bool isLeftValueReference = false;
		static constexpr bool isRightValueReference = false;
		static constexpr bool isNonThrowing = true;
	};

	template<typename Return, typename Class, typename... Arguments>
	struct PointerToMemberFunction<Return(Class::*)(Arguments...) const noexcept> {
		using ClassType = Class;
		using ReferenceType = const Class&;
		using FunctionType = Return(Arguments...) const noexcept;
		using ReturnType = Return;
		using ArgumentTypes = std::tuple<Arguments...>;

		static constexpr bool isVariadic = false;
		static constexpr bool isConstant = true;
		static constexpr bool isVolatile = false;
		static constexpr bool isLeftValueReference = false;
		static constexpr bool isRightValueReference = false;
		static constexpr bool isNonThrowing = true;
	};

	template<typename Return, typename Class, typename... Arguments>
	struct PointerToMemberFunction<Return(Class::*)(Arguments......) const noexcept> {
		using ClassType = Class;
		using ReferenceType = const Class&;
		using FunctionType = Return(Arguments......) const noexcept;
		using ReturnType = Return;
		using ArgumentTypes = std::tuple<Arguments...>;

		static constexpr bool isVariadic = true;
		static constexpr bool isConstant = true;
		static constexpr bool isVolatile = false;
		static constexpr bool isLeftValueReference = false;
		static constexpr bool isRightValueReference = false;
		static constexpr bool isNonThrowing = true;
	};

	template<typename Return, typename Class, typename... Arguments>
	struct PointerToMemberFunction<Return(Class::*)(Arguments...) volatile noexcept> {
		using ClassType = Class;
		using ReferenceType = volatile Class&;
		using FunctionType = Return(Arguments...) volatile noexcept;
		using ReturnType = Return;
		using ArgumentTypes = std::tuple<Arguments...>;

		static constexpr bool isVariadic = false;
		static constexpr bool isConstant = false;
		static constexpr bool isVolatile = true;
		static constexpr bool isLeftValueReference = false;
		static constexpr bool isRightValueReference = false;
		static constexpr bool isNonThrowing = true;
	};

	template<typename Return, typename Class, typename... Arguments>
	struct PointerToMemberFunction<Return(Class::*)(Arguments......) volatile noexcept> {
		using ClassType = Class;
		using ReferenceType = volatile Class&;
		using FunctionType = Return(Arguments......) volatile noexcept;
		using ReturnType = Return;
		using ArgumentTypes = std::tuple<Arguments...>;

		static constexpr bool isVariadic = true;
		static constexpr bool isConstant = false;
		static constexpr bool isVolatile = true;
		static constexpr bool isLeftValueReference = false;
		static constexpr bool isRightValueReference = false;
		static constexpr bool isNonThrowing = true;
	};

	template<typename Return, typename Class, typename... Arguments>
	struct PointerToMemberFunction<Return(Class::*)(Arguments...) const volatile noexcept> {
		using ClassType = Class;
		using ReferenceType = const volatile Class&;
		using FunctionType = Return(Arguments...) const volatile noexcept;
		using ReturnType = Return;
		using ArgumentTypes = std::tuple<Arguments...>;

		static constexpr bool isVariadic = false;
		static constexpr bool isConstant = true;
		static constexpr bool isVolatile = true;
		static constexpr bool isLeftValueReference = false;
		static constexpr bool isRightValueReference = false;
		static constexpr bool isNonThrowing = true;
	};

	template<typename Return, typename Class, typename... Arguments>
	struct PointerToMemberFunction<Return(Class::*)(Arguments......) const volatile noexcept> {
		using ClassType = Class;
		using ReferenceType = const volatile Class&;
		using FunctionType = Return(Arguments......) const volatile noexcept;
		using ReturnType = Return;
		using ArgumentTypes = std::tuple<Arguments...>;

		static constexpr bool isVariadic = true;
		static constexpr bool isConstant = true;
		static constexpr bool isVolatile = true;
		static constexpr bool isLeftValueReference = false;
		static constexpr bool isRightValueReference = false;
		static constexpr bool isNonThrowing = true;
	};

	template<typename Return, typename Class, typename... Arguments>
	struct PointerToMemberFunction<Return(Class::*)(Arguments...)& noexcept> {
		using ClassType = Class;
		using ReferenceType = Class&;
		using FunctionType = Return(Arguments...)& noexcept;
		using ReturnType = Return;
		using ArgumentTypes = std::tuple<Arguments...>;

		static constexpr bool isVariadic = false;
		static constexpr bool isConstant = false;
		static constexpr bool isVolatile = false;
		static constexpr bool isLeftValueReference = true;
		static constexpr bool isRightValueReference = false;
		static constexpr bool isNonThrowing = true;
	};

	template<typename Return, typename Class, typename... Arguments>
	struct PointerToMemberFunction<Return(Class::*)(Arguments......)& noexcept> {
		using ClassType = Class;
		using ReferenceType = Class&;
		using FunctionType = Return(Arguments......)& noexcept;
		using ReturnType = Return;
		using ArgumentTypes = std::tuple<Arguments...>;

		static constexpr bool isVariadic = true;
		static constexpr bool isConstant = false;
		static constexpr bool isVolatile = false;
		static constexpr bool isLeftValueReference = true;
		static constexpr bool isRightValueReference = false;
		static constexpr bool isNonThrowing = true;
	};

	template<typename Return, typename Class, typename... Arguments>
	struct PointerToMemberFunction<Return(Class::*)(Arguments...) const& noexcept> {
		using ClassType = Class;
		using ReferenceType = const Class&;
		using FunctionType = Return(Arguments...) const& noexcept;
		using ReturnType = Return;
		using ArgumentTypes = std::tuple<Arguments...>;

		static constexpr bool isVariadic = false;
		static constexpr bool isConstant = true;
		static constexpr bool isVolatile = false;
		static constexpr bool isLeftValueReference = true;
		static constexpr bool isRightValueReference = false;
		static constexpr bool isNonThrowing = true;
	};

	template<typename Return, typename Class, typename... Arguments>
	struct PointerToMemberFunction<Return(Class::*)(Arguments......) const& noexcept> {
		using ClassType = Class;
		using ReferenceType = const Class&;
		using FunctionType = Return(Arguments......) const& noexcept;
		using ReturnType = Return;
		using ArgumentTypes = std::tuple<Arguments...>;

		static constexpr bool isVariadic = true;
		static constexpr bool isConstant = true;
		static constexpr bool isVolatile = false;
		static constexpr bool isLeftValueReference = true;
		static constexpr bool isRightValueReference = false;
		static constexpr bool isNonThrowing = true;
	};

	template<typename Return, typename Class, typename... Arguments>
	struct PointerToMemberFunction<Return(Class::*)(Arguments...) volatile& noexcept> {
		using ClassType = Class;
		using ReferenceType = volatile Class&;
		using FunctionType = Return(Arguments...) volatile& noexcept;
		using ReturnType = Return;
		using ArgumentTypes = std::tuple<Arguments...>;

		static constexpr bool isVariadic = false;
		static constexpr bool isConstant = false;
		static constexpr bool isVolatile = true;
		static constexpr bool isLeftValueReference = true;
		static constexpr bool isRightValueReference = false;
		static constexpr bool isNonThrowing = true;
	};

	template<typename Return, typename Class, typename... Arguments>
	struct PointerToMemberFunction<Return(Class::*)(Arguments......) volatile& noexcept> {
		using ClassType = Class;
		using ReferenceType = volatile Class&;
		using FunctionType = Return(Arguments......) volatile& noexcept;
		using ReturnType = Return;
		using ArgumentTypes = std::tuple<Arguments...>;

		static constexpr bool isVariadic = true;
		static constexpr bool isConstant = false;
		static constexpr bool isVolatile = true;
		static constexpr bool isLeftValueReference = true;
		static constexpr bool isRightValueReference = false;
		static constexpr bool isNonThrowing = true;
	};

	template<typename Return, typename Class, typename... Arguments>
	struct PointerToMemberFunction<Return(Class::*)(Arguments...) const volatile& noexcept> {
		using ClassType = Class;
		using ReferenceType = const volatile Class&;
		using FunctionType = Return(Arguments...) const volatile& noexcept;
		using ReturnType = Return;
		using ArgumentTypes = std::tuple<Arguments...>;

		static constexpr bool isVariadic = false;
		static constexpr bool isConstant = true;
		static constexpr bool isVolatile = true;
		static constexpr bool isLeftValueReference = true;
		static constexpr bool isRightValueReference = false;
		static constexpr bool isNonThrowing = true;
	};

	template<typename Return, typename Class, typename... Arguments>
	struct PointerToMemberFunction<Return(Class::*)(Arguments......) const volatile& noexcept> {
		using ClassType = Class;
		using ReferenceType = const volatile Class&;
		using FunctionType = Return(Arguments......) const volatile& noexcept;
		using ReturnType = Return;
		using ArgumentTypes = std::tuple<Arguments...>;

		static constexpr bool isVariadic = true;
		static constexpr bool isConstant = true;
		static constexpr bool isVolatile = true;
		static constexpr bool isLeftValueReference = true;
		static constexpr bool isRightValueReference = false;
		static constexpr bool isNonThrowing = true;
	};

	template<typename Return, typename Class, typename... Arguments>
	struct PointerToMemberFunction<Return(Class::*)(Arguments...)&& noexcept> {
		using ClassType = Class;
		using ReferenceType = Class&&;
		using FunctionType = Return(Arguments...)&& noexcept;
		using ReturnType = Return;
		using ArgumentTypes = std::tuple<Arguments...>;

		static constexpr bool isVariadic = false;
		static constexpr bool isConstant = false;
		static constexpr bool isVolatile = false;
		static constexpr bool isLeftValueReference = false;
		static constexpr bool isRightValueReference = true;
		static constexpr bool isNonThrowing = true;
	};

	template<typename Return, typename Class, typename... Arguments>
	struct PointerToMemberFunction<Return(Class::*)(Arguments......)&& noexcept> {
		using ClassType = Class;
		using ReferenceType = Class&&;
		using FunctionType = Return(Arguments......)&& noexcept;
		using ReturnType = Return;
		using ArgumentTypes = std::tuple<Arguments...>;

		static constexpr bool isVariadic = true;
		static constexpr bool isConstant = false;
		static constexpr bool isVolatile = false;
		static constexpr bool isLeftValueReference = false;
		static constexpr bool isRightValueReference = true;
		static constexpr bool isNonThrowing = true;
	};

	template<typename Return, typename Class, typename... Arguments>
	struct PointerToMemberFunction<Return(Class::*)(Arguments...) const&& noexcept> {
		using ClassType = Class;
		using ReferenceType = const Class&&;
		using FunctionType = Return(Arguments...) const&& noexcept;
		using ReturnType = Return;
		using ArgumentTypes = std::tuple<Arguments...>;

		static constexpr bool isVariadic = false;
		static constexpr bool isConstant = true;
		static constexpr bool isVolatile = false;
		static constexpr bool isLeftValueReference = false;
		static constexpr bool isRightValueReference = true;
		static constexpr bool isNonThrowing = true;
	};

	template<typename Return, typename Class, typename... Arguments>
	struct PointerToMemberFunction<Return(Class::*)(Arguments......) const&& noexcept> {
		using ClassType = Class;
		using ReferenceType = const Class&&;
		using FunctionType = Return(Arguments......) const&& noexcept;
		using ReturnType = Return;
		using ArgumentTypes = std::tuple<Arguments...>;

		static constexpr bool isVariadic = true;
		static constexpr bool isConstant = true;
		static constexpr bool isVolatile = false;
		static constexpr bool isLeftValueReference = false;
		static constexpr bool isRightValueReference = true;
		static constexpr bool isNonThrowing = true;
	};

	template<typename Return, typename Class, typename... Arguments>
	struct PointerToMemberFunction<Return(Class::*)(Arguments...) volatile&& noexcept> {
		using ClassType = Class;
		using ReferenceType = volatile Class&&;
		using FunctionType = Return(Arguments...) volatile&& noexcept;
		using ReturnType = Return;
		using ArgumentTypes = std::tuple<Arguments...>;

		static constexpr bool isVariadic = false;
		static constexpr bool isConstant = false;
		static constexpr bool isVolatile = true;
		static constexpr bool isLeftValueReference = false;
		static constexpr bool isRightValueReference = true;
		static constexpr bool isNonThrowing = true;
	};

	template<typename Return, typename Class, typename... Arguments>
	struct PointerToMemberFunction<Return(Class::*)(Arguments......) volatile&& noexcept> {
		using ClassType = Class;
		using ReferenceType = volatile Class&&;
		using FunctionType = Return(Arguments......) volatile&& noexcept;
		using ReturnType = Return;
		using ArgumentTypes = std::tuple<Arguments...>;

		static constexpr bool isVariadic = true;
		static constexpr bool isConstant = false;
		static constexpr bool isVolatile = true;
		static constexpr bool isLeftValueReference = false;
		static constexpr bool isRightValueReference = true;
		static constexpr bool isNonThrowing = true;
	};

	template<typename Return, typename Class, typename... Arguments>
	struct PointerToMemberFunction<Return(Class::*)(Arguments...) const volatile&& noexcept> {
		using ClassType = Class;
		using ReferenceType = const volatile Class&&;
		using FunctionType = Return(Arguments...) const volatile&& noexcept;
		using ReturnType = Return;
		using ArgumentTypes = std::tuple<Arguments...>;

		static constexpr bool isVariadic = false;
		static constexpr bool isConstant = true;
		static constexpr bool isVolatile = true;
		static constexpr bool isLeftValueReference = false;
		static constexpr bool isRightValueReference = true;
		static constexpr bool isNonThrowing = true;
	};

	template<typename Return, typename Class, typename... Arguments>
	struct PointerToMemberFunction<Return(Class::*)(Arguments......) const volatile&& noexcept> {
		using ClassType = Class;
		using ReferenceType = const volatile Class&&;
		using FunctionType = Return(Arguments......) const volatile&& noexcept;
		using ReturnType = Return;
		using ArgumentTypes = std::tuple<Arguments...>;

		static constexpr bool isVariadic = true;
		static constexpr bool isConstant = true;
		static constexpr bool isVolatile = true;
		static constexpr bool isLeftValueReference = false;
		static constexpr bool isRightValueReference = true;
		static constexpr bool isNonThrowing = true;
	};
}

#endif

// Thanks to halalaluyafail3 (https://github.com/Halalaluyafail3) for the original, terribly unreadable, code
