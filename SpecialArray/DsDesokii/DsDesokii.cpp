#include <iostream>
using namespace std;

class Array {
private:
    int size;
    int length;
    int* items;
public:
    Array(int arrsize) {
        size = arrsize;
        length = 0;
        items = new int[arrsize];

    }
    void Fill() {
        cout << "how many items you want to fill?\n";
        int no_of_items;
        cin >> no_of_items;
        if (no_of_items > size) {
            cout << "You cannot exceed the array size\n";
            return;
        }
        else {
            for (int i = 0; i < no_of_items; i++) {
                cout << "enter item no " << i << "\n";
                cin >> items[i];
                length++;
            }
        }



    }
    void Display() {
        cout << "Display Array content\n";
        for (int i = 0; i < size; i++) {
            cout << items[i] << "\t";
        }
        cout << "\n";
    }

    int getSize() {
        return size;
    }
    int getLength() {
        return length;
    }
    int Search(int key) {
        for (int i = 0; i < length; i++) {
            if (items[i] == key) {
                return i;
            }
        }
        return -1;
    }

    void Append(int newitem)
    {
        if (size > length) {
            items[length] = newitem;
            length++;
        }
        else {
            cout << "Array is full\n";
        }

    }
    void insert(int idx, int newitem) {
        if (idx >=0 and idx<=size and length<size) {
            for (int i = length; i > idx; i--) {
                items[i] = items[i - 1];
            }
            items[idx] = newitem;
            length++;
        }
        else {
            if (length >= size) {
                cout << "array is full\n";
            }
            else {
                cout << "index out of range\n";
            }
        }
        

    }

    void Delete(int idx) {
        if (length > 0 and size > 0 and idx >= 0 and idx < size) {

            for (int i = idx; i < length - 1; i++) {
                items[i] = items[i + 1];
            }
            items[length - 1] = -1;
            length--;
        }
        else {
            if (size == 0 or length == 0) {
                cout << "Array is empty\n";
            }
            else
                cout << "idx is out of range\n";
        }
    }
    



};

int main()
{
    int arraysize;
    cout << "Hello this is Array ADT demo\n";
    cout << "Enter the array size\n";
    cin >> arraysize;
    Array myarray(arraysize);
    myarray.Fill();
    myarray.Display();
    cout << "array size " << myarray.getSize() << "\n";
    cout << "array length " << myarray.getLength() << "\n";
    cout << "enter the value to search for \n";
    int key;
    cin >> key;
    int idx = myarray.Search(key);
    if (idx != -1) {
        cout << "index position is " << idx << "\n";
    }
    else
        cout << "item not found\n";
    int newitem;
    cout << "enter new item to append at the array\n";
       cin >> newitem;
    myarray.Append(newitem);
    myarray.Display();
    cout << "Enter index and item\n";
    cin >> idx;
    cin >> newitem;
    myarray.insert(idx, newitem);
    myarray.Display();
    cout << "array size " << myarray.getSize() << "\n";
    cout << "array length " << myarray.getLength() << "\n";
    cout << "enter index to delelte\n";
    cin >> idx;
    myarray.Delete(idx);

    myarray.Display();



}

