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
				entities/ennemies/ennemy.c									\
				entities/ennemies/update.c									\
				entities/player/build_camera.c								\
				entities/player/build_player.c								\
				entities/player/build_weapon.c								\
				entities/player/update_camera.c								\
				entities/player/update_player.c								\
				entities/player/update_weapon.c								\
				entities/sprites/sprites.c									\
				entities/sprites/update.c									\
				entities/update/animate.c									\
				entities/update/display.c									\
				entities/update/drag.c										\
				entities/update/hover.c										\
				entities/update/select.c									\
				entities/user_interface/button/button.c						\
				entities/user_interface/button/update.c						\
				entities/user_interface/spawner/spawner.c					\
				entities/user_interface/spawner/update.c					\
				entities/entity.c											\
																			\
				events/handle.c												\
				events/keyboard/handle.c									\
				events/mouse/handle.c										\
																			\
				game/initialization/entities/buttons.c						\
				game/initialization/entities/ennemy.c						\
				game/initialization/entities/init.c							\
				game/initialization/entities/player.c						\
				game/initialization/entities/spawners.c						\
				game/initialization/entities/sprites.c						\
				game/initialization/interface/screen/init.c					\
				game/initialization/interface/screen/reset.c				\
				game/initialization/interface/sdl/init.c					\
				game/initialization/interface/sdl/destroy.c					\
				game/initialization/resources/buttons.c						\
				game/initialization/resources/ennemy.c						\
				game/initialization/resources/init.c						\
				game/initialization/resources/pistol.c						\
				game/initialization/resources/shootgun.c					\
				game/init.c													\
				game/loop.c													\
				game/render.c												\
																			\
																			\
				resources/textures/bitmap/load_bmp.c						\
				resources/textures/bitmap/render.c							\
				resources/textures/collide.c								\
				resources/textures/filter.c									\
				resources/textures/get.c									\
				resources/textures/render.c									\
				resources/textures/texture.c								\
																			\
				utils/color/add_blend.c										\
				utils/debug/debug.c											\
				utils/error/throw_null.c									\
				utils/error/throw_void.c									\
				utils/error/throw_error.c									\
				utils/matrix/mult.c											\
				utils/matrix/rotate.c										\
				utils/matrix/scale.c										\
				utils/matrix/to_vtx.c										\
				utils/matrix/translate.c									\
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
