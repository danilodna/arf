#include "TestMenu.hpp"

TestMenu::TestMenu(Test*& currentTest)
    : m_currentTest(currentTest)
{

}

void TestMenu::onImGuiRender()
{
    for(auto& test: m_tests)
    {
        if (ImGui::Button(test.first.c_str())) 
            m_currentTest = test.second();
    }
    
}
