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
    int high = 5;
    bool cash_out = false;

    do
    {
        make_wager(wager, myNumber, high);
        if(guess_is_right())
        {
            
            
        }
    }
    while(!cash_out);

    return 0;
}

int spin_the_wheel(int high)
{
    //We need a +1 here, as rand % N will return values between 0 and N-1
    //On first run this should result in a range of 0 to 5
    return rand() % (high+1);
}

void make_wager(int &wager, int &myNumber, int high)
{
    cout << "How many points would you like to wager (minimum of 1)? You currently have: " << points << "points." << endl;
    cin >> wager;
    cout << "Guess a number between 1 and " << high << endl;
    cin >> myNumber;
}

bool guess_is_right(int wager, int &multiplier, int &points)
{
    cout << "Winner! You got " << wager * multiplier << " points!\n";
    cout << "You now have: " << points << " points!";
    wager = wager * multiplier;
    points += wager;
}