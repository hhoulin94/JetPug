#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Box2D/Box2D.h>

#include "MyRectangle.h"

#include <iostream>
#include <sstream>  // for ostringstream
#include <vector>

#include <cstdlib>
#include <time.h>
#include <cstdio>
#include <conio.h>


using namespace std ; 

	float fixedTimeStep = 0.02f; 
	sf::Clock fixedUpdateClock;
	sf::Clock GameTime ; 
	float timeElapsedSinceLastFrame = 0;

   int windowSizeX=700, windowSizeY=600;
   int windowBorderSize = 16;
   int LeftRightBorderSize = 300 ; 

	b2Vec2 gravity(0.f, 9.81f);
	b2World world(gravity);


sf::Font loadFont(const string& fontFilename = "resources/04b03.ttf")
{
   sf::Font myFont;
   if (!myFont.loadFromFile(fontFilename))
   {
      cout << "Can not load font from " << fontFilename << std::endl;
      exit(1);
   }
   return myFont;
}

sf::Texture myBackground ; 
sf::Sprite mybacksprite ; 

sf::Texture LoadBackground(const string& backgroundfilename = "resources/Background.png") {
	
	if(!myBackground.loadFromFile(backgroundfilename)){
		cout << "Can not load background from " << backgroundfilename << endl ; 
		exit(1) ; 
	}


	  myBackground.setSmooth(true);
	  myBackground.setRepeated(false);

	 mybacksprite.setTexture(myBackground);
	 mybacksprite.setOrigin(sf::Vector2f(mybacksprite.getTextureRect().width / 2, mybacksprite.getTextureRect().height / 2));
	 mybacksprite.setPosition(windowSizeX/2 , windowSizeY/2 + 50 );
	 mybacksprite.scale(sf::Vector2f(1.0f, 1.0f));
	 mybacksprite.setColor(sf::Color(255, 255, 255, 255)); 
}

sf::Texture mylogo ; 
sf::Sprite mylogosprite ; 

sf::Texture LoadLogo(const string& logofilename = "resources/logo.png"){
	if(!mylogo.loadFromFile(logofilename)){
		cout << "Can not load background from " << logofilename << endl ; 
		exit(1) ; 
	}


	  mylogo.setSmooth(true);
	  mylogo.setRepeated(false);

	 mylogosprite.setTexture(mylogo);
	 mylogosprite.setOrigin(sf::Vector2f(mylogosprite.getTextureRect().width / 2, mylogosprite.getTextureRect().height / 2));
	 mylogosprite.setPosition(windowSizeX/2 , windowSizeY * 0.1f);
	 mylogosprite.scale(sf::Vector2f(1.0f, 1.0f));
	 mylogosprite.setColor(sf::Color(255, 255, 255, 255)); 
} 

sf::Texture mywood ; 
sf::Sprite mywoodsprite ; 
sf::Sprite mywoodsprite1 ;

sf::Texture LoadWood1(const string& woodfilename = "resources/wood.png"){
	if(!mywood.loadFromFile(woodfilename)){
		cout << "can not load wood from " << woodfilename << endl ; 
		exit(1) ; 
	}

	mywood.setSmooth(true) ;
	mywood.setRepeated(false) ;

	mywoodsprite.setTexture(mywood);
	mywoodsprite.setOrigin(sf::Vector2f(mywoodsprite.getTextureRect().width/2 , mywoodsprite.getTextureRect().height/2)) ;
	mywoodsprite.setPosition(LeftRightBorderSize * 0.1 , windowSizeY + 175) ; 
	mywoodsprite.scale(sf::Vector2f(0.25f, 1.5f));
	mywoodsprite.setColor(sf::Color(255, 255, 255, 255));

	mywoodsprite1.setTexture(mywood);
	mywoodsprite1.setOrigin(sf::Vector2f(mywoodsprite1.getTextureRect().width/2 , mywoodsprite1.getTextureRect().height/2)) ;
	mywoodsprite1.setPosition(windowSizeX-LeftRightBorderSize/8 ,windowSizeY + 175) ; 
	mywoodsprite1.scale(sf::Vector2f(0.25f, 1.5f));
	mywoodsprite1.setColor(sf::Color(255, 255, 255, 255));
} 

sf::Texture mypug1 ; 
sf::Sprite mypug1sprite ; 
sf::Texture LoadPug(const string& pugfilename = "resources/pug1.png"){
	if(!mypug1.loadFromFile(pugfilename)){
		cout << "can not load pug1 from " << pugfilename << endl ; 
		exit(1) ; 
	}

	mypug1.setSmooth(true) ; 
	mypug1.setRepeated(false) ;

	mypug1sprite.setTexture(mypug1);
	mypug1sprite.setOrigin(sf::Vector2f(mypug1sprite.getTextureRect().width/2 , mypug1sprite.getTextureRect().height/2)) ;
	mypug1sprite.scale(sf::Vector2f(1.0f, 1.0f));
	mypug1sprite.setColor(sf::Color(255, 255, 255, 255));
}


