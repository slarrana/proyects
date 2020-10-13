#include <stdio.h>
#include "libft/libft.h"
#include "libprintf.h"
#include <limits.h>
int main()
{
	char str[] = "prueba";
	int num = 2526;

/*	printf("LEN = %d\n", (ft_printf("%d,%10d,%3d,%010d,%03d,%-10d,%-3d,%.10d,%.3d,%10.3d,%3.10d,%-10.3d,%-3.10d\n", num, num, num, num, num, num, num, num, num, num, num, num, num)));
	printf("LEN = %d\n", (printf("%d,%10d,%3d,%010d,%03d,%-10d,%-3d,%.10d,%.3d,%10.3d,%3.10d,%-10.3d,%-3.10d\n", num, num, num, num, num, num, num, num, num, num, num, num, num)));
	printf("LEN = %d\n", (ft_printf("%d,%10d,%3d,%010d,%03d,%-10d,%-3d,%.10d,%.3d,%07.3d,%03.7d,%-10.3d,%-3.10d\n", -num, -num, -num, -num, -num, -num, -num, -num, -num, -num, -num, -num, -num)));
	printf("LEN = %d\n", (printf("%d,%10d,%3d,%010d,%03d,%-10d,%-3d,%.10d,%.3d,%07.3d,%03.7d,%-10.3d,%-3.10d\n", -num, -num, -num, -num, -num, -num, -num, -num, -num, -num, -num, -num, -num)));


	printf("LEN = %d\n", (ft_printf("hola que tal,%s,%.3s,%d,%p,%u,%x,%X,%2s,%012s,%02s,%4.3s,%d,%10d,%3d,%010d,%03d,%-10d,%-3d,%.10d,%.3d,%10.3d,%3.10d,%-10.3d,%-3.10d\n", str, str, num, &str, num, num, num, str, str, str, str, num, num, num, num, num, num, num, num, num, num, num, num, num)));
	printf("LEN = %d\n", (printf("hola que tal,%s,%.3s,%d,%p,%u,%x,%X,%2s,%012s,%02s,%4.3s,%d,%10d,%3d,%010d,%03d,%-10d,%-3d,%.10d,%.3d,%10.3d,%3.10d,%-10.3d,%-3.10d\n", str, str, num, &str, num, num, num, str, str, str, str, num, num, num, num, num, num, num, num, num, num, num, num, num)));
*/	printf("LEN = %d\n", (ft_printf("%-8s,%06.3s,%06.3s,%-15.15s,%-0sAAA\n", str, str, str, str ,str)));
/*	printf("LEN = %d\n", (printf("%-8s,%06.3s,%06.3s,%-15.15s,%-0sAAA\n", str, str, str, str ,str)));
	printf("LEN = %d\n", (ft_printf("%-*s,%*.*s,%0*.*s,%-*.*s\n", 10, str, 15, 3, str, 10, 3, str, 20, 4, str)));
	printf("LEN = %d\n", (printf("%-*s,%*.*s,%0*.*s,%-*.*s\n", 10, str, 15, 3, str, 10, 3, str, 20, 4, str)));

	printf("LEN = %d\n", (ft_printf("%0*.*s,%-*.*s\n", 10, 3, str, 20, 4, str)));
	printf("LEN = %d\n", (printf("%0*.*s,%-*.*s\n", 10, 3, str, 20, 4, str)));

	printf("LEN = %d\n", (ft_printf("%-10s,%15.3s,%010.3s,%-20.4s\n", str, str, str, str)));
	printf("LEN = %d\n", (printf("%-10s,%15.3s,%010.3s,%-20.4s\n", str, str, str, str)));
	printf("LEN = %d\n", (ft_printf("%*s,%*.*s\n", 7, str, 7, 10, str)));
	printf("LEN = %d\n", (printf("%*s,%*.*s\n", 7, str, 7, 10, str)));
	

	printf("LEN = %d\n", (ft_printf("%5X,%05X,%-5X,%.5X,%15X,%015X,%-15X,%.15X,%15.7X,%7.15X\n", num, num, num, num, num, num, num, num, num, num)));
	printf("LEN = %d\n", (printf("%5X,%05X,%-5X,%.5X,%15X,%015X,%-15X,%.15X,%15.7X,%7.15X\n", num, num, num, num, num, num, num, num, num, num)));

	printf("LEN = %d\n", (ft_printf("%u,%15u,%3u,%-15u,%015u,%.15u,%10.15u,%15.10u\n", num, num, num, num, num, num, num, num)));
	printf("LEN = %d\n", (printf("%u,%15u,%3u,%-15u,%015u,%.15u,%10.15u,%15.10u\n", num, num, num, num, num, num, num, num)));

	printf("LEN = %d\n", (ft_printf("%p,%15p,%3p,%-30p,%015p,%.15p,%10.15p,%-15.10p %%\n", &num, &num, &num, &num, &num, &num, &num, &num)));
	printf("LEN = %d\n", (printf("%p,%15p,%3p,%-30p,%015p,%.15p,%10.15p,%-15.10p %%\n", &num, &num, &num, &num, &num, &num, &num, &num)));

	printf("LEN = %d\n", (ft_printf("ESTO SON CHARS ,%15c,%-15c,%015c,%.15cBBBB\n", 'A', 'A', 'A', 'A')));
	printf("LEN = %d\n", (printf("ESTO SON CHARS ,%15c,%-15c,%015c,%.15cBBBB\n", 'A', 'A', 'A', 'A')));	
	printf("LEN = %d\n", (ft_printf("%d,%10d,%3d,%010d,%03d,%-10d,%-3d,%.10d,%.3d,%10.3d,%3.10d,%-10.3d,%-3.10d\n", num, num, num, num, num, num, num, num, num, num, num, num, num)));
        printf("LEN = %d\n", (printf("%d,%10d,%3d,%010d,%03d,%-10d,%-3d,%.10d,%.3d,%10.3d,%3.10d,%-10.3d,%-3.10d\n", num, num, num, num, num, num, num, num, num, num, num, num, num)));
        printf("LEN = %d\n", (ft_printf("%d,%10d,%3d,%010d,%03d,%-10d,%-3d,%.10d,%.3d,%07.3d,%03.7d,%-10.3d,%-3.10d\n", -num, -num, -num, -num, -num, -num, -num, -num, -num, -num, -num, -num, -num)));
        printf("LEN = %d\n", (printf("%d,%10d,%3d,%010d,%03d,%-10d,%-3d,%.10d,%.3d,%07.3d,%03.7d,%-10.3d,%-3.10d\n", -num, -num, -num, -num, -num, -num, -num, -num, -num, -num, -num, -num, -num)));
	
	   printf("LEN = %d\n", (ft_printf("%u,%10u,%3u,%010u,%03u,%-10u,%-3u,%.10u,%.3u,%07.3u,%3.10u,%-10.3u,%-3.10u\n", num, num, num, num, num, num, num, num, num, num, num, num, num)));
        printf("LEN = %d\n", (printf("%u,%10u,%3u,%010u,%03u,%-10u,%-3u,%.10u,%.3u,%07.3u,%3.10u,%-10.3u,%-3.10u\n", num, num, num, num, num, num, num, num, num, num, num, num, num)));
        printf("LEN = %d\n", (ft_printf("%u,%10u,%3u,%010u,%03u,%-10u,%-3u,%.10u,%.3u,%07.3u,%03.7u,%-10.3u,%-3.10u\n", -num, -num, -num, -num, -num, -num, -num, -num, -num, -num, -num, -num, -num)));
        printf("LEN = %d\n", (printf("%u,%10u,%3u,%010u,%03u,%-10u,%-3u,%.10u,%.3u,%07.3u,%03.7u,%-10.3u,%-3.10u\n", -num, -num, -num, -num, -num, -num, -num, -num, -num, -num, -num, -num, -num)));
	
	printf("LEN = %d\n", (ft_printf("%.i\n", 0)));
	printf("LEN = %d\n", (printf("%.i\n", 0)));	
    printf("LEN = %d\n", (ft_printf("%-8s,%06.3s,%06.3s,%-15.15s,%-0sAAA\n", str, str, str, str ,str)));
    printf("LEN = %d\n", (printf("%-8s,%06.3s,%06.3s,%-15.15s,%-0sAAA\n", str, str, str, str ,str)));	
	printf("LEN = %d\n", (ft_printf("%d,%d\n", INT_MIN, INT_MAX)));
	printf("LEN = %d\n", (printf("%d,%d\n", INT_MIN, INT_MAX)));
*/
	system("leaks a.out");
	return (0);
}
