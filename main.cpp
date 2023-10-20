#include <iostream>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <sstream>
#include <random>
#include <string>
#include <vector>
#include <algorithm>

#include "textBox.h"
#include "textInput.h"

using namespace std;

void checkAbove(int x, int y, int *mines, int col, int row, int numMines, vector<int>& mpt, vector<sf::Sprite>& one, vector<sf::Sprite>& two, vector<sf::Sprite>& three, vector<sf::Sprite>& four, vector<sf::Sprite>& five, vector<sf::Sprite>& six, vector<sf::Sprite>& seven, vector<sf::Sprite>& eight, sf::Texture& oney, sf::Texture& twoy, sf::Texture& threey, sf::Texture& foury, sf::Texture& fivey, sf::Texture& sixy, sf::Texture& seveny, sf::Texture& eighty, vector<int>& pos, sf::Texture& clickd, vector<sf::Sprite>& clickSq, vector<sf::Sprite>& flags, vector<sf::Sprite>& jim);
void checkBelow(int x, int y, int *mines, int col, int row, int numMines, vector<int>& mpt, vector<sf::Sprite>& one, vector<sf::Sprite>& two, vector<sf::Sprite>& three, vector<sf::Sprite>& four, vector<sf::Sprite>& five, vector<sf::Sprite>& six, vector<sf::Sprite>& seven, vector<sf::Sprite>& eight, sf::Texture& oney, sf::Texture& twoy, sf::Texture& threey, sf::Texture& foury, sf::Texture& fivey, sf::Texture& sixy, sf::Texture& seveny, sf::Texture& eighty, vector<int>& pos, sf::Texture& clickd, vector<sf::Sprite>& clickSq, vector<sf::Sprite>& flags, vector<sf::Sprite>& jim);
void checkLeft(int x, int y, int *mines, int col, int row, int numMines, vector<int>& mpt, vector<sf::Sprite>& one, vector<sf::Sprite>& two, vector<sf::Sprite>& three, vector<sf::Sprite>& four, vector<sf::Sprite>& five, vector<sf::Sprite>& six, vector<sf::Sprite>& seven, vector<sf::Sprite>& eight, sf::Texture& oney, sf::Texture& twoy, sf::Texture& threey, sf::Texture& foury, sf::Texture& fivey, sf::Texture& sixy, sf::Texture& seveny, sf::Texture& eighty, vector<int>& pos, sf::Texture& clickd, vector<sf::Sprite>& clickSq, vector<sf::Sprite>& flags, vector<sf::Sprite>& jim);
void checkRight(int x, int y, int *mines, int col, int row, int numMines, vector<int>& mpt, vector<sf::Sprite>& one, vector<sf::Sprite>& two, vector<sf::Sprite>& three, vector<sf::Sprite>& four, vector<sf::Sprite>& five, vector<sf::Sprite>& six, vector<sf::Sprite>& seven, vector<sf::Sprite>& eight, sf::Texture& oney, sf::Texture& twoy, sf::Texture& threey, sf::Texture& foury, sf::Texture& fivey, sf::Texture& sixy, sf::Texture& seveny, sf::Texture& eighty, vector<int>& pos, sf::Texture& clickd, vector<sf::Sprite>& clickSq, vector<sf::Sprite>& flags, vector<sf::Sprite>& jim);
void checkTR(int x, int y, int *mines, int col, int row, int numMines, vector<int>&mpt, vector<sf::Sprite>& one, vector<sf::Sprite>& two, vector<sf::Sprite>& three, vector<sf::Sprite>& four, vector<sf::Sprite>& five, vector<sf::Sprite>& six, vector<sf::Sprite>& seven, vector<sf::Sprite>& eight, sf::Texture& oney, sf::Texture& twoy, sf::Texture& threey, sf::Texture& foury, sf::Texture& fivey, sf::Texture& sixy, sf::Texture& seveny, sf::Texture& eighty, vector<int>& pos, sf::Texture& clickd, vector<sf::Sprite>& clickSq, vector<sf::Sprite>& flags, vector<sf::Sprite>& jim);
void checkTL(int x, int y, int *mines, int col, int row, int numMines, vector<int>&mpt, vector<sf::Sprite>& one, vector<sf::Sprite>& two, vector<sf::Sprite>& three, vector<sf::Sprite>& four, vector<sf::Sprite>& five, vector<sf::Sprite>& six, vector<sf::Sprite>& seven, vector<sf::Sprite>& eight, sf::Texture& oney, sf::Texture& twoy, sf::Texture& threey, sf::Texture& foury, sf::Texture& fivey, sf::Texture& sixy, sf::Texture& seveny, sf::Texture& eighty, vector<int>& pos, sf::Texture& clickd, vector<sf::Sprite>& clickSq, vector<sf::Sprite>& flags, vector<sf::Sprite>& jim);
void checkBR(int x, int y, int *mines, int col, int row, int numMines, vector<int>&mpt, vector<sf::Sprite>& one, vector<sf::Sprite>& two, vector<sf::Sprite>& three, vector<sf::Sprite>& four, vector<sf::Sprite>& five, vector<sf::Sprite>& six, vector<sf::Sprite>& seven, vector<sf::Sprite>& eight, sf::Texture& oney, sf::Texture& twoy, sf::Texture& threey, sf::Texture& foury, sf::Texture& fivey, sf::Texture& sixy, sf::Texture& seveny, sf::Texture& eighty, vector<int>& pos, sf::Texture& clickd, vector<sf::Sprite>& clickSq, vector<sf::Sprite>& flags, vector<sf::Sprite>& jim);
void checkBL(int x, int y, int *mines, int col, int row, int numMines, vector<int>&mpt, vector<sf::Sprite>& one, vector<sf::Sprite>& two, vector<sf::Sprite>& three, vector<sf::Sprite>& four, vector<sf::Sprite>& five, vector<sf::Sprite>& six, vector<sf::Sprite>& seven, vector<sf::Sprite>& eight, sf::Texture& oney, sf::Texture& twoy, sf::Texture& threey, sf::Texture& foury, sf::Texture& fivey, sf::Texture& sixy, sf::Texture& seveny, sf::Texture& eighty, vector<int>& pos, sf::Texture& clickd, vector<sf::Sprite>& clickSq, vector<sf::Sprite>& flags, vector<sf::Sprite>& jim);
int changexy(int x, int y, int row, int col);

