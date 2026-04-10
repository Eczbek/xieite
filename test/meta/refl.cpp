#include <xte/data/string_view.hpp>
#include <xte/math/approx_equal.hpp>
#include <xte/meta/refl.hpp>

using namespace xte::literal::refl;

static_assert([:123_refl:] == 123);
static_assert(xte::approx_equal([:3.14159_refl:], 3.14159));
static_assert([:"abc"_refl:] == xte::string_view("abc"));
