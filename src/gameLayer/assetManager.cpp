#include "assetManager.h"

void AssetManager::LoadAll()
{
	dirt = LoadTexture(RESOURCES_PATH "dirt.png");

	textures = LoadTexture(RESOURCES_PATH "textures.png");

}