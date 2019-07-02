#include<stdio.h>
#include"BST.h"

main()
{
	NODE *root = NULL;
	while(1)
	{
		int S,val=0;

		printf("\n|||||||||||||||||||||||");
		printf("\n|| CHOOSE THE OPTION ||");
		printf("\n|||||||||||||||||||||||");
		printf("\n|| 1_INSERT          ||");
		printf("\n|| 2_DELETE          ||");
		printf("\n|| 3_PRE-ORDER       ||");
		printf("\n|| 4_IN-ORDER        ||");
		printf("\n|| 5_POST-ORDER      ||");
		printf("\n|| 0_EXIT            ||");
		printf("\n|||||||||||||||||||||||\n");
		printf("\n\t\t\t\t Enter your choice...");
		scanf("%d",&S);
		switch(S)
		{
			case 0: return 0;

			case 1:
				printf("Enter the value :");
				scanf("%d",&val);
				root = insertBST(root,val);
			break;

			case 2:
				printf("Enter the value :");
				scanf("%d",&val);
				root = deleteBST(root,val);
			break;

			case 3:
				preorder(root);
			break;

			case 4:
				inorder(root);
			break;

			case 5:
				postorder(root);
			break;

			default : printf("\n PLEASE ENTER VALID OPTION \n");
			break;
		}
	}
}
