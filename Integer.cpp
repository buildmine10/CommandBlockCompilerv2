//
// Created by colli on 5/12/2022.
//

#include "Integer.h"
#include "HelperFunctions.h"

#include <fstream>
#include <unordered_set>
#include <stdexcept>
#include <iostream>


std::string Variable::getInteger(const std::string& name){
    if(!isNameUsed(name)){
        throw std::runtime_error("This integer does not exist");
    }
    return "@e[type=minecart, sort=nearest, limit=1] " + name;
}

std::string Variable::makeInteger(const std::string& name){
    nameValidation(name);

    std::string out;
    out += "scoreboard objectives add " + name + " dummy" + "\n";
    out += setInteger(name, 0) + "\n";

    return out;
}

std::string Variable::deleteInteger(const std::string& name){
    nameRemoval(name);
    return "scoreboard objectives remove " + name + "\n";
}

std::string Variable::setInteger(const std::string& name, int value){
    return "scoreboard players set " + getInteger(name) + " " + std::to_string(value) + "\n";
}

std::string Variable::setInteger(const std::string& name, const std::string& name2){
    return "scoreboard players operation " + getInteger(name) + " = " + getInteger(name2) + "\n";
}

std::string Variable::incrementInteger(const std::string& name, int value){
    return "scoreboard players add " + getInteger(name) + " " + std::to_string(value) + "\n";
}

std::string Variable::incrementInteger(const std::string& name, const std::string& name2){
    return "scoreboard players operation " + getInteger(name) + " += " + getInteger(name2) + "\n";
}

std::string Variable::decrementInteger(const std::string& name, int value){
    return "scoreboard players remove " + getInteger(name) + " " + std::to_string(value) + "\n";
}

std::string Variable::decrementInteger(const std::string& name, const std::string& name2){
    return "scoreboard players operation " + getInteger(name) + " -= " + getInteger(name2) + "\n";
}

std::string Variable::multiplyInteger(const std::string& name, int value){
    std::string out;
    out += setInteger("tempUsedForIntegerMath", value);
    out += "scoreboard players operation " + getInteger(name) + " *= " + getInteger("tempUsedForIntegerMath") + "\n";
    return out;
}

std::string Variable::multiplyInteger(const std::string& name, const std::string& name2){
    return "scoreboard players operation " + getInteger(name) + " *= " + getInteger(name2) + "\n";
}

std::string Variable::divideInteger(const std::string& name, int value){
    std::string out;
    out += setInteger("tempUsedForIntegerMath", value);
    out += "scoreboard players operation " + getInteger(name) + " /= " + getInteger("tempUsedForIntegerMath") + "\n";
    return out;
}

std::string Variable::divideInteger(const std::string& name, const std::string& name2){
    return "scoreboard players operation " + getInteger(name) + " /= " + getInteger(name2) + "\n";
}