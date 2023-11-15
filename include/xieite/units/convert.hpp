#ifndef XIEITE_HEADER_UNITS_CONVERT
#	define XIEITE_HEADER_UNITS_CONVERT

#	include "../concepts/numeric.hpp"
#	include "../math/pi.hpp"
#	include "../math/result.hpp"
#	include "../units/angle.hpp"
#	include "../units/area.hpp"
#	include "../units/length.hpp"
#	include "../units/temperature.hpp"
#	include "../units/volume.hpp"

namespace xieite::units {
	template<xieite::concepts::Numeric Number>
	[[nodiscard]] constexpr xieite::math::Result<Number> convert(Number value, const xieite::units::Angle source, const xieite::units::Angle target) noexcept {
		if (source == xieite::units::Angle::degree) {
			value = value * xieite::math::pi<xieite::math::Result<Number>> / 180;
		}
		if (target == xieite::units::Angle::degree) {
			value = value * 180 / xieite::math::pi<xieite::math::Result<Number>>;
		}
		return value;
	}

	template<xieite::concepts::Numeric Number>
	[[nodiscard]] constexpr xieite::math::Result<Number> convert(Number value, const xieite::units::Area source, const xieite::units::Area target) noexcept {
		switch (source) {
			case xieite::units::Area::quectometer:
				value /= 1000000000000000000000000000000000000000000000000000000000000.0;
				break;
			case xieite::units::Area::rontometer:
				value /= 1000000000000000000000000000000000000000000000000000000.0;
				break;
			case xieite::units::Area::yoctometer:
				value /= 1000000000000000000000000000000000000000000000000.0;
				break;
			case xieite::units::Area::zeptometer:
				value /= 1000000000000000000000000000000000000000000.0;
				break;
			case xieite::units::Area::attometer:
				value /= 1000000000000000000000000000000000000.0;
				break;
			case xieite::units::Area::femtometer:
				value /= 1000000000000000000000000000000.0;
				break;
			case xieite::units::Area::picometer:
				value /= 1000000000000000000000000.0;
				break;
			case xieite::units::Area::nanometer:
				value /= 1000000000000000000.0;
				break;
			case xieite::units::Area::micrometer:
				value /= 1000000000000.0;
				break;
			case xieite::units::Area::millimeter:
				value /= 1000000 .0;
				break;
			case xieite::units::Area::centimeter:
				value /= 10000.0;
				break;
			case xieite::units::Area::decimeter:
				value /= 100.0;
				break;
			case xieite::units::Area::decameter:
				value *= 100.0;
				break;
			case xieite::units::Area::hectometer:
				value *= 10000.0;
				break;
			case xieite::units::Area::kilometer:
				value *= 1000000.0;
				break;
			case xieite::units::Area::megameter:
				value *= 1000000000000.0;
				break;
			case xieite::units::Area::gigameter:
				value *= 1000000000000000000.0;
				break;
			case xieite::units::Area::terameter:
				value *= 1000000000000000000000000.0;
				break;
			case xieite::units::Area::petameter:
				value *= 1000000000000000000000000000000.0;
				break;
			case xieite::units::Area::exameter:
				value *= 1000000000000000000000000000000000000.0;
				break;
			case xieite::units::Area::zettameter:
				value *= 1000000000000000000000000000000000000000000.0;
				break;
			case xieite::units::Area::yottameter:
				value *= 1000000000000000000000000000000000000000000000000.0;
				break;
			case xieite::units::Area::ronnameter:
				value *= 1000000000000000000000000000000000000000000000000000000.0;
				break;
			case xieite::units::Area::quettameter:
				value *= 1000000000000000000000000000000000000000000000000000000000000.0;
				break;
			case xieite::units::Area::inch:
				value /= 0.00064516;
				break;
			case xieite::units::Area::foot:
				value /= 0.00064516 * 144.0;
				break;
			case xieite::units::Area::yard:
				value /= 0.00064516 * 1296.0;
				break;
			case xieite::units::Area::mile:
				value *= 2589988.110336;
				break;
			case xieite::units::Area::nauticalMile:
				value *= 3429904.0;
				break;
			case xieite::units::Area::rood:
				value *= 1011.7141056;
				break;
			case xieite::units::Area::acre:
				value *= 4046.8564224;
				break;
		}
		switch (target) {
			case xieite::units::Area::quectometer:
				value *= 1000000000000000000000000000000000000000000000000000000000000.0;
				break;
			case xieite::units::Area::rontometer:
				value *= 1000000000000000000000000000000000000000000000000000000.0;
				break;
			case xieite::units::Area::yoctometer:
				value *= 1000000000000000000000000000000000000000000000000.0;
				break;
			case xieite::units::Area::zeptometer:
				value *= 1000000000000000000000000000000000000000000.0;
				break;
			case xieite::units::Area::attometer:
				value *= 1000000000000000000000000000000000000.0;
				break;
			case xieite::units::Area::femtometer:
				value *= 1000000000000000000000000000000.0;
				break;
			case xieite::units::Area::picometer:
				value *= 1000000000000000000000000.0;
				break;
			case xieite::units::Area::nanometer:
				value *= 1000000000000000000.0;
				break;
			case xieite::units::Area::micrometer:
				value *= 1000000000000.0;
				break;
			case xieite::units::Area::millimeter:
				value *= 1000000 .0;
				break;
			case xieite::units::Area::centimeter:
				value *= 10000.0;
				break;
			case xieite::units::Area::decimeter:
				value *= 100.0;
				break;
			case xieite::units::Area::decameter:
				value /= 100.0;
				break;
			case xieite::units::Area::hectometer:
				value /= 10000.0;
				break;
			case xieite::units::Area::kilometer:
				value /= 1000000.0;
				break;
			case xieite::units::Area::megameter:
				value /= 1000000000000.0;
				break;
			case xieite::units::Area::gigameter:
				value /= 1000000000000000000.0;
				break;
			case xieite::units::Area::terameter:
				value /= 1000000000000000000000000.0;
				break;
			case xieite::units::Area::petameter:
				value /= 1000000000000000000000000000000.0;
				break;
			case xieite::units::Area::exameter:
				value /= 1000000000000000000000000000000000000.0;
				break;
			case xieite::units::Area::zettameter:
				value /= 1000000000000000000000000000000000000000000.0;
				break;
			case xieite::units::Area::yottameter:
				value /= 1000000000000000000000000000000000000000000000000.0;
				break;
			case xieite::units::Area::ronnameter:
				value /= 1000000000000000000000000000000000000000000000000000000.0;
				break;
			case xieite::units::Area::quettameter:
				value /= 1000000000000000000000000000000000000000000000000000000000000.0;
				break;
			case xieite::units::Area::inch:
				value *= 0.00064516;
				break;
			case xieite::units::Area::foot:
				value *= 0.00064516 * 144.0;
				break;
			case xieite::units::Area::yard:
				value *= 0.00064516 * 1296.0;
				break;
			case xieite::units::Area::mile:
				value /= 2589988.110336;
				break;
			case xieite::units::Area::nauticalMile:
				value /= 3429904.0;
				break;
			case xieite::units::Area::rood:
				value /= 1011.7141056;
				break;
			case xieite::units::Area::acre:
				value /= 4046.8564224;
				break;
		}
	}

