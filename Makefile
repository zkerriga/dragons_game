# ******************************************************************************* #
#                                                                             	  #
#     Makefile                                                   ♥           	  #
#                                                                 ¨/\_/\ ♥    	  #
#     By: zkerriga                                                 >^,^<     	  #
#                                                                   / \     	  #
#     Created: 2020-08-02 10:26:09 by zkerriga                     (___)__  	  #
#     Updated: 2020-08-02 10:26:12 by zkerriga                              	  #
#                                                                             	  #
# ******************************************************************************* #

NAME = dragons_game

OBJ_DIR = bin
LIB_DIR = libs

CC = gcc

INCLUDES = -I./$(LIB_DIR)/libft/ -I./$(BATTLEFIELD_DIR) -I./$(UNIT_DIR) -I./$(DRAGON_DIR) -I./$(HERO_DIR)

FLAGS = $(INCLUDES) -Wall -Wextra -Werror -O2 -MMD

MAIN_DIR = .
MAIN_FILES = $(wildcard $(MAIN_DIR)/*.c)
MAIN_FILES_O = $(addprefix $(OBJ_DIR)/, $(MAIN_FILES:.c=.o))

CLASS_DIR = classes

BATTLEFIELD_DIR = $(CLASS_DIR)/Battlefield
BATTLEFIELD_FILES = $(wildcard $(BATTLEFIELD_DIR)/*.c)
BATTLEFIELD_FILES_O = $(addprefix $(OBJ_DIR)/, $(BATTLEFIELD_FILES:.c=.o))

UNIT_DIR = $(CLASS_DIR)/Unit
UNIT_FILES = $(wildcard $(UNIT_DIR)/*.c)
UNIT_FILES_O = $(addprefix $(OBJ_DIR)/, $(UNIT_FILES:.c=.o))

DRAGON_DIR = $(UNIT_DIR)/Dragon
DRAGON_FILES = $(wildcard $(DRAGON_DIR)/*.c $(DRAGON_DIR)/*/*.c)
DRAGON_FILES_O = $(addprefix $(OBJ_DIR)/, $(DRAGON_FILES:.c=.o))

HERO_DIR = $(UNIT_DIR)/Hero
HERO_FILES = $(wildcard $(HERO_DIR)/*.c $(HERO_DIR)/*/*.c)
HERO_FILES_O = $(addprefix $(OBJ_DIR)/, $(HERO_FILES:.c=.o))

.PHONY: all
all: $(OBJ_DIR) lft $(NAME)
	@echo -e "\n\e[32m[+] $(NAME) is assembled!\e[0m"

$(OBJ_DIR):
	mkdir $(OBJ_DIR)
	@mkdir -p $(addprefix $(OBJ_DIR)/, $(BATTLEFIELD_DIR) $(HERO_DIR) $(DRAGON_DIR))
	@mkdir $(addprefix $(OBJ_DIR)/, $(HERO_DIR)/Berserk $(HERO_DIR)/Warrior $(DRAGON_DIR)/FireDragon $(DRAGON_DIR)/IceDragon)

.PHONY: lft
lft:
	@$(MAKE) -C ./$(LIB_DIR)/libft --no-print-directory --silent
	@echo -e "\e[32m[+] Libft is assembled!\e[0m"

$(NAME): $(UNIT_FILES_O) $(HERO_FILES_O) $(DRAGON_FILES_O) $(BATTLEFIELD_FILES_O) $(MAIN_FILES_O)
	@echo -e "\e[34m[+] END\e[0m"
	@$(CC) $(FLAGS)	$(UNIT_FILES_O) $(HERO_FILES_O) $(DRAGON_FILES_O) $(BATTLEFIELD_FILES_O) \
					$(MAIN_FILES_O) -L./$(LIB_DIR)/libft -lft -o $(NAME)

ifndef ECHO
T := $(shell $(MAKE) $(MAKECMDGOALS) --no-print-directory \
	-nrRf $(firstword $(MAKEFILE_LIST)) \
	ECHO="COUNTTHIS" | grep -c "COUNTTHIS")
N := x
C = $(words $N)$(eval N := x $N)
ifneq ($(T), 0)
	ECHO = echo -ne "\e[36m\r[`expr $C '*' 100 / $T`%]"
endif # ifneq #
ifeq ($(T), 0)
	ECHO = echo -ne "\e[36m\r[`expr $C '*' 100 / 22`%]"
endif # ifeq #
endif # ECHO #

$(UNIT_FILES_O): $(OBJ_DIR)/%.o: %.c
	@$(ECHO) "UNIT"
	@echo
	@$(CC) $(FLAGS) -c $< -o $@
include $(wildcard $(OBJ_DIR)/$(UNIT_DIR)/*.d)

$(HERO_FILES_O): $(OBJ_DIR)/%.o: %.c
	@$(ECHO) "HERO"
	@echo
	@$(CC) $(FLAGS) -c $< -o $@
include $(wildcard $(OBJ_DIR)/$(HERO_DIR)/*.d $(OBJ_DIR)/$(HERO_DIR)/*/*.d)

$(DRAGON_FILES_O): $(OBJ_DIR)/%.o: %.c
	@$(ECHO) "DRAGON"
	@echo
	@$(CC) $(FLAGS) -c $< -o $@
include $(wildcard $(OBJ_DIR)/$(DRAGON_DIR)/*.d $(OBJ_DIR)/$(DRAGON_DIR)/*/*.d)

$(BATTLEFIELD_FILES_O): $(OBJ_DIR)/%.o: %.c
	@$(ECHO) "BATTLEFIELD"
	@echo
	@$(CC) $(FLAGS) -c $< -o $@
include $(wildcard $(OBJ_DIR)/$(BATTLEFIELD_DIR)/*.d)

$(MAIN_FILES_O): $(OBJ_DIR)/%.o: %.c
	@$(ECHO) "MAIN"
	@echo
	@$(CC) $(FLAGS) -c $< -o $@
include $(wildcard $(OBJ_DIR)/$(MAIN_DIR)/*.d)

.PHONY: clean
clean:
	$(RM) -r $(OBJ_DIR)

.PHONY: fclean
fclean: clean
	$(RM) $(NAME)

.PHONY: re
re: fclean lib_fclean all

.PHONY: lib_fclean
lib_fclean:
	@$(MAKE) -C ./$(LIB_DIR)/libft --no-print-directory fclean
