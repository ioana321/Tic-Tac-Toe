#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

char verif( vector<char> a ) {
    if (a[0] == a[1] && a[0] == a[2] && a[0] != '_')
        return a[0];
    if (a[0] == a[3] && a[0] == a[6] && a[0] != '_')
        return a[0];
    if (a[6] == a[7] && a[6] == a[8] && a[6] != '_')
        return a[6];
    if (a[2] == a[5] && a[2] == a[8] && a[2] != '_')
        return a[2];
    if (a[0] == a[4] && a[0] == a[8] && a[0] != '_')
        return a[0];
    if (a[3] == a[4] && a[3] == a[5] && a[3] != '_')
        return a[3];
    if (a[1] == a[4] && a[1] == a[7] && a[1] != '_')
        return a[1];
    if (a[2] == a[4] && a[2] == a[6] && a[2] != '_')
        return a[2];
    else return 0;
}

void out(vector<char> a) {

    cout << a[0] << ' ' << a[1] << ' ' << a[2] << endl;
    cout << a[3] << ' ' << a[4] << ' ' << a[5] << endl;
    cout << a[6] << ' ' << a[7] << ' ' << a[8] << endl;

}

void position(vector<char> &a, char x) {

    int pos;
    while (x) {
        cin >> pos;
        if (pos > 9)
            cout << "Invalid position. Pick another one between 1 and 9: ";
        else {
            if (a[pos - 1] == '_')
            {
                a[pos - 1] = x;
                break;
            }
            else
                cout << "Invalid position. Pick another: ";
        }
    }

}

int main()
{
    vector<char> a = { '_','_','_','_','_','_','_','_','_' };
    int pos;
    cout << "TIC-TAC-TOE\nStart game.\n";
    system("pause");
    cout << "_ _ _\n_ _ _\n_ _ _\n";
    cout << "\nPlayer X pick position (1, 2, 3, 4, 5, 6, 7, 8 or 9): ";
    while (a[0]) {
        cin >> pos;
        if(pos>9)
            cout << "Invalid position. Pick another one between 1 and 9: ";
        else {
            a[pos - 1] = 'X';
            break;
        }
    }
    do {
        out(a);
        cout << "\nPlayer O pick position: ";
        position(a, 'O');
        cout << endl;
        out(a);
        if (verif(a))
            break;
        cout << "\nPlayer X pick position: ";
        position(a, 'X');
        cout << endl;
        if (verif(a))
        {
            out(a);
            break;
        }
    } while (!verif(a));
    cout << "\nPlayer " << verif(a) << " won! Congrats!\n";
    system("pause");
    return 0;
}
