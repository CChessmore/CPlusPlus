bool spin_the_wheel(int guess, int high);
int make_wager(int& wager, int& myNumber, int high, int points);
bool guess_is_right(int wager, int& multiplier, int& points);
int guess_is_wrong(int wager, int multiplier, int& points);

bool spin_the_wheel(int guess, int high)
{
    //We need a +1 here, as rand % N will return values between 0 and N-1
    //On first run this should result in a range of 0 to 5
    int winner = rand() % (high + 1);
    cout << "Wheel lands on " << winner << "!\n";
    if (guess == winner)
    {
        return true;
    }
    return false;
}

int make_wager(int& wager, int& myNumber, int high, int points)
{
    do
    {
        cout << "How many points would you like to wager (minimum of 1)? You currently have: " << points << " points." << endl;
        cin >> wager;
        cout << "Guess a number between 0 and " << high << " inclusive." << endl;
        cin >> myNumber;
    } while (!(wager < points + 1 && myNumber <= high));
    return myNumber;
}

bool guess_is_right(int wager, int& multiplier, int& points)
{
    points += wager * multiplier;
    cout << "Winner! You got " << wager * multiplier << " points!\n";
    cout << "You now have: " << points << " points!\n";
    wager = wager * multiplier;
    multiplier = multiplier + multiplier;
    return true;
}

int guess_is_wrong(int wager, int multiplier, int& points)
{
    cout << "Sorry, better luck next time!" << endl;
    points = points - wager;
    cout << "You lost " << wager << " points, leaving you with " << points << endl;
    return points;
}