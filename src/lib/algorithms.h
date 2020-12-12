
#pragma once

#include <concepts>

#include "range.h"

namespace ds {
  template < typename T >
  concept weakly_ordered = requires( T t1, T t2 ) {
    { t1 < t2 }
    ->std::same_as< bool >;
    { t1 <= t2 }
    ->std::same_as< bool >;
  }
  || requires( T t1, T t2 ) {
    { t1 > t2 }
    ->std::same_as< bool >;
    { t1 >= t2 }
    ->std::same_as< bool >;
  };

  template < range R >
  void sort( R r ) requires weakly_ordered< typename R::value_type > {
    auto iter      = r.begin();
    const auto end = r.end();
  }
} // namespace ds
