#include <xte/meta/type_at.hpp>
#include <xte/trait/is_same.hpp>

struct A {};
struct B {};
struct C {};
struct D {};
struct E {};
struct F {};

static_assert(xte::is_same<A, xte::type_at<0, A, B, C, D, E, F>>);
static_assert(xte::is_same<B, xte::type_at<1, A, B, C, D, E, F>>);
static_assert(xte::is_same<C, xte::type_at<2, A, B, C, D, E, F>>);
static_assert(xte::is_same<D, xte::type_at<3, A, B, C, D, E, F>>);
static_assert(xte::is_same<E, xte::type_at<4, A, B, C, D, E, F>>);
static_assert(xte::is_same<F, xte::type_at<5, A, B, C, D, E, F>>);
