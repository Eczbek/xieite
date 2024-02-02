#ifndef XIEITE_HEADER_UNITS_CONVERT
#	define XIEITE_HEADER_UNITS_CONVERT

#	include <type_traits>
#	include "../concepts/arithmetic.hpp"
#	include "../math/pi.hpp"
#	include "../units/angle.hpp"
#	include "../units/area.hpp"
#	include "../units/length.hpp"
#	include "../units/temperature.hpp"
#	include "../units/volume.hpp"

namespace xieite::units {
	template<xieite::concepts::Arithmetic Number>
	[[nodiscard]] constexpr std::common_type_t<double, Number> convert(const Number value, const xieite::units::Angle source, const xieite::units::Angle target) noexcept {
		std::common_type_t<double, Number> result = value;
		if (source == target) {
			return result;
		}
		switch (source) {
		case xieite::units::Angle::degree:
			result = result * xieite::math::pi<std::common_type_t<double, Number>> / 180;
			break;
		}
		switch (target) {
		case xieite::units::Angle::degree:
			result = result * 180 / xieite::math::pi<std::common_type_t<double, Number>>;
			break;
		}
		return result;
	}

	template<xieite::concepts::Arithmetic Number>
	[[nodiscard]] constexpr std::common_type_t<double, Number> convert(const Number value, const xieite::units::Area source, const xieite::units::Area target) noexcept {
		std::common_type_t<double, Number> result = value;
		if (source == target) {
			return result;
		}
		switch (source) {
		case xieite::units::Area::squareQuectometre:
			result /= 1000000000000000000000000000000000000000000000000000000000000.0;
			break;
		case xieite::units::Area::squareRontometre:
			result /= 1000000000000000000000000000000000000000000000000000000.0;
			break;
		case xieite::units::Area::squareYoctometre:
			result /= 1000000000000000000000000000000000000000000000000.0;
			break;
		case xieite::units::Area::squareZeptometre:
			result /= 1000000000000000000000000000000000000000000.0;
			break;
		case xieite::units::Area::squareAttometre:
			result /= 1000000000000000000000000000000000000.0;
			break;
		case xieite::units::Area::squareFemtometre:
			result /= 1000000000000000000000000000000.0;
			break;
		case xieite::units::Area::squarePicometre:
			result /= 1000000000000000000000000.0;
			break;
		case xieite::units::Area::squareNanometre:
			result /= 1000000000000000000.0;
			break;
		case xieite::units::Area::squareMicrometre:
			result /= 1000000000000.0;
			break;
		case xieite::units::Area::squareMillimetre:
			result /= 1000000.0;
			break;
		case xieite::units::Area::squareCentimetre:
			result /= 10000.0;
			break;
		case xieite::units::Area::squareDecimetre:
			[[fallthrough]];
		case xieite::units::Area::decimilliare:
			result /= 100.0;
			break;
		case xieite::units::Area::squareDecametre:
		case xieite::units::Area::are:
			result *= 100.0;
			break;
		case xieite::units::Area::squareHectometre:
			[[fallthrough]];
		case xieite::units::Area::hectare:
			result *= 10000.0;
			break;
		case xieite::units::Area::squareKilometre:
			result *= 1000000.0;
			break;
		case xieite::units::Area::squareMegametre:
			result *= 1000000000000.0;
			break;
		case xieite::units::Area::squareGigametre:
			result *= 1000000000000000000.0;
			break;
		case xieite::units::Area::squareTerametre:
			result *= 1000000000000000000000000.0;
			break;
		case xieite::units::Area::squarePetametre:
			result *= 1000000000000000000000000000000.0;
			break;
		case xieite::units::Area::squareExametre:
			result *= 1000000000000000000000000000000000000.0;
			break;
		case xieite::units::Area::squareZettametre:
			result *= 1000000000000000000000000000000000000000000.0;
			break;
		case xieite::units::Area::squareYottametre:
			result *= 1000000000000000000000000000000000000000000000000.0;
			break;
		case xieite::units::Area::squareRonnametre:
			result *= 1000000000000000000000000000000000000000000000000000000.0;
			break;
		case xieite::units::Area::squareQuettametre:
			result *= 1000000000000000000000000000000000000000000000000000000000000.0;
			break;
		case xieite::units::Area::squareInch:
			result /= 0.00064516;
			break;
		case xieite::units::Area::squareFoot:
			result /= 0.09290304;
			break;
		case xieite::units::Area::squareYard:
			result /= 0.83612736;
			break;
		case xieite::units::Area::squareMile:
			result *= 2589988.110336;
			break;
		case xieite::units::Area::rood:
			result *= 1011.7141056;
			break;
		case xieite::units::Area::acre:
			result *= 4046.8564224;
			break;
		case xieite::units::Area::deciare:
			result *= 10.0;
			break;
		case xieite::units::Area::decare:
			result *= 1000.0;
			break;
		}
		switch (target) {
		case xieite::units::Area::squareQuectometre:
			result *= 1000000000000000000000000000000000000000000000000000000000000.0;
			break;
		case xieite::units::Area::squareRontometre:
			result *= 1000000000000000000000000000000000000000000000000000000.0;
			break;
		case xieite::units::Area::squareYoctometre:
			result *= 1000000000000000000000000000000000000000000000000.0;
			break;
		case xieite::units::Area::squareZeptometre:
			result *= 1000000000000000000000000000000000000000000.0;
			break;
		case xieite::units::Area::squareAttometre:
			result *= 1000000000000000000000000000000000000.0;
			break;
		case xieite::units::Area::squareFemtometre:
			result *= 1000000000000000000000000000000.0;
			break;
		case xieite::units::Area::squarePicometre:
			result *= 1000000000000000000000000.0;
			break;
		case xieite::units::Area::squareNanometre:
			result *= 1000000000000000000.0;
			break;
		case xieite::units::Area::squareMicrometre:
			result *= 1000000000000.0;
			break;
		case xieite::units::Area::squareMillimetre:
			result *= 1000000.0;
			break;
		case xieite::units::Area::squareCentimetre:
			result *= 10000.0;
			break;
		case xieite::units::Area::squareDecimetre:
			[[fallthrough]];
		case xieite::units::Area::decimilliare:
			result *= 100.0;
			break;
		case xieite::units::Area::squareDecametre:
		case xieite::units::Area::are:
			result /= 100.0;
			break;
		case xieite::units::Area::squareHectometre:
			[[fallthrough]];
		case xieite::units::Area::hectare:
			result /= 10000.0;
			break;
		case xieite::units::Area::squareKilometre:
			result /= 1000000.0;
			break;
		case xieite::units::Area::squareMegametre:
			result /= 1000000000000.0;
			break;
		case xieite::units::Area::squareGigametre:
			result /= 1000000000000000000.0;
			break;
		case xieite::units::Area::squareTerametre:
			result /= 1000000000000000000000000.0;
			break;
		case xieite::units::Area::squarePetametre:
			result /= 1000000000000000000000000000000.0;
			break;
		case xieite::units::Area::squareExametre:
			result /= 1000000000000000000000000000000000000.0;
			break;
		case xieite::units::Area::squareZettametre:
			result /= 1000000000000000000000000000000000000000000.0;
			break;
		case xieite::units::Area::squareYottametre:
			result /= 1000000000000000000000000000000000000000000000000.0;
			break;
		case xieite::units::Area::squareRonnametre:
			result /= 1000000000000000000000000000000000000000000000000000000.0;
			break;
		case xieite::units::Area::squareQuettametre:
			result /= 1000000000000000000000000000000000000000000000000000000000000.0;
			break;
		case xieite::units::Area::squareInch:
			result *= 0.00064516;
			break;
		case xieite::units::Area::squareFoot:
			result *= 0.09290304;
			break;
		case xieite::units::Area::squareYard:
			result *= 0.83612736;
			break;
		case xieite::units::Area::squareMile:
			result /= 2589988.110336;
			break;
		case xieite::units::Area::rood:
			result /= 1011.7141056;
			break;
		case xieite::units::Area::acre:
			result /= 4046.8564224;
			break;
		case xieite::units::Area::deciare:
			result /= 10.0;
			break;
		case xieite::units::Area::decare:
			result /= 1000.0;
			break;
		}
		return result;
	}

