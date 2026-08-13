#include <xte/data/escape.hpp>

static_assert(xte::escape('a') == "'a'");
static_assert(xte::escape(' ') == "' '");
static_assert(xte::escape('"') == "'\"'");
static_assert(xte::escape('\'') == "'\\''");
static_assert(xte::escape('\\') == "'\\\\'");
static_assert(xte::escape('\a') == "'\\a'");
static_assert(xte::escape('\b') == "'\\b'");
static_assert(xte::escape('\f') == "'\\f'");
static_assert(xte::escape('\n') == "'\\n'");
static_assert(xte::escape('\r') == "'\\r'");
static_assert(xte::escape('\t') == "'\\t'");
static_assert(xte::escape('\v') == "'\\v'");
static_assert(xte::escape('\0') == "'\\x0'");
