#ifndef DETAIL_XIEITE_HEADER_MATH_UNIT
#	define DETAIL_XIEITE_HEADER_MATH_UNIT
#
#	include <chrono>
#	include <cstdint>
#	include <functional>
#	include "../data/fixed_str.hpp"
#	include "../math/pi.hpp"

namespace xieite {
	template<xieite::fixed_str type, auto to = std::identity(), auto from = std::identity()>
	struct base_unit {
		double value;

		template<auto other_to, auto other_from>
		[[nodiscard]] explicit(false) constexpr operator xieite::base_unit<type, other_to, other_from>() const noexcept {
			return xieite::base_unit<type, other_to, other_from>(other_from(to(this->value)));
		}
	};
}

namespace DETAIL_XIEITE::unit {
	template<double x>
	constexpr auto mul = [](double y) { return y * x; };

	template<double x>
	constexpr auto div = [](double y) { return y / x; };

	template<double x>
	constexpr auto add = [](double y) { return y + x; };

	template<double x, double y, double z>
	constexpr auto fahrenheit = [](double w) { return (w - x) * y + z; };
}

namespace xieite::unit {
	// Lengths
	using qm = xieite::base_unit<"len", DETAIL_XIEITE::unit::div<1e30>, DETAIL_XIEITE::unit::mul<1e30>>;
	using rm = xieite::base_unit<"len", DETAIL_XIEITE::unit::div<1e27>, DETAIL_XIEITE::unit::mul<1e27>>;
	using ym = xieite::base_unit<"len", DETAIL_XIEITE::unit::div<1e24>, DETAIL_XIEITE::unit::mul<1e24>>;
	using zm = xieite::base_unit<"len", DETAIL_XIEITE::unit::div<1e21>, DETAIL_XIEITE::unit::mul<1e21>>;
	using am = xieite::base_unit<"len", DETAIL_XIEITE::unit::div<1e18>, DETAIL_XIEITE::unit::mul<1e18>>;
	using fm = xieite::base_unit<"len", DETAIL_XIEITE::unit::div<1e15>, DETAIL_XIEITE::unit::mul<1e15>>;
	using pm = xieite::base_unit<"len", DETAIL_XIEITE::unit::div<1e12>, DETAIL_XIEITE::unit::mul<1e12>>;
	using nm = xieite::base_unit<"len", DETAIL_XIEITE::unit::div<1e9>, DETAIL_XIEITE::unit::mul<1e9>>;
	using um = xieite::base_unit<"len", DETAIL_XIEITE::unit::div<1e6>, DETAIL_XIEITE::unit::mul<1e6>>;
	using mm = xieite::base_unit<"len", DETAIL_XIEITE::unit::div<1e3>, DETAIL_XIEITE::unit::mul<1e3>>;
	using cm = xieite::base_unit<"len", DETAIL_XIEITE::unit::div<1e2>, DETAIL_XIEITE::unit::mul<1e2>>;
	using dm = xieite::base_unit<"len", DETAIL_XIEITE::unit::div<1e1>, DETAIL_XIEITE::unit::mul<1e1>>;
	using m = xieite::base_unit<"len">;
	using dam = xieite::base_unit<"len", DETAIL_XIEITE::unit::mul<1e1>, DETAIL_XIEITE::unit::div<1e1>>;
	using hm = xieite::base_unit<"len", DETAIL_XIEITE::unit::mul<1e2>, DETAIL_XIEITE::unit::div<1e2>>;
	using km = xieite::base_unit<"len", DETAIL_XIEITE::unit::mul<1e3>, DETAIL_XIEITE::unit::div<1e3>>;
	using Mm = xieite::base_unit<"len", DETAIL_XIEITE::unit::mul<1e6>, DETAIL_XIEITE::unit::div<1e6>>;
	using Gm = xieite::base_unit<"len", DETAIL_XIEITE::unit::mul<1e9>, DETAIL_XIEITE::unit::div<1e9>>;
	using Tm = xieite::base_unit<"len", DETAIL_XIEITE::unit::mul<1e12>, DETAIL_XIEITE::unit::div<1e12>>;
	using Pm = xieite::base_unit<"len", DETAIL_XIEITE::unit::mul<1e15>, DETAIL_XIEITE::unit::div<1e15>>;
	using Em = xieite::base_unit<"len", DETAIL_XIEITE::unit::mul<1e18>, DETAIL_XIEITE::unit::div<1e18>>;
	using Zm = xieite::base_unit<"len", DETAIL_XIEITE::unit::mul<1e21>, DETAIL_XIEITE::unit::div<1e21>>;
	using Ym = xieite::base_unit<"len", DETAIL_XIEITE::unit::mul<1e24>, DETAIL_XIEITE::unit::div<1e24>>;
	using Rm = xieite::base_unit<"len", DETAIL_XIEITE::unit::mul<1e27>, DETAIL_XIEITE::unit::div<1e27>>;
	using Qm = xieite::base_unit<"len", DETAIL_XIEITE::unit::mul<1e30>, DETAIL_XIEITE::unit::div<1e30>>;
	using twips = xieite::base_unit<"len", DETAIL_XIEITE::unit::mul<(0.0254 / 1440.0)>, DETAIL_XIEITE::unit::mul<(1440.0 / 0.0254)>>;
	using thous = xieite::base_unit<"len", DETAIL_XIEITE::unit::mul<0.0000254>, DETAIL_XIEITE::unit::div<0.0000254>>;
	using barleycorns = xieite::base_unit<"len", DETAIL_XIEITE::unit::mul<(0.0254 / 3.0)>, DETAIL_XIEITE::unit::mul<(3.0 / 0.0254)>>;
	using in = xieite::base_unit<"len", DETAIL_XIEITE::unit::mul<0.0254>, DETAIL_XIEITE::unit::div<0.0254>>;
	using ft = xieite::base_unit<"len", DETAIL_XIEITE::unit::mul<0.3048>, DETAIL_XIEITE::unit::div<0.3048>>;
	using yd = xieite::base_unit<"len", DETAIL_XIEITE::unit::mul<0.9144>, DETAIL_XIEITE::unit::div<0.9144>>;
	using chains = xieite::base_unit<"len", DETAIL_XIEITE::unit::mul<20.1168>, DETAIL_XIEITE::unit::div<20.1168>>;
	using furlongs = xieite::base_unit<"len", DETAIL_XIEITE::unit::mul<201.168>, DETAIL_XIEITE::unit::div<201.168>>;
	using mi = xieite::base_unit<"len", DETAIL_XIEITE::unit::mul<1609.344>, DETAIL_XIEITE::unit::div<1609.344>>;
	using leagues = xieite::base_unit<"len", DETAIL_XIEITE::unit::mul<4828.032>, DETAIL_XIEITE::unit::div<4828.032>>;
	using fathoms = xieite::base_unit<"len", DETAIL_XIEITE::unit::mul<1.8288>, DETAIL_XIEITE::unit::div<1.8288>>;
	using cables = xieite::base_unit<"len", DETAIL_XIEITE::unit::mul<185.2>, DETAIL_XIEITE::unit::div<185.2>>;
	using nmi = xieite::base_unit<"len", DETAIL_XIEITE::unit::mul<1852.0>, DETAIL_XIEITE::unit::div<1852.0>>;
	using nau_leagues = xieite::base_unit<"len", DETAIL_XIEITE::unit::mul<5556.0>, DETAIL_XIEITE::unit::div<5556.0>>;
	using links = xieite::base_unit<"len", DETAIL_XIEITE::unit::mul<0.201168>, DETAIL_XIEITE::unit::div<0.201168>>;
	using rods = xieite::base_unit<"len", DETAIL_XIEITE::unit::mul<5.0292>, DETAIL_XIEITE::unit::div<5.0292>>;
	using perches = xieite::unit::rods;
	using poles = xieite::unit::rods;
	using lugs = xieite::unit::rods;

