/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 23:58:32 by oprosvir          #+#    #+#             */
/*   Updated: 2024/04/26 00:31:35 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// убрать пробелы в начале строки
static const char	*trim_whitespace(const char *str)
{
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	return (str);
}

// получить знак
static int	get_sign(const char **str)
{
	int	sign;

	sign = 1;
	if (**str == '-')
	{
		sign = -1;
		(*str)++;
	}
	else if (**str == '+')
		(*str)++;
	return (sign);
}

// строку в число с проверкой на ошибки
static long	parse_to_long(const char *str, int sign, int *error)
{
	long	res;

	res = 0;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		if ((sign == 1 && res > INT_MAX) || (sign == -1 && -res < INT_MIN))
		{
			*error = 1;
			return (0);
		}
		str++;
	}
	return (res);
}

// проверка на лишние символы
static int	has_extra_characters(const char *str)
{
	while (*str >= '0' && *str <= '9')
		str++;
	return (*str != '\0');
}

static int	parse_arg(const char *str, int *error)
{
	int		sign;
	long	res;

	str = trim_whitespace(str);
	sign = get_sign(&str);
	if (*str < '0' || *str > '9') // проверка на цифры
	{
		*error = 1;
		return (0);
	}
	if (*str == '0' && *(str + 1) >= '0' && *(str + 1) <= '9') // на нули
	{
		*error = 1;
		return (0);
	}
	res = parse_to_long(str, sign, error);
	if (*error || has_extra_characters(str))
		return (0);
	return (int)(res * sign);
}

/* ======> working BIG <======

int	parse_arg(const char *str, int *error)
{
	long res = 0;
	int sign = 1;

	// Удаляем пробелы в начале и конце
	while ((*str >= 9 && *str <= 13) || *str == ' ') {
		str++;
	}

	// Проверка на допустимый знак
	if (*str == '-' || *str == '+') {
		if (*str == '-') {
			sign = -1;
		}
		str++;
	}

	// Убедимся, что строка содержит цифры
	if (*str < '0' || *str > '9') {
		*error = 1;
		return (0);
	}

	// Проверяем на ведущие нули
	if (*str == '0' && *(str + 1) >= '0' && *(str + 1) <= '9') {
		*error = 1;
		return (0);
	}

	// Преобразуем число
	while (*str >= '0' && *str <= '9') {
		res = res * 10 + (*str - '0');
		if ((sign == 1 && res > INT_MAX) || (sign == -1 && -res < INT_MIN)) {
			*error = 1;
			return (0);
		}
		str++;
	}

	// Проверка на дополнительные символы
	if (*str != '\0') {
		*error = 1;
		return (0);
	}

	return ((int)(res * sign));
}*/

/*  ------>previous<------

int	parse_arg(const char *str, int *error)
{
	long res;
	int sign;

	res = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		if ((sign == 1 && res > INT_MAX) || (sign == -1 && -res < INT_MIN))
		{
			*error = 1;
			return (0); // Immediate exit after setting an error
		}
		str++;
	}
	if (*str != '\0') // Check for invalid characters after the number
	{
		*error = 1;
		return (0); // Immediate exit after setting an error
	}
	return ((int)(res * sign));
}*/