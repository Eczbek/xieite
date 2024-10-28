module;

#include <xieite/fn.hpp>

export module xieite:unit;

import std;
import :fixed_str;
import :pi;

template<xieite::fixed_str type, auto to = XIEITE_GFN(_0), auto from = XIEITE_GFN(_0)>
struct base_unit {
	double value;

	template<auto other_to, auto other_from>
	[[nodiscard]] explicit(false) constexpr operator base_unit<type, other_to, other_from>() const noexcept {
		return base_unit<type, other_to, other_from>(other_from(to(this->value)));
	}
};

export namespace xieite::unit {
	// Lengths
	using qm = base_unit<"length", XIEITE_GFN(_0 / 1e30), XIEITE_GFN(_0 * 1e30)>;
	using rm = base_unit<"length", XIEITE_GFN(_0 / 1e27), XIEITE_GFN(_0 * 1e27)>;
	using ym = base_unit<"length", XIEITE_GFN(_0 / 1e24), XIEITE_GFN(_0 * 1e24)>;
	using zm = base_unit<"length", XIEITE_GFN(_0 / 1e21), XIEITE_GFN(_0 * 1e21)>;
	using am = base_unit<"length", XIEITE_GFN(_0 / 1e18), XIEITE_GFN(_0 * 1e18)>;
	using fm = base_unit<"length", XIEITE_GFN(_0 / 1e15), XIEITE_GFN(_0 * 1e15)>;
	using pm = base_unit<"length", XIEITE_GFN(_0 / 1e12), XIEITE_GFN(_0 * 1e12)>;
	using nm = base_unit<"length", XIEITE_GFN(_0 / 1e9), XIEITE_GFN(_0 * 1e9)>;
	using um = base_unit<"length", XIEITE_GFN(_0 / 1e6), XIEITE_GFN(_0 * 1e6)>;
	using mm = base_unit<"length", XIEITE_GFN(_0 / 1e3), XIEITE_GFN(_0 * 1e3)>;
	using cm = base_unit<"length", XIEITE_GFN(_0 / 1e2), XIEITE_GFN(_0 * 1e2)>;
	using dm = base_unit<"length", XIEITE_GFN(_0 / 1e1), XIEITE_GFN(_0 * 1e1)>;
	using m = base_unit<"length">;
	using dam = base_unit<"length", XIEITE_GFN(_0 * 1e1), XIEITE_GFN(_0 / 1e1)>;
	using hm = base_unit<"length", XIEITE_GFN(_0 * 1e2), XIEITE_GFN(_0 / 1e2)>;
	using km = base_unit<"length", XIEITE_GFN(_0 * 1e3), XIEITE_GFN(_0 / 1e3)>;
	using Mm = base_unit<"length", XIEITE_GFN(_0 * 1e6), XIEITE_GFN(_0 / 1e6)>;
	using Gm = base_unit<"length", XIEITE_GFN(_0 * 1e9), XIEITE_GFN(_0 / 1e9)>;
	using Tm = base_unit<"length", XIEITE_GFN(_0 * 1e12), XIEITE_GFN(_0 / 1e12)>;
	using Pm = base_unit<"length", XIEITE_GFN(_0 * 1e15), XIEITE_GFN(_0 / 1e15)>;
	using Em = base_unit<"length", XIEITE_GFN(_0 * 1e18), XIEITE_GFN(_0 / 1e18)>;
	using Zm = base_unit<"length", XIEITE_GFN(_0 * 1e21), XIEITE_GFN(_0 / 1e21)>;
	using Ym = base_unit<"length", XIEITE_GFN(_0 * 1e24), XIEITE_GFN(_0 / 1e24)>;
	using Rm = base_unit<"length", XIEITE_GFN(_0 * 1e27), XIEITE_GFN(_0 / 1e27)>;
	using Qm = base_unit<"length", XIEITE_GFN(_0 * 1e30), XIEITE_GFN(_0 / 1e30)>;
	using twips = base_unit<"length", XIEITE_GFN(_0 * 0.0254 / 1440.0), XIEITE_GFN(_0 * 1440.0 / 0.0254)>;
	using thous = base_unit<"length", XIEITE_GFN(_0 * 0.0000254), XIEITE_GFN(_0 / 0.0000254)>;
	using barleycorns = base_unit<"length", XIEITE_GFN(_0 * 0.0254 / 3.0), XIEITE_GFN(_0 * 3.0 / 0.0254)>;
	using in = base_unit<"length", XIEITE_GFN(_0 * 0.0254), XIEITE_GFN(_0 / 0.0254)>;
	using ft = base_unit<"length", XIEITE_GFN(_0 / 0.3048), XIEITE_GFN(_0 * 0.3048)>;
	using yd = base_unit<"length", XIEITE_GFN(_0 * 0.9144), XIEITE_GFN(_0 / 0.9144)>;
	using chains = base_unit<"length", XIEITE_GFN(_0 * 20.1168), XIEITE_GFN(_0 / 20.1168)>;
	using furlongs = base_unit<"length", XIEITE_GFN(_0 * 201.168), XIEITE_GFN(_0 / 201.168)>;
	using mi = base_unit<"length", XIEITE_GFN(_0 * 1609.344), XIEITE_GFN(_0 / 1609.344)>;
	using leagues = base_unit<"length", XIEITE_GFN(_0 * 4828.032), XIEITE_GFN(_0 / 4828.032)>;
	using fathoms = base_unit<"length", XIEITE_GFN(_0 * 1.8288), XIEITE_GFN(_0 / 1.8288)>;
	using cables = base_unit<"length", XIEITE_GFN(_0 * 185.2), XIEITE_GFN(_0 / 185.2)>;
	using nmi = base_unit<"length", XIEITE_GFN(_0 * 1852.0), XIEITE_GFN(_0 / 1852.0)>;
	using nau_leagues = base_unit<"length", XIEITE_GFN(_0 * 5556.0), XIEITE_GFN(_0 / 5556.0)>;
	using links = base_unit<"length", XIEITE_GFN(_0 * 0.201168), XIEITE_GFN(_0 / 0.201168)>;
	using rods = base_unit<"length", XIEITE_GFN(_0 * 5.0292), XIEITE_GFN(_0 / 5.0292)>;
	using perches = xieite::unit::rods;
	using poles = xieite::unit::rods;
	using lugs = xieite::unit::rods;

