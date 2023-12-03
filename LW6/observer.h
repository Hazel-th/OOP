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