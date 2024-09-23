

void	signal_error(void)
{
	ft_printf("\n%s\nserver: unexpected error.");
	exit(EXIT_FAILURE);
}

void	handle_signal(int signal)
{

}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("\n\t\tPID: %d\t\t\tBy: strodrig\n", getpid());
	sa.sa_flags = SA_RESTART;
	sa.sa_handler = handle_signal;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		signal_error();
	}
	while (1)
		pause();
	return (0);
}
