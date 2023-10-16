import java.util.Random;

public enum WordBank {
    //A smattering of 5 letter words for use in the game. I'm sure there's a better way to do this but an enum seemed perfect for something this size.
    APPLE, BEACH, BRAIN, BREAD, BRUSH, CHAIR, CHEST, CHORD, CLICK, CLOCK, CLOUD, DANCE, DRINK, EARTH, FLUTE, FRUIT, GHOST, GREEN, HAPPY, HOUSE, JUICE, PIZZA, RADIO, STORM, TIGER, TRAIN, WORLD, WRITE, YOUTH;

    private static final Random RNG = new Random();

    public static WordBank randWordBank() {
        WordBank[] wordBanks = values();
        return wordBanks[RNG.nextInt(wordBanks.length)];
    }
}
