#include<iostream>
#include<string>
using namespace std;
#define MAX 1000  // ͨѶ¼��������ĳ�ʼ��

// ��װ��ʾ�˵�������main�е���

// �˵�����
void showMenu()
{
	cout << "***************************" << endl;
	cout << "*****  1�������ϵ��  *****" << endl;
	cout << "*****  2����ʾ��ϵ��  *****" << endl;
	cout << "*****  3��ɾ����ϵ��  *****" << endl;
	cout << "*****  4��������ϵ��  *****" << endl;
	cout << "*****  5���޸���ϵ��  *****" << endl;
	cout << "*****  6�������ϵ��  *****" << endl;
	cout << "*****  0���˳���ϵ��  *****" << endl;
	cout << "***************************" << endl;
}

/*
�����ϵ�˵Ĳ���:
1.�����ϵ�˵Ľṹ��
2.���ͨѶ¼�ṹ��
3.main�����д���ͨѶ¼
4.��װ�����ϵ�˺���
5.���������ϵ�˵Ĺ���
*/

// ��ϵ�˸���Ľṹ��
struct person
{
	string name;
	int m_Sex; // �Ա�:1.�� 2. Ů
	int m_Age; // ����
	string m_Phone; // �绰
	string m_Address; // סַ
};

// ͨѶ¼�ṹ��
struct Addressbooks
{
	struct person personArray[MAX];
	int m_size;  // ͨѶ¼����
};

// ͨѶ¼�����ϵ�˵Ĺ���
void addPerson(Addressbooks* abs)
{
	// �ж�ͨѶ¼�Ƿ�����
	if (abs->m_size == MAX)
	{
		cout << "ͨѶ¼�洢�������������������" << endl;
		return;
	}
	else
	{
		// �����ϵ����Ϣ
	// ����
		string name;
		cout << "��������ϵ�˵�����:" << endl;
		cin >> name;
		abs->personArray[abs->m_size].name = name;
		// �Ա�
		cout << "�������Ա�:" << endl;
		cout << "1---��" << endl;
		cout << "2---Ů" << endl;
		int sex;
		// �ж��Ƿ�����ĸ�ʽ��ȷ ��ֻ����ȷ������������
		while (1) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[abs->m_size].m_Sex = sex;
				break;
			}
				cout << "�����ʽ����������������" << endl;
		}

		// ����
		cout << "����������" << endl;
		int age;
		cin >> age;
		abs->personArray[abs->m_size].m_Age = age;
		// �绰
		cout << "������绰����:" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_size].m_Phone = phone;
		// סַ
		cout << "�������ַ:" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_size].m_Address = address;
		// ��������
		abs->m_size++;
		cout << "��ӳɹ�!" << endl;
	}

	system("pause"); // �밴���������
	system("cls"); // ����
}

// ��ʾ��ϵ�˵Ĺ���

void displayPerson(Addressbooks* abs)
{
	if (abs->m_size == 0)
	{
		cout << "��ϵ�˵��б�Ϊ��,������Ӻ��ڲ�ѯ!" << endl;
		system("pause"); // �밴���������
		system("cls"); // ����
		return;
	}
	else
	{
		for (int i = 0; i < abs->m_size; i++)
		{
			cout << "��" << i + 1 << "����ϵ����Ϣ:" << endl;
			cout << "����: " << abs->personArray[i].name << "\t";
			cout << "�Ա�: " << (abs->personArray[i].m_Sex == 1 ? "��" : "Ů") << "\t";
			cout <<"����: " << abs->personArray[i].m_Age << "\t";
			cout << "�绰: " << abs->personArray[i].m_Phone << "\t";
			cout << "��ַ: " << abs->personArray[i].m_Address << endl;
		}
		cout << "��ʾͨѶ¼��Ϣ���" << endl;
	}
	system("pause"); // �밴���������
	system("cls"); // ����
}

// �����ϵ���Ƿ����
int existPerson(Addressbooks* abs,string name)
{
	for (int i = 0; i < abs->m_size; i++)
	{
		if (abs->personArray[i].name == name) {
			return i;
			// �ҵ��˾ͷ����±��λ��
		}
	}
	return -1; // �Ҳ�������-1
}

