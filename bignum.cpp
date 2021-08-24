#include <iostream> 
using namespace std; 
  
// Structure of Double Linked List 
struct node { 
      
    // To store a single number/digit 
    int digit; 
  
    // Pointers to the previous and next number/digit 
    struct node* next; 
    struct node* prev; 
    node(int); 
}; 
  
// To initialize the node with a single digit 
node::node(int val) 
{ 
    digit = val; 
    next = prev = NULL; 
} 

// Creating a Bignumber class  
class Bignum 
{ 
public: 
    Bignum();
  
  	// Prototypes and initializations
  	
    // To insert a number in front 
    void startInsert(int); 
    // To insert a number at the end 
    void endInsert(int); 
    // To print a the number 
    void print();
    // To compute length of numbers
    int length();
	// To add numbers  
    void add(Bignum*, Bignum*); 
    // To multiply numbers
	void mul(Bignum*, Bignum*); 
    node* start; 
    node* end; 
    // Digits counter
	int counter; 
}; 

 
  
// Constructor of the Bignum Class 
Bignum::Bignum() 
{ 
    start = end = NULL; 
    counter = 0; 
} 
  
// To insert at the beginning of the Linked List 
void Bignum::startInsert(int value) 
{ 
    node* temp = new node(value); 
      
    if (start == NULL) 
        start = end = temp; 
    else 
	{ 
        start->prev = temp; 
        temp->next = start; 
        start = temp; 
    } 
    counter++; 
} 
  
// To insert in the end 
void Bignum::endInsert(int value) 
{ 
    node* temp = new node(value); 
      
    if (end == NULL) 
        start = end = temp; 
    else 
	{ 
        end->next = temp; 
        temp->prev = end; 
        end = temp; 
    } 
    counter++; 
}   
// To print the number
void Bignum::print() 
{ 
    node* temp = start; 
      
    while (temp != NULL) 
	{ 
        cout << temp->digit; 
        temp = temp->next; 
    } 
}   
// Returns the number of digits 
int Bignum::length() 
{ 
    return counter; 
}  
// Addition inmplementation
void Bignum::add(Bignum* a, Bignum* b) 
{ 
    int c = 0, s;
	 
    Bignum* a1 = new Bignum(*a); 
    Bignum* b1 = new Bignum(*b);   
    // Copy Constructor - used to copy objects 
    this->start = NULL; 
    this->end = NULL; 
    this->counter = 0; 
  
    while (a1->end != NULL || b1->end != NULL) 
	{ 
        if (a1->end != NULL && b1->end != NULL) 
		{ 
            s = ((a1->end->digit) + (b1->end->digit) + c) % 10; 
            c = ((a1->end->digit) + (b1->end->digit) + c) / 10; 
            a1->end = a1->end->prev; 
            b1->end = b1->end->prev; 
        } 
        else if (a1->end == NULL && b1->end != NULL) 
		{ 
            s = ((b1->end->digit) + c) % 10; 
            c = ((b1->end->digit) + c) / 10; 
            b1->end = b1->end->prev; 
        } 
        else if (a1->end != NULL && b1->end == NULL) 
		{ 
            s = ((a1->end->digit) + c) % 10; 
            c = ((a1->end->digit) + c) / 10; 
            a1->end = a1->end->prev; 
        }           
        // Inserting the sum digit 
        startInsert(s); 
    }       
    // Inserting
    if (c != 0) 
        startInsert(c); 
}
  
// Multiplication implementation
void Bignum::mul(Bignum* a, Bignum* b) 
{ 
    int k = 0, i; 
    Bignum* tpro = new Bignum(); 
    while (b->end != NULL) 
	{ 
        int c = 0, s = 0; 
        Bignum* temp = new Bignum(*a); 
        Bignum* pro = new Bignum(); 
        while (temp->end != NULL) 
		{ 
            s = ((temp->end->digit) * (b->end->digit) + c) % 10; 
            c = ((temp->end->digit) * (b->end->digit) + c) / 10; 
            pro->startInsert(s); 
            temp->end = temp->end->prev; 
        } 
        if (c != 0) 
            pro->startInsert(c); 
  
        for (i = 0; i < k; i++) 
            pro->endInsert(0); 
  
        add(this, pro); 
        k++; 
        b->end = b->end->prev; 
        pro->start = pro->end = NULL; 
        pro->counter = 0; 
    } 
} 
  
// Main function
int main() 
{ 
	// Creating and allocating memory for Bignumber variables
    Bignum* x = new Bignum(); 
    Bignum* y = new Bignum(); 
    Bignum* z = new Bignum();
    
  	// Declaring number variables to store numbers
  	string num1;
  	string num2;
	    	
  	// Inputs (Taking first and second numbers from user)
  	cout << "Enter first number: ";
  	cin >> num1;
  	cout << "Enter second number: ";
  	cin >> num2;
  	
  	// Inserting first and second numbers into lists
    for (int i = 0; i < num1.length(); i++) 
        x->endInsert(num1.at(i) - '0'); 
    for (int i = 0; i < num2.length(); i++) 
        y->endInsert(num2.at(i) - '0'); 
	
	// Outputs
    cout << "Product :" << endl; 
    z->mul(x, y); 
    z->print(); 
    cout << endl; 
	cout << "length of first number(Number of digits): " << num1.length() << endl;
	cout << "length of second number(Number of digits): " << num2.length() << endl; 
    return 0; 
} 
