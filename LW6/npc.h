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