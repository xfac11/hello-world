#ifndef MAPEDITOR_H
#define MAPEDITOR_H
#include "TileMap.h"
#include"TileOptions.h"
#include"Textbox.h"
#define BLOCKWIDTH 32.f //g�r klass som h�ller alla define
#define BLOCKHEIGHT 32.f
class MapEditor
{
private:
	TileMap currentMap;
	bool isPressed;
	bool isMovable;
	//InputHandler theInputs;
	bool isRightClick;
	bool tileChange;

	TileType currentTileType;
	int currentTileTypeNr;
	sf::Text currentTileTypeText;
	std::string currentTileTypeString;
	sf::Font tileTypeFont;

	sf::RectangleShape tileMenu;
	sf::Texture arrow[4];
	sf::RectangleShape theArrows[4];

	TileOptions theTileOptions;
	sf::Texture textureForAll;
	sf::RectangleShape theMouse;
	Tile* tempBlock;
	int prevId;

	float speedForMovingCamera;

	float windowX(float size);
	float windowY(float size);

	sf::RectangleShape saveRect;
	sf::RectangleShape loadRect;
	sf::RectangleShape hudForLoadNSaveNText;
	Textbox textBox;

	bool temp;
	sf::Vector2i getMouseID();
	bool mouseOnObject(sf::RectangleShape object);
	void updateHUD(sf::View &view, float deltaTime);

public:
	MapEditor();
	~MapEditor();
	bool getTypeMode()const;
	void draw(sf::RenderWindow & window, float deltaTime, sf::View & view,sf::Event &theEvent);
	
	
};
#endif