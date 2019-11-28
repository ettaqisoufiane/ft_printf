/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 21:27:31 by settaqi           #+#    #+#             */
/*   Updated: 2019/11/10 00:33:17 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct		s_analyst
{
	int				leftspaces;
	int				rightspaces;
	int				leftzeroed;
	int				precision;
	int				zeroflag;
	int				minusflag;
}					t_analyst;

int					ft_printf(const char *str, ...);
void				ft_putnbr(long nb);
void				ft_putchar(char c);
void				ft_putstr(const char *str);
char				*ft_strrev(char *str);
char				*ft_convhexadecimaladd(long long i, int b);
char				*ft_putnbr_unsigned(int i);
char				*chartostr(int c);
int					ft_checkifcovers(char c);
int					ft_checksymbols(const char *str);
int					ft_getind(const char *str);
int					ft_checkifreserved(char c);
char				*controle_theoutput(const char *str, char c, va_list args);
char				*ft_conversions(const char *str, va_list args, char c);
char				*ft_conversiond(const char *str, va_list args, char c);
char				*ft_conversioni(const char *str, va_list args, char c);
char				*ft_conversionp(const char *str, va_list args, char c);
char				*ft_conversionu(const char *str, va_list args, char c);
char				*ft_conversionc(const char *str, va_list args, char c);
char				*ft_conversionx(const char *str, va_list args, char c);
char				*ft_conversionbigx(const char *str, va_list args, char c);
void				initialvalues(t_analyst *data);
char				*ft_addspacesdchar(char *ptr, int totalspaces, int lftorig);
char				*ft_addspacesd(int number, int totalspaces, int lftorig);
char				*ft_addzerod(int number, int totalzeroed);
char				*ft_addzerox(char *ptr, int totalzeroed);
char				*ft_addspacesxchar(char *ptr, int totalspaces, int lftorig);
int					ft_checkpointandzero(const char *str);
void				ft_forp(t_analyst *data, va_list args,
					const char *str, int i);
void				ft_forc(t_analyst *data, va_list args,
					const char *str, int i);
void				ft_foru(t_analyst *data, va_list args,
					const char *str, int i);
void				ft_convd2(const char *str, t_analyst *data,
					int i, va_list args);
void				ft_forxminx(t_analyst *data, va_list args,
					const char *str, int i);
char				*ft_conversionpercent(const char *str,
					va_list args, char c);
char				*ft_convhexadecimaladdu(unsigned long i, int b);
void				ft_createconvd2(va_list args, char **ptr,
					t_analyst *data, int *c);
int					ft_convp2(const char *str, va_list args,
					char c, t_analyst *data);
int					ft_hexdec2(int number, int c);
char				*ft_convs2(va_list args, t_analyst *data, char **ptr);
void				ft_createptrs(t_analyst *data, char **ptr, va_list args);
char				*ft_addzeros(char *ptr, int totalzeroed);
char				*ft_toshow_convs(char *ptr, int totalzeroed);
char				*ft_addspacesschar(char *ptr, int totalspaces, int lftorig);
int					ft_leftorright(t_analyst *data);
void				ft_createconvd3(va_list args, char **ptr,
					t_analyst *data, int *c);
void				ptrcreateu2(t_analyst *data, char **ptr, va_list args);
char				*ft_addzerou(int number, int totalzeroed);
char				*ft_addspacesu(int number, int totalspaces, int lftorig);
char				*ft_addspacesuchar(char *ptr, int totalspaces, int lftorig);
void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *str, int c, size_t n);
size_t				ft_strlen(const char *str);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
char				*ft_strrchr(const char *str, int c);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_calloc(size_t count, size_t size);
char				*ft_substr(char const *s, unsigned int start, int len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_itoa(long n);
char				*ft_strdup(const char *src);
char				*ft_strrev(char *str);
void				ft_somecases(const char *str, t_analyst
					*data, int i, va_list args);
void				ft_somecases2(const char *str, t_analyst *data,
					int i, va_list args);
int					checksig(int sig, int lftorig);
void				createptrforc(va_list args, char **ptr,
					t_analyst *data, int *c);
char				*ft_addzeroc(int c, int totalzeroed);
char				*ft_addspacesc(int c, int totalspaces, int lftorig);
char				*ft_addspacescchar(char *ptr, int totalspaces, int lftorig);
void				ft_printchar(const char *str);

#endif
