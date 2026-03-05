#include<iostream>
using namespace std;

struct Node{
    int data;
    Node*next;
};

class Linked_List{
private:
    Node *head;
public:
    Linked_List(){
        head=nullptr;
    }

    void Insert_Data(int Ndata)
    {   
        if (head == nullptr) {
            Node* New_Node = new Node();
            New_Node->data = Ndata;
            New_Node->next = nullptr;
            head = New_Node;   
        }
        else
        {
            Node* New_Node = new Node();
            New_Node->data = Ndata;
            New_Node->next = nullptr;   

            Node* temp = head;          
            while (temp->next != nullptr) 
            {
                temp = temp->next;
            }
            temp->next = New_Node;
        }
    }

    void Delete(int Ndata)
    {
        if(head->data==Ndata)
        {
            Node*temp=head;
            head=head->next;
            delete temp;
        }
        else
        {
            Node*temp=head;
            while(temp->next->data!=Ndata)
            {
                temp=temp->next;
            }

            Node*temp1=temp->next;
            temp->next=temp->next->next;
            delete temp1;

        }
    }

    bool Search(int Ndata)
    {
        Node *temp=head;

        while (temp!=nullptr)
        {
            if(temp->data==Ndata)
            {
                return true;
            }
            temp=temp->next;
        }
        return false;
    }
    int Length()
    {
        Node*temp=head;
        
        int size=0;
        while (temp!=nullptr)
        {
            size++;
            temp=temp->next;
        }
        return size;
        
    }

    void Print()
    {
        Node*temp=head;
        while (temp!=nullptr)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        
    }
};

int main() {
    Linked_List list;

    list.Insert_Data(12);
    cout << "List after inserting 12: ";
    list.Print();
    cout << "\n";

    list.Insert_Data(123);
    cout << "List after inserting 123: ";
    list.Print();
    cout << "\n";

    list.Delete(123);
    cout << "List after deleting 123: ";
    list.Print();
    cout << "\n";

    cout << "Search 123: " << list.Search(123) << "\n";
    cout << "Search 13: "  << list.Search(13)  << "\n";

    return 0;
}

