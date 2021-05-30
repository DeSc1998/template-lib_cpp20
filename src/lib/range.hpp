#pragma once

#include <concepts>
#include <iostream>

namespace ds {

  template < typename R, typename Iter = typename R::iterator >
  concept range = requires( R r ) {
    { r.begin() }
    ->std::same_as< Iter >;
    { r.end() }
    ->std::same_as< Iter >;
  };

  template < typename R, typename Iter = typename R::reverse_iterator >
  concept reverse_range = range< R >&& requires( R r ) {
    { r.rbegin() }
    ->std::same_as< Iter >;
    { r.rend() }
    ->std::same_as< Iter >;
  };

  template < range R >
  inline std::ostream& operator<<( std::ostream& stream, const R& r ) {
    const auto begin = r.begin();
    const auto end   = r.end();
    auto iter        = r.begin();

    do {
      if ( iter == begin )
        stream << '[';

      stream << *iter;

      if ( ++iter == end )
        stream << ']';
      else
        stream << ';';
    } while ( iter != end );

    return stream;
  }
} // namespace ds
