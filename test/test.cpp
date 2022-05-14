#include "ctest.h"
#include "libgeo/geo.h"
#include <string>

using namespace std;

CTEST(arithmetic_suite, simple_sum)
{
    // Given
    string buffer = "circle (0 0, 1.5)";

    // When
    const Circle result = FindCircle(buffer);

    // Then
    double perimeter = 9.4245;
    double square = 7.06837;
    double r = 1.5;
    double x = 0;
    double y = 0;

    ASSERT_DBL_NEAR(perimeter, result.perimeter);
    ASSERT_DBL_NEAR(square, result.square);
    ASSERT_DBL_NEAR(x, result.x);
    ASSERT_DBL_NEAR(y, result.y);
    ASSERT_DBL_NEAR(r, result.r);
}

CTEST(triangle_suite, simple_triangle)
{
    // Given
    string buffer = "triangle ((-3 -2, -1 0, -3 2, -3 -2))";

    // When
    const Triangle result = FindTriangle(buffer);

    // Then
    double coord1[2] = {-3, -2};
    double coord2[2] = {-1, 0};
    double coord3[2] = {-3, 2};
    double coord4[2] = {-3, -2};
    double sTriangle = 4;
    double pTriangle = 9.65685;

    ASSERT_DBL_NEAR(coord1[0], result.coord1[0]);
    ASSERT_DBL_NEAR(coord1[1], result.coord1[1]);
    ASSERT_DBL_NEAR(coord2[0], result.coord2[0]);
    ASSERT_DBL_NEAR(coord2[1], result.coord2[1]);
    ASSERT_DBL_NEAR(coord3[0], result.coord3[0]);
    ASSERT_DBL_NEAR(coord3[1], result.coord3[1]);
    ASSERT_DBL_NEAR(coord4[0], result.coord4[0]);
    ASSERT_DBL_NEAR(coord4[1], result.coord4[1]);
    ASSERT_DBL_NEAR(pTriangle, result.pTriangle);
    ASSERT_DBL_NEAR(sTriangle, result.sTriangle);
}