int main()
{

    ifstream file("files/board_config.cfg");
    int numCols, numRows, mineCount;
    string stringy;
    int counter1 = 0;
    while(getline(file, stringy))
    {
        if (counter1 == 0)
        {
            numCols = stoi(stringy);
        }
        else if (counter1 == 1)
        {
            numRows = stoi(stringy);
        }
        else
        {
            mineCount = stoi(stringy);
        }
        counter1++;
    }
    file.close();

    int width = numCols * 32;
    int height = numRows * 32 + 100;
    int tileCount = numCols * numRows;

    sf::Font font;
    font.loadFromFile("files/font.ttf");

    textBox welcomeTextBox = textBox("WELCOME TO MINESWEEPER!", font, 24, true, true, sf::Color::White, width/2.0f, height/2.0f - 150, width, height);
    sf::Text welcomeText = welcomeTextBox.getText();

    textBox inputPromptTextBox = textBox("Enter your name:", font, 20, true, false, sf::Color::White, width/2.0f, height/2.0f - 75, width, height);
    sf::Text inputPromptText = inputPromptTextBox.getText();

    inputBox inputTextBox = inputBox(18, sf::Color::Yellow, true, width/2.0f, height/2.0f - 45);
    inputTextBox.setFont(font);

    string name;
    bool openGame = false;

    sf::RenderWindow WelcomeWindow(sf::VideoMode(width, height), "Minesweeper", sf::Style::Close);

    while (WelcomeWindow.isOpen())
    {
        sf::Event event;
        while (WelcomeWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                WelcomeWindow.close();
            }
            else if (event.text.unicode == sf::Keyboard::Return && inputTextBox.text.str().length() > 0)
            {
                name = inputTextBox.text.str();
                WelcomeWindow.close();
                openGame = true;
            }
            else if (event.type == sf::Event::TextEntered)
            {
                inputTextBox.typed(event);
            }
        }
        WelcomeWindow.clear(sf::Color::Blue);

        WelcomeWindow.draw(welcomeText);
        WelcomeWindow.draw(inputPromptText);
        inputTextBox.drawOn(WelcomeWindow);

        WelcomeWindow.display();
    }

    for (int i = 0; i < name.length(); i++)
    {
        if (i == 0)
        {
            name[i] = toupper(name[i]);
        }
        else
        {
            name[i] = tolower(name[i]);
        }
    }

    if (openGame) {

        sf::RenderWindow GameWindow(sf::VideoMode(width, height), "Minesweeper", sf::Style::Close);

        sf::Texture hiddenTileTexture;
        hiddenTileTexture.loadFromFile("files/images/tile_hidden.png");

        //making hidden sprites
        sf::Sprite *tiles = new sf::Sprite[tileCount];
        int index = 0;
        for (int i = 0; i < numCols; i++) {
            for (int j = 0; j < numRows; j++) {
                sf::Sprite sprite;
                sprite.setTexture(hiddenTileTexture);
                sprite.setPosition(i * 32, j * 32);
                tiles[index] = sprite;
                index++;
            }
        }

        sf::Texture revealedTileTexture;
        revealedTileTexture.loadFromFile("files/images/tile_revealed.png");

        //making revealed sprites
        sf::Sprite *tilesRevealed = new sf::Sprite[tileCount];
        index = 0;
        for (int i = 0; i < numCols; i++) {
            for (int j = 0; j < numRows; j++) {
                sf::Sprite sprite;
                sprite.setTexture(revealedTileTexture);
                sprite.setPosition(i * 32, j * 32);
                tilesRevealed[index] = sprite;
                index++;
            }
        }

        //happy face button
        sf::Texture happyFaceTexture;
        happyFaceTexture.loadFromFile("files/images/face_happy.png");
        sf::Sprite happyFaceSprite;
        happyFaceSprite.setTexture(happyFaceTexture);
        happyFaceSprite.setPosition(numCols / 2.0f * 32 - 32, 32 * (numRows + 0.5f));

        //win face button
        sf::Texture winFaceTexture;
        winFaceTexture.loadFromFile("files/images/face_win.png");
        sf::Sprite winFaceSprite;
        winFaceSprite.setTexture(winFaceTexture);
        winFaceSprite.setPosition(numCols / 2.0f * 32 - 32, 32 * (numRows + 0.5f));

        //lose face button
        sf::Texture loseFaceTexture;
        loseFaceTexture.loadFromFile("files/images/face_lose.png");
        sf::Sprite loseFaceSprite;
        loseFaceSprite.setTexture(loseFaceTexture);
        loseFaceSprite.setPosition(numCols / 2.0f * 32 - 32, 32 * (numRows + 0.5f));

        //debug button
        sf::Texture debugTexture;
        debugTexture.loadFromFile("files/images/debug.png");
        sf::Sprite debugSprite;
        debugSprite.setTexture(debugTexture);
        debugSprite.setPosition(numCols * 32 - 304, 32 * (numRows + 0.5f));

        //pause button
        sf::Texture pauseTexture;
        pauseTexture.loadFromFile("files/images/pause.png");
        sf::Sprite pauseSprite;
        pauseSprite.setTexture(pauseTexture);
        pauseSprite.setPosition(numCols * 32 - 240, 32 * (numRows + 0.5f));

        //play button
        sf::Texture playTexture;
        playTexture.loadFromFile("files/images/play.png");
        sf::Sprite playSprite;
        playSprite.setTexture(playTexture);
        playSprite.setPosition(numCols * 32 - 240, 32 * (numRows + 0.5f));

        //leader button
        sf::Texture leaderTexture;
        leaderTexture.loadFromFile("files/images/leaderboard.png");
        sf::Sprite leaderSprite;
        leaderSprite.setTexture(leaderTexture);
        leaderSprite.setPosition(numCols * 32 - 176, 32 * (numRows + 0.5f));

        //making mine locations
        int *mineLocations = new int[mineCount];
        for (int i = 0; i < mineCount; i++) {
            mineLocations[i] = -1;
        }
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distr(0, tileCount - 1);
        for (int i = 0; i < mineCount; i++) {
            int num = distr(gen);

            bool bombReplicated = false;
            for (int j = 0; j < mineCount; j++) {
                if (mineLocations[j] == num) {
                    bombReplicated = true;
                }
            }
            while (bombReplicated) {
                num = distr(gen);

                bombReplicated = false;
                for (int j = 0; j < mineCount; j++) {
                    if (mineLocations[j] == num) {
                        bombReplicated = true;
                    }
                }
            }
            mineLocations[i] = num;
        }

        //mine sprite
        sf::Texture mineTexture;
        mineTexture.loadFromFile("files/images/mine.png");
        sf::Sprite* mines = new sf::Sprite[mineCount];
        for (int i = 0; i < mineCount; i++)
        {
            sf::Sprite sprite;
            sprite.setTexture(mineTexture);
            sprite.setPosition(mineLocations[i] / numRows * 32, mineLocations[i] % numRows * 32);
            mines[i] = sprite;
        }

        //vector for the clicked
        vector<sf::Sprite> clickedSquares;

        sf::Texture one;
        one.loadFromFile("files/images/number_1.png");
        sf::Texture two;
        two.loadFromFile("files/images/number_2.png");
        sf::Texture three;
        three.loadFromFile("files/images/number_3.png");
        sf::Texture four;
        four.loadFromFile("files/images/number_4.png");
        sf::Texture five;
        five.loadFromFile("files/images/number_5.png");
        sf::Texture six;
        six.loadFromFile("files/images/number_6.png");
        sf::Texture seven;
        seven.loadFromFile("files/images/number_7.png");
        sf::Texture eight;
        eight.loadFromFile("files/images/number_8.png");

        sf::Texture flag;
        flag.loadFromFile("files/images/flag.png");

        vector<sf::Sprite> nones;
        vector<sf::Sprite> ones;
        vector<sf::Sprite> twos;
        vector<sf::Sprite> threes;
        vector<sf::Sprite> fours;
        vector<sf::Sprite> fives;
        vector<sf::Sprite> sixes;
        vector<sf::Sprite> sevens;
        vector<sf::Sprite> eights;

        sf::Sprite counter1;
        sf::Sprite counter2;

        vector<sf::Sprite> jimmy;
        vector<int> positions;

        vector<sf::Sprite> flags;


        int currentTime1=0;
        int currentTime2=0;
        int currentTime3=0;
        int currentTime4=0;
        int currentTime12=0;
        int currentTime22=0;
        int currentTime32=0;
        int currentTime42=0;
        int tot4;

        int lbt1;
        int lbt2;
        int lbt3;
        int lbt4;

        int countNum;

        sf::Texture time;
        time.loadFromFile("files/images/digits.png");
        counter1.setTexture(time);
        counter2.setTexture(time);

        //controls
        bool showMines = false;
        bool paused = false;
        bool won = false;
        bool lost = false;
        bool clicked = false;
        bool debug = false;
        bool goIntoClock = false;
        bool returnhere = true;
        bool startOver = false;
        bool wonAdd = true;
        bool makeLB = false;
        sf::Clock clock2;
        sf::Clock clock;
        sf::Time spent2;
        sf::Time spent;

        while (GameWindow.isOpen()) {
            sf::Event event;
            while (GameWindow.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    GameWindow.close();
                }
                else if (event.type == event.MouseButtonReleased)
                {
                    clicked = false;
                }
            }

            GameWindow.clear(sf::Color::White);

            spent = clock.getElapsedTime();


            sf::Sprite abe;
            sf::Sprite dom;
            sf::Sprite louis;
            sf::Sprite ryan;
            if (!paused) {

                lbt1 = ((int) (spent.asSeconds() - tot4)) / 600;
                lbt2 = ((int) (spent.asSeconds() - tot4)) / 60;
                lbt3 = (((int) (spent.asSeconds() - tot4)) % 60) / 10;
                lbt4 = (((int) (spent.asSeconds() - tot4)) % 60) % 10;

                abe.setTexture(time);
                sf::IntRect rect(21 * ((((int) (spent.asSeconds() - tot4)) / 600)), 0, 21, 32);
                abe.setTextureRect(rect);
                abe.setPosition((numCols * 32) - 97, 32 * (numRows + 0.5f) + 16);
                GameWindow.draw(abe);

                dom.setTexture(time);
                sf::IntRect recty(21 * ((((int) (spent.asSeconds() - tot4)) / 60)), 0, 21, 32);
                dom.setTextureRect(recty);
                dom.setPosition((numCols * 32) - 97 + 21, 32 * (numRows + 0.5f) + 16);
                GameWindow.draw(dom);

                louis.setTexture(time);
                sf::IntRect rectile(21 * (((((int) (spent.asSeconds() - tot4)) % 60) / 10)), 0, 21, 32);
                louis.setTextureRect(rectile);
                louis.setPosition((numCols * 32) - 54, 32 * (numRows + 0.5f) + 16);
                GameWindow.draw(louis);

                ryan.setTexture(time);
                sf::IntRect rectilian(21 * (((((int) (spent.asSeconds() - tot4)) % 60) % 10)), 0, 21, 32);
                ryan.setTextureRect(rectilian);
                ryan.setPosition((numCols * 32) - 54 + 21, 32 * (numRows + 0.5f) + 16);
                GameWindow.draw(ryan);
            }
            else
            {
                abe.setTexture(time);
                sf::IntRect rect(21 * currentTime1, 0, 21, 32);
                abe.setTextureRect(rect);
                abe.setPosition((numCols * 32) - 97, 32 * (numRows + 0.5f) + 16);
                GameWindow.draw(abe);

                dom.setTexture(time);
                sf::IntRect recty(21 * currentTime2, 0, 21, 32);
                dom.setTextureRect(recty);
                dom.setPosition((numCols * 32) - 97 + 21, 32 * (numRows + 0.5f) + 16);
                GameWindow.draw(dom);

                louis.setTexture(time);
                sf::IntRect rectile(21 * currentTime3, 0, 21, 32);
                louis.setTextureRect(rectile);
                louis.setPosition((numCols * 32) - 54, 32 * (numRows + 0.5f) + 16);
                GameWindow.draw(louis);

                ryan.setTexture(time);
                sf::IntRect rectilian(21 * currentTime4, 0, 21, 32);
                ryan.setTextureRect(rectilian);
                ryan.setPosition((numCols * 32) - 54 + 21, 32 * (numRows + 0.5f) + 16);
                GameWindow.draw(ryan);
            }
            if (lost || won) {

                abe.setTexture(time);
                sf::IntRect rect(21 * currentTime1, 0, 21, 32);
                abe.setTextureRect(rect);
                abe.setPosition((numCols * 32) - 97, 32 * (numRows + 0.5f) + 16);
                GameWindow.draw(abe);

                dom.setTexture(time);
                sf::IntRect recty(21 * currentTime2, 0, 21, 32);
                dom.setTextureRect(recty);
                dom.setPosition((numCols * 32) - 97 + 21, 32 * (numRows + 0.5f) + 16);
                GameWindow.draw(dom);

                louis.setTexture(time);
                sf::IntRect rectile(21 * currentTime3, 0, 21, 32);
                louis.setTextureRect(rectile);
                louis.setPosition((numCols * 32) - 54, 32 * (numRows + 0.5f) + 16);
                GameWindow.draw(louis);

                ryan.setTexture(time);
                sf::IntRect rectilian(21 * currentTime4, 0, 21, 32);
                ryan.setTextureRect(rectilian);
                ryan.setPosition((numCols * 32) - 54 + 21, 32 * (numRows + 0.5f) + 16);
                GameWindow.draw(ryan);
            }

            if (!paused) {
                for (int i = 0; i < tileCount; i++) {
                    GameWindow.draw(tiles[i]);
                }
            }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !clicked)
            {
                clicked = true;
                sf::Vector2i mousePos = sf::Mouse::getPosition(GameWindow);

                if (((int)(mousePos.x)) >= happyFaceSprite.getPosition().x && ((int)(mousePos.x)) <= happyFaceSprite.getPosition().x + 64)
                {
                    if (((int)(mousePos.y)) >= happyFaceSprite.getPosition().y && ((int)(mousePos.y)) <= happyFaceSprite.getPosition().y + 64)
                    {
                        startOver = true;
                    }
                }

                if (((int)(mousePos.x)) >= leaderSprite.getPosition().x && ((int)(mousePos.x)) <= leaderSprite.getPosition().x + 64)
                {
                    if (((int)(mousePos.y)) >= leaderSprite.getPosition().y && ((int)(mousePos.y)) <= leaderSprite.getPosition().y + 64)
                    {
                        makeLB = true;
                    }
                }

                if (!lost and !won) {
                    if (mousePos.x >= debugSprite.getPosition().x && mousePos.x <= debugSprite.getPosition().x + 64) {
                        if (mousePos.y >= debugSprite.getPosition().y &&
                            mousePos.y <= debugSprite.getPosition().y + 64 && !paused) {
                            debug = !debug;
                        }
                    }

                    if (!paused) {
                        bool flagged = false;
                        for (int i = 0; i < mineCount; i++) {
                            if (((int) (mousePos.x) >= (mineLocations[i] / numRows * 32)) &&
                                ((int) (mousePos.x) <= (mineLocations[i] / numRows * 32 + 32))) {
                                if (((int) (mousePos.y) >= (mineLocations[i] % numRows * 32)) &&
                                    ((int) (mousePos.y) <= (mineLocations[i] % numRows * 32 + 32))) {
                                    for (int j = 0; j < flags.size(); j++) {
                                        if ((mousePos.x - mousePos.x % 32) == flags[j].getPosition().x &&
                                            mousePos.y - mousePos.y % 32 == flags[j].getPosition().y) {
                                            flagged = true;
                                        }
                                    }
                                    if (!flagged) {
                                        showMines = true;
                                        lost = true;
                                    }
                                }
                            }
                        }
                        for (int a = 0; a < flags.size(); a++) {
                            if ((mousePos.x - mousePos.x % 32) == flags[a].getPosition().x &&
                                mousePos.y - mousePos.y % 32 == flags[a].getPosition().y) {
                                flagged = true;
                            }
                        }
                        if ((int) mousePos.y / 32 < numRows && !flagged) {
                            int spaceClicked = (mousePos.x / 32) * numRows + (mousePos.y / 32);
                            bool addToPos = true;
                            if (positions.size() == 0)
                            {
                                positions.push_back(spaceClicked);
                            }
                            else {
                                for (int ab = 0; ab < positions.size(); ab++) {
                                    if (positions[ab] == spaceClicked) {
                                        addToPos = false;
                                    }
                                }
                            }
                            if (addToPos) {
                                positions.push_back(spaceClicked);

                                for (int j = 0; j < flags.size(); j++) {
                                    if ((mousePos.x - mousePos.x % 32) == flags[j].getPosition().x &&
                                        mousePos.y - mousePos.y % 32 == flags[j].getPosition().y) {
                                        flags.erase(flags.begin() + j);
                                    }
                                }
                                //cout << spaceClicked << endl;
                                int sum = 0;
                                if (mousePos.x / 32 * numRows == 0 && mousePos.y / 32 == 0) {
                                    //cout << "top left" << endl;
                                    int r = spaceClicked + numRows;
                                    for (int i = 0; i < mineCount; i++) {
                                        if (r == mineLocations[i]) {
                                            sum += 1;
                                        }
                                    }
                                    int b = spaceClicked + 1;
                                    for (int i = 0; i < mineCount; i++) {
                                        if (b == mineLocations[i]) {
                                            sum += 1;
                                        }
                                    }
                                    int br = spaceClicked + 1 + numRows;
                                    for (int i = 0; i < mineCount; i++) {
                                        if (br == mineLocations[i]) {
                                            sum += 1;
                                        }
                                    }
                                } else if (mousePos.x / 32 == numCols - 1 && mousePos.y / 32 == 0) {
                                    //cout << "top right" << endl;
                                    int l = spaceClicked - numRows;
                                    for (int i = 0; i < mineCount; i++) {
                                        if (l == mineLocations[i]) {
                                            sum += 1;
                                        }
                                    }
                                    int bl = spaceClicked + 1 - numRows;
                                    for (int i = 0; i < mineCount; i++) {
                                        if (bl == mineLocations[i]) {
                                            sum += 1;
                                        }
                                    }
                                    int b = spaceClicked + 1;
                                    for (int i = 0; i < mineCount; i++) {
                                        if (b == mineLocations[i]) {
                                            sum += 1;
                                        }
                                    }
                                } else if (mousePos.x / 32 == 0 && mousePos.y / 32 == numRows - 1) {
                                    //cout << "bottom left" << endl;
                                    int t = spaceClicked - 1;
                                    for (int i = 0; i < mineCount; i++) {
                                        if (t == mineLocations[i]) {
                                            sum += 1;
                                        }
                                    }
                                    int tr = spaceClicked - 1 + numRows;
                                    for (int i = 0; i < mineCount; i++) {
                                        if (tr == mineLocations[i]) {
                                            sum += 1;
                                        }
                                    }
                                    int r = spaceClicked + numRows;
                                    for (int i = 0; i < mineCount; i++) {
                                        if (r == mineLocations[i]) {
                                            sum += 1;
                                        }
                                    }
                                } else if (mousePos.x / 32 == numCols - 1 && mousePos.y / 32 == numRows - 1) {
                                    //cout << "bottom right" << endl;
                                    int t = spaceClicked - 1;
                                    for (int i = 0; i < mineCount; i++) {
                                        if (t == mineLocations[i]) {
                                            sum += 1;
                                        }
                                    }
                                    int tl = spaceClicked - 1 - numRows;
                                    for (int i = 0; i < mineCount; i++) {
                                        if (tl == mineLocations[i]) {
                                            sum += 1;
                                        }
                                    }
                                    int l = spaceClicked - numRows;
                                    for (int i = 0; i < mineCount; i++) {
                                        if (l == mineLocations[i]) {
                                            sum += 1;
                                        }
                                    }
                                } else if (mousePos.x / 32 == 0) {
                                    //cout << "left" << endl;
                                    int t = spaceClicked - 1;
                                    for (int i = 0; i < mineCount; i++) {
                                        if (t == mineLocations[i]) {
                                            sum += 1;
                                        }
                                    }
                                    int tr = spaceClicked - 1 + numRows;
                                    for (int i = 0; i < mineCount; i++) {
                                        if (tr == mineLocations[i]) {
                                            sum += 1;
                                        }
                                    }
                                    int r = spaceClicked + numRows;
                                    for (int i = 0; i < mineCount; i++) {
                                        if (r == mineLocations[i]) {
                                            sum += 1;
                                        }
                                    }
                                    int b = spaceClicked + 1;
                                    for (int i = 0; i < mineCount; i++) {
                                        if (b == mineLocations[i]) {
                                            sum += 1;
                                        }
                                    }
                                    int br = spaceClicked + 1 + numRows;
                                    for (int i = 0; i < mineCount; i++) {
                                        if (br == mineLocations[i]) {
                                            sum += 1;
                                        }
                                    }
                                } else if (mousePos.x / 32 == numCols - 1) {
                                    //cout << "right" << endl;
                                    int t = spaceClicked - 1;
                                    for (int i = 0; i < mineCount; i++) {
                                        if (t == mineLocations[i]) {
                                            sum += 1;
                                        }
                                    }
                                    int tl = spaceClicked - 1 - numRows;
                                    for (int i = 0; i < mineCount; i++) {
                                        if (tl == mineLocations[i]) {
                                            sum += 1;
                                        }
                                    }
                                    int l = spaceClicked - numRows;
                                    for (int i = 0; i < mineCount; i++) {
                                        if (l == mineLocations[i]) {
                                            sum += 1;
                                        }
                                    }
                                    int bl = spaceClicked + 1 - numRows;
                                    for (int i = 0; i < mineCount; i++) {
                                        if (bl == mineLocations[i]) {
                                            sum += 1;
                                        }
                                    }
                                    int b = spaceClicked + 1;
                                    for (int i = 0; i < mineCount; i++) {
                                        if (b == mineLocations[i]) {
                                            sum += 1;
                                        }
                                    }
                                } else if (mousePos.y / 32 == numRows - 1) {
                                    //cout << "bottom" << endl;
                                    int t = spaceClicked - 1;
                                    for (int i = 0; i < mineCount; i++) {
                                        if (t == mineLocations[i]) {
                                            sum += 1;
                                        }
                                    }
                                    int tl = spaceClicked - 1 - numRows;
                                    for (int i = 0; i < mineCount; i++) {
                                        if (tl == mineLocations[i]) {
                                            sum += 1;
                                        }
                                    }
                                    int tr = spaceClicked - 1 + numRows;
                                    for (int i = 0; i < mineCount; i++) {
                                        if (tr == mineLocations[i]) {
                                            sum += 1;
                                        }
                                    }
                                    int l = spaceClicked - numRows;
                                    for (int i = 0; i < mineCount; i++) {
                                        if (l == mineLocations[i]) {
                                            sum += 1;
                                        }
                                    }
                                    int r = spaceClicked + numRows;
                                    for (int i = 0; i < mineCount; i++) {
                                        if (r == mineLocations[i]) {
                                            sum += 1;
                                        }
                                    }
                                } else if (mousePos.y / 32 == 0) {
                                    //cout << "top" << endl;
                                    int l = spaceClicked - numRows;
                                    for (int i = 0; i < mineCount; i++) {
                                        if (l == mineLocations[i]) {
                                            sum += 1;
                                        }
                                    }
                                    int r = spaceClicked + numRows;
                                    for (int i = 0; i < mineCount; i++) {
                                        if (r == mineLocations[i]) {
                                            sum += 1;
                                        }
                                    }
                                    int bl = spaceClicked + 1 - numRows;
                                    for (int i = 0; i < mineCount; i++) {
                                        if (bl == mineLocations[i]) {
                                            sum += 1;
                                        }
                                    }
                                    int b = spaceClicked + 1;
                                    for (int i = 0; i < mineCount; i++) {
                                        if (b == mineLocations[i]) {
                                            sum += 1;
                                        }
                                    }
                                    int br = spaceClicked + 1 + numRows;
                                    for (int i = 0; i < mineCount; i++) {
                                        if (br == mineLocations[i]) {
                                            sum += 1;
                                        }
                                    }
                                } else {
                                    int t = spaceClicked - 1;
                                    for (int i = 0; i < mineCount; i++) {
                                        if (t == mineLocations[i]) {
                                            sum += 1;
                                        }
                                    }
                                    int tl = spaceClicked - 1 - numRows;
                                    for (int i = 0; i < mineCount; i++) {
                                        if (tl == mineLocations[i]) {
                                            sum += 1;
                                        }
                                    }
                                    int tr = spaceClicked - 1 + numRows;
                                    for (int i = 0; i < mineCount; i++) {
                                        if (tr == mineLocations[i]) {
                                            sum += 1;
                                        }
                                    }
                                    int l = spaceClicked - numRows;
                                    for (int i = 0; i < mineCount; i++) {
                                        if (l == mineLocations[i]) {
                                            sum += 1;
                                        }
                                    }
                                    int r = spaceClicked + numRows;
                                    for (int i = 0; i < mineCount; i++) {
                                        if (r == mineLocations[i]) {
                                            sum += 1;
                                        }
                                    }
                                    int bl = spaceClicked + 1 - numRows;
                                    for (int i = 0; i < mineCount; i++) {
                                        if (bl == mineLocations[i]) {
                                            sum += 1;
                                        }
                                    }
                                    int b = spaceClicked + 1;
                                    for (int i = 0; i < mineCount; i++) {
                                        if (b == mineLocations[i]) {
                                            sum += 1;
                                        }
                                    }
                                    int br = spaceClicked + 1 + numRows;
                                    for (int i = 0; i < mineCount; i++) {
                                        if (br == mineLocations[i]) {
                                            sum += 1;
                                        }
                                    }
                                }
                                if (sum == 0) {
                                    sf::Sprite sprite;
                                    sprite.setTexture(revealedTileTexture);
                                    sprite.setPosition(mousePos.x - (mousePos.x % 32), mousePos.y - (mousePos.y % 32));
                                    jimmy.push_back(sprite);
                                    nones.push_back(sprite);
                                    bool rec = true;
                                    for (int a = 0; a < mineCount; a++) {
                                        if (mineLocations[a] == spaceClicked) {
                                            rec = false;
                                        }
                                    }
                                    if (rec) {
                                        vector<int> mpt;
                                        checkAbove(spaceClicked / numRows, spaceClicked % numRows, mineLocations,
                                                   numCols,
                                                   numRows, mineCount, mpt, ones, twos, threes, fours, fives, sixes, sevens, eights, one, two, three, four, five, six, seven, eight, positions, revealedTileTexture, clickedSquares, flags, jimmy);
                                        checkBelow(spaceClicked / numRows, spaceClicked % numRows, mineLocations,
                                                   numCols,
                                                   numRows, mineCount, mpt, ones, twos, threes, fours, fives, sixes, sevens, eights, one, two, three, four, five, six, seven, eight, positions, revealedTileTexture, clickedSquares, flags, jimmy);
                                        checkLeft(spaceClicked / numRows, spaceClicked % numRows, mineLocations,
                                                  numCols,
                                                  numRows, mineCount, mpt, ones, twos, threes, fours, fives, sixes, sevens, eights, one, two, three, four, five, six, seven, eight, positions, revealedTileTexture, clickedSquares, flags, jimmy);
                                        checkRight(spaceClicked / numRows, spaceClicked % numRows, mineLocations,
                                                   numCols,
                                                   numRows, mineCount, mpt, ones, twos, threes, fours, fives, sixes, sevens, eights, one, two, three, four, five, six, seven, eight, positions, revealedTileTexture, clickedSquares, flags, jimmy);
                                        for (int i = 0; i < mpt.size(); i++) {
                                            sf::Sprite s;
                                            s.setTexture(revealedTileTexture);
                                            s.setPosition(mpt[i] / numRows * 32, (mpt[i] % numRows) * 32);
                                            jimmy.push_back(s);
                                            nones.push_back(s);
                                            bool alreadyIn = false;
                                            for (int ac = 0; ac < positions.size(); ac++)
                                            {
                                                if (positions[ac] == mpt[i])
                                                {
                                                    alreadyIn = true;
                                                }
                                            }
                                            if (!alreadyIn)
                                            {positions.push_back(mpt[i]);}
                                        }
                                    }
                                } else if (sum == 1) {
                                    sf::Sprite sprite;
                                    sf::Sprite spriteBG;
                                    spriteBG.setTexture(revealedTileTexture);
                                    spriteBG.setPosition(mousePos.x - (mousePos.x % 32),
                                                         mousePos.y - (mousePos.y % 32));
                                    clickedSquares.push_back(spriteBG);
                                    sprite.setTexture(one);
                                    sprite.setPosition(mousePos.x - (mousePos.x % 32), mousePos.y - (mousePos.y % 32));
                                    jimmy.push_back(sprite);
                                    ones.push_back(sprite);
                                } else if (sum == 2) {
                                    sf::Sprite sprite;
                                    sf::Sprite spriteBG;
                                    spriteBG.setTexture(revealedTileTexture);
                                    spriteBG.setPosition(mousePos.x - (mousePos.x % 32),
                                                         mousePos.y - (mousePos.y % 32));
                                    clickedSquares.push_back(spriteBG);
                                    sprite.setTexture(two);
                                    sprite.setPosition(mousePos.x - (mousePos.x % 32), mousePos.y - (mousePos.y % 32));
                                    jimmy.push_back(sprite);
                                    ones.push_back(sprite);
                                } else if (sum == 3) {
                                    sf::Sprite sprite;
                                    sf::Sprite spriteBG;
                                    spriteBG.setTexture(revealedTileTexture);
                                    spriteBG.setPosition(mousePos.x - (mousePos.x % 32),
                                                         mousePos.y - (mousePos.y % 32));
                                    clickedSquares.push_back(spriteBG);
                                    sprite.setTexture(three);
                                    sprite.setPosition(mousePos.x - (mousePos.x % 32), mousePos.y - (mousePos.y % 32));
                                    jimmy.push_back(sprite);
                                    ones.push_back(sprite);
                                } else if (sum == 4) {
                                    sf::Sprite sprite;
                                    sf::Sprite spriteBG;
                                    spriteBG.setTexture(revealedTileTexture);
                                    spriteBG.setPosition(mousePos.x - (mousePos.x % 32),
                                                         mousePos.y - (mousePos.y % 32));
                                    clickedSquares.push_back(spriteBG);
                                    sprite.setTexture(four);
                                    sprite.setPosition(mousePos.x - (mousePos.x % 32), mousePos.y - (mousePos.y % 32));
                                    jimmy.push_back(sprite);
                                    ones.push_back(sprite);
                                } else if (sum == 5) {
                                    sf::Sprite sprite;
                                    sf::Sprite spriteBG;
                                    spriteBG.setTexture(revealedTileTexture);
                                    spriteBG.setPosition(mousePos.x - (mousePos.x % 32),
                                                         mousePos.y - (mousePos.y % 32));
                                    clickedSquares.push_back(spriteBG);
                                    sprite.setTexture(five);
                                    sprite.setPosition(mousePos.x - (mousePos.x % 32), mousePos.y - (mousePos.y % 32));
                                    jimmy.push_back(sprite);
                                    ones.push_back(sprite);
                                } else if (sum == 6) {
                                    sf::Sprite sprite;
                                    sf::Sprite spriteBG;
                                    spriteBG.setTexture(revealedTileTexture);
                                    spriteBG.setPosition(mousePos.x - (mousePos.x % 32),
                                                         mousePos.y - (mousePos.y % 32));
                                    clickedSquares.push_back(spriteBG);
                                    sprite.setTexture(six);
                                    sprite.setPosition(mousePos.x - (mousePos.x % 32), mousePos.y - (mousePos.y % 32));
                                    jimmy.push_back(sprite);
                                    ones.push_back(sprite);
                                } else if (sum == 7) {
                                    sf::Sprite sprite;
                                    sf::Sprite spriteBG;
                                    spriteBG.setTexture(revealedTileTexture);
                                    spriteBG.setPosition(mousePos.x - (mousePos.x % 32),
                                                         mousePos.y - (mousePos.y % 32));
                                    clickedSquares.push_back(spriteBG);
                                    sprite.setTexture(seven);
                                    sprite.setPosition(mousePos.x - (mousePos.x % 32), mousePos.y - (mousePos.y % 32));
                                    jimmy.push_back(sprite);
                                    ones.push_back(sprite);
                                } else if (sum == 8) {
                                    sf::Sprite sprite;
                                    sf::Sprite spriteBG;
                                    spriteBG.setTexture(revealedTileTexture);
                                    spriteBG.setPosition(mousePos.x - (mousePos.x % 32),
                                                         mousePos.y - (mousePos.y % 32));
                                    clickedSquares.push_back(spriteBG);
                                    sprite.setTexture(eight);
                                    sprite.setPosition(mousePos.x - (mousePos.x % 32), mousePos.y - (mousePos.y % 32));
                                    jimmy.push_back(sprite);
                                    ones.push_back(sprite);
                                }
                            }
                        }
                    }
                    if (((int) (mousePos.x)) >= pauseSprite.getPosition().x &&
                        ((int) (mousePos.x)) <= (pauseSprite.getPosition().x + 64)) {
                        if (((int) (mousePos.y)) >= pauseSprite.getPosition().y &&
                            ((int) (mousePos.y)) <= (pauseSprite.getPosition().y + 64)) {
                            if (paused == false) {
                                currentTime1 = ((int) (clock.getElapsedTime().asSeconds() - tot4)) / 600;
                                currentTime2 = ((int) (clock.getElapsedTime().asSeconds() - tot4)) / 60;
                                currentTime3 = ((int) (clock.getElapsedTime().asSeconds() - tot4)) % 60 / 10;
                                currentTime4 = ((int) (clock.getElapsedTime().asSeconds() - tot4)) % 60 % 10;
                                clock2.restart();
                                goIntoClock = true;
                            } else {
                                tot4 += currentTime42;

                                goIntoClock = false;
                            }
                            paused = !paused;
                        }
                    }
                }

            }

            countNum = mineCount - flags.size();
            sf::IntRect cr1(21 * (abs(countNum) % 10), 0, 21, 32);
            counter1.setTextureRect(cr1);
            counter1.setPosition(33+42, 32 * (numRows+0.5f)+16);

            sf::IntRect cr2(21 * (abs(countNum) / 10), 0, 21, 32);
            counter2.setTextureRect(cr2);
            counter2.setPosition(33+21, 32 * (numRows+0.5f)+16);

            sf::Sprite extraDig;
            extraDig.setTexture(time);
            sf::IntRect cr3(21 * (abs(countNum) / 100), 0, 21, 32);
            extraDig.setTextureRect(cr3);
            extraDig.setPosition(33, 32*(numRows+0.5f)+16);
            GameWindow.draw(extraDig);

            if (countNum < 0)
            {
                sf::Sprite neg;
                neg.setTexture(time);
                sf::IntRect cr4(21 * 10, 0, 21, 32);
                neg.setTextureRect(cr4);
                neg.setPosition(33-21, 32*(numRows+0.5f)+16);
                GameWindow.draw(neg);
            }

            if (goIntoClock)
            {
                spent2 = clock2.getElapsedTime();
                currentTime12 = ((int)(clock2.getElapsedTime().asSeconds())) / 600;
                currentTime22 = ((int)(clock2.getElapsedTime().asSeconds())) / 60;
                currentTime32 = ((int)(clock2.getElapsedTime().asSeconds())) % 60 / 10;
                currentTime42 = ((int)(clock2.getElapsedTime().asSeconds()));
            }

            if ((lost || won) && returnhere)
            {
                returnhere = false;
                currentTime1 = ((int)(clock.getElapsedTime().asSeconds() - tot4)) / 600;
                currentTime2 = ((int)(clock.getElapsedTime().asSeconds() - tot4)) / 60;
                currentTime3 = ((int)(clock.getElapsedTime().asSeconds() - tot4)) % 60 / 10;
                currentTime4 = ((int)(clock.getElapsedTime().asSeconds() - tot4)) % 60 % 10;
            }

            if (!paused && sf::Mouse::isButtonPressed(sf::Mouse::Right) && !clicked && !(lost || won))
            {
                clicked = true;
                sf::Vector2i mousePos = sf::Mouse::getPosition(GameWindow);
                bool canDeFlag = false;
                int thisindex = 0;
                for (int i = 0; i < flags.size(); i++)
                {
                    if ((mousePos.x - mousePos.x % 32) == flags[i].getPosition().x && mousePos.y - mousePos.y % 32 == flags[i].getPosition().y)
                    {
                        canDeFlag = true;
                        thisindex = i;
                    }
                }
                if (canDeFlag)
                {
                    flags.erase(flags.begin() + thisindex);
                }
                else {
                    if ((int) mousePos.y / 32 < numRows) {
                        bool canFlag = true;
                        int spaceClicked = (mousePos.x / 32) * numRows + (mousePos.y / 32);
                        for (int i = 0; i < jimmy.size(); i++) {
                            if ((mousePos.x - mousePos.x % 32) == jimmy[i].getPosition().x &&
                                mousePos.y - mousePos.y % 32 == jimmy[i].getPosition().y) {
                                canFlag = false;
                            }
                        }
                        if (canFlag) {
                            sf::Sprite flagy;
                            flagy.setTexture(flag);
                            flagy.setPosition(mousePos.x - (mousePos.x % 32), mousePos.y - (mousePos.y % 32));
                            flags.push_back(flagy);
                        }
                    }
                }
            }

            for (int i = 0; i < clickedSquares.size(); i++)
            {
                GameWindow.draw(clickedSquares[i]);
            }
            for (int i = 0; i < nones.size(); i += 1)
            {
                GameWindow.draw(nones[i]);
            }
            for (int i = 0; i < ones.size(); i += 1)
            {
                GameWindow.draw(ones[i]);
            }
            for (int i = 0; i < twos.size(); i += 1)
            {
                GameWindow.draw(twos[i]);
            }
            for (int i = 0; i < threes.size(); i += 1)
            {
                GameWindow.draw(threes[i]);
            }
            for (int i = 0; i < fours.size(); i += 1)
            {
                GameWindow.draw(fours[i]);
            }
            for (int i = 0; i < fives.size(); i += 1)
            {
                GameWindow.draw(fives[i]);
            }
            for (int i = 0; i < sixes.size(); i += 1)
            {
                GameWindow.draw(sixes[i]);
            }
            for (int i = 0; i < sevens.size(); i += 1)
            {
                GameWindow.draw(sevens[i]);
            }
            for (int i = 0; i < eights.size(); i += 1)
            {
                GameWindow.draw(eights[i]);
            }
            for (int i = 0; i < flags.size(); i++)
            {
                GameWindow.draw(flags[i]);
            }

            GameWindow.draw(happyFaceSprite);

            if (paused)
            {
                GameWindow.draw(playSprite);
                for (int i = 0; i < tileCount; i++) {
                    GameWindow.draw(tilesRevealed[i]);
                }
            }
            else
            {
                GameWindow.draw(pauseSprite);
            }
            GameWindow.draw(leaderSprite);

            if ((showMines || debug) && !paused)
            {
                for (int i = 0; i < mineCount; i++)
                {
                    GameWindow.draw(mines[i]);
                }
            }

            GameWindow.draw(debugSprite);

            if (lost)
            {
                for (int i = 0; i < mineCount; i++)
                {
                    GameWindow.draw(mines[i]);
                }
                GameWindow.draw(loseFaceSprite);
            }
            if (positions.size() + mineCount == 402)
            {
                won = true;
            }
            if (won)
            {
                debug = false;
                if (wonAdd) {
                    flags.clear();
                    for (int i = 0; i < mineCount; i++) {
                        sf::Sprite newflag;
                        newflag.setTexture(flag);
                        newflag.setPosition((mineLocations[i] / numRows) * 32, (mineLocations[i] % numRows) * 32);
                        flags.push_back(newflag);
                    }

                    ifstream fle("files/leaderboard.txt");

                    string stringy1;
                    string stringy2;
                    string stringy3;
                    string stringy4;
                    string stringy5;

                    getline(fle, stringy1);
                    getline(fle, stringy2);
                    getline(fle, stringy3);
                    getline(fle, stringy4);
                    getline(fle, stringy5);

                    int time1 = stoi(stringy1.substr(0, 1)) * 600 + stoi(stringy1.substr(1, 2)) * 60 + stoi(stringy1.substr(3, 4)) * 10 + stoi(stringy1.substr(4, 5));
                    int time2 = stoi(stringy2.substr(0, 1)) * 600 + stoi(stringy2.substr(1, 2)) * 60 + stoi(stringy2.substr(3, 4)) * 10 + stoi(stringy2.substr(4, 5));
                    int time3 = stoi(stringy3.substr(0, 1)) * 600 + stoi(stringy3.substr(1, 2)) * 60 + stoi(stringy3.substr(3, 4)) * 10 + stoi(stringy3.substr(4, 5));
                    int time4 = stoi(stringy4.substr(0, 1)) * 600 + stoi(stringy4.substr(1, 2)) * 60 + stoi(stringy4.substr(3, 4)) * 10 + stoi(stringy4.substr(4, 5));
                    int time5 = stoi(stringy5.substr(0, 1)) * 600 + stoi(stringy5.substr(1, 2)) * 60 + stoi(stringy5.substr(3, 4)) * 10 + stoi(stringy5.substr(4, 5));

                    int winTime = lbt1 * 600 + lbt2 * 60 + lbt3 * 10 + lbt4;

                    int lbindex = -1;
                    if (winTime < time1)
                    {
                        lbindex = 0;
                    }
                    else if (winTime < time2)
                    {
                        lbindex = 1;
                    }
                    else if (winTime < time3)
                    {
                        lbindex = 2;
                    }
                    else if (winTime < time4)
                    {
                        lbindex = 3;
                    }
                    else if (winTime < time5)
                    {
                        lbindex = 4;
                    }

                    fle.close();
                    if (lbindex != -1)
                    {
                        ofstream fle("files/leaderboard.txt");

                        if (lbindex == 0)
                        {
                            fle << to_string(lbt1) + to_string(lbt2) + ":" + to_string(lbt3) + to_string(lbt4) + "," + name + "*\n";
                            fle << stringy1 + "\n";
                            fle << stringy2 + "\n";
                            fle << stringy3 + "\n";
                            fle << stringy4 + "\n";
                            fle << stringy5 + "\n";
                        }
                        else if (lbindex == 1)
                        {
                            fle << stringy1 + "\n";
                            fle << to_string(lbt1) + to_string(lbt2) + ":" + to_string(lbt3) + to_string(lbt4) + "," + name + "*\n";
                            fle << stringy2 + "\n";
                            fle << stringy3 + "\n";
                            fle << stringy4 + "\n";
                            fle << stringy5 + "\n";
                        }
                        else if (lbindex == 2)
                        {
                            fle << stringy1 + "\n";
                            fle << stringy2 + "\n";
                            fle << to_string(lbt1) + to_string(lbt2) + ":" + to_string(lbt3) + to_string(lbt4) + "," + name + "*\n";
                            fle << stringy3 + "\n";
                            fle << stringy4 + "\n";
                            fle << stringy5 + "\n";
                        }
                        else if (lbindex == 3)
                        {
                            fle << stringy1 + "\n";
                            fle << stringy2 + "\n";
                            fle << stringy3 + "\n";
                            fle << to_string(lbt1) + to_string(lbt2) + ":" + to_string(lbt3) + to_string(lbt4) + "," + name + "*\n";
                            fle << stringy4 + "\n";
                            fle << stringy5 + "\n";
                        }
                        else if (lbindex == 4)
                        {
                            fle << stringy1 + "\n";
                            fle << stringy2 + "\n";
                            fle << stringy3 + "\n";
                            fle << stringy4 + "\n";
                            fle << to_string(lbt1) + to_string(lbt2) + ":" + to_string(lbt3) + to_string(lbt4) + "," + name + "*\n";
                            fle << stringy5 + "\n";
                        }
                        fle.close();
                    }

                }

                wonAdd = false;
                GameWindow.draw(winFaceSprite);
            }

            GameWindow.draw(counter1);
            GameWindow.draw(counter2);

            if (startOver)
            {
                for (int i = 0; i < mineCount; i++) //old mines destroyed
                {
                    mineLocations[i] = -1;
                }
                for (int i = 0; i < mineCount; i++) { //new mines made
                    int num = distr(gen);

                    bool bombReplicated = false;
                    for (int j = 0; j < mineCount; j++) {
                        if (mineLocations[j] == num) {
                            bombReplicated = true;
                        }
                    }
                    while (bombReplicated) {
                        num = distr(gen);

                        bombReplicated = false;
                        for (int j = 0; j < mineCount; j++) {
                            if (mineLocations[j] == num) {
                                bombReplicated = true;
                            }
                        }
                    }
                    mineLocations[i] = num;
                }

                for (int i = 0; i < mineCount; i++)
                {
                    sf::Sprite sprite;
                    sprite.setTexture(mineTexture);
                    sprite.setPosition(mineLocations[i] / numRows * 32, mineLocations[i] % numRows * 32);
                    mines[i] = sprite;
                }

                clickedSquares.clear();

                nones.clear();
                ones.clear();
                twos.clear();
                threes.clear();
                fours.clear();
                fives.clear();
                sixes.clear();
                sevens.clear();
                eights.clear();
                positions.clear();

                jimmy.clear();

                flags.clear();

                currentTime1=0;
                currentTime2=0;
                currentTime3=0;
                currentTime4=0;
                currentTime12=0;
                currentTime22=0;
                currentTime32=0;
                currentTime42=0;
                tot4 = 0;

                countNum = 0;

                showMines = false;
                paused = false;
                won = false;
                lost = false;
                clicked = false;
                debug = false;
                goIntoClock = false;
                returnhere = true;
                startOver = false;
                wonAdd = true;

                clock2.restart();
                clock.restart();

            }
            if (makeLB)
            {
                for (int i = 0; i < tileCount; i++)
                {
                    GameWindow.draw(tilesRevealed[i]);
                }
            }
            GameWindow.display();
            if (makeLB) {
                if (!paused) {
                    clock2.restart();
                }

                textBox leaderBoardBox = textBox("LEADERBOARD", font, 20, true, true, sf::Color::White, width / 4,
                                                 height / 4 - 120, width / 2, height / 2);
                sf::Text leaderBoardText = leaderBoardBox.getText();

                ifstream file2("files/leaderboard.txt");

                string stringy1;
                string stringy2;
                string stringy3;
                string stringy4;
                string stringy5;

                makeLB = false;

                getline(file2, stringy1);
                getline(file2, stringy2);
                getline(file2, stringy3);
                getline(file2, stringy4);
                getline(file2, stringy5);

                file2.close();

                string finallb;
                finallb = "1.\t" + stringy1.substr(0, 5) + "\t" + stringy1.substr(6) + "\n\n2.\t" +
                          stringy2.substr(0, 5) + "\t" + stringy2.substr(6) + "\n\n3.\t" + stringy3.substr(0, 5) +
                          "\t" + stringy3.substr(6) + "\n\n4.\t" + stringy4.substr(0, 5) + "\t" + stringy4.substr(6) +
                          "\n\n5.\t" + stringy5.substr(0, 5) + "\t" + stringy5.substr(6);
                textBox leaderBoardCBox = textBox(finallb, font, 18, true, false, sf::Color::White, width / 4,
                                                  height / 4, width / 2, height / 2);
                sf::Text leaderBoardCText = leaderBoardCBox.getText();

                sf::RenderWindow leaderBoard(sf::VideoMode(width / 2, height / 2), "Minesweeper", sf::Style::Close);
                while (leaderBoard.isOpen()) {
                    sf::Event eventy;
                    while (leaderBoard.pollEvent(eventy)) {
                        if (eventy.type == sf::Event::Closed) {
                            leaderBoard.close();
                        }
                    }

                    leaderBoard.clear(sf::Color::Blue);

                    leaderBoard.draw(leaderBoardText);
                    leaderBoard.draw(leaderBoardCText);

                    leaderBoard.display();
                }

                currentTime42 = ((int) (clock2.getElapsedTime().asSeconds()));
                if (!paused) {
                    tot4 += currentTime42;
                }
            }

        }

        delete[] mineLocations;
        delete[] tiles;

    }
    return 0;
}

