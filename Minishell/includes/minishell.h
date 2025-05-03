/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tborges- <tborges-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 23:53:27 by tborges-          #+#    #+#             */
/*   Updated: 2025/04/25 22:53:08 by tborges-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <dirent.h>
# include <errno.h> //for errno
# include <fcntl.h>
# include <limits.h>           //for PATH_MAX
# include <readline/history.h> //readline
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h> //exit malloc
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h> //getcwd, chdir

# define PRIVATE_PATH \
	"/usr/local/sbin:/usr/local/bin:/usr/sbin\
:/usr/bin:/sbin:/bin"

typedef enum s_type
{
	PIPE,
	REDIR,
	WORD,
	QUOTE,
	DOLLAR,
	APPEND,
	INFILE,
	OUTFILE,
	HERE_DOC,
	COMMAND,
	COMMAND_ARGS,
}					t_type;

typedef struct s_token
{
	t_type			type;
	char			*str;
	struct s_token	*prev;
	struct s_token	*next;
}					t_token;

typedef struct s_redir
{
	t_type			type;
	t_type			expansion_rule;
	char			*str;
}					t_redir;

typedef struct s_cmd
{
	t_redir			**heredocs;

	int				input_fd;
	int				output_fd;
	int				pipe_fds[2];
	t_redir			**redirections;
	int				output_error;
	int				process_id;
	char			**arg;
	int				arg_count;
}					t_cmd;

typedef struct s_shell
{
	char			*readline;

	t_token			*tokens;
	t_cmd			**cmd;

	t_list			*env;
	t_list			*exp;

	int				last_exit_code;

	int				heredoc_pipe[2];

	char			*default_path;
}					t_shell;

/* ----------------- CORE FUNCTIONS (src/) ----------------- */
t_shell				*get_shell(void);
void				check_main_args(int ac);

/* ----------------- SIGNALS (src/signals/) ----------------- */
void				interactive_mode(void);
void				ignore_signal(int signal);
void				here_sigint(void);
void				exec_mode(void);

/* ----------------- EXECUTER UTILITY FUNCTIONS (src/executer/) ------------- */
void				free_arr(char **arr);
char				*trim_prefix(char *str, char *prefix);
int					is_longer(char *str1, char *str2);
int					arr_len(char **arr);
int					print_and_return(char *message, int exit_status);

int					has_equal(char *var);
char				*get_var_name(char *var);
void				free_lst(t_list *lst);
void				free_all(void);
int					arg_valid(char *arg);

t_list				*get_env(char **envp);

char				*put_double_quotes(char *str);
t_list				*get_exp(char **envp);

/* ----------------- BUILT-IN COMMANDS (src/executer/builtins/) ------------- */
/* src/executer/builtins/echo.c */
int					ms_echo(t_cmd *cmd);

/* src/executer/builtins/unset.c */
int					ms_unset(t_list **env, t_list **exp, t_cmd *cmd);

/* src/executer/builtins/cd.c */
int					ms_cd(t_shell *shell, t_list **env, t_cmd *cmd);

/* src/executer/builtins/pwd.c */
int					ms_pwd(void);

/* src/executer/builtins/export.c */
int					ms_export(t_list **env, t_list **exp, t_cmd *cmd);

/* src/executer/builtins/exit.c */
int					ms_exit(t_shell **shell, t_cmd *cmd);

/* src/executer/builtins/builtins.c */
void				build_ins(t_cmd *cmd);

/* ----------------- FILE REDIRECTIONS (src/executer/redirections/) ------ */
/* src/executer/redirections/error_handling.c */
int					infile_error(t_cmd *cmd);
int					error_open_outfile(int fd_outfile, char *name_outfile,
						t_cmd *cmd);

/* src/executer/redirections/env.c */
char				**make_env_arr(t_list *env);
int					is_build_in(t_cmd *cmd);

/* src/executer/redirections/heredoc.c */
void				manage_hd(t_shell *shell);

/* src/executer/redirections/infile.c */
int					last_is_infile(t_cmd *cmd);
int					get_fd_infile(char *infile);

/* src/executer/redirections/redirections.c */
void				manage_redir(t_shell **shell);

/* ----------------- COMMAND EXECUTION (src/executer/) ----------------- */
/* src/executer/executer.c */
void				executer(t_shell *shell);

/* src/executer/path.c */
char				*create_path(char *function, char **envp);

/* src/executer/fd_handling.c */
void				close_all_fd_red(void);

/* src/executer/cmd_processing.c */
void				handle_cmd_input(t_shell *shell, int i, int prev_pipe0);
void				handle_cmd_output_and_execute(t_shell *shell, int i,
						int prev_pipe0);

/* src/executer/signals.c */
void				exec_mode(void);

/* ----------------- DEBUGGING (src/parsing/debug/) ----------------- */
/* src/parsing/debug/debug.c */
void				print_tokens(void);
void				print_cmd_array(void);

/* ----------------- COMMAND ARRAY BUILDING (src/parsing/cmd_array_build/) -- */
/* src/parsing/cmd_array_build/args.c */
int					is_arg(t_token *token);
void				assign_args(t_token *tokens, char ***args);
void				get_args(t_token *token, t_cmd *cmd);

/* src/parsing/cmd_array_build/redirections.c */
void				assign_redirs(t_token *token, t_redir ***redir);
t_redir				**get_red(t_token *token);

/* src/parsing/cmd_array_build/cmd.c */
t_cmd				*get_next_cmd(t_token *token);
void				get_next_cmd_token(t_token **token);
int					count_cmds(t_token *tokens);
int					init_cmd(void);

/* ----------------- EXPANSION (src/parsing/expander/) ----------------- */
size_t				safe_strlen(const char *s);
char				*ms_strjoin(char const *s1, char const *s2);
void				restore_empty_str(void);
void				clear_empty_token(void);
void				update_str(char **update, char *src, int start, int len);
void				expand_quote(int *i, char **update, char *src,
						char quote_char);
void				expand_node(t_token **tmp, char *update);
void				expander(void);
char				*get_value(char *name);
void				exit_status_expander(char **update);
void				expand_standard_dollar_format(int **pointer_add, char *src,
						char **update);
void				process_dollar(int *len, char *src, char **update);

/* ----------------- MEMORY MANAGEMENT (src/parsing/frees/) ----------------- */
void				free_tokens(void);
void				free_atributes(void);
void				free_cmd_redir(t_cmd **cmd);
void				free_cmds(void);

/* ----------------- LEXER (src/parsing/lexer/) ----------------- */
int					quotes_check(void);
int					lexer(void);
void				white_space_skip(int *i);
int					quote_skip(int *i);
void				word_skip(int *i);
void				redir_skip(int *i);
void				add_token(int start, int len, t_type type);
t_token				*tokenlast(t_token *first);

/* ----------------- SYNTAX AND PARSING (src/parsing/) ----------------- */
int					syntax_check(void);
int					here_doc(char *del, t_type expansion_rule);
void				here_expander(char **line);

#endif
