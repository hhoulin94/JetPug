#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>


using namespace std ; 

class MyRectangle
{
 private:

	b2BodyDef bodyDef_;
	b2PolygonShape bodyShape_;
	b2FixtureDef bodyFixtureDef_;

 public:

 	b2Body* body_;
	sf::RectangleShape rect_;
	
	MyRectangle(b2World& world,
               sf::Vector2f size,
				sf::Vector2f position,
				float rotation = 0,
               bool isDynamic = true
              );

	void setFillColor(sf::Color col);
	void setOutlineThickness(float thickness);
	void setOutlineColor(sf::Color col);
	void update();

	void MoveRight() ; 
	void MoveLeft() ; 
	void MoveUp() ; 
	void PunchUp() ;
	void Notmove() ;  	
	
	sf::Shape& getShape();

};
