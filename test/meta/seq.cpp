#include <xte/aliases.hpp>
#include <xte/meta/seq.hpp>

[[maybe_unused]] constexpr xte::seq<0, 1, 2> x;

static_assert(([]<xte::uz... i>(xte::seq<i...>) {
	return sizeof...(i);
})(xte::make_seq<3>) == 3);
