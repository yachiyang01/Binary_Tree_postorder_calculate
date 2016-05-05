#include <iostream>
#include "BTree.cpp"
using namespace std;

float calculate(string input)
{
    int i = 0;
    float a,b;
    while( i < 9 )
    {
        switch(input[i])
        {
        case 'A':
            a = 100.1;
            break;
        case 'B':
            b = 10;
            break;
        case '/':
            a = a/b;
            break;
        case 'C':
            b = 1.2;
            break;
        case '*':
            a = a*b;
            break;
        case 'D':
            b = 2.9;
            break;
        case 'E':
            b = -10;
            break;
        case '+':
            a = a+b;
            break;
        default:
            cout<<"wrong";
        }
        i++;
    }
    return a;
}

int main()
{
    //A/B*C*D+E
    int i = 0;
    string input="A/B*C*D+E";
    string output;
    float result;
    BTree<char> tree(input[i]);
    i++;
    while(i<9)
    {
        char D,R;
        D = input[i];
        i++;
        R = input[i];
        i++;
        tree.insert(tree,*new BTree<char>(D),*new BTree<char>(R));
    }
    output = tree.postorder();
    cout << calculate(output);
}
