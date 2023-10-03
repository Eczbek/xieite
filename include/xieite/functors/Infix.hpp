#ifndef XIEITE_HEADER__FUNCTORS__INFIX
#	define XIEITE_HEADER__FUNCTORS__INFIX

#	include <concepts>
#	include <functional>
#	include <type_traits>
#	include "../types/Placeholder.hpp"

namespace xieite::functors {
	template<auto>
	struct Infix;

	template<std::invocable<xieite::types::Placeholder> auto callback>
	struct Infix<callback> {
		template<typename Argument>
		requires(std::invocable<decltype(callback), const Argument&>)
		friend constexpr std::invoke_result_t<decltype(callback), const Argument&> operator>(xieite::functors::Infix<callback>, const Argument& argument) {
			return std::invoke(callback, argument);
		}

		template<typename Argument>
		requires(std::invocable<decltype(callback), Argument&>)
		friend constexpr std::invoke_result_t<decltype(callback), Argument&> operator>(xieite::functors::Infix<callback>, Argument& argument) {
			return std::invoke(callback, argument);
		}

		template<typename Argument>
		requires(std::invocable<decltype(callback), const Argument&>)
		friend constexpr std::invoke_result_t<decltype(callback), const Argument&> operator<(const Argument& argument, xieite::functors::Infix<callback>) {
			return std::invoke(callback, argument);
		}

		template<typename Argument>
		requires(std::invocable<decltype(callback), Argument&>)
		friend constexpr std::invoke_result_t<decltype(callback), Argument&> operator<(Argument& argument, xieite::functors::Infix<callback>) {
			return std::invoke(callback, argument);
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

			constexpr auto operator=(const xieite::functors::Infix<callback>::Intermediate<LeftArgument>&) = delete;

			template<typename RightArgument>
			requires(std::invocable<decltype(callback), LeftArgument, const RightArgument&>)
			friend constexpr std::invoke_result_t<decltype(callback), LeftArgument, const RightArgument&> operator>(xieite::functors::Infix<callback>::Intermediate<LeftArgument>& infixIntermediate, const RightArgument& rightArgument) {
				return std::invoke(callback, infixIntermediate.leftArgument, rightArgument);
			}

			template<typename RightArgument>
			requires(std::invocable<decltype(callback), LeftArgument, RightArgument&>)
			friend constexpr std::invoke_result_t<decltype(callback), LeftArgument, RightArgument&> operator>(xieite::functors::Infix<callback>::Intermediate<LeftArgument>& infixIntermediate, RightArgument& rightArgument) {
				return std::invoke(callback, infixIntermediate.leftArgument, rightArgument);
			}

		private:
			const LeftArgument leftArgument; // NOTE: Do not question
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
