//
// Created by andre on 4/10/2023.
//

#ifndef MINESWEEPER_TEXTINPUT_H
#define MINESWEEPER_TEXTINPUT_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class inputBox
{
public:
    ostringstream text;
    sf::Text inputBoxText;
    int widthMid;
    int heightMid;
    int limit = 9;

    inputBox() {}

    inputBox(int size, sf::Color color, bool bold, int widthMid, int heightMid)
    {
        inputBoxText.setCharacterSize(size);
        inputBoxText.setColor(color);
        inputBoxText.setString("|");
        if (bold)
        {
            inputBoxText.setStyle(sf::Text::Bold);
        }
        int inputBoxTextWidth = inputBoxText.getGlobalBounds().width;
        int inputBoxTextHeight = inputBoxText.getGlobalBounds().height;
        inputBoxText.setPosition(widthMid - inputBoxTextWidth/2.0f, heightMid - inputBoxTextHeight/2.0f);

        this->widthMid = widthMid;
        this->heightMid = heightMid;
    }

    void setFont(sf::Font &font)
    {
        inputBoxText.setFont(font);
    }

    void typed(sf::Event input)
    {
        int chary = input.text.unicode;
        if ((chary < 123 && chary > 96) || (chary > 64 && chary < 91) || chary == 127 || chary == 8)
        {
            if (text.str().length() <= limit)
            {
                inputAction(chary);
            }
            else if (text.str().length() > limit && chary == 8)
            {
                deleteLast();
            }
            else if (chary == 13)
            {

            }
        }

    }

    void drawOn(sf::RenderWindow &window)
    {
        int inputBoxTextWidth = inputBoxText.getGlobalBounds().width;
        int inputBoxTextHeight = inputBoxText.getGlobalBounds().height;
        inputBoxText.setPosition(widthMid - inputBoxTextWidth/2.0f, heightMid - inputBoxTextHeight/2.0f);
        window.draw(inputBoxText);
    }

    void inputAction(int chary)
    {
        if (chary != 8 && chary != 13 && chary != 27)
        {
            text << static_cast<char>(chary);
        }
        else if (chary == 8)
        {
            if (text.str().length() > 0)
            {
                deleteLast();
            }
        }
        inputBoxText.setString(text.str() + "|");
    }

    void deleteLast()
    {
        string t = text.str();
        string newT = "";
        for (int i = 0; i < t.length() - 1; i++)
        {
            newT += t[i];
        }
        text.str("");
        text << newT;

        if (text.str().length() == limit)
        {
            inputBoxText.setString(text.str() + "|");
        }
        else
        {
            inputBoxText.setString(text.str());
        }
    }

};

#endif //MINESWEEPER_TEXTINPUT_H
