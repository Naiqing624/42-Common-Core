/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacao <nacao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 08:10:24 by nacao             #+#    #+#             */
/*   Updated: 2025/01/09 08:10:24 by nacao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int argument)
{
	return (argument >= 32 && argument <= 126);
}
