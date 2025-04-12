
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkList
{
public:
    Node *head;
    int size;

    LinkList()
    {
        this->head = NULL;
        this->size = -1;
    }

    void insertAtFront(int data)
    {
        Node *newNode = new Node(data);
        if (this->head == NULL)
        {
            this->head = newNode;
        }
        else
        {
            newNode->next = this->head;
            this->head = newNode;
        }
        this->size++;
    }

    void deleteAtIndex(int index)
    {
        if (index == 0)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            size--;
        }
        else if (index > 0 && index <= size)
        {
            Node *temp = head;
            for (int i = 0; i < index - 1; i++)
            {
                temp = temp->next;
            }
            Node *toDelete = temp->next;
            temp->next = toDelete->next;
            delete toDelete;
            size--;
        }
    }

    void searchindex(int index)
    {
        if (index == 0)
        {
            cout << head->data << endl;
        }
        else if (index > 0 && index <= size)
        {
            Node *temp = head;
            for (int i = 0; i < index; i++)
            {
                temp = temp->next;
            }
            cout << "Element at index " << index << " is: " << temp->data << endl;
        }
    }

    void displayList()
    {

        Node *temp = this->head;
        cout << "LinkList: ";

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void reverse()
    {
        Node *prev = nullptr;
        Node *current = head;

        while (current)
        {
            Node *next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
        cout << endl;
        cout << endl
             << "List Reveresed" << endl;
    }
};

int main()
{

    LinkList list;
    int choice;

    do
    {
        cout << endl
             << "---Linked list operation---" << endl;
        cout << endl
             << "Press 1 for inesert at front" << endl;
        cout << "Press 2 for delete" << endl;
        cout << "Press 3 for search" << endl;
        cout << "Press 4 for display" << endl;
        cout << "Press 5 for reverse" << endl;
        cout << "Press 6 for exit!!!" << endl;

        cout << endl
             << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the element to insert at front: ";
            int element;
            cin >> element;
            list.insertAtFront(element);
            break;

        case 2:
            cout << "Enter the index to delete:";
            cin >> element;
            list.deleteAtIndex(element);

            break;

        case 3:
            cout << "Enter the index to search:";
            cin >> element;
            list.searchindex(element);
            break;

        case 4:

            list.displayList();
            break;

        case 5:
            list.reverse();
            break;

        case 6:
            cout << "Existing the program!!!" << endl;
        default:
            break;
        }

    } while (choice != 0);

    return 0;
}