#include <iostream>
#include <string>


using namespace std;

class NotFoundException {
    private:
        string message;
    public:
        NotFoundException(const char* msg) : message(msg){}
        const char* what() const throw(){
            return message.c_str();
        }
};


class Node{
    public:
    int data;
    Node* next;
    Node* prev; 
    Node* curr;

    Node(int inVal) : data(inVal), next(nullptr), prev(nullptr) {} 

};

template <typename T>
class List{
    private:
        int length = 0;
        Node *head; //or front
        Node *last;
    public:
        //constructor
        List() : length(0), head(nullptr), last(nullptr) {}

        //deconstructor
        ~List() {
            while (head != nullptr){
                Node* temp = head;
                head = head -> next;
                delete temp;
            }
            last = nullptr;
            length = 0;
        }
        

        //insert funciton
        void addItem(int inVal){ //O(1)
            //empty list
            if (head == nullptr){
                head = new Node(inVal);
                last = head;
                length++;
            } else{
                //list is not empty
                last -> next = new Node(inVal);
                last = last->next;
                length++;
            }
        }

        //check if the list is empty
        void isEmpty(){
            if (head == nullptr){
                return true;
            } else{
                return false
            }
        };

        //return the size of the list
        int size(){
            return length;
        }

        //return the previous item in the list
        void seePrev(){
            int call = 1;
            int prevResult = curr -> prev -> data;
            if (call == 1) {
                //if the list is empty then return the throw error
                if (curr == nullptr || curr -> prev == nullptr){
                    throw NotFoundException("NotFoundException: list is empty cannot reach the next value.");
                }else{
                    //return previous without moving the element
                    call++;
                    cout << prevResult << endl;
                }
                
            } else {
                //if seeat or reset isnt set after the first time this is called
                
                //if the list is empty then return the throw error
                if (curr == nullptr || curr -> prev == nullptr ){
                    throw NotFoundException("NotFoundException: list is empty cannot reach the next value.");
                }else if (curr -> prev -> prev != nullptr){
                    //it is at the end of the list return a nullptr
                    cout << prevResult << current -> prev -> prev -> data << endl;
                } else {
                    //return next without moving the next element
                    cout << prevResult << endl;
                }
            }
        }

        //return the previous item in the list
        void seeNext(){
            int call = 1;
            int nextResult = curr -> next -> data;
            if (call == 1) {
                //if the list is empty then return the throw error
                if (curr == nullptr || curr -> next == nullptr){
                    throw NotFoundException("NotFoundException: list is empty cannot reach the next value.");
                } else {
                    //return next without moving the next element
                    cout << nextResult;
                }
                call++;
            } else {
                //if seenext or reset isnt set after the first time this is called
                
                //if the list is empty then return the throw error
                if (curr == nullptr || curr -> next == nullptr){
                    throw NotFoundException("NotFoundException: list is empty cannot reach the next value.");
                }else if (last -> next == nullptr){
                    //it is at the end of the list return a nullptr
                    cout << nextResult << curr->next->next->data << endl;
                } else {
                    //return next without moving the next element
                    cout << nextResult << endl;
                }
            }
            
        }

        void reset() {
            Node * temp = head;
            head = head -> next;
            delete temp;
            last = nullptr;
            next = nullptr;
            prev = nullptr;
            length = 0;
            seeNext.call = 0;
            seePrev.call = 0;
        }

        Node* seeAt(int inVal){
            int searchlength = 0;
            while (searchlength <= inVal){
                if (searchlength == inVal){
                    return Node* next;
                } else if (searchlength == 0){
                    head -> data;
                } else {
                    data -> next;
                    searchlength++;
                }
            }
        }

        


        //remove element
        int getItem(int inVal){
            Node *temp = head;
            //make sure there is a list
            if (length == 0){
            //if the user tries to delete a list of one char
                throw NotFoundException("NotFoundExceptiom: value not found.");
            }

            
            Node* hold = temp->next;
            temp -> next = hold -> next;
            int retVal = hold -> data;
            delete(hold);
            length--;
            return retVal;

            if(temp -> data = inVal){
                length--;
                int returning = temp -> data;
                head = temp -> next;
                delete temp;
                return retVal;
            }

            while(temp -> next != nullptr && temp -> next -> data != inVal){
                temp = temp -> next;
                //O(N)
            }

            if (temp -> next == nullptr) {
                throw NotFoundException("NotFoundExceptiom: value not found.");
            }

        }

        //find in the linked list
        int IsInList(int inVal) {
            //empty function
            Node *temp = head;
            while(temp != nullptr && temp ->data != inVal){
                temp = temp -> next;
            }

            if (temp == nullptr) {
                throw NotFoundException("NotFoundExceptiom: value not found.");
            }
            return temp -> data;
        }

