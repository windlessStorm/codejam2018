#include<stdio.h>




void displist(unsigned int *numlist, unsigned int size) {
	printf("\nNumber list:\n");
	for( int i = 0; i < size; i++) {
		printf("%u ", numlist[i]);
	}
	printf("\n");
}

/* Like bubble sort, but instead compare the current element with next to next element instead of next element and decide to swap or not.
*	eg. Bubble sort: 	2 3 1 4 ==> 2 1 3 4 ===> 1 2 3 4
	    Trouble sort:	2 3 1 4 ==> 1 3 2 4   //Stops here, cannot sort
*
*/
void troublesort( unsigned int *numlist, const unsigned int size) {
	char done = 0;
	int i = 0;
	while(!done) {
		done = 1;
		for( i = 0; i < size - 2; i++) {
			//printf("\nCurrent list:\n");
			//displist(numlist, size);
			if( numlist[i] > numlist[i+2]) {
				done = 0;
				//printf("Swapping %d and %d\n", numlist[i], numlist[i+2]);
				unsigned int temp = numlist[i+2];
				numlist[i+2] = numlist[i];
				numlist[i] = temp;
			}
		}
	}
}

int is_sorted( const unsigned int *numlist, const unsigned int size) {
	for(int i = 0; i < size-1; i++) {
		if(numlist[i]>numlist[i+1])
			return i;
	}
	return -1;
}



int main(int argc, const char* argv[]) {
	int total_testcase;
	int cur_testcase;
	
	scanf("%d", &total_testcase);	

	for(cur_testcase = 1; cur_testcase <= total_testcase; cur_testcase++) {
		unsigned int numlist[100000];
		unsigned int listsize;
		scanf("%u", &listsize);
	
		for(int i = 0; i < listsize; i++) {
			scanf("%u", &numlist[i]);
		}
	
		troublesort(numlist, listsize);
			
		//printf("Number list after troublesort is:");
		//displist(numlist, listsize);

		int retval = is_sorted(numlist, listsize);
		if(retval < 0){
			printf("Case #%d: OK\n", cur_testcase);
		}
		else{
			printf("Case #%d: %d\n", cur_testcase, retval);
		}
	}

		
}
