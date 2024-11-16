module;

#include <xieite/fn.hpp>

export module xieite:unit;

import std;
import :fixed_str;
import :pi;

namespace xieite {
	template<xieite::fixed_str type, auto to = [](auto x) { return x; }, auto from = [](auto x) { return x; }>
	struct base_unit {
		double value;

		template<auto other_to, auto other_from>
		[[nodiscard]] explicit(false) constexpr operator xieite::base_unit<type, other_to, other_from>() const noexcept {
			return xieite::base_unit<type, other_to, other_from>(other_from(to(this->value)));
		}
	};
}

namespace xieite::unit {
	// Lengths
	using qm = xieite::base_unit<"length", XIEITE_FN($0 / 1e30), XIEITE_FN($0 * 1e30)>;
	using rm = xieite::base_unit<"length", XIEITE_FN($0 / 1e27), XIEITE_FN($0 * 1e27)>;
	using ym = xieite::base_unit<"length", XIEITE_FN($0 / 1e24), XIEITE_FN($0 * 1e24)>;
	using zm = xieite::base_unit<"length", XIEITE_FN($0 / 1e21), XIEITE_FN($0 * 1e21)>;
	using am = xieite::base_unit<"length", XIEITE_FN($0 / 1e18), XIEITE_FN($0 * 1e18)>;
	using fm = xieite::base_unit<"length", XIEITE_FN($0 / 1e15), XIEITE_FN($0 * 1e15)>;
	using pm = xieite::base_unit<"length", XIEITE_FN($0 / 1e12), XIEITE_FN($0 * 1e12)>;
	using nm = xieite::base_unit<"length", XIEITE_FN($0 / 1e9), XIEITE_FN($0 * 1e9)>;
	using um = xieite::base_unit<"length", XIEITE_FN($0 / 1e6), XIEITE_FN($0 * 1e6)>;
	using mm = xieite::base_unit<"length", XIEITE_FN($0 / 1e3), XIEITE_FN($0 * 1e3)>;
	using cm = xieite::base_unit<"length", XIEITE_FN($0 / 1e2), XIEITE_FN($0 * 1e2)>;
	using dm = xieite::base_unit<"length", XIEITE_FN($0 / 1e1), XIEITE_FN($0 * 1e1)>;
	using m = xieite::base_unit<"length">;
	using dam = xieite::base_unit<"length", XIEITE_FN($0 * 1e1), XIEITE_FN($0 / 1e1)>;
	using hm = xieite::base_unit<"length", XIEITE_FN($0 * 1e2), XIEITE_FN($0 / 1e2)>;
	using km = xieite::base_unit<"length", XIEITE_FN($0 * 1e3), XIEITE_FN($0 / 1e3)>;
	using Mm = xieite::base_unit<"length", XIEITE_FN($0 * 1e6), XIEITE_FN($0 / 1e6)>;
	using Gm = xieite::base_unit<"length", XIEITE_FN($0 * 1e9), XIEITE_FN($0 / 1e9)>;
	using Tm = xieite::base_unit<"length", XIEITE_FN($0 * 1e12), XIEITE_FN($0 / 1e12)>;
	using Pm = xieite::base_unit<"length", XIEITE_FN($0 * 1e15), XIEITE_FN($0 / 1e15)>;
	using Em = xieite::base_unit<"length", XIEITE_FN($0 * 1e18), XIEITE_FN($0 / 1e18)>;
	using Zm = xieite::base_unit<"length", XIEITE_FN($0 * 1e21), XIEITE_FN($0 / 1e21)>;
	using Ym = xieite::base_unit<"length", XIEITE_FN($0 * 1e24), XIEITE_FN($0 / 1e24)>;
	using Rm = xieite::base_unit<"length", XIEITE_FN($0 * 1e27), XIEITE_FN($0 / 1e27)>;
	using Qm = xieite::base_unit<"length", XIEITE_FN($0 * 1e30), XIEITE_FN($0 / 1e30)>;
	using twips = xieite::base_unit<"length", XIEITE_FN($0 * 0.0254 / 1440.0), XIEITE_FN($0 * 1440.0 / 0.0254)>;
	using thous = xieite::base_unit<"length", XIEITE_FN($0 * 0.0000254), XIEITE_FN($0 / 0.0000254)>;
	using barleycorns = xieite::base_unit<"length", XIEITE_FN($0 * 0.0254 / 3.0), XIEITE_FN($0 * 3.0 / 0.0254)>;
	using in = xieite::base_unit<"length", XIEITE_FN($0 * 0.0254), XIEITE_FN($0 / 0.0254)>;
	using ft = xieite::base_unit<"length", XIEITE_FN($0 / 0.3048), XIEITE_FN($0 * 0.3048)>;
	using yd = xieite::base_unit<"length", XIEITE_FN($0 * 0.9144), XIEITE_FN($0 / 0.9144)>;
	using chains = xieite::base_unit<"length", XIEITE_FN($0 * 20.1168), XIEITE_FN($0 / 20.1168)>;
	using furlongs = xieite::base_unit<"length", XIEITE_FN($0 * 201.168), XIEITE_FN($0 / 201.168)>;
	using mi = xieite::base_unit<"length", XIEITE_FN($0 * 1609.344), XIEITE_FN($0 / 1609.344)>;
	using leagues = xieite::base_unit<"length", XIEITE_FN($0 * 4828.032), XIEITE_FN($0 / 4828.032)>;
	using fathoms = xieite::base_unit<"length", XIEITE_FN($0 * 1.8288), XIEITE_FN($0 / 1.8288)>;
	using cables = xieite::base_unit<"length", XIEITE_FN($0 * 185.2), XIEITE_FN($0 / 185.2)>;
	using nmi = xieite::base_unit<"length", XIEITE_FN($0 * 1852.0), XIEITE_FN($0 / 1852.0)>;
	using nau_leagues = xieite::base_unit<"length", XIEITE_FN($0 * 5556.0), XIEITE_FN($0 / 5556.0)>;
	using links = xieite::base_unit<"length", XIEITE_FN($0 * 0.201168), XIEITE_FN($0 / 0.201168)>;
	using rods = xieite::base_unit<"length", XIEITE_FN($0 * 5.0292), XIEITE_FN($0 / 5.0292)>;
	using perches = xieite::unit::rods;
	using poles = xieite::unit::rods;
	using lugs = xieite::unit::rods;