void checkAbove(int x, int y, int *mines, int col, int row, int numMines, vector<int>& mpt, vector<sf::Sprite>& one, vector<sf::Sprite>& two, vector<sf::Sprite>& three, vector<sf::Sprite>& four, vector<sf::Sprite>& five, vector<sf::Sprite>& six, vector<sf::Sprite>& seven, vector<sf::Sprite>& eight, sf::Texture& oney, sf::Texture& twoy, sf::Texture& threey, sf::Texture& foury, sf::Texture& fivey, sf::Texture& sixy, sf::Texture& seveny, sf::Texture& eighty, vector<int>& pos, sf::Texture& clickd, vector<sf::Sprite>& clickSq, vector<sf::Sprite>& flags, vector<sf::Sprite>& jim)
{
    bool flagged = false;
    for (int i = 0; i < flags.size(); i++)
    {
        if (((flags[i].getPosition().x) / 32 == x) && ((flags[i].getPosition().y) / 32 == y - 1))
        {
            flagged = true;
        }
    }
    if (flagged)
    {
        int x;
    }
    else {
        int sum = 0;
        bool cont = true;
        for (int k = 0; k < mpt.size(); k++) {
            if (mpt[k] == changexy(x, y - 1, row, col)) {
                cont = false;
            }
        }
        if (!cont) {
            int x;
        } else if (y == 0) {
            checkLeft(x, y, mines, col, row, numMines, mpt, one, two, three, four, five, six, seven, eight, oney, twoy,
                      threey, foury, fivey, sixy, seveny, eighty, pos, clickd, clickSq, flags, jim);
            checkRight(x, y, mines, col, row, numMines, mpt, one, two, three, four, five, six, seven, eight, oney, twoy,
                       threey, foury, fivey, sixy, seveny, eighty, pos, clickd, clickSq, flags, jim);
        } else if (y == 1) {
            mpt.push_back(changexy(x, y - 1, row, col));
            checkLeft(x, y - 1, mines, col, row, numMines, mpt, one, two, three, four, five, six, seven, eight, oney,
                      twoy, threey, foury, fivey, sixy, seveny, eighty, pos, clickd, clickSq, flags, jim);
            checkRight(x, y - 1, mines, col, row, numMines, mpt, one, two, three, four, five, six, seven, eight, oney,
                       twoy, threey, foury, fivey, sixy, seveny, eighty, pos, clickd, clickSq, flags, jim);
        } else {
            y -= 1;
            if (x == 0) //left side
            {
                for (int i = 0; i < numMines; i++) {
                    if (changexy(x, y - 1, row, col) == mines[i]) {
                        sum++;
                    }
                    if (changexy(x + 1, y - 1, row, col) == mines[i]) {
                        sum++;
                    }
                }
            } else if (x == col - 1) //right side
            {
                for (int i = 0; i < numMines; i++) {
                    if (changexy(x, y - 1, row, col) == mines[i]) {
                        sum++;
                    }
                    if (changexy(x - 1, y - 1, row, col) == mines[i]) {
                        sum++;
                    }
                }
            } else {
                for (int i = 0; i < numMines; i++) {
                    if (changexy(x, y - 1, row, col) == mines[i]) {
                        sum++;
                    }
                    if (changexy(x + 1, y - 1, row, col) == mines[i]) {
                        sum++;
                    }
                    if (changexy(x - 1, y - 1, row, col) == mines[i]) {
                        sum++;
                    }
                }
            }
            if (sum == 0) {
                mpt.push_back(changexy(x, y, row, col));
                checkAbove(x, y, mines, col, row, numMines, mpt, one, two, three, four, five, six, seven, eight, oney,
                           twoy, threey, foury, fivey, sixy, seveny, eighty, pos, clickd, clickSq, flags, jim);
                checkLeft(x, y, mines, col, row, numMines, mpt, one, two, three, four, five, six, seven, eight, oney,
                          twoy, threey, foury, fivey, sixy, seveny, eighty, pos, clickd, clickSq, flags, jim);
                checkRight(x, y, mines, col, row, numMines, mpt, one, two, three, four, five, six, seven, eight, oney,
                           twoy, threey, foury, fivey, sixy, seveny, eighty, pos, clickd, clickSq, flags, jim);
                checkTL(x, y, mines, col, row, numMines, mpt, one, two, three, four, five, six, seven, eight, oney, twoy,
                        threey, foury, fivey, sixy, seveny, eighty, pos, clickd, clickSq, flags, jim);
                checkTR(x, y, mines, col, row, numMines, mpt, one, two, three, four, five, six, seven, eight, oney, twoy,
                        threey, foury, fivey, sixy, seveny, eighty, pos, clickd, clickSq, flags, jim);
                checkBL(x, y, mines, col, row, numMines, mpt, one, two, three, four, five, six, seven, eight, oney, twoy,
                        threey, foury, fivey, sixy, seveny, eighty, pos, clickd, clickSq, flags, jim);
                checkBR(x, y, mines, col, row, numMines, mpt, one, two, three, four, five, six, seven, eight, oney, twoy,
                        threey, foury, fivey, sixy, seveny, eighty, pos, clickd, clickSq, flags, jim);
            } else if (sum == 1) {
                bool alreadyIn = false;
                int spclkd = changexy(x, y, row, col);
                for (int ac = 0; ac < pos.size(); ac++) {
                    if (pos[ac] == spclkd) {
                        alreadyIn = true;
                    }
                }
                if (!alreadyIn && x >= 0 && y >= 0 && x <= col - 1 && y <= row - 1) {
                    sf::Sprite spritey;
                    sf::Sprite spritey2;
                    spritey2.setTexture(clickd);
                    spritey2.setPosition(x * 32, y * 32);
                    clickSq.push_back(spritey2);
                    spritey.setTexture(oney);
                    spritey.setPosition(x * 32, y * 32);
                    one.push_back(spritey);
                    pos.push_back(spclkd);
                    jim.push_back(spritey2);
                }
            } else if (sum == 2) {
                bool alreadyIn = false;
                int spclkd = changexy(x, y, row, col);
                for (int ac = 0; ac < pos.size(); ac++) {
                    if (pos[ac] == spclkd) {
                        alreadyIn = true;
                    }
                }
                if (!alreadyIn && x >= 0 && y >= 0 && x <= col - 1 && y <= row - 1) {
                    sf::Sprite spritey;
                    sf::Sprite spritey2;
                    spritey2.setTexture(clickd);
                    spritey2.setPosition(x * 32, y * 32);
                    clickSq.push_back(spritey2);
                    spritey.setTexture(twoy);
                    spritey.setPosition(x * 32, y * 32);
                    two.push_back(spritey);
                    pos.push_back(spclkd);
                    jim.push_back(spritey2);
                }
            } else if (sum == 3) {
                bool alreadyIn = false;
                int spclkd = changexy(x, y, row, col);
                for (int ac = 0; ac < pos.size(); ac++) {
                    if (pos[ac] == spclkd) {
                        alreadyIn = true;
                    }
                }
                if (!alreadyIn && x >= 0 && y >= 0 && x <= col - 1 && y <= row - 1) {
                    sf::Sprite spritey;
                    sf::Sprite spritey2;
                    spritey2.setTexture(clickd);
                    spritey2.setPosition(x * 32, y * 32);
                    clickSq.push_back(spritey2);
                    spritey.setTexture(threey);
                    spritey.setPosition(x * 32, y * 32);
                    three.push_back(spritey);
                    pos.push_back(spclkd);
                    jim.push_back(spritey2);
                }
            } else if (sum == 4) {
                bool alreadyIn = false;
                int spclkd = changexy(x, y, row, col);
                for (int ac = 0; ac < pos.size(); ac++) {
                    if (pos[ac] == spclkd) {
                        alreadyIn = true;
                    }
                }
                if (!alreadyIn && x >= 0 && y >= 0 && x <= col - 1 && y <= row - 1) {
                    sf::Sprite spritey;
                    sf::Sprite spritey2;
                    spritey2.setTexture(clickd);
                    spritey2.setPosition(x * 32, y * 32);
                    clickSq.push_back(spritey2);
                    spritey.setTexture(foury);
                    spritey.setPosition(x * 32, y * 32);
                    four.push_back(spritey);
                    pos.push_back(spclkd);
                    jim.push_back(spritey2);
                }
            } else if (sum == 5) {
                bool alreadyIn = false;
                int spclkd = changexy(x, y, row, col);
                for (int ac = 0; ac < pos.size(); ac++) {
                    if (pos[ac] == spclkd) {
                        alreadyIn = true;
                    }
                }
                if (!alreadyIn && x >= 0 && y >= 0 && x <= col - 1 && y <= row - 1) {
                    sf::Sprite spritey;
                    sf::Sprite spritey2;
                    spritey2.setTexture(clickd);
                    spritey2.setPosition(x * 32, y * 32);
                    clickSq.push_back(spritey2);
                    spritey.setTexture(fivey);
                    spritey.setPosition(x * 32, y * 32);
                    five.push_back(spritey);
                    pos.push_back(spclkd);
                    jim.push_back(spritey2);
                }
            } else if (sum == 6) {
                bool alreadyIn = false;
                int spclkd = changexy(x, y, row, col);
                for (int ac = 0; ac < pos.size(); ac++) {
                    if (pos[ac] == spclkd) {
                        alreadyIn = true;
                    }
                }
                if (!alreadyIn && x >= 0 && y >= 0 && x <= col - 1 && y <= row - 1) {
                    sf::Sprite spritey;
                    sf::Sprite spritey2;
                    spritey2.setTexture(clickd);
                    spritey2.setPosition(x * 32, y * 32);
                    clickSq.push_back(spritey2);
                    spritey.setTexture(sixy);
                    spritey.setPosition(x * 32, y * 32);
                    six.push_back(spritey);
                    pos.push_back(spclkd);
                    jim.push_back(spritey2);
                }
            } else if (sum == 7) {
                bool alreadyIn = false;
                int spclkd = changexy(x, y, row, col);
                for (int ac = 0; ac < pos.size(); ac++) {
                    if (pos[ac] == spclkd) {
                        alreadyIn = true;
                    }
                }
                if (!alreadyIn && x >= 0 && y >= 0 && x <= col - 1 && y <= row - 1) {
                    sf::Sprite spritey;
                    sf::Sprite spritey2;
                    spritey2.setTexture(clickd);
                    spritey2.setPosition(x * 32, y * 32);
                    clickSq.push_back(spritey2);
                    spritey.setTexture(seveny);
                    spritey.setPosition(x * 32, y * 32);
                    seven.push_back(spritey);
                    pos.push_back(spclkd);
                    jim.push_back(spritey2);
                }
            } else if (sum == 8) {
                bool alreadyIn = false;
                int spclkd = changexy(x, y, row, col);
                for (int ac = 0; ac < pos.size(); ac++) {
                    if (pos[ac] == spclkd) {
                        alreadyIn = true;
                    }
                }
                if (!alreadyIn && x >= 0 && y >= 0 && x <= col - 1 && y <= row - 1) {
                    sf::Sprite spritey;
                    sf::Sprite spritey2;
                    spritey2.setTexture(clickd);
                    spritey2.setPosition(x * 32, y * 32);
                    clickSq.push_back(spritey2);
                    spritey.setTexture(eighty);
                    spritey.setPosition(x * 32, y * 32);
                    eight.push_back(spritey);
                    pos.push_back(spclkd);
                    jim.push_back(spritey2);
                }
            }
        }
    }
}

