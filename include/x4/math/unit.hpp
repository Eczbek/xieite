#pragma once

#include <chrono>
#include <cstdint>
#include <functional>
#include "../ctnr/fstr.hpp"
#include "../math/pi.hpp"
#include "../pp/fn.hpp"

namespace x4 {
	template<x4::fstr type, auto to = std::identity(), auto from = std::identity()>
	struct base_unit {
		double value;

		template<auto other_to, auto other_from>
		[[nodiscard]] explicit(false) constexpr operator x4::base_unit<type, other_to, other_from>() const noexcept {
			return x4::base_unit<type, other_to, other_from>(other_from(to(this->value)));
		}
	};
}

namespace x4::unit {
	using qm = x4::base_unit<"length", X4FN($0 / 1e30), X4FN($0 * 1e30)>;
	using rm = x4::base_unit<"length", X4FN($0 / 1e27), X4FN($0 * 1e27)>;
	using ym = x4::base_unit<"length", X4FN($0 / 1e24), X4FN($0 * 1e24)>;
	using zm = x4::base_unit<"length", X4FN($0 / 1e21), X4FN($0 * 1e21)>;
	using am = x4::base_unit<"length", X4FN($0 / 1e18), X4FN($0 * 1e18)>;
	using fm = x4::base_unit<"length", X4FN($0 / 1e15), X4FN($0 * 1e15)>;
	using pm = x4::base_unit<"length", X4FN($0 / 1e12), X4FN($0 * 1e12)>;
	using nm = x4::base_unit<"length", X4FN($0 / 1e9), X4FN($0 * 1e9)>;
	using um = x4::base_unit<"length", X4FN($0 / 1e6), X4FN($0 * 1e6)>;
	using mm = x4::base_unit<"length", X4FN($0 / 1e3), X4FN($0 * 1e3)>;
	using cm = x4::base_unit<"length", X4FN($0 / 1e2), X4FN($0 * 1e2)>;
	using dm = x4::base_unit<"length", X4FN($0 / 1e1), X4FN($0 * 1e1)>;
	using m = x4::base_unit<"length">;
	using dam = x4::base_unit<"length", X4FN($0 * 1e1), X4FN($0 / 1e1)>;
	using hm = x4::base_unit<"length", X4FN($0 * 1e2), X4FN($0 / 1e2)>;
	using km = x4::base_unit<"length", X4FN($0 * 1e3), X4FN($0 / 1e3)>;
	using Mm = x4::base_unit<"length", X4FN($0 * 1e6), X4FN($0 / 1e6)>;
	using Gm = x4::base_unit<"length", X4FN($0 * 1e9), X4FN($0 / 1e9)>;
	using Tm = x4::base_unit<"length", X4FN($0 * 1e12), X4FN($0 / 1e12)>;
	using Pm = x4::base_unit<"length", X4FN($0 * 1e15), X4FN($0 / 1e15)>;
	using Em = x4::base_unit<"length", X4FN($0 * 1e18), X4FN($0 / 1e18)>;
	using Zm = x4::base_unit<"length", X4FN($0 * 1e21), X4FN($0 / 1e21)>;
	using Ym = x4::base_unit<"length", X4FN($0 * 1e24), X4FN($0 / 1e24)>;
	using Rm = x4::base_unit<"length", X4FN($0 * 1e27), X4FN($0 / 1e27)>;
	using Qm = x4::base_unit<"length", X4FN($0 * 1e30), X4FN($0 / 1e30)>;
	using twips = x4::base_unit<"length", X4FN($0 * 0.0254 / 1440.0), X4FN($0 * 1440.0 / 0.0254)>;
	using thous = x4::base_unit<"length", X4FN($0 * 0.0000254), X4FN($0 / 0.0000254)>;
	using barleycorns = x4::base_unit<"length", X4FN($0 * 0.0254 / 3.0), X4FN($0 * 3.0 / 0.0254)>;
	using in = x4::base_unit<"length", X4FN($0 * 0.0254), X4FN($0 / 0.0254)>;
	using ft = x4::base_unit<"length", X4FN($0 / 0.3048), X4FN($0 * 0.3048)>;
	using yd = x4::base_unit<"length", X4FN($0 * 0.9144), X4FN($0 / 0.9144)>;
	using chains = x4::base_unit<"length", X4FN($0 * 20.1168), X4FN($0 / 20.1168)>;
	using furlongs = x4::base_unit<"length", X4FN($0 * 201.168), X4FN($0 / 201.168)>;
	using mi = x4::base_unit<"length", X4FN($0 * 1609.344), X4FN($0 / 1609.344)>;
	using leagues = x4::base_unit<"length", X4FN($0 * 4828.032), X4FN($0 / 4828.032)>;
	using fathoms = x4::base_unit<"length", X4FN($0 * 1.8288), X4FN($0 / 1.8288)>;
	using cables = x4::base_unit<"length", X4FN($0 * 185.2), X4FN($0 / 185.2)>;
	using nmi = x4::base_unit<"length", X4FN($0 * 1852.0), X4FN($0 / 1852.0)>;
	using nau_leagues = x4::base_unit<"length", X4FN($0 * 5556.0), X4FN($0 / 5556.0)>;
	using links = x4::base_unit<"length", X4FN($0 * 0.201168), X4FN($0 / 0.201168)>;
	using rods = x4::base_unit<"length", X4FN($0 * 5.0292), X4FN($0 / 5.0292)>;
	using perches = x4::unit::rods;
	using poles = x4::unit::rods;
	using lugs = x4::unit::rods;
	using qA = x4::base_unit<"area", X4FN($0 / 1e60), X4FN($0 * 1e60)>;
	using rA = x4::base_unit<"area", X4FN($0 / 1e54), X4FN($0 * 1e54)>;
	using yA = x4::base_unit<"area", X4FN($0 / 1e48), X4FN($0 * 1e48)>;
	using zA = x4::base_unit<"area", X4FN($0 / 1e42), X4FN($0 * 1e42)>;
	using aA = x4::base_unit<"area", X4FN($0 / 1e36), X4FN($0 * 1e36)>;
	using fA = x4::base_unit<"area", X4FN($0 / 1e30), X4FN($0 * 1e30)>;
	using pA = x4::base_unit<"area", X4FN($0 / 1e24), X4FN($0 * 1e24)>;
	using nA = x4::base_unit<"area", X4FN($0 / 1e18), X4FN($0 * 1e18)>;
	using uA = x4::base_unit<"area", X4FN($0 / 1e12), X4FN($0 * 1e12)>;
	using mA = x4::base_unit<"area", X4FN($0 / 1e6), X4FN($0 * 1e6)>;
	using cA = x4::base_unit<"area", X4FN($0 / 1e4), X4FN($0 * 1e4)>;
	using dA = x4::base_unit<"area", X4FN($0 / 1e2), X4FN($0 * 1e2)>;
	using A = x4::base_unit<"area">;
	using daA = x4::base_unit<"area", X4FN($0 * 1e2), X4FN($0 / 1e2)>;
	using hA = x4::base_unit<"area", X4FN($0 * 1e4), X4FN($0 / 1e4)>;
	using kA = x4::base_unit<"area", X4FN($0 * 1e6), X4FN($0 / 1e6)>;
	using MA = x4::base_unit<"area", X4FN($0 * 1e12), X4FN($0 / 1e12)>;
	using GA = x4::base_unit<"area", X4FN($0 * 1e18), X4FN($0 / 1e18)>;
	using TA = x4::base_unit<"area", X4FN($0 * 1e24), X4FN($0 / 1e24)>;
	using PA = x4::base_unit<"area", X4FN($0 * 1e30), X4FN($0 / 1e30)>;
	using EA = x4::base_unit<"area", X4FN($0 * 1e36), X4FN($0 / 1e36)>;
	using ZA = x4::base_unit<"area", X4FN($0 * 1e42), X4FN($0 / 1e42)>;
	using YA = x4::base_unit<"area", X4FN($0 * 1e48), X4FN($0 / 1e48)>;
	using RA = x4::base_unit<"area", X4FN($0 * 1e54), X4FN($0 / 1e54)>;
	using QA = x4::base_unit<"area", X4FN($0 * 1e60), X4FN($0 / 1e60)>;
	using sq_in = x4::base_unit<"area", X4FN($0 / 1550.0031), X4FN($0 * 1550.0031)>;
	using sq_ft = x4::base_unit<"area", X4FN($0 / 10.7639104), X4FN($0 * 10.7639104)>;
	using sq_yd = x4::base_unit<"area", X4FN($0 * 0.83612736), X4FN($0 / 0.83612736)>;
	using sq_mi = x4::base_unit<"area", X4FN($0 * 2589988.110336), X4FN($0 / 2589988.110336)>;
	using sq_roods = x4::base_unit<"area", X4FN($0 * 1011.7141056), X4FN($0 / 1011.7141056)>;
	using ac = x4::base_unit<"area", X4FN($0 * 4046.8564224), X4FN($0 / 4046.8564224)>;
	using dma = x4::unit::dA;
	using ca = x4::unit::A;
	using da = x4::base_unit<"area", X4FN($0 * 1e1), X4FN($0 / 1e1)>;
	using a = x4::unit::daA;
	using daa = x4::base_unit<"area", X4FN($0 * 1e3), X4FN($0 / 1e3)>;
	using ha = x4::unit::hA;
	using qV = x4::base_unit<"volume", X4FN($0 / 1e90), X4FN($0 * 1e90)>;
	using rV = x4::base_unit<"volume", X4FN($0 / 1e81), X4FN($0 * 1e81)>;
	using yV = x4::base_unit<"volume", X4FN($0 / 1e72), X4FN($0 * 1e72)>;
	using zV = x4::base_unit<"volume", X4FN($0 / 1e63), X4FN($0 * 1e63)>;
	using aV = x4::base_unit<"volume", X4FN($0 / 1e54), X4FN($0 * 1e54)>;
	using fV = x4::base_unit<"volume", X4FN($0 / 1e45), X4FN($0 * 1e45)>;
	using pV = x4::base_unit<"volume", X4FN($0 / 1e36), X4FN($0 * 1e36)>;
	using nV = x4::base_unit<"volume", X4FN($0 / 1e27), X4FN($0 * 1e27)>;
	using uV = x4::base_unit<"volume", X4FN($0 / 1e18), X4FN($0 * 1e18)>;
	using mV = x4::base_unit<"volume", X4FN($0 / 1e9), X4FN($0 * 1e9)>;
	using cV = x4::base_unit<"volume", X4FN($0 / 1e6), X4FN($0 * 1e6)>;
	using dV = x4::base_unit<"volume", X4FN($0 / 1e3), X4FN($0 * 1e3)>;
	using V = x4::base_unit<"volume">;
	using daV = x4::base_unit<"volume", X4FN($0 * 1e3), X4FN($0 / 1e3)>;
	using hV = x4::base_unit<"volume", X4FN($0 * 1e6), X4FN($0 / 1e6)>;
	using kV = x4::base_unit<"volume", X4FN($0 * 1e9), X4FN($0 / 1e9)>;
	using MV = x4::base_unit<"volume", X4FN($0 * 1e18), X4FN($0 / 1e18)>;
	using GV = x4::base_unit<"volume", X4FN($0 * 1e27), X4FN($0 / 1e27)>;
	using TV = x4::base_unit<"volume", X4FN($0 * 1e36), X4FN($0 / 1e36)>;
	using PV = x4::base_unit<"volume", X4FN($0 * 1e45), X4FN($0 / 1e45)>;
	using EV = x4::base_unit<"volume", X4FN($0 * 1e54), X4FN($0 / 1e54)>;
	using ZV = x4::base_unit<"volume", X4FN($0 * 1e63), X4FN($0 / 1e63)>;
	using YV = x4::base_unit<"volume", X4FN($0 * 1e72), X4FN($0 / 1e72)>;
	using RV = x4::base_unit<"volume", X4FN($0 * 1e81), X4FN($0 / 1e81)>;
	using QV = x4::base_unit<"volume", X4FN($0 * 1e90), X4FN($0 / 1e90)>;
	using cu_in = x4::base_unit<"volume", X4FN($0 / 61023.744095), X4FN($0 * 61023.744095)>;
	using cu_ft = x4::base_unit<"volume", X4FN($0 / 35.314666721), X4FN($0 * 35.314666721)>;
	using cu_yd = x4::base_unit<"volume", X4FN($0 / 1.3079506193), X4FN($0 * 1.3079506193)>;
	using cu_mi = x4::base_unit<"volume", X4FN($0 / 4168181825.440579584), X4FN($0 * 4168181825.440579584)>;
	using qL = x4::base_unit<"volume", X4FN($0 / 1e33), X4FN($0 * 1e33)>;
	using rL = x4::base_unit<"volume", X4FN($0 / 1e30), X4FN($0 * 1e30)>;
	using yL = x4::unit::nV;
	using zL = x4::base_unit<"volume", X4FN($0 / 1e24), X4FN($0 * 1e24)>;
	using aL = x4::base_unit<"volume", X4FN($0 / 1e21), X4FN($0 * 1e21)>;
	using fL = x4::unit::uV;
	using pL = x4::base_unit<"volume", X4FN($0 / 1e15), X4FN($0 * 1e15)>;
	using nL = x4::base_unit<"volume", X4FN($0 / 1e12), X4FN($0 * 1e12)>;
	using uL = x4::unit::mV;
	using mL = x4::unit::cV;
	using cL = x4::base_unit<"volume", X4FN($0 / 1e5), X4FN($0 * 1e5)>;
	using dL = x4::base_unit<"volume", X4FN($0 / 1e4), X4FN($0 * 1e4)>;
	using L = x4::unit::dV;
	using daL = x4::base_unit<"volume", X4FN($0 / 1e2), X4FN($0 * 1e2)>;
	using hL = x4::base_unit<"volume", X4FN($0 / 1e1), X4FN($0 * 1e1)>;
	using kL = x4::unit::V;
	using ML = x4::unit::daV;
	using GL = x4::unit::hV;
	using TL = x4::unit::kV;
	using PL = x4::base_unit<"volume", X4FN($0 * 1e12), X4FN($0 / 1e12)>;
	using EL = x4::base_unit<"volume", X4FN($0 * 1e15), X4FN($0 / 1e15)>;
	using ZL = x4::unit::MV;
	using YL = x4::base_unit<"volume", X4FN($0 * 1e21), X4FN($0 / 1e21)>;
	using RL = x4::base_unit<"volume", X4FN($0 * 1e24), X4FN($0 / 1e24)>;
	using QL = x4::unit::GV;
	using fl_oz = x4::base_unit<"volume", X4FN($0 / 33814.022702), X4FN($0 * 33814.022702)>;
	using gills = x4::base_unit<"volume", X4FN($0 / 7039.0159455708), X4FN($0 * 7039.0159455708)>;
	using cups = x4::base_unit<"volume", X4FN($0 / 3519.5079727854), X4FN($0 * 3519.5079727854)>;
	using pt = x4::base_unit<"volume", X4FN($0 / 1759.7539863927), X4FN($0 * 1759.7539863927)>;
	using qt = x4::base_unit<"volume", X4FN($0 / 879.87699319635), X4FN($0 * 879.87699319635)>;
	using gal = x4::base_unit<"volume", X4FN($0 / 219.9691574), X4FN($0 * 219.9691574)>;
	using rad = x4::base_unit<"angle">;
	using deg = x4::base_unit<"angle", X4FN($0 * x4::pi<double> / 180.0), X4FN($0 * 180.0 / x4::pi<double>)>;
	using K = x4::base_unit<"temperature">;
	using C = x4::base_unit<"temperature", X4FN($0 - 273.15), X4FN($0 + 273.15)>;
	using F = x4::base_unit<"temperature", X4FN(($0 - 32.0) / 1.8 + 273.15), X4FN(($0 - 273.15) * 1.8 + 32.0)>;
	using R = x4::base_unit<"temperature", X4FN($0 / 1.8), X4FN($0 * 1.8)>;
	using decades = std::chrono::duration<std::intmax_t, std::ratio<315569520>>;
	using centuries = std::chrono::duration<std::intmax_t, std::ratio<3155695200>>;
	using millenniums = std::chrono::duration<std::intmax_t, std::ratio<31556952000>>;
	using epochs = std::chrono::duration<std::intmax_t, std::ratio<31556952000000>>;
	using eons = std::chrono::duration<std::intmax_t, std::ratio<31556952000000000>>;
}
