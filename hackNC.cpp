 /*
 HackNC
 Dungeon Escape Game
 
 Luke Pearson
 Brice Hamlett
 Quinn Cerino
 */
 
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;


// Door Options
void env1 ();
void env2 ();
void env3 ();
void env4 ();
void env5 ();
void env6 ();
void env7 ();
void env8 ();
void env9 ();
void env10 ();

// Riddle Options
void rid1 ();
void rid2 ();
void rid3 ();
void rid4 ();
void rid5 ();
void randomrid(bool& rid);


void randomize(bool& alive); 
// Randomize Door 1 Output (1-5 options)

void weapon(int& items);
// has a chance to add a weapon to the inventory


const int MAXCHARACTERS = 50;


char inventory[MAXCHARACTERS];
int arr[10] = {0};
int items = 0;


char choice;
bool alive = true;
int survived = 0;


int main()
{
    srand(time(0));
    int goal = rand() % 11 + 5; 

    string name;
    int number;

    cout << "Welcome to the Dungeon Escape Game!\n";
    cout << "What is your name weary traveler?: ";
    cin >> name;

    cout << name << ", you are trapped in a dark dungeon. You must survive through " << goal 
    << " doors in order to escape! There are 2 doors in front of you." 
    << " Do you want to enter door 1 or 2? ";
    cin >> number;
    

    while (alive == true && survived < goal)
    {
       
        randomize(alive);
        survived++;


    }
    
    if (survived == goal)
    {
        cout << "\nCongratulations, " << name << ", you escaped!" << endl;
    }

    return 0;
}

// Creates a random number correlating to the riddles (option 9)
void randomrid()
{
    int rid = rand() % 5 + 1;
    if (arr[rid - 1] == 0)
    {
        
        switch (rid)
        {
            case 1:
                rid1();
                break;
            
            case 2:
                rid2();
                break;
            
            case 3:
                rid3();
                break;
            
            case 4:
                rid4();
                break;

            case 5:
                rid5();
                break;

            default:
            cout << "Uh oh, Spaghett!";
            break;

        }
    }
}

// Creates a radnom number correlated to a potential room
// 
void randomize(bool& alive)
{
    int num = rand() % 10 + 1;
    if (arr[num - 1] == 0)
    {
        weapon(items);
        switch (num)
        {
            case 1:
                env1();
                break;

            case 2:
                env2();
                break;

            case 3:
                env3();
                break;

            case 4:
                env4();
                break;

            case 5:
                env5();
                break;
                
            case 6:
                env6();
                break;
                
            case 7:
                env7();
                break;

            case 8:
                env8();
                break;
                
            case 9:
                env9();
                break;

            case 10:
                env10();
                break;

        default:
            cout << "Uh oh, Spaghett!";
            break;
        }
        arr[num - 1]++;
    } 
    else
    for (int index = 0; index < 10; index++)
    {
        if (arr[index] == 0)
        survived--;
    }
    
    
}

// Door Option 1
void env1()
{
    cout << "\nNARRATOR: You open the door and walk into a room with a volcanic pool of lava. "
    << "\nFrom the lava, a monster mixed with lava and rock appears in a large humanoid figure. You must choose to run (R) or fight (F). " << endl;

    if (items > 0)
    {
        cout << "You may also choose to use " << inventory << " (i): " << endl;
    }

    cin >> choice;
        
    if (choice == 'R' || choice == 'r')
    {
        cout<< "\nYou tried to outrun the lava monster and he splashed your back with lava. You burn to death." << endl;
        alive = false;
    }
    else if (choice == 'F' || choice == 'f')
    {
        cout<< "\nYou grab a sharp rock from beside the lava pool and chuck it at the lava monster. You successfully hit it right in the eye, blinding and injuring it." 
        << "\nThis gives you time to run past it, and you come to a new room." << endl;
        
    }
    else if (choice == 'I' || choice == 'i')
    {
        cout << "\nYou used your item to win, good job being resourceful!";
        inventory[0] = '\0';
        items--;

    }
    
}

// Door Option 2
void env2 ()
{   
    cout << "\nNARRATOR: You open the door to find a pitch black room. You suddenly feel a breath hit the back of your neck. You freeze in a panic. You realize you only have two options:"
    << "\nTurn and fight or run away. You must choose to run (R) or fight (F): \n";
   
    if (items > 0)
    {
        cout << "You may also choose to use " << inventory << " (i): " << endl;
    }

    cin >> choice;
    if (choice == 'F' || choice == 'f')
    {
        cout << "\nYou turn around to fight and you feel a knife go through your chest. You die." << endl;
        alive = false;
    }
    if (choice == 'R' || choice == 'r')
    {
        cout << "\nYou decide to run straight ahead of you, hoping you don't run into a wall. You manage to find a light switch. You flip it and the light turns on,"
        << " revealing that there is nothing in the room." << endl;
    }
       else if (choice == 'I' || choice == 'i')
    {
        cout << "\nYou used your item to win, good job being resourceful!";
        inventory[0] = '\0';
        items--;

    }
    
    
}   

