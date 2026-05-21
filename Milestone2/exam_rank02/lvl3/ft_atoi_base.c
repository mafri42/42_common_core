/*Assignment name  : ft_atoi_base
Expected files   : ft_atoi_base.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str (base N <= 16)
to an integer (base 10) and returns it.

The characters recognized in the input are: 0123456789abcdef
Those are, of course, to be trimmed according to the requested base. For
example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".

Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

Minus signs ('-') are interpreted only if they are the first character of the
string.

Your function must be declared as follows:

int	ft_atoi_base(const char *str, int str_base);*/

int is_space(char c)
{
    if ((c == 32) || ((c >= 9) && (c <= 13)))
        return (1);
    return (0);
}

int is_valid_base(char c, int base_len)
{
    char    *lc_base;
    char    *uc_base;
    int     i;

    lc_base = "0123456789abcdef";
    uc_base = "0123456789ABCDEF";
    i = 0;
    while (i < base_len)
    {
        if ((c == lc_base[i] || (c == uc_base[i])))
            return (i);
        i++;
    }
    return (-1);
}

int	ft_atoi_base(const char *str, int str_base)
{
    int     i;
    int     sign;
    int     result;

    i = 0;
    sign = 1;
    result = 0;
    while (is_space(str[i]))
        i++;
    if ((str[i] == '-') || (str[i] == '+'))
    {
        if (str[i] == '-')
            sign *= -1;
        i++;
    }
    while (str[i] && (is_valid_base(str[i], str_base) != -1))
    {
        result = result * str_base + is_valid_base(str[i], str_base);
        i++;
    }
    return (result * sign);
}
