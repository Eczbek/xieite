export module xieite:units.angle;

import std;
import :units.Unit;

export namespace xieite::units {
	using Radian = xieite::units::Unit<"angle">;
	using Degree = xieite::units::Unit<"angle", [](auto x) { return x * std::numbers::pi / 180.0; }, [](auto x) { return x * 180.0 / std::numbers::pi; }>;
}
