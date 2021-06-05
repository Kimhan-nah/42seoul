int	ft_sqrt(int nb)
{
	long long tmp;

	tmp = nb / 2;
	while (tmp * tmp > nb)
		tmp = tmp / 2;
	while (tmp * tmp <= nb)
	{
		if (tmp * tmp == nb)
			return (tmp);
		tmp++;
	}
	return (0);
}
