#include <iostream>
#include<cstring>

using namespace std;
//function i will be looking at:
/*  1) strlen()
    2) strcmp()
    3) strcpy()
    4) strncpy()
    5) strcat()

//my version of the 'strcmp'
/*
looking at the version that is built into the <cstring> library, it returns a '0'
or non zero. The method simply subtracts the pointer of the same position at string
A as string B. These two values are subtracted and if it equals 0 (A[0] - B[0] == 0) then
the stings match. If another value is returned then the strings do not match. My version
will be simpler and use a boolean return type rather than int:
*/
bool strcmp2 (char strA[], char strB[])
{
    if(strlen(strA)!=strlen(strB))
    {
        return false;
    }
    for(int i=0;strA[i]!='\0';i++) //i personally prefer to write this way however you can say less than
    {
        if(strA[i] != strB[i])
        {

            return false;
        }
    }
    return true;
}

/*this is a basic blueprint to how strcpy works, I made a basic algorithm to show this
it iterates over the second string and assigns the values to the first string.
As it only has 1 for loop, this algorithm has a complexity of O(N). I have also
included the "<=" as I wanted to copy the null connector.
*/
void strcpy2(char strA[], char strB[])
{
    for(int i =0; i <= strlen(strA); i++) {
    strA[i] = strB[i];
    }
}

//another basic blueprint to how the 'strncopy' function works, implementation can be found below
void strncpy2(char strA[], char strB[], int n)
{
    for(int i =0; i < n; i++) { // this function will also copy over the null connectors
        strA[i] = strB[i];
    }
}
//blueprint to how strcat works which concatenates strings together, in this case strA+strB
void strcat2(char strA[], char strB[])
{
    int lA = strlen(strA);
    int lB = strlen(strB);

    for(int i=0 ; i < lB; i++) {
        strA[i+lA] = strB[i]; //use the index of the length of the string plus its size to add the letters onto the end
    }

}
int main()
{
        char str1[100] = "ethan";
        char str2[100] = "ab";

        cout << "Before concatenation:" << endl;
        cout << str1 << endl;
        cout << str2 << endl;

         strcat2(str1,str2);

        cout << "After concatenation:" << endl;
        cout << str1 << endl;









        //*********String copy*******
/*
        cout << "Before copy:" << endl;
        cout << str1 << endl;
        cout << str2 << endl;

         strcpy(str1,str2);

        cout << "After copy:" << endl;
        cout << str1 << endl;
        cout << str2 << endl;

        cout << "Before copy:" << endl;
        cout << str1 << endl;
        cout << str2 << endl;

         strcpy2(str1,str2);

        cout << "After copy:" << endl;
        cout << str1 << endl;
        cout << str2 << endl;

        cout << "Before copy:" << endl;
        cout << str1 << endl;
        cout << str2 << endl;

         strncpy(str1,str2);

        cout << "After copy:" << endl;
        cout << str1 << endl;
        cout << str2 << endl;
  */
  /*
        cout << "Before copy:" << endl;
        cout << str1 << endl;
        cout << str2 << endl;

         strncpy2(str1,str2,4);

        cout << "After copy:" << endl;
        cout << str1 << endl;
        cout << str2 << endl;
*/
        //*******String comapre********


        /*
        cin >> str1 >> str2;
        if(strcmp(str1,str2)== 0) {
            cout << "Equal" << endl;
        } else {

        cout <<"Not equal" << endl;
        }
*/
    /*
        if(strcmp2(str1,str2)) {
        cout << "Equal" << endl;
          } else {

        cout <<"Not equal" << endl;
        }
    */



}
