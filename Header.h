#include <SFML/Graphics.hpp>	
#include <Windows.h>
#include "resource.h"			
#include "texture1.h"
using namespace sf;

void showScore(int sc[2], Sprite score[2], int& c, Sprite& cifr);
void showStartMenu(bool& menu, bool& setting, bool& game, bool& pok, bool& animation, bool& play, int& screen_width, int& kx, int& ky, Sprite player[2], Sprite& ball, Vector2i& pos, RenderWindow& window);
void showMenuSettings(bool& setting, bool& pok, bool& menu, Sprite& gal, int& c, Vector2i& pos);
void showMenuControl(Vector2i& pos, bool& game, bool& pok, bool& menu, bool& animation, bool& play, int& kx, int& ky, int& screen_width, Sprite& ball, Sprite player[2]);
void showMenuPause(Vector2i& pos, bool& pause, bool& play, bool& animation, bool& menu, int sc[2], Sprite player[2], Sprite& ball, int& screen_width, int& kx, int& ky);
void showMenuWins(Vector2i& pos, bool& stop, bool& menu, bool& animation, bool& play, int sc[2]);
void drawObjects(RenderWindow& window, Sprite& win, Sprite winbut[2], Sprite& pau, Sprite& con, Sprite pbut[2], Sprite& nazpause, Sprite& butplay, Sprite uprav[2], Sprite score[2], Sprite& KO, Sprite& cifr, Sprite& bsc, Sprite& gal, Sprite& npok, Sprite& back, Sprite& UI, Sprite& nac, Sprite& nastroy, Sprite& exit, Sprite player[2], Sprite& ball, Sprite& naz, Color& Dark_Green, CircleShape& circle, RectangleShape& line, bool& menu, bool& setting, bool& game, bool& pok, bool& play, bool& stop, bool& pause);
void ballCollisionBorder(bool& play, int& ky, Vector2f& b);
void paddleCollisions(bool& play, int& kx, int& screen_height, int& screen_width, Vector2f p[2], Sprite player[2], Sprite& ball);
void menuAnimation(bool& animation, Sprite player[2], Vector2f& b, Vector2f p[2]);
void scoreIncrease(Vector2f& b, Sprite& ball, int& screen_width, int sc[2]);
void showWins(int sc[2], bool& stop, Sprite player[2], Sprite& ball, int& kx, int& ky, int& c, int& screen_width, Sprite& win);
void keyControl(bool& stop, bool& pause, Sprite player[2]);
void dragAndDrop(Event& event, Sprite player[2], int& dx, int& dy, Vector2f& posp, bool& isMove);


