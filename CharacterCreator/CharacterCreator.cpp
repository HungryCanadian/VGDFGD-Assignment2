// CharacterCreator.cpp :
// VGDFGD Assignment 2
// By Jonathon Cannon

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::string;
using std::vector;

int chosenRace;
int chosenClass;

// Struct for races
struct abilityScores {
    int strength;
    int dexterity;
    int constitution;
    int intelligence;
    int wisdom;
    int charisma;

    abilityScores(int str, int dex, int con, int intl, int wis, int cha)
        : strength(str), dexterity(dex), constitution(con), intelligence(intl), wisdom(wis), charisma(cha) {}

    // Method to apply racial bonuses
    void applyRaceBonuses(const abilityScores& raceBonus) {
        strength += raceBonus.strength;
        dexterity += raceBonus.dexterity;
        constitution += raceBonus.constitution;
        intelligence += raceBonus.intelligence;
        wisdom += raceBonus.wisdom;
        charisma += raceBonus.charisma;
    }

};
struct Class {
    string name;
};
struct Race {
    string name;
    abilityScores abilityIncrease;

    Race(const string& raceName, int strBonus, int dexBonus, int conBonus, int intlBonus, int wisBonus, int chaBonus)
        : name(raceName), abilityIncrease(strBonus, dexBonus, conBonus, intlBonus, wisBonus, chaBonus) {}
};
class Character {
public:
    string name;
    Race race;
    Class type;
    abilityScores baseScores;

    Character(const string& characterName, const Race& characterRace, const Class& characterClass,  const abilityScores& scores)
        : name(characterName), race(characterRace), type(characterClass), baseScores(scores) {
        baseScores.applyRaceBonuses(race.abilityIncrease);
    }

    void displayStats() const {
        cout << "Character: " << name << "\n";
        cout << "Race: " << race.name << "\n";
        cout << "Class: " << type.name << "\n";
        cout << "Ability Scores:\n";
        cout << "Strength: " << baseScores.strength << "\n";
        cout << "Dexterity: " << baseScores.dexterity << "\n";
        cout << "Constitution: " << baseScores.constitution << "\n";
        cout << "Intelligence: " << baseScores.intelligence << "\n";
        cout << "Wisdom: " << baseScores.wisdom << "\n";
        cout << "Charisma: " << baseScores.charisma << "\n";
    }
};

    // Races
    vector<Race> races = {
        { "dwarf", 0, 0, 2, 0, 0, 0},
        { "Elf", 0, 2, 0, 0, 0, 0},
        { "Halfling",0, 2, 0, 0, 0, 0},
        { "Human", 0, 0, 1, 0, 2, 0},
        { "Gnome", 0, 0, 0, 0, 0, 0},
        { "Tiefling", 0, 0, 0, 0, 0, 0}
    };
    
    vector<Class> charClass = {
        { "Fighter" },
        { "Paladin" },
        { "Druid" },
        { "Warlock" },
        { "Sorceror" },
        { "Wizard" },
        { "Ranger" }
    };


int main()
{
    cout << "RPG Character Creator\n";
    cout << "Welcome to the world of Caspira, Let's get your new character made!\n";
 
    while (true) {
        system("cls");
        cout << "RPG Character Creator\n";
        cout << "Welcome to the world of Caspira, Let's get your new character made!\n";
    string characterName;
    while (true) {
        cout << "Enter your character's name (1-10 characters): ";
        cin >> characterName;

        if (characterName.empty() || characterName.length() > 10) {
            cout << "Invalid name. Name must be between 1 and 10 characters.\n";
        }
        else {
            break; // Valid name, exit the loop
        }
    }


    // Choose a race
    while (true) {
        cout << "Races:\n[1]Dwarf\n[2]Elf\n[3]Halfling\n[4]Human\n[5]Gnome\n[6]Tiefling\n\n";
        cout << "Please choose a Race (1-" << races.size() << "): ";
        cin >> chosenRace;

        if (chosenRace < 1 || chosenRace > races.size()) {
            cout << "Invalid choice. Please try again.\n";
        }
        else {
            chosenRace--; // Adjust for zero being #1
            break; // Valid choice, exit the loop
        }
    }

    // Choose a class
    while (true) {
        cout << "Classes:\n[1]Fighter\n[2]Paladin\n[3]Druid\n[4]Warlock\n[5]Sorcerer\n[6]Wizard\n[7]Ranger\n\n";
        cout << "Please choose a Class (1-" << charClass.size() << "): ";
        cin >> chosenClass;

        if (chosenClass < 1 || chosenClass > charClass.size()) {
            cout << "Invalid choice. Please try again.\n";
        }
        else {
            chosenClass--; // Adjust for zero
            break; // Valid choice, exit the loop
        }
    }


    abilityScores playerScores(0, 0, 0, 0, 0, 0);
    while (true) {
        cout << "Enter your ability scores (8-18):\n";
        cout << "Strength: "; 
        cin >> playerScores.strength;
        cout << "Dexterity: "; 
        cin >> playerScores.dexterity;
        cout << "Constitution: "; 
        cin >> playerScores.constitution;
        cout << "Intelligence: "; 
        cin >> playerScores.intelligence;
        cout << "Wisdom: "; 
        cin >> playerScores.wisdom;
        cout << "Charisma: "; 
        cin >> playerScores.charisma;

        // Validate ability scores
        if (playerScores.strength < 8 || playerScores.strength > 18 ||
            playerScores.dexterity < 8 || playerScores.dexterity > 18 ||
            playerScores.constitution < 8 || playerScores.constitution > 18 ||
            playerScores.intelligence < 8 || playerScores.intelligence > 18 ||
            playerScores.wisdom < 8 || playerScores.wisdom > 18 ||
            playerScores.charisma < 8 || playerScores.charisma > 18) {
            cout << "All ability scores must be between 8 and 18. Please try again.\n";
        }
        else {
            break; // Valid scores, exit the loop
        }
    }


    // Apply race bonuses to base ability scores
    //playerScores.applyRaceBonuses(races[chosenRace].abilityIncrease);

    // Display updated ability scores
    /*cout << "\n\nYour Ability Scores for " << races[chosenRace].name << ":\n";
    cout << "Strength: " << playerScores.strength << "\n";
    cout << "Dexterity: " << playerScores.dexterity << "\n";
    cout << "Constitution: " << playerScores.constitution << "\n";
    cout << "Intelligence: " << playerScores.intelligence << "\n";
    cout << "Wisdom: " << playerScores.wisdom << "\n";
    cout << "Charisma: " << playerScores.charisma << "\n\n\n";*/

    // Create character
    Character playerCharacter(characterName, races[chosenRace], charClass[chosenClass], playerScores);

    cout << "\n\n";
    playerCharacter.displayStats();

    // Ask if they want to create another character
    cout << "\nWould you like to create another character? (y/n): ";
    char continueChoice;
    cin >> continueChoice;

    if (continueChoice != 'y' && continueChoice != 'Y') {
        break; // Exit the loop
    }
}

cout << "Thank you for using the Caspiran Character Creator!\n";
return 0;
}