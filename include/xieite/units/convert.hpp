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
		case xieite::units::Angle::Degree:
			result = result * xieite::math::pi<std::common_type_t<double, Number>> / 180;
			break;
		}
		switch (target) {
		case xieite::units::Angle::Degree:
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
		case xieite::units::Area::SquareQuectometre:
			result /= 1000000000000000000000000000000000000000000000000000000000000.0;
			break;
		case xieite::units::Area::SquareRontometre:
			result /= 1000000000000000000000000000000000000000000000000000000.0;
			break;
		case xieite::units::Area::SquareYoctometre:
			result /= 1000000000000000000000000000000000000000000000000.0;
			break;
		case xieite::units::Area::SquareZeptometre:
			result /= 1000000000000000000000000000000000000000000.0;
			break;
		case xieite::units::Area::SquareAttometre:
			result /= 1000000000000000000000000000000000000.0;
			break;
		case xieite::units::Area::SquareFemtometre:
			result /= 1000000000000000000000000000000.0;
			break;
		case xieite::units::Area::SquarePicometre:
			result /= 1000000000000000000000000.0;
			break;
		case xieite::units::Area::SquareNanometre:
			result /= 1000000000000000000.0;
			break;
		case xieite::units::Area::SquareMicrometre:
			result /= 1000000000000.0;
			break;
		case xieite::units::Area::SquareMillimetre:
			result /= 1000000.0;
			break;
		case xieite::units::Area::SquareCentimetre:
			result /= 10000.0;
			break;
		case xieite::units::Area::SquareDecimetre: [[fallthrough]];
		case xieite::units::Area::Decimilliare:
			result /= 100.0;
			break;
		case xieite::units::Area::SquareDecametre: [[fallthrough]];
		case xieite::units::Area::Are:
			result *= 100.0;
			break;
		case xieite::units::Area::SquareHectometre: [[fallthrough]];
		case xieite::units::Area::Hectare:
			result *= 10000.0;
			break;
		case xieite::units::Area::SquareKilometre:
			result *= 1000000.0;
			break;
		case xieite::units::Area::SquareMegametre:
			result *= 1000000000000.0;
			break;
		case xieite::units::Area::SquareGigametre:
			result *= 1000000000000000000.0;
			break;
		case xieite::units::Area::SquareTerametre:
			result *= 1000000000000000000000000.0;
			break;
		case xieite::units::Area::SquarePetametre:
			result *= 1000000000000000000000000000000.0;
			break;
		case xieite::units::Area::SquareExametre:
			result *= 1000000000000000000000000000000000000.0;
			break;
		case xieite::units::Area::SquareZettametre:
			result *= 1000000000000000000000000000000000000000000.0;
			break;
		case xieite::units::Area::SquareYottametre:
			result *= 1000000000000000000000000000000000000000000000000.0;
			break;
		case xieite::units::Area::SquareRonnametre:
			result *= 1000000000000000000000000000000000000000000000000000000.0;
			break;
		case xieite::units::Area::SquareQuettametre:
			result *= 1000000000000000000000000000000000000000000000000000000000000.0;
			break;
		case xieite::units::Area::SquareInch:
			result /= 0.00064516;
			break;
		case xieite::units::Area::SquareFoot:
			result /= 0.09290304;
			break;
		case xieite::units::Area::SquareYard:
			result /= 0.83612736;
			break;
		case xieite::units::Area::SquareMile:
			result *= 2589988.110336;
			break;
		case xieite::units::Area::SquareRood:
			result *= 1011.7141056;
			break;
		case xieite::units::Area::Acre:
			result *= 4046.8564224;
			break;
		case xieite::units::Area::Deciare:
			result *= 10.0;
			break;
		case xieite::units::Area::Decare:
			result *= 1000.0;
			break;
		}
		switch (target) {
		case xieite::units::Area::SquareQuectometre:
			result *= 1000000000000000000000000000000000000000000000000000000000000.0;
			break;
		case xieite::units::Area::SquareRontometre:
			result *= 1000000000000000000000000000000000000000000000000000000.0;
			break;
		case xieite::units::Area::SquareYoctometre:
			result *= 1000000000000000000000000000000000000000000000000.0;
			break;
		case xieite::units::Area::SquareZeptometre:
			result *= 1000000000000000000000000000000000000000000.0;
			break;
		case xieite::units::Area::SquareAttometre:
			result *= 1000000000000000000000000000000000000.0;
			break;
		case xieite::units::Area::SquareFemtometre:
			result *= 1000000000000000000000000000000.0;
			break;
		case xieite::units::Area::SquarePicometre:
			result *= 1000000000000000000000000.0;
			break;
		case xieite::units::Area::SquareNanometre:
			result *= 1000000000000000000.0;
			break;
		case xieite::units::Area::SquareMicrometre:
			result *= 1000000000000.0;
			break;
		case xieite::units::Area::SquareMillimetre:
			result *= 1000000.0;
			break;
		case xieite::units::Area::SquareCentimetre:
			result *= 10000.0;
			break;
		case xieite::units::Area::SquareDecimetre: [[fallthrough]];
		case xieite::units::Area::Decimilliare:
			result *= 100.0;
			break;
		case xieite::units::Area::SquareDecametre: [[fallthrough]];
		case xieite::units::Area::Are:
			result /= 100.0;
			break;
		case xieite::units::Area::SquareHectometre: [[fallthrough]];
		case xieite::units::Area::Hectare:
			result /= 10000.0;
			break;
		case xieite::units::Area::SquareKilometre:
			result /= 1000000.0;
			break;
		case xieite::units::Area::SquareMegametre:
			result /= 1000000000000.0;
			break;
		case xieite::units::Area::SquareGigametre:
			result /= 1000000000000000000.0;
			break;
		case xieite::units::Area::SquareTerametre:
			result /= 1000000000000000000000000.0;
			break;
		case xieite::units::Area::SquarePetametre:
			result /= 1000000000000000000000000000000.0;
			break;
		case xieite::units::Area::SquareExametre:
			result /= 1000000000000000000000000000000000000.0;
			break;
		case xieite::units::Area::SquareZettametre:
			result /= 1000000000000000000000000000000000000000000.0;
			break;
		case xieite::units::Area::SquareYottametre:
			result /= 1000000000000000000000000000000000000000000000000.0;
			break;
		case xieite::units::Area::SquareRonnametre:
			result /= 1000000000000000000000000000000000000000000000000000000.0;
			break;
		case xieite::units::Area::SquareQuettametre:
			result /= 1000000000000000000000000000000000000000000000000000000000000.0;
			break;
		case xieite::units::Area::SquareInch:
			result *= 0.00064516;
			break;
		case xieite::units::Area::SquareFoot:
			result *= 0.09290304;
			break;
		case xieite::units::Area::SquareYard:
			result *= 0.83612736;
			break;
		case xieite::units::Area::SquareMile:
			result /= 2589988.110336;
			break;
		case xieite::units::Area::SquareRood:
			result /= 1011.7141056;
			break;
		case xieite::units::Area::Acre:
			result /= 4046.8564224;
			break;
		case xieite::units::Area::Deciare:
			result /= 10.0;
			break;
		case xieite::units::Area::Decare:
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
		case xieite::units::Length::Quectometre:
			result /= 1000000000000000000000000000000.0;
			break;
		case xieite::units::Length::Rontometre:
			result /= 1000000000000000000000000000.0;
			break;
		case xieite::units::Length::Yoctometre:
			result /= 1000000000000000000000000.0;
			break;
		case xieite::units::Length::Zeptometre:
			result /= 1000000000000000000000.0;
			break;
		case xieite::units::Length::Attometre:
			result /= 1000000000000000000.0;
			break;
		case xieite::units::Length::Femtometre:
			result /= 1000000000000000.0;
			break;
		case xieite::units::Length::Picometre:
			result /= 1000000000000.0;
			break;
		case xieite::units::Length::Nanometre:
			result /= 1000000000.0;
			break;
		case xieite::units::Length::Micrometre:
			result /= 1000000.0;
			break;
		case xieite::units::Length::Millimetre:
			result /= 1000.0;
			break;
		case xieite::units::Length::Centimetre:
			result /= 100.0;
			break;
		case xieite::units::Length::Decimetre:
			result /= 10.0;
			break;
		case xieite::units::Length::Decametre:
			result *= 10.0;
			break;
		case xieite::units::Length::Hectometre:
			result *= 100.0;
			break;
		case xieite::units::Length::Kilometre:
			result *= 1000.0;
			break;
		case xieite::units::Length::Megametre:
			result *= 1000000.0;
			break;
		case xieite::units::Length::Gigametre:
			result *= 1000000000.0;
			break;
		case xieite::units::Length::Terametre:
			result *= 1000000000000.0;
			break;
		case xieite::units::Length::Petametre:
			result *= 1000000000000000.0;
			break;
		case xieite::units::Length::Exametre:
			result *= 1000000000000000000.0;
			break;
		case xieite::units::Length::Zettametre:
			result *= 1000000000000000000000.0;
			break;
		case xieite::units::Length::Yottametre:
			result *= 1000000000000000000000000.0;
			break;
		case xieite::units::Length::Ronnametre:
			result *= 1000000000000000000000000000.0;
			break;
		case xieite::units::Length::Quettametre:
			result *= 1000000000000000000000000000000.0;
			break;
		case xieite::units::Length::Twip:
			result /= 0.0254 / 1440.0;
			break;
		case xieite::units::Length::Thou:
			result /= 0.0000254;
			break;
		case xieite::units::Length::Barleycorn:
			result /= 0.0254 / 3.0;
			break;
		case xieite::units::Length::Inch:
			result /= 0.0254;
			break;
		case xieite::units::Length::Foot:
			result *= 0.3048;
			break;
		case xieite::units::Length::Yard:
			result *= 0.9144;
			break;
		case xieite::units::Length::Chain:
			result *= 20.1168;
			break;
		case xieite::units::Length::Furlong:
			result *= 201.168;
			break;
		case xieite::units::Length::Mile:
			result *= 1609.344;
			break;
		case xieite::units::Length::League:
			result *= 4828.032;
			break;
		case xieite::units::Length::Fathom:
			result /= 1.8288;
			break;
		case xieite::units::Length::Cable:
			result *= 185.2;
			break;
		case xieite::units::Length::NauticalMile:
			result *= 1852.0;
			break;
		case xieite::units::Length::NauticalLeague:
			result *= 5556.0;
			break;
		case xieite::units::Length::Link:
			result /= 0.201168;
			break;
		case xieite::units::Length::Rod: [[fallthrough]];
		case xieite::units::Length::Perch: [[fallthrough]];
		case xieite::units::Length::Pole: [[fallthrough]];
		case xieite::units::Length::Lug:
			result *= 5.0292;
			break;
		}
		switch (target) {
		case xieite::units::Length::Quectometre:
			result *= 1000000000000000000000000000000.0;
			break;
		case xieite::units::Length::Rontometre:
			result *= 1000000000000000000000000000.0;
			break;
		case xieite::units::Length::Yoctometre:
			result *= 1000000000000000000000000.0;
			break;
		case xieite::units::Length::Zeptometre:
			result *= 1000000000000000000000.0;
			break;
		case xieite::units::Length::Attometre:
			result *= 1000000000000000000.0;
			break;
		case xieite::units::Length::Femtometre:
			result *= 1000000000000000.0;
			break;
		case xieite::units::Length::Picometre:
			result *= 1000000000000.0;
			break;
		case xieite::units::Length::Nanometre:
			result *= 1000000000.0;
			break;
		case xieite::units::Length::Micrometre:
			result *= 1000000.0;
			break;
		case xieite::units::Length::Millimetre:
			result *= 1000.0;
			break;
		case xieite::units::Length::Centimetre:
			result *= 100.0;
			break;
		case xieite::units::Length::Decimetre:
			result *= 10.0;
			break;
		case xieite::units::Length::Decametre:
			result /= 10.0;
			break;
		case xieite::units::Length::Hectometre:
			result /= 100.0;
			break;
		case xieite::units::Length::Kilometre:
			result /= 1000.0;
			break;
		case xieite::units::Length::Megametre:
			result /= 1000000.0;
			break;
		case xieite::units::Length::Gigametre:
			result /= 1000000000.0;
			break;
		case xieite::units::Length::Terametre:
			result /= 1000000000000.0;
			break;
		case xieite::units::Length::Petametre:
			result /= 1000000000000000.0;
			break;
		case xieite::units::Length::Exametre:
			result /= 1000000000000000000.0;
			break;
		case xieite::units::Length::Zettametre:
			result /= 1000000000000000000000.0;
			break;
		case xieite::units::Length::Yottametre:
			result /= 1000000000000000000000000.0;
			break;
		case xieite::units::Length::Ronnametre:
			result /= 1000000000000000000000000000.0;
			break;
		case xieite::units::Length::Quettametre:
			result /= 1000000000000000000000000000000.0;
			break;
		case xieite::units::Length::Twip:
			result *= 0.0254 / 1440.0;
			break;
		case xieite::units::Length::Thou:
			result *= 0.0000254;
			break;
		case xieite::units::Length::Barleycorn:
			result *= 0.0254 / 3.0;
			break;
		case xieite::units::Length::Inch:
			result *= 0.0254;
			break;
		case xieite::units::Length::Foot:
			result /= 0.3048;
			break;
		case xieite::units::Length::Yard:
			result /= 0.9144;
			break;
		case xieite::units::Length::Chain:
			result /= 20.1168;
			break;
		case xieite::units::Length::Furlong:
			result /= 201.168;
			break;
		case xieite::units::Length::Mile:
			result /= 1609.344;
			break;
		case xieite::units::Length::League:
			result /= 4828.032;
			break;
		case xieite::units::Length::Fathom:
			result *= 1.8288;
			break;
		case xieite::units::Length::Cable:
			result /= 185.2;
			break;
		case xieite::units::Length::NauticalMile:
			result /= 1852.0;
			break;
		case xieite::units::Length::NauticalLeague:
			result /= 5556.0;
			break;
		case xieite::units::Length::Link:
			result *= 0.201168;
			break;
		case xieite::units::Length::Rod: [[fallthrough]];
		case xieite::units::Length::Perch: [[fallthrough]];
		case xieite::units::Length::Pole: [[fallthrough]];
		case xieite::units::Length::Lug:
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
		case xieite::units::Temperature::Celsius:
			result += 273.15;
			break;
		case xieite::units::Temperature::Fahrenheit:
			result = (result - 32.0) / 1.8 + 273.15;
			break;
		case xieite::units::Temperature::Rankine:
			result *= 5.0 / 9.0;
			break;
		}
		switch (target) {
		case xieite::units::Temperature::Celsius:
			result -= 273.15;
			break;
		case xieite::units::Temperature::Fahrenheit:
			result = (result - 273.15) * 1.8 + 32.0;
			break;
		case xieite::units::Temperature::Rankine:
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
		case xieite::units::Volume::CubicQuectometre:
			result /= 1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000.0;
			break;
		case xieite::units::Volume::CubicRontometre:
			result /= 1000000000000000000000000000000000000000000000000000000000000000000000000000000000.0;
			break;
		case xieite::units::Volume::CubicYoctometre:
			result /= 1000000000000000000000000000000000000000000000000000000000000000000000000.0;
			break;
		case xieite::units::Volume::CubicZeptometre:
			result /= 1000000000000000000000000000000000000000000000000000000000000000.0;
			break;
		case xieite::units::Volume::CubicAttometre:
			result /= 1000000000000000000000000000000000000000000000000000000.0;
			break;
		case xieite::units::Volume::CubicFemtometre:
			result /= 1000000000000000000000000000000000000000000000.0;
			break;
		case xieite::units::Volume::CubicPicometre:
			result /= 1000000000000000000000000000000000000.0;
			break;
		case xieite::units::Volume::CubicNanometre:
			result /= 1000000000000000000000000000.0;
			break;
		case xieite::units::Volume::CubicMicrometre:
			result /= 1000000000000000000.0;
			break;
		case xieite::units::Volume::CubicMillimetre:
			result /= 1000000000.0;
			break;
		case xieite::units::Volume::CubicCentimetre:
			result /= 1000000.0;
			break;
		case xieite::units::Volume::CubicDecimetre:
			result /= 1000.0;
			break;
		case xieite::units::Volume::CubicDecametre:
			result *= 1000.0;
			break;
		case xieite::units::Volume::CubicHectometre:
			result *= 1000000.0;
			break;
		case xieite::units::Volume::CubicKilometre:
			result *= 1000000000.0;
			break;
		case xieite::units::Volume::CubicMegametre:
			result *= 1000000000000000000.0;
			break;
		case xieite::units::Volume::CubicGigametre:
			result *= 1000000000000000000000000000.0;
			break;
		case xieite::units::Volume::CubicTerametre:
			result *= 1000000000000000000000000000000000000.0;
			break;
		case xieite::units::Volume::CubicPetametre:
			result *= 1000000000000000000000000000000000000000000000.0;
			break;
		case xieite::units::Volume::CubicExametre:
			result *= 1000000000000000000000000000000000000000000000000000000.0;
			break;
		case xieite::units::Volume::CubicZettametre:
			result *= 1000000000000000000000000000000000000000000000000000000000000000.0;
			break;
		case xieite::units::Volume::CubicYottametre:
			result *= 1000000000000000000000000000000000000000000000000000000000000000000000000.0;
			break;
		case xieite::units::Volume::CubicRonnametre:
			result *= 1000000000000000000000000000000000000000000000000000000000000000000000000000000000.0;
			break;
		case xieite::units::Volume::CubicQuettametre:
			result *= 1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000.0;
			break;
		case xieite::units::Volume::CubicInch:
			result /= 0.000016387064;
			break;
		case xieite::units::Volume::CubicFoot:
			result /= 0.028316846592;
			break;
		case xieite::units::Volume::CubicYard:
			result /= 0.764554857984;
			break;
		case xieite::units::Volume::CubicMile:
			result *= 4168181825.440579584;
			break;
		case xieite::units::Volume::Quectolitre:
			result *= 1000000000000000000000000000000000.0;
			break;
		case xieite::units::Volume::Rontolitre:
			result *= 1000000000000000000000000000000.0;
			break;
		case xieite::units::Volume::Yoctolitre:
			result *= 1000000000000000000000000000.0;
			break;
		case xieite::units::Volume::Zeptolitre:
			result *= 1000000000000000000000000.0;
			break;
		case xieite::units::Volume::Attolitre:
			result *= 1000000000000000000000.0;
			break;
		case xieite::units::Volume::Femtolitre:
			result *= 1000000000000000000.0;
			break;
		case xieite::units::Volume::Picolitre:
			result *= 1000000000000000.0;
			break;
		case xieite::units::Volume::Nanolitre:
			result *= 1000000000000.0;
			break;
		case xieite::units::Volume::Microlitre:
			result *= 1000000000.0;
			break;
		case xieite::units::Volume::Millilitre:
			result *= 1000000.0;
			break;
		case xieite::units::Volume::Centilitre:
			result *= 100000.0;
			break;
		case xieite::units::Volume::Decilitre:
			result *= 10000.0;
			break;
		case xieite::units::Volume::Litre:
			result *= 1000.0;
			break;
		case xieite::units::Volume::Decalitre:
			result *= 100.0;
			break;
		case xieite::units::Volume::Hectolitre:
			result *= 10.0;
			break;
		case xieite::units::Volume::Megalitre:
			result /= 1000.0;
			break;
		case xieite::units::Volume::Gigalitre:
			result /= 1000000.0;
			break;
		case xieite::units::Volume::Teralitre:
			result /= 1000000000.0;
			break;
		case xieite::units::Volume::Petalitre:
			result /= 1000000000000.0;
			break;
		case xieite::units::Volume::Exalitre:
			result /= 1000000000000000.0;
			break;
		case xieite::units::Volume::Zettalitre:
			result /= 1000000000000000000.0;
			break;
		case xieite::units::Volume::Yottalitre:
			result /= 1000000000000000000000.0;
			break;
		case xieite::units::Volume::Ronnalitre:
			result /= 1000000000000000000000000.0;
			break;
		case xieite::units::Volume::Quettalitre:
			result /= 1000000000000000000000000000.0;
			break;
		case xieite::units::Volume::FluidOunce:
			result *= 0.00002957353;
			break;
		case xieite::units::Volume::Gill:
			result *= 0.0001182941;
			break;
		case xieite::units::Volume::Cup:
			result *= 0.0002365882;
			break;
		case xieite::units::Volume::Pint:
			result *= 0.0004731765;
			break;
		case xieite::units::Volume::Quart:
			result *= 0.000946353;
			break;
		case xieite::units::Volume::Gallon:
			result *= 0.003785412;
			break;
		}
		switch (target) {
		case xieite::units::Volume::CubicQuectometre:
			result *= 1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000.0;
			break;
		case xieite::units::Volume::CubicRontometre:
			result *= 1000000000000000000000000000000000000000000000000000000000000000000000000000000000.0;
			break;
		case xieite::units::Volume::CubicYoctometre:
			result *= 1000000000000000000000000000000000000000000000000000000000000000000000000.0;
			break;
		case xieite::units::Volume::CubicZeptometre:
			result *= 1000000000000000000000000000000000000000000000000000000000000000.0;
			break;
		case xieite::units::Volume::CubicAttometre:
			result *= 1000000000000000000000000000000000000000000000000000000.0;
			break;
		case xieite::units::Volume::CubicFemtometre:
			result *= 1000000000000000000000000000000000000000000000.0;
			break;
		case xieite::units::Volume::CubicPicometre:
			result *= 1000000000000000000000000000000000000.0;
			break;
		case xieite::units::Volume::CubicNanometre:
			result *= 1000000000000000000000000000.0;
			break;
		case xieite::units::Volume::CubicMicrometre:
			result *= 1000000000000000000.0;
			break;
		case xieite::units::Volume::CubicMillimetre:
			result *= 1000000000.0;
			break;
		case xieite::units::Volume::CubicCentimetre:
			result *= 1000000.0;
			break;
		case xieite::units::Volume::CubicDecimetre:
			result *= 1000.0;
			break;
		case xieite::units::Volume::CubicDecametre:
			result /= 1000.0;
			break;
		case xieite::units::Volume::CubicHectometre:
			result /= 1000000.0;
			break;
		case xieite::units::Volume::CubicKilometre:
			result /= 1000000000.0;
			break;
		case xieite::units::Volume::CubicMegametre:
			result /= 1000000000000000000.0;
			break;
		case xieite::units::Volume::CubicGigametre:
			result /= 1000000000000000000000000000.0;
			break;
		case xieite::units::Volume::CubicTerametre:
			result /= 1000000000000000000000000000000000000.0;
			break;
		case xieite::units::Volume::CubicPetametre:
			result /= 1000000000000000000000000000000000000000000000.0;
			break;
		case xieite::units::Volume::CubicExametre:
			result /= 1000000000000000000000000000000000000000000000000000000.0;
			break;
		case xieite::units::Volume::CubicZettametre:
			result /= 1000000000000000000000000000000000000000000000000000000000000000.0;
			break;
		case xieite::units::Volume::CubicYottametre:
			result /= 1000000000000000000000000000000000000000000000000000000000000000000000000.0;
			break;
		case xieite::units::Volume::CubicRonnametre:
			result /= 1000000000000000000000000000000000000000000000000000000000000000000000000000000000.0;
			break;
		case xieite::units::Volume::CubicQuettametre:
			result /= 1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000.0;
			break;
		case xieite::units::Volume::CubicInch:
			result *= 0.000016387064;
			break;
		case xieite::units::Volume::CubicFoot:
			result *= 0.028316846592;
			break;
		case xieite::units::Volume::CubicYard:
			result *= 0.764554857984;
			break;
		case xieite::units::Volume::CubicMile:
			result /= 4168181825.440579584;
			break;
		case xieite::units::Volume::Quectolitre:
			result /= 1000000000000000000000000000000000.0;
			break;
		case xieite::units::Volume::Rontolitre:
			result /= 1000000000000000000000000000000.0;
			break;
		case xieite::units::Volume::Yoctolitre:
			result /= 1000000000000000000000000000.0;
			break;
		case xieite::units::Volume::Zeptolitre:
			result /= 1000000000000000000000000.0;
			break;
		case xieite::units::Volume::Attolitre:
			result /= 1000000000000000000000.0;
			break;
		case xieite::units::Volume::Femtolitre:
			result /= 1000000000000000000.0;
			break;
		case xieite::units::Volume::Picolitre:
			result /= 1000000000000000.0;
			break;
		case xieite::units::Volume::Nanolitre:
			result /= 1000000000000.0;
			break;
		case xieite::units::Volume::Microlitre:
			result /= 1000000000.0;
			break;
		case xieite::units::Volume::Millilitre:
			result /= 1000000.0;
			break;
		case xieite::units::Volume::Centilitre:
			result /= 100000.0;
			break;
		case xieite::units::Volume::Decilitre:
			result /= 10000.0;
			break;
		case xieite::units::Volume::Litre:
			result /= 1000.0;
			break;
		case xieite::units::Volume::Decalitre:
			result /= 100.0;
			break;
		case xieite::units::Volume::Hectolitre:
			result /= 10.0;
			break;
		case xieite::units::Volume::Megalitre:
			result *= 1000.0;
			break;
		case xieite::units::Volume::Gigalitre:
			result *= 1000000.0;
			break;
		case xieite::units::Volume::Teralitre:
			result *= 1000000000.0;
			break;
		case xieite::units::Volume::Petalitre:
			result *= 1000000000000.0;
			break;
		case xieite::units::Volume::Exalitre:
			result *= 1000000000000000.0;
			break;
		case xieite::units::Volume::Zettalitre:
			result *= 1000000000000000000.0;
			break;
		case xieite::units::Volume::Yottalitre:
			result *= 1000000000000000000000.0;
			break;
		case xieite::units::Volume::Ronnalitre:
			result *= 1000000000000000000000000.0;
			break;
		case xieite::units::Volume::Quettalitre:
			result *= 1000000000000000000000000000.0;
			break;
		case xieite::units::Volume::FluidOunce:
			result /= 0.00002957353;
			break;
		case xieite::units::Volume::Gill:
			result /= 0.0001182941;
			break;
		case xieite::units::Volume::Cup:
			result /= 0.0002365882;
			break;
		case xieite::units::Volume::Pint:
			result /= 0.0004731765;
			break;
		case xieite::units::Volume::Quart:
			result /= 0.000946353;
			break;
		case xieite::units::Volume::Gallon:
			result /= 0.003785412;
			break;
		}
		return result;
	}
}

#endif
