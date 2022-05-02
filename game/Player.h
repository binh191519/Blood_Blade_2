#ifndef PLAYER_H_
#define PLAYER_H_

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <string>
#include <iostream>

#include "Game.h"
#include "LTexture.h"
#include "LTimer.h"
#include "Others.h"
#include "Particle.h"
//#include "Tile.h"

class Player
{
public:
	static const int PLAYER_VEL = 20;
	static const int PLAYER_MAX_HP = 100;

	Player(SDL_Renderer* gRenderer, LTexture& gRedTexture, const SDL_Rect& camera);
	~Player();

	void handleEvent(SDL_Event& e, const SDL_Rect& camera);
	void react(const SDL_Rect& enemyCollider, const bool& enemyAttack);

	void move(Tile* tiles[]);
	void updateVel(const int& x, const int& y);
	void updateForce();

	//Centers the camera over the dot
	void setCamera(SDL_Rect& camera);

	void render(LTexture& gPlayerTexture, LTexture& gRedTexture, LTexture& gBlueSlash, LTexture& gRedSword, LTexture& gRedCircle, const SDL_Rect& camera, Mix_Chunk* gSwordSlash);
	void renderParticles(LTexture& gRedTexture, const SDL_Rect& camera);

	void die();

	Point getPos() { return mPos; }
	SDL_Rect getCollider() { return mCollider; }
	int getForce() { return mForce; }
	int getHP() { return mHP; }
	bool getIsAttack() { return (mVelX != 0) || (mVelY != 0); }
	bool getIsAlive() { return isAlive; }

private:
	SDL_Renderer* renderer;
	Particle* particles[TOTAL_PARTICLES];

	Point mPos;
	int mVelX, mVelY;
	int mForce;
	SDL_Rect mCollider;
	double swordAngle = 0;

	int mHP;
	bool gotHit;
	bool isAlive;
	bool isAppear;

	//Mouse stuff
	Point initPos, lastPos;
	bool isHold = false;
	LTimer mTime;

	//Player flip when change direction
	SDL_RendererFlip flip = SDL_FLIP_NONE;
};

#endif // !PLAYER_H_

