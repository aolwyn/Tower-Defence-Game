#ifndef INC_320PROJECTMAINMENU_MAINMENU_H
#define INC_320PROJECTMAINMENU_MAINMENU_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

#define MAX_NUMBER_OF_ITEMS 3

using namespace std;

class MainMenu {
public:
    MainMenu(float width, float height);
    ~MainMenu();

    void draw(sf::RenderWindow &window);
    void MoveUp();	//selects the option above (moves selected thing up)
    void MoveDown(); //selects the option below (moves selected thing down)
    int GetPressedItem(){return selectedItemIndex;} //gets the pressed item



    /*   static void init();

        static void open();

        static void close();

        static void destroy_quit_btn();
     */
private:
    int selectedItemIndex;
    sf::Font font;
    sf::Text menu[MAX_NUMBER_OF_ITEMS];
    /*
        static void on_click_play();

        static void on_click_quit();

     */
};

#endif //INC_320PROJECTMAINMENU_MAINMENU_H