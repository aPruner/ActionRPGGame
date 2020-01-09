#pragma once

class TextureMapConstants {
public:
	// TextureMap Constants
	const std::string c_spriteSheetFilename = "sprites/sprite_sheets/all_sprites.png";
	const std::string c_spriteSheetListFilename = "sprites/dungeon_sprite_sheet_list.txt";

	// TODO: Make a full weapon animation spritesheet using Pyxeledit (animate each weapon and then combine them)
	// For now, just animate the knife
	const std::string c_weaponAnimSpriteSheetFilename = "sprites/sprite_sheets/weapon_animations/knife_anim.png";
	const std::string c_weaponAnimSpriteSheetListFilename = "sprites/weapon_anim_list.txt";

	const std::string c_weaponAirAnimSpriteSheetFilename = "sprites/sprite_sheets/hit_animations/hit_anims_1/swing01.png";
};
