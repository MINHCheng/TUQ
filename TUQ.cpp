#include <iostream>
#include <vector>
#include "string"
using namespace std;
class GamePiece
{
private:
    string value[9];

public:
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
        for (auto i : value)
        {
            temp++;
            if (temp % 3 == 0)
            {
                cout << endl;
                cout << "-   -   -" << endl;
            }
            cout << i << " | ";
        }
    }
    void printwinner() {}
};
int main()
{
    while (true)
    {
        GamePiece stage;
        stage.print();
    }
}