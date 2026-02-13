#include <xte/meta/make_seq.hpp>
#include <xte/meta/seq.hpp>
#include <xte/trait/is_same.hpp>
#include <xte/util/types.hpp>

static_assert(([]<xte::uz... i>(xte::seq<i...>) {
	return sizeof...(i);
})(xte::make_seq<3>) == 3);
