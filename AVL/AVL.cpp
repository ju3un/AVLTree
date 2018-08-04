#include "AVL.h"


int main() {
	int select, num;
	Node<int>* root = NULL;


	cout << "AVL Tree" << endl;
	while (1) {
		int i = 0;
		int arr[ROW][COL] = { 0 };

		cout << "=============================================================================" << endl;
		cout << "1. �Է�" << "  2. ����" << "  3. Preorder" << "  4. Inorder" << "  5. Postorder" << "  6. ���" << "  0. ������" << endl;
		cout << "=============================================================================" << endl;
		cout << "���� �Է� : ";
		cin >> select;

		switch (select) {
		case 1:
			cout << "Ʈ���� �ְ���� �� �Է� : ";
			cin >> num;
			root = root->INSERT(root, num);
			break;

		case 2:
			cout << "Ʈ������ �����ϰ� ���� �� �Է� : ";
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
			cout << "�߸��Է��ϼ̽��ϴ�. �޴��� ���ư��ϴ�." << endl;
			break;
		}
	}
}