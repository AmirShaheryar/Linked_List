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
    void RemoveDuplicate() 
    {
        for (Node* temp1 = head; temp1 != nullptr; temp1 = temp1->next)
        {
            for (Node* temp2 = temp1; temp2->next != nullptr; ) 
            {
                if (temp1->data == temp2->next->data) 
                {
                    Node* duplicate = temp2->next;
                    temp2->next = temp2->next->next; 
                    delete duplicate;
                } 
                else 
                {
                    temp2 = temp2->next; 
                }
            }
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
    int Insert_At_Index(int place,int Ndata)
    {
        if(place==0)
        {
            Node*NNode=new Node();
            NNode->data=Ndata;
            NNode->next=head;
            head=NNode;
        }
        
        else
        {
            Node*temp=head;
            Node*NNode=new Node();
            NNode->data=Ndata;
            int i=0;
            while(i<place-1)
            {
                temp=temp->next;
                i++;
            }
            NNode->next=temp->next;
            temp->next=NNode;
        }
    }
    int Get_Index_Value(int Position)
    {
        int s=Length();
        if(Position>s)
        {
            return -1;
        }
        
        else
        {
            Node*temp=head;
            int i=0;
            while(i<Position-1)
            {
                temp=temp->next;
                i++;
            }
            return temp->data;
        }
    }
    int find_Mid_Element()
    {
        int s=Length();
        int require_index=s/2;

        Node*temp=head;
        for(int i=0;i<require_index;i++)
        {
            temp=temp->next;
        }
        return temp->data;
    }

    int Find_Middle()
    {
        Node* slow = head;
        Node* fast = head;

        while(fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow->data;
    }

    void UpdateAtIndex(int Index,int val)
    {
        if(head==nullptr)
        {
            return;
        }
        Node*temp=head;
        for(int i=0;i<Index-1;i++)
        {   
            temp=temp->next;
        }
        temp->data=val;
    }

    void Sort()
    {

        Node*temp1=head;
        Node*temp2=head;

        for(temp1=head;temp1->next!=nullptr;temp1=temp1->next)
        {
            for(temp2=temp1->next;temp2!=nullptr;temp2=temp2->next)
            {
                if(temp1->data>temp2->data)
                {
                    swap(temp1->data,temp2->data);
                }
            }
        }

    }
    void Delete_At_Index(int Index)
    {
        if (head == nullptr) 
        {
            cout << "List is empty!" << endl;
            return;
        }

        if (Index == 0) 
        {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp1 = head;
        for (int i = 0; temp1 != nullptr && i < Index - 1; i++) 
        {
            temp1 = temp1->next;
        }

        if (temp1 == nullptr || temp1->next == nullptr) 
        {
            cout << "Index out of range!" << endl;
            return;
        }

        Node* temp2 = temp1->next;
        temp1->next = temp2->next;
        delete temp2;
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
    void Merge(Linked_List &other)
    {
        if(head==nullptr)
        {
            head=other.head;
            return;
        }
        Node*temp=head;

        while(temp->next!=nullptr)
        {
            temp=temp->next;
        }
        temp->next=other.head;
    }

    void Reverse() 
    {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;

        while (current != nullptr) 
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    ~Linked_List() 
    {
        Node* temp;
        while (head != nullptr) 
        {
            temp = head;
            head = head->next;
            delete temp;
        }
    }


    
};

int main() 
{
    Linked_List list;

    list.Insert_Data(12);
    cout << "List after inserting 12: ";
    list.Print();
    cout << "\n";

    cout<<"Size of List : "<<list.Length()<<"\n";

    list.Insert_Data(123);
    cout << "List after inserting 123: ";
    list.Print();
    cout << "\n";
    cout<<"Size of List : "<<list.Length()<<"\n";

    list.Insert_At_Index(0,5);
    cout << "List after inserting 5: ";
    list.Print();
    cout << "\n";
    cout<<"Size of List : "<<list.Length()<<"\n";

    list.Insert_At_Index(2,15);
    cout << "List after inserting 15: ";
    list.Print();
    cout << "\n";
    cout<<"Size of List : "<<list.Length()<<"\n";

    cout<<"Value at Index 2 "<<list.Get_Index_Value(2)<<"\n";

    list.Delete(123);
    cout << "List after deleting 123: ";
    list.Print();
    cout << "\n";
    cout<<"Size of List : "<<list.Length()<<"\n";

    cout << "Search 123: " << list.Search(123) << "\n";
    cout << "Search 13: "  << list.Search(13)  << "\n";


    list.Insert_Data(1);
    list.Insert_Data(2);
    list.Insert_Data(3);
    list.Insert_Data(4);
    cout<<"List after Insertion : ";
    list.Print();
    cout<<"\n";
    cout<<"Middle Element : "<<list.find_Mid_Element()<<"\n";
    cout<<"Middle Element : "<<list.Find_Middle()<<"\n";

    list.Sort();

    list.Print();
    cout<<"\n";

    list.UpdateAtIndex(2,100);
    list.Print();
    cout<<"\n";

    list.Insert_Data(1);
    list.Insert_Data(2);
    list.Insert_Data(3);
    list.Insert_Data(4);
    cout<<"List after Insertion : ";
    list.Print();
    cout<<"\n";
    list.RemoveDuplicate();
    list.Print();

    return 0;
}



