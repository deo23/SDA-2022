int main(){ 	
		int *ptr;
		int a, b, c;
		ptr = 5;
		a = ptr++;
		b = ++ptr;
		c = ptr + 1;
		printf("%d %d %d", a,b,c);
		return 0;
	}	
