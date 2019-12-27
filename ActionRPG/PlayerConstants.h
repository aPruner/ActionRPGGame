#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class PlayerConstants {
public:
	// Player Constants
	const static int c_startingHealth = 100;
	const static int c_startingSpeed = 200;
	// TODO: Figure out how to define static strings so there is no need to instantiate this class
	const std::string c_idleAnimName = "knight_f_idle_anim";
	const std::string c_runAnimName = "knight_f_run_anim";
};