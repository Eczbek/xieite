export module xieite:units.area;

import :units.Unit;

export namespace xieite::units {
	using SquareQuectometre = xieite::units::Unit<"area", [](auto x) { return x / 1e60; }, [](auto x) { return x * 1e60; }>;
	using SquareRontometre = xieite::units::Unit<"area", [](auto x) { return x / 1e54; }, [](auto x) { return x * 1e54; }>;
	using SquareYoctometre = xieite::units::Unit<"area", [](auto x) { return x / 1e48; }, [](auto x) { return x * 1e48; }>;
	using SquareZeptometre = xieite::units::Unit<"area", [](auto x) { return x / 1e42; }, [](auto x) { return x * 1e42; }>;
	using SquareAttometre = xieite::units::Unit<"area", [](auto x) { return x / 1e36; }, [](auto x) { return x * 1e36; }>;
	using SquareFemtometre = xieite::units::Unit<"area", [](auto x) { return x / 1e30; }, [](auto x) { return x * 1e30; }>;
	using SquarePicometre = xieite::units::Unit<"area", [](auto x) { return x / 1e24; }, [](auto x) { return x * 1e24; }>;
	using SquareNanometre = xieite::units::Unit<"area", [](auto x) { return x / 1e18; }, [](auto x) { return x * 1e18; }>;
	using SquareMicrometre = xieite::units::Unit<"area", [](auto x) { return x / 1e12; }, [](auto x) { return x * 1e12; }>;
	using SquareMillimetre = xieite::units::Unit<"area", [](auto x) { return x / 1e6; }, [](auto x) { return x * 1e6; }>;
	using SquareCentimetre = xieite::units::Unit<"area", [](auto x) { return x / 1e4; }, [](auto x) { return x * 1e4; }>;
	using SquareDecimetre = xieite::units::Unit<"area", [](auto x) { return x / 1e2; }, [](auto x) { return x * 1e2; }>;
	using SquareMetre = xieite::units::Unit<"area">;
	using SquareDecametre = xieite::units::Unit<"area", [](auto x) { return x * 1e2; }, [](auto x) { return x / 1e2; }>;
	using SquareHectometre = xieite::units::Unit<"area", [](auto x) { return x * 1e4; }, [](auto x) { return x / 1e4; }>;
	using SquareKilometre = xieite::units::Unit<"area", [](auto x) { return x * 1e6; }, [](auto x) { return x / 1e6; }>;
	using SquareMegametre = xieite::units::Unit<"area", [](auto x) { return x * 1e12; }, [](auto x) { return x / 1e12; }>;
	using SquareGigametre = xieite::units::Unit<"area", [](auto x) { return x * 1e18; }, [](auto x) { return x / 1e18; }>;
	using SquareTerametre = xieite::units::Unit<"area", [](auto x) { return x * 1e24; }, [](auto x) { return x / 1e24; }>;
	using SquarePetametre = xieite::units::Unit<"area", [](auto x) { return x * 1e30; }, [](auto x) { return x / 1e30; }>;
	using SquareExametre = xieite::units::Unit<"area", [](auto x) { return x * 1e36; }, [](auto x) { return x / 1e36; }>;
	using SquareZettametre = xieite::units::Unit<"area", [](auto x) { return x * 1e42; }, [](auto x) { return x / 1e42; }>;
	using SquareYottametre = xieite::units::Unit<"area", [](auto x) { return x * 1e48; }, [](auto x) { return x / 1e48; }>;
	using SquareRonnametre = xieite::units::Unit<"area", [](auto x) { return x * 1e54; }, [](auto x) { return x / 1e54; }>;
	using SquareQuettametre = xieite::units::Unit<"area", [](auto x) { return x * 1e60; }, [](auto x) { return x / 1e60; }>;
	using SquareInch = xieite::units::Unit<"area", [](auto x) { return x / 1550.0031; }, [](auto x) { return x * 1550.0031; }>;
	using SquareFoot = xieite::units::Unit<"area", [](auto x) { return x / 10.7639104; }, [](auto x) { return x * 10.7639104; }>;
	using SquareYard = xieite::units::Unit<"area", [](auto x) { return x * 0.83612736; }, [](auto x) { return x / 0.83612736; }>;
	using SquareMile = xieite::units::Unit<"area", [](auto x) { return x * 2589988.110336; }, [](auto x) { return x / 2589988.110336; }>;
	using SquareRood = xieite::units::Unit<"area", [](auto x) { return x * 1011.7141056; }, [](auto x) { return x / 1011.7141056; }>;
	using Acre = xieite::units::Unit<"area", [](auto x) { return x * 4046.8564224; }, [](auto x) { return x / 4046.8564224; }>;
	using Decare = xieite::units::Unit<"area", [](auto x) { return x * 1e3; }, [](auto x) { return x / 1e3; }>;
	using Decimilliare = xieite::units::SquareDecimetre;
	using Centiare = xieite::units::SquareMetre;
	using Deciare = xieite::units::Unit<"area", [](auto x) { return x * 1e1; }, [](auto x) { return x / 1e1; }>;
	using Are = xieite::units::SquareDecametre;
	using Hectare = xieite::units::SquareHectometre;
}
