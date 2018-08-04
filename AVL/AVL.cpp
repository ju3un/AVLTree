#include "AVL.h"


int main() {
	int select, num;
	Node<int>* root = NULL;


	cout << "AVL Tree" << endl;
	while (1) {
		int i = 0;
		int arr[ROW][COL] = { 0 };

		cout << "=============================================================================" << endl;
		cout << "1. 입력" << "  2. 삭제" << "  3. Preorder" << "  4. Inorder" << "  5. Postorder" << "  6. 출력" << "  0. 나가기" << endl;
		cout << "=============================================================================" << endl;
		cout << "숫자 입력 : ";
		cin >> select;

		switch (select) {
		case 1:
			cout << "트리에 넣고싶은 값 입력 : ";
			cin >> num;
			root = root->INSERT(root, num);
			break;

		case 2:
			cout << "트리에서 삭제하고 싶은 값 입력 : ";
			cin >> num;
			root = root->REMOVE(root, num);
			break;

		case 3:
			root->PREORDER(root);
			cout << endl;
			break;

		case 4:
			root->INORDER(root);
			cout << endl;
			break;

		case 5:
			root->POSTORDER(root);
			cout << endl;
			break;

		case 6:
			root->PRINT(root, arr, i, 0);

			for (int j = 0; j < ROW; j++) {
				for (int k = 0; k < COL; k++) {
					if (arr[j][k])
						cout << arr[j][k] << "  ";

					else
						cout << "   ";
				}

				cout << endl;
			}
			break;

		case 0:
			return 0;
			break;

		default:
			cout << "잘못입력하셨습니다. 메뉴로 돌아갑니다." << endl;
			break;
		}
	}
}