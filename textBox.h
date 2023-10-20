//
// Created by andre on 4/10/2023.
//

#ifndef MINESWEEPER_TEXTBOX_H
#define MINESWEEPER_TEXTBOX_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <string>

using namespace std;

class textBox
{
public:
    string text;
    sf::Font font;
    int fontSize;
    bool bold;
    bool underlined;
    sf::Color color;
    int widthMid;
    int heightMid;
    int windowWidth;
    int windowHeight;

    textBox() {}

    textBox(string _text, sf::Font _font, int _fontSize, bool _bold, bool _underlined, sf::Color _color, int _widthMid, int _heightMid, int _windowWidth, int _windowHeight)
    {
        text = _text;
        font = _font;
        fontSize = _fontSize;
        bold = _bold;
        underlined = _underlined;
        color = _color;
        widthMid = _widthMid;
        heightMid = _heightMid;
        windowWidth = _windowWidth;
        windowHeight = _windowHeight;
    }

    sf::Text getText()
    {
        sf::Text newText;
        newText.setString(text);
        newText.setFont(font);
        newText.setCharacterSize(fontSize);
        if (bold)
        {
            newText.setStyle(sf::Text::Bold);
        }
        if (underlined)
        {
            newText.setStyle(sf::Text::Underlined);
        }
        int newTextWidth = newText.getGlobalBounds().width;
        int newTextHeight = newText.getGlobalBounds().height;
        newText.setPosition(widthMid - newTextWidth/2.0f, heightMid - newTextHeight/2.0f);

        return newText;
    }

};

#endif //MINESWEEPER_TEXTBOX_H
