//
// Created by Jaime Blasco, Clara Landaríbar, Belén García on May 2018.
// 

#include "Clouds.h"
#include "Cloud.h"
#include <time.h> 
#include <stdio.h> 
#include <stdlib.h>  

// Group of clouds init
Clouds::Clouds() {
	srand(time(NULL));
	figures = {};
	//Create 50 clouds with random values
	for (int i = 0; i < 50; i++) figures.push_back(new Cloud(rand() % 10000 / 1000.));
}

void Clouds::draw() {
	//Draws all figuress
	for (Figure* figure : figures) figure->draw();
}