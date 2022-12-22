#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

template <typename T>
class Set{
private:
    vector<T> vctr;
public:
    const vector<T> &getVctr() const;

    Set(const vector<T> &vctr) : vctr(vctr) {}
    //default constructor
    Set();
    bool operator==(Set& anotherSet);
    bool operator!=(Set& anotherSet);
    //Add item function and the user enters a parameter
    void Add_Item(T item);
    //Add item function and the user gets a message
    void Add_Item();
    //Remove item function and the user enters a parameter
    void Remove_Item(T item);
    //Remove item function and the user gets a message
    void Remove_Item();
    //counts the number of elements in the set
    int CountItems();
    //Checks if this value is in the set
    bool IsInSet(T item);
    //User gets a message and checks if this value is in the set
    bool IsInSet();
    T* begin();
};
//Function to add an item into the set
template<typename T>
void Set<T>::Add_Item(T item){
   if(!IsInSet(item)){
       this->vctr.push_back(item);
       cout<<item<<" has been added to the set";
   }
   else if(IsInSet(item))
       cout << item << " is already in set." << endl;
}

//Function to add an item into the set
template<typename T>
void Set<T>::Add_Item(){
    cout<<"Please enter the item you would like to add to this set: ";
    T st;
    cin>>st;
    Add_Item(st);
    cout<<endl;
}
//Function to remove an item from the set
template<typename T>
void Set<T>::Remove_Item(T item){
    if(IsInSet(item)){
        std::remove(vctr.begin(), vctr.end(), item);
//        vctr.pop_back();
    }
    else
        cout<<"This value is not the set.";
}

//Function to remove an item from the set
template<typename T>
void Set<T>::Remove_Item() {
    cout<<"Please enter the item that you would like to remove from this set";
    T st;
    cin>>st;
    Remove_Item(st);
}

//Function to count the items in the set
template<typename T>
int Set<T>::CountItems() {
    return vctr.size();
}

//Function to find if the item is in the set or not
template<typename T>
bool Set<T>::IsInSet(T item) {
    for(int i = 0; i < vctr.size(); i++){
        if(vctr[i] == item) return true;
    }
    return false;
}

//Function to find if the item is in the set or not
template<typename T>
bool Set<T>::IsInSet() {
    cout<<"Please enter the item that you would like to remove from this set";
    T st;
    cin>>st;
    return IsInSet(st);
}

template<typename T>
Set<T>::Set() {
    vctr = new vector<T>;
}

template<typename T>
T *Set<T>::begin() {
    T* ptr=vctr;
    return ptr;
}

template<typename T>
bool Set<T>::operator==(Set& anotherSet) {
    if (CountItems() != anotherSet.CountItems()) return false;
    for(int i = 0; i < vctr.size(); i++){
        if(!anotherSet.IsInSet(vctr[i])) return false;
    }
    return true;
}

template<typename T>
bool Set<T>::operator!=(Set& anotherSet) {
    if(CountItems() != anotherSet.CountItems()) return true;
    for(int i = 0; i < vctr.size(); i++){
        if(!anotherSet.IsInSet(vctr[i])) return true;
    }
    return false;
}

template<typename T>
const vector<T> &Set<T>::getVctr() const {
    return vctr;
}

int main() {
        vector<int> intv = {1, 3, 6, 8, 9};
        vector<int> intv2 = {1, 3, 6, 8, 9,10};
        vector<string> stringv = {"Laila","Aisha","Fares","Ahmed"};
        vector<string> stringv2 = {"Laila","Aisha","Fares","Ahmed"};
        Set<int> st1(intv);
        Set<int> st2(intv2);
        Set<string>st3(stringv);
        Set<string>st4(stringv2);
        //set of type int
        if(intv != intv2) cout << "These sets are not equal to each other" << endl;
        else if(intv==intv2) cout<<"These sets are equal to each other"<<endl;
        st1.Add_Item();
        st1.Remove_Item();
        for(int i=0;i<st1.getVctr().size();i++){
            cout<<st1.getVctr()[i]<<" ";
        }
        cout << endl;
        cout << st1.CountItems() << endl;
        cout << st1.IsInSet(8);
//set of type string
//        st2.Add_Item();
//        st2.Remove_Item();
//        for(int i=0;i<st2.getVctr().size();i++){
//        cout<<st2.getVctr()[i]<<" ";
//        }
//        cout << endl;
//        cout <<"The number of elements in this set: "<<st2.CountItems() << endl;
//        cout << st2.IsInSet("Ahmed");
//        string *p;
//        delete p;
}
