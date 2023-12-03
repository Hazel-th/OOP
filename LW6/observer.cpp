#include "observer.h"
#include "npc.h"

void ConsoleObserver::update(NPC* defender, NPC* attacker, bool win){
    if (win == 0) return;

    std::cout << "\n" << "-----KILL----- " << "\n";
    defender->print();
    std::cout << "was killed by " << "\n";
    attacker->print();
    std::cout << "\n";
}

FileObserver::FileObserver(std::string& filename){
    this->filename = filename;
    in.open(filename);
}

FileObserver::~FileObserver(){
    in.close();
}

void FileObserver::update(NPC* defender, NPC* attacker, bool win){
    if (in.is_open()){
        if (win) {
            in << "\n" << "-----KILL----- " << "\n";
            defender->print();
            in << "was killed by " << "\n";
            attacker->print();
            in << "\n";
        }
    }
    else{
        std::cerr << "File error." << "\n";
    }
}