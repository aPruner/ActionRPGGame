#include "PlayerConstants.h"
#include <string>


// TODO: Convert these to const static maps like how RoomConstants and TileConstants do it
const std::string& PlayerConstants::getPlayerIdleAnimName(PlayerClass playerClass)
{
	switch (playerClass)
	{
	case PlayerClass::Knight:
		c_idleAnimName = std::string("knight_m_idle_anim");
		break;
	case PlayerClass::Wizard:
		c_idleAnimName = std::string("wizzard_m_idle_anim");
		break;
	case PlayerClass::Elf:
		c_idleAnimName = std::string("elf_m_idle_anim");
		break;
	case PlayerClass::Dino:
		c_idleAnimName = std::string("lizard_m_idle_anim");
		break;
	default:
		c_runAnimName = std::string("");
		break;
	}
	return c_idleAnimName;
}


const std::string& PlayerConstants::getPlayerRunAnimName(PlayerClass playerClass)
{
	switch (playerClass)
	{
	case PlayerClass::Knight:
		c_runAnimName = std::string("knight_m_run_anim");
		break;
	case PlayerClass::Wizard:
		c_runAnimName = std::string("wizzard_m_run_anim");
		break;
	case PlayerClass::Elf:
		c_runAnimName = std::string("elf_m_run_anim");
		break;
	case PlayerClass::Dino:
		c_runAnimName = std::string("lizard_m_run_anim");
		break;
	default:
		c_runAnimName = std::string("");
		break;
	}
	return c_runAnimName;
}

const std::string& PlayerConstants::getPlayerHitAnimName(PlayerClass playerClass)
{
	switch (playerClass)
	{
	case PlayerClass::Knight:
		c_hitAnimName = std::string("knight_m_hit_anim");
		break;
	case PlayerClass::Wizard:
		c_hitAnimName = std::string("wizzard_m_hit_anim");
		break;
	case PlayerClass::Elf:
		c_hitAnimName = std::string("elf_m_hit_anim");
		break;
	case PlayerClass::Dino:
		c_hitAnimName = std::string("lizard_m_hit_anim");
		break;
	default:
		c_runAnimName = std::string("");
		break;
	}
	return c_hitAnimName;
}