	// Areas
	using qA = xieite::base_unit<"area", XIEITE_FN($0 / 1e60), XIEITE_FN($0 * 1e60)>;
	using rA = xieite::base_unit<"area", XIEITE_FN($0 / 1e54), XIEITE_FN($0 * 1e54)>;
	using yA = xieite::base_unit<"area", XIEITE_FN($0 / 1e48), XIEITE_FN($0 * 1e48)>;
	using zA = xieite::base_unit<"area", XIEITE_FN($0 / 1e42), XIEITE_FN($0 * 1e42)>;
	using aA = xieite::base_unit<"area", XIEITE_FN($0 / 1e36), XIEITE_FN($0 * 1e36)>;
	using fA = xieite::base_unit<"area", XIEITE_FN($0 / 1e30), XIEITE_FN($0 * 1e30)>;
	using pA = xieite::base_unit<"area", XIEITE_FN($0 / 1e24), XIEITE_FN($0 * 1e24)>;
	using nA = xieite::base_unit<"area", XIEITE_FN($0 / 1e18), XIEITE_FN($0 * 1e18)>;
	using uA = xieite::base_unit<"area", XIEITE_FN($0 / 1e12), XIEITE_FN($0 * 1e12)>;
	using mA = xieite::base_unit<"area", XIEITE_FN($0 / 1e6), XIEITE_FN($0 * 1e6)>;
	using cA = xieite::base_unit<"area", XIEITE_FN($0 / 1e4), XIEITE_FN($0 * 1e4)>;
	using dA = xieite::base_unit<"area", XIEITE_FN($0 / 1e2), XIEITE_FN($0 * 1e2)>;
	using A = xieite::base_unit<"area">;
	using daA = xieite::base_unit<"area", XIEITE_FN($0 * 1e2), XIEITE_FN($0 / 1e2)>;
	using hA = xieite::base_unit<"area", XIEITE_FN($0 * 1e4), XIEITE_FN($0 / 1e4)>;
	using kA = xieite::base_unit<"area", XIEITE_FN($0 * 1e6), XIEITE_FN($0 / 1e6)>;
	using MA = xieite::base_unit<"area", XIEITE_FN($0 * 1e12), XIEITE_FN($0 / 1e12)>;
	using GA = xieite::base_unit<"area", XIEITE_FN($0 * 1e18), XIEITE_FN($0 / 1e18)>;
	using TA = xieite::base_unit<"area", XIEITE_FN($0 * 1e24), XIEITE_FN($0 / 1e24)>;
	using PA = xieite::base_unit<"area", XIEITE_FN($0 * 1e30), XIEITE_FN($0 / 1e30)>;
	using EA = xieite::base_unit<"area", XIEITE_FN($0 * 1e36), XIEITE_FN($0 / 1e36)>;
	using ZA = xieite::base_unit<"area", XIEITE_FN($0 * 1e42), XIEITE_FN($0 / 1e42)>;
	using YA = xieite::base_unit<"area", XIEITE_FN($0 * 1e48), XIEITE_FN($0 / 1e48)>;
	using RA = xieite::base_unit<"area", XIEITE_FN($0 * 1e54), XIEITE_FN($0 / 1e54)>;
	using QA = xieite::base_unit<"area", XIEITE_FN($0 * 1e60), XIEITE_FN($0 / 1e60)>;
	using sq_in = xieite::base_unit<"area", XIEITE_FN($0 / 1550.0031), XIEITE_FN($0 * 1550.0031)>;
	using sq_ft = xieite::base_unit<"area", XIEITE_FN($0 / 10.7639104), XIEITE_FN($0 * 10.7639104)>;
	using sq_yd = xieite::base_unit<"area", XIEITE_FN($0 * 0.83612736), XIEITE_FN($0 / 0.83612736)>;
	using sq_mi = xieite::base_unit<"area", XIEITE_FN($0 * 2589988.110336), XIEITE_FN($0 / 2589988.110336)>;
	using sq_roods = xieite::base_unit<"area", XIEITE_FN($0 * 1011.7141056), XIEITE_FN($0 / 1011.7141056)>;
	using ac = xieite::base_unit<"area", XIEITE_FN($0 * 4046.8564224), XIEITE_FN($0 / 4046.8564224)>;
	using dma = xieite::unit::dA;
	using ca = xieite::unit::A;
	using da = xieite::base_unit<"area", XIEITE_FN($0 * 1e1), XIEITE_FN($0 / 1e1)>;
	using a = xieite::unit::daA;
	using daa = xieite::base_unit<"area", XIEITE_FN($0 * 1e3), XIEITE_FN($0 / 1e3)>;
	using ha = xieite::unit::hA;