// ɾ����ϵ�˵Ĺ���
void deletePerson(Addressbooks* abs)
{
	cout << "��������Ҫɾ������ϵ�˵�����" << endl;
	string name;
	cin >> name;

	// ���ú����ӿ�
	int ret = existPerson(abs, name);
	
	// ret == -1 δ�鵽���� ��������ھ����ҵ���
	if (ret == -1)
		cout << "���޴���!" << endl;
	else
	{
		for (int i = ret; i < abs->m_size; i++)
		{
			// ����ǰ��
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_size--; // ������ϵ������
		cout << "ɾ���ɹ�!" << endl;
	}
	system("pause"); // �밴���������
	system("cls"); // ����
}

// ������ϵ��
void searchPerson(Addressbooks* abs)
{
	cout << "��������Ҫ���ҵ���ϵ������:" << endl;
	string name;
	cin >> name;

	// ���ú����ӿ�
	int ret = existPerson(abs, name);

	// ret = -1 �Ͳ��޴��� ���������Ϣ
	if (ret == -1)
	{
		cout << "���޴��ˣ�" << endl;
	}
	else
	{
		cout << "�鵽����ϵ����Ϣ����:" << endl;
		cout << "����: " << abs->personArray[ret].name << "\t";
		cout << "�Ա�: " << (abs->personArray[ret].m_Sex == 1 ? "��" : "Ů") << "\t";
		cout << "����: " << abs->personArray[ret].m_Age << "\t";
		cout << "�绰: " << abs->personArray[ret].m_Phone << "\t";
		cout << "��ַ: " << abs->personArray[ret].m_Address << endl;
	}
	system("pause"); // �밴���������
	system("cls"); // ����
}

// �޸���ϵ�˵Ĺ���
void modifyPerson(Addressbooks* abs)
{
	cout << "��������Ҫ�޸ĵ���ϵ������:" << endl;
	string name;
	cin >> name;

	// ���ú���
	int ret = existPerson(abs, name);

	// ret = -1 �Ͳ��޴��� ������ǿ�ʼ�޸ĵĹ�����
	if (ret == -1)
		cout << "���޴���" << endl;
	else
	{
		// ��Ϊ��֪����Ҫ����һ�� ���԰�ÿһ����û���������
		cout << "�������ǶԸ���ϵ����Ϣ�����޸�" << endl;
		// ����
		string name;
		cout << "����������: ";
		cin >> name;
		abs->personArray[ret].name = name;
		cout << endl;
		// �Ա�
		int sex;
		while (1) {
			cout << "�������Ա�:" << endl;
			cout << "1 --- ��" << endl;
			cout << "2 --- Ů" << endl;
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[ret].m_Sex = sex;
				cout << endl;
				break;
			}
			else
			{
				cout << "�����ʽ��������������!" << endl;
				system("pause"); 
				system("cls");
			}
		}
		// ����
		cout << "����������: ";
		int age;
		cin >> age;
		abs->personArray[ret].m_Age = age;
		cout << endl;
		// �绰
		cout << "������绰: ";
		string phone;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;
		cout << endl;
		// ��ַ
		cout << "�������ַ:";
		string address;
		cin >> address;
		abs->personArray[ret].m_Address = address;
		cout << endl;

		cout << "�޸ĳɹ���" << endl;
	}
	system("pause");
	system("cls");
}

// �����ϵ�˵Ĺ���
void cleanPerson(Addressbooks* abs)
{
	abs->m_size = 0; // ֱ�Ӵ�С���Ϊ0 �������޷�����������
	cout << "��ϲ�㣬��ճɹ���" << endl;
	system("pause");
	system("cls");
}

// ��װ����
void fuction()
{
	int select; // �û���ѡ��
	// ����ͨѶ¼�ṹ�����
	Addressbooks abs;
	abs.m_size = 0;

	while (1) {
		// �˵�����
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1: // 1�������ϵ��
			addPerson(&abs);
			break;
		case 2: // 2����ʾ��ϵ��
			displayPerson(&abs);
			break;
		case 3: // 3��ɾ����ϵ��
			/*{  // ���ֻ���������Ե�
				cout << "��������Ҫɾ����ϵ�˵�����:" << endl;
				string k;
				cin >> k;
				if (existPerson(&abs, k) == -1)
					cout << "���޴���" << endl;
				else
					cout << "�ҵ�����" << endl;
			}*/
			deletePerson(&abs);
			break;
		case 4: // 4��������ϵ��
			searchPerson(&abs);
			break;
		case 5: // 5���޸���ϵ��
			modifyPerson(&abs);
			break;
		case 6: // 6�������ϵ��
			cleanPerson(&abs);
			break;
		case 0: // 0���˳���ϵ��
			cout << "��ӭ�´�ʹ��:" << endl;
			system("pause");
			return;
			break;
		}
	}
}

int main()
{
	// ���ù��ܰ�ť�ĺ���
	fuction();
	return 0;
}