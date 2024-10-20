module;

#include <xieite/arrow.hpp>
#include <xieite/forward.hpp>

export module xieite:functors.Mixfix;

import std;
import :concepts.Invocable;
import :containers.MaybeCopyAssignable;
import :containers.MaybeMoveAssignable;
import :functors.Function;

export namespace xieite::functors {
	template<typename>
	struct Mixfix;

	template<typename Return, typename Argument>
	struct Mixfix<Return(Argument)>
	: xieite::functors::Function<Return(Argument)> {
		using xieite::functors::Function<Return(Argument)>::Function;

		template<std::convertible_to<Argument> ArgumentReference>
		/* discardable */ friend constexpr auto operator->*(const Mixfix& mixfix, ArgumentReference&& argument)
		XIEITE_ARROW(mixfix(XIEITE_FORWARD(argument)))

		template<std::convertible_to<Argument> ArgumentReference>
		/* discardable */ friend constexpr auto operator*(const Mixfix& mixfix, ArgumentReference&& argument)
		XIEITE_ARROW(mixfix(XIEITE_FORWARD(argument)))

		template<std::convertible_to<Argument> ArgumentReference>
		/* discardable */ friend constexpr auto operator/(const Mixfix& mixfix, ArgumentReference&& argument)
		XIEITE_ARROW(mixfix(XIEITE_FORWARD(argument)))

		template<std::convertible_to<Argument> ArgumentReference>
		/* discardable */ friend constexpr auto operator%(const Mixfix& mixfix, ArgumentReference&& argument)
		XIEITE_ARROW(mixfix(XIEITE_FORWARD(argument)))

		template<std::convertible_to<Argument> ArgumentReference>
		/* discardable */ friend constexpr auto operator+(const Mixfix& mixfix, ArgumentReference&& argument)
		XIEITE_ARROW(mixfix(XIEITE_FORWARD(argument)))

		template<std::convertible_to<Argument> ArgumentReference>
		/* discardable */ friend constexpr auto operator-(const Mixfix& mixfix, ArgumentReference&& argument)
		XIEITE_ARROW(mixfix(XIEITE_FORWARD(argument)))

		template<std::convertible_to<Argument> ArgumentReference>
		/* discardable */ friend constexpr auto operator<<(const Mixfix& mixfix, ArgumentReference&& argument)
		XIEITE_ARROW(mixfix(XIEITE_FORWARD(argument)))

		template<std::convertible_to<Argument> ArgumentReference>
		/* discardable */ friend constexpr auto operator>>(const Mixfix& mixfix, ArgumentReference&& argument)
		XIEITE_ARROW(mixfix(XIEITE_FORWARD(argument)))

		template<std::convertible_to<Argument> ArgumentReference>
		/* discardable */ friend constexpr auto operator<=>(const Mixfix& mixfix, ArgumentReference&& argument)
		XIEITE_ARROW(mixfix(XIEITE_FORWARD(argument)))

		template<std::convertible_to<Argument> ArgumentReference>
		/* discardable */ friend constexpr auto operator<(const Mixfix& mixfix, ArgumentReference&& argument)
		XIEITE_ARROW(mixfix(XIEITE_FORWARD(argument)))

		template<std::convertible_to<Argument> ArgumentReference>
		/* discardable */ friend constexpr auto operator<=(const Mixfix& mixfix, ArgumentReference&& argument)
		XIEITE_ARROW(mixfix(XIEITE_FORWARD(argument)))

		template<std::convertible_to<Argument> ArgumentReference>
		/* discardable */ friend constexpr auto operator>(const Mixfix& mixfix, ArgumentReference&& argument)
		XIEITE_ARROW(mixfix(XIEITE_FORWARD(argument)))

		template<std::convertible_to<Argument> ArgumentReference>
		/* discardable */ friend constexpr auto operator>=(const Mixfix& mixfix, ArgumentReference&& argument)
		XIEITE_ARROW(mixfix(XIEITE_FORWARD(argument)))

		template<std::convertible_to<Argument> ArgumentReference>
		/* discardable */ friend constexpr auto operator==(const Mixfix& mixfix, ArgumentReference&& argument)
		XIEITE_ARROW(mixfix(XIEITE_FORWARD(argument)))

		template<std::convertible_to<Argument> ArgumentReference>
		/* discardable */ friend constexpr auto operator!=(const Mixfix& mixfix, ArgumentReference&& argument)
		XIEITE_ARROW(mixfix(XIEITE_FORWARD(argument)))

		template<std::convertible_to<Argument> ArgumentReference>
		/* discardable */ friend constexpr auto operator&(const Mixfix& mixfix, ArgumentReference&& argument)
		XIEITE_ARROW(mixfix(XIEITE_FORWARD(argument)))

		template<std::convertible_to<Argument> ArgumentReference>
		/* discardable */ friend constexpr auto operator^(const Mixfix& mixfix, ArgumentReference&& argument)
		XIEITE_ARROW(mixfix(XIEITE_FORWARD(argument)))

		template<std::convertible_to<Argument> ArgumentReference>
		/* discardable */ friend constexpr auto operator|(const Mixfix& mixfix, ArgumentReference&& argument)
		XIEITE_ARROW(mixfix(XIEITE_FORWARD(argument)))

		template<std::convertible_to<Argument> ArgumentReference>
		/* discardable */ friend constexpr auto operator&&(const Mixfix& mixfix, ArgumentReference&& argument)
		XIEITE_ARROW(mixfix(XIEITE_FORWARD(argument)))

		template<std::convertible_to<Argument> ArgumentReference>
		/* discardable */ friend constexpr auto operator||(const Mixfix& mixfix, ArgumentReference&& argument)
		XIEITE_ARROW(mixfix(XIEITE_FORWARD(argument)))

		template<std::convertible_to<Argument> ArgumentReference>
		/* discardable */ friend constexpr auto operator*=(const Mixfix& mixfix, ArgumentReference&& argument)
		XIEITE_ARROW(mixfix(XIEITE_FORWARD(argument)))

		template<std::convertible_to<Argument> ArgumentReference>
		/* discardable */ friend constexpr auto operator/=(const Mixfix& mixfix, ArgumentReference&& argument)
		XIEITE_ARROW(mixfix(XIEITE_FORWARD(argument)))

		template<std::convertible_to<Argument> ArgumentReference>
		/* discardable */ friend constexpr auto operator%=(const Mixfix& mixfix, ArgumentReference&& argument)
		XIEITE_ARROW(mixfix(XIEITE_FORWARD(argument)))

		template<std::convertible_to<Argument> ArgumentReference>
		/* discardable */ friend constexpr auto operator+=(const Mixfix& mixfix, ArgumentReference&& argument)
		XIEITE_ARROW(mixfix(XIEITE_FORWARD(argument)))

		template<std::convertible_to<Argument> ArgumentReference>
		/* discardable */ friend constexpr auto operator-=(const Mixfix& mixfix, ArgumentReference&& argument)
		XIEITE_ARROW(mixfix(XIEITE_FORWARD(argument)))

		template<std::convertible_to<Argument> ArgumentReference>
		/* discardable */ friend constexpr auto operator<<=(const Mixfix& mixfix, ArgumentReference&& argument)
		XIEITE_ARROW(mixfix(XIEITE_FORWARD(argument)))

		template<std::convertible_to<Argument> ArgumentReference>
		/* discardable */ friend constexpr auto operator>>=(const Mixfix& mixfix, ArgumentReference&& argument)
		XIEITE_ARROW(mixfix(XIEITE_FORWARD(argument)))

		template<std::convertible_to<Argument> ArgumentReference>
		/* discardable */ friend constexpr auto operator&=(const Mixfix& mixfix, ArgumentReference&& argument)
		XIEITE_ARROW(mixfix(XIEITE_FORWARD(argument)))

		template<std::convertible_to<Argument> ArgumentReference>
		/* discardable */ friend constexpr auto operator^=(const Mixfix& mixfix, ArgumentReference&& argument)
		XIEITE_ARROW(mixfix(XIEITE_FORWARD(argument)))

		template<std::convertible_to<Argument> ArgumentReference>
		/* discardable */ friend constexpr auto operator|=(const Mixfix& mixfix, ArgumentReference&& argument)
		XIEITE_ARROW(mixfix(XIEITE_FORWARD(argument)))

		template<std::convertible_to<Argument> ArgumentReference>
		/* discardable */ friend constexpr auto operator,(const Mixfix& mixfix, ArgumentReference&& argument)
		XIEITE_ARROW(mixfix(XIEITE_FORWARD(argument)))

		template<std::convertible_to<Argument> ArgumentReference>
		/* discardable */ friend constexpr auto operator->*(ArgumentReference&& argument, const Mixfix& mixfix)
		XIEITE_ARROW(mixfix(XIEITE_FORWARD(argument)))

		template<std::convertible_to<Argument> ArgumentReference>
		/* discardable */ friend constexpr auto operator*(ArgumentReference&& argument, const Mixfix& mixfix)
		XIEITE_ARROW(mixfix(XIEITE_FORWARD(argument)))

		template<std::convertible_to<Argument> ArgumentReference>
		/* discardable */ friend constexpr auto operator/(ArgumentReference&& argument, const Mixfix& mixfix)
		XIEITE_ARROW(mixfix(XIEITE_FORWARD(argument)))

		template<std::convertible_to<Argument> ArgumentReference>
		/* discardable */ friend constexpr auto operator%(ArgumentReference&& argument, const Mixfix& mixfix)
		XIEITE_ARROW(mixfix(XIEITE_FORWARD(argument)))

		template<std::convertible_to<Argument> ArgumentReference>
		/* discardable */ friend constexpr auto operator+(ArgumentReference&& argument, const Mixfix& mixfix)
		XIEITE_ARROW(mixfix(XIEITE_FORWARD(argument)))

		template<std::convertible_to<Argument> ArgumentReference>
		/* discardable */ friend constexpr auto operator-(ArgumentReference&& argument, const Mixfix& mixfix)
		XIEITE_ARROW(mixfix(XIEITE_FORWARD(argument)))

		template<std::convertible_to<Argument> ArgumentReference>
		/* discardable */ friend constexpr auto operator<<(ArgumentReference&& argument, const Mixfix& mixfix)
		XIEITE_ARROW(mixfix(XIEITE_FORWARD(argument)))

		template<std::convertible_to<Argument> ArgumentReference>
		/* discardable */ friend constexpr auto operator>>(ArgumentReference&& argument, const Mixfix& mixfix)
		XIEITE_ARROW(mixfix(XIEITE_FORWARD(argument)))

		template<std::convertible_to<Argument> ArgumentReference>
		/* discardable */ friend constexpr auto operator<=>(ArgumentReference&& argument, const Mixfix& mixfix)
		XIEITE_ARROW(mixfix(XIEITE_FORWARD(argument)))

		template<std::convertible_to<Argument> ArgumentReference>
		/* discardable */ friend constexpr auto operator<(ArgumentReference&& argument, const Mixfix& mixfix)
		XIEITE_ARROW(mixfix(XIEITE_FORWARD(argument)))

		template<std::convertible_to<Argument> ArgumentReference>
		/* discardable */ friend constexpr auto operator<=(ArgumentReference&& argument, const Mixfix& mixfix)
		XIEITE_ARROW(mixfix(XIEITE_FORWARD(argument)))

		template<std::convertible_to<Argument> ArgumentReference>
		/* discardable */ friend constexpr auto operator>(ArgumentReference&& argument, const Mixfix& mixfix)
		XIEITE_ARROW(mixfix(XIEITE_FORWARD(argument)))

		template<std::convertible_to<Argument> ArgumentReference>
		/* discardable */ friend constexpr auto operator>=(ArgumentReference&& argument, const Mixfix& mixfix)
		XIEITE_ARROW(mixfix(XIEITE_FORWARD(argument)))

		template<std::convertible_to<Argument> ArgumentReference>
		/* discardable */ friend constexpr auto operator==(ArgumentReference&& argument, const Mixfix& mixfix)
		XIEITE_ARROW(mixfix(XIEITE_FORWARD(argument)))

		template<std::convertible_to<Argument> ArgumentReference>
		/* discardable */ friend constexpr auto operator!=(ArgumentReference&& argument, const Mixfix& mixfix)
		XIEITE_ARROW(mixfix(XIEITE_FORWARD(argument)))

		template<std::convertible_to<Argument> ArgumentReference>
		/* discardable */ friend constexpr auto operator&(ArgumentReference&& argument, const Mixfix& mixfix)
		XIEITE_ARROW(mixfix(XIEITE_FORWARD(argument)))

		template<std::convertible_to<Argument> ArgumentReference>
		/* discardable */ friend constexpr auto operator^(ArgumentReference&& argument, const Mixfix& mixfix)
		XIEITE_ARROW(mixfix(XIEITE_FORWARD(argument)))

		template<std::convertible_to<Argument> ArgumentReference>
		/* discardable */ friend constexpr auto operator|(ArgumentReference&& argument, const Mixfix& mixfix)
		XIEITE_ARROW(mixfix(XIEITE_FORWARD(argument)))

		template<std::convertible_to<Argument> ArgumentReference>
		/* discardable */ friend constexpr auto operator&&(ArgumentReference&& argument, const Mixfix& mixfix)
		XIEITE_ARROW(mixfix(XIEITE_FORWARD(argument)))

		template<std::convertible_to<Argument> ArgumentReference>
		/* discardable */ friend constexpr auto operator||(ArgumentReference&& argument, const Mixfix& mixfix)
		XIEITE_ARROW(mixfix(XIEITE_FORWARD(argument)))

		template<std::convertible_to<Argument> ArgumentReference>
		/* discardable */ friend constexpr auto operator*=(ArgumentReference&& argument, const Mixfix& mixfix)
		XIEITE_ARROW(mixfix(XIEITE_FORWARD(argument)))

		template<std::convertible_to<Argument> ArgumentReference>
		/* discardable */ friend constexpr auto operator/=(ArgumentReference&& argument, const Mixfix& mixfix)
		XIEITE_ARROW(mixfix(XIEITE_FORWARD(argument)))

		template<std::convertible_to<Argument> ArgumentReference>
		/* discardable */ friend constexpr auto operator%=(ArgumentReference&& argument, const Mixfix& mixfix)
		XIEITE_ARROW(mixfix(XIEITE_FORWARD(argument)))

		template<std::convertible_to<Argument> ArgumentReference>
		/* discardable */ friend constexpr auto operator+=(ArgumentReference&& argument, const Mixfix& mixfix)
		XIEITE_ARROW(mixfix(XIEITE_FORWARD(argument)))

		template<std::convertible_to<Argument> ArgumentReference>
		/* discardable */ friend constexpr auto operator-=(ArgumentReference&& argument, const Mixfix& mixfix)
		XIEITE_ARROW(mixfix(XIEITE_FORWARD(argument)))

		template<std::convertible_to<Argument> ArgumentReference>
		/* discardable */ friend constexpr auto operator<<=(ArgumentReference&& argument, const Mixfix& mixfix)
		XIEITE_ARROW(mixfix(XIEITE_FORWARD(argument)))

		template<std::convertible_to<Argument> ArgumentReference>
		/* discardable */ friend constexpr auto operator>>=(ArgumentReference&& argument, const Mixfix& mixfix)
		XIEITE_ARROW(mixfix(XIEITE_FORWARD(argument)))

		template<std::convertible_to<Argument> ArgumentReference>
		/* discardable */ friend constexpr auto operator&=(ArgumentReference&& argument, const Mixfix& mixfix)
		XIEITE_ARROW(mixfix(XIEITE_FORWARD(argument)))

		template<std::convertible_to<Argument> ArgumentReference>
		/* discardable */ friend constexpr auto operator^=(ArgumentReference&& argument, const Mixfix& mixfix)
		XIEITE_ARROW(mixfix(XIEITE_FORWARD(argument)))

		template<std::convertible_to<Argument> ArgumentReference>
		/* discardable */ friend constexpr auto operator|=(ArgumentReference&& argument, const Mixfix& mixfix)
		XIEITE_ARROW(mixfix(XIEITE_FORWARD(argument)))

		template<std::convertible_to<Argument> ArgumentReference>
		/* discardable */ friend constexpr auto operator,(ArgumentReference&& argument, const Mixfix& mixfix)
		XIEITE_ARROW(mixfix(XIEITE_FORWARD(argument)))
	};

