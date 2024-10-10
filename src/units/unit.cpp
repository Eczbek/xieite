export module xieite:units.Unit;

import :containers.FixedString;

export namespace xieite::units {
	template<xieite::containers::FixedString type, auto toBase = [](auto x) { return x; }, auto fromBase = [](auto x) { return x; }>
	struct Unit {
		double value;

		template<auto otherToBase, auto otherFromBase>
		[[nodiscard]] explicit(false) constexpr operator Unit<type, otherToBase, otherFromBase>() const noexcept {
			return Unit<type, otherToBase, otherFromBase>(otherFromBase(toBase(this->value)));
		}
	};
}
