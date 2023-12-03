#pragma once

#include "npc.h"

class Outlaw: public NPC{
public:
    Outlaw(int x, int y, std::string& name): NPC(OutlawType, x, y, name){}
    Outlaw(std::ifstream& is, std::string& name): NPC(OutlawType, is, name){}

    void save(std::ofstream& os) override;
    void print() override;
    void get_name(std::ofstream& os) override;
    void accept(std::shared_ptr<NPC> attacker, Visitor& visitor) override;
    void attach(std::shared_ptr<FightObserver> observer) override;
    void detach(std::shared_ptr<FightObserver> observer) override;
    
    friend std::ostream& operator<<(std::ostream& os, Outlaw& outlaw);
};