// Door Option 3
void env3 ()
{
    cout << "\nNARRATOR:You open the door to reveal a strange sight. Before you is another person. The room reminds you of the same one that you woke up in."
        << "\nYou get a bad premonition as the doors behind you close and a voice whispers, \"Welcome to the Escape The Dungeon Game.\""
        << "\nThe voice finally acknowledges you: \"Oh, I see another player has entered! Very well then. You all must fight, and the winner advances to the next room." << endl;

    cout << "\nWhen you fight, you have the choice of either a sword (S) or a gun (G) and your opponent will recieve the other: " << endl;
    
    

    if (items > 0)
    {
        cout << "You may also choose to use " << inventory << " (i): " << endl;
    }

    cin >> choice;
    if (choice == 'S' || choice == 's')
    {
        cout << "\nYou choose the sword. Good for you, because the gun had no bullets, and you win the fight." << endl;

    }
    else if (choice == 'g' || choice == 'G')
    {
        cout << "'\nSmart decision, you would live ... however the gun has no bullets."
            << "\nYour morality has gotten you killed" << endl;
        alive = false;
    }
       else if (choice == 'I' || choice == 'i')
    {
        cout << "\nYou used your item to win, good job being resourceful!";
        inventory[0] = '\0';
        items--;
    }
}

// Door Option 4
void env4 ()
{
    cout << "\nNARRATOR: You open the door to a zombie apocalypse! If you're touched by a zombie, you will become infected and die. "
        << "\nYou have the choice to fight (F) and try to kill off the zombies, or run away (R): " << endl;

    if (items > 0)
    {
       cout << "You may also choose to use " << inventory << " (i): " << endl;
    }

    cin >> choice;

    if (choice == 'F' || choice == 'f')
    {
        cout << "\nYou decide to fight. You pick up a nearby knife. As you try to stab a zombie, another zombie comes behind you"
            << "\nand grabs your arm, and you become infected and die." << endl;
        alive = false;
    }
    else if (choice == 'R' || choice == 'r')
    {
        cout << "\nYou decide to run. Zombies are extremely slow with low IQ, so you are able to outrun them. You come to another door." << endl;
    }
       else if (choice == 'I' || choice == 'i')
    {
        cout << "\nYou used your item to win, good job being resourceful!";
        inventory[0] = '\0';
        items--;
    }
}

// Door Option 5
void env5 ()
{
    cout << "\nNARRATOR: You open the door to a giant tarantula spider. It shoots venomous spiderwebs out of its eyes if you make eye contact with it. "
        << "\nIt is blocking the next door, and you must find a way to move past it safely. You must search around the room for something to help you. "
        << "\nYou see a broken pair of sunglasses (S) and a piece of metal (M). Which do you choose to pick up?: " << endl;

    if (items > 0)
    {
       cout << "You may also choose to use " << inventory << " (i): " << endl;
    }

    cin >> choice;

    if (choice == 'S' || choice == 's')
    {
        cout << "\nYou pick up the pair of sunglasses and put them on. One of the dark glass lenses is broken, so you are careful to keep that eye shut. "
            << "\nYou are able to successfully maneuver past the spider and come to the next door." << endl;
    }
    else if (choice == 'M' || choice == 'm')
    {
        cout << "\nYou pick up the piece of metal, hoping to use it as a barrier between you and the spider as you move past. The metal is rusty and you accidentally cut yourself."
            << "\nYou get blood poisoning and die. " << endl;
        alive = false;
    }
    else if (choice == 'I' || choice == 'i')
    {
        cout << "\nYou used your item to win, good job being resourceful!";
        inventory[0] = '\0';
        items--;
    }
}

// Door Option 6
void env6 ()
{
    cout << "\nNARRATOR: You open the door to a gym hosting a hackathon. You have 24 hours to code something to my liking."
    << "\nYou can either code a text based game (T) or a VR game (V): " << endl;
      if (items > 0)
    {
        cout << "You may also choose to use " << inventory << " (i): " << endl;
    }
    cin >> choice;

    if (choice == 'T' || choice == 't')
    {
        cout << "\nYou choose to code a text based game, and the code was perfect. You move to the next room!" << endl;
    }
    if (choice == 'V' || choice == 'v')
    {
        cout << "\nYou choose to code a VR game, and the code was horrendous. You die." << endl;
        alive = false;
    }
     else if (choice == 'I' || choice == 'i')
    {
        cout << "\nYou used your item to win, good job being resourceful!";
        inventory[0] = '\0';
        items--;
    }
}

// Door Option 7
void env7 ()
{
    cout << "\nNARRATOR: You walk into a normal looking room. In the room, you see a stranger smiling and waving with a cooler next to him."
        << "\nHe states, \"Yo, whats good bro? I got lost down here and the next room looks very difficult to get through. You want something to drink? It may help you for the next room.\" (Y or N): " << endl;
      if (items > 0)
    {
        cout << "You may also choose to use " << inventory << " (i): " << endl;
    }
    
    cin >> choice; 
    
    if (choice == 'y' || choice == 'Y')
    {
        cout << "\nThe drink was poisoned. Maybe don't trust strangers... you die" << endl;
        alive = false;
    }
    if (choice == 'n' || choice == 'N')
    {
        cout <<"\nIgnoring the kind stranger was a smart decision, because the drink was poisoned! You move onto the next door." << endl;
    }
     else if (choice == 'I' || choice == 'i')
    {
        cout << "\nYou used your item to win, good job being resourceful!";
        inventory[0] = '\0';
        items--;
    }
}


