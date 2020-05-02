// Copyright 2020 Peter Dimov
// Distributed under the Boost Software License, Version 1.0.
// https://www.boost.org/LICENSE_1_0.txt

#include <boost/endian/conversion.hpp>
#include <boost/core/lightweight_test.hpp>
#include <boost/config.hpp>
#include <cstddef>

template<class T> void test_reverse( T x )
{
    using boost::endian::endian_reverse;

    T x2 = endian_reverse( endian_reverse( x ) );

    BOOST_TEST( x == x2 );
}

template<class T> void test_reverse_inplace( T x )
{
    using boost::endian::endian_reverse_inplace;

    T x2( x );

    endian_reverse_inplace( x2 );
    endian_reverse_inplace( x2 );

    BOOST_TEST( x == x2 );
}

enum E1 { e1 };

#if !defined(BOOST_NO_CXX11_SCOPED_ENUMS)

enum E2: long { e2 };
enum class E3 { e3 };
enum class E4: long { e4 };

#endif

int main()
{
    test_reverse( 1 );

#if !defined(BOOST_NO_CXX11_SCOPED_ENUMS)

    test_reverse( E3::e3 );
    test_reverse( E4::e4 );

#endif

    test_reverse_inplace( 1 );

#if !defined(BOOST_NO_CXX11_SCOPED_ENUMS)

    test_reverse_inplace( E3::e3 );
    test_reverse_inplace( E4::e4 );

#endif

    return boost::report_errors();
}
