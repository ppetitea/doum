#include "SDL.h"
#include <stdio.h>
#include "libft.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#define RATIO 16 / 9
#define HEIGHT 1080
#define WIDTH (HEIGHT * RATIO) 

typedef struct		s_point
{
	int			x;
	int			y;
}					t_point;

typedef struct		s_rect
{
	int			x;
	int			y;
	int			h;
	int			w;
}					t_rect;

typedef struct		s_poly
{
	int			x1;
	int			y1;
	int			x2;
	int			y2;
	int			x3;
	int			y3;
	int			x4;
	int			y4;
}					t_poly;

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

int pp_putpixel_renderer(SDL_Renderer *renderer, int x, int y, SDL_Color color)
{
	SDL_Color tmp;

	SDL_GetRenderDrawColor(renderer, &tmp.r, &tmp.g, &tmp.g, &tmp.a);
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	SDL_RenderDrawPoint(renderer, x, y);
	SDL_SetRenderDrawColor(renderer, tmp.r, tmp.g, tmp.b, tmp.a);
	return (0);
}

void	brush_square(uint32_t *pixels, int x, int y, int size, SDL_Color color)
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			pp_putpixel(pixels, x + j, y + i, color);
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

void	pp_liner_renderer(SDL_Renderer *renderer, t_point *a, t_point *b, SDL_Color color)
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
		pp_putpixel_renderer(renderer, tab[0], tab[2], color);
		tab[9] = tab[8];
		tab[8] -= (tab[9] > -tab[4]) ? tab[6] : 0;
		tab[0] += (tab[9] > -tab[4]) ? tab[5] : 0;
		tab[8] += (tab[9] < tab[6]) ? tab[4] : 0;
		tab[2] += (tab[9] < tab[6]) ? tab[7] : 0;
	}
}

int pp_rect(SDL_Renderer *renderer, t_rect rect, SDL_Color color)
{
	int i;
	int j;

	i = 0;
	while (i < rect.h)
	{
		j = 0;
		while (j < rect.w)
		{
			pp_putpixel_renderer(renderer, rect.x + j, rect.y + i, color);
			j++;
		}
		i++;
	}
	return (0);
}

int pp_drawsquare(SDL_Renderer *renderer, int x, int y, int size, SDL_Color color)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			pp_putpixel_renderer(renderer, x + j, y + i, color);
			j++;
		}
		i++;
	}
	return (0);
}

void	pp_bucket_tool(uint32_t *pixels, int x, int y, uint32_t color)
{
	pixels[y * WIDTH + x] = color;
	if (pixels[y * WIDTH + x + 1] <= WIDTH)
		if (pixels[y * WIDTH + x + 1] != color)
			pp_bucket_tool(pixels, x + 1, y, color);
	if (pixels[y * WIDTH + x - 1] >= 0)
		if (pixels[y * WIDTH + x - 1] != color)
			pp_bucket_tool(pixels, x - 1, y, color);
	if (pixels[(y + 1) * WIDTH + x] <= HEIGHT)
		if (pixels[(y + 1) * WIDTH + x] != color)
			pp_bucket_tool(pixels, x, y + 1, color);
	if (pixels[(y - 1) * WIDTH + x] >= 0)
		if (pixels[(y - 1) * WIDTH + x] != color)
			pp_bucket_tool(pixels, x, y - 1, color);
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("usage: ./exec texture.png\n");
		return (0);
	}
	SDL_Event e;
	int quit = 0;
	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;
	int statut = EXIT_FAILURE;
	SDL_Color orange = {18, 18, 18, 255};
	SDL_Color green = {0, 255, 0, 255};
	SDL_Color red = {255, 0, 0, 255};
	SDL_Texture *texture;
	SDL_Surface *image = SDL_LoadBMP(argv[1]);
	SDL_Texture *texture2;


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

	SDL_SetRenderDrawColor(renderer, orange.r, orange.g, orange.b, orange.a);
	SDL_RenderClear(renderer);

	uint32_t *screen;
	screen = malloc(sizeof(uint32_t) * HEIGHT * WIDTH );
	//memset(screen, 255, WIDTH * HEIGHT * (sizeof(uint32_t)));
	texture2 = SDL_CreateTextureFromSurface(renderer, image);

	t_point a;
	t_point b;
	a.x = 20;
	a.y = 30;
	b.y = HEIGHT - 40;
	b.x = WIDTH - 50;

	t_rect rect;
	rect.x = 200;
	rect.y = 200;
	rect.h = 50;
	rect.w = 100;

	pp_rect(renderer, rect, green);
	pp_liner_renderer(renderer, &a, &b, green);
	pp_drawsquare(renderer, 50, 50, 75, red);
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_NONE);
	SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
	//SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_NONE);

	memset(screen, 0x00000000, WIDTH * HEIGHT * sizeof(uint32_t));
	pp_liner(screen, &a, &b, green);
	int draw = 0;
	while(!quit)
	{
		SDL_UpdateTexture(texture, NULL, screen, WIDTH * sizeof(uint32_t));
		a.x = e.button.x;
		a.y = e.button.y;
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
				{
					printf("%d %d \n", e.button.x, e.button.y);
					draw = 1;
				}
				if (e.button.button == SDL_BUTTON_RIGHT)
					pp_bucket_tool(screen, e.button.x, e.button.y, pp_get_SDLcolor(green));
			}
			if (e.type == SDL_MOUSEBUTTONUP)
				if (e.button.button == SDL_BUTTON_LEFT)
					draw = 0;
		}
		b.x = e.button.x;
		b.y = e.button.y;
		if (draw)
			brush_square(screen, e.button.x, e.button.y, 10, green);
		if (draw)
			pp_liner(screen, &a, &b, green);
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, texture2, NULL, NULL);
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
