#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include <windows.h>;
#include <fstream>
#include <string>

// Deklaracja levelu 
#define LEVEL 2
#if (LEVEL == 1)
    #define WIDTH 8
    #define HEIGHT 8
    int windowHeight = 400;
    int windowWidth = 400;
#elif (LEVEL == 2)
    #define WIDTH 10
    #define HEIGHT 10
    int windowHeight = 400;
    int windowWidth = 400;
#else 
    #define WIDTH 12
    #define HEIGHT 12
    int windowHeight = 600;
    int windowWidth = 600;
#endif


/*
    * Levele 1 - easy (malo bomb do 10)
    * Levele 2 - mediu (srednia ilosc bomb do 25)
    * Levele 3 - hard (malo bomb do 50)
*/

using namespace sf;

int licznikBomb = 0;
int ruchy = 0;
int iloscBomb = 0;
bool wygrana = false;

int main()
{
    srand(time(0));

    RenderWindow window(VideoMode(windowHeight, windowWidth), "Saper");
    int w = 32;
    int plansza[HEIGHT + 1][HEIGHT + 1];
    int sPlansza[HEIGHT + 1][HEIGHT + 1];

    Texture t;
    t.loadFromFile("images.jpg");
    Sprite s(t);
    Texture win;
    win.loadFromFile("wygrana.png");

    // inicjalizacja planszy i bomb

    for (int i = 1; i <= WIDTH; i++)
        for (int j = 1; j <= WIDTH; j++)
        {
            sPlansza[i][j] = 10;
            if (LEVEL == 1) {
                if (rand() % 8 == 0)
                {
                    plansza[i][j] = 9;
                    iloscBomb++;
                }
                else
                {
                    plansza[i][j] = 0;
                }
            }
            else if (LEVEL == 2)
            {
                if (rand() % 5 == 0)
                {
                    plansza[i][j] = 9;
                    iloscBomb++;
                }
                else
                {
                    plansza[i][j] = 0;
                }
            }
            else {

                if (rand() % 3 == 0)
                {
                    plansza[i][j] = 9;
                    iloscBomb++;
                }
                else
                {
                    plansza[i][j] = 0;
                }
            }
        }

    // inicjalizacja hintow

    for (int i = 1; i <= WIDTH; i++)
        for (int j = 1; j <= WIDTH; j++)
        {
            int n = 0;
            if (plansza[i][j] == 9)
            {
               continue;
            }

            if (plansza[i + 1][j] == 9)
            {
                n++;
            }

            if (plansza[i][j + 1] == 9) 
            {
                n++;
            }

            if (plansza[i - 1][j] == 9) 
            {
                n++;
            }

            if (plansza[i][j - 1] == 9) 
            {
                n++;
            }

            if (plansza[i + 1][j + 1] == 9) 
            {
                n++;
            }

            if (plansza[i - 1][j - 1] == 9) 
            {
                n++;
            }

            if (plansza[i - 1][j + 1] == 9)
            {
                n++;
            }

            if (plansza[i + 1][j - 1] == 9)
            {
                n++;
            }

            plansza[i][j] = n;
            
        }

    while (window.isOpen())
    {
        Vector2i pos = Mouse::getPosition(window);
        int x = pos.x / w;
        int y = pos.y / w;

        Event e;
        Font font;
        while (window.pollEvent(e))
        {
            if (e.type == Event::Closed)
            {
                window.close();

            }

            if (e.type == Event::MouseButtonPressed)
            {
                if (e.key.code == Mouse::Left)
                {
                    sPlansza[x][y] = plansza[x][y];                   
                    ruchy += 1;
                    if (plansza[x][y] == 9) {
                        std::cout << "LOSE " << std::endl;
                        wygrana = false;
                    }
                }

                else if (e.key.code == Mouse::Right)
                {
                    sPlansza[x][y] = 11;
                    if (plansza[x][y] == 9) {
                        licznikBomb += 1;
                    }
                }

            }

        }
        
        window.clear(Color::White);
        if (licznikBomb == iloscBomb)
        {
            wygrana = true;
            
            Sprite winS(win);
            winS.setTexture(win);
            window.draw(winS);
        }
        else
        {

            for (int i = 1; i <= WIDTH; i++)
                for (int j = 1; j <= WIDTH; j++)
                {
                    if (sPlansza[x][y] == 9)
                    {
                        sPlansza[i][j] = plansza[i][j];
                    }
                    s.setTextureRect(IntRect(sPlansza[i][j] * w, 0, w, w));
                    s.setPosition(i * w, j * w);
                    window.draw(s);
                }

        }
        window.display();
    }

    // Zapis do pliku 
    std::ofstream myfile;
    std::string fileName = "rozgrywka.txt";
    myfile.open(fileName, std::fstream::app);
    if (wygrana == true) {
        myfile << "\nRunda wygrana " << std::endl;
    }
    else 
    {
        myfile << "\nRunda przegrana " << std::endl;
    }
    
    myfile << "Liczba ruchow " << ruchy << ", liczba znalezionych bomb " << licznikBomb << ", ilosc bomb lacznie " << iloscBomb << std::endl;
    std::cout << "Zapisano do pliku " << fileName << std::endl;
    myfile.close();

    
    // Odczyt z pliku
    std::cout << "DANE Z PLIKU " << fileName << std::endl;

    std::ifstream fileRead;
    std::string fileText = "";
    fileRead.open("rozgrywka.txt", std::ios_base::in);
    
    if (fileRead.is_open())
    {
        while (fileRead.good())
        {
            getline(fileRead, fileText);
            std::cout << fileText << std::endl;
        }

        fileRead.close();
    }


    return 0;
}
