int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index > 1)
		return (ft_fibonacci(index - 2) + ft_fibonacci(index - 1));
	else if (index == 1)
		return (1);
	return (0);
}
