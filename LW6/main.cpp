#include "npc.h"
#include "outlaw.h"
#include "orc.h"
#include "werewolf.h"
#include "visitor.h"
#include "factory.h"

std::set<std::shared_ptr<NPC>> load(const std::string& filename){
    std::set<std::shared_ptr<NPC>> result;
    std::ifstream is;
    is.open(filename);

    if (is.good() && is.is_open()){
        int count;
        is >> count;

        for (int i = 0; i < count; ++i){
            result.insert(factory(is));
        }
        is.close();
    }
    else
        std::cerr << "File error." << "\n";
    return result;
}

int main(){

    srand(time(NULL));
    std::string m_file = "monsters.txt"; 
    std::set<std::shared_ptr<NPC>> monsters; 

    // monsters = load(m_file);

    for (size_t i = 0; i < 20; ++i){
        monsters.insert(factory(NpcType(std::rand() % 3 + 1),std::rand() % 500,std::rand() % 500));
    }

    std::ofstream file;
    file.open(m_file);

    if(file.is_open()){
        file << monsters.size() << "\n";
        for (auto &n : monsters)
            n->save(file);
        file.close();
    }
    else{
        std::cerr << "File error." << "\n";
    }

    ConsoleObserver consObserv;
    std::shared_ptr<ConsoleObserver> ob = std::make_shared<ConsoleObserver>(consObserv);

    for(auto& elem: monsters){
        elem->attach(ob);
    }
    OnceVisitor visitor;

    std::cout << "************Monsters************" << "\n"; 
    for (auto &n : monsters){
        n->print();
    }
    std::cout << "\n";

    int round = 1;
    for (size_t distance = 20; (distance <= 500) && !monsters.empty(); distance += 60){
        std::cout << "\n" << "----------------Round " << round << "----------------" << "\n" << "           !!!!_FIGHT_!!!!!       " << "\n";
        
        std::set<std::shared_ptr<NPC>> dead;
        for (const auto &attacker : monsters){
            for (const auto &defender : monsters){
                
                if ((attacker != defender) && (attacker->is_close(defender, distance))){
                    attacker->set_success(false);
                    defender->accept(attacker, visitor);

                    if (defender->get_success() == 1){
                        defender->notify(attacker.get(), true);
                        dead.insert(defender);
                    }
                }
            }
        }
        for (auto &d: dead){
            monsters.erase(d);
        }
        std::cout <<  "----------------Results----------------" << "\n" << "distance: " << distance << "\n" << "killed: " << dead.size() << "\n" << "\n";
        ++round;
    }

    std::cout << "\n" << "************Alive************" << "\n";
    for (auto &n : monsters){
        n->print();
    }
}