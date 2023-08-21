#include <iostream>
using namespace std;

void bournVita() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif  
}

int main() {
    bournVita();

    int n, e;
    cin >> n >> e;

    int **board = new int*[n];

    for(int i=0; i<n; i++) {
        board[i] = new int[e];

        for(int j=0; j<e; j++) {
            board[i][j] = 0;
        }
    }

    for(int i=0; i<e; i++) {
        int f, s;
        cin >> f >> s;

        //For undirected Graph
        board[f][s] = 1;
        board[s][f] = 1;
    }

    for(int i=0; i<n; i++) {

        for(int j=0; j<e; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    //Delete a 2d matrix explicitly 
    for(int i=0; i<n; i++) {
        delete [] board[i];
    }

    delete [] board;

    return 0;
}