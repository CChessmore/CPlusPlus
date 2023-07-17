struct slist_node {
    int info;
    struct slist_node *next;
}
//Goals:
//Add to end, print list contents, send contents to file

class SList {
    slist_node* head;

    public:
    SList():head(nullptr){ };
    
    void insert_start(int data=0)
    {
        slist_node* temp = new slist_node(data);
        if(head == nullptr) {head = temp;};
        else
        {
            temp->next = head;
            head = temp;
        }
    }

    void insert_end(int data=0)
    {
        slist_node* temp = new slist_node(data);
        if(head == nullptr) {head = temp;};
        else
        {
            slist_node* curr = head;
            while(curr->next)
            {
                curr = curr->next;
            }
            curr->next = temp;
        }
    }

    void remove(int data)
    {
        if(!head) {return;};

        slist_node* temp = head;

        if(temp && temp->info = data)
        {
            head = temp->next;
            delete temp;
            return;
        }
        else
        {
            slist_node* curr = head;
            while(temp && temp->info != data)
            {
                curr = temp;
                temp = temp->next;
            }
            if(!temp)
            {
                cout << "Value not found in list." << endl;
                return;
            }
            else
            {
                curr->next = temp->next;
                delete temp;
            }
        }
    }

    void print_nodes()
    {
        slist_node* temp = head;
        while(temp)
        {
            cout << "["<< temp->info << "]->";
            temp = temp->next;
        }
        cout << "[NULL]";
    }

    void send_to_file()
    {
        slist_node* temp = head;
        string list;
        ofstream outfile ("SList.txt");
        while(temp)
        {
            list.append("["<< temp->info << "]->");
            temp = temp->next;
        }
        list.append("[END OF LIST]");
        outfile << list;
        outfile.close();
    }

}