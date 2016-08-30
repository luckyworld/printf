#include "includes/ft_printf.h"

PF *ft_init_argument(PF *argument)
{
	int i;

	i = 0;
	while (i < 13)
	{
		argument->flags[i] = 0;
		i++;
	}
	argument->format = NULL;
	argument->index = 0;
	argument->spec = '\0';
	argument->arg = NULL;
	return (argument);
}

void ft_init_spe_tab(SPE *spe)
{
	spe->spe['s'] = ft_arg_s;
	// spe->spe['S'] = ft_arg_ups;
	// spe->spe['c'] = ft_arg_c;
	// spe->spe['C'] = ft_arg_upc;
	spe->spe['d'] = ft_arg_d;
	// spe->spe['D'] = ft_arg_upd;
	// spe->spe['i'] = ft_arg_d;
	// spe->spe['o'] = ft_arg_o;
	// spe->spe['O'] = ft_arg_upo;
	// spe->spe['u'] = ft_arg_u;
	// spe->spe['U'] = ft_arg_upu;
	// spe->spe['\0'] = ft_arg_nospe;
	// spe->spe['%'] = ft_arg_prc;
}

void *ft_arg_s(void *argument, va_list ap)
{
	char *str;

	str = (char*)ap;
	return(ft_buff(argument, str));
}

int ft_check_format(char *str, PF *argument, va_list ap)
{
	int i;
	SPE spe[128];
	i = -1;
	ft_init_spe_tab(spe);
	while (str[++i] != '\0')
	{
		if (str[i] == '%')
		{
			ft_init_argument(argument);
			argument->format = &str[++i];
			if (ft_get_flags(argument, ap) == -1)
				return(-1);
			argument->arg = spe->spe[argument->spec](argument, va_arg(ap, void*));
			i += argument->index;
		}
		else if (str[i] != '%' && str[i] != '\0')
		{
			g_buff[g_i] = str[i];
			g_i++;
		}
	}
	return(0);
}



int ft_printf(const char *format, ...)
{
	va_list ap;
	PF argument;

	argument.ret = 0;
	if (!format)
		return(0);
	va_start(ap, format);
	ft_init_buff();
	ft_check_format((char*)format, &argument, ap);
	if (g_i)
		ft_display(&argument);
	ft_putchar('\n');
	va_end(ap);
	return(argument.ret);
}

int main(int ac, char **av)
{  
	char *s, c, d;
	int a;

	a = 42;
	s = "argument";
	c = 55;
	d = 'q';

	ft_printf(av[1], s);
	printf("%.0d\n",0 );
	return (0);
}