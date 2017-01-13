#include <cstdio> //io lib
#include <stdlib.h> //standart lib
#include <locale.h> //locale lib
#define _USE_MATH_DEFINES
#include <math.h> //math lib
#include <ctime> //time lib for random


using namespace std;

void AreaTriangle();
void PayPhone();
void Calc();
void Search();
void Average();

int main()
{
    int swivar;
    setlocale(LC_ALL, "Russian");
    printf(
    "1. �������� ��������� ���������� ������� ������������,"
    "���� �������� ����� ���� ������ � �������� ���� ����� ����." 
    "���� �������� ������������� ��� ������ �� ����� ���������� ���������" 
    "(������, ��������� �������������, �������� ���������� �������). \n"

    "2. ������ ���������� ����� ������������ �� ���������� �������: "
    "�� ��������� �� A ����� � ����� ������������ B ������, "
    "� ��������� ����� ������������� ����� ������������ �� ������� C ������ �� ������. "
    "����� �������� ������ �� T ����� ���������� � ����� ��� ��������  ��������� A,B,C. \n"

    "3. �������� ���������, � ������� �������� ��� �������������� ����� x � y � ����� ��������������� ��������, "
    "������� ������� ��������� ��� ����� �������: 1 � ��������, 2 � ���������, 3 � ���������, 4 � �������. "
    "� ��������� ������� ��������� ��������� �������� � ������ ���������. \n"

    "4. ��� ������ a[N]. �������� ������� ������������� � ������� �����������. "
    "��������� ����� ��������� ������, ����� � ������� ������� �� ��������� key. "
    "������ ������ ���������� �������� ��� -1, ���� ������ �������� � ������� ���. "
    "���� ����� ��������� ���������, ������ ������ ������� �� ���.  "
    "���������� � �������� ��������� ������� � �������� �������� �������� key ������ � ����������. "
    "�����������: N<=100, �������� �������� ��������� [-50; 50], ��� ��������� � �����. \n"

    "5.���� ������������� ������� b[M][N]. ���������� ������ ������, "
    "������� �������������� ��������� ������� �����������. "
    "���� ����� ����� ���������, �� ������ ���������� �� �� ��������. "
    "�������� ������� ������ � ������� ���������� ��������� �����. "
    "��������  M, N ������ � ����������. �����������: M<=10, N<=10, "
    "�������� ��������� �� ��������� [-20; 20]. \n"
    );

    scanf("%d", &swivar);
	switch (swivar)
	{
		case 1:
			AreaTriangle();
			break;
		case 2:
            PayPhone();
			break;
		case 3:
			Calc();
			break;
        case 4:
			Search();
			break;
        case 5:
			Average();
			break;
	}

return 0;
}

void AreaTriangle()
{
    double longA, longB, angleAB, AreaT;
    printf("���������� ������� ������������.\n������� ����� ������ ����� ���� ������ ������������ (��): ");
    scanf("%lf%lf", &longA, &longB); //qualifier %lf for double
    printf("������� �������� ���� ����� ����� ���������: ");
    scanf("%lf", &angleAB); 

    AreaT = 0.5 * longA * longB * sin(angleAB * M_PI / 180); // 1/2ABsin(alpha), Angle degrees to radians * pi / 180
    printf("������� ������������: %lf ��.��.", AreaT);
}

void PayPhone()
{
    double Limit, PriceB, PriceC, Time;
    printf("���������� ��������� ���������.\n������� ����� ���������� �� ��������� ���� � �������: ");
    scanf("%lf", &Limit);
    printf("������� ��������� ������ ��������� �� ������: ");
    scanf("%lf", &PriceB);
    printf("������� ��������� ������ ��������� ����� ������: ");
    scanf("%lf", &PriceC);
    printf("������� ����� ���������: ");
    scanf("%lf", &Time);
    if (Limit > Time) //if talk time exceeds the limit
    {
        printf("��������� ���������: %lf", Time * PriceB);
    }else
    {
        printf("��������� ���������: %0.*lf", 2, Limit * PriceB + (Time - Limit) * PriceC); //modifier output with arg *
    }
}

void Calc()
{
    double NumA, NumB, ans;
    short choice;
    printf("������� 2 ������������� ����� ����� ������: ");
    scanf("%lf%lf", &NumA, &NumB);
    printf("�������� �������� 1 � ��������, 2 � ���������, 3 � ���������, 4 � �������: ");
    scanf("%hd", &choice);
    switch (choice)
	{
		case 1:
			ans = NumA + NumB;
		    break;
        case 2:
			ans = NumA - NumB;
		    break;
        case 3:
			ans = NumA * NumB;
		    break;
        case 4:
			ans = NumA / NumB;
		    break;
    }
    printf("�����: %lf", ans);
}

void Search()
{
    int SearchMas[100], count;
    printf("������� ���������� ��������� �������: ");
    do{
        scanf("%d", &count);
        if (count > 100)
            printf("���������� ��������� � ������� ������ ���� <=100");
    }while (count >= 100 || count <= 0);
    printf("������� %d ��������� �������\n", count);

    for (int i = 0; i < count; i++){
        do{
            scanf("%d", &SearchMas[i]);
            if (SearchMas[i] > 50 || SearchMas[i] < -50)
                printf("������� ������� ������ ���� [-50; 50]\n");
        }while (SearchMas[i] > 50 || SearchMas[i] < -50);
    }
    
    printf("������ �� %d ���������: \n", count);
    for (int i = 0; i < count; i++) printf("%d ", SearchMas[i]);

    int first = 0, last = count, key, it = 0;
    printf("\n������� ������� ��������: ");
    scanf("%d", &key);
    while (first < last) {
        int mid = first + (last - first) / 2;

        if (key <= SearchMas[mid])
            last = mid;
        else
            first = mid + 1;
        it++;
    }

    if (last < count && SearchMas[last] == key) {
        printf("������ �������� ��������: %d, ������ �� %d ��������", last, it);
    } else
        printf("������ �������� ��������: %d", -1);
}

void Average()
{
    int AveMass[10][10], m, n;
    srand(time(0));
    printf("������� ������ ������������� �������: ");
    do{
        scanf("%d%d", &m, &n);
        if ((m <= 0 || m > 10) && (n <= 0 || n > 10))
            printf("������� ����� ������ �������");
    }while((m <= 0 || m > 10) && (n <= 0 || n > 10));
    for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++){
        AveMass[i][j] = rand()%40-20;
    }

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            printf("%4.1d", AveMass[i][j]);
        }
        printf("\n");
    }
    int max = -20, index = 0, ave = 0;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            ave = ave + AveMass[i][j];
        }
        ave = ave / n;
        if (max < ave){
            max = ave;
            index = i;
        }
        ave = 0; 
    }
    printf("������� �������������� ��������� ����������� � %d ������", index + 1);
}