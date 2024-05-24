// Virtual Functions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

// GetName() function ----> Returns all information related to 
//                          the name of an attribute at a given index

class Entity
{
public:
    // virtual --> If function is overridden you can point to the correct funtion
    // Otherwise this would return "Entity" twice
    virtual std::string GetName() { return "Entity"; } // Return "Entity"
};


class Player : public Entity // Subclass of Entity class (Player is an Entity)
{
private:
    std::string m_Name; // Store a name
public:
    Player(const std::string& name) // constructor to specify name
        : m_Name(name) {}           //

    std::string GetName() override { return m_Name; } // Return the name
    // override is not necessary but helps with readability
};

void PrintName(Entity* entity)
{
    std::cout << entity->GetName() << std::endl;
}

int main()
{
    // Print out "Entity"
    Entity* entity = new Entity(); // Create instance of class Entity
    PrintName(entity);

    // Specify and print out the player's name
    Player* player = new Player("testboi");
    PrintName(player);

    Entity* entity2 = player; // Pointer to a player type
                              // It's actually an instance of Player class
    std::cout << entity2->GetName() << std::endl; // Would expect to print out player name
                                                  // Prints out "Entity" instead

    std::cin.get(); // Pause the program and allow user to type
}

// Notes:
/*
Virtual functions work a lot like interfaces in other languages
Whatever is marked by virtual can be overridden

Player is a subclass of Entity: meaning it's both an Entity and a Player
Subclasses inherit public information from parent class ( Entity ):
    -variables
    -functions
Everything in private or protected of parent class would be ignored
The Player subclass can call functions belonging to Entity class

Polymorphism refers to using the Player class as both a Player class and an Entity class
*/