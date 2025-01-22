module;

#include <xieite/arrow.hpp>
#include <xieite/fwd.hpp>

export module xieite:try_c_args;

import std;
import :add_c;
import :type_list;

export namespace xieite {
	template<typename F, typename... Args>
	constexpr auto try_c_args(F&& fn, Args&&... args)
		XIEITE_ARROW(typename xieite::type_list<Args...>
			::xform<1, []<typename Arg, typename... Rest> {
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
				[]<typename... CArgs>(F&& fn, Args&&... args)
					XIEITE_ARROW(std::invoke(XIEITE_FWD(fn), std::forward_like<CArgs>(args)...)),
				XIEITE_FWD(fn),
				XIEITE_FWD(args)...
			)
		)
}
