export module xieite:units.area;

import :units.Unit;

export namespace xieite::units {
	using SquareQuectometer = xieite::units::Unit<"area", [](auto x) { return x / 1e60; }, [](auto x) { return x * 1e60; }>;
	using SquareRontometer = xieite::units::Unit<"area", [](auto x) { return x / 1e54; }, [](auto x) { return x * 1e54; }>;
	using SquareYoctometer = xieite::units::Unit<"area", [](auto x) { return x / 1e48; }, [](auto x) { return x * 1e48; }>;
	using SquareZeptometer = xieite::units::Unit<"area", [](auto x) { return x / 1e42; }, [](auto x) { return x * 1e42; }>;
	using SquareAttometer = xieite::units::Unit<"area", [](auto x) { return x / 1e36; }, [](auto x) { return x * 1e36; }>;
	using SquareFemtometer = xieite::units::Unit<"area", [](auto x) { return x / 1e30; }, [](auto x) { return x * 1e30; }>;
	using SquarePicometer = xieite::units::Unit<"area", [](auto x) { return x / 1e24; }, [](auto x) { return x * 1e24; }>;
	using SquareNanometer = xieite::units::Unit<"area", [](auto x) { return x / 1e18; }, [](auto x) { return x * 1e18; }>;
	using SquareMicrometer = xieite::units::Unit<"area", [](auto x) { return x / 1e12; }, [](auto x) { return x * 1e12; }>;
	using SquareMillimeter = xieite::units::Unit<"area", [](auto x) { return x / 1e6; }, [](auto x) { return x * 1e6; }>;
	using SquareCentimeter = xieite::units::Unit<"area", [](auto x) { return x / 1e4; }, [](auto x) { return x * 1e4; }>;
	using SquareDecimeter = xieite::units::Unit<"area", [](auto x) { return x / 1e2; }, [](auto x) { return x * 1e2; }>;
	using SquareMeter = xieite::units::Unit<"area">;
	using SquareDecameter = xieite::units::Unit<"area", [](auto x) { return x * 1e2; }, [](auto x) { return x / 1e2; }>;
	using SquareHectometer = xieite::units::Unit<"area", [](auto x) { return x * 1e4; }, [](auto x) { return x / 1e4; }>;
	using SquareKilometer = xieite::units::Unit<"area", [](auto x) { return x * 1e6; }, [](auto x) { return x / 1e6; }>;
	using SquareMegameter = xieite::units::Unit<"area", [](auto x) { return x * 1e12; }, [](auto x) { return x / 1e12; }>;
	using SquareGigameter = xieite::units::Unit<"area", [](auto x) { return x * 1e18; }, [](auto x) { return x / 1e18; }>;
	using SquareTerameter = xieite::units::Unit<"area", [](auto x) { return x * 1e24; }, [](auto x) { return x / 1e24; }>;
	using SquarePetameter = xieite::units::Unit<"area", [](auto x) { return x * 1e30; }, [](auto x) { return x / 1e30; }>;
	using SquareExameter = xieite::units::Unit<"area", [](auto x) { return x * 1e36; }, [](auto x) { return x / 1e36; }>;
	using SquareZettameter = xieite::units::Unit<"area", [](auto x) { return x * 1e42; }, [](auto x) { return x / 1e42; }>;
	using SquareYottameter = xieite::units::Unit<"area", [](auto x) { return x * 1e48; }, [](auto x) { return x / 1e48; }>;
	using SquareRonnameter = xieite::units::Unit<"area", [](auto x) { return x * 1e54; }, [](auto x) { return x / 1e54; }>;
	using SquareQuettameter = xieite::units::Unit<"area", [](auto x) { return x * 1e60; }, [](auto x) { return x / 1e60; }>;
	using SquareInch = xieite::units::Unit<"area", [](auto x) { return x / 1550.0031; }, [](auto x) { return x * 1550.0031; }>;
	using SquareFoot = xieite::units::Unit<"area", [](auto x) { return x / 10.7639104; }, [](auto x) { return x * 10.7639104; }>;
	using SquareYard = xieite::units::Unit<"area", [](auto x) { return x * 0.83612736; }, [](auto x) { return x / 0.83612736; }>;
	using SquareMile = xieite::units::Unit<"area", [](auto x) { return x * 2589988.110336; }, [](auto x) { return x / 2589988.110336; }>;
	using SquareRood = xieite::units::Unit<"area", [](auto x) { return x * 1011.7141056; }, [](auto x) { return x / 1011.7141056; }>;
	using Acre = xieite::units::Unit<"area", [](auto x) { return x * 4046.8564224; }, [](auto x) { return x / 4046.8564224; }>;
	using Decare = xieite::units::Unit<"area", [](auto x) { return x * 1e3; }, [](auto x) { return x / 1e3; }>;
	using Decimilliare = xieite::units::SquareDecimeter;
	using Centiare = xieite::units::SquareMeter;
	using Deciare = xieite::units::Unit<"area", [](auto x) { return x * 1e1; }, [](auto x) { return x / 1e1; }>;
	using Are = xieite::units::SquareDecameter;
	using Hectare = xieite::units::SquareHectometer;
}