	// Volumes
	using qV = xieite::base_unit<"volume", XIEITE_FN($0 / 1e90), XIEITE_FN($0 * 1e90)>;
	using rV = xieite::base_unit<"volume", XIEITE_FN($0 / 1e81), XIEITE_FN($0 * 1e81)>;
	using yV = xieite::base_unit<"volume", XIEITE_FN($0 / 1e72), XIEITE_FN($0 * 1e72)>;
	using zV = xieite::base_unit<"volume", XIEITE_FN($0 / 1e63), XIEITE_FN($0 * 1e63)>;
	using aV = xieite::base_unit<"volume", XIEITE_FN($0 / 1e54), XIEITE_FN($0 * 1e54)>;
	using fV = xieite::base_unit<"volume", XIEITE_FN($0 / 1e45), XIEITE_FN($0 * 1e45)>;
	using pV = xieite::base_unit<"volume", XIEITE_FN($0 / 1e36), XIEITE_FN($0 * 1e36)>;
	using nV = xieite::base_unit<"volume", XIEITE_FN($0 / 1e27), XIEITE_FN($0 * 1e27)>;
	using uV = xieite::base_unit<"volume", XIEITE_FN($0 / 1e18), XIEITE_FN($0 * 1e18)>;
	using mV = xieite::base_unit<"volume", XIEITE_FN($0 / 1e9), XIEITE_FN($0 * 1e9)>;
	using cV = xieite::base_unit<"volume", XIEITE_FN($0 / 1e6), XIEITE_FN($0 * 1e6)>;
	using dV = xieite::base_unit<"volume", XIEITE_FN($0 / 1e3), XIEITE_FN($0 * 1e3)>;
	using V = xieite::base_unit<"volume">;
	using daV = xieite::base_unit<"volume", XIEITE_FN($0 * 1e3), XIEITE_FN($0 / 1e3)>;
	using hV = xieite::base_unit<"volume", XIEITE_FN($0 * 1e6), XIEITE_FN($0 / 1e6)>;
	using kV = xieite::base_unit<"volume", XIEITE_FN($0 * 1e9), XIEITE_FN($0 / 1e9)>;
	using MV = xieite::base_unit<"volume", XIEITE_FN($0 * 1e18), XIEITE_FN($0 / 1e18)>;
	using GV = xieite::base_unit<"volume", XIEITE_FN($0 * 1e27), XIEITE_FN($0 / 1e27)>;
	using TV = xieite::base_unit<"volume", XIEITE_FN($0 * 1e36), XIEITE_FN($0 / 1e36)>;
	using PV = xieite::base_unit<"volume", XIEITE_FN($0 * 1e45), XIEITE_FN($0 / 1e45)>;
	using EV = xieite::base_unit<"volume", XIEITE_FN($0 * 1e54), XIEITE_FN($0 / 1e54)>;
	using ZV = xieite::base_unit<"volume", XIEITE_FN($0 * 1e63), XIEITE_FN($0 / 1e63)>;
	using YV = xieite::base_unit<"volume", XIEITE_FN($0 * 1e72), XIEITE_FN($0 / 1e72)>;
	using RV = xieite::base_unit<"volume", XIEITE_FN($0 * 1e81), XIEITE_FN($0 / 1e81)>;
	using QV = xieite::base_unit<"volume", XIEITE_FN($0 * 1e90), XIEITE_FN($0 / 1e90)>;
	using cu_in = xieite::base_unit<"volume", XIEITE_FN($0 / 61023.744095), XIEITE_FN($0 * 61023.744095)>;
	using cu_ft = xieite::base_unit<"volume", XIEITE_FN($0 / 35.314666721), XIEITE_FN($0 * 35.314666721)>;
	using cu_yd = xieite::base_unit<"volume", XIEITE_FN($0 / 1.3079506193), XIEITE_FN($0 * 1.3079506193)>;
	using cu_mi = xieite::base_unit<"volume", XIEITE_FN($0 / 4168181825.440579584), XIEITE_FN($0 * 4168181825.440579584)>;
	using qL = xieite::base_unit<"volume", XIEITE_FN($0 / 1e33), XIEITE_FN($0 * 1e33)>;
	using rL = xieite::base_unit<"volume", XIEITE_FN($0 / 1e30), XIEITE_FN($0 * 1e30)>;
	using yL = xieite::unit::nV;
	using zL = xieite::base_unit<"volume", XIEITE_FN($0 / 1e24), XIEITE_FN($0 * 1e24)>;
	using aL = xieite::base_unit<"volume", XIEITE_FN($0 / 1e21), XIEITE_FN($0 * 1e21)>;
	using fL = xieite::unit::uV;
	using pL = xieite::base_unit<"volume", XIEITE_FN($0 / 1e15), XIEITE_FN($0 * 1e15)>;
	using nL = xieite::base_unit<"volume", XIEITE_FN($0 / 1e12), XIEITE_FN($0 * 1e12)>;
	using uL = xieite::unit::mV;
	using mL = xieite::unit::cV;
	using cL = xieite::base_unit<"volume", XIEITE_FN($0 / 1e5), XIEITE_FN($0 * 1e5)>;
	using dL = xieite::base_unit<"volume", XIEITE_FN($0 / 1e4), XIEITE_FN($0 * 1e4)>;
	using L = xieite::unit::dV;
	using daL = xieite::base_unit<"volume", XIEITE_FN($0 / 1e2), XIEITE_FN($0 * 1e2)>;
	using hL = xieite::base_unit<"volume", XIEITE_FN($0 / 1e1), XIEITE_FN($0 * 1e1)>;
	using kL = xieite::unit::V;
	using ML = xieite::unit::daV;
	using GL = xieite::unit::hV;
	using TL = xieite::unit::kV;
	using PL = xieite::base_unit<"volume", XIEITE_FN($0 * 1e12), XIEITE_FN($0 / 1e12)>;
	using EL = xieite::base_unit<"volume", XIEITE_FN($0 * 1e15), XIEITE_FN($0 / 1e15)>;
	using ZL = xieite::unit::MV;
	using YL = xieite::base_unit<"volume", XIEITE_FN($0 * 1e21), XIEITE_FN($0 / 1e21)>;
	using RL = xieite::base_unit<"volume", XIEITE_FN($0 * 1e24), XIEITE_FN($0 / 1e24)>;
	using QL = xieite::unit::GV;
	using fl_oz = xieite::base_unit<"volume", XIEITE_FN($0 / 33814.022702), XIEITE_FN($0 * 33814.022702)>;
	using gills = xieite::base_unit<"volume", XIEITE_FN($0 / 7039.0159455708), XIEITE_FN($0 * 7039.0159455708)>;
	using cups = xieite::base_unit<"volume", XIEITE_FN($0 / 3519.5079727854), XIEITE_FN($0 * 3519.5079727854)>;
	using pt = xieite::base_unit<"volume", XIEITE_FN($0 / 1759.7539863927), XIEITE_FN($0 * 1759.7539863927)>;
	using qt = xieite::base_unit<"volume", XIEITE_FN($0 / 879.87699319635), XIEITE_FN($0 * 879.87699319635)>;
	using gal = xieite::base_unit<"volume", XIEITE_FN($0 / 219.9691574), XIEITE_FN($0 * 219.9691574)>;

