# Лабораторная 6
# Кайдалова Александра, М8О-212Б-22, Вариант 10
## Тема: Паттерны проектирования
### Цель: 
1. Закрепление паттернов SOLID
#### Требования к программе:
Вы разрабатываете редактор подземелья для новой RPG игры Balagur Fate 3. Ваша задача сделать
программу, которая позволит моделировать базовые локации, расставляя на них NPC (non-player
characters).
Редактор должен позволять делать следующие действия:
1. Добавлять новые NPC по разным координатам (типы объектов предопределены заданием)
a. NPC размещаются в квадрате 0<=x<=500 метров, 0<=y<=500 метров
b. У каждого типа объекта помимо координат должно быть уникальное имя.
2. Сохранять объекты в файл и загружать из файла
3. Печатать перечень объектов на экран (с типом объектов, координатами и именем)
4. Запускать боевой режим с указанием дальности, на которой могут сражаться NPC. В
боевом режиме NPC начинают сражаться каждый с каждым (если дальность позволяет),
проигравший NPC – удаляется. При этом погибнуть могут и оба NPC.
При создании программы обязательно использовать паттерны:
- Какой-нибудь из вариантов Factory для создания NPC и загрузки NPC из файла
- Visitor – для проведения цикла сражения
- Observer – для печати событий о совершенных убийствах. Сделать два класса Observer – для
записи в файл “log.txt” и для печати на экран.
#### Вариант 10: 
Разбойник, Орк, Оборотень:
1. Разбойник убивает оборотней
2. Оборотень убивает разбойника
3. Орк убивает разбойника

#### main.cpp
```cpp
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
```
#### factory.h
```cpp
#pragma once

#include "npc.h"
#include "outlaw.h"
#include "orc.h"
#include "werewolf.h"

int outlaws = 0;
int orcs = 0;
int werewolfs = 0;

std::shared_ptr<NPC> factory(NpcType type, int x, int y){
    std::shared_ptr<NPC> result;
    std::string name;
    switch (type){

    case OutlawType:
        ++outlaws;
        name = "Outlaw_" + std::to_string(outlaws);
        result = std::make_shared<Outlaw>(x, y, name);
        break;

    case OrcType:
        ++orcs;
        name = "Orc_" + std::to_string(orcs);
        result = std::make_shared<Orc>(x, y, name);
        break;

    case WerewolfType:
        ++werewolfs;
        name = "Werewolf_" + std::to_string(werewolfs);
        result = std::make_shared<Werewolf>(x, y, name);
        break;

    default:
        break;
    }
    return result;
}

// Для файла
std::shared_ptr<NPC> factory(std::ifstream &is){
    std::shared_ptr<NPC> result;
    std::string name;
    int type = 0;
    if (is >> type){
        switch (type){

        case OutlawType:
            ++outlaws;
            name = "Outlaw_" + std::to_string(outlaws);
            result = std::make_shared<Outlaw>(is, name);
            break;

        case OrcType:
            ++orcs;
            name = "Orc_" + std::to_string(orcs);
            result = std::make_shared<Orc>(is, name);
            break;

        case WerewolfType:
            ++werewolfs;
            name = "Werewolf_" + std::to_string(werewolfs);
            result = std::make_shared<Werewolf>(is, name);
            break;
        }
    }
    else
        std::cerr << "File error." << "\n";

    return result;
}
```
#### npc.h
```cpp
#pragma once

#include <iostream>
#include <memory>
#include <cstring>
#include <string>
#include <random>
#include <fstream>
#include <set>
#include <math.h>
#include "observer.h"

class Outlaw;
class Orc;
class Werewolf;
enum NpcType{
    Unknown, OutlawType, OrcType, WerewolfType
};

class Visitor;

class NPC{
public:
    NpcType type;
    int x = 0;
    int y = 0;
    std::string name;
    std::vector<std::shared_ptr<FightObserver>> observers;
    bool success = false;

    NPC() = default;
    ~NPC() = default;
    NPC(NpcType t, int x, int y, std::string& name);
    NPC(NpcType t, std::ifstream& is, std::string& name);

    void set_success(bool value) {
        success = value;
    }
    bool get_success() const {
        return success;
    }

    bool is_close(const std::shared_ptr<NPC>& other, size_t distance) const;
    void notify(NPC* attacker, bool win);
    virtual void save(std::ofstream& os);
    virtual void print() = 0;
    virtual void get_name(std::ofstream& os) = 0;
    virtual void accept(std::shared_ptr<NPC> attacker, Visitor& visitor) = 0;
    virtual void attach(std::shared_ptr<FightObserver> observer) = 0;
    virtual void detach(std::shared_ptr<FightObserver> observer) = 0;

    friend std::ostream& operator<<(std::ostream& os, NPC& npc);
};
```
#### npc.cpp
```cpp
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
```
#### outlaw.h
```cpp
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
```
#### outlaw.cpp
```cpp
#include "outlaw.h"
#include "visitor.h"
#include <algorithm>

void Outlaw::save(std::ofstream& os){
    os << OutlawType << "\n";
    NPC::save(os);
}

void Outlaw::print(){
    std::cout << *this;
}

void Outlaw::get_name(std::ofstream& os){
    os << this->name << ": x = " << this->x << "; y = " << this->y << "\n";
}

void Outlaw::accept(std::shared_ptr<NPC> attacker,Visitor& visitor) {
    int res1 = 0;
    if(dynamic_cast<Orc*>(attacker.get()))
        res1 = visitor.visit(dynamic_cast<Orc*>(attacker.get()));
    
    if(res1 == 2) success = true;

    int res2 = 0;
    if(dynamic_cast<Werewolf*>(attacker.get()))
        res2 = visitor.visit(dynamic_cast<Werewolf*>(attacker.get()));
    
    if(res2 == 3) success = true;
}

void Outlaw::attach(std::shared_ptr<FightObserver> observer){
    NPC::observers.push_back(observer);
}

void Outlaw::detach(std::shared_ptr<FightObserver> observer){
    NPC::observers.erase(std::find(NPC::observers.begin(), NPC::observers.end(), observer));
}

std::ostream& operator<<(std::ostream& os, Outlaw& outlaw){
    os << *static_cast<NPC*>(&outlaw);
    return os;
}
```
#### orc.h
```cpp
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
```
#### orc.cpp
```cpp
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
```
#### werewolf.h
```cpp
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
```
#### werewolf.h
```cpp
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
```
#### observer.h
```cpp
#pragma once

#include <iostream>
#include <memory>
#include <fstream>

class NPC;

class FightObserver{
public:
    FightObserver() = default;
    ~FightObserver() = default;
    virtual void update(NPC* defender, NPC* attacker, bool win) = 0;
}; 

class ConsoleObserver: public FightObserver{
public:
    ConsoleObserver() = default;
    ~ConsoleObserver() = default;
    void update(NPC* defender, NPC* attacker, bool win) override;
};

class FileObserver: public FightObserver{
public:
    std::ofstream in;
    std::string filename;
    FileObserver() = default;
    FileObserver(std::string& filename);
    FileObserver(FileObserver& other){}
    FileObserver(FileObserver&& other){}
    ~FileObserver();
    void update(NPC* defender, NPC* attacker, bool win) override;
};
```
#### observer.cpp
```cpp
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
```
#### visitor.h
```cpp
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
```