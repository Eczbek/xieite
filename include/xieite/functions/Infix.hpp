#ifndef XIEITE_HEADER_FUNCTIONS_INFIX
#	define XIEITE_HEADER_FUNCTIONS_INFIX

#	include <functional>
#	include <xieite/concepts/Functional.hpp>

namespace xieite::functions {
	template<typename Result, typename LeftParameter, typename RightParameter>
	class Infix {
	public:
		constexpr Infix(const xieite::concepts::Functional<Result(LeftParameter, RightParameter)> auto& callback) noexcept
		: callback(callback) {}

	private:
		class Bind {
		public:
			constexpr Bind(const xieite::concepts::Functional<Result(LeftParameter, RightParameter)> auto& callback, const LeftParameter& leftParameter) noexcept
			: callback(callback), leftParameter(leftParameter) {}

			constexpr Result operator()(const RightParameter& rightParameter) const noexcept {
				return this->callback(leftParameter, rightParameter);
			}

		private:
			std::function<Result(LeftParameter, RightParameter)> callback;
			const LeftParameter& leftParameter;
		};

		class Infixator {
		public:
			constexpr Infixator(const Bind& bind) noexcept
			: bind(bind) {}

			constexpr Result operator|(const RightParameter& rightParameter) const noexcept {
				return this->bind(rightParameter);
			}

		private:
			const Bind bind;
		};

		std::function<Result(LeftParameter, RightParameter)> callback;

		friend constexpr Infixator operator|(const LeftParameter& leftParameter, const Infix<Result, LeftParameter, RightParameter>& infix) noexcept {
			return Infixator(Bind(infix.callback, leftParameter));
		}
	};
}

#endif
