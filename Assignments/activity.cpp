#include <iostream>
using namespace std;
class Passengers
{

    string name;
    string ticketNo;

public:
    static int noOfPassengers;
    Passengers() {}
    Passengers(string name, string ticketNo)
    {
        this->name = name;
        this->ticketNo = ticketNo;
        noOfPassengers++;
    }
    string getName() const
    {
        return name;
    }
    string getTicket() const
    {
        return ticketNo;
    }

    void display()
    {
        cout << "Person name is : " << name << endl;
        cout << "Person ticket id is : " << ticketNo << endl;
    }
    ~Passengers() {}
};
int Passengers::noOfPassengers = 0;
class TicketReservationSystem : public Passengers
{
    Passengers *arr[10];
    static int j;

public:
    TicketReservationSystem()
    {
        for (int i = 0; i < 10; i++)
        {
            arr[i] = nullptr;
        }
    }

    void addPassenger(string name, string Ticketno)
    {
        arr[j] = new Passengers(name, Ticketno);
        j++;
    }
    void display()
    {
        for (int i = 0; i < j; i++)
        {
            arr[i]->display();
        }
    }
    void findPassenger()
    {
        cout << "Enter ticket id: ";
        string ticket;
        cin >> ticket;

        for (int i = 0; i < j; i++)
        {
            string id = arr[i]->getTicket();
            if (ticket == id)
               { cout << "found ticket" << endl;
               return;}
                
        }
        cout<<"ticket not found"<<endl;
    }
    ~TicketReservationSystem()
    {
        for (int i = 0; i < j; i++)
        {
            delete arr[i];
        }
    }
};
int TicketReservationSystem::j = 0;
int main()
{

    TicketReservationSystem system;
    system.addPassenger("ayush", "india1");
    system.addPassenger("rahul", "india2");
    system.addPassenger("neha", "india3");

    system.display();
    system.findPassenger();

    return 0;
}

// Ans1:
//  By storing Passengers objects as pointers, the objects are allocated dynamically on the heap using new.     This ensures the objects persist in memory even after the function in which they were created ends, unlike local objects that would be destroyed automatically when their scope ends. 
//  Although not fully utilized in this specific example, storing objects as pointers allows the system to take advantage of polymorphism if the Passengers class is extended with virtual functions or subclasses.

// Ans2: 
// The search by ticket in this code works by prompting the user to input a ticket ID and then iterating through the array of stored Passengers objects. Each passenger's ticket ID is retrieved using the getTicket() method and compared to the input. If a match is found, the method prints "found ticket" and exits. If no match is found after checking all entries, it outputs "ticket not found." This approach ensures that the program examines all currently stored passengers (up to j, the number of passengers added) in a linear search manner, making it straightforward but potentially inefficient for larger datasets.

// Ans3:


// If we don't use a pointer-based array and store Passengers objects directly, it could lead to object slicing if subclasses are introduced, losing data or behavior unique to derived classes. Managing memory becomes less flexible, as directly stored objects have fixed lifetimes tied to the array's scope, preventing dynamic allocation. Copying entire objects into the array could be inefficient for large or complex objects, increasing overhead. Additionally, modifying or deleting a specific passenger becomes cumbersome, as direct storage lacks the explicit control over object lifecycles provided by pointers. Overall, using pointers ensures flexibility, polymorphism, and better memory management.