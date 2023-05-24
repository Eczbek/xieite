#ifndef XIEITE_HEADER_FUNCTIONS_SUFFIX
#	define XIEITE_HEADER_FUNCTIONS_SUFFIX

#	include <functional>
#	include <xieite/concepts/Functional.hpp>

namespace xieite::functions {
	template<typename>
	struct Suffix;

	template<typename Result, typename LeftParameter>
	class Suffix<Result(LeftParameter)> final {
	public:
		constexpr Suffix(const xieite::concepts::Functional<Result(LeftParameter)> auto& callback) noexcept
		: callback(callback) {}

		friend constexpr Result operator<(const LeftParameter& leftArgument, const xieite::functions::Suffix<Result(LeftParameter)>& suffix) {
			return suffix.callback(leftArgument);
		}

	private:
		std::function<Result(LeftParameter)> callback;
	};
}

#endif
