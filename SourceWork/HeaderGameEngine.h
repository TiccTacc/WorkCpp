#pragma once

#include "HeaderButton.h";
#include "Tetramino.h";
#include "HeaderTextures.h";

using namespace sf;

class GameEngine
{
public:
	GameEngine();
	void run();
private:

	GetTextures manager;

	std::unique_ptr<RenderWindow> window = std::make_unique<RenderWindow>(VideoMode(640, 640), L"Tetris", Style::Close);
	Image icon;

	RectangleShape background = RectangleShape(Vector2f(640, 640));

	Button pause	= Button(Vector2f(13, 140), GetTextures::GetTexture("image/Play.png"),		GetTextures::GetTexture("image/PausePressed.png"));
	Button restart	= Button(Vector2f(13, 220), GetTextures::GetTexture("image/Restart.png"),	GetTextures::GetTexture("image/RestartPressed.png"));
	Button exit		= Button(Vector2f(13, 380), GetTextures::GetTexture("image/Exit.png"),		GetTextures::GetTexture("image/ExitPressed.png"));

	Text text;

	Tetramino tetramino = Tetramino(*window, Vector2f(210, -42), Vector2i(20, 33), 20);
	
	void input();
	void update(Time const& deltaTime);
	void draw();

	bool myexit = false;
	bool mypause = false;
	bool mus = false;

	Time tm;

};

GameEngine::GameEngine() {
	
	background.setTexture(&GetTextures::GetTexture("image/Tetris.png")); // ѕолучение ссылки на текстуру дл€ фона

	if (!icon.loadFromFile("image/game.png")) 
		window->close();

	window->setIcon(256, 256, icon.getPixelsPtr());

	text.setFont(GetTextures::GetFont("font/Godzilla.ttf"));
	text.setFillColor(Color::Green);

	tetramino.maket(Vector2f(70, 20));

}

void GameEngine::input() {
	
	Event event;
	while (window->pollEvent(event)) {
		
		if (event.type == Event::Closed)
			window->close();

		if (Keyboard::isKeyPressed(Keyboard::Left)) {
			tetramino.tetDirection(Tetramino::direction::left);
		}
		else if (Keyboard::isKeyPressed(Keyboard::Right)) {
			tetramino.tetDirection(Tetramino::direction::right);
		}
		else if (Keyboard::isKeyPressed(Keyboard::Down)) {
			tetramino.speed();
		}
		else if (Keyboard::isKeyPressed(Keyboard::Up)) {
			tetramino.rotate();
		}

		if (event.type == Event::MouseWheelMoved) {
			if ((event.mouseWheel.delta == -1) || (event.mouseWheel.delta == 1)) {
				tetramino.speed();
			}
		}

		if (event.type == Event::MouseButtonPressed) {
			if (event.mouseButton.button == sf::Mouse::Left) {
				
				if (pause.checkClick(Mouse::getPosition(*window))) {
					mypause = !mypause;
				}
				
				if (restart.checkClick(Mouse::getPosition(*window))) {
					tetramino.restart();
				}

				if (exit.checkClick(sf::Mouse::getPosition(*window))) {
					myexit = true;
				}
				if ((Mouse::getPosition(*window).x < tetramino.getPositio().x) && (Mouse::getPosition(*window).x > 208) && (Mouse::getPosition(*window).x < 609)) {
					tetramino.tetDirection(Tetramino::direction::left);
				}
				if (Mouse::getPosition(*window).x >= tetramino.getPositio().x && Mouse::getPosition(*window).x > 208 && Mouse::getPosition(*window).x < 609) {
					tetramino.tetDirection(Tetramino::direction::right);
				}
			}
			if (event.mouseButton.button == Mouse::Right) {
				if (Mouse::getPosition(*window).x > 208 && Mouse::getPosition(*window).x < 609) {
					tetramino.rotate();
				}
			}
		}
		
		if (event.type == Event::MouseButtonReleased) {
			if (event.mouseButton.button == Mouse::Left) {
				restart.checkClick();
				exit.checkClick();
			}

		}
	}
}

void GameEngine::update(Time const& deltaTime) {
	
	if (!mypause) 
		tetramino.update(deltaTime);

	if (myexit) {
		tm += deltaTime;
		if (tm > sf::seconds(1)) {
			if (myexit) window->close();
		}
	}
}

void GameEngine::draw() {
	
	window->clear(Color::Black);
	
	tetramino.draw();
	
	window->draw(background);
	window->draw(*pause.getSprite());
	window->draw(*restart.getSprite());
	window->draw(*exit.getSprite());

	text.setPosition(15, 515);
	text.setString(" < score > ");

	window->draw(text);

	text.setString(std::to_string(tetramino.getscore()));
	text.setPosition(100 - text.getGlobalBounds().width / 2, 555);

	window->draw(text);
	window->display();

}

void GameEngine::run() {
	
	Clock clock;
	while (window->isOpen()) {		
		Time dt = clock.restart();
		input(); 
		update(dt);
		draw();
	}
}