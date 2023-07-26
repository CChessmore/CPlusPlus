#include <iostream>
#include <cmath>

using namespace std;
/*Basic number roulette game.
1) User starts with 1000 points
2) User will enter a number between 1 and 5 to start
3) If they get a win, they earn back their bet amount plus 20%
4) User can "cash out" and save their score, or "let it ride" to reduce 
   their odds for bigger winnings (payouts double every round).

*/
int main() {
    int payout = 0;
    int points = 1000;
    //Minimum wager is 1
    int wager = 1;
    int myNumber;
    int multiplier = 2;
    int high_start = 5;
    bool cash_out = false;

    do
    {
        cout << "Guess a number between 1 and " << high_start << endl;
        cin >> myNumber;
    }
    while(!cash_out);

    return 0;
}

bool guess_is_right()
{

}