void checkBelow(int x, int y, int *mines, int col, int row, int numMines, vector<int>& mpt, vector<sf::Sprite>& one, vector<sf::Sprite>& two, vector<sf::Sprite>& three, vector<sf::Sprite>& four, vector<sf::Sprite>& five, vector<sf::Sprite>& six, vector<sf::Sprite>& seven, vector<sf::Sprite>& eight, sf::Texture& oney, sf::Texture& twoy, sf::Texture& threey, sf::Texture& foury, sf::Texture& fivey, sf::Texture& sixy, sf::Texture& seveny, sf::Texture& eighty, vector<int>& pos, sf::Texture& clickd, vector<sf::Sprite>& clickSq, vector<sf::Sprite>& flags, vector<sf::Sprite>& jim)
{
    bool flagged = false;
    for (int i = 0; i < flags.size(); i++)
    {
        if ((flags[i].getPosition().x) / 32 == x && (flags[i].getPosition().y) / 32 == y + 1)
        {
            flagged = true;
        }
    }
    if (flagged)
    {
        int x;
    }
    else {
        int sum = 0;
        bool cont = true;
        for (int k = 0; k < mpt.size(); k++) {
            if (mpt[k] == changexy(x, y + 1, row, col)) {
                cont = false;
            }
        }
        if (!cont) {
            int x;
        } else if (y == col - 1) // 16 is row
        {
            checkLeft(x, y, mines, col, row, numMines, mpt, one, two, three, four, five, six, seven, eight, oney, twoy,
                      threey, foury, fivey, sixy, seveny, eighty, pos, clickd, clickSq, flags, jim);
            checkRight(x, y, mines, col, row, numMines, mpt, one, two, three, four, five, six, seven, eight, oney, twoy,
                       threey, foury, fivey, sixy, seveny, eighty, pos, clickd, clickSq, flags, jim);
        } else if (y == col - 2) {
            mpt.push_back(changexy(x, y + 1, row, col));
            checkLeft(x, y + 1, mines, col, row, numMines, mpt, one, two, three, four, five, six, seven, eight, oney,
                      twoy, threey, foury, fivey, sixy, seveny, eighty, pos, clickd, clickSq, flags, jim);
            checkRight(x, y + 1, mines, col, row, numMines, mpt, one, two, three, four, five, six, seven, eight, oney,
                       twoy, threey, foury, fivey, sixy, seveny, eighty, pos, clickd, clickSq, flags, jim);
        } else {
            y += 1;
            if (x == 0) //left side
            {
                for (int i = 0; i < numMines; i++) {
                    if (changexy(x, y + 1, row, col) == mines[i]) {
                        sum++;
                    }
                    if (changexy(x + 1, y + 1, row, col) == mines[i]) {
                        sum++;
                    }
                }
            } else if (x == col - 1) //right side
            {
                for (int i = 0; i < numMines; i++) {
                    if (changexy(x, y + 1, row, col) == mines[i]) {
                        sum++;
                    }
                    if (changexy(x - 1, y + 1, row, col) == mines[i]) {
                        sum++;
                    }
                }
            } else {
                for (int i = 0; i < numMines; i++) {
                    if (changexy(x, y + 1, row, col) == mines[i]) {
                        sum++;
                    }
                    if (changexy(x - 1, y + 1, row, col) == mines[i]) {
                        sum++;
                    }
                    if (changexy(x + 1, y + 1, row, col) == mines[i]) {
                        sum++;
                    }
                }
            }
            if (sum == 0) {
                mpt.push_back(changexy(x, y, row, col));
                checkBelow(x, y, mines, col, row, numMines, mpt, one, two, three, four, five, six, seven, eight, oney,
                           twoy, threey, foury, fivey, sixy, seveny, eighty, pos, clickd, clickSq, flags, jim);
                checkLeft(x, y, mines, col, row, numMines, mpt, one, two, three, four, five, six, seven, eight, oney,
                          twoy, threey, foury, fivey, sixy, seveny, eighty, pos, clickd, clickSq, flags, jim);
                checkRight(x, y, mines, col, row, numMines, mpt, one, two, three, four, five, six, seven, eight, oney,
                           twoy, threey, foury, fivey, sixy, seveny, eighty, pos, clickd, clickSq, flags, jim);
                checkTL(x, y, mines, col, row, numMines, mpt, one, two, three, four, five, six, seven, eight, oney, twoy,
                        threey, foury, fivey, sixy, seveny, eighty, pos, clickd, clickSq, flags, jim);
                checkTR(x, y, mines, col, row, numMines, mpt, one, two, three, four, five, six, seven, eight, oney, twoy,
                        threey, foury, fivey, sixy, seveny, eighty, pos, clickd, clickSq, flags, jim);
                checkBL(x, y, mines, col, row, numMines, mpt, one, two, three, four, five, six, seven, eight, oney, twoy,
                        threey, foury, fivey, sixy, seveny, eighty, pos, clickd, clickSq, flags, jim);
                checkBR(x, y, mines, col, row, numMines, mpt, one, two, three, four, five, six, seven, eight, oney, twoy,
                        threey, foury, fivey, sixy, seveny, eighty, pos, clickd, clickSq, flags, jim);
            } else if (sum == 1) {
                bool alreadyIn = false;
                int spclkd = changexy(x, y, row, col);
                for (int ac = 0; ac < pos.size(); ac++) {
                    if (pos[ac] == spclkd) {
                        alreadyIn = true;
                    }
                }
                if (!alreadyIn && x >= 0 && y >= 0 && x <= col - 1 && y <= row - 1) {
                    sf::Sprite spritey;
                    sf::Sprite spritey2;
                    spritey2.setTexture(clickd);
                    spritey2.setPosition(x * 32, y * 32);
                    clickSq.push_back(spritey2);
                    spritey.setTexture(oney);
                    spritey.setPosition(x * 32, y * 32);
                    one.push_back(spritey);
                    pos.push_back(spclkd);
                    jim.push_back(spritey2);
                }
            } else if (sum == 2) {
                bool alreadyIn = false;
                int spclkd = changexy(x, y, row, col);
                for (int ac = 0; ac < pos.size(); ac++) {
                    if (pos[ac] == spclkd) {
                        alreadyIn = true;
                    }
                }
                if (!alreadyIn && x >= 0 && y >= 0 && x <= col - 1 && y <= row - 1) {
                    sf::Sprite spritey;
                    sf::Sprite spritey2;
                    spritey2.setTexture(clickd);
                    spritey2.setPosition(x * 32, y * 32);
                    clickSq.push_back(spritey2);
                    spritey.setTexture(twoy);
                    spritey.setPosition(x * 32, y * 32);
                    two.push_back(spritey);
                    pos.push_back(spclkd);
                    jim.push_back(spritey2);
                }
            } else if (sum == 3) {
                bool alreadyIn = false;
                int spclkd = changexy(x, y, row, col);
                for (int ac = 0; ac < pos.size(); ac++) {
                    if (pos[ac] == spclkd) {
                        alreadyIn = true;
                    }
                }
                if (!alreadyIn && x >= 0 && y >= 0 && x <= col - 1 && y <= row - 1) {
                    sf::Sprite spritey;
                    sf::Sprite spritey2;
                    spritey2.setTexture(clickd);
                    spritey2.setPosition(x * 32, y * 32);
                    clickSq.push_back(spritey2);
                    spritey.setTexture(threey);
                    spritey.setPosition(x * 32, y * 32);
                    three.push_back(spritey);
                    pos.push_back(spclkd);
                    jim.push_back(spritey2);
                }
            } else if (sum == 4) {
                bool alreadyIn = false;
                int spclkd = changexy(x, y, row, col);
                for (int ac = 0; ac < pos.size(); ac++) {
                    if (pos[ac] == spclkd) {
                        alreadyIn = true;
                    }
                }
                if (!alreadyIn && x >= 0 && y >= 0 && x <= col - 1 && y <= row - 1) {
                    sf::Sprite spritey;
                    sf::Sprite spritey2;
                    spritey2.setTexture(clickd);
                    spritey2.setPosition(x * 32, y * 32);
                    clickSq.push_back(spritey2);
                    spritey.setTexture(foury);
                    spritey.setPosition(x * 32, y * 32);
                    four.push_back(spritey);
                    pos.push_back(spclkd);
                    jim.push_back(spritey2);
                }
            } else if (sum == 5) {
                bool alreadyIn = false;
                int spclkd = changexy(x, y, row, col);
                for (int ac = 0; ac < pos.size(); ac++) {
                    if (pos[ac] == spclkd) {
                        alreadyIn = true;
                    }
                }
                if (!alreadyIn && x >= 0 && y >= 0 && x <= col - 1 && y <= row - 1) {
                    sf::Sprite spritey;
                    sf::Sprite spritey2;
                    spritey2.setTexture(clickd);
                    spritey2.setPosition(x * 32, y * 32);
                    clickSq.push_back(spritey2);
                    spritey.setTexture(fivey);
                    spritey.setPosition(x * 32, y * 32);
                    five.push_back(spritey);
                    pos.push_back(spclkd);
                    jim.push_back(spritey2);
                }
            } else if (sum == 6) {
                bool alreadyIn = false;
                int spclkd = changexy(x, y, row, col);
                for (int ac = 0; ac < pos.size(); ac++) {
                    if (pos[ac] == spclkd) {
                        alreadyIn = true;
                    }
                }
                if (!alreadyIn && x >= 0 && y >= 0 && x <= col - 1 && y <= row - 1) {
                    sf::Sprite spritey;
                    sf::Sprite spritey2;
                    spritey2.setTexture(clickd);
                    spritey2.setPosition(x * 32, y * 32);
                    clickSq.push_back(spritey2);
                    spritey.setTexture(sixy);
                    spritey.setPosition(x * 32, y * 32);
                    six.push_back(spritey);
                    pos.push_back(spclkd);
                    jim.push_back(spritey2);
                }
            } else if (sum == 7) {
                bool alreadyIn = false;
                int spclkd = changexy(x, y, row, col);
                for (int ac = 0; ac < pos.size(); ac++) {
                    if (pos[ac] == spclkd) {
                        alreadyIn = true;
                    }
                }
                if (!alreadyIn && x >= 0 && y >= 0 && x <= col - 1 && y <= row - 1) {
                    sf::Sprite spritey;
                    sf::Sprite spritey2;
                    spritey2.setTexture(clickd);
                    spritey2.setPosition(x * 32, y * 32);
                    clickSq.push_back(spritey2);
                    spritey.setTexture(seveny);
                    spritey.setPosition(x * 32, y * 32);
                    seven.push_back(spritey);
                    pos.push_back(spclkd);
                    jim.push_back(spritey2);
                }
            } else if (sum == 8) {
                bool alreadyIn = false;
                int spclkd = changexy(x, y, row, col);
                for (int ac = 0; ac < pos.size(); ac++) {
                    if (pos[ac] == spclkd) {
                        alreadyIn = true;
                    }
                }
                if (!alreadyIn && x >= 0 && y >= 0 && x <= col - 1 && y <= row - 1) {
                    sf::Sprite spritey;
                    sf::Sprite spritey2;
                    spritey2.setTexture(clickd);
                    spritey2.setPosition(x * 32, y * 32);
                    clickSq.push_back(spritey2);
                    spritey.setTexture(eighty);
                    spritey.setPosition(x * 32, y * 32);
                    eight.push_back(spritey);
                    pos.push_back(spclkd);
                    jim.push_back(spritey2);
                }
            }
        }
    }
}


