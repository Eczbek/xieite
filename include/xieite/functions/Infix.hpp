#ifndef XIEITE_HEADER_FUNCTIONS_INFIX
#	define XIEITE_HEADER_FUNCTIONS_INFIX

#	include <functional>
#	include <xieite/concepts/Functional.hpp>

namespace xieite::functions {
	template<typename>
	struct Infix;

	template<typename Result, typename Parameter>
	class Infix<Result(Parameter)> final {
	public:
		constexpr Infix(const xieite::concepts::Functional<Result(Parameter)> auto& callback) noexcept
		: callback(callback) {}

		[[nodiscard]]
		constexpr Result operator>(const Parameter& argument) const noexcept {
			return this->callback(argument);
		}

		[[nodiscard]]
		friend constexpr Result operator<(const Parameter& argument, const xieite::functions::Infix<Result(Parameter)>& infix) noexcept {
			return infix.callback(argument);
		}

	private:
		const std::function<Result(Parameter)> callback;
	};

	template<typename Result, typename LeftParameter, typename RightParameter>
	class Infix<Result(LeftParameter, RightParameter)> final {
	private:
		class Intermediate {
		public:
			constexpr Intermediate(const std::function<Result(LeftParameter, RightParameter)>& callback, const LeftParameter& leftArgument) noexcept
			: callback(callback), leftArgument(leftArgument) {}

			[[nodiscard]]
			constexpr Result operator>(const RightParameter& rightArgument) const noexcept {
				return this->callback(leftArgument, rightArgument);
			}

		private:
			const std::function<Result(LeftParameter, RightParameter)> callback;
			const LeftParameter& leftArgument;
		};

	public:
		constexpr Infix(const xieite::concepts::Functional<Result(LeftParameter, RightParameter)> auto& callback) noexcept
		: callback(callback) {}

	private:
		const std::function<Result(LeftParameter, RightParameter)> callback;

		[[nodiscard]]
		friend constexpr xieite::functions::Infix<Result(LeftParameter, RightParameter)>::Intermediate operator<(const LeftParameter& leftArgument, const xieite::functions::Infix<Result(LeftParameter, RightParameter)>& infix) noexcept {
			return xieite::functions::Infix<Result(LeftParameter, RightParameter)>::Intermediate(infix.callback, leftArgument);
		}
	};
}

#endif
