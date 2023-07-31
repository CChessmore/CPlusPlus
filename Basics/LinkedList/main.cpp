#include "header.h"
#include "SList.cpp"

using namespace std;

int main() {
    int total_items = 0;
    vector<int> items;
    SList myList;

    //Loop to prompt for non-negative number below 100 and above 0
    while(!total_items){
    total_items =  rand() % 50+1;
    cout << "Creating list of " << total_items << " length" << endl;
    if(total_items>100) {total_items = 100;}
    if(total_items<0) {
        total_items = 0;
        cout << "Error; please enter a value that is a number and is above 0." << endl;
        }
    }

    myList.insert_start(rand() % 100 + 1);

    //i starts at 1, as we placed one item in the list already
    for(int i=1;i<total_items;i++)
    {
        myList.insert_end(rand() % 100 + 1);
    };
    myList.print_nodes();
    
    myList.send_to_file();
    return 0;
}