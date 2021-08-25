/*
Bogdan Ciobanu 4/23/21
This program employs a binary tree to sort nodes containing instances
of the EmployeeInfo class and allows the user to search the tree for
a specific value.

Objectives:
1. Create BinaryTree class that uses the EmployeeInfo class to 
create nodes. The EmployeeInfo class should hold an employee name
and ID number. The nodes should be sorted by the ID number.
2. Create insert and search functions for the class.
3. Test the binary tree by inserting eight nodes and the asking the
user to input an ID number that will be searched for. Display
the name associated with that number or a message indicating it was
not found.
*/

#include <iostream>
#include <string>

using namespace std;

//BinaryTree class declaration
class BinaryTree
{
private:
    //EmployeeInfo class to create nodes
    class EmployeeInfo
    {
    public:
        //Member variable declarations
        int employeeID;
        string employeeName;
        EmployeeInfo* left;
        EmployeeInfo* right;

        //Constructor
        EmployeeInfo(int id, string name, 
            EmployeeInfo* left1 = nullptr, 
            EmployeeInfo* right1 = nullptr) 
        {
            employeeID = id;
            employeeName = name;
            left = left1;
            right = right1;
        }
    };

    //Pointer to the root of the tree
    EmployeeInfo* root;

    //Private helper member function protypes
    void insert(EmployeeInfo*& tree, int id, string name);
    void search(EmployeeInfo*& tree, int id);

public:
    //Constructor
    BinaryTree() {
        root = nullptr;
    }

    //Public member functions
    void insert(int id, string name) {
        insert(root, id, name);
    }

    void search(int id) {
        search(root, id);
    }
};

//Insert member function
void BinaryTree::insert(EmployeeInfo*& tree, int id, string name) {
    //If tree is empty, make new node and set as root
    if (!tree) {
        tree = new EmployeeInfo(id, name);
        return;
    }
    //Else insert the new node into the proper subtree
    else if (id < tree->employeeID) {
        insert(tree->left, id, name);
    }
    else {
        insert(tree->right, id, name);
    }
}

void BinaryTree::search(EmployeeInfo*& tree, int id) {
    
    //If nullptr reached, display ID not found
    if (!tree) {
        cout << "Employee ID " << id << " not found." << endl;
        return;
    }
    //Else check for ID recursively and display name associated with ID
    else if (id == tree->employeeID) {
        cout << "The name associated with ID " << id << " is "
            << tree->employeeName << endl;
    }
    else if (id < tree->employeeID) {
        search(tree->left, id);
    }
    else {
        search(tree->right, id);
    }
}


int main()
{
    //Variable declaration
    int input;
    
    //Instantiate BinaryTree
    BinaryTree tree;

    //Insert eight node into tree
    cout << "Inserting employee nodes into binary tree...\n\n";
    
    tree.insert(1021, "John Williams");
    tree.insert(1057, "Bill Witherspoon");
    tree.insert(2487, "Jennifer Twain");
    tree.insert(3769, "Sophia Lancaster");
    tree.insert(1017, "Debbie Reece");
    tree.insert(1275, "George McMullen");
    tree.insert(1899, "Ashley Smith");
    tree.insert(4218, "Josh Plemmons");

    //Request employee ID to search for
    cout << "Search employee name by employee ID. Enter ID: " << endl;
    cin >> input;

    //Call search function with user input
    tree.search(input);
}
