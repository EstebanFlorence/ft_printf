/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:43:09 by adi-nata          #+#    #+#             */
/*   Updated: 2023/01/08 23:23:18 by adi-nata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_printfs(char *s, t_format *flag)
{
	int		len;

	if (!s)
		len = 6;
	else
		len = (int)ft_strlen(s);
	if (!flag->meno && !flag->wdt && !flag->prc)
	{
		ft_puts(s, len, flag);
		return ;
	}
	if (flag->prc)
	{
		if (flag->prcquant > len)
			flag->prc = 0;
		else
			len = flag->prcquant;
	}
	if (flag->meno)
		ft_puts(s, len, flag);
	ft_checkwdts(len, s, flag);
	if (!flag->meno)
		ft_puts(s, len, flag);
}

void	ft_puts(char *s, int len, t_format *flag)
{
	if (!s)
	{
		if ((flag->prc && flag->prcquant < 6))
			return ;
		ft_puts("(null)", len, flag);
		return ;
	}
	if (flag->prc)
		ft_putstrprc(s, flag);
	else
	{
		ft_putstr(s);
		flag->len += (int)ft_strlen(s);
	}
}

void	ft_checkwdts(int len, char *s, t_format *flag)
{
	if (!flag->wdt)
		return ;
	if (!s)
	{
		if (flag->prc && flag->prcquant < 6)
			ft_putwdt(flag);
		else
		{
			flag->wdtquant -= len;
			ft_putwdt(flag);
		}
	}
	else
	{
		flag->wdtquant -= len;
		ft_putwdt(flag);
	}
}
