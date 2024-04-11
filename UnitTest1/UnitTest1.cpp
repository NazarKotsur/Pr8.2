#include "pch.h" 
#include "CppUnitTest.h"
#include "../Pr8.2/Pr8.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(RemoveParenthesesTest)
    {
    public:

        TEST_METHOD(TestRemoveParentheses_NoParentheses)
        {
            std::string input = "abcdef";

            std::string result = removeParentheses(input);

            Assert::AreEqual(input, result);
        }

        TEST_METHOD(TestRemoveParentheses_SingleParentheses)
        {
            std::string input = "a(b)c";

            std::string result = removeParentheses(input);

            Assert::AreEqual(std::string("abc"), result);
        }

        TEST_METHOD(TestRemoveParentheses_MultipleParentheses)
        {
            std::string input = "a(b(cd)e)f";

            std::string result = removeParentheses(input);

            Assert::AreEqual(std::string("acdb(cd)ef"), result);
        }

        TEST_METHOD(TestRemoveParentheses_NestedParentheses)
        {
            std::string input = "a(b(cd)e)f(g)";

            std::string result = removeParentheses(input);

            Assert::AreEqual(std::string("acdb(cd)efg"), result);
        }

        TEST_METHOD(TestRemoveParentheses_EmptyString)
        {
            std::string input = "";

            std::string result = removeParentheses(input);

            Assert::AreEqual(input, result);
        }
    };
}
