#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	char operation[10];
	int plate_stack[1000], line_A[1000], line_B[1000];
	int stack_order = 0, A_order = 0, B_order = 0, tmp = 0;
	char en_choose, de_choose;
	while(scanf("%s", &operation) != EOF) {		//scanf 讀進來要執行的指令
		if(strcmp(operation, "PUSH") == 0) {   //Push的情況
			scanf(" %d", &plate_stack[stack_order]);	//scanf後面的數字
			stack_order++;
		}
		else if(strcmp(operation, "POP") == 0) {	//pop的情況
			tmp = plate_stack[stack_order-1];
			plate_stack[stack_order-1] = '\0';
			stack_order--;
		}
		else if(strcmp(operation, "ENQUEUE") == 0) {	//enqueue的情況
			scanf(" %c", &en_choose);			//scanf A 或 B
			if(en_choose == 'A') {
				line_A[A_order] = tmp;
				A_order++;
			}
			else if(en_choose == 'B') {
				line_B[B_order] = tmp;
				B_order++;
			}
		}
		else if(strcmp(operation, "DEQUEUE") == 0) {	//Dequeue的情況
			scanf(" %c", &de_choose);				//scanf A 或 B
			if(de_choose == 'A') {
				printf("%d\n\n", line_A[0]);
				for(int i = 0; i < A_order; ++i)
					line_A[i] = line_A[i+1];
				line_A[A_order] = '\0';
				A_order--;
			}
			else if(de_choose == 'B') {
				printf("%d\n\n", line_B[0]);
				for(int i = 0; i < B_order; ++i)
					line_B[i] = line_B[i+1];
				line_B[B_order] = '\0';
				B_order--;
			}
		}
	}
	return 0;
}