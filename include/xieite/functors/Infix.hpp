#ifndef XIEITE_HEADER__FUNCTORS__INFIX
#	define XIEITE_HEADER__FUNCTORS__INFIX

#	include "../concepts/Functable.hpp"

namespace xieite::functors {
	template<typename Type, xieite::concepts::Functable<Type> auto>
	struct Infix;

	template<typename Result, typename Parameter, xieite::concepts::Functable<Result(Parameter)> auto callback>
	struct Infix<Result(Parameter), callback> {
		constexpr Result operator>(const Parameter& argument) const {
			return callback(argument);
		}

		friend constexpr Result operator<(const Parameter& argument, const xieite::functors::Infix<Result(Parameter), callback>&) {
			return callback(argument);
		}
	};

	template<typename Result, typename LeftParameter, typename RightParameter, xieite::concepts::Functable<Result(LeftParameter, RightParameter)> auto callback>
	class Infix<Result(LeftParameter, RightParameter), callback> {
	private:
		class Intermediate {
		public:
			constexpr Intermediate(const LeftParameter& leftArgument) noexcept
			: leftArgument(leftArgument) {}

			constexpr Result operator>(const RightParameter& rightArgument) const {
				return callback(this->leftArgument, rightArgument);
			}

		private:
			const LeftParameter& leftArgument;
		};

	public:
		[[nodiscard]]
		friend constexpr xieite::functors::Infix<Result(LeftParameter, RightParameter), callback>::Intermediate operator<(const LeftParameter& leftArgument, const xieite::functors::Infix<Result(LeftParameter, RightParameter), callback>&) noexcept {
			return xieite::functors::Infix<Result(LeftParameter, RightParameter), callback>::Intermediate(leftArgument);
		}
	};
}

#endif