	// Areas
	using qA = base_unit<"area", XIEITE_GFN(_0 / 1e60), XIEITE_GFN(_0 * 1e60)>;
	using rA = base_unit<"area", XIEITE_GFN(_0 / 1e54), XIEITE_GFN(_0 * 1e54)>;
	using yA = base_unit<"area", XIEITE_GFN(_0 / 1e48), XIEITE_GFN(_0 * 1e48)>;
	using zA = base_unit<"area", XIEITE_GFN(_0 / 1e42), XIEITE_GFN(_0 * 1e42)>;
	using aA = base_unit<"area", XIEITE_GFN(_0 / 1e36), XIEITE_GFN(_0 * 1e36)>;
	using fA = base_unit<"area", XIEITE_GFN(_0 / 1e30), XIEITE_GFN(_0 * 1e30)>;
	using pA = base_unit<"area", XIEITE_GFN(_0 / 1e24), XIEITE_GFN(_0 * 1e24)>;
	using nA = base_unit<"area", XIEITE_GFN(_0 / 1e18), XIEITE_GFN(_0 * 1e18)>;
	using uA = base_unit<"area", XIEITE_GFN(_0 / 1e12), XIEITE_GFN(_0 * 1e12)>;
	using mA = base_unit<"area", XIEITE_GFN(_0 / 1e6), XIEITE_GFN(_0 * 1e6)>;
	using cA = base_unit<"area", XIEITE_GFN(_0 / 1e4), XIEITE_GFN(_0 * 1e4)>;
	using dA = base_unit<"area", XIEITE_GFN(_0 / 1e2), XIEITE_GFN(_0 * 1e2)>;
	using A = base_unit<"area">;
	using daA = base_unit<"area", XIEITE_GFN(_0 * 1e2), XIEITE_GFN(_0 / 1e2)>;
	using hA = base_unit<"area", XIEITE_GFN(_0 * 1e4), XIEITE_GFN(_0 / 1e4)>;
	using kA = base_unit<"area", XIEITE_GFN(_0 * 1e6), XIEITE_GFN(_0 / 1e6)>;
	using MA = base_unit<"area", XIEITE_GFN(_0 * 1e12), XIEITE_GFN(_0 / 1e12)>;
	using GA = base_unit<"area", XIEITE_GFN(_0 * 1e18), XIEITE_GFN(_0 / 1e18)>;
	using TA = base_unit<"area", XIEITE_GFN(_0 * 1e24), XIEITE_GFN(_0 / 1e24)>;
	using PA = base_unit<"area", XIEITE_GFN(_0 * 1e30), XIEITE_GFN(_0 / 1e30)>;
	using EA = base_unit<"area", XIEITE_GFN(_0 * 1e36), XIEITE_GFN(_0 / 1e36)>;
	using ZA = base_unit<"area", XIEITE_GFN(_0 * 1e42), XIEITE_GFN(_0 / 1e42)>;
	using YA = base_unit<"area", XIEITE_GFN(_0 * 1e48), XIEITE_GFN(_0 / 1e48)>;
	using RA = base_unit<"area", XIEITE_GFN(_0 * 1e54), XIEITE_GFN(_0 / 1e54)>;
	using QA = base_unit<"area", XIEITE_GFN(_0 * 1e60), XIEITE_GFN(_0 / 1e60)>;
	using sq_in = base_unit<"area", XIEITE_GFN(_0 / 1550.0031), XIEITE_GFN(_0 * 1550.0031)>;
	using sq_ft = base_unit<"area", XIEITE_GFN(_0 / 10.7639104), XIEITE_GFN(_0 * 10.7639104)>;
	using sq_yd = base_unit<"area", XIEITE_GFN(_0 * 0.83612736), XIEITE_GFN(_0 / 0.83612736)>;
	using sq_mi = base_unit<"area", XIEITE_GFN(_0 * 2589988.110336), XIEITE_GFN(_0 / 2589988.110336)>;
	using sq_roods = base_unit<"area", XIEITE_GFN(_0 * 1011.7141056), XIEITE_GFN(_0 / 1011.7141056)>;
	using ac = base_unit<"area", XIEITE_GFN(_0 * 4046.8564224), XIEITE_GFN(_0 / 4046.8564224)>;
	using dma = xieite::unit::dA;
	using ca = xieite::unit::A;
	using da = base_unit<"area", XIEITE_GFN(_0 * 1e1), XIEITE_GFN(_0 / 1e1)>;
	using a = xieite::unit::daA;
	using daa = base_unit<"area", XIEITE_GFN(_0 * 1e3), XIEITE_GFN(_0 / 1e3)>;
	using ha = xieite::unit::hA;