void checkLeft(int x, int y, int *mines, int col, int row, int numMines, vector<int>& mpt, vector<sf::Sprite>& one, vector<sf::Sprite>& two, vector<sf::Sprite>& three, vector<sf::Sprite>& four, vector<sf::Sprite>& five, vector<sf::Sprite>& six, vector<sf::Sprite>& seven, vector<sf::Sprite>& eight, sf::Texture& oney, sf::Texture& twoy, sf::Texture& threey, sf::Texture& foury, sf::Texture& fivey, sf::Texture& sixy, sf::Texture& seveny, sf::Texture& eighty, vector<int>& pos, sf::Texture& clickd, vector<sf::Sprite>& clickSq, vector<sf::Sprite>& flags, vector<sf::Sprite>& jim)
{
    bool flagged = false;
    for (int i = 0; i < flags.size(); i++)
    {
        if ((flags[i].getPosition().x) / 32 == x - 1 && (flags[i].getPosition().y) / 32 == y)
        {
            flagged = true;
        }
    }
    if (flagged)
    {
        int x;
    }
    else {
        int sum = 0;
        bool cont = true;
        for (int k = 0; k < mpt.size(); k++) {
            if (mpt[k] == changexy(x - 1, y, row, col)) {
                cont = false;
            }
        }
        if (x == 0 || !cont) {
            int x;
        } else if (x == 1) {
            mpt.push_back(changexy(x - 1, y, row, col));
            checkBelow(x - 1, y, mines, col, row, numMines, mpt, one, two, three, four, five, six, seven, eight, oney,
                       twoy, threey, foury, fivey, sixy, seveny, eighty, pos, clickd, clickSq, flags, jim);
            checkAbove(x - 1, y, mines, col, row, numMines, mpt, one, two, three, four, five, six, seven, eight, oney,
                       twoy, threey, foury, fivey, sixy, seveny, eighty, pos, clickd, clickSq, flags, jim);
        } else {
            x -= 1;
            if (y == 0) //top side
            {
                for (int i = 0; i < numMines; i++) {
                    if (changexy(x - 1, y, row, col) == mines[i]) {
                        sum++;
                    }
                    if (changexy(x - 1, y + 1, row, col) == mines[i]) {
                        sum++;
                    }
                }
            } else if (y == row - 1) //bottom side
            {
                for (int i = 0; i < numMines; i++) {
                    if (changexy(x - 1, y, row, col) == mines[i]) {
                        sum++;
                    }
                    if (changexy(x - 1, y - 1, row, col) == mines[i]) {
                        sum++;
                    }
                }
            } else {
                for (int i = 0; i < numMines; i++) {
                    if (changexy(x - 1, y, row, col) == mines[i]) {
                        sum++;
                    }
                    if (changexy(x - 1, y - 1, row, col) == mines[i]) {
                        sum++;
                    }
                    if (changexy(x - 1, y + 1, row, col) == mines[i]) {
                        sum++;
                    }
                }
            }
            if (sum == 0) {
                bool add2 = true;
                for (int j = 0; j < mpt.size(); j++) {
                    if (mpt[j] == changexy(x, y, row, col)) {
                        add2 = false;
                    }
                }
                if (add2) {
                    mpt.push_back(changexy(x, y, row, col));
                }
                checkBelow(x, y, mines, col, row, numMines, mpt, one, two, three, four, five, six, seven, eight, oney,
                           twoy, threey, foury, fivey, sixy, seveny, eighty, pos, clickd, clickSq, flags, jim);
                checkAbove(x, y, mines, col, row, numMines, mpt, one, two, three, four, five, six, seven, eight, oney,
                           twoy, threey, foury, fivey, sixy, seveny, eighty, pos, clickd, clickSq, flags, jim);
                checkLeft(x, y, mines, col, row, numMines, mpt, one, two, three, four, five, six, seven, eight, oney,
                          twoy, threey, foury, fivey, sixy, seveny, eighty, pos, clickd, clickSq, flags, jim);
                checkTL(x, y, mines, col, row, numMines, mpt, one, two, three, four, five, six, seven, eight, oney, twoy,
                        threey, foury, fivey, sixy, seveny, eighty, pos, clickd, clickSq, flags, jim);
                checkTR(x, y, mines, col, row, numMines, mpt, one, two, three, four, five, six, seven, eight, oney, twoy,
                        threey, foury, fivey, sixy, seveny, eighty, pos, clickd, clickSq, flags, jim);
                checkBL(x, y, mines, col, row, numMines, mpt, one, two, three, four, five, six, seven, eight, oney, twoy,
                        threey, foury, fivey, sixy, seveny, eighty, pos, clickd, clickSq, flags, jim);
                checkBR(x, y, mines, col, row, numMines, mpt, one, two, three, four, five, six, seven, eight, oney, twoy,
                        threey, foury, fivey, sixy, seveny, eighty, pos, clickd, clickSq, flags, jim);
            } else if (sum == 1) {
                bool alreadyIn = false;
                int spclkd = changexy(x, y, row, col);
                for (int ac = 0; ac < pos.size(); ac++) {
                    if (pos[ac] == spclkd) {
                        alreadyIn = true;
                    }
                }
                if (!alreadyIn && x >= 0 && y >= 0 && x <= col - 1 && y <= row - 1) {
                    sf::Sprite spritey;
                    sf::Sprite spritey2;
                    spritey2.setTexture(clickd);
                    spritey2.setPosition(x * 32, y * 32);
                    clickSq.push_back(spritey2);
                    spritey.setTexture(oney);
                    spritey.setPosition(x * 32, y * 32);
                    one.push_back(spritey);
                    pos.push_back(spclkd);
                    jim.push_back(spritey2);
                }
            } else if (sum == 2) {
                bool alreadyIn = false;
                int spclkd = changexy(x, y, row, col);
                for (int ac = 0; ac < pos.size(); ac++) {
                    if (pos[ac] == spclkd) {
                        alreadyIn = true;
                    }
                }
                if (!alreadyIn && x >= 0 && y >= 0 && x <= col - 1 && y <= row - 1) {
                    sf::Sprite spritey;
                    sf::Sprite spritey2;
                    spritey2.setTexture(clickd);
                    spritey2.setPosition(x * 32, y * 32);
                    clickSq.push_back(spritey2);
                    spritey.setTexture(twoy);
                    spritey.setPosition(x * 32, y * 32);
                    two.push_back(spritey);
                    pos.push_back(spclkd);
                    jim.push_back(spritey2);
                }
            } else if (sum == 3) {
                bool alreadyIn = false;
                int spclkd = changexy(x, y, row, col);
                for (int ac = 0; ac < pos.size(); ac++) {
                    if (pos[ac] == spclkd) {
                        alreadyIn = true;
                    }
                }
                if (!alreadyIn && x >= 0 && y >= 0 && x <= col - 1 && y <= row - 1) {
                    sf::Sprite spritey;
                    sf::Sprite spritey2;
                    spritey2.setTexture(clickd);
                    spritey2.setPosition(x * 32, y * 32);
                    clickSq.push_back(spritey2);
                    spritey.setTexture(threey);
                    spritey.setPosition(x * 32, y * 32);
                    three.push_back(spritey);
                    jim.push_back(spritey2);
                    pos.push_back(spclkd);
                }
            } else if (sum == 4) {
                bool alreadyIn = false;
                int spclkd = changexy(x, y, row, col);
                for (int ac = 0; ac < pos.size(); ac++) {
                    if (pos[ac] == spclkd) {
                        alreadyIn = true;
                    }
                }
                if (!alreadyIn && x >= 0 && y >= 0 && x <= col - 1 && y <= row - 1) {
                    sf::Sprite spritey;
                    sf::Sprite spritey2;
                    spritey2.setTexture(clickd);
                    spritey2.setPosition(x * 32, y * 32);
                    clickSq.push_back(spritey2);
                    spritey.setTexture(foury);
                    spritey.setPosition(x * 32, y * 32);
                    four.push_back(spritey);
                    pos.push_back(spclkd);
                    jim.push_back(spritey2);
                }
            } else if (sum == 5) {
                bool alreadyIn = false;
                int spclkd = changexy(x, y, row, col);
                for (int ac = 0; ac < pos.size(); ac++) {
                    if (pos[ac] == spclkd) {
                        alreadyIn = true;
                    }
                }
                if (!alreadyIn && x >= 0 && y >= 0 && x <= col - 1 && y <= row - 1) {
                    sf::Sprite spritey;
                    sf::Sprite spritey2;
                    spritey2.setTexture(clickd);
                    spritey2.setPosition(x * 32, y * 32);
                    clickSq.push_back(spritey2);
                    spritey.setTexture(fivey);
                    spritey.setPosition(x * 32, y * 32);
                    five.push_back(spritey);
                    pos.push_back(spclkd);
                    jim.push_back(spritey2);
                }
            } else if (sum == 6) {
                bool alreadyIn = false;
                int spclkd = changexy(x, y, row, col);
                for (int ac = 0; ac < pos.size(); ac++) {
                    if (pos[ac] == spclkd) {
                        alreadyIn = true;
                    }
                }
                if (!alreadyIn && x >= 0 && y >= 0 && x <= col - 1 && y <= row - 1) {
                    sf::Sprite spritey;
                    sf::Sprite spritey2;
                    spritey2.setTexture(clickd);
                    spritey2.setPosition(x * 32, y * 32);
                    clickSq.push_back(spritey2);
                    spritey.setTexture(sixy);
                    spritey.setPosition(x * 32, y * 32);
                    six.push_back(spritey);
                    jim.push_back(spritey2);
                    pos.push_back(spclkd);
                }
            } else if (sum == 7) {
                bool alreadyIn = false;
                int spclkd = changexy(x, y, row, col);
                for (int ac = 0; ac < pos.size(); ac++) {
                    if (pos[ac] == spclkd) {
                        alreadyIn = true;
                    }
                }
                if (!alreadyIn && x >= 0 && y >= 0 && x <= col - 1 && y <= row - 1) {
                    sf::Sprite spritey;
                    sf::Sprite spritey2;
                    spritey2.setTexture(clickd);
                    spritey2.setPosition(x * 32, y * 32);
                    clickSq.push_back(spritey2);
                    spritey.setTexture(seveny);
                    spritey.setPosition(x * 32, y * 32);
                    seven.push_back(spritey);
                    pos.push_back(spclkd);
                    jim.push_back(spritey2);
                }
            } else if (sum == 8) {
                bool alreadyIn = false;
                int spclkd = changexy(x, y, row, col);
                for (int ac = 0; ac < pos.size(); ac++) {
                    if (pos[ac] == spclkd) {
                        alreadyIn = true;
                    }
                }
                if (!alreadyIn && x >= 0 && y >= 0 && x <= col - 1 && y <= row - 1) {
                    sf::Sprite spritey;
                    sf::Sprite spritey2;
                    spritey2.setTexture(clickd);
                    spritey2.setPosition(x * 32, y * 32);
                    clickSq.push_back(spritey2);
                    spritey.setTexture(eighty);
                    spritey.setPosition(x * 32, y * 32);
                    eight.push_back(spritey);
                    jim.push_back(spritey2);
                    pos.push_back(spclkd);
                }
            }
        }
    }
}

