int main()
{
	// variables
	int array[4];
	int i;
	int j;
	int temp;
	int swapped = 1;
	array[0] = 4;
	array[1] = 66;
	array[2] = 1;
	array[3] = 21;
	//array[4] = 420;

	// bubble sort
	while(swapped == 1)
	{
		swapped = 0;
		for( i = 0; i < 4; i++)
		{
			//if(array[i] > array[i+1])
			//{
				swapped = 1;
				temp = array[i];
				array[i] = array[i+1];
				array[i+1] = temp;

			//}
		}
		swapped = 0; 
	}

}
