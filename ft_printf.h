/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-mar <kait-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 11:45:08 by kait-mar          #+#    #+#             */
/*   Updated: 2020/01/08 12:57:26 by kait-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
#include "string.h"
//# include "libft.h"

typedef struct	s_list{
	int				integer;
	char			*string;
	unsigned int	unsign;
	char			car;
	unsigned long long	pointer;
}				list_type;
typedef struct list_flag{
	int				integer1;
	int				integer2;
}				flag;
typedef struct info{
	int rest;
	struct info	*next;
}				infos;
int		g_counter;
int		ft_printf(const char *format, ...);
int		number_length(int n);
int		unsign_length(unsigned long long n);
int		find(const char *string, char c);
void	which_format1(const char *string, list_type *structure);
void	which_format2(const char *string, list_type *structure);
void	construction_string(const char *format, flag *s_flag, list_type *structure);
void 	ft_putnbr(long n);
char	*join(const char *s, char c);
int		negative(const char *format, list_type *structure);
void	printf_flag(const char **format, flag *s_flag, list_type *structure);
int		types_absolue(const char *format, list_type *structure);
int		is_format(char c);
void	*ft_calloc(size_t count, size_t size);
void    fct5(const char **format, list_type *structure, int i, int j);
int		types(const char *s, list_type *structure);
void	print_left(const char **format, list_type *structure);
void	print_format(const char *format, list_type *structure);
void	ft_putstr(char *s);
void	ft_putchar(char c);
flag	*construction_flag(const char *format, va_list list);
void	fct3(const char *format, list_type *structure, int i);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_itoa(int n);
int		condition1(const char *format);
void    aux3(const char **format, list_type *structure);
void    aux4(const char **format, list_type *structure, flag *s_flag);
int     condition4(const char *format, list_type *structure, int k, int j);
void    aux5(const char *format, char *s, list_type *structure);
void    aux6(const char **format, char *s);
int		cond1(int i, int j);
void    print_spaces(char *s);
void    aux7(list_type *structure, int j);
void    norm1(const char *format, int i, int test_0, list_type *structure);
void    norm2(const char *format, int i, list_type *structure);
int    norm3(const char **format);
void    norm4(const char **format);
int 	condition9(const char **format, list_type *structure, int k);
void    norm6(const char **format, int i, int k);
void    norm7(int i);
void    norm8(const char **format, list_type *structure, int i, int j);
void    norm9(const char **format, list_type *structure, int i);
void    fct4(const char **format, list_type *structure, int i, int j);
void    fct5(const char **format, list_type *structure, int i, int j);
int		cond1(int i, int j);

void    norm5(const char **format, int count, int test_0, list_type *structure);
void    aux8(char **str, list_type *structure);
int     aux9(const char *format);
char	*allocation_negative(int n, int len, long num);
void    fct4(const char **format, list_type *structure, int i, int j);
void	print_negative(const char **format);
char	*allocation_nulle(int n);
char	*dec_to_hexax(unsigned long long n);
void    aux2(const char **format, int i);
void    auxilliaire1(const char **format);
int		find_point(const char *string, char c);
void    print_c(const char **format, list_type *structure);
int     condition3(const char *format);
char	*dec_to_hexaX(unsigned long long n);
void	put_string(const char *format, int j, list_type *structure);
int		ft_lstsize(infos *lst);
void	function(const char **format, list_type *structure);
int indice(const char *format, char c);
void	fct1(const char *format, list_type *structure, int j);
void	fct2(const char *format, list_type *structure, int i, int j);
int		absolue(long n);
int		how_many(const char *format, char c);
list_type	*construction_struct(const char *format, va_list list);
int		condition2(const char *format, list_type *structure);
void	add_front(infos *alst, infos *new);
int		ft_atoi(const char *str);
int		is_width(char c);
void	ft_putunsign(unsigned int n);
int		print_right_left(const char **format, list_type *structure);
int		ft_strlen(char *s);

#endif