void checkRight(int x, int y, int *mines, int col, int row, int numMines, vector<int>& mpt, vector<sf::Sprite>& one, vector<sf::Sprite>& two, vector<sf::Sprite>& three, vector<sf::Sprite>& four, vector<sf::Sprite>& five, vector<sf::Sprite>& six, vector<sf::Sprite>& seven, vector<sf::Sprite>& eight, sf::Texture& oney, sf::Texture& twoy, sf::Texture& threey, sf::Texture& foury, sf::Texture& fivey, sf::Texture& sixy, sf::Texture& seveny, sf::Texture& eighty, vector<int>& pos, sf::Texture& clickd, vector<sf::Sprite>& clickSq, vector<sf::Sprite>& flags, vector<sf::Sprite>& jim)
{
    bool flagged = false;
    for (int i = 0; i < flags.size(); i++)
    {
        if ((flags[i].getPosition().x) / 32 == x + 1 && (flags[i].getPosition().y) / 32 == y)
        {
            flagged = true;
        }
    }
    if (flagged)
    {
        int x;
    }
    else {
        int sum = 0;
        bool cont = true;
        for (int k = 0; k < mpt.size(); k++) {
            if (mpt[k] == changexy(x + 1, y, row, col)) {
                cont = false;
            }
        }
        if (x == col - 1 || !cont) {
            int x;
        } else {
            x++;
            if (y == 0) //top side
            {
                for (int i = 0; i < numMines; i++) {
                    if (changexy(x + 1, y, row, col) == mines[i]) {
                        sum++;
                    }
                    if (changexy(x + 1, y + 1, row, col) == mines[i]) {
                        sum++;
                    }
                }
            } else if (y == row - 1) //bottom side
            {
                for (int i = 0; i < numMines; i++) {
                    if (changexy(x + 1, y, row, col) == mines[i]) {
                        sum++;
                    }
                    if (changexy(x + 1, y - 1, row, col) == mines[i]) {
                        sum++;
                    }
                }
            } else {
                for (int i = 0; i < numMines; i++) {
                    if (changexy(x + 1, y, row, col) == mines[i]) {
                        sum++;
                    }
                    if (changexy(x + 1, y - 1, row, col) == mines[i]) {
                        sum++;
                    }
                    if (changexy(x + 1, y + 1, row, col) == mines[i]) {
                        sum++;
                    }
                }
            }
            if (sum == 0) {
                bool add2 = true;
                for (int j = 0; j < mpt.size(); j++) {
                    if (mpt[j] == changexy(x, y, row, col)) {
                        add2 = false;
                    }
                }
                if (add2) {
                    mpt.push_back(changexy(x, y, row, col));

                    checkBelow(x, y, mines, col, row, numMines, mpt, one, two, three, four, five, six, seven, eight,
                               oney,
                               twoy, threey, foury, fivey, sixy, seveny, eighty, pos, clickd, clickSq, flags, jim);
                    checkAbove(x, y, mines, col, row, numMines, mpt, one, two, three, four, five, six, seven, eight,
                               oney,
                               twoy, threey, foury, fivey, sixy, seveny, eighty, pos, clickd, clickSq, flags, jim);
                    checkRight(x, y, mines, col, row, numMines, mpt, one, two, three, four, five, six, seven, eight,
                               oney,
                               twoy, threey, foury, fivey, sixy, seveny, eighty, pos, clickd, clickSq, flags, jim);
                    checkTL(x, y, mines, col, row, numMines, mpt, one, two, three, four, five, six, seven, eight, oney, twoy,
                            threey, foury, fivey, sixy, seveny, eighty, pos, clickd, clickSq, flags, jim);
                    checkTR(x, y, mines, col, row, numMines, mpt, one, two, three, four, five, six, seven, eight, oney, twoy,
                            threey, foury, fivey, sixy, seveny, eighty, pos, clickd, clickSq, flags, jim);
                    checkBL(x, y, mines, col, row, numMines, mpt, one, two, three, four, five, six, seven, eight, oney, twoy,
                            threey, foury, fivey, sixy, seveny, eighty, pos, clickd, clickSq, flags, jim);
                    checkBR(x, y, mines, col, row, numMines, mpt, one, two, three, four, five, six, seven, eight, oney, twoy,
                            threey, foury, fivey, sixy, seveny, eighty, pos, clickd, clickSq, flags, jim);
                }
            } else if (sum == 1) {
                bool alreadyIn = false;
                int spclkd = changexy(x, y, row, col);
                for (int ac = 0; ac < pos.size(); ac++) {
                    if (pos[ac] == spclkd) {
                        alreadyIn = true;
                    }
                }
                if (!alreadyIn && x >= 0 && y >= 0 && x <= col - 1 && y <= row - 1) {
                    sf::Sprite spritey;
                    sf::Sprite spritey2;
                    spritey2.setTexture(clickd);
                    spritey2.setPosition(x * 32, y * 32);
                    clickSq.push_back(spritey2);
                    spritey.setTexture(oney);
                    spritey.setPosition(x * 32, y * 32);
                    one.push_back(spritey);
                    pos.push_back(spclkd);
                    jim.push_back(spritey2);
                }
            } else if (sum == 2) {
                bool alreadyIn = false;
                int spclkd = changexy(x, y, row, col);
                for (int ac = 0; ac < pos.size(); ac++) {
                    if (pos[ac] == spclkd) {
                        alreadyIn = true;
                    }
                }
                if (!alreadyIn && x >= 0 && y >= 0 && x <= col - 1 && y <= row - 1) {
                    sf::Sprite spritey;
                    sf::Sprite spritey2;
                    spritey2.setTexture(clickd);
                    spritey2.setPosition(x * 32, y * 32);
                    clickSq.push_back(spritey2);
                    spritey.setTexture(twoy);
                    spritey.setPosition(x * 32, y * 32);
                    two.push_back(spritey);
                    pos.push_back(spclkd);
                    jim.push_back(spritey2);
                }
            } else if (sum == 3) {
                bool alreadyIn = false;
                int spclkd = changexy(x, y, row, col);
                for (int ac = 0; ac < pos.size(); ac++) {
                    if (pos[ac] == spclkd) {
                        alreadyIn = true;
                    }
                }
                if (!alreadyIn && x >= 0 && y >= 0 && x <= col - 1 && y <= row - 1) {
                    sf::Sprite spritey;
                    sf::Sprite spritey2;
                    spritey2.setTexture(clickd);
                    spritey2.setPosition(x * 32, y * 32);
                    clickSq.push_back(spritey2);
                    spritey.setTexture(threey);
                    spritey.setPosition(x * 32, y * 32);
                    three.push_back(spritey);
                    jim.push_back(spritey2);
                    pos.push_back(spclkd);
                }
            } else if (sum == 4) {
                bool alreadyIn = false;
                int spclkd = changexy(x, y, row, col);
                for (int ac = 0; ac < pos.size(); ac++) {
                    if (pos[ac] == spclkd) {
                        alreadyIn = true;
                    }
                }
                if (!alreadyIn && x >= 0 && y >= 0 && x <= col - 1 && y <= row - 1) {
                    sf::Sprite spritey;
                    sf::Sprite spritey2;
                    spritey2.setTexture(clickd);
                    spritey2.setPosition(x * 32, y * 32);
                    clickSq.push_back(spritey2);
                    spritey.setTexture(foury);
                    spritey.setPosition(x * 32, y * 32);
                    four.push_back(spritey);
                    pos.push_back(spclkd);
                    jim.push_back(spritey2);
                }
            } else if (sum == 5) {
                bool alreadyIn = false;
                int spclkd = changexy(x, y, row, col);
                for (int ac = 0; ac < pos.size(); ac++) {
                    if (pos[ac] == spclkd) {
                        alreadyIn = true;
                    }
                }
                if (!alreadyIn && x >= 0 && y >= 0 && x <= col - 1 && y <= row - 1) {
                    sf::Sprite spritey;
                    sf::Sprite spritey2;
                    spritey2.setTexture(clickd);
                    spritey2.setPosition(x * 32, y * 32);
                    clickSq.push_back(spritey2);
                    spritey.setTexture(fivey);
                    spritey.setPosition(x * 32, y * 32);
                    five.push_back(spritey);
                    pos.push_back(spclkd);
                    jim.push_back(spritey2);
                }
            } else if (sum == 6) {
                bool alreadyIn = false;
                int spclkd = changexy(x, y, row, col);
                for (int ac = 0; ac < pos.size(); ac++) {
                    if (pos[ac] == spclkd) {
                        alreadyIn = true;
                    }
                }
                if (!alreadyIn && x >= 0 && y >= 0 && x <= col - 1 && y <= row - 1) {
                    sf::Sprite spritey;
                    sf::Sprite spritey2;
                    spritey2.setTexture(clickd);
                    spritey2.setPosition(x * 32, y * 32);
                    clickSq.push_back(spritey2);
                    spritey.setTexture(sixy);
                    spritey.setPosition(x * 32, y * 32);
                    six.push_back(spritey);
                    pos.push_back(spclkd);
                    jim.push_back(spritey2);
                }
            } else if (sum == 7) {
                bool alreadyIn = false;
                int spclkd = changexy(x, y, row, col);
                for (int ac = 0; ac < pos.size(); ac++) {
                    if (pos[ac] == spclkd) {
                        alreadyIn = true;
                    }
                }
                if (!alreadyIn && x >= 0 && y >= 0 && x <= col - 1 && y <= row - 1) {
                    sf::Sprite spritey;
                    sf::Sprite spritey2;
                    spritey2.setTexture(clickd);
                    spritey2.setPosition(x * 32, y * 32);
                    clickSq.push_back(spritey2);
                    spritey.setTexture(seveny);
                    spritey.setPosition(x * 32, y * 32);
                    seven.push_back(spritey);
                    pos.push_back(spclkd);
                    jim.push_back(spritey2);
                }
            } else if (sum == 8) {
                bool alreadyIn = false;
                int spclkd = changexy(x, y, row, col);
                for (int ac = 0; ac < pos.size(); ac++) {
                    if (pos[ac] == spclkd) {
                        alreadyIn = true;
                    }
                }
                if (!alreadyIn && x >= 0 && y >= 0 && x <= col - 1 && y <= row - 1) {
                    sf::Sprite spritey;
                    sf::Sprite spritey2;
                    spritey2.setTexture(clickd);
                    spritey2.setPosition(x * 32, y * 32);
                    clickSq.push_back(spritey2);
                    spritey.setTexture(eighty);
                    spritey.setPosition(x * 32, y * 32);
                    eight.push_back(spritey);
                    pos.push_back(spclkd);
                    jim.push_back(spritey2);
                }
            }

        }
    }
}