	template<xieite::concepts::Numeric Number>
	[[nodiscard]] constexpr xieite::math::Result<Number> convert(Number value, const xieite::units::Length source, const xieite::units::Length target) noexcept {
		switch (source) {
			case xieite::units::Length::quectometer:
				value /= 1000000000000000000000000000000.0;
				break;
			case xieite::units::Length::rontometer:
				value /= 1000000000000000000000000000.0;
				break;
			case xieite::units::Length::yoctometer:
				value /= 1000000000000000000000000.0;
				break;
			case xieite::units::Length::zeptometer:
				value /= 1000000000000000000000.0;
				break;
			case xieite::units::Length::attometer:
				value /= 1000000000000000000.0;
				break;
			case xieite::units::Length::femtometer:
				value /= 1000000000000000.0;
				break;
			case xieite::units::Length::picometer:
				value /= 1000000000000.0;
				break;
			case xieite::units::Length::nanometer:
				value /= 1000000000.0;
				break;
			case xieite::units::Length::micrometer:
				value /= 1000000.0;
				break;
			case xieite::units::Length::millimeter:
				value /= 1000.0;
				break;
			case xieite::units::Length::centimeter:
				value /= 100.0;
				break;
			case xieite::units::Length::decimeter:
				value /= 10.0;
				break;
			case xieite::units::Length::decameter:
				value *= 10.0;
				break;
			case xieite::units::Length::hectometer:
				value *= 100.0;
				break;
			case xieite::units::Length::kilometer:
				value *= 1000.0;
				break;
			case xieite::units::Length::megameter:
				value *= 1000000.0;
				break;
			case xieite::units::Length::gigameter:
				value *= 1000000000.0;
				break;
			case xieite::units::Length::terameter:
				value *= 1000000000000.0;
				break;
			case xieite::units::Length::petameter:
				value *= 1000000000000000.0;
				break;
			case xieite::units::Length::exameter:
				value *= 1000000000000000000.0;
				break;
			case xieite::units::Length::zettameter:
				value *= 1000000000000000000000.0;
				break;
			case xieite::units::Length::yottameter:
				value *= 1000000000000000000000000.0;
				break;
			case xieite::units::Length::ronnameter:
				value *= 1000000000000000000000000000.0;
				break;
			case xieite::units::Length::quettameter:
				value *= 1000000000000000000000000000000.0;
				break;
			case xieite::units::Length::twip:
				value /= 0.0254 / 1440.0;
				break;
			case xieite::units::Length::thou:
				value /= 0.0000254;
				break;
			case xieite::units::Length::barleycorn:
				value /= 0.0254 / 3.0;
				break;
			case xieite::units::Length::inch:
				value /= 0.0254;
				break;
			case xieite::units::Length::foot:
				value /= 0.0254 * 12.0;
				break;
			case xieite::units::Length::yard:
				value /= 0.0254 * 36.0;
				break;
			case xieite::units::Length::chain:
				value /= 0.0254 * 792.0;
				break;
			case xieite::units::Length::furlong:
				value /= 0.0254 * 7920.0;
				break;
			case xieite::units::Length::mile:
				value *= 1609.344;
				break;
			case xieite::units::Length::league:
				value *= 1609.344 * 3.0;
				break;
			case xieite::units::Length::fathom:
				value /= 0.0254 * 72.0;
				break;
			case xieite::units::Length::cable:
				value *= 185.2;
				break;
			case xieite::units::Length::nauticalMile:
				value *= 1852.0;
				break;
			case xieite::units::Length::nauticalLeague:
				value *= 5556.0;
				break;
			case xieite::units::Length::link:
				value /= 0.201168;
				break;
			case xieite::units::Length::rod:
			case xieite::units::Length::perch:
			case xieite::units::Length::pole:
			case xieite::units::Length::lug:
				value *= 5.0292;
				break;
		}
		switch (target) {
			case xieite::units::Length::quectometer:
				value *= 1000000000000000000000000000000.0;
				break;
			case xieite::units::Length::rontometer:
				value *= 1000000000000000000000000000.0;
				break;
			case xieite::units::Length::yoctometer:
				value *= 1000000000000000000000000.0;
				break;
			case xieite::units::Length::zeptometer:
				value *= 1000000000000000000000.0;
				break;
			case xieite::units::Length::attometer:
				value *= 1000000000000000000.0;
				break;
			case xieite::units::Length::femtometer:
				value *= 1000000000000000.0;
				break;
			case xieite::units::Length::picometer:
				value *= 1000000000000.0;
				break;
			case xieite::units::Length::nanometer:
				value *= 1000000000.0;
				break;
			case xieite::units::Length::micrometer:
				value *= 1000000.0;
				break;
			case xieite::units::Length::millimeter:
				value *= 1000.0;
				break;
			case xieite::units::Length::centimeter:
				value *= 100.0;
				break;
			case xieite::units::Length::decimeter:
				value *= 10.0;
				break;
			case xieite::units::Length::decameter:
				value /= 10.0;
				break;
			case xieite::units::Length::hectometer:
				value /= 100.0;
				break;
			case xieite::units::Length::kilometer:
				value /= 1000.0;
				break;
			case xieite::units::Length::megameter:
				value /= 1000000.0;
				break;
			case xieite::units::Length::gigameter:
				value /= 1000000000.0;
				break;
			case xieite::units::Length::terameter:
				value /= 1000000000000.0;
				break;
			case xieite::units::Length::petameter:
				value /= 1000000000000000.0;
				break;
			case xieite::units::Length::exameter:
				value /= 1000000000000000000.0;
				break;
			case xieite::units::Length::zettameter:
				value /= 1000000000000000000000.0;
				break;
			case xieite::units::Length::yottameter:
				value /= 1000000000000000000000000.0;
				break;
			case xieite::units::Length::ronnameter:
				value /= 1000000000000000000000000000.0;
				break;
			case xieite::units::Length::quettameter:
				value /= 1000000000000000000000000000000.0;
				break;
			case xieite::units::Length::twip:
				value *= 0.0254 / 1440.0;
				break;
			case xieite::units::Length::thou:
				value *= 0.0000254;
				break;
			case xieite::units::Length::barleycorn:
				value *= 0.0254 / 3.0;
				break;
			case xieite::units::Length::inch:
				value *= 0.0254;
				break;
			case xieite::units::Length::foot:
				value *= 0.0254 * 12.0;
				break;
			case xieite::units::Length::yard:
				value *= 0.0254 * 36.0;
				break;
			case xieite::units::Length::chain:
				value *= 0.0254 * 792.0;
				break;
			case xieite::units::Length::furlong:
				value *= 0.0254 * 7920.0;
				break;
			case xieite::units::Length::mile:
				value /= 1609.344;
				break;
			case xieite::units::Length::league:
				value /= 1609.344 * 3.0;
				break;
			case xieite::units::Length::fathom:
				value *= 0.0254 * 72.0;
				break;
			case xieite::units::Length::cable:
				value /= 185.2;
				break;
			case xieite::units::Length::nauticalMile:
				value /= 1852.0;
				break;
			case xieite::units::Length::nauticalLeague:
				value /= 5556.0;
				break;
			case xieite::units::Length::link:
				value *= 0.201168;
				break;
			case xieite::units::Length::rod:
			case xieite::units::Length::perch:
			case xieite::units::Length::pole:
			case xieite::units::Length::lug:
				value /= 5.0292;
				break;
		}
		return value;
	}

