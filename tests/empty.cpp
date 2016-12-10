#include "catch.hpp"
#include <stack.hpp>


SCENARIO("empty() must return answer on <Is stack empty?>")
{
    GIVEN("Empty stack")
    {
        stack<int> s;
        WHEN("Calling empty()")
        {
            THEN("empty() must return true")
            {
                REQUIRE(s.empty() == true);
            }
        }
    }

    GIVEN("Filled stack")
    {
        stack<int> s;
        s.push(0);
        WHEN("Calling empty()")
        {
            THEN("empty() must return false")
            {
                REQUIRE(s.empty() == false);
            }
        }
    }
}


