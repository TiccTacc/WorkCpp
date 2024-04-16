#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

class Button {
private:
    Sprite normal;          // хранит нормальное отображение кнопки
    Sprite clicked;         // хранит отображение нажатой кнопки
    Sprite* currentSpr;     // указатель на Sprite
    bool current = false;   // свойство состо€ни€ кнопки  
    void setState(bool);    // метод мен€ющий отображение кнопки
public:

    Button(Vector2f location, const Texture& normal, const Texture& clicked);   // (координаты кнопки; текстура нормальной кнопки; текстура нажатой кнопки)       
    bool checkClick(Vector2i mousePos = Vector2i(-1, -1));                      // проверка нажати€ на кнопку в параметрах передаютс€ координаты курсора мышки
    Sprite* getSprite();                                                        // текущее состо€ние отображени€ кнопки 
};

Button::Button(Vector2f location, const Texture& normal, const Texture& clicked) {
   
    // устанавливаем текстуры дл€ спрайтов 

    this->normal.setTexture(normal);   // нормальна€ кнопка
    this->clicked.setTexture(clicked); // кнопка нажата

    // устанавливаем координаты расположени€ кнопок

    this->normal.setPosition(location);
    this->clicked.setPosition(location);

    // присваиваем указателю нормальное состо€ние кнопки

    currentSpr = &this->normal;

}

bool Button::checkClick(Vector2i mousePos) {
    
    // если передаютс€ координаты курсора мышки делаем проверку, 
    // что курсор находитс€ в пределах границ кнопки
    if (mousePos.x>=0) {
        if ((static_cast<float>(mousePos.x) > currentSpr->getPosition().x && static_cast<float>(mousePos.x) < (currentSpr->getPosition().x + currentSpr->getGlobalBounds().width))
            && (static_cast<float>(mousePos.y) > currentSpr->getPosition().y && static_cast<float>(mousePos.y) < (currentSpr->getPosition().y + currentSpr->getGlobalBounds().height)) ) {
            
            setState(!current); return true; // мен€ем состо€ние кнопки на противоположное
        }
    }
    else  
        if (current) { // если кнопка нажата мен€ем еЄ вид в нормальное положение
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