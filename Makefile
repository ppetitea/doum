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
				events/handle.c												\
				events/keyboard/handle.c									\
				events/mouse/handle.c										\
																			\
				game/init.c													\
				game/loop.c													\
				game/render.c												\
																			\
				screen/init.c												\
				screen/reset.c												\
																			\
				sdl/destroy.c												\
				sdl/init.c													\
																			\
				sprites/init/init.c											\
				sprites/sprites.c											\
																			\
				textures/bitmap/load_bmp.c									\
				textures/bitmap/render.c									\
				textures/list/get.c											\
				textures/list/init.c										\
				textures/collide.c											\
				textures/filter.c											\
				textures/render.c											\
				textures/texture.c											\
																			\
				user_interface/update/hover.c								\
				user_interface/update/select.c								\
				user_interface/update/drag.c								\
				user_interface/init.c										\
				user_interface/ui_button.c									\
				user_interface/ui_component.c								\
				user_interface/ui_spawner.c									\
																			\
				utils/color/add_blend.c										\
				utils/debug/debug.c											\
				utils/error/throw_null.c									\
				utils/error/throw_void.c									\
				utils/error/throw_error.c									\
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
LDFLAGS		:=	-Wall -Werror -Wextra

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
