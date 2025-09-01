#include <iostream>
#include <string>
using namespace std;
int main() {
    char st1[100], st2[100];
    cout<<"Enter 1st string: ";
    cin.getline(st1,100);
    cout<<"Enter 2nd string: ";
    cin.getline(st2,100);
    int i=0,j=0;
    while (st1[i]!='\0') {
        i++;
    }
    while (st2[j]!='\0') {
        st1[i] = st2[j];
        i++;
        j++;
    }
    st1[i] = '\0';
    cout<<"Concatenated string: "<<st1;
    return 0;
}