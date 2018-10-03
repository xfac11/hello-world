#include"TileOptions.h"

TileOptions::TileOptions()
{
	this->y = 600.0f;
	this->x = 20.0f;
	this->cap = 20;
	this->from = 0;
	this->end = 10;
	this->nrOfTiles = 0;
	this->currentShowing = 0;
	this->showingtiles = new Tile[10];
	this->leftRight = new Tile[2];
	this->allTiles = new Tile[this->cap];
}

TileOptions::~TileOptions()
{
	delete[] this->showingtiles;
	delete[] this->leftRight;
	delete[] this->allTiles;
}

void TileOptions::addTileTexture(int textureRectPos)//color to texture 
{
	if (this->nrOfTiles == this->cap) //extendurr
	{
		this->cap += 10;
		Tile* temp = new Tile[this->cap];
		for (int i = 0; i < this->nrOfTiles; i++)
		{
			temp[i] = this->allTiles[i];
		}
		delete[] this->allTiles;
		this->allTiles = temp;
	}

	this->allTiles[this->nrOfTiles] = Tile(textureRectPos);
	//this->allTiles[this->nrOfTiles].setTexture(&text);
	//this->allTiles[this->nrOfTiles].setTextureRect(textureRectPos);
	//F�r att visa de f�rsta 
	if (this->nrOfTiles < 10)
	{
		this->showingtiles[this->nrOfTiles] = this->allTiles[this->nrOfTiles];
	}
	if (this->nrOfTiles == 10)
	{
		this->currentShowing = 1;
		this->from = 10;
	}
	//

	//if (this->y >= 67.0f)
	//{
	//	this->x = 20.0f;
	//	this->y = 600.0f;
	//}
	this->nrOfTiles++;
}

void TileOptions::changeShowingTiles()
{
	if (this->end == this->nrOfTiles)
	{
		this->from = 0;
		this->end = 10;
		this->currentShowing = 0;
	}
	if (this->nrOfTiles - (10 * this->currentShowing) > 10)
	{
		this->end = (1 + this->currentShowing) * 10;
	}
	else
	{
		this->end = this->nrOfTiles;
	}

	int j = 0;
	for (int i = this->from; i < this->end; i++)
	{
		this->showingtiles[j] = this->allTiles[i];
		j += 1;
	}
	this->from = this->end;
	this->currentShowing += 1;

}

sf::RectangleShape & TileOptions::getRectFromTiles(const int pos)
{
	return this->showingtiles[pos];
}

void TileOptions::drawCurrentTiles(sf::RenderWindow & window)
{
	int numOfShow = 0;
	if (this->end % 10 == 0)
	{
		numOfShow = 10;
	}
	else
	{
		numOfShow = this->end % 10;
	}
	for (int i = 0; i < numOfShow; i++)
	{
		window.draw(this->showingtiles[i]);
	}
}

void TileOptions::setPosition(float x, float y)
{
	int numOfShow = 0;
	if (this->end % 10 == 0)
	{
		numOfShow = 10;
	}
	else
	{
		numOfShow = this->end % 10;
	}
	for (int i = 0; i < numOfShow; i++)
	{
		this->showingtiles[i].setPosition(this->x+x, this->y+y);
		if (this->x >= 188.0f&&this->y>=768.0f)
		{
			this->x = 20.0f;
			this->y = 726.0f;
		}
		else if (this->x >= 188.0f)
		{
			this->y = 768.0f;
		}
		else
		{
			this->x += 20.0f + 32.0f;
		}
	}
}

Tile TileOptions::getTile(int pos)
{
	return this->showingtiles[pos];
}

int TileOptions::getNrOfCurrentTiles() const
{
	int numOfShow = 0;
	if (this->end % 10 == 0)
	{
		numOfShow = 10;
	}
	else
	{
		numOfShow = this->end % 10;
	}
	return numOfShow;
}
