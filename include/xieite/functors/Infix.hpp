#ifndef XIEITE_HEADER__FUNCTORS__INFIX
#	define XIEITE_HEADER__FUNCTORS__INFIX

#	include <concepts>
#	include <type_traits>
#	include "../types/Placeholder.hpp"

namespace xieite::functors {
	template<auto>
	struct Infix;

	template<std::invocable<xieite::types::Placeholder> auto callback>
	struct Infix<callback> {
		template<typename Argument>
		requires(std::invocable<decltype(callback), const Argument&>)
		constexpr std::invoke_result_t<decltype(callback), const Argument&> operator>(const Argument& argument) const {
			return callback(argument);
		}

		template<typename Argument>
		requires(std::invocable<decltype(callback), Argument&>)
		constexpr std::invoke_result_t<decltype(callback), Argument&> operator>(Argument& argument) const {
			return callback(argument);
		}

		template<typename Argument>
		requires(std::invocable<decltype(callback), const Argument&>)
		friend constexpr std::invoke_result_t<decltype(callback), const Argument&> operator<(const Argument& argument, xieite::functors::Infix<callback>) {
			return callback(argument);
		}

		template<typename Argument>
		requires(std::invocable<decltype(callback), Argument&>)
		friend constexpr std::invoke_result_t<decltype(callback), Argument&> operator<(Argument& argument, xieite::functors::Infix<callback>) {
			return callback(argument);
		}
	};

	template<std::invocable<xieite::types::Placeholder, xieite::types::Placeholder> auto callback>
	class Infix<callback> {
	private:
		template<typename LeftArgument>
		class Intermediate {
		public:
			constexpr Intermediate(const LeftArgument& leftArgument) noexcept
			: leftArgument(leftArgument) {}

			template<typename RightArgument>
			requires(std::invocable<decltype(callback), LeftArgument, const RightArgument&>)
			constexpr std::invoke_result_t<decltype(callback), LeftArgument, const RightArgument&> operator>(const RightArgument& rightArgument) const {
				return callback(this->leftArgument, rightArgument);
			}

			template<typename RightArgument>
			requires(std::invocable<decltype(callback), LeftArgument, RightArgument&>)
			constexpr std::invoke_result_t<decltype(callback), LeftArgument, RightArgument&> operator>(RightArgument& rightArgument) {
				return callback(this->leftArgument, rightArgument);
			}

		private:
			const LeftArgument leftArgument;
		};

	public:
		template<typename LeftArgument>
		requires(std::invocable<decltype(callback), const LeftArgument&, xieite::types::Placeholder>)
		[[nodiscard]] friend constexpr Infix<callback>::Intermediate<const LeftArgument&> operator<(const LeftArgument& leftArgument, xieite::functors::Infix<callback>) noexcept {
			return xieite::functors::Infix<callback>::Intermediate<const LeftArgument&>(leftArgument);
		}

		template<typename LeftArgument>
		requires(std::invocable<decltype(callback), LeftArgument&, xieite::types::Placeholder>)
		[[nodiscard]] friend constexpr Infix<callback>::Intermediate<LeftArgument&> operator<(LeftArgument& leftArgument, xieite::functors::Infix<callback>) noexcept {
			return xieite::functors::Infix<callback>::Intermediate<LeftArgument&>(leftArgument);
		}
	};
}

#endif
