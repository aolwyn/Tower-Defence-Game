#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "MainMenu.h"
//#include "button.h" <--include the button header
//#include state handler


using namespace std;

MainMenu::MainMenu(float width, float height) {



    /*  //create background image
        sf::Texture textureMM;
        if(!textureMM.loadFromFile("C://Users//secre//CLionProjects//320ProjectMainMenu//queen_s_td_title_no_buttons.png"));
        {
            std::cout << "Error! Could not load Main Menu from file.";
            //    return 0;
        }
        sf::Sprite mainMenu;
        mainMenu.setTexture(textureMM);

        //insert rest of buttons and their location on screen.
    }
     */

    sf::Font font;
    font.loadFromFile("arial.ttf");

//menu[x].setSize(12);
//menu[x].setOutlineColor(sf::Color::___);

    menu[0].setFont(font);
    menu[0].setString("Play");
    menu[0].setFillColor(sf::Color::White);
    menu[0].setStyle(sf::Text::Regular);
    menu[0].setPosition(sf::Vector2f(width/2, height/(3+1)*1)); //for positioning

    menu[1].setFont(font);
    menu[1].setString("Options");
    menu[1].setStyle(sf::Text::Regular);
    menu[1].setFillColor(sf::Color::White);
    menu[1].setPosition(sf::Vector2f(width/2, height/(3+1)*2));

    menu[2].setFont(font);
    menu[2].setString("Exit");
    menu[1].setStyle(sf::Text::Regular);
    menu[2].setFillColor(sf::Color::White);
    menu[2].setPosition(sf::Vector2f(width/2, height/(3+1)*3));

}

MainMenu::~MainMenu() {}

void MainMenu::draw(sf::RenderWindow &window)
{
    for (int i = 0; i < 3; i++){
        window.draw(menu[i]);
    }

    selectedItemIndex = 0;
}

void MainMenu::MoveUp() { //for when the players hits the arrow up key.
    if(selectedItemIndex -1 >= 0){  //there's 3 indexes in the array, 1 for each 'button' or in this case text
        menu[selectedItemIndex].setFillColor(sf::Color::White); //sets the previously selected thing to white
        selectedItemIndex--;        //deselects previous
        menu[selectedItemIndex].setFillColor(sf::Color::Red); //selects new option, colors it red
    }

}

//same thing as move up but going down
void MainMenu::MoveDown(){
    if(selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS){
        menu[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex++;
        menu[selectedItemIndex].setFillColor(sf::Color::Red);
    }

}
/*Below is the code for the main.cpp I was using to test. it may help you understand what's going on.
 *
int main() {

    sf::RenderWindow window(sf::VideoMode(1000,1000), "SFML WORK!");
    MainMenu  MainMenu(window.getSize().x, window.getSize().y);
    while (window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::KeyReleased:
                    switch(event.key.code)
                    {
                        case sf::Keyboard::Up:
                            MainMenu.MoveUp();
                            break;

                        case sf::Keyboard::Down:
                            MainMenu.MoveDown();
                            break;
                        case sf::Keyboard::Return:
                            switch(MainMenu.GetPressedItem())
                            {
                                case 0:
                                    std::cout<<"Play button has been pressed"<<std::endl;
                                case 1:
                                    std::cout<<"Option button has been pressed"<<std::endl;
                                case 2:
                                    window.close();
                                    break;
                            }
                            break;
                    }
                    break;
                case sf::Event::Closed:
                    window.close();
                    break;
            }
        }
        window.clear();
        MainMenu.draw(window);
        window.display();
    }
}
 */