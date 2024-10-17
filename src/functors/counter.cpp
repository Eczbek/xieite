export module xieite:functors.Counter;

import std;
import :types.Value;

export namespace xieite::functors {
	template<auto = [] {}, std::integral Integral = std::size_t>
	struct Counter {
	private:
		template<Integral count>
		struct Value {
			template<auto>
			friend auto flag(Value);

			struct Set
			: xieite::types::Value<count> {
				template<auto>
				friend auto flag(Value) {}
			};
		};

	public:
		template<auto = [] {}>
		static consteval Integral get() noexcept {
			return ([]<Integral count = 0>(this auto self) {
				if constexpr (requires { flag<0>(Counter::Value<count>()); }) {
					return self.template operator()<count + 1>();
				} else {
					return count;
				}
			})();
		}

		template<auto tag = [] {}>
		static consteval Integral advance() noexcept {
			return Counter::Value<Counter::get<tag>()>::Set::value;
		}

		template<auto tag = [] {}>
		static consteval Integral next() noexcept {
			return Counter::advance<tag>() + 1;
		}
	};
}

// https://mc-deltat.github.io/articles/stateful-metaprogramming-cpp20
// `flag` is a template to avoid GCC warnings
