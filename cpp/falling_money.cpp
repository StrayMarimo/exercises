#include <iostream>
#include <ctime>
#include <conio.h>
#include <Windows.h>
using namespace std;

// constants
const char CPPKEYLEFT =  75;
const char CPPKEYRIGHT = 77;

//struct definition
struct Node {
    string data;
    Node* next;
};

typedef Node* Nodeptr; // customize data type

// function prototypes
void addHead(Nodeptr&, string);
void printList(Nodeptr, string&, short int);
void deleteNode(Nodeptr&);
string generateLine(string);

int main() {
    srand (time(NULL)); // generate different random numbers at runtime
    char input;
    short int score = 50, emptyLines = 20, basket = 20;
    string temp(42, ' '), lastLine;
    temp[0] = '|'; temp[41] = '|'; // assign border at first and last value of every line
    Nodeptr newPtr = new Node; // create new node
    newPtr->data = temp; // assign data to new node
    newPtr->next = NULL; // point it to null since it is currently the last node of the list
    Nodeptr head = newPtr; // point head to newly created node

    // insert empty lines for first 20 members of linked list
    while (emptyLines > 0){
      addHead(head, temp);
      emptyLines--;
    }
   
    while (score < 100 && score > 0) {
        cout << "------------- Falling  Money -------------" <<endl;
        if (kbhit())
            input = getch();  // store pressed key to input
        
        // update basket position on key hit but prevent it from exceeding the border
        if (input == CPPKEYLEFT && basket > 1)
            basket--;
        else if (input == CPPKEYRIGHT && basket < 40)
            basket++;
        
        printList(head, lastLine, basket); // print whole list with the last line containing the basket
        addHead(head, generateLine(temp)); // insert another node with a randomly generated positions of falling objects

        //update score depending on the object caught
        if (lastLine[basket] == '$')
            score += 10;
        else if (lastLine[basket] == '.')
            score -= 15;
        
        deleteNode(head); //deletes the last node on list

        cout << "Your score: "<<score << endl; // display score

        Sleep(10); //set speed

        // display score feedback if game ends
        if (score <= 0)
            cout << "Sorry, you lose..." << endl;
        else if (score >= 100)
            cout << "Yeah, you win!!" << endl;
        else // otherwise clearscreen for movement
            system("CLS");
        input = ' '; //resets key hit
    }
    system("PAUSE"); // stops program from immediately closing when game ends
    return 0;
}
// function to randomly decide what symbol to use
char generateSymbol(){
    if (rand() % 2)
        return '$';
    else
        return '.';
}

// function to generate a string containing 2 symbols with random positions
string generateLine(string temp){
    short int first_pos, second_pos;
    char symbol;
    first_pos = 1 + rand() % 40;
    temp[first_pos] = generateSymbol();

    // prevents the 2nd symbol to have the same position as the first one
    do {
        second_pos = 1 + rand() % 40;
    } while (second_pos == first_pos);

    temp[second_pos] = generateSymbol();
    return temp;
}

//insert new node at the beginning of the list
void addHead(Nodeptr& head, string newLine){
   Nodeptr newPtr = new Node; //create a new node
   newPtr -> data = newLine; //assign data to new node
   newPtr -> next = head; // set its pointer to what the head is currently pointing to
   head = newPtr; // point head to the newly created node
}

//display current nodes of linked list
void printList(Nodeptr p, string& lastLine, short int basket) {
   //iterate through every node to print it
   while(p!= NULL) {
       if (p->next == NULL){
          lastLine = p->data; //store last line to a variable to check what the user catches later
          p->data[basket] = 'U'; // assigns basket to the specified position
       }
       cout << p->data << endl; // print data of current node
       p = p->next; // move to next node
   }
}

// delete last node
void deleteNode(Nodeptr& head) {
   Nodeptr newPtr = head;
   while(newPtr->next->next != NULL) // stops at second to the last node
        newPtr = newPtr -> next; //traverse the list
   delete(newPtr -> next); //deletes last node
    newPtr->next = NULL;  // set pointer of former 2nd to the last node to null
}