	template<typename Return, typename LeftArgument, typename RightArgument>
	struct Mixfix<Return(LeftArgument, RightArgument)>
	: xieite::functors::Function<Return(LeftArgument, RightArgument)> {
	private:
		template<typename LeftArgumentReference>
		struct Intermediate
		: xieite::containers::MaybeCopyAssignable<false>, xieite::containers::MaybeMoveAssignable<false> {
		public:
			constexpr Intermediate(const Mixfix& mixfix, LeftArgumentReference&& leftArgument) noexcept
			: mixfix(mixfix), leftArgument(XIEITE_FORWARD(leftArgument)) {}

			template<std::convertible_to<RightArgument> RightArgumentReference>
			/* discardable */ friend constexpr auto operator->*(const Intermediate&& intermediate, RightArgumentReference&& rightArgument)
			XIEITE_ARROW(intermediate.mixfix(XIEITE_FORWARD(intermediate.leftArgument), XIEITE_FORWARD(rightArgument)))

			template<std::convertible_to<RightArgument> RightArgumentReference>
			/* discardable */ friend constexpr auto operator*(const Intermediate&& intermediate, RightArgumentReference&& rightArgument)
			XIEITE_ARROW(intermediate.mixfix(XIEITE_FORWARD(intermediate.leftArgument), XIEITE_FORWARD(rightArgument)))

			template<std::convertible_to<RightArgument> RightArgumentReference>
			/* discardable */ friend constexpr auto operator/(const Intermediate&& intermediate, RightArgumentReference&& rightArgument)
			XIEITE_ARROW(intermediate.mixfix(XIEITE_FORWARD(intermediate.leftArgument), XIEITE_FORWARD(rightArgument)))

			template<std::convertible_to<RightArgument> RightArgumentReference>
			/* discardable */ friend constexpr auto operator%(const Intermediate&& intermediate, RightArgumentReference&& rightArgument)
			XIEITE_ARROW(intermediate.mixfix(XIEITE_FORWARD(intermediate.leftArgument), XIEITE_FORWARD(rightArgument)))

			template<std::convertible_to<RightArgument> RightArgumentReference>
			/* discardable */ friend constexpr auto operator+(const Intermediate&& intermediate, RightArgumentReference&& rightArgument)
			XIEITE_ARROW(intermediate.mixfix(XIEITE_FORWARD(intermediate.leftArgument), XIEITE_FORWARD(rightArgument)))

			template<std::convertible_to<RightArgument> RightArgumentReference>
			/* discardable */ friend constexpr auto operator-(const Intermediate&& intermediate, RightArgumentReference&& rightArgument)
			XIEITE_ARROW(intermediate.mixfix(XIEITE_FORWARD(intermediate.leftArgument), XIEITE_FORWARD(rightArgument)))

			template<std::convertible_to<RightArgument> RightArgumentReference>
			/* discardable */ friend constexpr auto operator<<(const Intermediate&& intermediate, RightArgumentReference&& rightArgument)
			XIEITE_ARROW(intermediate.mixfix(XIEITE_FORWARD(intermediate.leftArgument), XIEITE_FORWARD(rightArgument)))

			template<std::convertible_to<RightArgument> RightArgumentReference>
			/* discardable */ friend constexpr auto operator>>(const Intermediate&& intermediate, RightArgumentReference&& rightArgument)
			XIEITE_ARROW(intermediate.mixfix(XIEITE_FORWARD(intermediate.leftArgument), XIEITE_FORWARD(rightArgument)))

			template<std::convertible_to<RightArgument> RightArgumentReference>
			/* discardable */ friend constexpr auto operator<=>(const Intermediate&& intermediate, RightArgumentReference&& rightArgument)
			XIEITE_ARROW(intermediate.mixfix(XIEITE_FORWARD(intermediate.leftArgument), XIEITE_FORWARD(rightArgument)))

			template<std::convertible_to<RightArgument> RightArgumentReference>
			/* discardable */ friend constexpr auto operator<(const Intermediate&& intermediate, RightArgumentReference&& rightArgument)
			XIEITE_ARROW(intermediate.mixfix(XIEITE_FORWARD(intermediate.leftArgument), XIEITE_FORWARD(rightArgument)))

			template<std::convertible_to<RightArgument> RightArgumentReference>
			/* discardable */ friend constexpr auto operator<=(const Intermediate&& intermediate, RightArgumentReference&& rightArgument)
			XIEITE_ARROW(intermediate.mixfix(XIEITE_FORWARD(intermediate.leftArgument), XIEITE_FORWARD(rightArgument)))

			template<std::convertible_to<RightArgument> RightArgumentReference>
			/* discardable */ friend constexpr auto operator>(const Intermediate&& intermediate, RightArgumentReference&& rightArgument)
			XIEITE_ARROW(intermediate.mixfix(XIEITE_FORWARD(intermediate.leftArgument), XIEITE_FORWARD(rightArgument)))

			template<std::convertible_to<RightArgument> RightArgumentReference>
			/* discardable */ friend constexpr auto operator>=(const Intermediate&& intermediate, RightArgumentReference&& rightArgument)
			XIEITE_ARROW(intermediate.mixfix(XIEITE_FORWARD(intermediate.leftArgument), XIEITE_FORWARD(rightArgument)))

			template<std::convertible_to<RightArgument> RightArgumentReference>
			/* discardable */ friend constexpr auto operator==(const Intermediate&& intermediate, RightArgumentReference&& rightArgument)
			XIEITE_ARROW(intermediate.mixfix(XIEITE_FORWARD(intermediate.leftArgument), XIEITE_FORWARD(rightArgument)))

			template<std::convertible_to<RightArgument> RightArgumentReference>
			/* discardable */ friend constexpr auto operator!=(const Intermediate&& intermediate, RightArgumentReference&& rightArgument)
			XIEITE_ARROW(intermediate.mixfix(XIEITE_FORWARD(intermediate.leftArgument), XIEITE_FORWARD(rightArgument)))

			template<std::convertible_to<RightArgument> RightArgumentReference>
			/* discardable */ friend constexpr auto operator&(const Intermediate&& intermediate, RightArgumentReference&& rightArgument)
			XIEITE_ARROW(intermediate.mixfix(XIEITE_FORWARD(intermediate.leftArgument), XIEITE_FORWARD(rightArgument)))

			template<std::convertible_to<RightArgument> RightArgumentReference>
			/* discardable */ friend constexpr auto operator^(const Intermediate&& intermediate, RightArgumentReference&& rightArgument)
			XIEITE_ARROW(intermediate.mixfix(XIEITE_FORWARD(intermediate.leftArgument), XIEITE_FORWARD(rightArgument)))

			template<std::convertible_to<RightArgument> RightArgumentReference>
			/* discardable */ friend constexpr auto operator|(const Intermediate&& intermediate, RightArgumentReference&& rightArgument)
			XIEITE_ARROW(intermediate.mixfix(XIEITE_FORWARD(intermediate.leftArgument), XIEITE_FORWARD(rightArgument)))

			template<std::convertible_to<RightArgument> RightArgumentReference>
			/* discardable */ friend constexpr auto operator&&(const Intermediate&& intermediate, RightArgumentReference&& rightArgument)
			XIEITE_ARROW(intermediate.mixfix(XIEITE_FORWARD(intermediate.leftArgument), XIEITE_FORWARD(rightArgument)))

			template<std::convertible_to<RightArgument> RightArgumentReference>
			/* discardable */ friend constexpr auto operator||(const Intermediate&& intermediate, RightArgumentReference&& rightArgument)
			XIEITE_ARROW(intermediate.mixfix(XIEITE_FORWARD(intermediate.leftArgument), XIEITE_FORWARD(rightArgument)))

			template<std::convertible_to<RightArgument> RightArgumentReference>
			/* discardable */ friend constexpr auto operator*=(const Intermediate&& intermediate, RightArgumentReference&& rightArgument)
			XIEITE_ARROW(intermediate.mixfix(XIEITE_FORWARD(intermediate.leftArgument), XIEITE_FORWARD(rightArgument)))

			template<std::convertible_to<RightArgument> RightArgumentReference>
			/* discardable */ friend constexpr auto operator/=(const Intermediate&& intermediate, RightArgumentReference&& rightArgument)
			XIEITE_ARROW(intermediate.mixfix(XIEITE_FORWARD(intermediate.leftArgument), XIEITE_FORWARD(rightArgument)))

			template<std::convertible_to<RightArgument> RightArgumentReference>
			/* discardable */ friend constexpr auto operator%=(const Intermediate&& intermediate, RightArgumentReference&& rightArgument)
			XIEITE_ARROW(intermediate.mixfix(XIEITE_FORWARD(intermediate.leftArgument), XIEITE_FORWARD(rightArgument)))

			template<std::convertible_to<RightArgument> RightArgumentReference>
			/* discardable */ friend constexpr auto operator+=(const Intermediate&& intermediate, RightArgumentReference&& rightArgument)
			XIEITE_ARROW(intermediate.mixfix(XIEITE_FORWARD(intermediate.leftArgument), XIEITE_FORWARD(rightArgument)))

			template<std::convertible_to<RightArgument> RightArgumentReference>
			/* discardable */ friend constexpr auto operator-=(const Intermediate&& intermediate, RightArgumentReference&& rightArgument)
			XIEITE_ARROW(intermediate.mixfix(XIEITE_FORWARD(intermediate.leftArgument), XIEITE_FORWARD(rightArgument)))

			template<std::convertible_to<RightArgument> RightArgumentReference>
			/* discardable */ friend constexpr auto operator<<=(const Intermediate&& intermediate, RightArgumentReference&& rightArgument)
			XIEITE_ARROW(intermediate.mixfix(XIEITE_FORWARD(intermediate.leftArgument), XIEITE_FORWARD(rightArgument)))

			template<std::convertible_to<RightArgument> RightArgumentReference>
			/* discardable */ friend constexpr auto operator>>=(const Intermediate&& intermediate, RightArgumentReference&& rightArgument)
			XIEITE_ARROW(intermediate.mixfix(XIEITE_FORWARD(intermediate.leftArgument), XIEITE_FORWARD(rightArgument)))

			template<std::convertible_to<RightArgument> RightArgumentReference>
			/* discardable */ friend constexpr auto operator&=(const Intermediate&& intermediate, RightArgumentReference&& rightArgument)
			XIEITE_ARROW(intermediate.mixfix(XIEITE_FORWARD(intermediate.leftArgument), XIEITE_FORWARD(rightArgument)))

			template<std::convertible_to<RightArgument> RightArgumentReference>
			/* discardable */ friend constexpr auto operator^=(const Intermediate&& intermediate, RightArgumentReference&& rightArgument)
			XIEITE_ARROW(intermediate.mixfix(XIEITE_FORWARD(intermediate.leftArgument), XIEITE_FORWARD(rightArgument)))

			template<std::convertible_to<RightArgument> RightArgumentReference>
			/* discardable */ friend constexpr auto operator|=(const Intermediate&& intermediate, RightArgumentReference&& rightArgument)
			XIEITE_ARROW(intermediate.mixfix(XIEITE_FORWARD(intermediate.leftArgument), XIEITE_FORWARD(rightArgument)))

			template<std::convertible_to<RightArgument> RightArgumentReference>
			/* discardable */ friend constexpr auto operator,(const Intermediate&& intermediate, RightArgumentReference&& rightArgument)
			XIEITE_ARROW(intermediate.mixfix(XIEITE_FORWARD(intermediate.leftArgument), XIEITE_FORWARD(rightArgument)))

		private:
			const Mixfix& mixfix;
			LeftArgumentReference&& leftArgument;
		};

	public:
		using xieite::functors::Function<Return(LeftArgument, RightArgument)>::Function;

		template<std::convertible_to<LeftArgument> LeftArgumentReference>
		[[nodiscard]] friend constexpr auto operator->*(LeftArgumentReference&& leftArgument, const Mixfix& mixfix)
		XIEITE_ARROW(Mixfix::Intermediate<LeftArgumentReference>(mixfix, XIEITE_FORWARD(leftArgument)))

		template<std::convertible_to<LeftArgument> LeftArgumentReference>
		[[nodiscard]] friend constexpr auto operator*(LeftArgumentReference&& leftArgument, const Mixfix& mixfix)
		XIEITE_ARROW(Mixfix::Intermediate<LeftArgumentReference>(mixfix, XIEITE_FORWARD(leftArgument)))

		template<std::convertible_to<LeftArgument> LeftArgumentReference>
		[[nodiscard]] friend constexpr auto operator/(LeftArgumentReference&& leftArgument, const Mixfix& mixfix)
		XIEITE_ARROW(Mixfix::Intermediate<LeftArgumentReference>(mixfix, XIEITE_FORWARD(leftArgument)))

		template<std::convertible_to<LeftArgument> LeftArgumentReference>
		[[nodiscard]] friend constexpr auto operator%(LeftArgumentReference&& leftArgument, const Mixfix& mixfix)
		XIEITE_ARROW(Mixfix::Intermediate<LeftArgumentReference>(mixfix, XIEITE_FORWARD(leftArgument)))

		template<std::convertible_to<LeftArgument> LeftArgumentReference>
		[[nodiscard]] friend constexpr auto operator+(LeftArgumentReference&& leftArgument, const Mixfix& mixfix)
		XIEITE_ARROW(Mixfix::Intermediate<LeftArgumentReference>(mixfix, XIEITE_FORWARD(leftArgument)))

		template<std::convertible_to<LeftArgument> LeftArgumentReference>
		[[nodiscard]] friend constexpr auto operator-(LeftArgumentReference&& leftArgument, const Mixfix& mixfix)
		XIEITE_ARROW(Mixfix::Intermediate<LeftArgumentReference>(mixfix, XIEITE_FORWARD(leftArgument)))

		template<std::convertible_to<LeftArgument> LeftArgumentReference>
		[[nodiscard]] friend constexpr auto operator<<(LeftArgumentReference&& leftArgument, const Mixfix& mixfix)
		XIEITE_ARROW(Mixfix::Intermediate<LeftArgumentReference>(mixfix, XIEITE_FORWARD(leftArgument)))

		template<std::convertible_to<LeftArgument> LeftArgumentReference>
		[[nodiscard]] friend constexpr auto operator>>(LeftArgumentReference&& leftArgument, const Mixfix& mixfix)
		XIEITE_ARROW(Mixfix::Intermediate<LeftArgumentReference>(mixfix, XIEITE_FORWARD(leftArgument)))

		template<std::convertible_to<LeftArgument> LeftArgumentReference>
		[[nodiscard]] friend constexpr auto operator<=>(LeftArgumentReference&& leftArgument, const Mixfix& mixfix)
		XIEITE_ARROW(Mixfix::Intermediate<LeftArgumentReference>(mixfix, XIEITE_FORWARD(leftArgument)))

		template<std::convertible_to<LeftArgument> LeftArgumentReference>
		[[nodiscard]] friend constexpr auto operator<(LeftArgumentReference&& leftArgument, const Mixfix& mixfix)
		XIEITE_ARROW(Mixfix::Intermediate<LeftArgumentReference>(mixfix, XIEITE_FORWARD(leftArgument)))

		template<std::convertible_to<LeftArgument> LeftArgumentReference>
		[[nodiscard]] friend constexpr auto operator<=(LeftArgumentReference&& leftArgument, const Mixfix& mixfix)
		XIEITE_ARROW(Mixfix::Intermediate<LeftArgumentReference>(mixfix, XIEITE_FORWARD(leftArgument)))

		template<std::convertible_to<LeftArgument> LeftArgumentReference>
		[[nodiscard]] friend constexpr auto operator>(LeftArgumentReference&& leftArgument, const Mixfix& mixfix)
		XIEITE_ARROW(Mixfix::Intermediate<LeftArgumentReference>(mixfix, XIEITE_FORWARD(leftArgument)))

		template<std::convertible_to<LeftArgument> LeftArgumentReference>
		[[nodiscard]] friend constexpr auto operator>=(LeftArgumentReference&& leftArgument, const Mixfix& mixfix)
		XIEITE_ARROW(Mixfix::Intermediate<LeftArgumentReference>(mixfix, XIEITE_FORWARD(leftArgument)))

		template<std::convertible_to<LeftArgument> LeftArgumentReference>
		[[nodiscard]] friend constexpr auto operator==(LeftArgumentReference&& leftArgument, const Mixfix& mixfix)
		XIEITE_ARROW(Mixfix::Intermediate<LeftArgumentReference>(mixfix, XIEITE_FORWARD(leftArgument)))

		template<std::convertible_to<LeftArgument> LeftArgumentReference>
		[[nodiscard]] friend constexpr auto operator!=(LeftArgumentReference&& leftArgument, const Mixfix& mixfix)
		XIEITE_ARROW(Mixfix::Intermediate<LeftArgumentReference>(mixfix, XIEITE_FORWARD(leftArgument)))

		template<std::convertible_to<LeftArgument> LeftArgumentReference>
		[[nodiscard]] friend constexpr auto operator&(LeftArgumentReference&& leftArgument, const Mixfix& mixfix)
		XIEITE_ARROW(Mixfix::Intermediate<LeftArgumentReference>(mixfix, XIEITE_FORWARD(leftArgument)))

		template<std::convertible_to<LeftArgument> LeftArgumentReference>
		[[nodiscard]] friend constexpr auto operator^(LeftArgumentReference&& leftArgument, const Mixfix& mixfix)
		XIEITE_ARROW(Mixfix::Intermediate<LeftArgumentReference>(mixfix, XIEITE_FORWARD(leftArgument)))

		template<std::convertible_to<LeftArgument> LeftArgumentReference>
		[[nodiscard]] friend constexpr auto operator|(LeftArgumentReference&& leftArgument, const Mixfix& mixfix)
		XIEITE_ARROW(Mixfix::Intermediate<LeftArgumentReference>(mixfix, XIEITE_FORWARD(leftArgument)))

		template<std::convertible_to<LeftArgument> LeftArgumentReference>
		[[nodiscard]] friend constexpr auto operator&&(LeftArgumentReference&& leftArgument, const Mixfix& mixfix)
		XIEITE_ARROW(Mixfix::Intermediate<LeftArgumentReference>(mixfix, XIEITE_FORWARD(leftArgument)))

		template<std::convertible_to<LeftArgument> LeftArgumentReference>
		[[nodiscard]] friend constexpr auto operator||(LeftArgumentReference&& leftArgument, const Mixfix& mixfix)
		XIEITE_ARROW(Mixfix::Intermediate<LeftArgumentReference>(mixfix, XIEITE_FORWARD(leftArgument)))

		template<std::convertible_to<LeftArgument> LeftArgumentReference>
		[[nodiscard]] friend constexpr auto operator*=(LeftArgumentReference&& leftArgument, const Mixfix& mixfix)
		XIEITE_ARROW(Mixfix::Intermediate<LeftArgumentReference>(mixfix, XIEITE_FORWARD(leftArgument)))

		template<std::convertible_to<LeftArgument> LeftArgumentReference>
		[[nodiscard]] friend constexpr auto operator/=(LeftArgumentReference&& leftArgument, const Mixfix& mixfix)
		XIEITE_ARROW(Mixfix::Intermediate<LeftArgumentReference>(mixfix, XIEITE_FORWARD(leftArgument)))

		template<std::convertible_to<LeftArgument> LeftArgumentReference>
		[[nodiscard]] friend constexpr auto operator%=(LeftArgumentReference&& leftArgument, const Mixfix& mixfix)
		XIEITE_ARROW(Mixfix::Intermediate<LeftArgumentReference>(mixfix, XIEITE_FORWARD(leftArgument)))

		template<std::convertible_to<LeftArgument> LeftArgumentReference>
		[[nodiscard]] friend constexpr auto operator+=(LeftArgumentReference&& leftArgument, const Mixfix& mixfix)
		XIEITE_ARROW(Mixfix::Intermediate<LeftArgumentReference>(mixfix, XIEITE_FORWARD(leftArgument)))

		template<std::convertible_to<LeftArgument> LeftArgumentReference>
		[[nodiscard]] friend constexpr auto operator-=(LeftArgumentReference&& leftArgument, const Mixfix& mixfix)
		XIEITE_ARROW(Mixfix::Intermediate<LeftArgumentReference>(mixfix, XIEITE_FORWARD(leftArgument)))

		template<std::convertible_to<LeftArgument> LeftArgumentReference>
		[[nodiscard]] friend constexpr auto operator<<=(LeftArgumentReference&& leftArgument, const Mixfix& mixfix)
		XIEITE_ARROW(Mixfix::Intermediate<LeftArgumentReference>(mixfix, XIEITE_FORWARD(leftArgument)))

		template<std::convertible_to<LeftArgument> LeftArgumentReference>
		[[nodiscard]] friend constexpr auto operator>>=(LeftArgumentReference&& leftArgument, const Mixfix& mixfix)
		XIEITE_ARROW(Mixfix::Intermediate<LeftArgumentReference>(mixfix, XIEITE_FORWARD(leftArgument)))

		template<std::convertible_to<LeftArgument> LeftArgumentReference>
		[[nodiscard]] friend constexpr auto operator&=(LeftArgumentReference&& leftArgument, const Mixfix& mixfix)
		XIEITE_ARROW(Mixfix::Intermediate<LeftArgumentReference>(mixfix, XIEITE_FORWARD(leftArgument)))

		template<std::convertible_to<LeftArgument> LeftArgumentReference>
		[[nodiscard]] friend constexpr auto operator^=(LeftArgumentReference&& leftArgument, const Mixfix& mixfix)
		XIEITE_ARROW(Mixfix::Intermediate<LeftArgumentReference>(mixfix, XIEITE_FORWARD(leftArgument)))

		template<std::convertible_to<LeftArgument> LeftArgumentReference>
		[[nodiscard]] friend constexpr auto operator|=(LeftArgumentReference&& leftArgument, const Mixfix& mixfix)
		XIEITE_ARROW(Mixfix::Intermediate<LeftArgumentReference>(mixfix, XIEITE_FORWARD(leftArgument)))

		template<std::convertible_to<LeftArgument> LeftArgumentReference>
		[[nodiscard]] friend constexpr auto operator,(LeftArgumentReference&& leftArgument, const Mixfix& mixfix)
		XIEITE_ARROW(Mixfix::Intermediate<LeftArgumentReference>(mixfix, XIEITE_FORWARD(leftArgument)))
	};
}
