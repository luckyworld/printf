#include "includes/ft_printf.h"

#include <stdio.h>
#include <limits.h>
#include <locale.h>

int main(int ac, char const *av[])
{
	(void)ac;
	(void)av;
	printf(" 1 !%-42.56lf!\n", -1054803456.0000700);
	ft_printf(" 0 !%-42.56lf!\n\n", -1054803456.0007000);
	printf(" 1 !% .60f!\n", 1092938880.0000400);
	ft_printf(" 0 !% .60f!\n\n", 1092938880.0000400);
	// printf(" 1 {%54.16lf}\n", -1.420000);
	// ft_printf(" 0 {%54.16lf}\n\n",-1.420000);
	// printf(" 1 {% .48f}{%F}\n", -1037923456.000000, 1.42);
	// ft_printf(" 0 {% .48f}{%F}\n\n", -1037923456.000000, 1.42);
	// printf(" 1 {%f}{%F}\n", 1444565444646.6465424242242, 1444565444646.6465424242242);
	// ft_printf(" 0 {%f}{%F}\n\n", 1444565444646.6465424242242, 1444565444646.6465424242242);
	// printf(" 1 {%f}{%F}\n", -1444565444646.6465424242242454654, -1444565444646.6465424242242454654);
	// ft_printf(" 0 {%f}{%F}\n", -1444565444646.6465424242242454654, -1444565444646.6465424242242454654);
	// printf(" 1 {% 32.2lf}{%F}\n", 1574891136.000000, -1444565444646.6465424242242454654);	
	// ft_printf(" 0 {% 32.2lf}{%F}\n", 1574891136.000000, -1444565444646.6465424242242454654);
	// printf("{%f}{%F}\n", 1444565444646.6465424242242, 1444565444646.6465424242242);
	// ft_printf("{%f}{%F}", 1444565444646.6465424242242, 1444565444646.6465424242242);
	return 0;
}