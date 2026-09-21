#ifndef DETAIL_XTE_HEADER_META_STATE
#	define DETAIL_XTE_HEADER_META_STATE
#
#	include "../aliases.hpp"
#	include "../meta/wrap_value.hpp"
#	include "../preproc/diagnostic.hpp"

XTE_DIAGNOSTIC_PUSH_GCC()
XTE_DIAGNOSTIC_OFF_GCC("-Wnon-template-friend")
XTE_DIAGNOSTIC_OFF_GCC("-Wsfinae-incomplete")
XTE_DIAGNOSTIC_OFF_GCC("-Wunused-function")

namespace DETAIL_XTE::state {
	template<auto id>
	struct impl {
	private:
		template<xte::uz index>
		struct reader {
			friend auto flag(DETAIL_XTE::state::impl<id>::reader<index>);
		};

		template<xte::uz index, decltype(auto) x>
		struct setter {
			static constexpr auto self = DETAIL_XTE::state::impl<id>();

			friend auto flag(DETAIL_XTE::state::impl<id>::reader<index>) {
				return xte::wrap_value<x>();
			}
		};

	public:
		template<auto = []{}>
		static constexpr decltype(auto) get = ([]<xte::uz i = 0>(this auto self) -> decltype(auto) {
			if constexpr (requires { flag(DETAIL_XTE::state::impl<id>::reader<i>()); }) {
				return self.template operator()<(i + 1)>();
			} else if constexpr (i) {
				return decltype(flag(DETAIL_XTE::state::impl<id>::reader<(i - 1)>()))::value;
			} else {
				static_assert(false, "must assign state before access");
			}
		})();

		template<decltype(auto) x, auto = []{}>
		static constexpr auto set = ([]<xte::uz i = 0>(this auto self) -> decltype(auto) {
			if constexpr (requires { flag(DETAIL_XTE::state::impl<id>::reader<i>()); }) {
				return self.template operator()<(i + 1)>();
			} else {
				return DETAIL_XTE::state::impl<id>::setter<i, x>::self;
			}
		})();
	};
}

XTE_DIAGNOSTIC_POP_GCC()

namespace xte {
	template<auto id = []{}>
	constexpr DETAIL_XTE::state::impl<id> state;
}

#endif