sf::Texture mypug2 ; 
sf::Sprite mypug2sprite ; 
sf::Texture LoadPug2(const string& pugfile2name = "resources/pug2.png"){
	if(!mypug2.loadFromFile(pugfile2name)){
		cout << "can not load pug2 from " << pugfile2name << endl ; 
		exit(1) ; 
	}

	mypug2.setSmooth(true) ; 
	mypug2.setRepeated(false) ;

	mypug2sprite.setTexture(mypug2);
	mypug2sprite.setOrigin(sf::Vector2f(mypug2sprite.getTextureRect().width/2 , mypug2sprite.getTextureRect().height/2)) ;
	mypug2sprite.scale(sf::Vector2f(1.0f, 1.0f));
	mypug2sprite.setColor(sf::Color(255, 255, 255, 255));
}

sf::Texture mypug1attack ; 
sf::Sprite mypug1attacksprite ; 
sf::Texture LoadPug1attack(const string& pugfile3name = "resources/pug1attack.png"){
	if(!mypug1attack.loadFromFile(pugfile3name)){
		cout << "can not load pug1attack from " << pugfile3name << endl ; 
		exit(1) ; 
	}

	mypug1attack.setSmooth(true) ; 
	mypug1attack.setRepeated(false) ;

	mypug1attacksprite.setTexture(mypug1attack);
	mypug1attacksprite.setOrigin(sf::Vector2f(mypug1attacksprite.getTextureRect().width/2 , mypug1attacksprite.getTextureRect().height/2)) ;
	mypug1attacksprite.scale(sf::Vector2f(0.25f, 0.25f));
	mypug1attacksprite.setColor(sf::Color(255, 255, 255, 255));
}

sf::Texture mypug2attack ; 
sf::Sprite mypug2attacksprite ; 
sf::Texture LoadPug2attack(const string& pugfile4name = "resources/pug2attack.png"){
	if(!mypug2attack.loadFromFile(pugfile4name)){
		cout << "can not load pug2attack from " << pugfile4name << endl ; 
		exit(1) ; 
	}

	mypug2attack.setSmooth(true) ; 
	mypug2attack.setRepeated(false) ;

	mypug2attacksprite.setTexture(mypug2attack);
	mypug2attacksprite.setOrigin(sf::Vector2f(mypug2attacksprite.getTextureRect().width/2 , mypug2attacksprite.getTextureRect().height/2)) ;
	mypug2attacksprite.scale(sf::Vector2f(0.25f, 0.25f));
	mypug2attacksprite.setColor(sf::Color(255, 255, 255, 255));
}
 
