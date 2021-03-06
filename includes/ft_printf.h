/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvillat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:26:05 by guvillat          #+#    #+#             */
/*   Updated: 2019/01/23 15:26:06 by guvillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define PF t_printf
# define SPE t_spec
# define BUFF_MAX 128
# define BLK "\033[22;30m"
# define RGE "\033[22;31m"
# define GRN "\033[22;32m"
# define BWN "\033[22;33m"
# define BLU "\033[22;34m"
# define MGT "\033[22;35m"
# define CYA "\033[22;36m"
# define GRY "\033[22;37m"
# define DGRY "\033[01;30m"
# define LRED "\033[01;31m"
# define LGRN "\033[01;32m"
# define YEL "\033[01;33m"
# define LBLU "\033[01;34m"
# define LMGT "\033[01;35m"
# define LCYA "\033[01;36m"
# define RST "\033[01;37m"
# include "../libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <wchar.h>

char	g_buff[BUFF_MAX];
int		g_i;

/*
** fla[13] is an array which contains flags for precision, width, flags
** and modifiers such as:
** |0        |1    |2|3|4|5|6|7 |8|9 |10|11|12|
** |precision|width|#|0|-|+| |hh|h|ll|l |j |z |
** %[flags][width][.precision][length]specifier
** specifier : c s p d i o u x X f
** bonus : S D O U C b wildcards
** color : %s before the arg
*/

typedef struct s_printf	t_printf;
typedef struct s_spec	t_spec;

struct	s_printf
{
	char			*format;
	size_t			index;
	unsigned char	spec;
	int				flags[13];
	char			*arg;
	wchar_t			*warg;
	int				ret;
};

struct	s_spec
{
	int (*spe[128])(PF*, va_list);
};

int		ft_printf(const char *format, ...);

/*
** DISPLAY
*/

void	ft_display(PF *argument);
void	*ft_buff(char *str, PF *argument);
void	ft_buf(char c, PF *argument);
int		ft_print_character(PF *argument);
int		ft_print_str(PF *argument);
int		ft_print_number(PF *argument, char *pre);
int		ft_print_float(PF *argument, char *pre);

/*
** MEMORY
*/

void	ft_free(PF *argument);
void	ft_init_buff();
PF		*ft_init_argument(PF *argument);
void	ft_init_spe_tab(SPE *spe);

/*
** LIBPRINTF
*/

int		ft_wcharlen(wchar_t wchar);
size_t	ft_wbytelen(wchar_t *ws);
void	*ft_strlower(char *s);
char	*ft_itoa_base(uintmax_t nbr, int base);
int		ft_wchartostr(char *s, wchar_t wc);
void	ft_nputchar(char c, ssize_t n, PF *argument);
size_t	ft_wstrlen(wchar_t *s);
int		ft_wstrtostr(char *s, wchar_t *wstr, int n);
char	*ft_wstrsub(wchar_t *ws, unsigned int start, size_t len);
char	*ft_strsub_with_free(char const *s, unsigned int start, size_t len);
char	*ft_transform_wchar_in_char(wchar_t *ws);
int		ft_putwchar_in_char(wchar_t wchar, char *fresh, int i);

/*
** HANDLER
*/

int		signed_handler(PF *argument, va_list ap);
int		pointer_handler(PF *argument, va_list ap);
int		character_handler(PF *argument, va_list ap);
int		string_handler(PF *argument, va_list ap);
int		unsigned_handler(PF *argument, va_list ap);
int		ft_arg_nospe(PF *argument, va_list ap);
int		prc_handler(PF *argument, va_list ap);
int		float_handler(PF *argument, va_list ap);

/*
** FLAGS
*/

int		ft_wildcard(PF *argument, va_list ap, int index);
int		ft_get_flags(PF *argu, va_list ap);
int		ft_check_flags(PF *argu);
int		ft_check_width(PF *argu, va_list ap);
int		ft_check_precision(PF *argument, va_list ap);
void	ft_check_length(PF *argu);
int		ft_check_spec(PF *argument);
int		ft_check_spec_bis(PF *argument);

#endif
