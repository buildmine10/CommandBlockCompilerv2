//
// Created by colli on 5/12/2022.
//

#ifndef COMMANDBLOCKCOMPILERV2_HELPERFUNCTIONS_H
#define COMMANDBLOCKCOMPILERV2_HELPERFUNCTIONS_H

#include "Integer.h"
#include "Position.h"

#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>


inline std::string &ltrim(std::string &s){
    s.erase(s.begin(), std::find_if(s.begin(), s.end(),
                                    std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
inline std::string &rtrim(std::string &s){
    s.erase(std::find_if(s.rbegin(), s.rend(),
                         std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
    return s;
}

// trim from both ends
inline std::string &trim(std::string &s){
    return ltrim(rtrim(s));
}

std::vector<std::string> getLines(const std::string& fileName);

extern const std::string commandStart;
extern const std::string commandEnd;


namespace Variable{
    extern std::unordered_set<std::string> usedNames;

    std::string initialization();
    std::string uninitialization();
    bool isNameUsed(const std::string& name);
    void nameValidation(const std::string& name);
    void nameRemoval(const std::string& name);
}

void printCommand(std::string commands);



#endif //COMMANDBLOCKCOMPILERV2_HELPERFUNCTIONS_H
