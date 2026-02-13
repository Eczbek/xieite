#include <xte/literal/dedent.hpp>

using namespace xte::literal::dedent;

static_assert(R"(
	abc
	xyz
)"_dedent == "abc\nxyz");
