#ifndef DETAIL_XTE_HEADER_FUNC_DEFER
#	define DETAIL_XTE_HEADER_FUNC_DEFER
#
#	include "../preproc/arrow_ctor.hpp"
#	include "../preproc/fwd.hpp"
#	include "../trait/is_callable.hpp"

namespace xte {
	template<xte::is_callable<> Func>
	struct defer {
	private:
		Func _func;

	public:
		[[nodiscard]] explicit(false) constexpr defer(Func&& func) XTE_ARROW_CTOR(,
			_func, ((XTE_FWD(func)))
		)

		constexpr compl defer() {
			XTE_FWD(this->_func)();
		}
	};

	template<typename Func>
	defer(Func&&) -> defer<Func>;
}

#endif
