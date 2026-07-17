#ifndef DETAIL_XTE_HEADER_META_STATE
#	define DETAIL_XTE_HEADER_META_STATE
#
#	include "../meta/wrap_value.hpp"
#	include "../preproc/diagnostic.hpp"
#	include "../util/number_types.hpp"

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
			friend auto flag(impl::reader<index>);
		};

		template<xte::uz index, decltype(auto) x>
		struct setter {
			static constexpr auto self = impl();

			friend auto flag(impl::reader<index>) {
				return xte::wrap_value<x>();
			}
		};

	public:
		template<auto = []{}>
		static constexpr decltype(auto) get = ([]<xte::uz i = 0>(this auto self) -> decltype(auto) {
			if constexpr (requires { flag(impl::reader<i>()); }) {
				return self.template operator()<(i + 1)>();
			} else if constexpr (i) {
				return decltype(flag(impl::reader<(i - 1)>()))::value;
			} else {
				static_assert(false, "must assign state before access");
			}
		})();

		template<decltype(auto) x, auto = []{}>
		static constexpr auto set = ([]<xte::uz i = 0>(this auto self) -> decltype(auto) {
			if constexpr (requires { flag(impl::reader<i>()); }) {
				return self.template operator()<(i + 1)>();
			} else {
				return impl::setter<i, x>::self;
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
