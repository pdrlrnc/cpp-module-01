NAME        = sed_but_better
SRC         = main.cpp
OBJ_DIR	    = obj/
OBJ         = $(patsubst %.cpp, $(OBJ_DIR)%.o, $(SRC))

COMPILER    = c++
CFLAGS      = -Wall -Wextra -Werror -g -std=c++98
RM          = rm -rf

GRAY        = \033[38;5;244m
CURSIVE	   := \033[33;3m
INDIGO     := \033[38;5;057m
RED	   := \033[0;31m
DEF_COLOUR  = \033[0m

all: $(NAME)
	@echo "$(GRAY)                    ^...^$(DEF_COLOUR)"
	@echo "$(GRAY)                   <_* *_>$(DEF_COLOUR)"
	@echo "$(GRAY)                     \_/  $(DEF_COLOUR)"
	@echo "$(CURSIVE)$(INDIGO)c++: shooting urself in the foot was never this fun! $(DEF_COLOUR)"

$(NAME): $(OBJ)
	@echo "Linking executable..."
	@$(COMPILER) $(OBJ) -o $@
	@echo "$(NAME) built!"
	@ctags -R .

$(OBJ_DIR)%.o: %.cpp | $(OBJ_DIR)
	@echo "Compiling $@..."
	@$(COMPILER) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
clean:
	@echo "Removing object files..."
	@$(RM) $(OBJ_DIR)
	@$(RM) *.replace

fclean: clean
	@echo "Removing executable..."
	@$(RM) $(NAME)
	@$(RM) tags
	@$(RM) test*
	@$(RM) diffs

tests:
	@make --no-print-directory re
	@echo "aaaaa" > test1
	@echo -e "a\n\nb\n\nab\n\ncab\n\n" > test2
	@printf "" > test3
	@./$(NAME) test1 a b
	@./$(NAME) test2 a z
	@./$(NAME) test3 a b
	@sed 's/a/b/g' test1 > test1.sed
	@sed 's/a/z/g' test2 > test2.sed
	@sed 's/a/b/g' test3 > test3.sed
	@diff test1.replace test1.sed >> diffs || true
	@diff test2.replace test2.sed >> diffs || true
	@diff test3.replace test3.sed >> diffs || true
	@if [ ! -s diffs ]; then \
		echo "$(INDIGO)No diffs$(DEF_COLOUR)"; \
	else \
		echo "$(RED)ERROR$(DEF_COLOUR)"; \
	fi


re: fclean all

.PHONY: all clean fclean re tests
