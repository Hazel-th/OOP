#pragma once

#include "npc.h"

class Orc: public NPC{
public:
    Orc(int x, int y, std::string& name): NPC(OrcType, x, y, name){}
    Orc(std::ifstream& is, std::string& name): NPC(OrcType, is, name){}

    void save(std::ofstream& os) override;
    void print() override;
    void get_name(std::ofstream& os) override;
    void accept(std::shared_ptr<NPC> attacker, Visitor& visitor) override;
    void attach(std::shared_ptr<FightObserver> observer) override;
    void detach(std::shared_ptr<FightObserver> observer) override;
    
    friend std::ostream& operator<<(std::ostream& os, Orc& Orc);
};