#include "../includes/so_long.h"

int main()
{
	t_solong *solong = (t_solong *)ft_calloc(sizeof(t_solong), 1);

	printf("%d\n", solong->row);
	printf("%d\n", solong->col);
	printf("%d\n", solong->flag[0]);
	printf("%d\n", solong->flag[1]);
	printf("%d\n", solong->flag[2]);

	return 0;
}
