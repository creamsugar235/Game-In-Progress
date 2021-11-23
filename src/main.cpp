#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include <random>
#include <thread>
#include <iostream>

int main()
{
	//              x,  y,  width, height
	sf::FloatRect r(50, 40, 30, 20);
	std::cout<<r.left<<" "<<r.top<<" "<<r.width<<" "<<r.height<<std::endl;
	
	return 0;
}