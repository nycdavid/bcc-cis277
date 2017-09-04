#include "../../catch.hpp"
#define CATCH_CONFIG_MAIN

TEST_CASE("Vector#calc_sum") {
  SECTION("it returns a vector") {
    Vector v1 = { 2.00, 4.00 };
    Vector v2 = { 3.00, 5.00 };
    Vector sum_vector;
    calc_sum(v1, v2, sum_vector);

    REQUIRE(sum_vector.x == 5.00);
    REQUIRE(sum_vector.y == 9.00);
  }
}
