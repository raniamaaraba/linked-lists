#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

class Node{
    public:
    int data;
    Node *prev;
    Node *next;
    Node *curr;

    Node(int inVal) : data(inVal), next(nullptr), prev(nullptr) {} 

};

class Deck{
    private:
        int stack = 0;
        Node *top; //top card of the stack
        Node *last; // bottom card
    public:
        //constructor
        Deck() : stack(0), top(nullptr), last(nullptr){}

        //deconstructor
        ~Deck() {
            while (top != nullptr){
                Node* temp = top;
                top = top -> next;
                delete temp;
            }
            last = nullptr;
            stack = 0; 
        }

        //make sure to call twice when they win
        void addItem(int inVal){ //O(1)
            //empty list
            if (top == nullptr){
                top = new Node(inVal);
                last = top;
                stack++;
            } else{
                //list is not empty
                last -> next = new Node(inVal);
                last = last->next;
                stack++;
            }
        }

        //user deck numbof cards
        int userSize(){
            return stack;
        }

        //computer number of deck of cards
        int compSize(){
            return (52 - stack);
        }

        //peek at the top card
        void peek(){
            return (top != nullptr) ? top -> data : -1;
        }

      
};

class Pile{
    //side pile is for player to set aside cards
    
    //no peak func
    //can add card or remove from top
    //return size only user not comp

    private:
        int stack = 0;
        Node *top; //top card of the stack
        Node *last; // bottom card
        int size = 0;
        int cards[size];
    public:
        //constructor
        Pile() : stack(0), top(nullptr), last(nullptr){}

        //deconstructor
        ~Pile() {
            while (top != nullptr){
                Node* temp = top;
                top = top -> next;
                delete temp;
            }
            last = nullptr;
            stack = 0; 
        }
        

        //max of 5 cards
        void addItem(int inVal){
            if (stack < 5){
                cards[stack] = inVal;
                stack++;
            }
        }

        void removeTop(){
            if (stack < 5){
                cards[stack] - cards[top];
            }
        }

        int deckSize(){
            return stack;
        }
            

};

class KOH {
    public:
    void cardDeterminant(Deck& userDeck, Deck& computerDeck){
        srand(time(nullptr));
        vector<int> fullDeck;
        for (int i = 2; i <= 14; i++){
            for (int j = 0; j < 4; j ++){
                fullDeck.push_back(i);
            }
        }

        rand_shuffle(fullDeck.begin(), fullDeck.end());

        for (int i = 0; i < 26; i++){
            userDeck.addItem(fullDeck[i]);
        }

        for (int i = 26 i < 52; i++){
            computerDeck.addItem(fullDeck[i]);
        }




    }

    


};

int main() {
    bool looping = true;
    int inVal, uInVal;
    Deck userDeck, computerDeck;
    Pile pile;
    KOH deckDetermine;

    cout << "Welcome to War! You and the computer each start with 26 cards. " << endl;

    //value card assigment
    deckDetermine.cardDeterminant(userDeck, computerDeck);

    while (looping = true){
        cout << "Please choose an option: " << endl;
        cout << "1. View Deck " << endl;
        cout << "2. Add to side pile " << endl;
        cout << "3. View Computer Deck " << endl;
        cout << "4. Peak at top card " << endl;
        cout << "5. Play card " << endl;
        cin >> inVal;

        if (inVal == 1){
            //return user deck
            userDeck.userSize();

        } else if (inVal == 2){
            //add top card to side pile
            cout << "Please select an option for your side pile. " << endl;
            cout << "1. Add to pile " << endl;
            cout << "2. View pile size " << endl;
            cout << "3. Remove top card " << endl;
            cout << "4. Return to main menu " << endl;
            cin >> uInVal;

            if (uInVal == 1){
                //add top card to pile

            } else if (uInVal == 2){
                //return size
                pile.deckSize();

            } else if (uInVal == 3){
                //remove from side stack

            } else if (uInVal == 4){
                return 0;
            }

        } else if (inVal == 3){
            //return comp deck
            computerDeck.compSize();

        } else if (inVal == 4){
            //peak func
            userDeck.peek();

        } else if (inVal == 5){
            //play game

        } else {
            cout << "Error. Please enter a correct operation. " << endl;
        }

    }



}
