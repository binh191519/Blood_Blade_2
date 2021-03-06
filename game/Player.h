#ifndef PLAYER_H_
#define PLAYER_H_

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <iostream>

#include "Game_Base.h"
#include "LTexture.h"
#include "LTimer.h"
#include "Tile.h"
#include "Geometry.h"
#include "Particle.h"

class Player
{
public:
	static const int PLAYER_VEL = 20;
	static const int PLAYER_MAX_HP = 100;
	static const int FORCE_SLOW_DOWN = 10;
	static const int FORCE_CAPABILITY = 100;
	static const int FORCE_LOSS = 2;
	static const int PLAYER_MAX_STRENGTH = 50;
	static const int ULTIMATE_TIME = 200;
	static const int SCORE_TO_NEXT_ULTIMATE = 25;

	Player();
	Player(SDL_Renderer* gRenderer, LTexture& gRedTexture);
	~Player();

	//Init player
	void init(SDL_Renderer* gRenderer, LTexture& gRedTexture);

	//Update sword angle, mouse's init and last position
	void handleEvent(SDL_Event& e, const SDL_Rect& camera);

	//Update x, y velocity
	void updateVel(const int& x, const int& y);

	//Update player's attack collider
	void updateAttackCollider(const int& score);

	//Update player's stats 
	void react(const bool& eIsAttack, const SDL_Rect& eAttackCollider);

	//Update player's position
	void move(Tile* tiles[]);

	//Update player's force when hold
	void updateForce();

	//Centers the camera over player
	void setCamera(SDL_Rect& camera);

	//Render particles ~ mForce
	void renderParticles(LTexture& gRedTexture, const SDL_Rect& camera);

	//Render player, effects, sounds
	void render(LTexture& gPlayerTexture, LTexture& gRedTexture, LTexture& gBlueSlashTexture, LTexture& gWeaponTexture, LTexture& gRedCircleTexture, LTexture& gUltimateTexture, const SDL_Rect& camera, Mix_Chunk* gSwordSlashSound);

	SDL_Rect getCollider() { return mCollider; }
	SDL_Rect getAttackCollider() { return mAttackCollider; }
	bool getIsAttack() { return (mVelX != 0) || (mVelY != 0) || isUltimate; }
	bool getIsAlive() { return isAlive; }
	bool getIsAppear() { return isAppear; }
	void pBlock() { gotBlock = true; }

private:
	SDL_Renderer* renderer;
	Particle* particles[TOTAL_PARTICLES];

	Point mPos;
	SDL_Rect mCollider;
	int mVelX, mVelY;
	int mForce;

	int mHP;
	int mStrength;
	SDL_Rect mAttackCollider;
	int scoreToUltimate;

	bool gotHit;
	bool gotBlock;
	bool canUltimate;
	bool isUltimate;
	bool isAlive;
	bool isAppear;

	//Mouse stuff
	Point initPos, lastPos;
	LTimer mTime;
	bool isHold = false;
	double swordAngle = 0;

	//Player flip when change direction
	SDL_RendererFlip bodyFlip = SDL_FLIP_NONE;
};

#endif // !PLAYER_H_

