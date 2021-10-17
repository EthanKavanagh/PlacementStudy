#include<iostream>
using namespace std;

int length(char a[])
{
 int count = 0;
 for(int i =0; a[i] != '\0'; i++) { //reads up until terminator after the last character in the array
    count++;
 }
 return count;
}


void reverse(char input[])
{
    int start = 0;
    int end = length(input) -1;
    while(start < end) {
        swap(input[start], input[end]);
        start++;
        end--;
    }

}

int main()
{
    /*
    char b[100];

    cin >>b;
    cout << b;
    */

    char name[100];
    cout << "Please enter your name: " << endl;
    cin.getline(name,100);
    reverse(name);
    cout << "Name reversed: " << name;

}