int changexy(int x, int y, int row, int col)
{
    if (x < 0 || y < 0 || x > col - 1 || y > row - 1)
    {
        return -1;
    }
    return (x * row) + y;
}

void checkTR(int x, int y, int *mines, int col, int row, int numMines, vector<int>&mpt, vector<sf::Sprite>& one, vector<sf::Sprite>& two, vector<sf::Sprite>& three, vector<sf::Sprite>& four, vector<sf::Sprite>& five, vector<sf::Sprite>& six, vector<sf::Sprite>& seven, vector<sf::Sprite>& eight, sf::Texture& oney, sf::Texture& twoy, sf::Texture& threey, sf::Texture& foury, sf::Texture& fivey, sf::Texture& sixy, sf::Texture& seveny, sf::Texture& eighty, vector<int>& pos, sf::Texture& clickd, vector<sf::Sprite>& clickSq, vector<sf::Sprite>& flags, vector<sf::Sprite>& jim)
{

    y--;
    x++;
    bool flagged = false;
    for (int i = 0; i < flags.size(); i++)
    {
        if (((flags[i].getPosition().x) / 32 == x) && ((flags[i].getPosition().y) / 32 == y))
        {
            flagged = true;
        }
    }
    if (flagged)
    {
        int x;
    }
    else {
        int sum = 0;
        if (y < 0 || x < 0 || y > row - 1 || x > col - 1) // off board
        {
            int x;
        } else if (y == 0 && x == col - 1) //top right position
        {
            int x;
        } else if (y == 0) //top position
        {
            for (int i = 0; i < numMines; i++) {
                if (changexy(x + 1, y, row, col) == mines[i]) {
                    sum++;
                }
                if (changexy(x + 1, y + 1, row, col) == mines[i]) {
                    sum++;
                }
            }
        } else if (x == col - 1) //right position
        {
            for (int i = 0; i < numMines; i++) {
                if (changexy(x, y - 1, row, col) == mines[i]) {
                    sum++;
                }
                if (changexy(x - 1, y - 1, row, col) == mines[i]) {
                    sum++;
                }
            }
        } else {
            for (int i = 0; i < numMines; i++) {
                if (changexy(x, y - 1, row, col) == mines[i]) {
                    sum++;
                }
                if (changexy(x - 1, y - 1, row, col) == mines[i]) {
                    sum++;
                }
                if (changexy(x + 1, y, row, col) == mines[i]) {
                    sum++;
                }
                if (changexy(x + 1, y + 1, row, col) == mines[i]) {
                    sum++;
                }
                if (changexy(x + 1, y - 1, row, col) == mines[i]) {
                    sum++;
                }
            }
        }
        if (sum == 0) {
            bool add2 = true;
            for (int j = 0; j < mpt.size(); j++) {
                if (mpt[j] == changexy(x, y, row, col)) {
                    add2 = false;
                }
            }
            if (add2) {
                mpt.push_back(changexy(x, y, row, col));
                checkAbove(x, y, mines, col, row, numMines, mpt, one, two, three, four, five, six, seven, eight, oney,
                           twoy, threey, foury, fivey, sixy, seveny, eighty, pos, clickd, clickSq, flags, jim);
                checkRight(x, y, mines, col, row, numMines, mpt, one, two, three, four, five, six, seven, eight, oney,
                           twoy, threey, foury, fivey, sixy, seveny, eighty, pos, clickd, clickSq, flags, jim);
                checkBR(x, y, mines, col, row, numMines, mpt, one, two, three, four, five, six, seven, eight, oney,
                        twoy, threey, foury, fivey, sixy, seveny, eighty, pos, clickd, clickSq, flags, jim);
                checkTL(x, y, mines, col, row, numMines, mpt, one, two, three, four, five, six, seven, eight, oney,
                        twoy, threey, foury, fivey, sixy, seveny, eighty, pos, clickd, clickSq, flags, jim);
                checkTR(x, y, mines, col, row, numMines, mpt, one, two, three, four, five, six, seven, eight, oney,
                        twoy, threey, foury, fivey, sixy, seveny, eighty, pos, clickd, clickSq, flags, jim);
            }
        } else if (sum == 1) {
            bool alreadyIn = false;
            int spclkd = changexy(x, y, row, col);
            for (int ac = 0; ac < pos.size(); ac++) {
                if (pos[ac] == spclkd) {
                    alreadyIn = true;
                }
            }
            if (!alreadyIn && x >= 0 && y >= 0 && x <= col - 1 && y <= row - 1) {
                sf::Sprite spritey;
                sf::Sprite spritey2;
                spritey2.setTexture(clickd);
                spritey2.setPosition(x * 32, y * 32);
                clickSq.push_back(spritey2);
                spritey.setTexture(oney);
                spritey.setPosition(x * 32, y * 32);
                one.push_back(spritey);
                pos.push_back(spclkd);
                jim.push_back(spritey2);
            }
        } else if (sum == 2) {
            bool alreadyIn = false;
            int spclkd = changexy(x, y, row, col);
            for (int ac = 0; ac < pos.size(); ac++) {
                if (pos[ac] == spclkd) {
                    alreadyIn = true;
                }
            }
            if (!alreadyIn && x >= 0 && y >= 0 && x <= col - 1 && y <= row - 1) {
                sf::Sprite spritey;
                sf::Sprite spritey2;
                spritey2.setTexture(clickd);
                spritey2.setPosition(x * 32, y * 32);
                clickSq.push_back(spritey2);
                spritey.setTexture(twoy);
                spritey.setPosition(x * 32, y * 32);
                two.push_back(spritey);
                pos.push_back(spclkd);
                jim.push_back(spritey2);
            }
        } else if (sum == 3) {
            bool alreadyIn = false;
            int spclkd = changexy(x, y, row, col);
            for (int ac = 0; ac < pos.size(); ac++) {
                if (pos[ac] == spclkd) {
                    alreadyIn = true;
                }
            }
            if (!alreadyIn && x >= 0 && y >= 0 && x <= col - 1 && y <= row - 1) {
                sf::Sprite spritey;
                sf::Sprite spritey2;
                spritey2.setTexture(clickd);
                spritey2.setPosition(x * 32, y * 32);
                clickSq.push_back(spritey2);
                spritey.setTexture(threey);
                spritey.setPosition(x * 32, y * 32);
                three.push_back(spritey);
                pos.push_back(spclkd);
                jim.push_back(spritey2);
            }
        } else if (sum == 4) {
            bool alreadyIn = false;
            int spclkd = changexy(x, y, row, col);
            for (int ac = 0; ac < pos.size(); ac++) {
                if (pos[ac] == spclkd) {
                    alreadyIn = true;
                }
            }
            if (!alreadyIn && x >= 0 && y >= 0 && x <= col - 1 && y <= row - 1) {
                sf::Sprite spritey;
                sf::Sprite spritey2;
                spritey2.setTexture(clickd);
                spritey2.setPosition(x * 32, y * 32);
                clickSq.push_back(spritey2);
                spritey.setTexture(foury);
                spritey.setPosition(x * 32, y * 32);
                four.push_back(spritey);
                pos.push_back(spclkd);
                jim.push_back(spritey2);
            }
        } else if (sum == 5) {
            bool alreadyIn = false;
            int spclkd = changexy(x, y, row, col);
            for (int ac = 0; ac < pos.size(); ac++) {
                if (pos[ac] == spclkd) {
                    alreadyIn = true;
                }
            }
            if (!alreadyIn && x >= 0 && y >= 0 && x <= col - 1 && y <= row - 1) {
                sf::Sprite spritey;
                sf::Sprite spritey2;
                spritey2.setTexture(clickd);
                spritey2.setPosition(x * 32, y * 32);
                clickSq.push_back(spritey2);
                spritey.setTexture(fivey);
                spritey.setPosition(x * 32, y * 32);
                five.push_back(spritey);
                pos.push_back(spclkd);
                jim.push_back(spritey2);
            }
        }
    }
}

void checkTL(int x, int y, int *mines, int col, int row, int numMines, vector<int>&mpt, vector<sf::Sprite>& one, vector<sf::Sprite>& two, vector<sf::Sprite>& three, vector<sf::Sprite>& four, vector<sf::Sprite>& five, vector<sf::Sprite>& six, vector<sf::Sprite>& seven, vector<sf::Sprite>& eight, sf::Texture& oney, sf::Texture& twoy, sf::Texture& threey, sf::Texture& foury, sf::Texture& fivey, sf::Texture& sixy, sf::Texture& seveny, sf::Texture& eighty, vector<int>& pos, sf::Texture& clickd, vector<sf::Sprite>& clickSq, vector<sf::Sprite>& flags, vector<sf::Sprite>& jim)
{
    y--;
    x--;
    bool flagged = false;
    for (int i = 0; i < flags.size(); i++)
    {
        if (((flags[i].getPosition().x) / 32 == x) && ((flags[i].getPosition().y) / 32 == y))
        {
            flagged = true;
        }
    }
    if (flagged)
    {
        int x;
    }
    else {
        int sum = 0;
        if (y < 0 || x < 0 || y > row - 1 || x > col - 1) // off board
        {
            int x;
        } else if (y == 0 && x == 0) //top left position
        {
            int x;
        } else if (y == 0) //top position
        {
            for (int i = 0; i < numMines; i++) {
                if (changexy(x - 1, y, row, col) == mines[i]) {
                    sum++;
                }
                if (changexy(x - 1, y + 1, row, col) == mines[i]) {
                    sum++;
                }
            }
        } else if (x == 0) //left position
        {
            for (int i = 0; i < numMines; i++) {
                if (changexy(x, y - 1, row, col) == mines[i]) {
                    sum++;
                }
                if (changexy(x + 1, y - 1, row, col) == mines[i]) {
                    sum++;
                }
            }
        } else {
            for (int i = 0; i < numMines; i++) {
                if (changexy(x, y - 1, row, col) == mines[i]) {
                    sum++;
                }
                if (changexy(x + 1, y - 1, row, col) == mines[i]) {
                    sum++;
                }
                if (changexy(x - 1, y, row, col) == mines[i]) {
                    sum++;
                }
                if (changexy(x - 1, y + 1, row, col) == mines[i]) {
                    sum++;
                }
                if (changexy(x - 1, y - 1, row, col) == mines[i]) {
                    sum++;
                }
            }
        }
        if (sum == 0) {
            bool add2 = true;
            for (int j = 0; j < mpt.size(); j++) {
                if (mpt[j] == changexy(x, y, row, col)) {
                    add2 = false;
                }
            }
            if (add2) {
                mpt.push_back(changexy(x, y, row, col));
                checkAbove(x, y, mines, col, row, numMines, mpt, one, two, three, four, five, six, seven, eight, oney,
                           twoy, threey, foury, fivey, sixy, seveny, eighty, pos, clickd, clickSq, flags, jim);
                checkLeft(x, y, mines, col, row, numMines, mpt, one, two, three, four, five, six, seven, eight, oney,
                          twoy, threey, foury, fivey, sixy, seveny, eighty, pos, clickd, clickSq, flags, jim);
                checkTR(x, y, mines, col, row, numMines, mpt, one, two, three, four, five, six, seven, eight, oney,
                        twoy, threey, foury, fivey, sixy, seveny, eighty, pos, clickd, clickSq, flags, jim);
                checkTL(x, y, mines, col, row, numMines, mpt, one, two, three, four, five, six, seven, eight, oney,
                        twoy, threey, foury, fivey, sixy, seveny, eighty, pos, clickd, clickSq, flags, jim);
                checkBL(x, y, mines, col, row, numMines, mpt, one, two, three, four, five, six, seven, eight, oney,
                        twoy, threey, foury, fivey, sixy, seveny, eighty, pos, clickd, clickSq, flags, jim);
            }
        } else if (sum == 1) {
            bool alreadyIn = false;
            int spclkd = changexy(x, y, row, col);
            for (int ac = 0; ac < pos.size(); ac++) {
                if (pos[ac] == spclkd) {
                    alreadyIn = true;
                }
            }
            if (!alreadyIn && x >= 0 && y >= 0 && x <= col - 1 && y <= row - 1) {
                sf::Sprite spritey;
                sf::Sprite spritey2;
                spritey2.setTexture(clickd);
                spritey2.setPosition(x * 32, y * 32);
                clickSq.push_back(spritey2);
                spritey.setTexture(oney);
                spritey.setPosition(x * 32, y * 32);
                one.push_back(spritey);
                pos.push_back(spclkd);
                jim.push_back(spritey2);
            }
        } else if (sum == 2) {
            bool alreadyIn = false;
            int spclkd = changexy(x, y, row, col);
            for (int ac = 0; ac < pos.size(); ac++) {
                if (pos[ac] == spclkd) {
                    alreadyIn = true;
                }
            }
            if (!alreadyIn && x >= 0 && y >= 0 && x <= col - 1 && y <= row - 1) {
                sf::Sprite spritey;
                sf::Sprite spritey2;
                spritey2.setTexture(clickd);
                spritey2.setPosition(x * 32, y * 32);
                clickSq.push_back(spritey2);
                spritey.setTexture(twoy);
                spritey.setPosition(x * 32, y * 32);
                two.push_back(spritey);
                pos.push_back(spclkd);
                jim.push_back(spritey2);
            }
        } else if (sum == 3) {
            bool alreadyIn = false;
            int spclkd = changexy(x, y, row, col);
            for (int ac = 0; ac < pos.size(); ac++) {
                if (pos[ac] == spclkd) {
                    alreadyIn = true;
                }
            }
            if (!alreadyIn && x >= 0 && y >= 0 && x <= col - 1 && y <= row - 1) {
                sf::Sprite spritey;
                sf::Sprite spritey2;
                spritey2.setTexture(clickd);
                spritey2.setPosition(x * 32, y * 32);
                clickSq.push_back(spritey2);
                spritey.setTexture(threey);
                spritey.setPosition(x * 32, y * 32);
                three.push_back(spritey);
                pos.push_back(spclkd);
                jim.push_back(spritey2);
            }
        } else if (sum == 4) {
            bool alreadyIn = false;
            int spclkd = changexy(x, y, row, col);
            for (int ac = 0; ac < pos.size(); ac++) {
                if (pos[ac] == spclkd) {
                    alreadyIn = true;
                }
            }
            if (!alreadyIn && x >= 0 && y >= 0 && x <= col - 1 && y <= row - 1) {
                sf::Sprite spritey;
                sf::Sprite spritey2;
                spritey2.setTexture(clickd);
                spritey2.setPosition(x * 32, y * 32);
                clickSq.push_back(spritey2);
                spritey.setTexture(foury);
                spritey.setPosition(x * 32, y * 32);
                four.push_back(spritey);
                pos.push_back(spclkd);
                jim.push_back(spritey2);
            }
        } else if (sum == 5) {
            bool alreadyIn = false;
            int spclkd = changexy(x, y, row, col);
            for (int ac = 0; ac < pos.size(); ac++) {
                if (pos[ac] == spclkd) {
                    alreadyIn = true;
                }
            }
            if (!alreadyIn && x >= 0 && y >= 0 && x <= col - 1 && y <= row - 1) {
                sf::Sprite spritey;
                sf::Sprite spritey2;
                spritey2.setTexture(clickd);
                spritey2.setPosition(x * 32, y * 32);
                clickSq.push_back(spritey2);
                spritey.setTexture(fivey);
                spritey.setPosition(x * 32, y * 32);
                five.push_back(spritey);
                pos.push_back(spclkd);
                jim.push_back(spritey2);
            }
        }
    }
}

