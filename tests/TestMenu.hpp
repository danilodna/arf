#ifndef TEST_MENU_HPP_
#define TEST_MENU_HPP_

#include "Test.hpp"

class TestMenu : public Test
{
public:
    TestMenu() = default;
    TestMenu(Test*& current);
    ~TestMenu() = default;

    void onImGuiRender() override;
    
    template<typename T>
    void addTest(const std::string& name)
    {
        std::cout << "Adding test: " << name << std::endl;
        m_tests[name] = []() { return new T(); };
    }

private:
    // A pointer that have the address of a reference of the Current Test;
    // This way its possible to construct and destruct tests in real time, not just making active one
    // from a list of inactive tests.
    Test*& m_currentTest;
    std::map<std::string, std::function<Test*()> > m_tests;
};

#endif // TEST_MENU_HPP_