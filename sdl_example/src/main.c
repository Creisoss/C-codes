#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_timer.h>
#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include "./constants.h"


int game_is_running = false;
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

int last_frame_time = 0;

int x_direction = 1;
int y_direction = 1;

struct ball {
	float x;
	float y;
	float width;
	float height;
} ball;


int initialize_window(void) {	
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		fprintf(stderr, "Error initializing SDL.\n");
		return false;
	}
	window = SDL_CreateWindow(
			NULL, 
			SDL_WINDOWPOS_CENTERED, 
			SDL_WINDOWPOS_CENTERED, 
			WINDOW_WIDTH, 
			WINDOW_HEIGHT,
			SDL_WINDOW_BORDERLESS
			);
	if (!window) {
		fprintf(stderr, "Error creating SDL Window.\n");
		return false;
	}
	
	renderer = SDL_CreateRenderer(window, -1, 0);
	if (!renderer) {
		fprintf(stderr, "Error creating SDL Renderer.\n");
		return false;
	}
	
	return true;
}

void process_input(){
	SDL_Event event;
	SDL_PollEvent(&event);
	
	switch (event.type) {
		case SDL_QUIT:
			game_is_running = false;
			break;
		case SDL_KEYDOWN:
			if (event.key.keysym.sym == SDLK_ESCAPE) {
				game_is_running = false;
			}
			break;
		default:
			break;
	}
}

void setup() {
	ball.x = 20;
	ball.y = 20;
	ball.width = 15;
	ball.height = 15;
}

void check_x_wall(){
	if(ball.x >= X_MAX || ball.x <= 0){
		x_direction = x_direction * -1;
	}
}
void check_y_wall(){
	if (ball.y >= Y_MAX || ball.y <= 0) {
		y_direction = y_direction * -1;
	}
}


void update(){
	// LOGIC TO KEEP A FIXED TIMESTEP
	while (!SDL_TICKS_PASSED(SDL_GetTicks(), last_frame_time + FRAME_TARGET_TIME));
	
	// Get a delta time factor converted to seconds to be used to update my objects
	float delta_time = (SDL_GetTicks() - last_frame_time) / 1000.0f;
	
	last_frame_time = SDL_GetTicks();

	ball.x += (X_BALL_VELOCITY * x_direction) * delta_time;
	ball.y += (Y_BALL_VELOCITY * y_direction)* delta_time;
	check_x_wall();
	check_y_wall();
}



void render(){
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	// Draw a rectangle
	SDL_Rect ball_rect = {(int)ball.x, (int)ball.y, (int)ball.width, (int)ball.height};
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(renderer, &ball_rect);
	SDL_RenderPresent(renderer);
}

void destroy_window(){
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

int main(int argc, char *argv[]){
	game_is_running = initialize_window();
	
	setup();

	while (game_is_running) {
		process_input();
		update();
		render();
	}
	destroy_window();
	return 0;
}
