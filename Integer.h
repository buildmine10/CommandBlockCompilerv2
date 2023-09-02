//
// Created by colli on 5/12/2022.
//

#ifndef COMMANDBLOCKCOMPILERV2_INTEGER_H
#define COMMANDBLOCKCOMPILERV2_INTEGER_H

#include <vector>
#include <string>
#include <algorithm>

namespace Variable{
    std::string makeInteger(const std::string& name);
    std::string getInteger(const std::string& name);
    std::string deleteInteger(const std::string& name);


    std::string setInteger(const std::string& name, int value);
    std::string setInteger(const std::string& name, const std::string& name2);

    std::string incrementInteger(const std::string& name, int value);
    std::string incrementInteger(const std::string& name, const std::string& name2);

    std::string decrementInteger(const std::string& name, int value);
    std::string decrementInteger(const std::string& name, const std::string& name2);

    std::string multiplyInteger(const std::string& name, int value);
    std::string multiplyInteger(const std::string& name, const std::string& name2);

    std::string divideInteger(const std::string& name, int value);
    std::string divideInteger(const std::string& name, const std::string& name2);
}

#endif //COMMANDBLOCKCOMPILERV2_INTEGER_H
