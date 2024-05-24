// Pure Virtual Functions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

class Printable
{
public:
    virtual std::string GetClassName() = 0;
    // This needs to be implemented in a subclass to be used
    // =0 makes it a pure virtual function
};

class Entity : public Printable
{
public:
    virtual std::string GetName() { return "Entity"; }
    std::string GetClassName() override { return "Entity"; }
};


class Player : public Entity
{
private:
    std::string m_Name; // Store a name
public:
    Player(const std::string& name) // constructor to specify name
        : m_Name(name) {}           //

    std::string GetName() override { return m_Name; }
    std::string GetClassName() override { return m_Name; }
};

void Print(Printable* object)
{
    std::cout << object->GetClassName() << std::endl;
}

int main()
{

    Entity* entity = new Entity;

    Player* player = new Player("testboi");

    Print(entity);
    Print(player);

    std::cin.get();
}

// Notes:
/*
Printable is the parent of Entity which is the parent of Player
Entity would override any functions of Printable
Player would override any functions with the same name of both Printable and Entity

Printable is technically a class but acts exactly as an interface
*/