	template<xieite::concepts::Arithmetic Number>
	[[nodiscard]] constexpr std::common_type_t<double, Number> convert(const Number value, const xieite::units::Length source, const xieite::units::Length target) noexcept {
		std::common_type_t<double, Number> result = value;
		if (source == target) {
			return result;
		}
		switch (source) {
		case xieite::units::Length::quectometre:
			result /= 1000000000000000000000000000000.0;
			break;
		case xieite::units::Length::rontometre:
			result /= 1000000000000000000000000000.0;
			break;
		case xieite::units::Length::yoctometre:
			result /= 1000000000000000000000000.0;
			break;
		case xieite::units::Length::zeptometre:
			result /= 1000000000000000000000.0;
			break;
		case xieite::units::Length::attometre:
			result /= 1000000000000000000.0;
			break;
		case xieite::units::Length::femtometre:
			result /= 1000000000000000.0;
			break;
		case xieite::units::Length::picometre:
			result /= 1000000000000.0;
			break;
		case xieite::units::Length::nanometre:
			result /= 1000000000.0;
			break;
		case xieite::units::Length::micrometre:
			result /= 1000000.0;
			break;
		case xieite::units::Length::millimetre:
			result /= 1000.0;
			break;
		case xieite::units::Length::centimetre:
			result /= 100.0;
			break;
		case xieite::units::Length::decimetre:
			result /= 10.0;
			break;
		case xieite::units::Length::decametre:
			result *= 10.0;
			break;
		case xieite::units::Length::hectometre:
			result *= 100.0;
			break;
		case xieite::units::Length::kilometre:
			result *= 1000.0;
			break;
		case xieite::units::Length::megametre:
			result *= 1000000.0;
			break;
		case xieite::units::Length::gigametre:
			result *= 1000000000.0;
			break;
		case xieite::units::Length::terametre:
			result *= 1000000000000.0;
			break;
		case xieite::units::Length::petametre:
			result *= 1000000000000000.0;
			break;
		case xieite::units::Length::exametre:
			result *= 1000000000000000000.0;
			break;
		case xieite::units::Length::zettametre:
			result *= 1000000000000000000000.0;
			break;
		case xieite::units::Length::yottametre:
			result *= 1000000000000000000000000.0;
			break;
		case xieite::units::Length::ronnametre:
			result *= 1000000000000000000000000000.0;
			break;
		case xieite::units::Length::quettametre:
			result *= 1000000000000000000000000000000.0;
			break;
		case xieite::units::Length::twip:
			result /= 0.0254 / 1440.0;
			break;
		case xieite::units::Length::thou:
			result /= 0.0000254;
			break;
		case xieite::units::Length::barleycorn:
			result /= 0.0254 / 3.0;
			break;
		case xieite::units::Length::inch:
			result /= 0.0254;
			break;
		case xieite::units::Length::foot:
			result *= 0.3048;
			break;
		case xieite::units::Length::yard:
			result *= 0.9144;
			break;
		case xieite::units::Length::chain:
			result *= 20.1168;
			break;
		case xieite::units::Length::furlong:
			result *= 201.168;
			break;
		case xieite::units::Length::mile:
			result *= 1609.344;
			break;
		case xieite::units::Length::league:
			result *= 4828.032;
			break;
		case xieite::units::Length::fathom:
			result /= 1.8288;
			break;
		case xieite::units::Length::cable:
			result *= 185.2;
			break;
		case xieite::units::Length::nauticalMile:
			result *= 1852.0;
			break;
		case xieite::units::Length::nauticalLeague:
			result *= 5556.0;
			break;
		case xieite::units::Length::link:
			result /= 0.201168;
			break;
		case xieite::units::Length::rod:
			[[fallthrough]];
		case xieite::units::Length::perch:
			[[fallthrough]];
		case xieite::units::Length::pole:
			[[fallthrough]];
		case xieite::units::Length::lug:
			result *= 5.0292;
			break;
		}
		switch (target) {
		case xieite::units::Length::quectometre:
			result *= 1000000000000000000000000000000.0;
			break;
		case xieite::units::Length::rontometre:
			result *= 1000000000000000000000000000.0;
			break;
		case xieite::units::Length::yoctometre:
			result *= 1000000000000000000000000.0;
			break;
		case xieite::units::Length::zeptometre:
			result *= 1000000000000000000000.0;
			break;
		case xieite::units::Length::attometre:
			result *= 1000000000000000000.0;
			break;
		case xieite::units::Length::femtometre:
			result *= 1000000000000000.0;
			break;
		case xieite::units::Length::picometre:
			result *= 1000000000000.0;
			break;
		case xieite::units::Length::nanometre:
			result *= 1000000000.0;
			break;
		case xieite::units::Length::micrometre:
			result *= 1000000.0;
			break;
		case xieite::units::Length::millimetre:
			result *= 1000.0;
			break;
		case xieite::units::Length::centimetre:
			result *= 100.0;
			break;
		case xieite::units::Length::decimetre:
			result *= 10.0;
			break;
		case xieite::units::Length::decametre:
			result /= 10.0;
			break;
		case xieite::units::Length::hectometre:
			result /= 100.0;
			break;
		case xieite::units::Length::kilometre:
			result /= 1000.0;
			break;
		case xieite::units::Length::megametre:
			result /= 1000000.0;
			break;
		case xieite::units::Length::gigametre:
			result /= 1000000000.0;
			break;
		case xieite::units::Length::terametre:
			result /= 1000000000000.0;
			break;
		case xieite::units::Length::petametre:
			result /= 1000000000000000.0;
			break;
		case xieite::units::Length::exametre:
			result /= 1000000000000000000.0;
			break;
		case xieite::units::Length::zettametre:
			result /= 1000000000000000000000.0;
			break;
		case xieite::units::Length::yottametre:
			result /= 1000000000000000000000000.0;
			break;
		case xieite::units::Length::ronnametre:
			result /= 1000000000000000000000000000.0;
			break;
		case xieite::units::Length::quettametre:
			result /= 1000000000000000000000000000000.0;
			break;
		case xieite::units::Length::twip:
			result *= 0.0254 / 1440.0;
			break;
		case xieite::units::Length::thou:
			result *= 0.0000254;
			break;
		case xieite::units::Length::barleycorn:
			result *= 0.0254 / 3.0;
			break;
		case xieite::units::Length::inch:
			result *= 0.0254;
			break;
		case xieite::units::Length::foot:
			result /= 0.3048;
			break;
		case xieite::units::Length::yard:
			result /= 0.9144;
			break;
		case xieite::units::Length::chain:
			result /= 20.1168;
			break;
		case xieite::units::Length::furlong:
			result /= 201.168;
			break;
		case xieite::units::Length::mile:
			result /= 1609.344;
			break;
		case xieite::units::Length::league:
			result /= 4828.032;
			break;
		case xieite::units::Length::fathom:
			result *= 1.8288;
			break;
		case xieite::units::Length::cable:
			result /= 185.2;
			break;
		case xieite::units::Length::nauticalMile:
			result /= 1852.0;
			break;
		case xieite::units::Length::nauticalLeague:
			result /= 5556.0;
			break;
		case xieite::units::Length::link:
			result *= 0.201168;
			break;
		case xieite::units::Length::rod:
			[[fallthrough]];
		case xieite::units::Length::perch:
			[[fallthrough]];
		case xieite::units::Length::pole:
			[[fallthrough]];
		case xieite::units::Length::lug:
			result /= 5.0292;
			break;
		}
		return result;
	}