	// Angles
	using rad = xieite::base_unit<"angle">;
	using deg = xieite::base_unit<"angle", XIEITE_FN($0 * xieite::pi<double> / 180.0), XIEITE_FN($0 * 180.0 / xieite::pi<double>)>;

	// Temperature scales
	using K = xieite::base_unit<"temperature">;
	using C = xieite::base_unit<"temperature", XIEITE_FN($0 - 273.15), XIEITE_FN($0 + 273.15)>;
	using F = xieite::base_unit<"temperature", XIEITE_FN(($0 - 32.0) / 1.8 + 273.15), XIEITE_FN(($0 - 273.15) * 1.8 + 32.0)>;
	using R = xieite::base_unit<"temperature", XIEITE_FN($0 / 1.8), XIEITE_FN($0 * 1.8)>;

	// Durations
	using decades = std::chrono::duration<std::intmax_t, std::ratio<315569520>>;
	using centuries = std::chrono::duration<std::intmax_t, std::ratio<3155695200>>;
	using millenniums = std::chrono::duration<std::intmax_t, std::ratio<31556952000>>;
	using epochs = std::chrono::duration<std::intmax_t, std::ratio<31556952000000>>;
	using eons = std::chrono::duration<std::intmax_t, std::ratio<31556952000000000>>;
}
