# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/20 10:50:03 by kyoulee           #+#    #+#              #
#    Updated: 2022/11/15 14:13:16 by kyoulee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET = minishell

CC = cc
CXXFLAGS = $(NULL)
CFLAGS = -Wall -Werror -Wextra
DFLAGS = $(NULL)
IFLAGS =	-I $(INCLUDE_BUILTIN_DIR) \
			-I $(INCLUDE_DIR)

LDLIBS =	-lreadline

#####***** COLOR *****#####
BG_RED     = \033[41m
BG_GREEN   = \033[42m
BG_YELLOW  = \033[43m
BG_BLUE    = \033[44m
BG_MAGENTA = \033[45m
BG_CYAN    = \033[46m
BG_LGREY   = \033[47m
BG_DGREY   = \033[100m
BG_LRED    = \033[101m
BG_LGREEN  = \033[102m
BG_LYELLOW = \033[103m
BG_LBLUE   = \033[104m
BG_LMAGENTA= \033[105m
BG_LCYAN   = \033[106m
BG_WHITE   = \033[107m
BG_MAKE1   = \033[48;5;236m
BG_MAKE2   = \033[48;5;238m
BG_MAKE3   = \033[48;5;240m

FG_BLACK   = \033[30m
FG_RED     = \033[31m
FG_GREEN   = \033[32m
FG_YELLOW  = \033[33m
FG_BLUE    = \033[34m
FG_MAGENTA = \033[35m
FG_CYAN    = \033[36m
FG_LGREY   = \033[37m
FG_DGREY   = \033[90m
FG_LRED    = \033[91m
FG_LGREEN  = \033[92m
FG_LYELLOW = \033[93m
FG_LBLUE   = \033[94m
FG_LMAGENTA= \033[95m
FG_LCYAN   = \033[96m
FG_WHITE   = \033[97m
 
CL_BOLD   = \033[1m
CL_DIM    = \033[2m
CL_UDLINE = \033[4m
CL_BLINK  = \033[5m
CL_INVERT = \033[7m
CL_HIDDEN = \033[8m
 
NO_COLOR = \033[0m

#####***** DIR *****#####

ROOTDIR = $(abspath $(dir $(word $(words $(MAKEFILE_LIST)),$(MAKEFILE_LIST))))
SRC_DIR = $(ROOTDIR)/src
SRC_BUILTIN_DIR = $(ROOTDIR)/src_builtin
SRC_CMD_DIR = $(ROOTDIR)/src_cmd
SRC_DIR_DIR = $(ROOTDIR)/src_dir
SRC_ENV_TOOL_DIR = $(ROOTDIR)/src_env_tool
SRC_ERROR_DIR = $(ROOTDIR)/src_error
SRC_EXE_DIR = $(ROOTDIR)/src_exe
SRC_EXPORT_TOOL_DIR = $(ROOTDIR)/src_export_tool
SRC_FILE_DIR = $(ROOTDIR)/src_file
SRC_GLOBAL_DIR = $(ROOTDIR)/src_global
SRC_RUNNING_DIR = $(ROOTDIR)/src_running
SRC_TERMINAL_DIR = $(ROOTDIR)/src_terminal
SRC_TOOL_DIR = $(ROOTDIR)/src_tool
SRC_TRANSRATE_DIR = $(ROOTDIR)/src_transrate

OBJ_DIR = $(ROOTDIR)/obj
INCLUDE_DIR = $(ROOTDIR)/include
INCLUDE_BUILTIN_DIR = $(ROOTDIR)/include/builtin

#####***** SRC *****#####
SRC_FILE =	main.c

SRC_C = $(addprefix $(SRC_DIR)/, $(SRC_FILE))

SRC_BUILTIN_FILE =	ft_cd.c		\
					ft_echo.c	\
					ft_env.c	\
					ft_exit.c	\
					ft_export.c	\
					ft_pwd.c	\
					ft_unset.c

SRC_BUILTIN_C = $(addprefix $(SRC_BUILTIN_DIR)/, $(SRC_BUILTIN_FILE))

SRC_CMD_FILE =		ft_cmd.c		\
					ft_cmd_argv.c	\
					ft_redirect.c

SRC_CMD_C = $(addprefix $(SRC_CMD_DIR)/, $(SRC_CMD_FILE))

SRC_DIR_FILE =	ft_dir_in_file.c

SRC_DIR_C = $(addprefix $(SRC_DIR_DIR)/, $(SRC_DIR_FILE))

SRC_ENV_TOOL_FILE =		ft_putenv.c		\
						ft_setenv.c		\
						ft_unsetenv.c

SRC_ENV_TOOL_C = $(addprefix $(SRC_ENV_TOOL_DIR)/, $(SRC_ENV_TOOL_FILE))

SRC_ERROR_FILE =	ft_syntax_error.c

SRC_ERROR_C = $(addprefix $(SRC_ERROR_DIR)/, $(SRC_ERROR_FILE))

SRC_EXE_FILE =	ft_exe.c	\
				ft_execute.c

SRC_EXE_C = $(addprefix $(SRC_EXE_DIR)/, $(SRC_EXE_FILE))

SRC_EXPORT_TOOL_FILE =	ft_envp.c	\
						ft_export_args.c	\
						ft_export_find.c	\
						ft_export_init.c	\
						ft_export_set.c		\
						ft_export_unset.c

SRC_EXPORT_TOOL_C = $(addprefix $(SRC_EXPORT_TOOL_DIR)/, $(SRC_EXPORT_TOOL_FILE))

SRC_FILE_FILE =	ft_get_file.c

SRC_FILE_C = $(addprefix $(SRC_FILE_DIR)/, $(SRC_FILE_FILE))

SRC_GLOBAL_FILE =	ft_global.c

SRC_GLOBAL_C = $(addprefix $(SRC_GLOBAL_DIR)/, $(SRC_GLOBAL_FILE))

SRC_RUNNING_FILE =	ft_running.c

SRC_RUNNING_C = $(addprefix $(SRC_RUNNING_DIR)/, $(SRC_RUNNING_FILE))

SRC_TERMINAL_FILE =	ft_tty.c	\
					ft_tty_loop.c

SRC_TERMINAL_C = $(addprefix $(SRC_TERMINAL_DIR)/, $(SRC_TERMINAL_FILE))

SRC_TOOL_FILE =		ft_atoi.c		\
					ft_bzero.c		\
					ft_file_name.c	\
					ft_isalpha.c	\
					ft_isdigit.c	\
					ft_isenv.c		\
					ft_itoa.c		\
					ft_memcpy.c		\
					ft_strcat.c		\
					ft_strchr.c		\
					ft_strcmp.c		\
					ft_strcpy.c		\
					ft_strdup.c		\
					ft_strjoin.c	\
					ft_strlcpy.c	\
					ft_strlen.c		\
					ft_strncat.c	\
					ft_strncmp.c	\
					ft_strncpy.c	\
					ft_strword.c	\
					ft_void_len.c

SRC_TOOL_C = $(addprefix $(SRC_TOOL_DIR)/, $(SRC_TOOL_FILE))

SRC_TRANSRATE_FILE =		ft_transrate_env.c

SRC_TRANSRATE_C = $(addprefix $(SRC_TRANSRATE_DIR)/, $(SRC_TRANSRATE_FILE))

OBJS =	$(SRC_C:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)				\
		$(SRC_BUILTIN_C:$(SRC_BUILTIN_DIR)/%.c=$(OBJ_DIR)/%.o)		\
		$(SRC_CMD_C:$(SRC_CMD_DIR)/%.c=$(OBJ_DIR)/%.o)			\
		$(SRC_DIR_C:$(SRC_DIR_DIR)/%.c=$(OBJ_DIR)/%.o)			\
		$(SRC_ENV_TOOL_C:$(SRC_ENV_TOOL_DIR)/%.c=$(OBJ_DIR)/%.o)		\
		$(SRC_ERROR_C:$(SRC_ERROR_DIR)/%.c=$(OBJ_DIR)/%.o)		\
		$(SRC_EXE_C:$(SRC_EXE_DIR)/%.c=$(OBJ_DIR)/%.o)			\
		$(SRC_EXPORT_TOOL_C:$(SRC_EXPORT_TOOL_DIR)/%.c=$(OBJ_DIR)/%.o)	\
		$(SRC_FILE_C:$(SRC_FILE_DIR)/%.c=$(OBJ_DIR)/%.o)			\
		$(SRC_GLOBAL_C:$(SRC_GLOBAL_DIR)/%.c=$(OBJ_DIR)/%.o)		\
		$(SRC_RUNNING_C:$(SRC_RUNNING_DIR)/%.c=$(OBJ_DIR)/%.o)		\
		$(SRC_TERMINAL_C:$(SRC_TERMINAL_DIR)/%.c=$(OBJ_DIR)/%.o)		\
		$(SRC_TOOL_C:$(SRC_TOOL_DIR)/%.c=$(OBJ_DIR)/%.o)			\
		$(SRC_TRANSRATE_C:$(SRC_TRANSRATE_DIR)/%.c=$(OBJ_DIR)/%.o)	\
		

OBJS_CLEAN = $(OBJS)

#####***** working *****#####

all : $(OBJ_DIR) $(TARGET)

bonus : $(OBJ_DIR) $(TARGET)

$(TARGET) : $(OBJS) $(LIBFT) $(MINILIBX_SELECT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(IFLAGS) $(LDLIBS) $(OBJS) -o $(TARGET)
	@echo "$(FG_LMAGENTA)$(CC) $(FG_BLUE) $(CFLAGS)"
	@(for i in $(IFLAGS); do echo $$i; done)
	@echo "$(LDLIBS) $(FG_LCYAN)"
	@(for i in $(OBJS); do echo $$i; done)
	@echo "$(FG_BLUE)-o $(FG_LYELLOW)$(TARGET)$(NO_COLOR)"

$(OBJ_DIR) : 
	mkdir $@

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o : $(SRC_BUILTIN_DIR)/%.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o : $(SRC_CMD_DIR)/%.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o : $(SRC_DIR_DIR)/%.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o : $(SRC_ENV_TOOL_DIR)/%.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o : $(SRC_ERROR_DIR)/%.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o : $(SRC_EXE_DIR)/%.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o : $(SRC_EXPORT_TOOL_DIR)/%.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o : $(SRC_FILE_DIR)/%.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o : $(SRC_FILE_DIR)/%.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o : $(SRC_GLOBAL_DIR)/%.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o : $(SRC_RUNNING_DIR)/%.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o : $(SRC_TERMINAL_DIR)/%.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o : $(SRC_TOOL_DIR)/%.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o : $(SRC_TRANSRATE_DIR)/%.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

#####***** clean *****#####
clean : 
	rm -f $(OBJS_CLEAN)

fclean : OBJS_CLEAN+=$(TARGET)
fclean : clean

re : fclean all

.PHONY: all bonus re clean fclean
