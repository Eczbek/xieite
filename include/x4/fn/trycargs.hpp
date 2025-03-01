#pragma once

#include <functional>
#include <type_traits>
#include <utility>
#include "../meta/typl.hpp"
#include "../pp/ar.hpp"
#include "../pp/fwd.hpp"
#include "../trait/addc.hpp"

namespace x4 {
	template<typename F, typename... Args>
	[[nodiscard]] constexpr auto trycargs(F&& fn, Args&&... args)
		X4AR(typename x4::typl<Args...>
			::template xform<1, []<typename Arg, typename... Rest> {
				return std::conditional<
					x4::typl<Args...>
						::template slice<sizeof...(Rest) + 1>
						::template prepend<F, Rest..., x4::addc<Arg>>
						::template to<std::is_invocable>
						::value,
					x4::addc<Arg>,
					Arg
				>();
			}>::apply(
				[]<typename... CArgs>(F&& fn, Args&&... args) static
					X4AR(std::invoke(X4FWD(fn), std::forward_like<CArgs>(args)...)),
				X4FWD(fn),
				X4FWD(args)...
			)
		)
}
