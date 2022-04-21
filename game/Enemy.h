#ifndef ENEMY_H_
#define ENEMY_H_

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <iostream>

#include "Game.h"
#include "LTexture.h"
#include "Others.h"
#include "Particle.h"
#include "LTimer.h"

class Enemy
{
public:
	static const int ENEMY_VEL = 5;
	static const int ENEMY_MAX_HP = 7;
	static const int SPIN_SPEED = 15;
	static const int TIME_BEFORE_ATTACK = 100;
	static const int ATTACK_RANGE = 100;

	Enemy();
	Enemy(SDL_Renderer* gRenderer, const SDL_Rect& camera);
	~Enemy();

	void init(SDL_Renderer* gRenderer, const SDL_Rect& camera);
	void respawn(const SDL_Rect& camera);

	void react(const SDL_Rect& playerCollider, const bool& playerIsMoving);

	virtual void move(const SDL_Rect& playerCollider);
	void updateVel(const Point& playerPos);
	virtual void attack();

	void render(LTexture& gEnemyTexture, LTexture& gRedTexture, LTexture& gRedSlash, const SDL_Rect& camera);
	void renderParticles(LTexture& gRedTexture, const SDL_Rect& camera);

	SDL_Rect getCollider() { return mCollider; }
	bool getIsAlive() { return isAlive; }
	bool getHit() { return gotHit; }
	bool getIsAppear() { return isAppear; }
	bool getIsAttack() { return isAttack; }

protected:
	SDL_Renderer* renderer;
	Particle* particles[TOTAL_PARTICLES];

	Point mPos;
	int mVelX, mVelY;
	SDL_Rect mCollider;

	int mHP;
	bool gotHit;
	bool isAlive;
	bool isAppear;
	bool hasParticle;
	bool isAttack;

	LTimer mTime;

	int bodyAngle = 0;
	SDL_RendererFlip bodyFlip = SDL_FLIP_NONE;
};

#endif // !ENEMY_H_
