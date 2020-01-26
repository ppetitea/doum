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
				utils/error/debug_mode.c									\
				utils/error/throw_null.c									\
				utils/error/throw_void.c									\
				utils/error/throw_error.c									\
				utils/error/throw_warning.c									\
				utils/matrix/mult.c											\
				utils/matrix/rotate.c										\
				utils/matrix/scale.c										\
				utils/matrix/to_vtx.c										\
				utils/matrix/translate.c									\
				utils/time/get_delta.c										\
				utils/parser/check/close_curly_braces.c						\
				utils/parser/check/curly_braces.c							\
				utils/parser/check/open_curly_braces.c						\
				utils/parser/check/utility.c								\
				utils/parser/debug/debug.c									\
				utils/parser/get_data_in_string/get_index.c					\
				utils/parser/get_data_in_string/get_key.c					\
				utils/parser/get_data_in_string/get_value_type.c			\
				utils/parser/get_data_in_string/get_value.c					\
				utils/parser/object/getter/get_child_object.c				\
				utils/parser/object/getter/get_float_value.c				\
				utils/parser/object/getter/get_int_value.c					\
				utils/parser/object/getter/get_string_value.c				\
				utils/parser/object/getter/init_with_obj.c					\
				utils/parser/object/getter/strcmp_obj.c						\
				utils/parser/object/create.c								\
				utils/parser/object/free.c									\
				utils/parser/read_file/get_file_datas.c						\
				utils/parser/split_data/free_string_array.c					\
				utils/parser/split_data/new_string_array.c					\
				utils/parser/split_data/split_data.c						\
				utils/parser/parser.c										\
				utils/parser/to_object.c									\
																			\
				engine/game/game_init.c										\
																			\
				engine/interface/sdl/init_sdl.c								\
				engine/interface/sdl/destroy.c								\
				engine/interface/screen/init_screen.c						\
				engine/interface/screen/reset.c								\
																			\
				engine/build.c												\
																			\
				engine/resources/images/add_bmp.c							\
				engine/resources/images/collide_texture.c					\
				engine/resources/images/fill_texture.c						\
				engine/resources/images/filter_texture.c					\
				engine/resources/images/get_bmp.c							\
				engine/resources/images/init_texture.c						\
				engine/resources/images/load_bmp.c							\
				engine/resources/images/render_texture.c					\
				engine/resources/images/render.c							\
				engine/resources/images/set_pixel_texture.c					\
				engine/resources/images/texture_build.c						\
				engine/resources/images/texture_list_build.c				\
				engine/resources/images/texture_oriented_build.c			\
																			\
				engine/entities/entities_build.c							\
				engine/entities/entities_dup.c								\
				engine/entities/entities_overwrite.c						\
				engine/entities/entity/entity_animate.c						\
				engine/entities/entity/entity_build.c						\
				engine/entities/entity/entity_dup.c							\
				engine/entities/entity/entity_get.c							\
				engine/entities/entity/entity_init.c						\
				engine/entities/entity/entity_overwrite.c					\
				engine/entities/entity/entity_status_build.c				\
				engine/entities/entity/entity_texture_build.c				\
				engine/entities/character/character_actions.c				\
				engine/entities/character/character_build.c					\
				engine/entities/character/character_die_build.c				\
				engine/entities/character/character_dup.c					\
				engine/entities/character/character_init.c					\
				engine/entities/character/character_orientation.c			\
				engine/entities/character/character_overwrite.c				\
				engine/entities/character/character_texture_build.c			\
				engine/entities/character/character_type_build.c			\
				engine/entities/character/weapon/character_weapons_build.c	\
				engine/entities/character/weapon/weapon_build.c				\
				engine/entities/character/weapon/weapon_dup.c				\
				engine/entities/character/weapon/weapon_get.c				\
				engine/entities/character/weapon/weapon_init.c				\
				engine/entities/character/weapon/weapon_overwrite.c			\
				engine/entities/character/weapon/weapon_texture_build.c		\
				engine/entities/character/weapon/weapon_type_build.c		\
				engine/entities/character/weapon/weapon_update.c			\
				engine/entities/character/camera/camera_build.c				\
				engine/entities/character/camera/camera_init.c				\
				engine/entities/character/camera/camera_overwrite.c			\
																			\
				engine/maps/map_build.c										\
				engine/maps/map_init.c										\
				engine/maps/map_render2d.c									\
																			\
																			\
				#															\
				engine/scenes/init_scene.c									\
				engine/scenes/update_scene.c								\
																			\
																			\
																			\
				engine/entities/build_entities.c							\
				engine/entities/get_entity.c								\
				engine/entities/init_entity_with_obj.c						\
				engine/entities/init_entity.c								\
				engine/entities/sort_rules.c								\
				engine/entities/update_entity.c								\
				engine/entities/update/animate.c							\
				engine/entities/update/display.c							\
				engine/entities/update/drag.c								\
				engine/entities/update/hover.c								\
				engine/entities/update/select.c								\
																			\
				engine/entities/ui/button/build_button.c					\
				engine/entities/ui/button/init_button_entity.c				\
				engine/entities/ui/button/init_button.c						\
				engine/entities/ui/button/update_button.c					\
																			\
				engine/entities/ui/checkbox/init_checkbox_entity.c			\
				engine/entities/ui/checkbox/init_checkbox.c					\
				engine/entities/ui/checkbox/update_checkbox.c				\
																			\
				engine/entities/ui/image/build_image.c						\
				engine/entities/ui/image/init_image_entity.c				\
				engine/entities/ui/image/init_image.c						\
				engine/entities/ui/image/update_image.c						\
																			\
				engine/entities/ui/spawner/init_spawner_entity.c			\
				engine/entities/ui/spawner/init_spawner.c					\
				engine/entities/ui/spawner/update_spawner.c					\
																			\
																			\
				engine/entities/player/build_player.c						\
				engine/entities/player/init_player_entity.c					\
				engine/entities/player/init_player.c						\
				engine/entities/player/update_player.c						\
				engine/entities/player/build_camera.c						\
				engine/entities/player/init_camera.c						\
				engine/entities/player/update_camera.c						\
				engine/entities/player/build_weapon.c						\
				engine/entities/player/init_weapon.c						\
				engine/entities/player/update_weapon.c						\
																			\
				engine/entities/ennemy/build_ennemy.c						\
				engine/entities/ennemy/init_ennemy_entity.c					\
				engine/entities/ennemy/init_ennemy.c						\
				engine/entities/ennemy/update_ennemy.c						\
																			\
				engine/loop.c												\
				engine/render.c												\
																			\
				engine/interface/events/keyboard/handle.c					\
				engine/interface/events/mouse/handle.c						\
				engine/interface/events/handle.c							\
																			\
				scenes/build.c												\
				scenes/build_menu.c											\
				scenes/build_game.c											\
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
CFLAGS		:=	-Wall -Werror -Wextra -O3 -Ofast -flto -g
LDFLAGS		:=	-Wall -Werror -Wextra  -O3 -Ofast -flto -g -lm 

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