	template<xieite::concepts::Numeric Number>
	[[nodiscard]] constexpr xieite::math::Result<Number> convert(Number value, const xieite::units::Temperature source, const xieite::units::Temperature target) noexcept {
		switch (source) {
			case xieite::units::Temperature::celsius:
				value += 273.15;
				break;
			case xieite::units::Temperature::fahrenheit:
				value = (value - 32) / 1.8 + 273.15;
				break;
			case xieite::units::Temperature::rankine:
				value = value * 5 / 9;
				break;
		}
		switch (target) {
			case xieite::units::Temperature::celsius:
				value -= 273.15;
				break;
			case xieite::units::Temperature::fahrenheit:
				value = (value - 273.15) * 1.8 + 32;
				break;
			case xieite::units::Temperature::rankine:
				value *= 1.8;
				break;
		}
		return value;
	}

	template<xieite::concepts::Numeric Number>
	[[nodiscard]] constexpr xieite::math::Result<Number> convert(Number value, const xieite::units::Volume source, const xieite::units::Volume target) noexcept {
		switch (source) {
			case xieite::units::Volume::quectolitre:
				value *= 1000000000000000000000000000000.0;
				break;
			case xieite::units::Volume::rontolitre:
				value *= 1000000000000000000000000000.0;
				break;
			case xieite::units::Volume::yoctolitre:
				value *= 1000000000000000000000000.0;
				break;
			case xieite::units::Volume::zeptolitre:
				value *= 1000000000000000000000.0;
				break;
			case xieite::units::Volume::attolitre:
				value *= 1000000000000000000.0;
				break;
			case xieite::units::Volume::femtolitre:
				value *= 1000000000000000.0;
				break;
			case xieite::units::Volume::picolitre:
				value *= 1000000000000.0;
				break;
			case xieite::units::Volume::nanolitre:
				value *= 1000000000.0;
				break;
			case xieite::units::Volume::microlitre:
				value *= 1000000.0;
				break;
			case xieite::units::Volume::millilitre:
				value *= 1000.0;
				break;
			case xieite::units::Volume::centilitre:
				value *= 100.0;
				break;
			case xieite::units::Volume::decilitre:
				value *= 10.0;
				break;
			case xieite::units::Volume::decalitre:
				value /= 10.0;
				break;
			case xieite::units::Volume::hectolitre:
				value /= 100.0;
				break;
			case xieite::units::Volume::kilolitre:
				value /= 1000.0;
				break;
			case xieite::units::Volume::megalitre:
				value /= 1000000.0;
				break;
			case xieite::units::Volume::gigalitre:
				value /= 1000000000.0;
				break;
			case xieite::units::Volume::teralitre:
				value /= 1000000000000.0;
				break;
			case xieite::units::Volume::petalitre:
				value /= 1000000000000000.0;
				break;
			case xieite::units::Volume::exalitre:
				value /= 1000000000000000000.0;
				break;
			case xieite::units::Volume::zettalitre:
				value /= 1000000000000000000000.0;
				break;
			case xieite::units::Volume::yottalitre:
				value /= 1000000000000000000000000.0;
				break;
			case xieite::units::Volume::ronnalitre:
				value /= 1000000000000000000000000000.0;
				break;
			case xieite::units::Volume::quettalitre:
				value /= 1000000000000000000000000000000.0;
				break;
			case xieite::units::Volume::fluidOunce:
				value *= 0.02957353;
				break;
			case xieite::units::Volume::gill:
				value *= 0.1182941;
				break;
			case xieite::units::Volume::cup:
				value *= 0.2365882;
				break;
			case xieite::units::Volume::pint:
				value *= 0.4731765;
				break;
			case xieite::units::Volume::quart:
				value *= 0.946353;
				break;
			case xieite::units::Volume::gallon:
				value *= 3.785412;
				break;
		}
		switch (target) {
			case xieite::units::Volume::quectolitre:
				value /= 1000000000000000000000000000000.0;
				break;
			case xieite::units::Volume::rontolitre:
				value /= 1000000000000000000000000000.0;
				break;
			case xieite::units::Volume::yoctolitre:
				value /= 1000000000000000000000000.0;
				break;
			case xieite::units::Volume::zeptolitre:
				value /= 1000000000000000000000.0;
				break;
			case xieite::units::Volume::attolitre:
				value /= 1000000000000000000.0;
				break;
			case xieite::units::Volume::femtolitre:
				value /= 1000000000000000.0;
				break;
			case xieite::units::Volume::picolitre:
				value /= 1000000000000.0;
				break;
			case xieite::units::Volume::nanolitre:
				value /= 1000000000.0;
				break;
			case xieite::units::Volume::microlitre:
				value /= 1000000.0;
				break;
			case xieite::units::Volume::millilitre:
				value /= 1000.0;
				break;
			case xieite::units::Volume::centilitre:
				value /= 100.0;
				break;
			case xieite::units::Volume::decilitre:
				value /= 10.0;
				break;
			case xieite::units::Volume::decalitre:
				value *= 10.0;
				break;
			case xieite::units::Volume::hectolitre:
				value *= 100.0;
				break;
			case xieite::units::Volume::kilolitre:
				value *= 1000.0;
				break;
			case xieite::units::Volume::megalitre:
				value *= 1000000.0;
				break;
			case xieite::units::Volume::gigalitre:
				value *= 1000000000.0;
				break;
			case xieite::units::Volume::teralitre:
				value *= 1000000000000.0;
				break;
			case xieite::units::Volume::petalitre:
				value *= 1000000000000000.0;
				break;
			case xieite::units::Volume::exalitre:
				value *= 1000000000000000000.0;
				break;
			case xieite::units::Volume::zettalitre:
				value *= 1000000000000000000000.0;
				break;
			case xieite::units::Volume::yottalitre:
				value *= 1000000000000000000000000.0;
				break;
			case xieite::units::Volume::ronnalitre:
				value *= 1000000000000000000000000000.0;
				break;
			case xieite::units::Volume::quettalitre:
				value *= 1000000000000000000000000000000.0;
				break;
			case xieite::units::Volume::fluidOunce:
				value /= 0.02957353;
				break;
			case xieite::units::Volume::gill:
				value /= 0.1182941;
				break;
			case xieite::units::Volume::cup:
				value /= 0.2365882;
				break;
			case xieite::units::Volume::pint:
				value /= 0.4731765;
				break;
			case xieite::units::Volume::quart:
				value /= 0.946353;
				break;
			case xieite::units::Volume::gallon:
				value /= 3.785412;
				break;
		}
		return value;
	}
}

#endif
