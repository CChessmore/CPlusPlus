
public class MainWordle {
    public static void main(String[] args) {
        //Get random word from WordBank enum
        //Allow up to 5 guesses
        //If a letter in a word is correct, reveal it
        //After 5 guesses, if word isn't found, display loss
        //If correct word is guessed, display win message
        WordBank guessMe = WordBank.randWordBank();
    }
}
