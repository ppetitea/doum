#include "SDL.h"
#include <stdio.h>
#include "libft.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#define RATIO 16 / 9
#define HEIGHT 1080
#define WIDTH (HEIGHT * RATIO) 

typedef struct s_point
{
	int x;
	int y;
} t_point;

uint32_t	pp_get_SDLcolor(SDL_Color color)
{
	uint32_t c;
	c = 0xFFFFFFFF;
	c = c | color.a;
	c = c << 8;
	c = c | color.r;
	c = c << 8;
	c = c | color.g;
	c = c << 8;
	c = c | color.b;
	return (c);
}

int pp_putpixel(uint32_t *pixel, int x, int y, SDL_Color color)
{
	uint32_t c;
	c = 0xFFFFFFFF;
	c = c | color.a;
	c = c << 8;
	c = c | color.r;
	c = c << 8;
	c = c | color.g;
	c = c << 8;
	c = c | color.b;
	pixel[y * WIDTH + x] = c; 
	return (0);
}

void	pp_liner(uint32_t *pixel, t_point *a, t_point *b, SDL_Color color)
{
	int tab[10];

	tab[0] = a->x;
	tab[1] = b->x;
	tab[2] = a->y;
	tab[3] = b->y;
	tab[4] = abs(tab[1] - tab[0]);
	tab[5] = tab[0] < tab[1] ? 1 : -1;
	tab[6] = abs(tab[3] - tab[2]);
	tab[7] = tab[2] < tab[3] ? 1 : -1;
	tab[8] = (tab[4] > tab[6] ? tab[4] : -tab[6]) / 2;
	while (!(tab[0] == tab[1] && tab[2] == tab[3]))
	{
		pp_putpixel(pixel, tab[0], tab[2], color);
		tab[9] = tab[8];
		tab[8] -= (tab[9] > -tab[4]) ? tab[6] : 0;
		tab[0] += (tab[9] > -tab[4]) ? tab[5] : 0;
		tab[8] += (tab[9] < tab[6]) ? tab[4] : 0;
		tab[2] += (tab[9] < tab[6]) ? tab[7] : 0;
	}
}

int	get_blue(uint32_t color)
{
	int c;
	color = color << 24;
	color = color >> 24;
	c = (int) color;
	return (c);
}
void	draw_column(uint32_t *pixels, int x, int height, uint32_t color)
{
	if (height > HEIGHT)
		height = HEIGHT;
	while(height--)
		pixels[(HEIGHT - height - 1) * WIDTH + x] = color;
}

void	render(uint32_t *pixels, uint32_t *heightmap, t_point player, float ag, int renderdistance)
{
	(void)pixels;
	(void)heightmap;
	(void)player.x;
	(void)ag;
	(void)renderdistance;
	memset(pixels, 0xFFFFFFFF, WIDTH * HEIGHT * (sizeof(uint32_t)));
	int scale;
	scale = HEIGHT / 255;
	float cosag = cos(ag);
	float sinag = sin(ag);
	
	int columny;
	int columnx;

	while(renderdistance)
	{		
		for(int i = 0; i < WIDTH; i++)
		{
			columny = sinag * renderdistance;
			columnx = cosag * renderdistance;
			draw_column(pixels, i, get_blue(heightmap[columny * WIDTH + columnx] * scale), 0xFF00FFFF);	
		}
		renderdistance--;
	}
}

int main()
{
	SDL_Event e;
	int quit = 0;
	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;
	int statut = EXIT_FAILURE;
	SDL_Texture *texture = NULL;

	if(0 != SDL_Init(SDL_INIT_VIDEO))
		goto Quit;
	window = SDL_CreateWindow("SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
	if(NULL == window)
		goto Quit;
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
	if(NULL == renderer)
		goto Quit;
	texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC, WIDTH, HEIGHT);

	SDL_RenderClear(renderer);

	uint32_t *screen;
	screen = malloc(sizeof(uint32_t) * HEIGHT * WIDTH );
	//memset(screen, 255, WIDTH * HEIGHT * (sizeof(uint32_t)));

	uint32_t *hm;
	hm = malloc(sizeof(uint32_t) * HEIGHT * WIDTH );
	
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_NONE);
	SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_NONE);

	memset(screen, 0x00000000, WIDTH * HEIGHT * sizeof(uint32_t));
	memset(hm, 0xFF0A0A0A, WIDTH * HEIGHT * sizeof(uint32_t));

	t_point player;
	player.x = WIDTH/2;
	player.y = HEIGHT/2;

	render(screen, hm, player, 0, 50);

	while(!quit)
	{
		SDL_UpdateTexture(texture, NULL, screen, WIDTH * sizeof(uint32_t));
		while(SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT) {quit = 1;}
			if (e.type == SDL_KEYDOWN){
				if (e.key.keysym.sym == SDLK_SPACE)
					memset(screen, 0x00000000, WIDTH * HEIGHT * sizeof(uint32_t));
				else
					quit = 1;}
			if (e.type == SDL_MOUSEBUTTONDOWN)
			{
				if (e.button.button == SDL_BUTTON_LEFT)
					printf("%d %d \n", e.button.x, e.button.y);
			}
		}
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, texture, NULL, NULL);
		SDL_RenderPresent(renderer);
	}

	statut = EXIT_SUCCESS;

Quit:
	if(NULL != renderer)
		SDL_DestroyRenderer(renderer);
	if(NULL != texture)
		SDL_DestroyTexture(texture);
	if(NULL != window)
		SDL_DestroyWindow(window);
	SDL_Quit();
	return statut;
}
