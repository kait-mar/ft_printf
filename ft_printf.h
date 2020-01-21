/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kait-mar <kait-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 11:45:08 by kait-mar          #+#    #+#             */
/*   Updated: 2020/01/21 01:00:52 by kait-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "string.h"

typedef struct			s_list_type{
	int					integer;
	char				*string;
	unsigned int		unsign;
	char				car;
	unsigned long long	pointer;
}						t_list_type;
typedef struct			s_flag{
	int					integer1;
	int					integer2;
}						t_flag;
typedef struct			s_list2{
	int					i;
	int					j;
	int					test_0;
}						t_list2;
typedef struct			s_list3{
	int					i;
	int					j;
	const char			*format;
}						t_list3;
int						g_counter;
int						ft_printf(const char *format, ...);
int						number_length(int n);
int						unsign_length(unsigned long long n);
int						find(const char *string, char c);
void					which_format(const char *string,
		t_list_type *structure);
void					construction_string(const char **format, t_flag *flaag,
						t_list_type *structure);
void					ft_putnbr(long n);
void					laast(const char **format);
char					*join(const char *s, char c);
void					help404(int i, int j);
void					help14(const char **format,
		t_list_type *structure, int i);
void					help15(const char **format,
		t_list_type *structure, int i, int j);
void					help16(const char **format,
		t_list_type *structure, int i, int j);
void					help17(const char **fromat,
		t_list_type *structure, int i, int j);
int						negative(const char *format, t_list_type *structure);
void					printf_flag(const char **format, t_flag *flaag,
						t_list_type *structure);
int						types_absolue(const char *format,
		t_list_type *structure);
int						is_format(char c);
int						skip(const char *format);
void					normin(const char **format, t_list_type *structure);
int						cond11(const char **format, t_list_type *structure);
void					help_struct(const char *format, t_list_type *structure,
						int i, va_list list);
int						cond12(const char **format, t_list_type *structure);
void					tab(char **converted);
int						first_str(const char **format);
void					help_string(t_list_type *structure, int i, int j);
void					help_pointer(const char **format,
		t_list_type *structure,
						int i, int j);
void					help_d(int i, int j, int test_0);
char					*ft_itoa(int n);
int						ft_atoi(const char *str);
int						ft_isdigit(int c);
void					help_others(const char **format,
			t_list_type *structure, t_list2 *structe);
void					last_function(const char **format,
			t_list_type *structure, t_list2 *structe);
int						support1(const char *string);
int						support1(const char *string);
void					support2(char **string, t_list_type *structure,
						t_flag *flaag, t_list3 *liste);
void					support3(char **string,
		t_list_type *structure, t_list3 *liste);
void					*ft_calloc(size_t count, size_t size);
void					fct5(const char **format,
		t_list_type *structure, int i, int j);
int						types(const char *s, t_list_type *structure);
void					print_left(const char **format, t_list_type *structure);
void					print_format(const char *format,
		t_list_type *structure);
void					ft_putstr(char *s);
void					ft_putchar(char c);
t_flag					*construction_flag(const char *format, va_list list);
void					fct3(const char *format, t_list_type *structure, int i);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_itoa(int n);
int						condition1(const char *format);
void					aux3(const char **format, t_list_type *structure);
void					aux4(const char **format,
		t_list_type *structure, t_flag *flaag);
int						condition4(const char *format,
		t_list_type *structure, int k, int j);
void					fct2_negatif(int i, int j);
void					fct3_negatif(int i);
void					fct4_negatif(int i);
void					aux5(const char *format, char *s,
		t_list_type *structure);
void					aux6(const char **format, char *s);
int						cond1(int i, int j);
void					fct1_negatif(int j);
void					print_spaces(char *s);
void					aux7(t_list_type *structure, int j);
void					norm1(const char *format,
		int i, int test_0, t_list_type *structure);
void					norm2(const char *format, int i,
		t_list_type *structure);
int						norm3(const char **format);
void					norm4(const char **format);
void					help1(const char **format, t_list_type *structure);
int						cond10(const char **format);
int						cond13(const char **format);
int						cond14(const char **format);
int						cond15(const char **format,
		t_list_type *structure, int k);
int						condition9(const char **format,
		t_list_type *structure, int k);
void					norm6(const char **format, int i, int k);
void					norm7(int i);
void					norm8(const char **format,
		t_list_type *structure, int i, int j);
void					norm9(const char **format,
		t_list_type *structure, int i);
void					fct4(const char **format,
		t_list_type *structure, int i, int j);
void					fct5(const char **format,
		t_list_type *structure, int i, int j);
int						cond1(int i, int j);
void					support4(char **string,
		t_list_type *structure, t_list3 *liste);
void					support5(char **string, t_list_type *structure,
						t_flag *flaag, t_list3 *liste);
void					support6(char **string, t_list_type *structure,
						t_flag *flaag, t_list3 *liste);
void					support7(char **string, t_list_type *structure,
						t_list3 *liste);
void					support8(char **string, t_list_type *structure,
						t_list3 *liste);
void					support9(char **string, t_list_type *structure,
						t_flag *flaag, t_list3 *liste);
void					support(char **string, t_list_type *structure,
						t_flag *flaag, t_list3 *liste3);
int						condii(int i, int j);
void					help18(t_list_type *structure, int i, int j);
void					help19(t_list_type *structure, int i, int j);
void					norm5(const char **format, int count,
						int test_0, t_list_type *structure);
void					aux8(char **str, t_list_type *structure);
int						aux9(const char *format);
int						condition_mod(const char *format);
void					fct4(const char **format,
		t_list_type *structure, int i, int j);
void					print_negative(const char **format);
char					*dec_to_hexax(unsigned long long n);
void					aux2(const char **format, int i);
void					auxilliaire1(const char **format);
int						find_point(const char *string, char c);
void					print_c(const char **format, t_list_type *structure);
int						condition3(const char *format);
char					*dec_to_hexaxx(unsigned long long n);
void					put_string(const char *format,
		int j, t_list_type *structure);
void					function(const char **format, t_list_type *structure);
int						indice(const char *format, char c);
void					fct1(const char *format, t_list_type *structure, int j);
void					fct2(const char *format,
		t_list_type *structure, int i, int j);
int						absolue(long n);
int						how_many(const char *format, char c);
t_list_type				*construction_struct(const char *format, va_list list);
int						condition2(const char *format, t_list_type *structure);
int						ft_atoi(const char *str);
int						is_width(char c);
void					ft_putunsign(unsigned int n);
int						print_right_left(const char **format,
		t_list_type *structure);
int						ft_strlen(char *s);
int						is_flag(char c);

#endif
