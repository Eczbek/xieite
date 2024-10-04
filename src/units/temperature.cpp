export module xieite:units.temperature;

import :units.Unit;

export namespace xieite::units {
	using Kelvin = xieite::units::Unit<"temperature">;
	using Celsius = xieite::units::Unit<"temperature", [](auto x) { return x - 273.15; }, [](auto x) { return x + 273.15; }>;
	using Fahrenheit = xieite::units::Unit<"temperature", [](auto x) { return (x - 32.0) / 1.8 + 273.15; }, [](auto x) { return (x - 273.15) * 1.8 + 32.0; }>;
	using Rankine = xieite::units::Unit<"temperature", [](auto x) { return x / 1.8; }, [](auto x) { return x * 1.8; }>;
}
