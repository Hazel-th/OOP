#pragma once

#include "outlaw.h"
#include "orc.h"
#include "werewolf.h"

class Visitor{
public:
    virtual int visit(Outlaw* element) = 0;
    virtual int visit(Orc* element) = 0;
    virtual int visit(Werewolf* element) = 0;
};

class OnceVisitor: public Visitor{
public:
    int visit(Outlaw* element) override{
        return 1;
    }

    int visit(Orc* element) override{
        return 2;
    }

    int visit(Werewolf* element) override{
        return 3;
    }
};