	// Areas
	using qA = xieite::base_unit<"area", DETAIL_XIEITE::unit::div<1e60>, DETAIL_XIEITE::unit::mul<1e60>>;
	using rA = xieite::base_unit<"area", DETAIL_XIEITE::unit::div<1e54>, DETAIL_XIEITE::unit::mul<1e54>>;
	using yA = xieite::base_unit<"area", DETAIL_XIEITE::unit::div<1e48>, DETAIL_XIEITE::unit::mul<1e48>>;
	using zA = xieite::base_unit<"area", DETAIL_XIEITE::unit::div<1e42>, DETAIL_XIEITE::unit::mul<1e42>>;
	using aA = xieite::base_unit<"area", DETAIL_XIEITE::unit::div<1e36>, DETAIL_XIEITE::unit::mul<1e36>>;
	using fA = xieite::base_unit<"area", DETAIL_XIEITE::unit::div<1e30>, DETAIL_XIEITE::unit::mul<1e30>>;
	using pA = xieite::base_unit<"area", DETAIL_XIEITE::unit::div<1e24>, DETAIL_XIEITE::unit::mul<1e24>>;
	using nA = xieite::base_unit<"area", DETAIL_XIEITE::unit::div<1e18>, DETAIL_XIEITE::unit::mul<1e18>>;
	using uA = xieite::base_unit<"area", DETAIL_XIEITE::unit::div<1e12>, DETAIL_XIEITE::unit::mul<1e12>>;
	using mA = xieite::base_unit<"area", DETAIL_XIEITE::unit::div<1e6>, DETAIL_XIEITE::unit::mul<1e6>>;
	using cA = xieite::base_unit<"area", DETAIL_XIEITE::unit::div<1e4>, DETAIL_XIEITE::unit::mul<1e4>>;
	using dA = xieite::base_unit<"area", DETAIL_XIEITE::unit::div<1e2>, DETAIL_XIEITE::unit::mul<1e2>>;
	using A = xieite::base_unit<"area">;
	using daA = xieite::base_unit<"area", DETAIL_XIEITE::unit::mul<1e2>, DETAIL_XIEITE::unit::div<1e2>>;
	using hA = xieite::base_unit<"area", DETAIL_XIEITE::unit::mul<1e4>, DETAIL_XIEITE::unit::div<1e4>>;
	using kA = xieite::base_unit<"area", DETAIL_XIEITE::unit::mul<1e6>, DETAIL_XIEITE::unit::div<1e6>>;
	using MA = xieite::base_unit<"area", DETAIL_XIEITE::unit::mul<1e12>, DETAIL_XIEITE::unit::div<1e12>>;
	using GA = xieite::base_unit<"area", DETAIL_XIEITE::unit::mul<1e18>, DETAIL_XIEITE::unit::div<1e18>>;
	using TA = xieite::base_unit<"area", DETAIL_XIEITE::unit::mul<1e24>, DETAIL_XIEITE::unit::div<1e24>>;
	using PA = xieite::base_unit<"area", DETAIL_XIEITE::unit::mul<1e30>, DETAIL_XIEITE::unit::div<1e30>>;
	using EA = xieite::base_unit<"area", DETAIL_XIEITE::unit::mul<1e36>, DETAIL_XIEITE::unit::div<1e36>>;
	using ZA = xieite::base_unit<"area", DETAIL_XIEITE::unit::mul<1e42>, DETAIL_XIEITE::unit::div<1e42>>;
	using YA = xieite::base_unit<"area", DETAIL_XIEITE::unit::mul<1e48>, DETAIL_XIEITE::unit::div<1e48>>;
	using RA = xieite::base_unit<"area", DETAIL_XIEITE::unit::mul<1e54>, DETAIL_XIEITE::unit::div<1e54>>;
	using QA = xieite::base_unit<"area", DETAIL_XIEITE::unit::mul<1e60>, DETAIL_XIEITE::unit::div<1e60>>;
	using sq_in = xieite::base_unit<"area", DETAIL_XIEITE::unit::div<1550.0031>, DETAIL_XIEITE::unit::mul<1550.0031>>;
	using sq_ft = xieite::base_unit<"area", DETAIL_XIEITE::unit::div<10.7639104>, DETAIL_XIEITE::unit::mul<10.7639104>>;
	using sq_yd = xieite::base_unit<"area", DETAIL_XIEITE::unit::mul<0.83612736>, DETAIL_XIEITE::unit::div<0.83612736>>;
	using sq_mi = xieite::base_unit<"area", DETAIL_XIEITE::unit::mul<2589988.110336>, DETAIL_XIEITE::unit::div<2589988.110336>>;
	using sq_roods = xieite::base_unit<"area", DETAIL_XIEITE::unit::mul<1011.7141056>, DETAIL_XIEITE::unit::div<1011.7141056>>;
	using ac = xieite::base_unit<"area", DETAIL_XIEITE::unit::mul<4046.8564224>, DETAIL_XIEITE::unit::div<4046.8564224>>;
	using dma = xieite::unit::dA;
	using ca = xieite::unit::A;
	using da = xieite::base_unit<"area", DETAIL_XIEITE::unit::mul<1e1>, DETAIL_XIEITE::unit::div<1e1>>;
	using a = xieite::unit::daA;
	using daa = xieite::base_unit<"area", DETAIL_XIEITE::unit::mul<1e3>, DETAIL_XIEITE::unit::div<1e3>>;
	using ha = xieite::unit::hA;

