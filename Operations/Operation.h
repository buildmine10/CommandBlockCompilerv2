//
// Created by colli on 5/12/2022.
//

#ifndef COMMANDBLOCKCOMPILERV2_OPERATION_H
#define COMMANDBLOCKCOMPILERV2_OPERATION_H
#include <string>

class Operation {
protected:
    std::string keyword = "invalid";

public:

    virtual std::string getText() = 0;


};


#endif //COMMANDBLOCKCOMPILERV2_OPERATION_H