        //implement overload functions for <,>, and ==

        //< 
        bool operator<(const List<T>& inVal) const {
            return length < inVal.length;
        }

        //>
        bool operator>(const List<T>& inVal) const {
            return length > inVal.length;
        }

        //==
        bool operator==(const List<T>& inVal) const {
            if (length != inVal.length) {
                return false;
            }

            Node* temp1 = head;
            Node* temp2 = inVal.head;
            while (temp1 != nullptr) {
                if (temp1->data != temp2->data) {
                    return false;
                } else {
                    temp1 = temp1->next;
                    temp2 = temp2->next;
                }
            }
            return true;
        }

        //list going forawrd
        void displayForward() {
            Node* temp = head;
            while (temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }

        //list back
        void displayBackward() {
            Node* temp = last;
            while (temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->prev;
            }
            cout << endl;
        }

        void asciiDisplay(const string& inVal){
            for( char ch : inVal){
                //use a switch case depending on the number
                int digits = ch - '0';
                switch (digits){
                    case 0:
                        cout <<"  000  " << endl;
                        cout <<" 0   0 " << endl;
                        cout <<"0     0" << endl;
                        cout <<"0     0" << endl;
                        cout <<"0     0" << endl;
                        cout <<" 0   0 " << endl;
                        cout <<"  000  " << endl;
                        break;
                    case 1:
                        cout <<"   1   " << endl;
                        cout <<"  11   " << endl;
                        cout <<"   1   " << endl;
                        cout <<"   1   " << endl;
                        cout <<"   1   " << endl;
                        cout <<"   1   " << endl;
                        cout <<"  111  " << endl;
                        break;
                    case 2:
                        cout <<"  222  " << endl;
                        cout <<" 2   2 " << endl;
                        cout <<"     2 " << endl;
                        cout <<"    2  " << endl;
                        cout <<"   2   " << endl;
                        cout<<"  2    " << endl;
                        cout<<" 22222 " << endl;
                        break;
                    case 3:
                        cout<<"  333  " << endl;
                        cout<<" 3   3 " << endl;
                        cout<<"     3 " << endl;
                        cout<<"   33  " << endl;
                        cout<<"     3 "<< endl;
                        cout<<" 3   3 " << endl;
                        cout<<"  333  "<<endl;
                        break;
                    case 4:
                        cout<<"     4 "<<endl;
                        cout<<"    44 "<<endl;
                        cout<<"   4 4 "<<endl;
                        cout<<"  4  4 "<<endl;
                        cout<<" 444444"<<endl;
                        cout<<"     4 "<<endl;
                        cout<<"     4 "<<endl;
                        break;
                    case 5:
                        cout<<" 55555 "<<endl;
                        cout<<" 5     " <<endl;
                        cout<<" 5     "<<endl;
                        cout<<"  555  "<<endl;
                        cout<<"     5 "<<endl;
                        cout<<" 5   5 "<<endl;
                        cout<<"  555  "<<endl;
                        break;
                    case 6:
                        cout<<"  666  "<<endl;
                        cout<<" 6     "<<endl;
                        cout<<" 6     "<<endl;
                        cout<<" 6666  "<<endl;
                        cout<<" 6   6 "<<endl;
                        cout<<" 6   6 "<<endl;
                        cout<<"  666  "<<endl;
                        break;
                    case 7:
                        cout<<" 777777 "<<endl;
                        cout<<"     7 "<<endl;
                        cout<<"    7  "<<endl;
                        cout<<"   7   "<<endl;
                        cout<<"  7    "<<endl;
                        cout<<" 7     "<<endl;
                        cout<<"7     "<<endl;
                        break;
                    case 8:
                        cout<<"  888  "<<endl;
                        cout<<" 8   8 "<<endl;
                        cout<<" 8   8 "<<endl;
                        cout<<"  888  "<<endl;
                        cout<<" 8   8 "<<endl;
                        cout<<" 8   8 "<<endl;
                        cout<<"  888  "<<endl;
                        break;
                    case 9:
                        cout<<"  999  "<<endl;
                        cout<<" 9   9 "<<endl;
                        cout<<" 9   9 "<<endl;
                        cout<<"  9999 "<<endl;
                        cout<<"     9 "<<endl;
                        cout<<"    9  "<<endl;
                        cout<<"   9   "<<endl;
                        break;
                    default:
                        cout << "Invalid character: " << ch << endl;
                        break;
                }
            }
            
        }
        
};   

class Part{
    private:
        int sku, price, quantity, leadTime;
        string description, UOM;

