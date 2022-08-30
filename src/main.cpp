#include <iostream>
#include <cstdlib>
#include <cstdio>
using std::cout;
using std::getchar;
using std::system;
using std::cin;
using std::cerr;

#define ENDL '\n'

enum tictoe {
    EMPTY,
    CROSS,
    CIRCLE
};

char trans(tictoe c) {
    int k=static_cast<int>(c);
    if(k==0) return ' ';
    else if(k==1) return 'X';
    else return 'O';
}

void print_board(tictoe map[3][3]) {
    for(int i=0;i<=1;i++) {
        cout<< trans(map[i][0]) << '|' << trans(map[i][1]) << '|' << trans(map[i][2]) << ENDL;
        cout<< "------" << ENDL;
    }
    cout<< trans(map[2][0]) << '|' << trans(map[2][1]) << '|' << trans(map[2][2]) << ENDL;
}

bool check_mate(tictoe map[3][3]) {
    int cross=0,circle=0;
    int num=0;
    for(int i=0;i<=2;i++) {
        for(int j=0;j<=2;j++) {
            if(map[i][j]== CIRCLE) {
                circle++;
                num++;
            }
            else {
                if(map[i][j]==CROSS) {
                    cross++;
                    num++;
                }
            }
        }
        if(circle==3 or (cross==3 or num==9)) {
            return true;
        }
        else {
            cross=0;
            circle=0;
        }
    }
    cross=0;
    circle=0;
    for(int j=0;j<=2;j++) {
        for(int i=0;i<=2;i++) {
            if(map[i][j]== CIRCLE) {
                circle++;
            }
            else {
                if(map[i][j]==CROSS) {
                    cross++;
                }
            }
        }
        if(circle==3 or cross==3) {
            return true;
        }
        else {
            cross=0;
            circle=0;
        }
    }
    cross=0;
    circle=0;
    for(int i=0;i<=2;i++) {
        if(map[i][i]==CIRCLE) {
            circle++;
        }
        else {
            if(map[i][i]==CROSS) {
                cross++;
            }
        }
    }
    if(circle==3 or cross==3) {
        return true;
    }
    else {
        cross=0;
        circle=0;
    }
    for(int i=2;i>=0;i--) {
        if(map[i][i]==CIRCLE) {
            circle++;
        }
        else {
            if(map[i][i]==CROSS) {
                cross++;
            }
        }
    }
    if(circle==3 or cross==3) {
        return true;
    }
    return false;
}

int main() {
    tictoe map[3][3];
    for(int i=0;i<=2;i++) {
        for(int j=0;j<=2;j++) {
            map[i][j] = EMPTY;
        }
    }
    system("cls");
    print_board(map);
    unsigned int a;
    bool is_circle=true;
    while(!check_mate(map)) {
        cout<<ENDL;
        cin>>a;
        unsigned int j=a%10;
        unsigned int i=(a-j)/10;
        if(a>22 or j>2) {
            cerr<<"It's not a valid number!";
            continue;
        }
        if(map[i][j] == CIRCLE or map[i][j] == CROSS) {
            cerr<<"You cannot place there!";
            continue;
        }
        if(is_circle) {
            map[i][j]=CIRCLE;
        }
        else {
            map[i][j]=CROSS;
        }
        system("cls");
        is_circle = !is_circle;
        print_board(map);
    }
    cout<<ENDL<<"GAME OVER!"<<ENDL;
    _sleep(5000);
    return 0;
}