void dragAndDrop(Event& event, Sprite player[2], float& dx, float& dy, Vector2f& posp, bool& isMove) {
	if (event.type == Event::MouseButtonPressed) {
		if (event.key.code == Mouse::Left) {
			if (player[0].getGlobalBounds().contains(posp.x, posp.y)) {
				dx = posp.x - player[0].getPosition().x;
				dy = posp.y - player[0].getPosition().y;
				isMove = true;
			}
		}
	}
	if (event.type == Event::MouseButtonReleased)
		if (event.key.code == Mouse::Left) {
			isMove = false;
			player[0].setColor(Color::Yellow);
		}
	if (isMove) {
		player[0].setColor(Color::Green);
		player[0].setPosition(posp.x - dx, posp.y - dy);

	}
}
void showScore(int sc[2], Sprite score[2], int& c, Sprite& cifr) {

	for (int i = 0; i < 2; i++) {
		if (sc[i] < 10)
			score[i].setTextureRect(IntRect(50 * sc[i], 0, 50, 75));
		else if (sc[i] == 10)
			score[i].setTextureRect(IntRect(500, 0, 75, 75));
		else if (sc[i] == 11)
			score[i].setTextureRect(IntRect(580, 0, 75, 75));
	}
	if (c < 10)
		cifr.setTextureRect(IntRect(50 * c, 0, 50, 75));
	else if (c == 10)
		cifr.setTextureRect(IntRect(500, 0, 75, 75));
	else if (c == 11)
		cifr.setTextureRect(IntRect(580, 0, 75, 75));
}
void showStartMenu(bool& menu, bool& setting, bool& game, bool& pok, bool& animation, bool& play, int& screen_width, int& kx, int& ky, Sprite player[2], Sprite& ball, Vector2i& pos, RenderWindow& window) {
	if (menu) {
		if (pos.x >= 500 && pos.x <= 734 && pos.y >= 470 && pos.y <= 533) {	//button exit
			window.close();
		}
		if (pos.x >= 500 && pos.x <= 734 && pos.y >= 370 && pos.y <= 433) {	//button settings
			menu = false;
			setting = true;
			PlaySound(MAKEINTRESOURCEW(IDR_WAVE2), NULL, SND_RESOURCE | SND_ASYNC);	//sound that not needs openal32.dll
		}
		if (pos.x >= 500 && pos.x <= 734 && pos.y >= 270 && pos.y <= 333) {	//button start game
			game = true;
			menu = false;
			if (!pok) {
				animation = false;
				play = true;
				for (int i = 0; i < 2; ++i)
					player[i].setPosition((screen_width - 35) * i, 250);
				ball.setPosition(40, 320);
				kx = 1, ky = 1;
			}
			PlaySound(MAKEINTRESOURCEW(IDR_WAVE2), NULL, SND_RESOURCE | SND_ASYNC);	//sound that not needs openal32.dll
		}
	}
}
void showMenuSettings(bool& setting, bool& pok, bool& menu, Sprite& gal, int& c, Vector2i& pos) {
	if (setting) {
		if (pos.x >= 595 && pos.x <= 683 && pos.y >= 300 && pos.y <= 375 && c < 11)	//button +
		{
			c++;
			PlaySound(MAKEINTRESOURCEW(IDR_WAVE2), NULL, SND_RESOURCE | SND_ASYNC);	//sound that not needs openal32.dll
		}
		else if (pos.x >= 520 && pos.x <= 595 && pos.y >= 300 && pos.y <= 375 && c > 3)	//button -
		{
			c--;
			PlaySound(MAKEINTRESOURCEW(IDR_WAVE2), NULL, SND_RESOURCE | SND_ASYNC);
		}
		//conditions that provide function disable hints
		if (pos.x >= 360 && pos.x <= 431 && pos.y >= 630 && pos.y <= 701) {	//interactive object checkbox fill
			if (pok) {
				pok = false;
				gal.setTextureRect(IntRect(71, 0, 71, 71));
				PlaySound(MAKEINTRESOURCEW(IDR_WAVE2), NULL, SND_RESOURCE | SND_ASYNC);
			}
			else if (!pok) {
				pok = true;
				gal.setTextureRect(IntRect(0, 0, 71, 71));
				PlaySound(MAKEINTRESOURCEW(IDR_WAVE2), NULL, SND_RESOURCE | SND_ASYNC);
			}
		}
		if (pos.x >= 50 && pos.x <= 321 && pos.y >= 650 && pos.y <= 727) {	//button back in settings menu
			menu = true;
			setting = false;
			PlaySound(MAKEINTRESOURCEW(IDR_WAVE2), NULL, SND_RESOURCE | SND_ASYNC);
		}
	}
}
void showMenuControl(Vector2i& pos, bool& game, bool& pok, bool& menu, bool& animation, bool& play, int& kx, int& ky, int& screen_width, Sprite& ball, Sprite player[2]) {
	if (game && pok) {
		if (pos.x >= 50 && pos.x <= 321 && pos.y >= 650 && pos.y <= 727) {	//button back in menu with play control information
			menu = true;
			game = false;
			PlaySound(MAKEINTRESOURCEW(IDR_WAVE2), NULL, SND_RESOURCE | SND_ASYNC);
		}
		if (pos.x >= 450 && pos.x <= 722 && pos.y >= 650 && pos.y <= 722) {	//button start game in menu with play control information
			game = false;
			animation = false;
			play = true;
			for (int i = 0; i < 2; ++i)
				player[i].setPosition((screen_width - 35) * i, 250);
			ball.setPosition(40, 320);
			kx = 1, ky = 1;
			PlaySound(MAKEINTRESOURCEW(IDR_WAVE2), NULL, SND_RESOURCE | SND_ASYNC);
		}
	}
}
void showMenuPause(Vector2i& pos, bool& pause, bool& play, bool& animation, bool& menu, int sc[2], Sprite player[2], Sprite& ball, int& screen_width, int& kx, int& ky) {
	if (pause) {
		if (pos.x >= 500 && pos.x <= 734 && pos.y >= 260 && pos.y <= 323) {	//button continue
			pause = false;
			PlaySound(MAKEINTRESOURCEW(IDR_WAVE2), NULL, SND_RESOURCE | SND_ASYNC);
		}
		if (pos.x >= 460 && pos.x <= 761 && pos.y >= 360 && pos.y <= 438) {		//button start again
			for (int i = 0; i < 2; i++)
				sc[i] = 0;
			pause = false;
			for (int i = 0; i < 2; i++)
				player[i].setPosition((screen_width - 35) * i, 250);
			ball.setPosition(40, 320);
			kx = 1, ky = 1;
			PlaySound(MAKEINTRESOURCEW(IDR_WAVE2), NULL, SND_RESOURCE | SND_ASYNC);
		}
		if (pos.x >= 480 && pos.x <= 741 && pos.y >= 460 && pos.y <= 538) {		//button return to menu
			pause = false;
			play = false;
			animation = true;
			menu = true;
			for (int i = 0; i < 2; i++)
				sc[i] = 0;
			for (int i = 0; i < 2; i++)
				player[i].setPosition((screen_width - 35) * i, 250);
			ball.setPosition(40, 320);
			kx = 1, ky = 1;
			PlaySound(MAKEINTRESOURCEW(IDR_WAVE2), NULL, SND_RESOURCE | SND_ASYNC);
		}
	}
}
void showMenuWins(Vector2i& pos, bool& stop, bool& menu, bool& animation, bool& play, int sc[2]) {
	if (stop) {
		if (pos.x >= 50 && pos.x <= 352 && pos.y >= 600 && pos.y <= 678) {	//button start game
			for (int i = 0; i < 2; i++)
				sc[i] = 0;
			stop = false;
			PlaySound(MAKEINTRESOURCEW(IDR_WAVE2), NULL, SND_RESOURCE | SND_ASYNC);
		}
		if (pos.x >= 475 && pos.x <= 730 && pos.y >= 600 && pos.y <= 678) {	//button return to menu
			menu = true;
			animation = true;
			stop = false;
			play = false;
			for (int i = 0; i < 2; i++)
				sc[i] = 0;
			PlaySound(MAKEINTRESOURCEW(IDR_WAVE2), NULL, SND_RESOURCE | SND_ASYNC);
		}
	}
}
void drawObjects(RenderWindow& window, Sprite& win, Sprite winbut[2], Sprite& pau, Sprite& con, Sprite pbut[2], Sprite& nazpause, Sprite& butplay, Sprite uprav[2], Sprite score[2], Sprite& KO, Sprite& cifr, Sprite& bsc, Sprite& gal, Sprite& npok, Sprite& back, Sprite& UI, Sprite& nac, Sprite& nastroy, Sprite& exit, Sprite player[2], Sprite& ball, Sprite& naz, Color& Dark_Green, CircleShape& circle, RectangleShape& line, bool& menu, bool& setting, bool& game, bool& pok, bool& play, bool& stop, bool& pause) {
	window.clear(Color(Dark_Green));
	window.draw(circle);
	window.draw(line);
	for (int i = 0; i < 2; i++)	//draw paddle of players and ball
		window.draw(player[i]);
	window.draw(ball);
	if (menu) {			//draw object main menu - buttons and description
		window.draw(naz);
		window.draw(nac);
		window.draw(nastroy);
		window.draw(exit);
	}
	if (setting) {		//draw object menu-settings - buttons, interactive object and other
		window.draw(KO);
		window.draw(cifr);
		window.draw(bsc);
		window.draw(gal);
		window.draw(npok);
		window.draw(back);
	}
	if (game && pok) {	//draw object in menu with information about control of players
		window.draw(UI);
		window.draw(nazpause);
		window.draw(back);
		window.draw(butplay);
		for (int i = 0; i < 2; i++)
			window.draw(uprav[i]);
	}
	if (play)		//draw scores of players
		for (int i = 0; i < 2; i++)
			window.draw(score[i]);
	if (stop) {		//draw message about winner and button win-menu
		window.draw(win);
		window.draw(winbut[0]);
		window.draw(winbut[1]);
	}
	if (pause) {	//draw object if menu-pause
		window.draw(pau);
		window.draw(con);
		for (int i = 0; i < 2; i++)
			window.draw(pbut[i]);
	}
	window.display();
}
void ballCollisionBorder(bool& play, int& ky, Vector2f& b) {
	if (b.y < 0 || b.y>730) {
		ky *= -1;
		//conditions that disable sound of ball if game not start, but animations play
		if (play)
			PlaySoundW(MAKEINTRESOURCEW(IDR_WAVE1), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC);
	}
}
void paddleCollisions(bool& play, int& kx, int& screen_height, int& screen_width, Vector2f p[2], Sprite player[2], Sprite& ball) {
	for (int i = 0; i < 2; i++) {
		p[i] = player[i].getPosition();
		if (ball.getGlobalBounds().intersects(player[i].getGlobalBounds())) {
			kx *= -1;
			if (kx < 0)
				ball.move(-10, 0);
			if (play)
				PlaySoundW(MAKEINTRESOURCEW(IDR_WAVE1), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC);
		}
		//conditions that decide collisions of padle of players with border fields
		if (p[i].y > screen_height - 210)
			player[i].setPosition((screen_width - 35) * i, screen_height - 210);
		if (p[i].y < 0)
			player[i].setPosition((screen_width - 35) * i, 0);
	}
}
void menuAnimation(bool& animation, Sprite player[2], Vector2f& b, Vector2f p[2]) {
	if (animation)
		for (int i = 0; i < 2; i++) {
			if (b.y > p[i].y)
				player[i].move(0, 0.5);
			if (b.y < p[i].y)
				player[i].move(0, -0.5);
		}
}
void scoreIncrease(Vector2f& b, Sprite& ball, int& screen_width, int sc[2]) {
	//condition that provide increasing score blue player if yellow player missed ball
	if (b.x < -100) {
		ball.setPosition(screen_width - 100, 320);
		sc[1]++;
		PlaySound(MAKEINTRESOURCEW(IDR_WAVE3), NULL, SND_RESOURCE | SND_ASYNC);
	}
	//condition that provide increasing score yellow player if blue player missed ball
	else if (b.x > screen_width) {
		ball.setPosition(40, 320);
		sc[0]++;
		PlaySound(MAKEINTRESOURCEW(IDR_WAVE3), NULL, SND_RESOURCE | SND_ASYNC);
	}
}
void showWins(int sc[2], bool& stop, Sprite player[2], Sprite& ball, int& kx, int& ky, int& c, int& screen_width, Sprite& win) {
	//condition that provide display message "yellow wins"
	if (sc[0] == c) {
		stop = true;
		player[0].setPosition(0, 250);
		win.setTextureRect(IntRect(0, 0, 493, 57));
		ball.setPosition(40, 320);
		kx = 1, ky = 1;
	}
	//condition that provide display message "blue wins
	else if (sc[1] == c) {
		stop = true;
		player[1].setPosition((screen_width - 35), 250);
		win.setTextureRect(IntRect(0, 57, 493, 57));
		ball.setPosition(40, 320);
		kx = 1, ky = 1;
	}
}
void keyControl(bool& stop, bool& pause, Sprite player[2]) {
	if (!stop && !pause) {
		if (Keyboard::isKeyPressed(Keyboard::Up))
			player[1].move(0, -0.75);
		if (Keyboard::isKeyPressed(Keyboard::Down))
			player[1].move(0, 0.75);
		if (Keyboard::isKeyPressed(Keyboard::W))
			player[0].move(0, -0.75);
		if (Keyboard::isKeyPressed(Keyboard::S))
			player[0].move(0, 0.75);
	}
}