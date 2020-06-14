#pragma once

#include <iostream>
#include <utility>

namespace ds {

  template < typename R >
  concept range = requires( R r ) {
    { r.begin() };
    { r.end() };
  };

  template < typename R >
  concept reverse_range = range< R >&& requires( R r ) {
    { r.rbegin() };
    { r.rend() };
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
