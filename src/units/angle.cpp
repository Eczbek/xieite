export module xieite:units.angle;

import std;
import :units.Unit;

export namespace xieite::units {
	using Radian = xieite::units::Unit<"angle">;
	using Degree = xieite::units::Unit<"angle", '*', std::numbers::pi, '/', 180.0>;
}