	// Volumes
	using qV = xieite::base_unit<"vol", DETAIL_XIEITE::unit::div<1e90>, DETAIL_XIEITE::unit::mul<1e90>>;
	using rV = xieite::base_unit<"vol", DETAIL_XIEITE::unit::div<1e81>, DETAIL_XIEITE::unit::mul<1e81>>;
	using yV = xieite::base_unit<"vol", DETAIL_XIEITE::unit::div<1e72>, DETAIL_XIEITE::unit::mul<1e72>>;
	using zV = xieite::base_unit<"vol", DETAIL_XIEITE::unit::div<1e63>, DETAIL_XIEITE::unit::mul<1e63>>;
	using aV = xieite::base_unit<"vol", DETAIL_XIEITE::unit::div<1e54>, DETAIL_XIEITE::unit::mul<1e54>>;
	using fV = xieite::base_unit<"vol", DETAIL_XIEITE::unit::div<1e45>, DETAIL_XIEITE::unit::mul<1e45>>;
	using pV = xieite::base_unit<"vol", DETAIL_XIEITE::unit::div<1e36>, DETAIL_XIEITE::unit::mul<1e36>>;
	using nV = xieite::base_unit<"vol", DETAIL_XIEITE::unit::div<1e27>, DETAIL_XIEITE::unit::mul<1e27>>;
	using uV = xieite::base_unit<"vol", DETAIL_XIEITE::unit::div<1e18>, DETAIL_XIEITE::unit::mul<1e18>>;
	using mV = xieite::base_unit<"vol", DETAIL_XIEITE::unit::div<1e9>, DETAIL_XIEITE::unit::mul<1e9>>;
	using cV = xieite::base_unit<"vol", DETAIL_XIEITE::unit::div<1e6>, DETAIL_XIEITE::unit::mul<1e6>>;
	using dV = xieite::base_unit<"vol", DETAIL_XIEITE::unit::div<1e3>, DETAIL_XIEITE::unit::mul<1e3>>;
	using V = xieite::base_unit<"vol">;
	using daV = xieite::base_unit<"vol", DETAIL_XIEITE::unit::mul<1e3>, DETAIL_XIEITE::unit::div<1e3>>;
	using hV = xieite::base_unit<"vol", DETAIL_XIEITE::unit::mul<1e6>, DETAIL_XIEITE::unit::div<1e6>>;
	using kV = xieite::base_unit<"vol", DETAIL_XIEITE::unit::mul<1e9>, DETAIL_XIEITE::unit::div<1e9>>;
	using MV = xieite::base_unit<"vol", DETAIL_XIEITE::unit::mul<1e18>, DETAIL_XIEITE::unit::div<1e18>>;
	using GV = xieite::base_unit<"vol", DETAIL_XIEITE::unit::mul<1e27>, DETAIL_XIEITE::unit::div<1e27>>;
	using TV = xieite::base_unit<"vol", DETAIL_XIEITE::unit::mul<1e36>, DETAIL_XIEITE::unit::div<1e36>>;
	using PV = xieite::base_unit<"vol", DETAIL_XIEITE::unit::mul<1e45>, DETAIL_XIEITE::unit::div<1e45>>;
	using EV = xieite::base_unit<"vol", DETAIL_XIEITE::unit::mul<1e54>, DETAIL_XIEITE::unit::div<1e54>>;
	using ZV = xieite::base_unit<"vol", DETAIL_XIEITE::unit::mul<1e63>, DETAIL_XIEITE::unit::div<1e63>>;
	using YV = xieite::base_unit<"vol", DETAIL_XIEITE::unit::mul<1e72>, DETAIL_XIEITE::unit::div<1e72>>;
	using RV = xieite::base_unit<"vol", DETAIL_XIEITE::unit::mul<1e81>, DETAIL_XIEITE::unit::div<1e81>>;
	using QV = xieite::base_unit<"vol", DETAIL_XIEITE::unit::mul<1e90>, DETAIL_XIEITE::unit::div<1e90>>;
	using cu_in = xieite::base_unit<"vol", DETAIL_XIEITE::unit::div<61023.744095>, DETAIL_XIEITE::unit::mul<61023.744095>>;
	using cu_ft = xieite::base_unit<"vol", DETAIL_XIEITE::unit::div<35.314666721>, DETAIL_XIEITE::unit::mul<35.314666721>>;
	using cu_yd = xieite::base_unit<"vol", DETAIL_XIEITE::unit::div<1.3079506193>, DETAIL_XIEITE::unit::mul<1.3079506193>>;
	using cu_mi = xieite::base_unit<"vol", DETAIL_XIEITE::unit::div<4168181825.440579584>, DETAIL_XIEITE::unit::mul<4168181825.440579584>>;
	using qL = xieite::base_unit<"vol", DETAIL_XIEITE::unit::div<1e33>, DETAIL_XIEITE::unit::mul<1e33>>;
	using rL = xieite::base_unit<"vol", DETAIL_XIEITE::unit::div<1e30>, DETAIL_XIEITE::unit::mul<1e30>>;
	using yL = xieite::unit::nV;
	using zL = xieite::base_unit<"vol", DETAIL_XIEITE::unit::div<1e24>, DETAIL_XIEITE::unit::mul<1e24>>;
	using aL = xieite::base_unit<"vol", DETAIL_XIEITE::unit::div<1e21>, DETAIL_XIEITE::unit::mul<1e21>>;
	using fL = xieite::unit::uV;
	using pL = xieite::base_unit<"vol", DETAIL_XIEITE::unit::div<1e15>, DETAIL_XIEITE::unit::mul<1e15>>;
	using nL = xieite::base_unit<"vol", DETAIL_XIEITE::unit::div<1e12>, DETAIL_XIEITE::unit::mul<1e12>>;
	using uL = xieite::unit::mV;
	using mL = xieite::unit::cV;
	using cL = xieite::base_unit<"vol", DETAIL_XIEITE::unit::div<1e5>, DETAIL_XIEITE::unit::mul<1e5>>;
	using dL = xieite::base_unit<"vol", DETAIL_XIEITE::unit::div<1e4>, DETAIL_XIEITE::unit::mul<1e4>>;
	using L = xieite::unit::dV;
	using daL = xieite::base_unit<"vol", DETAIL_XIEITE::unit::div<1e2>, DETAIL_XIEITE::unit::mul<1e2>>;
	using hL = xieite::base_unit<"vol", DETAIL_XIEITE::unit::div<1e1>, DETAIL_XIEITE::unit::mul<1e1>>;
	using kL = xieite::unit::V;
	using ML = xieite::unit::daV;
	using GL = xieite::unit::hV;
	using TL = xieite::unit::kV;
	using PL = xieite::base_unit<"vol", DETAIL_XIEITE::unit::mul<1e12>, DETAIL_XIEITE::unit::div<1e12>>;
	using EL = xieite::base_unit<"vol", DETAIL_XIEITE::unit::mul<1e15>, DETAIL_XIEITE::unit::div<1e15>>;
	using ZL = xieite::unit::MV;
	using YL = xieite::base_unit<"vol", DETAIL_XIEITE::unit::mul<1e21>, DETAIL_XIEITE::unit::div<1e21>>;
	using RL = xieite::base_unit<"vol", DETAIL_XIEITE::unit::mul<1e24>, DETAIL_XIEITE::unit::div<1e24>>;
	using QL = xieite::unit::GV;
	using fl_oz = xieite::base_unit<"vol", DETAIL_XIEITE::unit::div<33814.022702>, DETAIL_XIEITE::unit::mul<33814.022702>>;
	using gills = xieite::base_unit<"vol", DETAIL_XIEITE::unit::div<7039.0159455708>, DETAIL_XIEITE::unit::mul<7039.0159455708>>;
	using cups = xieite::base_unit<"vol", DETAIL_XIEITE::unit::div<3519.5079727854>, DETAIL_XIEITE::unit::mul<3519.5079727854>>;
	using pt = xieite::base_unit<"vol", DETAIL_XIEITE::unit::div<1759.7539863927>, DETAIL_XIEITE::unit::mul<1759.7539863927>>;
	using qt = xieite::base_unit<"vol", DETAIL_XIEITE::unit::div<879.87699319635>, DETAIL_XIEITE::unit::mul<879.87699319635>>;
	using gal = xieite::base_unit<"vol", DETAIL_XIEITE::unit::div<219.9691574>, DETAIL_XIEITE::unit::mul<219.9691574>>;

