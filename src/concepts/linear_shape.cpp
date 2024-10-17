export module xieite:concepts.LinearShape;

import std;
import :concepts.Arithmetic;
import :concepts.SameAsAny;

export namespace xieite::geometry {
	template<xieite::concepts::Arithmetic>
	struct Line;

	template<xieite::concepts::Arithmetic>
	struct Ray;

	template<xieite::concepts::Arithmetic>
	struct Segment;
}

export namespace xieite::concepts {
	template<typename Type, typename Arithmetic = double>
	concept LinearShape =
		xieite::concepts::Arithmetic<Arithmetic>
		&& xieite::concepts::SameAsAny<
			std::remove_cvref_t<Type>,
			xieite::geometry::Line<Arithmetic>,
			xieite::geometry::Ray<Arithmetic>,
			xieite::geometry::Segment<Arithmetic>
		>;
}
