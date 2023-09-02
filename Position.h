//
// Created by colli on 5/12/2022.
//

#ifndef COMMANDBLOCKCOMPILERV2_POSITION_H
#define COMMANDBLOCKCOMPILERV2_POSITION_H


#include <vector>
#include <string>
#include <algorithm>

namespace Variable{
    std::string makePosition(const std::string& name, double x = 0, double y = 0, double z = 0, bool isRelative = true);
    std::string getPosition(const std::string& name);
    std::string deletePosition(const std::string& name);

    std::string setPosition(const std::string& name, double x, double y, double z, bool isRelative = true);
    std::string movePosition(const std::string& name, double x, double y, double z);

    std::string movePositionToEntity(const std::string& name, const std::string& selector);

    std::string executeAtPosition(const std::string& name, const std::string& command);
}

#endif //COMMANDBLOCKCOMPILERV2_POSITION_H