    public:
         //constructor
         Part() : sku(0), price(0), quantity(0), leadTime(0), description(""), UOM(""){}

         //deconstructor
         ~Part() {
         }

        void setDescription(const string& desc) {
            description = desc;
        }

        void setPrice(int p) { price = p; }
        void setQuantity(int q) { quantity = q; }
        void setLeadTime(int lt) { leadTime = lt; }

        void setSku(int s) { sku = s; }
    
        string getPartInfo() {
            return description.empty() ? "No description available." : description;
        }
    
        int getPrice() {
            return price;
        }
    
        bool inStock() {
            return quantity > 0;
        }
    
        string available(int m, int d, int leadTimeInput) {
            if (leadTime == 0) {
                leadTime = leadTimeInput; 
            }
    
            if (inStock()) {
                return "This item is available today.";
            }
    
            d += leadTime;
            while (d > daysInMonthFunc(m)) {
                d -= daysInMonthFunc(m);
                m++;
                if (m > 12) {
                    m = 1;
                }
            }
            return "Available on " + to_string(m) + "/" + to_string(d);
        }
    
        int daysInMonthFunc(int month) const {
            if (month == 2) return 28;
            return (month == 4 || month == 6 || month == 9 || month == 11) ? 30 : 31;
        }

        bool operator<(const Part& inVal) const {
            return this->sku < inVal.sku;
        }

        //>
        bool operator>(const Part& inVal) const {
            return this->sku > inVal.sku;
        }

        //==
        bool operator==(const Part& inVal) const {
            return this->sku == inVal.sku; 
        }

        //part 4 ascii art
        void asciiArt(const string& inVal){
            //only display key members
            List<int> list;
            list.asciiDisplay(inVal);
        }



};

int main(){
    //for the availibity based on the date, read in m and d year not neccessary
    Part part, part2;
    string inVal; 
    int uVal;
    bool looping;
    looping = true;
    bool loopIN = true;
    bool descriptioning = false;
    string linklist;
    //ask the user which list they would like?
    

    while (looping == true ){
        cout << "There are several base linked lists for use. " << endl;
        while (loopIN = true) {
            cout << "Please select a numbered option. " << endl;
            cout << "1. Get Part Info " << endl;
            cout << "2. Get Price " << endl;
            cout << "3. Check Stock " << endl;
            cout << "4. Check Avalibility " << endl;
            cout << "5. Compare" << endl;
            cout << "6. ASCII Art"<< endl;
            cin >> uVal;
            cin.ignore();
            
            if (uVal == 1) {
                if (!descriptioning) {
                    cout << "Enter Part Description: ";
                    string description;
                    getline(cin, description);
                    part.setDescription(description);
                    descriptioning = true;
                }
                cout << "Description: " << part.getPartInfo() << endl;
            } else if (uVal == 2) {
                cout << "Enter Price: ";
                int priceInput;
                cin >> priceInput;
                cout << "Price: $" << priceInput << endl;
            } else if (uVal == 3) {
                cout << "Enter Quantity: ";
                int quantityInput;
                cin >> quantityInput;
                cout << (quantityInput > 0 ? "In stock" : "Out of stock") << endl;
            } else if (uVal == 4) {
                int m, d, leadTimeInput;
                cout << "Enter Lead Time (in days): ";
                cin >> leadTimeInput;
                cout << "Enter month and day: ";
                cin >> m >> d;
                cout << part.available(m, d, leadTimeInput) << endl;

            } else if (uVal == 5) {
                cout << "Enter SKU for part 1: ";
                int sku1;
                cin >> sku1;
                part.setSku(sku1);

                cout << "Enter SKU for part 2: ";
                int sku2;
                cin >> sku2;
                part2.setSku(sku2);

                cout << "Choose an operator overload (<, >, ==): ";
                string choice;
                cin >> choice;

                if (choice == "<") {
                    cout << (part < part2 ? "Part 1 has a lower SKU." : "Part 1 does not have a lower SKU.") << endl;
                } else if (choice == ">") {
                    cout << (part > part2 ? "Part 1 has a higher SKU." : "Part 1 does not have a higher SKU.") << endl;
                } else if (choice == "==") {
                    cout << (part == part2 ? "Both parts have the same SKU." : "The parts have different SKUs.") << endl;
                } else {
                    cout << "Invalid operator choice." << endl;
                }

            } else if (uVal == 6){
                //ascii art
                cout << "Please enter a string of integers to turn into ACII art 1-10: " << endl;
                cin >> linklist;
                part.asciiArt(linklist);
            } else {
                cout << "Invalid input, please try again" << endl;
            }
        }
        cout << "Invalid input, please try again" << endl;
    }
}
