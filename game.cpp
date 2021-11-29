#include "game.h"
#include <sstream>
#include <fstream>
#include <vector>
#include <map>
#include <iostream>

Game::Game() {
    active_color = green;
    node = 'M';
    stuff[red] =  map<char, vector<char>>();
    stuff[green] = map<char, vector<char>>();
    stuff[blue] =  map<char, vector<char>>();
    load_maps();
    history.push_back(node);
}

void Game::print_history() {
    for(int i = 0; i < history.size(); i++) {
        cout << history.at(i) << " ";
    }
    cout << endl;
}

vector<char> Game::moves() {
   return stuff[active_color][node];
}

void Game::undo() {
    if(history.size() == 1) return;
    history.pop_back();
    node = history.back();
    decrement_color();
}

bool Game::is_move_valid(char m) {
    vector<char> _moves = this->moves();
    for(int i = 0; i < _moves.size(); i++) {
        if(m == _moves.at(i)) return true;
    }
    return false;
}

void Game::move(char m) {
    if(is_move_valid(m) == false) return;
    node = m;
    history.push_back(m);
    increment_color();
}

void Game::increment_color() {
    if(active_color == green) {
        active_color = blue;
    } else if(active_color == blue) {
        active_color = red;
    } else {
        active_color = green;
    }
}

void Game::decrement_color() {
    increment_color();
    increment_color();
}

void Game::load_maps() {
    ifstream ifs;
    ifs.open("input.txt");

    
    string str;
    while(getline(ifs, str)) {
        istringstream iss(str);
        char a, b, c;
        iss >> a >> b >> c;
        map<char, vector<char>> *curr = nullptr;

        if(c == 'R') {
           curr = &stuff[red];
        } else if(c == 'B') {
            curr = &stuff[blue];
        } else {
            curr = &stuff[green];
        }

        if(curr->count(a) == 0) {
                (*curr)[a] = {b};
        } else {
               (*curr)[a].push_back(b);
        }

        if(curr->count(b) == 0) {
            (*curr)[b] = {a};
        } else {
            (*curr)[b].push_back(a);
        }
    }
}

void Game::print_maps() {
    for(map<char, vector<char>>::iterator iter=stuff[green].begin(); iter != stuff[green].end(); ++iter)  {
        cout << iter-> first << "=> ";
        vector<char> a = iter->second;
        for(int i = 0; i < a.size(); i++) {
            cout << a.at(i) << " ";
        }
        cout << endl;
    }
}