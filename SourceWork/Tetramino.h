#pragma once
#include "HeaderTextures.h"
#include <array>
#include <vector>
#include <chrono>
#include <random>
#include <math.h>

using namespace sf;

class Tetramino {
public:
	
	enum class direction { left = -1, nuLL, right }; // ������������ ����������� �������� ��������� �� �����������
	enum class ch { x, y, rotation }; // ������������ �������� ��������� �� ������������ � ������������� ���������, ��� ����������� � ��������/

	explicit Tetramino(RenderWindow&, Vector2f, Vector2i, float);	// ����������� ���������

	void tetDirection(direction);	// ����� ��������������� ������ �������� ���������
	void draw();					// ����� �������� ��������� � ����������� ����
	void update(Time const&);	// ���������� ������� ������ ���������
	void rotate();					// ����� �������� ���������
	void speed();					// ����� ���������� ������� ���������
	void restart();					// ����� ������������ ��� �������� � ��������� �������� - ������� ����
	int getscore() const;			// ����� ������������ ���������� ���������� �����
	void maket(Vector2f);		// ����� ����������� ������ ���������� ���������

	Vector2f getPositio();		// ����� ������������ ���������� ������ ���������

private:

	const int height;               // ������ �������� ���� 
	const int width;                // ������ �������� ���� 
	const  float click_dy = 1.0f;   // ��� ����������� ��������� �� y  

	std::vector <std::vector <Color>> square;	// ������ �������� ����
	std::array <std::array <int, 4>, 7> figures { {{1,3,5,7},{2,4,5,7},{3,4,5,6},{3,4,5,7},{2,3,5,7},{3,5,6,7},{2,3,4,5}} };	// ������ ��������� ��������� ������� ��������� 
	std::array <Vector2f, 4> t;	// ��������� �������������� � ���������� ��������� 
	
	// ������ ����� ��� ���������
	std::array <Color, 7>
		tetcolor{ {
				Color::Blue,
				Color::Cyan,
				Color::Yellow, 
				Color::Green,
				Color::Magenta,
				Color::Red,
				Color::White} };	

	std::unique_ptr <RectangleShape> cube = std::make_unique<RectangleShape>();	// ������������� ���������
	long long seed = std::chrono::system_clock::now().time_since_epoch().count();	// ������ ���������� �������
	std::default_random_engine rnd = std::default_random_engine(static_cast<long>(seed));	// ������ ���������� ��������� �����
	std::uniform_int_distribution<int> d = std::uniform_int_distribution<int>(0, 6);		// ��������� ��������� ��������� �����
	
	RenderWindow& window;	// ������ �� ����������� ����
	const Vector2f tet;			// ��������� ���������� ���������
	Time frameRate;				// �������� ���������� ������� ������ 
	Vector2i typeTet;			// ��� ��������� 
	Vector2i colTet;			// ���� ��������� 
	void newFigrois();				// ����� ���������  
	void lineDead(int);				// ����������� ������� ��������� ��� ���������� ���� �� ����������� 
	bool check(ch);					// �������� ��������� ��������� 
	Int32 delay;					// �������� ��������� ������� ������ 
	float click_dx;					// ��� ����������� ��������� �� x  
	int score;						// ���� �������� 
	float scale;					// ������� ��������� 

	Vector2f positionmaket = Vector2f(-1, -1);	// �������� ��������� ������ ���������
};

Tetramino::Tetramino(RenderWindow& window, Vector2f pos, Vector2i square_size, float scale)
	: height(square_size.y), width(square_size.x), window(window), tet(pos), scale(scale) {
	
	cube->setOutlineColor(Color(78, 87, 84));
	cube->setOutlineThickness(-1);
	cube->setSize(Vector2f(scale, scale));
	
	for (int i = 0; i < width; i++) {
		std::vector<Color> v;
		for (int j = 0; j < height; j++) {
			v.push_back(Color::Black);
		}
		square.push_back(v);
	}

	restart();

}

void Tetramino::restart() {
	
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			square[i][j] = Color::Black;
		}
	}

	typeTet.y	= d(rnd);
	colTet.y	= d(rnd);

	score = 0;
	newFigrois();

}

void Tetramino::newFigrois() {
	
	typeTet.x = typeTet.y;
	colTet.x = colTet.y;
	for (int i = 0; i < 4; i++) {
		t[i].x = figures[typeTet.x][i] % 2 + static_cast<float>(floor(width / 2));
		t[i].y = static_cast<float>(figures[typeTet.x][i] / 2);
	}

	typeTet.y	= d(rnd);
	colTet.y	= d(rnd);

	delay = 250;
}

