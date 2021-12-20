#include <iostream>

#include "TestSequence.h"
#include "TestSorts.h"
#include "Menu.h"


int main()
{
    testSeq();
    testAllSorts();
    std::cout << "Tests are passed well" << std::endl;
    Menu();
}