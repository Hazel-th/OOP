#include "orc.h"
#include "visitor.h"
#include <algorithm>

void Orc::save(std::ofstream& os){
    os << OrcType << "\n";
    NPC::save(os);
}

void Orc::print(){
    std::cout << *this;
}

void Orc::get_name(std::ofstream& os){
    os << this->name << ": x = " << this->x << "; y = " << this->y << "\n";
}

void Orc::accept(std::shared_ptr<NPC> attacker,Visitor& visitor){}

void Orc::attach(std::shared_ptr<FightObserver> observer){
    NPC::observers.push_back(observer);
}

void Orc::detach(std::shared_ptr<FightObserver> observer){
    NPC::observers.erase(std::find(NPC::observers.begin(), NPC::observers.end(), observer));
}

std::ostream& operator<<(std::ostream& os, Orc& orc){
    os << *static_cast<NPC*>(&orc);
    return os;
}