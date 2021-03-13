/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 16:02:15 by hannkim           #+#    #+#             */
/*   Updated: 2021/02/20 23:29:09 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
void rush(int x, int y);

int main()
{
	rush(5,3);
	printf("\n");
	rush(5,1);
	printf("\n");
	rush(1,1);
	printf("\n");
	rush(1,2);
	printf("\n");
	rush(1,5);
	printf("\n");
	rush(4,4);
	printf("\n");
	rush(2,2);
	printf("\n");
	rush(3,2);
	printf("\n");
	rush(2,3);
	rush(5,0);
	rush(0,0);
	rush(0,5);
	printf("\n");
	rush(123,42);
	printf("\n");
	rush(5,5);

	return 0;

}
