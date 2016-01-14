#include "MyRectangle.h"

//use 2^n Value 
static const float PIXEL_PER_METER = 64.0f;

MyRectangle::MyRectangle(b2World& world,
                         sf::Vector2f size,
						 sf::Vector2f position,
						 float rotation,
                         bool isDynamic
                         )

{
	//SFML part
	rect_ = sf::RectangleShape(size);
	rect_.setOrigin(sf::Vector2f(size.x/2,size.y/2));
	rect_.setFillColor(sf::Color(255, 0, 0, 255));
	rect_.setOutlineThickness(-1);
	rect_.setOutlineColor(sf::Color(255 , 255 , 255 ,0));

	//Box2D 
	bodyDef_.position = b2Vec2(position.x/PIXEL_PER_METER, position.y/PIXEL_PER_METER);

	if (isDynamic)
   {
      bodyDef_.type = b2_dynamicBody;
   }
   else  
   {
      bodyDef_.type = b2_staticBody;
   }

	bodyShape_.SetAsBox((size.x/2)/PIXEL_PER_METER, (size.y/2)/PIXEL_PER_METER);

	bodyFixtureDef_.shape = &bodyShape_;
	bodyFixtureDef_.density = 1.0f;
	bodyFixtureDef_.friction = 0.5f;

	body_ = world.CreateBody(&bodyDef_);
	body_->CreateFixture(&bodyFixtureDef_);
	
}

void MyRectangle::setFillColor(sf::Color col)
{
	rect_.setFillColor(col);
}

void MyRectangle::setOutlineThickness(float thickness)
{
	rect_.setOutlineThickness(thickness);
}

void MyRectangle::setOutlineColor(sf::Color col)
{
	rect_.setOutlineColor(col);
}

void MyRectangle::update()
{
	// Box2D uses radians for rotation, SFML uses degree
    rect_.setRotation(0);
    rect_.setPosition( body_->GetPosition().x*PIXEL_PER_METER, body_->GetPosition().y*PIXEL_PER_METER);
    
}

sf::Shape& MyRectangle::getShape()
{
	return rect_;
}

void MyRectangle::MoveRight(){
	float randomX = rand() % 5 + 2.5f; 
	body_->SetLinearVelocity(b2Vec2(randomX,0)) ; 
}	

void MyRectangle::MoveLeft(){
	float randomX = rand() % 5 + 2.5f ; 
	body_->SetLinearVelocity(b2Vec2(-randomX,0)) ; 
}

void MyRectangle::Notmove(){
	body_->SetLinearVelocity(b2Vec2(0,0)) ; 
}

void MyRectangle::PunchUp(){
	body_->ApplyLinearImpulse( b2Vec2(0, -3.0f), body_->GetWorldCenter()) ;
}

void MyRectangle::MoveUp(){
	body_->ApplyLinearImpulse( b2Vec2(0, -3.0f), body_->GetWorldCenter()) ;
}
