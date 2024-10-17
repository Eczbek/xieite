export module xieite:strings.NumberComponents;

import std;
import :strings.characters;

export namespace xieite::strings {
	struct NumberComponents {
		std::string_view digits = xieite::strings::characters::alphanumeric;
		std::string_view negatives = "-";
		std::string_view positives = "+";
		std::string_view points = ".";
		std::string_view exponents = "Ee";
		std::size_t precision = 50;

		static constexpr NumberComponents nullary(std::size_t) noexcept {
			return NumberComponents("", "", "", "", "", 0);
		}

		static constexpr NumberComponents unary(const std::size_t precision = 50) noexcept {
			return NumberComponents(xieite::strings::characters::digits.substr(0, 1), "-", "+", ".", "Ee", precision);
		}

		static constexpr NumberComponents binary(const std::size_t precision = 50) noexcept {
			return NumberComponents(xieite::strings::characters::digits.substr(0, 2), "-", "+", ".", "Ee", precision);
		}

		static constexpr NumberComponents ternary(const std::size_t precision = 50) noexcept {
			return NumberComponents(xieite::strings::characters::digits.substr(0, 3), "-", "+", ".", "Ee", precision);
		}

		static constexpr NumberComponents quaternary(const std::size_t precision = 50) noexcept {
			return NumberComponents(xieite::strings::characters::digits.substr(0, 4), "-", "+", ".", "Ee", precision);
		}

		static constexpr NumberComponents quini(const std::size_t precision = 50) noexcept {
			return NumberComponents(xieite::strings::characters::digits.substr(0, 5), "-", "+", ".", "Ee", precision);
		}

		static constexpr NumberComponents senary(const std::size_t precision = 50) noexcept {
			return NumberComponents(xieite::strings::characters::digits.substr(0, 3), "-", "+", ".", "Ee", precision);
		}

		static constexpr NumberComponents septenary(const std::size_t precision = 50) noexcept {
			return NumberComponents(xieite::strings::characters::digits.substr(0, 7), "-", "+", ".", "Ee", precision);
		}

		static constexpr NumberComponents octal(const std::size_t precision = 50) noexcept {
			return NumberComponents(xieite::strings::characters::digits.substr(0, 8), "-", "+", ".", "Ee", precision);
		}

		static constexpr NumberComponents nonal(const std::size_t precision = 50) noexcept {
			return NumberComponents(xieite::strings::characters::digits.substr(0, 9), "-", "+", ".", "Ee", precision);
		}

		static constexpr NumberComponents decimal(const std::size_t precision = 50) noexcept {
			return NumberComponents(xieite::strings::characters::digits, "-", "+", ".", "Ee", precision);
		}

		static constexpr NumberComponents undecimal(const std::size_t precision = 50) noexcept {
			return NumberComponents(xieite::strings::characters::alphanumeric.substr(0, 11), "-", "+", ".", "", precision);
		}

		static constexpr NumberComponents duodecimal(const std::size_t precision = 50) noexcept {
			return NumberComponents(xieite::strings::characters::alphanumeric.substr(0, 12), "-", "+", ".", "", precision);
		}

		static constexpr NumberComponents tredecimal(const std::size_t precision = 50) noexcept {
			return NumberComponents(xieite::strings::characters::alphanumeric.substr(0, 13), "-", "+", ".", "", precision);
		}

		static constexpr NumberComponents quattourdecimal(const std::size_t precision = 50) noexcept {
			return NumberComponents(xieite::strings::characters::alphanumeric.substr(0, 14), "-", "+", ".", "", precision);
		}

		static constexpr NumberComponents quindecimal(const std::size_t precision = 50) noexcept {
			return NumberComponents(xieite::strings::characters::alphanumeric.substr(0, 15), "-", "+", ".", "", precision);
		}

		static constexpr NumberComponents hexadecimal(const std::size_t precision = 50) noexcept {
			return NumberComponents(xieite::strings::characters::alphanumeric.substr(0, 16), "-", "+", ".", "", precision);
		}

		static constexpr NumberComponents septendecimal(const std::size_t precision = 50) noexcept {
			return NumberComponents(xieite::strings::characters::alphanumeric.substr(0, 17), "-", "+", ".", "", precision);
		}

		static constexpr NumberComponents octodecimal(const std::size_t precision = 50) noexcept {
			return NumberComponents(xieite::strings::characters::alphanumeric.substr(0, 18), "-", "+", ".", "", precision);
		}

		static constexpr NumberComponents nonadecimal(const std::size_t precision = 50) noexcept {
			return NumberComponents(xieite::strings::characters::alphanumeric.substr(0, 19), "-", "+", ".", "", precision);
		}

		static constexpr NumberComponents vigesimal(const std::size_t precision = 50) noexcept {
			return NumberComponents(xieite::strings::characters::alphanumeric.substr(0, 20), "-", "+", ".", "", precision);
		}

