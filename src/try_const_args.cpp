module;

#include <xieite/arrow.hpp>
#include <xieite/fwd.hpp>

export module xieite:try_const_args;

import std;
import :type_list;
import :maybe_const;

export namespace xieite {
	template<typename F, typename... Args>
	constexpr auto try_const_args(F&& fn, Args&&... args)
	XIEITE_ARROW(
		xieite::type_list<Args...>
		::template transform<
			1,
			[]<typename Arg, typename... Rest> {
				return std::type_identity<
					std::conditional_t<
						xieite::type_list<Args...>
						::template slice<sizeof...(Rest) + 1>
						::template prepend<F, Rest..., xieite::maybe_const<Arg, true>>
						::template to<std::is_invocable>
						::value,
						xieite::maybe_const<Arg, true>,
						Arg
					>
				>();
			}
		>
		::apply(
			[&fn, &args...]<typename... ConstArgs>
			XIEITE_ARROW(std::invoke(XIEITE_FWD(fn), std::forward_like<ConstArgs>(args)...))
		)
	)
}
