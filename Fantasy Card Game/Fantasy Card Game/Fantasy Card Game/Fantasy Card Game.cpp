// Assignment 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h> // Defines FILENAME_MAX
#include <direct.h> // Used for GetCurrentDir function
#include <sstream>
#include <vector>
#include "Card.h"
#include "Player.h"
#define GetCurrentDir _getcwd

using namespace std;

const int maxTurns = 30; // Sorceress always goes first
const int numberCardsSorceress = 34;
const int numberCardsWizard = 35;
const int playerHealth = 30;

//Member functions
void AddCardToDeck(vector<Card>&, int type, string name, int attack, int health);

int Random(const float n);

//Global hands
vector<Card> sorceressHand;
vector<Card> wizardHand;

int main()
{
    // Define size of program path size
    char programPath[FILENAME_MAX];

    // Get path of program
    GetCurrentDir(programPath, sizeof(programPath));

    string path = programPath;

    // Read decks from files
    ifstream fileSorceress(path + "/" + "sorceress.txt");
    ifstream fileWizard(path + "/" + "wizard.txt");

    // Creating vectors to hold lines of file
    vector <string> linesOfSorceress[numberCardsSorceress];
    string lineSorceress;
    vector <string> linesOfWizard[numberCardsWizard];
    string lineWizard;

    vector<Card> sorceressDeck;
    vector<Card> wizardDeck;

    // Put each string in from the file in the vector
    for (int i = 0; i < numberCardsSorceress; i++)
    {
        getline(fileSorceress, lineSorceress);
        if (lineSorceress.size() > 0)
        {
            linesOfSorceress[i].push_back(lineSorceress);
        }
    }

    for (int i = 0; i < numberCardsWizard; i++)
    {
        getline(fileWizard, lineWizard);
        if (lineWizard.size() > 0)
        {
            linesOfWizard[i].push_back(lineWizard);
        }
    }

    // Go through each line in the file and create cards accordingly
    for (int i = 0; i < numberCardsSorceress; i++)
    {
        for (string& line : linesOfSorceress[i])
        {
            std::stringstream ss;
            ss << line;

            std::string cardType;
            int stringToNumber;

            std::string linePart;
            while (getline(ss, linePart, ' '))
            {
                if (linePart == "Orc")
                {
                    AddCardToDeck(sorceressDeck, 1, "Orc", 2, 2);
                }
                if (linePart == "Goblin")
                {
                    AddCardToDeck(sorceressDeck, 1, "Goblin", 2, 1);
                }
                if (linePart == "Pooka")
                {
                    AddCardToDeck(sorceressDeck, 1, "Pooka", 2, 4);
                }
                if (linePart == "Thorns")
                {
                    AddCardToDeck(sorceressDeck, 1, "Thorns", 1, 4);
                }
                if (linePart == "Giant")
                {
                    AddCardToDeck(sorceressDeck, 1, "Giant", 4, 4);
                }
                if (linePart == "Dwarf")
                {
                    AddCardToDeck(sorceressDeck, 1, "Dwarf", 2, 4);
                }
                if (linePart == "Cannon")
                {
                    AddCardToDeck(sorceressDeck, 1, "Cannon", 4, 1);
                }
                if (linePart == "Swordswinger")
                {
                    AddCardToDeck(sorceressDeck, 1, "Swordswinger", 2, 2);
                }
                if (linePart == "Spearcarrier")
                {
                    AddCardToDeck(sorceressDeck, 1, "Spearcarrier", 2, 1);
                }
                if (linePart == "Elf")
                {
                    AddCardToDeck(sorceressDeck, 1, "Elf", 1, 4);
                }
            } 
        }
    }

    for (int i = 0; i < numberCardsWizard; i++)
    {
        for (string& line : linesOfWizard[i])
        {
            std::stringstream ss;
            ss << line;

            std::string cardType;
            int stringToNumber;

            std::string linePart;
            while (getline(ss, linePart, ' '))
            {
                if (linePart == "Orc")
                {
                    AddCardToDeck(wizardDeck, 1, "Orc", 2, 2);
                }
                if (linePart == "Goblin")
                {
                    AddCardToDeck(wizardDeck, 1, "Goblin", 2, 1);
                }
                if (linePart == "Pooka")
                {
                    AddCardToDeck(wizardDeck, 1, "Pooka", 2, 4);
                }
                if (linePart == "Thorns")
                {
                    AddCardToDeck(wizardDeck, 1, "Thorns", 1, 4);
                }
                if (linePart == "Giant")
                {
                    AddCardToDeck(wizardDeck, 1, "Giant", 4, 4);
                }
                if (linePart == "Dwarf")
                {
                    AddCardToDeck(wizardDeck, 1, "Dwarf", 2, 4);
                }
                if (linePart == "Cannon")
                {
                    AddCardToDeck(wizardDeck, 1, "Cannon", 4, 1);
                }
                if (linePart == "Swordswinger")
                {
                    AddCardToDeck(wizardDeck, 1, "Swordswinger", 2, 2);
                }
                if (linePart == "Spearcarrier")
                {
                    AddCardToDeck(wizardDeck, 1, "Spearcarrier", 2, 1);
                }
                if (linePart == "Elf")
                {
                    AddCardToDeck(wizardDeck, 1, "Elf", 1, 4);
                }
            }
        }
    }

    // Draw first card into the player's hand and display it
    sorceressHand.push_back(sorceressDeck[0]);
    cout << "Sorceress begins with: " << sorceressHand[0].GetName() << endl;;
    wizardHand.push_back(wizardDeck[0]);
    cout << "Wizard begins with: " << wizardHand[0].GetName() << endl;

    //Seeding the Random function
    srand(6);
    int randomValue1 = 0;
    int randomValue2 = 0;

    vector<Card> cardsOnTableSorceress;
    vector<Card> cardsOnTableWizard;

    char keyContinue;

    //Create the 2 players
    Player sorceress(playerHealth);
    Player wizard(playerHealth);

    //Go through all possible turns
    for (int i = 1; i <= maxTurns; i++)
    {
        cout << "Round " << i << endl;
        // Draw a new card
        sorceressHand.push_back(sorceressDeck[i]);
        wizardHand.push_back(wizardDeck[i]);

       //Sorceress' turn
       cout << "Sorceress draws " << sorceressDeck[i].GetName() << endl;
       randomValue1 = Random(1); // Choose a random number between 0 and 1
       cout << "Sorceress plays " << sorceressHand[randomValue1].GetName() << endl;
       cardsOnTableSorceress.push_back(sorceressHand[randomValue1]);

       //List all cards on the sorceress' table
       cout << "Cards on table: ";
       for (int n = 0; n < cardsOnTableSorceress.size(); n++)
       {
           cout << cardsOnTableSorceress[n].GetName() << "(" << cardsOnTableSorceress[n].GetHealth() << ") ";
       }

       cout << endl;

       //Choose wether to attack wizard
       for (int x = 0; x < cardsOnTableSorceress.size(); x++)
       {
           if (cardsOnTableWizard.empty())
           {
               wizard.SetHealth(wizard.GetHealth() - cardsOnTableSorceress[x].GetAttack());
               cout << cardsOnTableSorceress[x].GetName() << " attacks Wizard: Wizard health now " << wizard.GetHealth() << endl;
           }
           else
           {
               //Choose a random card from sorceress' cards on table to attack a random card from the wizard's cards on table
               randomValue1 = Random(cardsOnTableWizard.size()-1);
               randomValue2 = Random(cardsOnTableSorceress.size()-1);
               cardsOnTableWizard[randomValue1].SetHealth(cardsOnTableWizard[randomValue1].GetHealth() - cardsOnTableSorceress[randomValue2].GetHealth());
               cout << cardsOnTableSorceress[randomValue2].GetName() << " attacks " << cardsOnTableWizard[randomValue1].GetName() << ": ";
               if (cardsOnTableWizard[randomValue1].GetHealth() <= 0)
               {
                   cout << cardsOnTableWizard[randomValue1].GetName() << " killed" << endl;
                   cardsOnTableWizard.erase(cardsOnTableWizard.begin() + randomValue1); // Erase card from table
               }
               else cout << cardsOnTableWizard[randomValue1].GetName() << " health now " << cardsOnTableWizard[randomValue1].GetHealth() << endl;
           }
       }

       //Wizard's turn
       cout << endl;
       cout << "Wizard draws " << wizardDeck[i].GetName() << endl;
       randomValue1 = Random(1); // Choose a random number between 0 and 1
       cout << "Wizard plays " << wizardHand[randomValue1].GetName() << endl;
       cardsOnTableWizard.push_back(wizardHand[randomValue1]);

       //List all cards on the wizard's table
       cout << "Cards on table: ";
       for (int n = 0; n < cardsOnTableWizard.size(); n++)
       {
           cout << cardsOnTableWizard[n].GetName() << "(" << cardsOnTableWizard[n].GetHealth() << ") ";
       }

       cout << endl;

       //Choose wether to attack sorceress
       for (int x = 0; x < cardsOnTableWizard.size(); x++)
       {
           if (cardsOnTableSorceress.empty())
           {
               sorceress.SetHealth(sorceress.GetHealth() - cardsOnTableWizard[x].GetAttack());
               cout << endl << cardsOnTableWizard[x].GetName() << " attacks Sorceress: Sorceress health now " << sorceress.GetHealth() << endl;
           }
           else
           {
               //Choose a random card from wizards cards on table to attack a random card from the sorceress' cards on table
               randomValue1 = Random(cardsOnTableSorceress.size()-1);
               randomValue2 = Random(cardsOnTableWizard.size()-1);
               cardsOnTableSorceress[randomValue1].SetHealth(cardsOnTableSorceress[randomValue1].GetHealth() - cardsOnTableWizard[randomValue2].GetHealth());
               cout << cardsOnTableWizard[randomValue2].GetName() << " attacks " << cardsOnTableSorceress[randomValue1].GetName() << ": ";
               if (cardsOnTableSorceress[randomValue1].GetHealth() <= 0)
               {
                   cout << cardsOnTableSorceress[randomValue1].GetName() << " killed" << endl;
                   cardsOnTableSorceress.erase(cardsOnTableSorceress.begin() + randomValue1); // Erase card from table
               }
               else
                   cout << cardsOnTableSorceress[randomValue1].GetName() << " health now " << cardsOnTableSorceress[randomValue1].GetHealth() << endl;
           }
       }

       cout << "Enter any key to continue" << endl;
       cin >> keyContinue;

       //Win conditions
       if (wizard.GetHealth() <= 0)
       {
           cout << endl << "Sorceress won!" << endl;
           break;
       }

       if (sorceress.GetHealth() <= 0)
       {
           cout << endl << "Wizard won!" << endl;
           break;
       }
    }


}

void AddCardToDeck(vector<Card>& myDeck, int type, string name, int attack, int health)
{
    //Create a new class instance
    Card newCard(type, name, attack, health);
    //Add card to deck
    myDeck.push_back(newCard);
}

int Random(const float n)
{
    return static_cast<int>(static_cast<double> (rand()) / (RAND_MAX + 1) * (n + 1));
}