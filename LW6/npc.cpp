#include "npc.h"

NPC::NPC(NpcType t, int x, int y, std::string& name){
    type = t;
    this->x = x;
    this->y = y; 
    this->name = name;
}

NPC::NPC(NpcType t, std::ifstream& is, std::string& name){ 
    type = t;
    this->name = name;
    is >> x;
    is >> y;
}

bool NPC::is_close(const std::shared_ptr<NPC>& other, size_t distance) const{
    if (std::pow(x - other->x, 2) + std::pow(y - other->y, 2) <= std::pow(distance, 2))
        return true;
    else
        return false;
}

void NPC::notify(NPC* attacker, bool win){
    if (win == 1){
        for (auto &elem : NPC::observers){
            elem->update(this, attacker, win);
        }
    }
}

void NPC::save(std::ofstream& os){
    os << x << "\n";
    os << y << "\n";
}

std::ostream& operator<<(std::ostream& os, NPC& npc){
    os << npc.name << ": x = " << npc.x << "; y = " << npc.y << "\n";
    return os;
}