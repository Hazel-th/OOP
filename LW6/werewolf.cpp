#include "werewolf.h"
#include "visitor.h"
#include <algorithm>

void Werewolf::save(std::ofstream& os){
    os << WerewolfType << "\n";
    NPC::save(os);
}

void Werewolf::print(){
    std::cout << *this;
}

void Werewolf::get_name(std::ofstream& os){
    os << this->name << ": x = " << this->x << "; y = " << this->y << "\n";
}

void Werewolf::accept(std::shared_ptr<NPC> attacker, Visitor& visitor) {
    int res = 0;
    if(dynamic_cast<Outlaw*>(attacker.get()))
        res = visitor.visit(dynamic_cast<Outlaw*>(attacker.get()));
    
    if(res == 1) success = true;
}

void Werewolf::attach(std::shared_ptr<FightObserver> observer){
    NPC::observers.push_back(observer);
}

void Werewolf::detach(std::shared_ptr<FightObserver> observer){
    NPC::observers.erase(std::find(NPC::observers.begin(), NPC::observers.end(), observer));
}

std::ostream& operator<<(std::ostream& os, Werewolf& werewolf){
    os << *static_cast<NPC*>(&werewolf);
    return os;
}