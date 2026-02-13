#include <xte/literal/analog.hpp>

using namespace xte::literal::analog;

static_assert((x).width == 0);

static_assert((x).height == 0);

static_assert((x).length == 0);

static_assert((x).area == 0);

static_assert((x).volume == 0);

static_assert((x - x).width == 0);

static_assert((x - x).height == 0);

static_assert((x - x).length == 1);

static_assert((x - x).area == 0);

static_assert((x - x).volume == 0);

static_assert((x - - - - - x).width == 0);

static_assert((x - - - - - x).height == 0);

static_assert((x - - - - - x).length == 5);

static_assert((x - - - - - x).area == 0);

static_assert((x - - - - - x).volume == 0);

static_assert((x - +
               !   !
               + - x).width == 1);

static_assert((x - +
               !   !
               + - x).height == 1);

static_assert((x - +
               !   !
               + - x).length == 0);

static_assert((x - +
               !   !
               + - x).area == 1);

static_assert((x - +
               !   !
               + - x).volume == 0);

static_assert((x - - +
               !     !
               + - - x).width == 2);

static_assert((x - - +
               !     !
               + - - x).height == 1);

static_assert((x - - +
               !     !
               + - - x).length == 0);

static_assert((x - - +
               !     !
               + - - x).area == 2);

static_assert((x - - +
               !     !
               + - - x).volume == 0);

static_assert((x - +
               !   !
               !   !
               + - x).width == 1);

static_assert((x - +
               !   !
               !   !
               + - x).height == 2);

static_assert((x - +
               !   !
               !   !
               + - x).length == 0);

static_assert((x - +
               !   !
               !   !
               + - x).area == 2);

static_assert((x - +
               !   !
               !   !
               + - x).volume == 0);

static_assert((x - - - - - +
               !           !
               !           !
               !           !
               !           !
               !           !
               + - - - - - x).width == 5);

static_assert((x - - - - - +
               !           !
               !           !
               !           !
               !           !
               !           !
               + - - - - - x).height == 5);

static_assert((x - - - - - +
               !           !
               !           !
               !           !
               !           !
               !           !
               + - - - - - x).length == 0);

static_assert((x - - - - - +
               !           !
               !           !
               !           !
               !           !
               !           !
               + - - - - - x).area == 25);

static_assert((x - - - - - +
               !           !
               !           !
               !           !
               !           !
               !           !
               + - - - - - x).volume == 0);

static_assert((x - +
               !*   *
               + + - +
                *!   !
                 + - x).width == 1);

static_assert((x - +
               !*   *
               + + - +
                *!   !
                 + - x).height == 1);

static_assert((x - +
               !*   *
               + + - +
                *!   !
                 + - x).length == 1);

static_assert((x - +
               !*   *
               + + - +
                *!   !
                 + - x).area == 6);

static_assert((x - +
               !*   *
               + + - +
                *!   !
                 + - x).volume == 1);

static_assert((x - - +
               !*     *
               + + - - +
                *!     !
                 + - - x).width == 2);

static_assert((x - - +
               !*     *
               + + - - +
                *!     !
                 + - - x).height == 1);

static_assert((x - - +
               !*     *
               + + - - +
                *!     !
                 + - - x).length == 1);

static_assert((x - - +
               !*     *
               + + - - +
                *!     !
                 + - - x).area == 10);

static_assert((x - - +
               !*     *
               + + - - +
                *!     !
                 + - - x).volume == 2);

static_assert((x - +
               !*   *
               ! + - +
               + !   !
                *!   !
                 + - x).width == 1);

static_assert((x - +
               !*   *
               ! + - +
               + !   !
                *!   !
                 + - x).height == 2);

static_assert((x - +
               !*   *
               ! + - +
               + !   !
                *!   !
                 + - x).length == 1);

static_assert((x - +
               !*   *
               ! + - +
               + !   !
                *!   !
                 + - x).area == 10);

static_assert((x - +
               !*   *
               ! + - +
               + !   !
                *!   !
                 + - x).volume == 2);

static_assert((x - +
               !*   *
               + *   *
                * + - +
                 *!   !
                  + - x).width == 1);

static_assert((x - +
               !*   *
               + *   *
                * + - +
                 *!   !
                  + - x).height == 1);

static_assert((x - +
               !*   *
               + *   *
                * + - +
                 *!   !
                  + - x).length == 2);

static_assert((x - +
               !*   *
               + *   *
                * + - +
                 *!   !
                  + - x).area == 10);

static_assert((x - +
               !*   *
               + *   *
                * + - +
                 *!   !
                  + - x).volume == 2);

static_assert((x - - - - - +
               !*           *
               ! *           *
               !  *           *
               !   *           *
               !    *           *
               +     + - - - - - +
                *    !           !
                 *   !           !
                  *  !           !
                   * !           !
                    *!           !
                     + - - - - - x).width == 5);

static_assert((x - - - - - +
               !*           *
               ! *           *
               !  *           *
               !   *           *
               !    *           *
               +     + - - - - - +
                *    !           !
                 *   !           !
                  *  !           !
                   * !           !
                    *!           !
                     + - - - - - x).height == 5);

static_assert((x - - - - - +
               !*           *
               ! *           *
               !  *           *
               !   *           *
               !    *           *
               +     + - - - - - +
                *    !           !
                 *   !           !
                  *  !           !
                   * !           !
                    *!           !
                     + - - - - - x).length == 5);

static_assert((x - - - - - +
               !*           *
               ! *           *
               !  *           *
               !   *           *
               !    *           *
               +     + - - - - - +
                *    !           !
                 *   !           !
                  *  !           !
                   * !           !
                    *!           !
                     + - - - - - x).area == 150);

static_assert((x - - - - - +
               !*           *
               ! *           *
               !  *           *
               !   *           *
               !    *           *
               +     + - - - - - +
                *    !           !
                 *   !           !
                  *  !           !
                   * !           !
                    *!           !
                     + - - - - - x).volume == 125);
