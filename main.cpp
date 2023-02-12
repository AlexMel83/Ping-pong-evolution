#include "Header.h"

//разнести программу по функциям
//реализовать взаимодействие с объектом в сфмл при взаимодействии

int main() {
	Color Dark_Green = Color{ 20,160,133,255 };
	Color Light_Green = Color{ 129,204,184,255 };
	int screen_width = 1200, screen_height = 800, kx = 1, ky = 1, c = 3;
	float dx = 0, dy = 0;
	bool isMove = false, menu = true, setting = false, pok = true, game = false, animation = true, play = false, stop = false, pause = false;
	RenderWindow window(VideoMode(screen_width, screen_height), "Ping-pong Evolution");
	RectangleShape line(Vector2f(1, screen_height));
	line.setFillColor(Color::White);
	line.setPosition(screen_width / 2, 0);
	CircleShape circle(200);
	circle.setPosition(screen_width / 2 - 200, screen_height / 2 - 200);
	circle.setFillColor(Light_Green);
	Image icon;
	icon.loadFromMemory(iconicon, sizeof(iconicon));
	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	Texture t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20;
	t1.loadFromMemory(player, sizeof(player));
	t2.loadFromMemory(ball, sizeof(ball));
	t3.loadFromMemory(nazva, sizeof(nazva));
	t4.loadFromMemory(butplay, sizeof(butplay));
	t5.loadFromMemory(nastroy, sizeof(nastroy));
	t6.loadFromMemory(exitb, sizeof(exitb));
	t7.loadFromMemory(KO, sizeof(KO));
	t8.loadFromMemory(cifr, sizeof(cifr));
	t9.loadFromMemory(bsc, sizeof(bsc));
	t10.loadFromMemory(gal, sizeof(gal));
	t11.loadFromMemory(npok, sizeof(npok));
	t12.loadFromMemory(back, sizeof(back));
	t13.loadFromMemory(UI, sizeof(UI));
	t14.loadFromMemory(nazvapause, sizeof(nazvapause));
	t15.loadFromMemory(uprav, sizeof(uprav));
	t16.loadFromMemory(nac, sizeof(nac));
	t17.loadFromMemory(win, sizeof(win));
	t18.loadFromMemory(winbut, sizeof(winbut));
	t19.loadFromMemory(pau, sizeof(pau));
	t20.loadFromMemory(cont, sizeof(cont));
	Sprite player[2], ball(t2), naz(t3), butplay(t4), nastroy(t5), exit(t6), KO(t7), cifr(t8), bsc(t9), gal(t10), npok(t11), back(t12), UI(t13), nazpause(t14), uprav[2], nac(t16), score[2], win(t17), winbut[2], pau(t19), con(t20), pbut[2];
	for (int i = 0; i < 2; ++i) {
		player[i].setTexture(t1);
		player[i].setTextureRect(IntRect(40 * i, 0, 36, 208));
		player[i].setPosition((screen_width - 35) * i, 250);
	}
	ball.setScale(1, 1);
	ball.setPosition(40, 320);
	naz.setPosition(40, 30);
	nac.setPosition(500, 270);
	nastroy.setPosition(500, 370);
	exit.setPosition(500, 470);
	KO.setPosition(440, 130);
	cifr.setTextureRect(IntRect(150, 0, 50, 75));
	cifr.setPosition(575, 215);
	bsc.setPosition(520, 300);
	gal.setTextureRect(IntRect(0, 0, 71, 71));
	gal.setPosition(360, 630);
	npok.setPosition(450, 620);
	back.setPosition(50, 650);
	UI.setPosition(140, 170);
	nazpause.setPosition(180, 340);
	butplay.setPosition(450, 650);
	for (int i = 0; i < 2; ++i) {
		uprav[i].setTexture(t15);
		uprav[i].setTextureRect(IntRect(118 * i, 0, 118, 217));
		uprav[i].setPosition(50 + 550 * i, 250);
	}
	int sc[2]{ 0, 0 };
	score[0].setTexture(t8);
	score[1].setTexture(t8);
	score[0].setPosition(100, 10);
	score[1].setPosition((screen_width - 100), 10);
	win.setPosition(350, 150);
	for (int i = 0; i < 2; ++i) {
		winbut[i].setTexture(t18);
		winbut[i].setPosition(50 + 425 * i, 600);
	}
	winbut[0].setTextureRect(IntRect(0, 0, 302, 78));
	winbut[1].setTextureRect(IntRect(302, 0, 261, 78));
	pau.setPosition(50, 120);
	con.setPosition(500, 260);
	for (int i = 0; i < 2; ++i)
		pbut[i].setTexture(t18);
	pbut[0].setPosition(460, 360);
	pbut[1].setPosition(480, 460);
	pbut[0].setTextureRect(IntRect(0, 0, 302, 78));
	pbut[1].setTextureRect(IntRect(302, 0, 261, 78));
	while (window.isOpen()) {
		Event event;
		Vector2i pixelPos = Mouse::getPosition(window);
		Vector2f posp = window.mapPixelToCoords(pixelPos);
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
			if (event.type == Event::MouseButtonPressed) {
				if (event.key.code == Mouse::Left) {
					Vector2i pos = Mouse::getPosition(window);
					showStartMenu(menu, setting, game, pok, animation, play, screen_width, kx, ky, player, ball, pos, window);
					showMenuSettings(setting, pok, menu, gal, c, pos);
					showMenuControl(pos, game, pok, menu, animation, play, kx, ky, screen_width, ball, player);
					showMenuPause(pos, pause, play, animation, menu, sc, player, ball, screen_width, kx, ky);
					showMenuWins(pos, stop, menu, animation, play, sc);
				}
			}
			dragAndDrop(event, player, dx, dy, posp, isMove);
		}
		if (!pause)
			ball.move(0.5 * kx, 0.5 * ky);
		Vector2f b = ball.getPosition();
		ballCollisionBorder(play, ky, b);
		Vector2f p[2];
		paddleCollisions(play, kx, screen_height, screen_width, p, player, ball);
		menuAnimation(animation, player, b, p);
		if (play) {
			keyControl(stop, pause, player);
			scoreIncrease(b, ball, screen_width, sc);
			showWins(sc, stop, player, ball, kx, ky, c, screen_width, win);
			if (Keyboard::isKeyPressed(Keyboard::Escape))
				pause = true;
		}
		showScore(sc, score, c, cifr);
		drawObjects(window, win, winbut, pau, con, pbut, nazpause, butplay, uprav, score, KO, cifr, bsc, gal, npok, back, UI, nac, nastroy, exit, player, ball, naz, Dark_Green, circle, line, menu, setting, game, pok, play, stop, pause);
	}
	return 0;
}
