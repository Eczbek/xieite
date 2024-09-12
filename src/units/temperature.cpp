export module xieite:units.temperature;

import :units.Unit;

export namespace xieite::units {
	using Kelvin = xieite::units::Unit<"temperature">;
	using Celsius = xieite::units::Unit<"temperature", '+', 273.15>;
	using Fahrenheit = xieite::units::Unit<"temperature", '-', 32.0, '/', 1.8, '+', 273.15>;
	using Rankine = xieite::units::Unit<"temperature", '*', 1.8>;
}
