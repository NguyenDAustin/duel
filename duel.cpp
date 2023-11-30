#include <iostream>
#include <random>
#include <string>
#include <vector>
using namespace std;


int changeLP(int lp, int change, char pm)
{
    if (pm == 'g'){
        lp += change;
    }
    else if (pm == 'l'){
        lp -= change;
    }
    return lp;
}

string flipCoin(){
    random_device rd;
    string a;
    uniform_int_distribution<int> dist(0, 1);
    int ind = dist(rd);
    if (ind == 0){
        a = "heads";
    }
    else if (ind == 1){
        a = "tails";
    }
    return a;
}

int rollDice(int dice)
{
    random_device rd;
    int ind;
    if (dice == 1){
        uniform_int_distribution<int> dist(1, 6);
        ind = dist(rd);
    }
    else if (dice == 2){
        uniform_int_distribution<int> dist(2, 12);
        ind = dist(rd);
    }
    return ind;
}

int damageCalc()
{
    vector<int> calc;
    int a;
    int b = 0;
    cout << "-1 to finish" << endl;
    while (true){
        cin >> a;
        calc.push_back(a);
        if (a == -1){
        break;
        }
}
    calc.pop_back();
    for (int i = 0; i < calc.size(); i++){
        b += calc[i];
    }
    return b;
}

void display()
{
    cout << "1 for p1 lifepoints change" << endl;
    cout << "2 for p2 lifepoints change" << endl;
    cout << "3 for coin flip" << endl;
    cout << "4 for roll dice" << endl;
    cout << "5 for damage calculator" << endl;
}
int main()
{
    int p1 = 8000;
    int p2 = 8000;
    int player;
    int change;
    char type;
    int diceNum;

    do{
    cin >> player;
        switch (player){
            case 1: //lose life points for player 1
                cout << "amount >> gain or loss" << endl;
                cin >> change;
                cin >> type;
                p1 = changeLP(p1, change, type);
                cout << "Player 1 lifepoints: " << p1 << endl;
                cout << "Player 2 lifepoints: " << p2 << endl;
                break;

            case 2: //lose life points for player 2
                cout << "amount >> gain or loss" << endl;
                cin >> change;
                cin >> type;
                p2 = changeLP(p2, change, type);
                cout << "Player 1 lifepoints: " << p1 << endl;
                cout << "Player 2 lifepoints: " << p2 << endl;
                break;

            case 3:
                cout << flipCoin() << endl;;
                break;

            case 4:
                cout << "number of dice" << endl;
                cin >> diceNum;
                cout << rollDice(diceNum) << endl;
                break;
            
            case 5:
                cout << damageCalc() << endl;
                break;
        }
    
    } while (p1 >= 0 || p2 >= 0);
    return 0;
}