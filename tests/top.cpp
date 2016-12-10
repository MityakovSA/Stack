#include "catch.hpp"
#include <stack.hpp>


SCENARIO("top() must return constant pointer on the top element of the stack")
{
    GIVEN("Filled stack")
    {
        stack<int> s;
        s.push(0);
        s.push(1);
        s.push(2);
        WHEN("Calling top()")
        {
            THEN("top() must return constant pointer on 2")
            {
                REQUIRE(*s.top() == 2);
            }
        }
    }
    GIVEN("Empty stack")
    {
        stack<int> s;
        WHEN("Calling top()")
        {
            THEN("top() return nullptr")
            {
                REQUIRE(s.top() == nullptr);
            }
        }
    }
}
