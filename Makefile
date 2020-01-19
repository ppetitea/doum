#****************	RAPPEL	****************
#	commentaire mono-ligne

#	commentaire\
	multi-ligne

#	NAME = VALUE -> permet de definir une constante
#	NAME := VALUE -> permet de definir une variable

#	cible:dependance
#		commande

#	$@	Le nom de la cible
#	$<	Le nom de la première dépendance
#	$^	La liste des dépendances
#	$?	La liste des dépendances plus récentes que la cible
#	$*	Le nom du fichier sans suffixe
#	.PHONY -> cible dont les dependances sont systematiquement reconstruites

#	$(addprefix prefix, name) -> permet d'ajouter un prefix



#****************	VARIABLES	****************
UNAME		=	$(shell uname)
EXEC		=	doom-nukem

#SOURCES
SRCS_LIST	=	main.c														\
																			\
				utils/color/add_blend.c										\
				utils/error/throw_null.c									\
				utils/error/throw_void.c									\
				utils/error/throw_error.c									\
				utils/matrix/mult.c											\
				utils/matrix/rotate.c										\
				utils/matrix/scale.c										\
				utils/matrix/to_vtx.c										\
				utils/matrix/translate.c									\
																			\
				engine/init_game.c											\
																			\
				engine/interface/sdl/init_sdl.c								\
				engine/interface/sdl/destroy.c								\
				engine/interface/screen/init_screen.c						\
				engine/interface/screen/reset.c								\
				engine/scenes/init_scene.c									\
																			\
				scenes/init.c												\
				scenes/game/init_game.c										\
				scenes/game/interface/init_game_interface.c					\
				scenes/game/resources/init_game_resources.c					\
				scenes/game/resources/textures/weapons/pistol.c				\
				scenes/game/resources/textures/weapons/shootgun.c			\
				scenes/game/resources/textures/ennemies/ennemy.c			\
				scenes/game/entities/init_game_entities.c					\
				scenes/game/entities/player.c								\
				scenes/game/entities/ennemy.c								\
																			\
				engine/resources/images/render.c							\
				engine/resources/images/add_bmp.c							\
				engine/resources/images/get_bmp.c							\
				engine/resources/images/load_bmp.c							\
																			\
				engine/resources/textures/add_texture.c						\
				engine/resources/textures/collide_texture.c					\
				engine/resources/textures/fill_texture.c					\
				engine/resources/textures/filter_texture.c					\
				engine/resources/textures/init_texture.c					\
				engine/resources/textures/render_texture.c					\
				engine/resources/textures/set_pixel_texture.c				\
																			\
				engine/entities/init_entity.c								\
				engine/entities/update_entity.c								\
				engine/entities/update/animate.c							\
				engine/entities/update/display.c							\
				engine/entities/update/drag.c								\
				engine/entities/update/hover.c								\
				engine/entities/update/select.c								\
																			\
				engine/entities/player/init_player_entity.c					\
				engine/entities/player/init_player.c						\
				engine/entities/player/update_player.c						\
				engine/entities/player/init_camera.c						\
				engine/entities/player/update_camera.c						\
				engine/entities/player/init_weapon.c						\
				engine/entities/player/update_weapon.c						\
																			\
				engine/entities/ennemy/init_ennemy_entity.c					\
				engine/entities/ennemy/init_ennemy.c						\
				engine/entities/ennemy/update_ennemy.c						\
																			\
																			\
																			\
				engine/loop.c												\
				engine/render.c												\
																			\
				engine/interface/events/keyboard/handle.c					\
				engine/interface/events/mouse/handle.c						\
				engine/interface/events/handle.c							\
																			\
																			\
																			#\
																			\
																			\
																			\
				engine/build_game.c											\
				engine/scenes/update_scene.c								\
																			\
																			\
																			\
																			\
																			\
				engine/entities/ui/button/build_button_entity.c				\
				engine/entities/ui/button/build_button.c					\
				engine/entities/ui/button/update_button.c					\
																			\
				engine/entities/ui/spawner/build_spawner_entity.c			\
				engine/entities/ui/spawner/build_spawner.c					\
				engine/entities/ui/spawner/update_spawner.c					\
																			\
																			\
																			\
																			\
																			\
				scenes/map_editor/init_map_editor.c							\
				scenes/map_editor/entities/init_map_editor_entities.c		\
				scenes/map_editor/entities/button_down.c					\
				scenes/map_editor/entities/button_up.c						\
				scenes/map_editor/entities/spawner_sprite.c					\
				scenes/map_editor/interface/init_map_editor_interface.c		\
				scenes/map_editor/resources/init_map_editor_resources.c		\
				scenes/map_editor/resources/button_down.c					\
				scenes/map_editor/resources/button_plus.c					\
				scenes/map_editor/resources/button_up.c						\
				scenes/map_editor/resources/button_x.c						\
																			\
				scenes/menu/init_menu.c										\
				scenes/menu/entities/init_menu_entities.c					\
				scenes/menu/entities/button_start.c							\
				scenes/menu/interface/init_menu_interface.c					\
				scenes/menu/resources/init_menu_resources.c					\
				scenes/menu/resources/button_down.c							\
																			\
				scenes/menu/init_scenes.c									\
				scenes/menu/init.c											\
																			\


