#ifndef GAME__H
#define GAME__H

#include <vector>
#include <map>
using namespace std;

enum color { red, green, blue };
enum mode { greenStart, blueStart };

class Game {
    public: 
        Game(mode=greenStart);
        mode game_mode;
        vector<char> moves();
        void move(char);
        color active_color;
        char node;
        void undo();
        void print_history();
    private:
        void print_maps();
        bool is_move_valid(char);
        vector<char> history;
        void increment_color();
        void decrement_color();
        void load_maps();        
        map<color,map<char, vector<char>>> stuff;
        
};

#endif