	template<xieite::concepts::Arithmetic Number>
	[[nodiscard]] constexpr std::common_type_t<double, Number> convert(const Number value, const xieite::units::Temperature source, const xieite::units::Temperature target) noexcept {
		std::common_type_t<double, Number> result = value;
		if (source == target) {
			return result;
		}
		switch (source) {
		case xieite::units::Temperature::celsius:
			result += 273.15;
			break;
		case xieite::units::Temperature::fahrenheit:
			result = (result - 32.0) / 1.8 + 273.15;
			break;
		case xieite::units::Temperature::rankine:
			result *= 5.0 / 9.0;
			break;
		}
		switch (target) {
		case xieite::units::Temperature::celsius:
			result -= 273.15;
			break;
		case xieite::units::Temperature::fahrenheit:
			result = (result - 273.15) * 1.8 + 32.0;
			break;
		case xieite::units::Temperature::rankine:
			result *= 1.8;
			break;
		}
		return result;
	}

	template<xieite::concepts::Arithmetic Number>
	[[nodiscard]] constexpr std::common_type_t<double, Number> convert(const Number value, const xieite::units::Volume source, const xieite::units::Volume target) noexcept {
		std::common_type_t<double, Number> result = value;
		if (source == target) {
			return result;
		}
		switch (source) {
		case xieite::units::Volume::cubicQuectometre:
			result /= 1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000.0;
			break;
		case xieite::units::Volume::cubicRontometre:
			result /= 1000000000000000000000000000000000000000000000000000000000000000000000000000000000.0;
			break;
		case xieite::units::Volume::cubicYoctometre:
			result /= 1000000000000000000000000000000000000000000000000000000000000000000000000.0;
			break;
		case xieite::units::Volume::cubicZeptometre:
			result /= 1000000000000000000000000000000000000000000000000000000000000000.0;
			break;
		case xieite::units::Volume::cubicAttometre:
			result /= 1000000000000000000000000000000000000000000000000000000.0;
			break;
		case xieite::units::Volume::cubicFemtometre:
			result /= 1000000000000000000000000000000000000000000000.0;
			break;
		case xieite::units::Volume::cubicPicometre:
			result /= 1000000000000000000000000000000000000.0;
			break;
		case xieite::units::Volume::cubicNanometre:
			result /= 1000000000000000000000000000.0;
			break;
		case xieite::units::Volume::cubicMicrometre:
			result /= 1000000000000000000.0;
			break;
		case xieite::units::Volume::cubicMillimetre:
			result /= 1000000000.0;
			break;
		case xieite::units::Volume::cubicCentimetre:
			result /= 1000000.0;
			break;
		case xieite::units::Volume::cubicDecimetre:
			result /= 1000.0;
			break;
		case xieite::units::Volume::cubicDecametre:
			result *= 1000.0;
			break;
		case xieite::units::Volume::cubicHectometre:
			result *= 1000000.0;
			break;
		case xieite::units::Volume::cubicKilometre:
			result *= 1000000000.0;
			break;
		case xieite::units::Volume::cubicMegametre:
			result *= 1000000000000000000.0;
			break;
		case xieite::units::Volume::cubicGigametre:
			result *= 1000000000000000000000000000.0;
			break;
		case xieite::units::Volume::cubicTerametre:
			result *= 1000000000000000000000000000000000000.0;
			break;
		case xieite::units::Volume::cubicPetametre:
			result *= 1000000000000000000000000000000000000000000000.0;
			break;
		case xieite::units::Volume::cubicExametre:
			result *= 1000000000000000000000000000000000000000000000000000000.0;
			break;
		case xieite::units::Volume::cubicZettametre:
			result *= 1000000000000000000000000000000000000000000000000000000000000000.0;
			break;
		case xieite::units::Volume::cubicYottametre:
			result *= 1000000000000000000000000000000000000000000000000000000000000000000000000.0;
			break;
		case xieite::units::Volume::cubicRonnametre:
			result *= 1000000000000000000000000000000000000000000000000000000000000000000000000000000000.0;
			break;
		case xieite::units::Volume::cubicQuettametre:
			result *= 1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000.0;
			break;
		case xieite::units::Volume::cubicInch:
			result /= 0.000016387064;
			break;
		case xieite::units::Volume::cubicFoot:
			result /= 0.028316846592;
			break;
		case xieite::units::Volume::cubicYard:
			result /= 0.764554857984;
			break;
		case xieite::units::Volume::cubicMile:
			result *= 4168181825.440579584;
			break;
		case xieite::units::Volume::quectolitre:
			result *= 1000000000000000000000000000000000.0;
			break;
		case xieite::units::Volume::rontolitre:
			result *= 1000000000000000000000000000000.0;
			break;
		case xieite::units::Volume::yoctolitre:
			result *= 1000000000000000000000000000.0;
			break;
		case xieite::units::Volume::zeptolitre:
			result *= 1000000000000000000000000.0;
			break;
		case xieite::units::Volume::attolitre:
			result *= 1000000000000000000000.0;
			break;
		case xieite::units::Volume::femtolitre:
			result *= 1000000000000000000.0;
			break;
		case xieite::units::Volume::picolitre:
			result *= 1000000000000000.0;
			break;
		case xieite::units::Volume::nanolitre:
			result *= 1000000000000.0;
			break;
		case xieite::units::Volume::microlitre:
			result *= 1000000000.0;
			break;
		case xieite::units::Volume::millilitre:
			result *= 1000000.0;
			break;
		case xieite::units::Volume::centilitre:
			result *= 100000.0;
			break;
		case xieite::units::Volume::decilitre:
			result *= 10000.0;
			break;
		case xieite::units::Volume::litre:
			result *= 1000.0;
			break;
		case xieite::units::Volume::decalitre:
			result *= 100.0;
			break;
		case xieite::units::Volume::hectolitre:
			result *= 10.0;
			break;
		case xieite::units::Volume::megalitre:
			result /= 1000.0;
			break;
		case xieite::units::Volume::gigalitre:
			result /= 1000000.0;
			break;
		case xieite::units::Volume::teralitre:
			result /= 1000000000.0;
			break;
		case xieite::units::Volume::petalitre:
			result /= 1000000000000.0;
			break;
		case xieite::units::Volume::exalitre:
			result /= 1000000000000000.0;
			break;
		case xieite::units::Volume::zettalitre:
			result /= 1000000000000000000.0;
			break;
		case xieite::units::Volume::yottalitre:
			result /= 1000000000000000000000.0;
			break;
		case xieite::units::Volume::ronnalitre:
			result /= 1000000000000000000000000.0;
			break;
		case xieite::units::Volume::quettalitre:
			result /= 1000000000000000000000000000.0;
			break;
		case xieite::units::Volume::fluidOunce:
			result *= 0.00002957353;
			break;
		case xieite::units::Volume::gill:
			result *= 0.0001182941;
			break;
		case xieite::units::Volume::cup:
			result *= 0.0002365882;
			break;
		case xieite::units::Volume::pint:
			result *= 0.0004731765;
			break;
		case xieite::units::Volume::quart:
			result *= 0.000946353;
			break;
		case xieite::units::Volume::gallon:
			result *= 0.003785412;
			break;
		}
		switch (target) {
		case xieite::units::Volume::cubicQuectometre:
			result *= 1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000.0;
			break;
		case xieite::units::Volume::cubicRontometre:
			result *= 1000000000000000000000000000000000000000000000000000000000000000000000000000000000.0;
			break;
		case xieite::units::Volume::cubicYoctometre:
			result *= 1000000000000000000000000000000000000000000000000000000000000000000000000.0;
			break;
		case xieite::units::Volume::cubicZeptometre:
			result *= 1000000000000000000000000000000000000000000000000000000000000000.0;
			break;
		case xieite::units::Volume::cubicAttometre:
			result *= 1000000000000000000000000000000000000000000000000000000.0;
			break;
		case xieite::units::Volume::cubicFemtometre:
			result *= 1000000000000000000000000000000000000000000000.0;
			break;
		case xieite::units::Volume::cubicPicometre:
			result *= 1000000000000000000000000000000000000.0;
			break;
		case xieite::units::Volume::cubicNanometre:
			result *= 1000000000000000000000000000.0;
			break;
		case xieite::units::Volume::cubicMicrometre:
			result *= 1000000000000000000.0;
			break;
		case xieite::units::Volume::cubicMillimetre:
			result *= 1000000000.0;
			break;
		case xieite::units::Volume::cubicCentimetre:
			result *= 1000000.0;
			break;
		case xieite::units::Volume::cubicDecimetre:
			result *= 1000.0;
			break;
		case xieite::units::Volume::cubicDecametre:
			result /= 1000.0;
			break;
		case xieite::units::Volume::cubicHectometre:
			result /= 1000000.0;
			break;
		case xieite::units::Volume::cubicKilometre:
			result /= 1000000000.0;
			break;
		case xieite::units::Volume::cubicMegametre:
			result /= 1000000000000000000.0;
			break;
		case xieite::units::Volume::cubicGigametre:
			result /= 1000000000000000000000000000.0;
			break;
		case xieite::units::Volume::cubicTerametre:
			result /= 1000000000000000000000000000000000000.0;
			break;
		case xieite::units::Volume::cubicPetametre:
			result /= 1000000000000000000000000000000000000000000000.0;
			break;
		case xieite::units::Volume::cubicExametre:
			result /= 1000000000000000000000000000000000000000000000000000000.0;
			break;
		case xieite::units::Volume::cubicZettametre:
			result /= 1000000000000000000000000000000000000000000000000000000000000000.0;
			break;
		case xieite::units::Volume::cubicYottametre:
			result /= 1000000000000000000000000000000000000000000000000000000000000000000000000.0;
			break;
		case xieite::units::Volume::cubicRonnametre:
			result /= 1000000000000000000000000000000000000000000000000000000000000000000000000000000000.0;
			break;
		case xieite::units::Volume::cubicQuettametre:
			result /= 1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000.0;
			break;
		case xieite::units::Volume::cubicInch:
			result *= 0.000016387064;
			break;
		case xieite::units::Volume::cubicFoot:
			result *= 0.028316846592;
			break;
		case xieite::units::Volume::cubicYard:
			result *= 0.764554857984;
			break;
		case xieite::units::Volume::cubicMile:
			result /= 4168181825.440579584;
			break;
		case xieite::units::Volume::quectolitre:
			result /= 1000000000000000000000000000000000.0;
			break;
		case xieite::units::Volume::rontolitre:
			result /= 1000000000000000000000000000000.0;
			break;
		case xieite::units::Volume::yoctolitre:
			result /= 1000000000000000000000000000.0;
			break;
		case xieite::units::Volume::zeptolitre:
			result /= 1000000000000000000000000.0;
			break;
		case xieite::units::Volume::attolitre:
			result /= 1000000000000000000000.0;
			break;
		case xieite::units::Volume::femtolitre:
			result /= 1000000000000000000.0;
			break;
		case xieite::units::Volume::picolitre:
			result /= 1000000000000000.0;
			break;
		case xieite::units::Volume::nanolitre:
			result /= 1000000000000.0;
			break;
		case xieite::units::Volume::microlitre:
			result /= 1000000000.0;
			break;
		case xieite::units::Volume::millilitre:
			result /= 1000000.0;
			break;
		case xieite::units::Volume::centilitre:
			result /= 100000.0;
			break;
		case xieite::units::Volume::decilitre:
			result /= 10000.0;
			break;
		case xieite::units::Volume::litre:
			result /= 1000.0;
			break;
		case xieite::units::Volume::decalitre:
			result /= 100.0;
			break;
		case xieite::units::Volume::hectolitre:
			result /= 10.0;
			break;
		case xieite::units::Volume::megalitre:
			result *= 1000.0;
			break;
		case xieite::units::Volume::gigalitre:
			result *= 1000000.0;
			break;
		case xieite::units::Volume::teralitre:
			result *= 1000000000.0;
			break;
		case xieite::units::Volume::petalitre:
			result *= 1000000000000.0;
			break;
		case xieite::units::Volume::exalitre:
			result *= 1000000000000000.0;
			break;
		case xieite::units::Volume::zettalitre:
			result *= 1000000000000000000.0;
			break;
		case xieite::units::Volume::yottalitre:
			result *= 1000000000000000000000.0;
			break;
		case xieite::units::Volume::ronnalitre:
			result *= 1000000000000000000000000.0;
			break;
		case xieite::units::Volume::quettalitre:
			result *= 1000000000000000000000000000.0;
			break;
		case xieite::units::Volume::fluidOunce:
			result /= 0.00002957353;
			break;
		case xieite::units::Volume::gill:
			result /= 0.0001182941;
			break;
		case xieite::units::Volume::cup:
			result /= 0.0002365882;
			break;
		case xieite::units::Volume::pint:
			result /= 0.0004731765;
			break;
		case xieite::units::Volume::quart:
			result /= 0.000946353;
			break;
		case xieite::units::Volume::gallon:
			result /= 0.003785412;
			break;
		}
		return result;
	}
}

#endif
