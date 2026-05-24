#include <xte/data/quote.hpp>

static_assert(xte::quote('a') == "'a'");
static_assert(xte::quote(' ') == "' '");
static_assert(xte::quote('"') == "'\"'");
static_assert(xte::quote('\'') == "'\\''");
static_assert(xte::quote('\\') == "'\\\\'");
static_assert(xte::quote('\a') == "'\\a'");
static_assert(xte::quote('\b') == "'\\b'");
static_assert(xte::quote('\f') == "'\\f'");
static_assert(xte::quote('\n') == "'\\n'");
static_assert(xte::quote('\r') == "'\\r'");
static_assert(xte::quote('\t') == "'\\t'");
static_assert(xte::quote('\v') == "'\\v'");
static_assert(xte::quote('\0') == "'\\x0'");
