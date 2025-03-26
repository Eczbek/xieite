#ifndef DETAIL_XIEITE_HEADER_FN_TRY_C_ARGS
#	define DETAIL_XIEITE_HEADER_FN_TRY_C_ARGS
#
#	include <functional>
#	include <type_traits>
#	include <utility>
#	include "../meta/type_list.hpp"
#	include "../pp/arrow.hpp"
#	include "../pp/fwd.hpp"
#	include "../trait/add_c.hpp"

namespace xieite {
	template<typename F, typename... Args>
	[[nodiscard]] constexpr auto try_c_args(F&& fn, Args&&... args)
		XIEITE_ARROW(typename xieite::type_list<Args...>
			::template xform<1, []<typename Arg, typename... Rest> {
				return std::conditional<
					xieite::type_list<Args...>
						::template slice<sizeof...(Rest) + 1>
						::template prepend<F, Rest..., xieite::add_c<Arg>>
						::template to<std::is_invocable>
						::value,
					xieite::add_c<Arg>,
					Arg
				>();
			}>::apply(
				[]<typename... CArgs>(F&& fn, Args&&... args) static
					XIEITE_ARROW(std::invoke(XIEITE_FWD(fn), std::forward_like<CArgs>(args)...)),
				XIEITE_FWD(fn),
				XIEITE_FWD(args)...
			)
		)
}

#endif