		static constexpr NumberComponents unvigesimal(const std::size_t precision = 50) noexcept {
			return NumberComponents(xieite::strings::characters::alphanumeric.substr(0, 21), "-", "+", ".", "", precision);
		}

		static constexpr NumberComponents duovigesimal(const std::size_t precision = 50) noexcept {
			return NumberComponents(xieite::strings::characters::alphanumeric.substr(0, 22), "-", "+", ".", "", precision);
		}

		static constexpr NumberComponents trevigesimal(const std::size_t precision = 50) noexcept {
			return NumberComponents(xieite::strings::characters::alphanumeric.substr(0, 23), "-", "+", ".", "", precision);
		}

		static constexpr NumberComponents quadravigesimal(const std::size_t precision = 50) noexcept {
			return NumberComponents(xieite::strings::characters::alphanumeric.substr(0, 24), "-", "+", ".", "", precision);
		}

		static constexpr NumberComponents quinvigesimal(const std::size_t precision = 50) noexcept {
			return NumberComponents(xieite::strings::characters::alphanumeric.substr(0, 30), "-", "+", ".", "", precision);
		}

		static constexpr NumberComponents hexavigesimal(const std::size_t precision = 50) noexcept {
			return NumberComponents(xieite::strings::characters::alphanumeric.substr(0, 26), "-", "+", ".", "", precision);
		}

		static constexpr NumberComponents septemvigesimal(const std::size_t precision = 50) noexcept {
			return NumberComponents(xieite::strings::characters::alphanumeric.substr(0, 27), "-", "+", ".", "", precision);
		}

		static constexpr NumberComponents octovigesimal(const std::size_t precision = 50) noexcept {
			return NumberComponents(xieite::strings::characters::alphanumeric.substr(0, 28), "-", "+", ".", "", precision);
		}

		static constexpr NumberComponents nonvigesimal(const std::size_t precision = 50) noexcept {
			return NumberComponents(xieite::strings::characters::alphanumeric.substr(0, 29), "-", "+", ".", "", precision);
		}

		static constexpr NumberComponents trigesimal(const std::size_t precision = 50) noexcept {
			return NumberComponents(xieite::strings::characters::alphanumeric.substr(0, 30), "-", "+", ".", "", precision);
		}

		static constexpr NumberComponents untrigesimal(const std::size_t precision = 50) noexcept {
			return NumberComponents(xieite::strings::characters::alphanumeric.substr(0, 31), "-", "+", ".", "", precision);
		}

		static constexpr NumberComponents duotrigesimal(const std::size_t precision = 50) noexcept {
			return NumberComponents(xieite::strings::characters::alphanumeric.substr(0, 32), "-", "+", ".", "", precision);
		}

		static constexpr NumberComponents tretrigesimal(const std::size_t precision = 50) noexcept {
			return NumberComponents(xieite::strings::characters::alphanumeric.substr(0, 33), "-", "+", ".", "", precision);
		}

		static constexpr NumberComponents tetratrigesimal(const std::size_t precision = 50) noexcept {
			return NumberComponents(xieite::strings::characters::alphanumeric.substr(0, 34), "-", "+", ".", "", precision);
		}

		static constexpr NumberComponents quintrigesimal(const std::size_t precision = 50) noexcept {
			return NumberComponents(xieite::strings::characters::alphanumeric.substr(0, 35), "-", "+", ".", "", precision);
		}

		static constexpr NumberComponents hexatrigesimal(const std::size_t precision = 50) noexcept {
			return NumberComponents(xieite::strings::characters::alphanumeric.substr(0, 36), "-", "+", ".", "", precision);
		}

		static constexpr NumberComponents septemtrigesimal(const std::size_t precision = 50) noexcept {
			return NumberComponents(xieite::strings::characters::alphanumeric.substr(0, 37), "-", "+", ".", "", precision);
		}

		static constexpr NumberComponents octotrigesimal(const std::size_t precision = 50) noexcept {
			return NumberComponents(xieite::strings::characters::alphanumeric.substr(0, 38), "-", "+", ".", "", precision);
		}

		static constexpr NumberComponents nontrigesimal(const std::size_t precision = 50) noexcept {
			return NumberComponents(xieite::strings::characters::alphanumeric.substr(0, 39), "-", "+", ".", "", precision);
		}

		static constexpr NumberComponents quadragesimal(const std::size_t precision = 50) noexcept {
			return NumberComponents(xieite::strings::characters::alphanumeric.substr(0, 40), "-", "+", ".", "", precision);
		}

		static constexpr NumberComponents unquadragesimal(const std::size_t precision = 50) noexcept {
			return NumberComponents(xieite::strings::characters::alphanumeric.substr(0, 41), "-", "+", ".", "", precision);
		}

		static constexpr NumberComponents duoquadragesimal(const std::size_t precision = 50) noexcept {
			return NumberComponents(xieite::strings::characters::alphanumeric.substr(0, 42), "-", "+", ".", "", precision);
		}