	// Angles
	using rad = xieite::base_unit<"angle">;
	using deg = xieite::base_unit<"angle", DETAIL_XIEITE::unit::mul<(xieite::pi<double> / 180.0)>, DETAIL_XIEITE::unit::mul<(180.0 / xieite::pi<double>)>>;

	// Temperature scales
	using K = xieite::base_unit<"temp">;
	using C = xieite::base_unit<"temp", DETAIL_XIEITE::unit::add<-273.15>, DETAIL_XIEITE::unit::add<273.15>>;
	using F = xieite::base_unit<"temp", DETAIL_XIEITE::unit::fahrenheit<32.0, (1 / 1.8), 273.15>, DETAIL_XIEITE::unit::fahrenheit<273.15, 1.8, 32.0>>;
	using R = xieite::base_unit<"temp", DETAIL_XIEITE::unit::div<1.8>, DETAIL_XIEITE::unit::mul<1.8>>;

	// Durations
	using decades = std::chrono::duration<std::intmax_t, std::ratio<315569520>>;
	using centuries = std::chrono::duration<std::intmax_t, std::ratio<3155695200>>;
	using millenniums = std::chrono::duration<std::intmax_t, std::ratio<31556952000>>;
	using epochs = std::chrono::duration<std::intmax_t, std::ratio<31556952000000>>;
	using eons = std::chrono::duration<std::intmax_t, std::ratio<31556952000000000>>;
}

#endif
