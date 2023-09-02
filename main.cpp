#include <iostream>

#include "HelperFunctions.h"



//variable types
//integer  (able to use in if statements)
//position (able to run commands at positions)



int main() {
    std::string out;
    out += Variable::makePosition("hi", 1, 1, 1);

    out += Variable::executeAtPosition("hi", "setblock ~ ~ ~ stone");
    //out += "execute at " + Variable::getPosition("hi") + " run setblock ~ ~ ~ stone" + "\n";

    out += Variable::deletePosition("hi");

    std::cout << std::endl << std::endl;

    printCommand(out);

    std::cout << std::endl << std::endl;

    system("pause");

    return 0;
}
