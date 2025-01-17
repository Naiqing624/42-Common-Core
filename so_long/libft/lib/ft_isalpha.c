/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacao <nacao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 08:10:46 by nacao             #+#    #+#             */
/*   Updated: 2025/01/09 08:10:46 by nacao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int argument)
{
	return ((argument >= 'a' && argument <= 'z')
		|| (argument >= 'A' && argument <= 'Z'));
}