void Tetramino::update(Time const& deltaTime) {

	frameRate += deltaTime;

	if (frameRate > milliseconds(delay)) {
		frameRate = milliseconds(0);
		if (check(ch::x) && click_dx != 0) {
			for (int i = 0; i < 4; i++) t[i].x += click_dx; click_dx = 0;
		}
		if (check(ch::y)) {
			for (int i = 0; i < 4; i++)  
				t[i].y += click_dy; 
		}
		else {
			for (int i = 0; i < t.size(); i++) {
				if (static_cast<int>(t[i].y) == 2) { 
					restart();
					return; 
				}

				square[static_cast<size_t>(t[i].x)][static_cast<size_t>(t[i].y)] = Color(tetcolor[colTet.x]);
			}

			int numLine = 0;
			for (int j = 0; j < height; j++) {
				
				int line = 0;
				for (int i = 0; i < width; i++) {
					if (square[i][j] != Color::Black) 
						line++;

					if (line == width) {
						lineDead(j);
						numLine++;
					}
				}
			}
			if (numLine != 0) {
				score += 5 * (numLine * numLine);
			}
			newFigrois();
		}
	}
}

void Tetramino::tetDirection(direction dir) {
	click_dx = static_cast<float> (dir);
}

void Tetramino::rotate() {
	
	if (check(ch::rotation)) {
		
		Vector2f centerRotation = t[1];
		for (int i = 0; i < t.size(); i++) {
			float x = t[i].y - centerRotation.y;
			float y = t[i].x - centerRotation.x;
			t[i].x = centerRotation.x - x;
			t[i].y = centerRotation.y + y;
		}
	}
}

void Tetramino::speed() {
	delay = 10;
}

void Tetramino::lineDead(int g) {
	
	for (int i = g; i > 0; i--) {
		for (int j = 0; j < width; j++) {
			square[j][i] = square[j][static_cast<size_t>(i - 1)];
		}
	}

}

bool Tetramino::check(ch ch)
{
	switch (ch) {
	case Tetramino::ch::x: {	
		for (int i = 0; i < t.size(); i++) {
			if ((t[i].x + click_dx < 0) || (t[i].x + click_dx > static_cast<float>(width - 1))) 
				return false;

			if ((static_cast<int>(t[i].y) >= 0) && (square[static_cast<size_t>(t[i].x + click_dx)][static_cast<size_t>(t[i].y)]	!= Color::Black)) 
				return false;
		}
	break; 
	}

	case Tetramino::ch::y:{	
		for (int i = 0; i < t.size(); i++) {
			if ((t[i].y + click_dy) > static_cast<float>(height - 1))  
				return false;
			if ((static_cast<int>(t[i].y + click_dy) >= 0) && (square[static_cast<size_t>(t[i].x)][static_cast<size_t>(t[i].y + click_dy)]!= Color::Black))  
				return false;
	}
	break;
	}

	case Tetramino::ch::rotation:{ 
		
		Vector2f centerRotation = t[1];
		for (int i = 0; i < t.size(); i++) {
			
			float x = t[i].y - centerRotation.y;
			float y = t[i].x - centerRotation.x;
			
			if (((centerRotation.x - x) < 0) || ((centerRotation.x - x) > static_cast<float>(width - 1)) || ((centerRotation.y + y) > static_cast<float>(height - 1))) 
				return false;

			if ((static_cast<int>(centerRotation.y + y) >= 0) && (square[static_cast<size_t>(centerRotation.x - x)][static_cast<size_t>(centerRotation.y + y)]!= Color::Black)) 
				return false;
		}
	break; 
	}
	default:
		break;
	}

	return true;

}

void Tetramino::draw() {
	
	if (positionmaket.x >= 0) {
		
		cube->setFillColor(tetcolor[colTet.y]);
		for (int i = 0; i < 4; i++) {
			cube->setPosition((figures[typeTet.y][i] % 2) * scale, (static_cast<float>(figures[typeTet.y][i] / 2)) * scale);
			cube->move(positionmaket);
			window.draw(*cube);
		}
	}
	
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			cube->setFillColor(square[i][j]);
			cube->setPosition(static_cast<float>(i) * scale, static_cast<float>(j) * scale);
			cube->move(tet);
			window.draw(*cube);
		}
	}
	
	cube->setFillColor(tetcolor[colTet.x]);
	for (int i = 0; i < t.size(); i++) {
		cube->setPosition(t[i].x * scale, t[i].y * scale);
		cube->move(tet);
		window.draw(*cube);
	}
}

int Tetramino::getscore() const {
	return score;
}

Vector2f Tetramino::getPositio() {
	
	Vector2f pos;
	pos.x = t[1].x * scale + tet.x;
	pos.y = t[1].y * scale + tet.y;
	return pos;

}

void Tetramino::maket(Vector2f posmak) {
	positionmaket = posmak;
}