void checkBL(int x, int y, int *mines, int col, int row, int numMines, vector<int>&mpt, vector<sf::Sprite>& one, vector<sf::Sprite>& two, vector<sf::Sprite>& three, vector<sf::Sprite>& four, vector<sf::Sprite>& five, vector<sf::Sprite>& six, vector<sf::Sprite>& seven, vector<sf::Sprite>& eight, sf::Texture& oney, sf::Texture& twoy, sf::Texture& threey, sf::Texture& foury, sf::Texture& fivey, sf::Texture& sixy, sf::Texture& seveny, sf::Texture& eighty, vector<int>& pos, sf::Texture& clickd, vector<sf::Sprite>& clickSq, vector<sf::Sprite>& flags, vector<sf::Sprite>& jim)
{
    y++;
    x--;
    bool flagged = false;
    for (int i = 0; i < flags.size(); i++)
    {
        if (((flags[i].getPosition().x) / 32 == x) && ((flags[i].getPosition().y) / 32 == y))
        {
            flagged = true;
        }
    }
    if (flagged)
    {
        int x;
    }
    else {
        int sum = 0;
        if (y < 0 || x < 0 || y > row - 1 || x > col - 1) // off board
        {
            int x;
        } else if (y == row - 1 && x == 0) //bottom left position
        {
            int x;
        } else if (y == row - 1) //bottom position
        {
            for (int i = 0; i < numMines; i++) {
                if (changexy(x - 1, y, row, col) == mines[i]) {
                    sum++;
                }
                if (changexy(x - 1, y - 1, row, col) == mines[i]) {
                    sum++;
                }
            }
        } else if (x == 0) //left position
        {
            for (int i = 0; i < numMines; i++) {
                if (changexy(x, y + 1, row, col) == mines[i]) {
                    sum++;
                }
                if (changexy(x + 1, y + 1, row, col) == mines[i]) {
                    sum++;
                }
            }
        } else {
            for (int i = 0; i < numMines; i++) {
                if (changexy(x, y + 1, row, col) == mines[i]) {
                    sum++;
                }
                if (changexy(x + 1, y + 1, row, col) == mines[i]) {
                    sum++;
                }
                if (changexy(x - 1, y, row, col) == mines[i]) {
                    sum++;
                }
                if (changexy(x - 1, y - 1, row, col) == mines[i]) {
                    sum++;
                }
                if (changexy(x - 1, y + 1, row, col) == mines[i]) {
                    sum++;
                }
            }
        }
        if (sum == 0) {
            bool add2 = true;
            for (int j = 0; j < mpt.size(); j++) {
                if (mpt[j] == changexy(x, y, row, col)) {
                    add2 = false;
                }
            }
            if (add2) {
                mpt.push_back(changexy(x, y, row, col));
                checkBelow(x, y, mines, col, row, numMines, mpt, one, two, three, four, five, six, seven, eight, oney,
                           twoy, threey, foury, fivey, sixy, seveny, eighty, pos, clickd, clickSq, flags, jim);
                checkLeft(x, y, mines, col, row, numMines, mpt, one, two, three, four, five, six, seven, eight, oney,
                          twoy, threey, foury, fivey, sixy, seveny, eighty, pos, clickd, clickSq, flags, jim);
                checkBL(x, y, mines, col, row, numMines, mpt, one, two, three, four, five, six, seven, eight, oney,
                        twoy, threey, foury, fivey, sixy, seveny, eighty, pos, clickd, clickSq, flags, jim);
                checkTL(x, y, mines, col, row, numMines, mpt, one, two, three, four, five, six, seven, eight, oney,
                        twoy, threey, foury, fivey, sixy, seveny, eighty, pos, clickd, clickSq, flags, jim);
                checkBR(x, y, mines, col, row, numMines, mpt, one, two, three, four, five, six, seven, eight, oney,
                        twoy, threey, foury, fivey, sixy, seveny, eighty, pos, clickd, clickSq, flags, jim);
            }
        } else if (sum == 1) {
            bool alreadyIn = false;
            int spclkd = changexy(x, y, row, col);
            for (int ac = 0; ac < pos.size(); ac++) {
                if (pos[ac] == spclkd) {
                    alreadyIn = true;
                }
            }
            if (!alreadyIn && x >= 0 && y >= 0 && x <= col - 1 && y <= row - 1) {
                sf::Sprite spritey;
                sf::Sprite spritey2;
                spritey2.setTexture(clickd);
                spritey2.setPosition(x * 32, y * 32);
                clickSq.push_back(spritey2);
                spritey.setTexture(oney);
                spritey.setPosition(x * 32, y * 32);
                one.push_back(spritey);
                pos.push_back(spclkd);
                jim.push_back(spritey2);
            }
        } else if (sum == 2) {
            bool alreadyIn = false;
            int spclkd = changexy(x, y, row, col);
            for (int ac = 0; ac < pos.size(); ac++) {
                if (pos[ac] == spclkd) {
                    alreadyIn = true;
                }
            }
            if (!alreadyIn && x >= 0 && y >= 0 && x <= col - 1 && y <= row - 1) {
                sf::Sprite spritey;
                sf::Sprite spritey2;
                spritey2.setTexture(clickd);
                spritey2.setPosition(x * 32, y * 32);
                clickSq.push_back(spritey2);
                spritey.setTexture(twoy);
                spritey.setPosition(x * 32, y * 32);
                two.push_back(spritey);
                pos.push_back(spclkd);
                jim.push_back(spritey2);
            }
        } else if (sum == 3) {
            bool alreadyIn = false;
            int spclkd = changexy(x, y, row, col);
            for (int ac = 0; ac < pos.size(); ac++) {
                if (pos[ac] == spclkd) {
                    alreadyIn = true;
                }
            }
            if (!alreadyIn && x >= 0 && y >= 0 && x <= col - 1 && y <= row - 1) {
                sf::Sprite spritey;
                sf::Sprite spritey2;
                spritey2.setTexture(clickd);
                spritey2.setPosition(x * 32, y * 32);
                clickSq.push_back(spritey2);
                spritey.setTexture(threey);
                spritey.setPosition(x * 32, y * 32);
                three.push_back(spritey);
                pos.push_back(spclkd);
                jim.push_back(spritey2);
            }
        } else if (sum == 4) {
            bool alreadyIn = false;
            int spclkd = changexy(x, y, row, col);
            for (int ac = 0; ac < pos.size(); ac++) {
                if (pos[ac] == spclkd) {
                    alreadyIn = true;
                }
            }
            if (!alreadyIn && x >= 0 && y >= 0 && x <= col - 1 && y <= row - 1) {
                sf::Sprite spritey;
                sf::Sprite spritey2;
                spritey2.setTexture(clickd);
                spritey2.setPosition(x * 32, y * 32);
                clickSq.push_back(spritey2);
                spritey.setTexture(foury);
                spritey.setPosition(x * 32, y * 32);
                four.push_back(spritey);
                pos.push_back(spclkd);
                jim.push_back(spritey2);
            }
        } else if (sum == 5) {
            bool alreadyIn = false;
            int spclkd = changexy(x, y, row, col);
            for (int ac = 0; ac < pos.size(); ac++) {
                if (pos[ac] == spclkd) {
                    alreadyIn = true;
                }
            }
            if (!alreadyIn && x >= 0 && y >= 0 && x <= col - 1 && y <= row - 1) {
                sf::Sprite spritey;
                sf::Sprite spritey2;
                spritey2.setTexture(clickd);
                spritey2.setPosition(x * 32, y * 32);
                clickSq.push_back(spritey2);
                spritey.setTexture(fivey);
                spritey.setPosition(x * 32, y * 32);
                five.push_back(spritey);
                pos.push_back(spclkd);
                jim.push_back(spritey2);
            }
        }
    }
}

void checkBR(int x, int y, int *mines, int col, int row, int numMines, vector<int>&mpt, vector<sf::Sprite>& one, vector<sf::Sprite>& two, vector<sf::Sprite>& three, vector<sf::Sprite>& four, vector<sf::Sprite>& five, vector<sf::Sprite>& six, vector<sf::Sprite>& seven, vector<sf::Sprite>& eight, sf::Texture& oney, sf::Texture& twoy, sf::Texture& threey, sf::Texture& foury, sf::Texture& fivey, sf::Texture& sixy, sf::Texture& seveny, sf::Texture& eighty, vector<int>& pos, sf::Texture& clickd, vector<sf::Sprite>& clickSq, vector<sf::Sprite>& flags, vector<sf::Sprite>& jim)
{
    y++;
    x++;
    bool flagged = false;
    for (int i = 0; i < flags.size(); i++)
    {
        if (((flags[i].getPosition().x) / 32 == x) && ((flags[i].getPosition().y) / 32 == y))
        {
            flagged = true;
        }
    }
    if (flagged)
    {
        int x;
    }
    else {
        int sum = 0;
        if (y < 0 || x < 0 || y > row - 1 || x > col - 1) // off board
        {
            int x;
        } else if (y == row - 1 && x == col - 1) //bottom right position
        {
            int x;
        } else if (y == row - 1) //bottom position
        {
            for (int i = 0; i < numMines; i++) {
                if (changexy(x + 1, y, row, col) == mines[i]) {
                    sum++;
                }
                if (changexy(x + 1, y - 1, row, col) == mines[i]) {
                    sum++;
                }
            }
        } else if (x == col - 1) //right position
        {
            for (int i = 0; i < numMines; i++) {
                if (changexy(x, y + 1, row, col) == mines[i]) {
                    sum++;
                }
                if (changexy(x - 1, y + 1, row, col) == mines[i]) {
                    sum++;
                }
            }
        } else {
            for (int i = 0; i < numMines; i++) {
                if (changexy(x, y + 1, row, col) == mines[i]) {
                    sum++;
                }
                if (changexy(x - 1, y + 1, row, col) == mines[i]) {
                    sum++;
                }
                if (changexy(x + 1, y, row, col) == mines[i]) {
                    sum++;
                }
                if (changexy(x + 1, y - 1, row, col) == mines[i]) {
                    sum++;
                }
                if (changexy(x + 1, y + 1, row, col) == mines[i]) {
                    sum++;
                }
            }
        }
        if (sum == 0) {
            bool add2 = true;
            for (int j = 0; j < mpt.size(); j++) {
                if (mpt[j] == changexy(x, y, row, col)) {
                    add2 = false;
                }
            }
            if (add2) {
                mpt.push_back(changexy(x, y, row, col));
                checkBelow(x, y, mines, col, row, numMines, mpt, one, two, three, four, five, six, seven, eight, oney,
                           twoy, threey, foury, fivey, sixy, seveny, eighty, pos, clickd, clickSq, flags, jim);
                checkRight(x, y, mines, col, row, numMines, mpt, one, two, three, four, five, six, seven, eight, oney,
                           twoy, threey, foury, fivey, sixy, seveny, eighty, pos, clickd, clickSq, flags, jim);
                checkTR(x, y, mines, col, row, numMines, mpt, one, two, three, four, five, six, seven, eight, oney,
                        twoy, threey, foury, fivey, sixy, seveny, eighty, pos, clickd, clickSq, flags, jim);
                checkBR(x, y, mines, col, row, numMines, mpt, one, two, three, four, five, six, seven, eight, oney,
                        twoy, threey, foury, fivey, sixy, seveny, eighty, pos, clickd, clickSq, flags, jim);
                checkBL(x, y, mines, col, row, numMines, mpt, one, two, three, four, five, six, seven, eight, oney,
                        twoy, threey, foury, fivey, sixy, seveny, eighty, pos, clickd, clickSq, flags, jim);
            }
        } else if (sum == 1) {
            bool alreadyIn = false;
            int spclkd = changexy(x, y, row, col);
            for (int ac = 0; ac < pos.size(); ac++) {
                if (pos[ac] == spclkd) {
                    alreadyIn = true;
                }
            }
            if (!alreadyIn && x >= 0 && y >= 0 && x <= col - 1 && y <= row - 1) {
                sf::Sprite spritey;
                sf::Sprite spritey2;
                spritey2.setTexture(clickd);
                spritey2.setPosition(x * 32, y * 32);
                clickSq.push_back(spritey2);
                spritey.setTexture(oney);
                spritey.setPosition(x * 32, y * 32);
                one.push_back(spritey);
                pos.push_back(spclkd);
                jim.push_back(spritey2);
            }
        } else if (sum == 2) {
            bool alreadyIn = false;
            int spclkd = changexy(x, y, row, col);
            for (int ac = 0; ac < pos.size(); ac++) {
                if (pos[ac] == spclkd) {
                    alreadyIn = true;
                }
            }
            if (!alreadyIn && x >= 0 && y >= 0 && x <= col - 1 && y <= row - 1) {
                sf::Sprite spritey;
                sf::Sprite spritey2;
                spritey2.setTexture(clickd);
                spritey2.setPosition(x * 32, y * 32);
                clickSq.push_back(spritey2);
                spritey.setTexture(twoy);
                spritey.setPosition(x * 32, y * 32);
                two.push_back(spritey);
                pos.push_back(spclkd);
                jim.push_back(spritey2);
            }
        } else if (sum == 3) {
            bool alreadyIn = false;
            int spclkd = changexy(x, y, row, col);
            for (int ac = 0; ac < pos.size(); ac++) {
                if (pos[ac] == spclkd) {
                    alreadyIn = true;
                }
            }
            if (!alreadyIn && x >= 0 && y >= 0 && x <= col - 1 && y <= row - 1) {
                sf::Sprite spritey;
                sf::Sprite spritey2;
                spritey2.setTexture(clickd);
                spritey2.setPosition(x * 32, y * 32);
                clickSq.push_back(spritey2);
                spritey.setTexture(threey);
                spritey.setPosition(x * 32, y * 32);
                three.push_back(spritey);
                pos.push_back(spclkd);
                jim.push_back(spritey2);
            }
        } else if (sum == 4) {
            bool alreadyIn = false;
            int spclkd = changexy(x, y, row, col);
            for (int ac = 0; ac < pos.size(); ac++) {
                if (pos[ac] == spclkd) {
                    alreadyIn = true;
                }
            }
            if (!alreadyIn && x >= 0 && y >= 0 && x <= col - 1 && y <= row - 1) {
                sf::Sprite spritey;
                sf::Sprite spritey2;
                spritey2.setTexture(clickd);
                spritey2.setPosition(x * 32, y * 32);
                clickSq.push_back(spritey2);
                spritey.setTexture(foury);
                spritey.setPosition(x * 32, y * 32);
                four.push_back(spritey);
                pos.push_back(spclkd);
                jim.push_back(spritey2);
            }
        } else if (sum == 5) {
            bool alreadyIn = false;
            int spclkd = changexy(x, y, row, col);
            for (int ac = 0; ac < pos.size(); ac++) {
                if (pos[ac] == spclkd) {
                    alreadyIn = true;
                }
            }
            if (!alreadyIn && x >= 0 && y >= 0 && x <= col - 1 && y <= row - 1) {
                sf::Sprite spritey;
                sf::Sprite spritey2;
                spritey2.setTexture(clickd);
                spritey2.setPosition(x * 32, y * 32);
                clickSq.push_back(spritey2);
                spritey.setTexture(fivey);
                spritey.setPosition(x * 32, y * 32);
                five.push_back(spritey);
                pos.push_back(spclkd);
                jim.push_back(spritey2);
            }
        }
    }
}