#include<iostream>
using namespace std;
 
int main(){
    int n;
    cin>>n; //Input the number of the lines.
    
    while (n--) //For each loop, n--, so there will be n loops for n words.
    {
        string word;
        cin>>word; //Input the word
        if (word.length()<=10) //If the length of the word <=10, just output it.
            cout<<word<<endl;
        
        /*
        If the length of the word >10, 
        so get the first letter and last letter of the word, 
        and put the the length of the word minus 2 into the middle of the first letter and the last letter.
        */
        else
            cout<<word[0]<<word.length()-2<<word[word.length()-1]<<endl;
    }
    return 0;
}
