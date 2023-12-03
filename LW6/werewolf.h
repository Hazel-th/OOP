#pragma once

#include "npc.h"

class Werewolf: public NPC{
public: 
    Werewolf(int x, int y, std::string& name): NPC(WerewolfType, x, y, name){}
    Werewolf(std::ifstream& is, std::string& name): NPC(WerewolfType, is, name){}

    void save(std::ofstream& os) override;
    void print() override;
    void get_name(std::ofstream& os) override;
    void accept(std::shared_ptr<NPC> attacker, Visitor& visitor) override;
    void attach(std::shared_ptr<FightObserver> observer) override;
    void detach(std::shared_ptr<FightObserver> observer) override;
    
    friend std::ostream& operator<<(std::ostream& os, Werewolf& Werewolf);
};