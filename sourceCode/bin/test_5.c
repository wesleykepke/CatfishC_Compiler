int x;
int y;

void main(){

	// declaring constants and single variables
	int i = 1;
	int a[3];
	int b[5][6];

	// 1D usage on left and right hand side
	a[2] = i;
	a[1] = a[2];


	// 2d usage on left and right hand side
	b[3][4] = i;
	b[2][0] = b[3][4];

}