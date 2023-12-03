#include <gtest/gtest.h>
#include <memory>
#include "npc.h"
// #include "outlaw.h"
// #include "orc.h"
// #include "werewolf.h"
#include "visitor.h"
#include "observer.h"

TEST(test1, constructor){
    int x = 55;
    int y = 10;
    std::string name{"outlaw_1"};
    std::shared_ptr<NPC> outlaw = std::make_shared<Outlaw>(x,y,name);

    EXPECT_EQ(55, outlaw->x);
    EXPECT_EQ(10, outlaw->y);
    EXPECT_EQ("outlaw_1", outlaw->name);
}

TEST(test2, constructor){
    int x = 30;
    int y = 120;
    std::string name{"orc_1"};
    std::shared_ptr<NPC> orc = std::make_shared<Orc>(x,y,name);

    EXPECT_EQ(30, orc->x);
    EXPECT_EQ(120, orc->y);
    EXPECT_EQ("orc_1", orc->name);
}

TEST(test3, constructor){
    int x = 5;
    int y = 1;
    std::string name{"werewolf_1"};
    std::shared_ptr<NPC> werewolf = std::make_shared<Werewolf>(x,y,name);

    EXPECT_EQ(5, werewolf->x);
    EXPECT_EQ(1, werewolf->y);
    EXPECT_EQ("werewolf_1", werewolf->name);
}

TEST(test4, fight){

    OnceVisitor visitor;

    int x1 = 100;
    int y1 = 100;
    std::string name1{"outlaw_1"};
    std::shared_ptr<NPC> attacker = std::make_shared<Outlaw>(x1, y1, name1);

    int x2 = 101;
    int y2 = 101;
    std::string name2{"werewolf_1"};
    std::shared_ptr<NPC> defender = std::make_shared<Werewolf>(x2, y2, name2);

    int success = true;
    defender->accept(attacker, visitor);

    EXPECT_TRUE(success);
}

TEST(test5, fight){

    OnceVisitor visitor;

    int x1 = 100;
    int y1 = 100;
    std::string name1{"outlaw_1"};
    std::shared_ptr<NPC> attacker = std::make_shared<Outlaw>(x1, y1, name1);

    int x2 = 200;
    int y2 = 250;
    std::string name2{"werewolf_1"};
    std::shared_ptr<NPC> defender = std::make_shared<Werewolf>(x2, y2, name2);

    int success = false;
    defender->accept(attacker, visitor);
    
    EXPECT_FALSE(success);
}

TEST(test6, fight){

    OnceVisitor visitor;

    int x1 = 100;
    int y1 = 100;
    std::string name1{"outlaw_1"};
    std::shared_ptr<NPC> attacker = std::make_shared<Outlaw>(x1, y1, name1);

    int x2 = 110;
    int y2 = 100;
    std::string name2{"orc_1"};
    std::shared_ptr<NPC> defender = std::make_shared<Orc>(x2, y2, name2);

    int success = false;
    defender->accept(attacker, visitor);
    
    EXPECT_FALSE(success);
}

TEST(test7, fight){

    OnceVisitor visitor;

    int x1 = 100;
    int y1 = 100;
    std::string name1{"werewolf_1"};
    std::shared_ptr<NPC> attacker = std::make_shared<Werewolf>(x1, y1, name1);

    int x2 = 110;
    int y2 = 100;
    std::string name2{"orc_1"};
    std::shared_ptr<NPC> defender = std::make_shared<Orc>(x2, y2, name2);

    int success = false;
    defender->accept(attacker, visitor);
    
    EXPECT_FALSE(success);
}