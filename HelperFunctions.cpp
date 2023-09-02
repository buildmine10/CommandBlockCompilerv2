//
// Created by colli on 5/12/2022.
//

#include "HelperFunctions.h"
#include <fstream>

#include <stdexcept>
#include <iostream>

std::unordered_set<std::string> Variable::usedNames;



std::vector<std::string> getLines(const std::string& fileName){
    std::ifstream file;
    file.open(fileName);
    std::vector<std::string> lines;

    while(!file.eof()){
        std::string line;
        std::getline(file, line);
        trim(line);
        lines.push_back(line);
    }

    return lines;
}

const std::string commandStart = "{id:command_block_minecart,Command:'";
const std::string commandEnd = "'},\n";

bool Variable::isNameUsed(const std::string& name){
    return usedNames.count(name) > 0;
}

void Variable::nameValidation(const std::string& name){
    if(isNameUsed(name)){
        throw std::runtime_error("Variable name already used");
    }else{
        usedNames.insert(name);
    }
}

void Variable::nameRemoval(const std::string& name){
    usedNames.erase(name);
}


std::string Variable::initialization(){


    std::string out;

    nameValidation("tempUsedForIntegerMath");
    out += commandStart + "scoreboard objectives add " + "tempUsedForIntegerMath" + " dummy" + commandEnd;
    out += commandStart + setInteger("tempUsedForIntegerMath", 0);
    out.pop_back();
    out += commandEnd;

    return out;
}

std::string Variable::uninitialization(){

    nameRemoval("tempUsedForIntegerMath");
    std::string out;
    //out += deleteInteger("tempUsedForIntegerMath");
    out += commandStart + "scoreboard objectives remove tempUsedForIntegerMath" + commandEnd;


    return out;
}



void printCommand(std::string commands){
    std::string out = "summon falling_block ~ ~2 ~ {BlockState:{Name:redstone_block},Passengers:[";
    out +=            "{id:armor_stand,Health:0,Passengers:[";
    out +=            "{id:falling_block,BlockState:{Name:activator_rail},Passengers:[";
    out +=            "{id:command_block_minecart,Command:'gamerule commandBlockOutput false'},\n";
    out +=            "{id:command_block_minecart,Command:'data merge block ~ ~-2 ~ {auto:0}'},\n";
    out +=            "{id:minecart},\n";
    out += Variable::initialization();

    out += "\n\n\n";

    while(!commands.empty()){
        size_t nextLine = commands.find('\n');

        //std::cout << nextLine << std::endl;

        if(nextLine == commands.npos){
            out += commandStart + commands + commandEnd;
            commands.clear();
        }else{
            out += commandStart + commands.substr(0, nextLine) + commandEnd;
            commands.erase(0, nextLine + 1);
        }

    }

    out += "\n\n\n";

    out += Variable::uninitialization();
    out += "{id:command_block_minecart,Command:'setblock ~ ~1 ~ command_block{auto:1,Command:\"fill ~ ~ ~ ~ ~-2 ~ air\"}'},\n";
    out += "{id:command_block_minecart,Command:'kill @e[type=minecart,distance=..1]'},\n";
    out += "{id:command_block_minecart,Command:'kill @e[type=command_block_minecart,distance=..1]'}]}]}]}";


    std::cout << out << std::endl;
}