SRCS_FOLDER	=	./srcs/
SRCS		=	$(addprefix $(SRCS_FOLDER), $(SRCS_LIST))

#OBJECTS
OBJS_LIST	=	$(SRCS_LIST:.c=.o)	#Pour chaque .c de SRC on construit dans OBJ un .o
OBJS_FOLDER	=	./objs/
OBJS		=	$(addprefix $(OBJS_FOLDER), $(OBJS_LIST))

#HEADERS
INCLUDES_FOLDER	=	./includes/
INCLUDES	:=	-I includes

#COMPILATION
CC			=	gcc
CFLAGS		:=	-Wall -Werror -Wextra
LDFLAGS		:=	-Wall -Werror -Wextra -lm

#LIBRARIES
#	libft
LIBFT_FOLDER=	./libft
LIBFT		=	$(LIBFT_FOLDER)/libft.a
INCLUDES	:=	$(INCLUDES) -I $(LIBFT_FOLDER)/includes
LDFLAGS		:=	$(LDFLAGS) -L $(LIBFT_FOLDER) -lft
#	SDL
SDL_FOLDER	=	./SDL
SDL			=	$(SDL_FOLDER)/build
INCLUDES	:=	$(INCLUDES) -I $(SDL_FOLDER)/include
LDFLAGS		:=	$(LDFLAGS) -L $(SDL_FOLDER) `sdl2-config --cflags --libs`



#****************	RULES	****************
all: $(SDL) $(LIBFT) $(EXEC)

$(EXEC): $(OBJS)
	@$(CC) $(OBJS) -o $(EXEC) $(LDFLAGS)

$(OBJS_FOLDER)%.o: $(SRCS_FOLDER)%.c
	@mkdir -p $(dir $@)
	@$(CC) -c $< -o $@ $(INCLUDES) $(CFLAGS)

$(LIBFT):
	@make -C libft

$(SDL):
	@printf "compiling SDL it may takes long time ~3mn <3\n";
	@cd $(SDL_FOLDER) &&\
	./configure > /dev/null &&\
	make > /dev/null;

cl:
	@rm -rf $(OBJS_FOLDER)

clean: libft-clean sdl-clean
	@rm -rf $(OBJS_FOLDER)

libft-clean:
	@make -C $(LIBFT_FOLDER) clean > /dev/null

sdl-clean:
	@cd $(SDL_FOLDER) &&\
	make clean > /dev/null;

fcl: cl
	@rm -rf $(EXEC)

fclean: clean libft-fclean sdl-fclean
	@rm -rf $(EXEC)

libft-fclean:
	@make -C $(LIBFT_FOLDER) fclean > /dev/null

sdl-fclean:
	@cd $(SDL_FOLDER);\
	make clean > /dev/null

r: cl all

re: fclean all

.PHONY: clean libft-clean sdl-clean fclean libft-fclean sdl-fclean re
