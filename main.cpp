#include <iostream>
#include "game.h"
#include <set>

using namespace std;

map<color, map<char, bool>> transposition;
void add_trans(char m, color c) {
    transposition[c][m] = true;
}

bool deja_vu(char m, color c) {
    return (transposition[c].count(m) != 0);
}

void solve(Game &, string = "");

int main() {
    Game g;
    transposition[green] = map<char, bool>();
    transposition[red] = map<char, bool>();
    transposition[blue] = map<char, bool>();

    solve(g);

    return 0;
}

void solve(Game &g, string indent) {
    vector<char> moves = g.moves();
    if(moves.size() == 0) {
        g.print_history();
        return;
    }
    if(deja_vu(g.node, g.active_color)) {
        return;
    }



    for(int i = 0; i < moves.size(); i++) {
        add_trans(g.node, g.active_color);
        g.move(moves.at(i));
        solve(g);
        g.undo();
    }
    
}

    // char m;
    // while (true) {
    //     vector<char> ee = g.moves();
    //     cout << "\nmoves: ";
    //     for(int i = 0; i < ee.size(); i++) {
    //         cout << ee.at(i) << " ";
    //     }
    //     cout << endl;
    //     cout << "enter move/Undo[U]: ";
    //     cin >> m;
    //     if(m == 'U') {
    //         g.undo();
    //     } else {
    //         g.move(m);
    //     }

        

    // }