// Door Option 8
void env8 ()
{
    cout << "\nNARRATOR: You walk into a room and see a clown on a unicycle. It is juggling what appears to be water balloons. "
    << "But in reality, they are filled with acid. As he prepares to throw them at you, you can choose an object nearby to help you dodge the balloons."
    << "Do you choose a knife (K) or a shield (S)?: " << endl;
    if (items > 0)
    {
        cout << "You may also choose to use " << inventory << " (i): " << endl;
    }
    cin >> choice;

    if (choice == 'K' || choice == 'k')
    {
        cout << "\nWhile this seems like a great idea in theory, when you stab the balloons as they fly at you, the acid splashes on you and burns your skin and you die." << endl;
        alive = false;
    }

    else if (choice == 'S' || choice == 's')
    {
        cout << "\nYou are able to block the incomming balloons with the shield and they fall and explode on the ground, not splashing you. Once the clown is out of balloons,"
            << " you sprint away and come to the next door." << endl;
    }
     else if (choice == 'I' || choice == 'i')
    {
        cout << "\nYou used your item to win, good job being resourceful!";
        inventory[0] = '\0';
        items--;
    }
        
}

// Door Option 9
void env9 ()
{
    string answer;
    cout << "\nNARRATOR: You walk into the next room. There is a riddle written on the wall, and you must solve it to leave. ";
    randomrid();
    
}

// Door Option 10
void env10 ()
{
    cout << "\nNARRATOR: You walk into the next room and find a giant fish tank/aquarium. The tank is filled with chomping hungry piranhas. "
        << "There are two paths to the next door: right or left. One of the paths let you pass safely, and the other path opens the tank, releasing the piranhas on you. "
        << "Which do you choose? L or R: " << endl;
    if (items > 0)
    {
        cout << "You may also choose to use " << inventory << " (i): " << endl;
    }
    cin >> choice;

    if (choice == 'L' || choice == 'l')
    {
        cout << "Wrong choice! The tank opens and you're eaten by piranhas." << endl;
        alive = false;
    }

    else if (choice == 'R' || choice == 'r')
    {
        cout << "Correct choice! You pass safely and journey to the next door." << endl;
    }
     else if (choice == 'I' || choice == 'i')
    {
        cout << "\nYou used your item to win, good job being resourceful!";
        inventory[0] = '\0';
        items--;
    }
}

// Riddle Option 1
void rid1()
{
    string rid;
    cout << "What goes up but never comes down?: ";
    cin >> rid;

    if (rid == "Age" || rid == "age")
    {
        cout << "Correct! You may choose another door!" << endl;
    }
    else
    {
        cout << "Wrong! You die." << endl;
        alive = false;
    }
}

void rid2 ()
{
    string rid;
    cout << "I have one eye but am unable to see. What am I?: ";
    cin >> rid;

    if (rid == "Needle" || rid == "needle")
    {
        cout << "Correct! You may choose another door!" << endl;
    }
    else
    {
        cout << "Wrong! You die." << endl;
        alive = false;
    }
}   

void rid3 ()
{
    string rid;
    cout << "What can you put in a bucket to make it weigh less?: ";
    cin >> rid;

    if (rid == "Hole" || rid == "hole")
    {
        cout << "Correct! You may choose another door!" << endl;
    }
    else
    {
        cout << "Wrong! You die." << endl;
        alive = false;
    }
}

void rid4 ()
{
    string rid;
    cout << "What do you buy to eat but never consume?: ";
    cin >> rid;

    if (rid == "Cutlery" || rid == "cutlery")
    {
        cout << "Correct! You may choose another door!" << endl;
    }
    else
    {
        cout << "Wrong! You die." << endl;
        alive = false;
    }
}

void rid5 ()
{
    string rid;
    cout << "What has branches, but no fruit, trunk, or leaves?: ";
    cin >> rid;

    if (rid == "Bank" || rid == "bank")
    {
        cout << "Correct! You may choose another door!" << endl;
    }
    else
    {
        cout << "Wrong! You die." << endl;
        alive = false;
    }

}
void weapon(int& items)
{
    int chance = rand() % 6;


    if (chance == 0 && items <= 3)
    {
        int num = rand() % 3 + 1;
       
// Used ChatGPT for strcat 
        switch (num)
        {
            case 1:
                cout << "\nIn the room you found a Sword!\n";
                strcat(inventory, " ");
                strcat(inventory, "Sword");
                break;

            case 2:
                cout << "\nIn the room you found a device with ChatGPT\n";
                strcat(inventory, " ");
                strcat(inventory, "ChatGPT");
                break;

            case 3:
                cout << "\nIn the room found a gun!\n";
                strcat(inventory, " ");
                strcat(inventory, "Gun");
                break;
        }

        items++;
    }

}
    
