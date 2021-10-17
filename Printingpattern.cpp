#include<iostream>
#include<cstring>

using namespace std;

//pseudo char strA[] = "wxyz"
/* to print the following patterns i will print based off indexes, so looking at the
index at the start of the pattern and the index at the end. Incrementing between
iterations to print the full pattern. Taking the string above:
w = strA[0] -> strA[0] -- print
wx = strA[0] - > srtA[1] -- print
wxy = strA[0] -> strA[2] -- print
wxyz = strA[0] -> strA[3] -- print

looking at the pseudo above, its clear there must be two loops, one beginning at 0
and the other to increment from this to print the rest of the prefix.
*/

void printpatterns(char strA[])
{
 for(int last = 0; strA[last] != '\0'; last++) { //first loop to increment at 0

   for(int first = 0; first<=last;first++){ // second loop to increment from loop 1
    cout <<strA[first]; // print
 }
    cout << endl; // new line for next line
 }
}

int main()

{
    char str1[] = "ethan";
    printpatterns(str1);
    return 0;

}


