#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

class Button {
private:
    Sprite normal;          // ������ ���������� ����������� ������
    Sprite clicked;         // ������ ����������� ������� ������
    Sprite* currentSpr;     // ��������� �� Sprite
    bool current = false;   // �������� ��������� ������  
    void setState(bool);    // ����� �������� ����������� ������
public:

    Button(Vector2f location, const Texture& normal, const Texture& clicked);   // (���������� ������; �������� ���������� ������; �������� ������� ������)       
    bool checkClick(Vector2i mousePos = Vector2i(-1, -1));                      // �������� ������� �� ������ � ���������� ���������� ���������� ������� �����
    Sprite* getSprite();                                                        // ������� ��������� ����������� ������ 
};

Button::Button(Vector2f location, const Texture& normal, const Texture& clicked) {
   
    // ������������� �������� ��� �������� 

    this->normal.setTexture(normal);   // ���������� ������
    this->clicked.setTexture(clicked); // ������ ������

    // ������������� ���������� ������������ ������

    this->normal.setPosition(location);
    this->clicked.setPosition(location);

    // ����������� ��������� ���������� ��������� ������

    currentSpr = &this->normal;

}

bool Button::checkClick(Vector2i mousePos) {
    
    // ���� ���������� ���������� ������� ����� ������ ��������, 
    // ��� ������ ��������� � �������� ������ ������
    if (mousePos.x>=0) {
        if ((static_cast<float>(mousePos.x) > currentSpr->getPosition().x && static_cast<float>(mousePos.x) < (currentSpr->getPosition().x + currentSpr->getGlobalBounds().width))
            && (static_cast<float>(mousePos.y) > currentSpr->getPosition().y && static_cast<float>(mousePos.y) < (currentSpr->getPosition().y + currentSpr->getGlobalBounds().height)) ) {
            
            setState(!current); return true; // ������ ��������� ������ �� ���������������
        }
    }
    else  
        if (current) { // ���� ������ ������ ������ � ��� � ���������� ���������
            setState(!current);
            return true; 
        } 

    return false;

}

void Button::setState(bool which) {
    
    current = which;
    if (current) {
        currentSpr = &clicked;
        return;
    }
    currentSpr = &normal;
}

Sprite* Button::getSprite() {
    return currentSpr;
}