int main()
{
	//Clear Screen
	system("cls"); 

	LoadPug() ; 
	LoadPug1attack() ; 

	LoadPug2() ; 
	LoadPug2attack() ; 

	LoadWood1() ;

	LoadLogo() ; 

	sf::Music backmusic ; 

	if(!backmusic.openFromFile("resources/background.ogg")){
		cout << "No Audio Found" << endl; 
	}

	backmusic.setPosition(0, 1, 10); // change its 3D position
	backmusic.setVolume(100);         // reduce the volume
	backmusic.setLoop(true); 
	
	backmusic.play() ; 
	
	sf::Music punch ; 

	if(!punch.openFromFile("resources/punch.ogg")){
		cout << "No Audio Found" << endl; 
	}

	punch.setPosition(0, 1, 10); // change its 3D position
	punch.setVolume(125);          

	sf::RenderWindow window(sf::VideoMode(windowSizeX, windowSizeY), "Jet Pug Wrestle Mania !");

	// Set vSync to true (and as a result, we have a cap of 60FPS)
	window.setVerticalSyncEnabled(true);
    window.setActive();

    //Player Creation 
	sf::Vector2f PlayerSize(80 , 67) ; 

	//Player1
	float Player1X = windowSizeX *0.75f ;
	float Player1Y = windowSizeY * 0.95f - 50 ; 

	sf::Vector2f Player1InitPos(Player1X, Player1Y);


    MyRectangle Player1(world , PlayerSize , Player1InitPos , 0.0 , true) ; 
              Player1.setOutlineThickness(-1);
              Player1.setFillColor(sf::Color(255, 255, 255,0));
	
    //Player 2 
    float Player2X = windowSizeX * 0.25f  ;
    float Player2Y = windowSizeY * 0.95f - 50 ;

    sf::Vector2f Player2InitPos(Player2X , Player2Y) ; 
    MyRectangle Player2(world , PlayerSize , Player2InitPos , 0.0 , true) ; 
              Player2.setOutlineThickness(-1);
              Player2.setFillColor(sf::Color(255, 255, 255 ,0)); 
	

	//Border Creation
	sf::Vector2f horizontalBorderSize(windowSizeX,25);
	sf::Vector2f TopBorderSize(windowSizeX , 200) ; 
	sf::Vector2f verticalBorderSize(windowBorderSize,windowSizeY-windowBorderSize + 15);

	sf::Vector2f bottomBorderPos(windowSizeX/2               	  ,windowSizeY-windowBorderSize/2 - 50);
	sf::Vector2f   leftBorderPos(LeftRightBorderSize * 0.1          ,windowSizeY + 175 );
	sf::Vector2f  rightBorderPos(windowSizeX-LeftRightBorderSize/8 ,windowSizeY + 175) ;
	sf::Vector2f topBorderPos(windowSizeX/2 , windowSizeY - 600 ) ; 

	MyRectangle bottomBorder(world, horizontalBorderSize, bottomBorderPos, 0.0, false);
              bottomBorder.setOutlineThickness(-1);
              bottomBorder.setFillColor(sf::Color(255, 255, 255 , 0));

	MyRectangle leftBorder(world, verticalBorderSize, leftBorderPos, 0.0, false);
              leftBorder.setOutlineThickness(-1);
              leftBorder.setFillColor(sf::Color(255,255,255,0));

	MyRectangle rightBorder(world, verticalBorderSize, rightBorderPos, 0.0, false);
              rightBorder.setOutlineThickness(-1);
              rightBorder.setFillColor(sf::Color(255,255,255,0));

    MyRectangle topBorder(world , TopBorderSize , topBorderPos , 0.0 , false );
   			  topBorder.setOutlineThickness(-1);
              topBorder.setFillColor(sf::Color(255,255,255,0));
	
	// Text creation
	sf::Font font = loadFont();
	sf::Text text;
	text.setFont(font);  
	text.setCharacterSize(30);
	text.setPosition(windowSizeX/2 - 100, windowSizeY* 0.5f);
	text.setColor(sf::Color::Black);
		 
	sf::Text insturctLeft; 
	insturctLeft.setFont(font); 
	insturctLeft.setCharacterSize(20) ; 
	insturctLeft.setPosition(windowSizeX * 0.25f - 175, windowSizeY * 0.3f);
	insturctLeft.setColor(sf::Color::Black) ; 

	sf::Text insturctRight; 
	insturctRight.setFont(font) ;
	insturctRight.setCharacterSize(20) ; 
	insturctRight.setPosition(windowSizeX * 0.75f - 450, windowSizeY * 0.5f ) ;
	insturctRight.setColor(sf::Color::Black)  ;

	LoadBackground() ; 
	sf::Clock coutdown ;

	bool GameOver = false ; 

	//Update Loop	
	while(window.isOpen())
	{
		//Setting Sprite To Position
		mypug1sprite.setPosition(Player1.rect_.getPosition().x, Player1.rect_.getPosition().y) ;

		mypug2sprite.setPosition(Player2.rect_.getPosition().x, Player2.rect_.getPosition().y) ;

		mypug1attacksprite.setPosition( -300 , 0) ;

		mypug2attacksprite.setPosition( -300, 0) ; 
		
		sf::Event event;

		while (window.pollEvent(event));
		{

			//Delay issues
			if(event.type == sf::Event::Closed)
				window.close();
		}

		//Player 1 Boolean
		bool moveRightbool = false ; 
		bool moveLeftbool = false ; 
		bool moveDownbool = false ; 
		bool moveUpbool = false ; 

		//Control Player 1 Movement 
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
			if(!moveUpbool){
				Player1.MoveUp() ; 
				moveUpbool = true ; 
			}
		}else{
			moveUpbool = false ; 
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
		if(!moveRightbool){
			 Player1.MoveRight() ; 
			 moveRightbool = true ; 
			}
		}else{
			moveRightbool = false ;
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
			if(!moveLeftbool){
				Player1.MoveLeft() ; 
				moveLeftbool = true ;  
			}	 
		}else{
			moveLeftbool = false ; 
		}


		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
			if(!moveDownbool){
				Player1.Notmove() ; 
				moveDownbool = true ; 
			}	 
		}else{
			moveDownbool = false ; 
		}

		bool moveLbool = false ; 
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::M)){
			float difference = Player1.rect_.getPosition().x - Player2.rect_.getPosition().x ; 
			if(difference < 81.0f){
				mypug2attacksprite.setPosition(mypug1sprite.getPosition().x , mypug1sprite.getPosition().y) ; 
				mypug1sprite.setPosition(-300 , 0) ; 
				Player2.PunchUp() ; 
				punch.play() ;
			}
		}

		//Player 2 Control
		bool moveRight2bool = false ; 
		bool moveLeft2bool = false ; 
		bool moveDown2bool = false ; 
		bool moveUp2bool = false ; 

		//Player 2 movement 
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
			if(!moveUp2bool){
				Player2.MoveUp() ; 
				moveUp2bool = true ; 
			}
		}else{
			moveUp2bool = false ; 
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
			if(!moveRightbool){
			 Player2.MoveRight() ; 
			 moveRight2bool = true ; 
			}
		}else{
			moveRight2bool = false ;
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
			if(!moveLeftbool){
				Player2.MoveLeft() ; 
				moveLeft2bool = true ;  
			}	 
		}else{
			moveLeft2bool = false ; 
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
			if(!moveDown2bool){
				Player2.Notmove() ; 
				moveDown2bool = true ; 
			}	 
		}else{
			moveDown2bool = false ; 
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::O)){
			
			float difference = (Player2.rect_.getPosition().x - Player1.rect_.getPosition().x) * -1 ; 

				if(difference < 81.0f){
					mypug1attacksprite.setPosition(mypug2sprite.getPosition().x , mypug2sprite.getPosition().y) ; 
					Player1.PunchUp() ;
					mypug2sprite.setPosition(-300 , 0) ;
					punch.play() ; 
				}
			
		}

		//Setting Up Winning String
		if(Player1.rect_.getPosition().x > rightBorder.rect_.getPosition().x || Player1.rect_.getPosition().x < leftBorder.rect_.getPosition().x){
			text.setString("Player 2 Win !"); 
			GameOver = true ; 
		}else if (Player2.rect_.getPosition().x > rightBorder.rect_.getPosition().x || Player2.rect_.getPosition().x < leftBorder.rect_.getPosition().x){
			text.setString("Player 1 Win !") ;
			GameOver = true;
		}else{
			text.setString(" ") ; 
		}

		//Clock For Tutorial
		sf::Time GameElapsedTime = GameTime.getElapsedTime() ; 
		sf::Time waitlo = sf::seconds(3) ; 

 
		sf::Time elapsedTime = coutdown.getElapsedTime();
        sf::Time waitTime = sf::seconds(2); 

        if(elapsedTime > waitTime){
    		insturctRight.setString(" ") ;
			insturctLeft.setString(" ") ;  
		}else{
			insturctRight.setString(" Up: Jump  Left: Left  Right: Right  Down: Fall  M: Fire ->") ;
			insturctLeft.setString(" <- A: Left  W: Jump  S: Fall  D: Right  O: Fire " ) ; 
		}

		

		timeElapsedSinceLastFrame += fixedUpdateClock.restart().asSeconds();


		if(timeElapsedSinceLastFrame >= fixedTimeStep)
		{

			// Step is used to update physics position/rotation
			world.Step(fixedTimeStep, //update frequency
                    8,                //velocityIterations
                    3                 //positionIterations  
                   );

			// Update the objects that uses physics
			Player2.update() ; 
			Player1.update();
	
			bottomBorder.update();
			leftBorder.update();
			rightBorder.update();
			topBorder.update() ; 

			timeElapsedSinceLastFrame -= fixedTimeStep;
		}

		// Rendering
		window.clear(sf::Color(149,216,232));	

		//Render Sprite
		window.draw(mybacksprite) ; 
		window.draw(mywoodsprite) ; 
		window.draw(mywoodsprite1) ;
		
		window.draw(mypug1sprite) ; 
		window.draw(mypug2sprite) ;
		window.draw(mypug1attacksprite) ;
		window.draw(mypug2attacksprite) ;

		// Render all objects, transparent and replace by sprite
		window.draw(Player2.getShape()) ; 
		window.draw( Player1.getShape());
		
		window.draw(bottomBorder.getShape());
		window.draw(  leftBorder.getShape());
		window.draw( rightBorder.getShape());
		window.draw(topBorder.getShape()) ;

		//Render 
		window.draw(mylogosprite) ;

		window.draw(text);

		window.draw(insturctRight) ;
		window.draw(insturctLeft) ;
		
		window.display();

		//reopen window when game over
		if(GameOver == true){
			sf::sleep(sf::seconds(2));
			window.close() ;
			backmusic.stop() ; 
			punch.stop() ; 
			sf::sleep(sf::milliseconds(10)) ;  
			system("a.exe") ; 
		}
	}

	return 0;
}