	// Volumes
	using qV = base_unit<"volume", XIEITE_GFN(_0 / 1e90), XIEITE_GFN(_0 * 1e90)>;
	using rV = base_unit<"volume", XIEITE_GFN(_0 / 1e81), XIEITE_GFN(_0 * 1e81)>;
	using yV = base_unit<"volume", XIEITE_GFN(_0 / 1e72), XIEITE_GFN(_0 * 1e72)>;
	using zV = base_unit<"volume", XIEITE_GFN(_0 / 1e63), XIEITE_GFN(_0 * 1e63)>;
	using aV = base_unit<"volume", XIEITE_GFN(_0 / 1e54), XIEITE_GFN(_0 * 1e54)>;
	using fV = base_unit<"volume", XIEITE_GFN(_0 / 1e45), XIEITE_GFN(_0 * 1e45)>;
	using pV = base_unit<"volume", XIEITE_GFN(_0 / 1e36), XIEITE_GFN(_0 * 1e36)>;
	using nV = base_unit<"volume", XIEITE_GFN(_0 / 1e27), XIEITE_GFN(_0 * 1e27)>;
	using uV = base_unit<"volume", XIEITE_GFN(_0 / 1e18), XIEITE_GFN(_0 * 1e18)>;
	using mV = base_unit<"volume", XIEITE_GFN(_0 / 1e9), XIEITE_GFN(_0 * 1e9)>;
	using cV = base_unit<"volume", XIEITE_GFN(_0 / 1e6), XIEITE_GFN(_0 * 1e6)>;
	using dV = base_unit<"volume", XIEITE_GFN(_0 / 1e3), XIEITE_GFN(_0 * 1e3)>;
	using V = base_unit<"volume">;
	using daV = base_unit<"volume", XIEITE_GFN(_0 * 1e3), XIEITE_GFN(_0 / 1e3)>;
	using hV = base_unit<"volume", XIEITE_GFN(_0 * 1e6), XIEITE_GFN(_0 / 1e6)>;
	using kV = base_unit<"volume", XIEITE_GFN(_0 * 1e9), XIEITE_GFN(_0 / 1e9)>;
	using MV = base_unit<"volume", XIEITE_GFN(_0 * 1e18), XIEITE_GFN(_0 / 1e18)>;
	using GV = base_unit<"volume", XIEITE_GFN(_0 * 1e27), XIEITE_GFN(_0 / 1e27)>;
	using TV = base_unit<"volume", XIEITE_GFN(_0 * 1e36), XIEITE_GFN(_0 / 1e36)>;
	using PV = base_unit<"volume", XIEITE_GFN(_0 * 1e45), XIEITE_GFN(_0 / 1e45)>;
	using EV = base_unit<"volume", XIEITE_GFN(_0 * 1e54), XIEITE_GFN(_0 / 1e54)>;
	using ZV = base_unit<"volume", XIEITE_GFN(_0 * 1e63), XIEITE_GFN(_0 / 1e63)>;
	using YV = base_unit<"volume", XIEITE_GFN(_0 * 1e72), XIEITE_GFN(_0 / 1e72)>;
	using RV = base_unit<"volume", XIEITE_GFN(_0 * 1e81), XIEITE_GFN(_0 / 1e81)>;
	using QV = base_unit<"volume", XIEITE_GFN(_0 * 1e90), XIEITE_GFN(_0 / 1e90)>;
	using cu_in = base_unit<"volume", XIEITE_GFN(_0 / 61023.744095), XIEITE_GFN(_0 * 61023.744095)>;
	using cu_ft = base_unit<"volume", XIEITE_GFN(_0 / 35.314666721), XIEITE_GFN(_0 * 35.314666721)>;
	using cu_yd = base_unit<"volume", XIEITE_GFN(_0 / 1.3079506193), XIEITE_GFN(_0 * 1.3079506193)>;
	using cu_mi = base_unit<"volume", XIEITE_GFN(_0 / 4168181825.440579584), XIEITE_GFN(_0 * 4168181825.440579584)>;
	using qL = base_unit<"volume", XIEITE_GFN(_0 / 1e33), XIEITE_GFN(_0 * 1e33)>;
	using rL = base_unit<"volume", XIEITE_GFN(_0 / 1e30), XIEITE_GFN(_0 * 1e30)>;
	using yL = xieite::unit::nV;
	using zL = base_unit<"volume", XIEITE_GFN(_0 / 1e24), XIEITE_GFN(_0 * 1e24)>;
	using aL = base_unit<"volume", XIEITE_GFN(_0 / 1e21), XIEITE_GFN(_0 * 1e21)>;
	using fL = xieite::unit::uV;
	using pL = base_unit<"volume", XIEITE_GFN(_0 / 1e15), XIEITE_GFN(_0 * 1e15)>;
	using nL = base_unit<"volume", XIEITE_GFN(_0 / 1e12), XIEITE_GFN(_0 * 1e12)>;
	using uL = xieite::unit::mV;
	using mL = xieite::unit::cV;
	using cL = base_unit<"volume", XIEITE_GFN(_0 / 1e5), XIEITE_GFN(_0 * 1e5)>;
	using dL = base_unit<"volume", XIEITE_GFN(_0 / 1e4), XIEITE_GFN(_0 * 1e4)>;
	using L = xieite::unit::dV;
	using daL = base_unit<"volume", XIEITE_GFN(_0 / 1e2), XIEITE_GFN(_0 * 1e2)>;
	using hL = base_unit<"volume", XIEITE_GFN(_0 / 1e1), XIEITE_GFN(_0 * 1e1)>;
	using kL = xieite::unit::V;
	using ML = xieite::unit::daV;
	using GL = xieite::unit::hV;
	using TL = xieite::unit::kV;
	using PL = base_unit<"volume", XIEITE_GFN(_0 * 1e12), XIEITE_GFN(_0 / 1e12)>;
	using EL = base_unit<"volume", XIEITE_GFN(_0 * 1e15), XIEITE_GFN(_0 / 1e15)>;
	using ZL = xieite::unit::MV;
	using YL = base_unit<"volume", XIEITE_GFN(_0 * 1e21), XIEITE_GFN(_0 / 1e21)>;
	using RL = base_unit<"volume", XIEITE_GFN(_0 * 1e24), XIEITE_GFN(_0 / 1e24)>;
	using QL = xieite::unit::GV;
	using fl_oz = base_unit<"volume", XIEITE_GFN(_0 / 33814.022702), XIEITE_GFN(_0 * 33814.022702)>;
	using gills = base_unit<"volume", XIEITE_GFN(_0 / 7039.0159455708), XIEITE_GFN(_0 * 7039.0159455708)>;
	using cups = base_unit<"volume", XIEITE_GFN(_0 / 3519.5079727854), XIEITE_GFN(_0 * 3519.5079727854)>;
	using pt = base_unit<"volume", XIEITE_GFN(_0 / 1759.7539863927), XIEITE_GFN(_0 * 1759.7539863927)>;
	using qt = base_unit<"volume", XIEITE_GFN(_0 / 879.87699319635), XIEITE_GFN(_0 * 879.87699319635)>;
	using gal = base_unit<"volume", XIEITE_GFN(_0 / 219.9691574), XIEITE_GFN(_0 * 219.9691574)>;

	// Angles
	using rad = base_unit<"angle">;
	using deg = base_unit<"angle", XIEITE_GFN(_0 * xieite::pi<double> / 180.0), XIEITE_GFN(_0 * 180.0 / xieite::pi<double>)>;

	// Temperature scales
	using K = base_unit<"temperature">;
	using C = base_unit<"temperature", XIEITE_GFN(_0 - 273.15), XIEITE_GFN(_0 + 273.15)>;
	using F = base_unit<"temperature", XIEITE_GFN((_0 - 32.0) / 1.8 + 273.15), XIEITE_GFN((_0 - 273.15) * 1.8 + 32.0)>;
	using R = base_unit<"temperature", XIEITE_GFN(_0 / 1.8), XIEITE_GFN(_0 * 1.8)>;

	// Durations
	using decades = std::chrono::duration<std::intmax_t, std::ratio<315569520>>;
	using centuries = std::chrono::duration<std::intmax_t, std::ratio<3155695200>>;
	using millenniums = std::chrono::duration<std::intmax_t, std::ratio<31556952000>>;
	using epochs = std::chrono::duration<std::intmax_t, std::ratio<31556952000000>>;
	using eons = std::chrono::duration<std::intmax_t, std::ratio<31556952000000000>>;
}
