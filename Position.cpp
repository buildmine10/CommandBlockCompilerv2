//
// Created by colli on 5/12/2022.
//

#include "Position.h"
#include "HelperFunctions.h"

std::string Variable::makePosition(const std::string& name, double x, double y, double z, bool isRelative){
    nameValidation(name);
    std::string out;
    if(isRelative){
        out += "summon armor_stand ~" + std::to_string(x) + " ~" + std::to_string(y - 2) + " ~" + std::to_string(z) + " {NoGravity:1,Invulnerable:1,Invisible:1,Tags:[\"" + name + "\"]}" + "\n";
    }else{
        out += "summon armor_stand " + std::to_string(x) + " " + std::to_string(y) + " " + std::to_string(z) + " {NoGravity:1,Invulnerable:1,Invisible:1,Tags:[\"" + name + "\"]}" + "\n";
    }
    out += "execute as " + getPosition(name) + " at @s align xyz positioned ~0.5 ~0 ~0.5 run tp @s ~ ~ ~" + "\n";
    return out;
}

std::string Variable::getPosition(const std::string& name){
    return "@e[type=armor_stand,tag=" + name + ", sort=nearest, limit=1]";
}

std::string Variable::deletePosition(const std::string& name){
    nameRemoval(name);
    return "kill " + getPosition(name) + "\n";
}

std::string Variable::setPosition(const std::string& name, double x, double y, double z, bool isRelative){
    if(isRelative){
        return "tp " + Variable::getPosition(name) + " ~" + std::to_string(x) + " ~" + std::to_string(y - 2) + " ~" + std::to_string(z) + "\n";
    }else{
        return "tp " + Variable::getPosition(name) + " " + std::to_string(x) + " " + std::to_string(y) + " " + std::to_string(z) + "\n";
    }
}

std::string Variable::movePosition(const std::string& name, double x, double y, double z){
    std::string out;
    out += executeAtPosition(name, "tp " + Variable::getPosition(name) + " ~" + std::to_string(x) + " ~" + std::to_string(y) +" ~" + std::to_string(z));
    return out;
}

std::string Variable::executeAtPosition(const std::string& name, const std::string& command){
    std::string out;
    out += "execute at " + Variable::getPosition(name) + " run " + command + "\n";
    return out;
}

std::string Variable::movePositionToEntity(const std::string& name, const std::string& selector){
    std::string out;
    out += "execute at " + selector + " run tp " + getPosition(name) + " ~ ~ ~" + "\n";
    return out;
}