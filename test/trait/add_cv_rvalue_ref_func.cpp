#include <xte/meta/member_type.hpp>
#include <xte/trait/add_cv_rvalue_ref_func.hpp>
#include <xte/trait/is_same.hpp>

struct A {};

static_assert(xte::is_same<int() const volatile&& noexcept, xte::add_cv_rvalue_ref_func<int() noexcept>>);
static_assert(xte::is_same<xte::member_type<A, int() const volatile&& noexcept>, xte::add_cv_rvalue_ref_func<xte::member_type<A, int() noexcept>>>);
static_assert(xte::is_same<int() const volatile& noexcept, xte::add_cv_rvalue_ref_func<int() & noexcept>>);
