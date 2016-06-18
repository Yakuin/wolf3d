/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iscntrl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboualla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 19:07:11 by yboualla          #+#    #+#             */
/*   Updated: 2016/02/17 00:30:32 by yboualla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_iscntrl(unsigned char c)
{
	return (c == '\t' || c == '\n' || c == '\v' ||
			c == '\f' || c == '\r' || c == ' ');
}
