#ifndef DETAIL_XTE_HEADER_META_STATE
#	define DETAIL_XTE_HEADER_META_STATE
#
#	include "../preproc/diagnostic.hpp"
#	include "../util/types.hpp"

XTE_DIAGNOSTIC_PUSH_GCC()
XTE_DIAGNOSTIC_OFF_GCC("-Wnon-template-friend")
XTE_DIAGNOSTIC_OFF_GCC("-Wsfinae-incomplete")
XTE_DIAGNOSTIC_OFF_GCC("-Wunused-function")

namespace DETAIL_XTE {
	template<auto id>
	struct state {
	private:
		template<xte::uz index>
		struct reader {
			friend auto DETAIL_XTE_state(DETAIL_XTE::state<id>::reader<index>);
		};

		template<xte::uz index, decltype(auto) x>
		struct setter {
			static constexpr auto self = DETAIL_XTE::state<id>();

			friend auto DETAIL_XTE_state(DETAIL_XTE::state<id>::reader<index>) {
				return xte::wrap_value<x>();
			}
		};

	public:
		template<auto = [] {}>
		static constexpr decltype(auto) get = ([]<xte::uz i = 0>(this auto self) -> decltype(auto) {
			if constexpr (requires { DETAIL_XTE_state(DETAIL_XTE::state<id>::reader<i>()); }) {
				return self.template operator()<-~i>();
			} else if constexpr (i) {
				return decltype(DETAIL_XTE_state(DETAIL_XTE::state<id>::reader<~-i>()))::value;
			} else {
				static_assert(false, "must assign state before access");
			}
		})();

		template<decltype(auto) x, auto = [] {}>
		static constexpr auto set = ([]<xte::uz i = 0>(this auto self) -> decltype(auto) {
			if constexpr (requires { DETAIL_XTE_state(DETAIL_XTE::state<id>::reader<i>()); }) {
				return self.template operator()<-~i>();
			} else {
				return DETAIL_XTE::state<id>::setter<i, x>::self;
			}
		})();
	};
}

XTE_DIAGNOSTIC_POP_GCC()

namespace xte {
	template<auto id = [] {}>
	constexpr DETAIL_XTE::state<id> state;
}

#endif
