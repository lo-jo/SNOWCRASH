int main(int argc, char **argv)
{
	char *arg;
	int i = 0;

	arg = argv[1];
	while(*arg)
	{
		printf("%c", *arg - i);
		i++;
		arg++;
	}
	printf("\n");
	return 0;
}