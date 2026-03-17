#include <raylib.h>
#include "gameMain.h"
#include <iostream>
#include <assetManager.h>
#include <gameMap.h>
#include <helpers.h>

struct GameData
{
	GameMap gameMap;
	Camera2D camera = {};
}gameData;

AssetManager assetManager;

bool initGame()
{
	assetManager.LoadAll();

	
	gameData.gameMap.Create(30, 10);

	gameData.gameMap.getBlocUnsafe(0, 0).type = Block::dirt;
	gameData.gameMap.getBlocUnsafe(1, 1).type = Block::blueRubyBlock;
	gameData.gameMap.getBlocUnsafe(2, 2).type = Block::boneWordrobe;
	gameData.gameMap.getBlocUnsafe(3, 3).type = Block::grass;
	gameData.gameMap.getBlocUnsafe(4, 4).type = Block::copperBlock;

	gameData.camera.target = { 0, 0 };
	gameData.camera.rotation = 0.f;
	gameData.camera.zoom = 100.0f;

	return true;
}

bool updateGame()
{
	float dt = GetFrameTime();
	if(dt > 1.f / 5) {dt = 1 / 5.f;}

	gameData.camera.offset = { GetScreenWidth() / 2.f, GetScreenHeight() / 2.f };

	ClearBackground({ 75, 75, 150, 255 });

#pragma region camera movement
	if (IsKeyDown(KEY_A)) gameData.camera.target.x -= 7.f * dt;
	if (IsKeyDown(KEY_D)) gameData.camera.target.x += 7.f * dt;
	if (IsKeyDown(KEY_S)) gameData.camera.target.y += 7.f * dt;
	if (IsKeyDown(KEY_W)) gameData.camera.target.y -= 7.f * dt;
#pragma endregion


	BeginMode2D(gameData.camera);
	
	for (int y = 0; y < gameData.gameMap.h; y++)
	{
		for (int x = 0; x < gameData.gameMap.w; x++)
		{
			auto& b = gameData.gameMap.getBlocUnsafe(x, y);

			if (b.type != Block::air)
			{

				DrawTexturePro(
					assetManager.textures,
					getTextureAtlas(b.type, 0, 32, 32),
					{ (float)x, (float)y, 1, 1 },
					{ 0, 0 },
					0.0f,
					WHITE
				);
			}
		}
	}
	EndMode2D();

	return true;
}

void closeGame()
{
	std::cout << "CLOSE GAME!!!@!@!@!@!@!@!@\n";
}