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