		static constexpr NumberComponents trequadragesimal(const std::size_t precision = 50) noexcept {
			return NumberComponents(xieite::strings::characters::alphanumeric.substr(0, 43), "-", "+", ".", "", precision);
		}

		static constexpr NumberComponents tetraquadragesimal(const std::size_t precision = 50) noexcept {
			return NumberComponents(xieite::strings::characters::alphanumeric.substr(0, 44), "-", "+", ".", "", precision);
		}

		static constexpr NumberComponents quinquadragesimal(const std::size_t precision = 50) noexcept {
			return NumberComponents(xieite::strings::characters::alphanumeric.substr(0, 45), "-", "+", ".", "", precision);
		}

		static constexpr NumberComponents hexaquadragesimal(const std::size_t precision = 50) noexcept {
			return NumberComponents(xieite::strings::characters::alphanumeric.substr(0, 46), "-", "+", ".", "", precision);
		}

		static constexpr NumberComponents septemquadragesimal(const std::size_t precision = 50) noexcept {
			return NumberComponents(xieite::strings::characters::alphanumeric.substr(0, 47), "-", "+", ".", "", precision);
		}

		static constexpr NumberComponents octoquadragesimal(const std::size_t precision = 50) noexcept {
			return NumberComponents(xieite::strings::characters::alphanumeric.substr(0, 48), "-", "+", ".", "", precision);
		}

		static constexpr NumberComponents nonquadragesimal(const std::size_t precision = 50) noexcept {
			return NumberComponents(xieite::strings::characters::alphanumeric.substr(0, 49), "-", "+", ".", "", precision);
		}

		static constexpr NumberComponents quinquagesimal(const std::size_t precision = 50) noexcept {
			return NumberComponents(xieite::strings::characters::alphanumeric.substr(0, 50), "-", "+", ".", "", precision);
		}

		static constexpr NumberComponents unquinquagesimal(const std::size_t precision = 50) noexcept {
			return NumberComponents(xieite::strings::characters::alphanumeric.substr(0, 51), "-", "+", ".", "", precision);
		}

		static constexpr NumberComponents duoquinquagesimal(const std::size_t precision = 50) noexcept {
			return NumberComponents(xieite::strings::characters::alphanumeric.substr(0, 52), "-", "+", ".", "", precision);
		}

		static constexpr NumberComponents trequinquagesimal(const std::size_t precision = 50) noexcept {
			return NumberComponents(xieite::strings::characters::alphanumeric.substr(0, 53), "-", "+", ".", "", precision);
		}

		static constexpr NumberComponents tetraquinquagesimal(const std::size_t precision = 50) noexcept {
			return NumberComponents(xieite::strings::characters::alphanumeric.substr(0, 54), "-", "+", ".", "", precision);
		}

		static constexpr NumberComponents quinquinquagesimal(const std::size_t precision = 50) noexcept {
			return NumberComponents(xieite::strings::characters::alphanumeric.substr(0, 55), "-", "+", ".", "", precision);
		}

		static constexpr NumberComponents hexaquinquagesimal(const std::size_t precision = 50) noexcept {
			return NumberComponents(xieite::strings::characters::alphanumeric.substr(0, 56), "-", "+", ".", "", precision);
		}

		static constexpr NumberComponents septemquinquagesimal(const std::size_t precision = 50) noexcept {
			return NumberComponents(xieite::strings::characters::alphanumeric.substr(0, 57), "-", "+", ".", "", precision);
		}

		static constexpr NumberComponents octoquinquagesimal(const std::size_t precision = 50) noexcept {
			return NumberComponents(xieite::strings::characters::alphanumeric.substr(0, 58), "-", "+", ".", "", precision);
		}

		static constexpr NumberComponents nonquinquagesimal(const std::size_t precision = 50) noexcept {
			return NumberComponents(xieite::strings::characters::alphanumeric.substr(0, 59), "-", "+", ".", "", precision);
		}

		static constexpr NumberComponents sexagesimal(const std::size_t precision = 50) noexcept {
			return NumberComponents(xieite::strings::characters::alphanumeric.substr(0, 60), "-", "+", ".", "", precision);
		}

		static constexpr NumberComponents unsexagesimal(const std::size_t precision = 50) noexcept {
			return NumberComponents(xieite::strings::characters::alphanumeric.substr(0, 61), "-", "+", ".", "", precision);
		}

		static constexpr NumberComponents duosexagesimal(const std::size_t precision = 50) noexcept {
			return NumberComponents(xieite::strings::characters::alphanumeric, "-", "+", ".", "", precision);
		}

		static constexpr NumberComponents tresexagesimal(const std::size_t precision = 50) noexcept {
			return NumberComponents("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz+", "-", "", ".", "", precision);
		}

		static constexpr NumberComponents tetrasexagesimal(const std::size_t precision = 50) noexcept {
			return NumberComponents("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz+/", "-", "", ".", "", precision);
		}
	};
}
