#include <iostream>
#include <vector>
#include "string"
using namespace std;
class GamePiece
{
private:
    string value[9];

public:
    string previous;
    GamePiece()
    {
        for (int i = 0; i < 9; i++)
        {
            value[i] = " ";
        }
    }
    void print()
    {
        int temp = 0;
        int unicode = 0;
        for (auto i : value)
        {
            temp++;
            if (i == " ")
            {
                cout << temp << " ";
            }
            else
            {
                cout << i << " ";
            }
            if (temp % 3 == 0)
            {
                cout << endl;
                if (temp < 9)
                {
                    cout << "-   -   -" << endl;
                }
            }
            else
            {
                cout << " | ";
            }
        }
    }
    bool isfull()
    {
        for (auto &i : value)
        {
            if (i == " ")
            {
                return false;
            }
        }
        return true;
    }
    bool move(int position, string player)
    {
        if (position > 9 || position < 1)
        {
            cout << "please enter valid positions" << endl;;
            return false;
        }
        else if (player == this->previous)
        {
            cout << "it is not your turn!";
            return false;
        }
        else
        {
            this->value[position - 1] = player;
            this->previous = player;
        }
        return true;
    }
    bool winner()
    {
        for (int i = 0; i < 3; ++i)
        {
            if (value[i * 3] != " " && value[i * 3] == value[i * 3 + 1] && value[i * 3] == value[i * 3 + 2])
            {
                return true;
            }
        }

        for (int i = 0; i < 3; ++i)
        {
            if (value[i] != " " && value[i] == value[i + 3] && value[i] == value[i + 6])
            {
                return true;
            }
        }
        if (value[0] != " " && value[0] == value[4] && value[0] == value[8])
        {
            return true;
        }
        if (value[2] != " " && value[2] == value[4] && value[2] == value[6])
        {
            return true;
        }
        return false;
    }
    bool isturn(string player)
    {
        if (this->previous == player)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    GamePiece stage;

    while (true)
    {
        stage.print();
        if (stage.winner())
        {
            cout << stage.previous << " wins!";
            return -1;
        }

        else if (stage.isfull())
        {
            cout << "its a tie!";
            return -1;
        }
        cout << "Who are you? x or o?" << endl;
        string player;
        cin >> player;
        while (stage.isturn(player))
        {
            cout << "it is not your turn" << endl;
            cin >> player;
        }

        cout << "input position" << endl;
        int position;
        cin >> position;


        if (stage.move(position, player))
        {
            cout << player << " moved to " << position << endl;
        }
    }
}