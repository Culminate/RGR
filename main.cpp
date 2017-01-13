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
    "1. Написать программу вычисления площади треугольника,"
    "если известны длины двух сторон и величина угла между ними." 
    "Ниже приведен рекомендуемый вид экрана во время выполнения программы" 
    "(данные, введенные пользователем, выделены полужирным шрифтом). \n"

    "2. Услуги телефонной связи оплачиваются по следующему правилу: "
    "за разговоры до A минут в месяц оплачивается B рублей, "
    "а разговоры сверх установленной нормы оплачиваются из расчета C рублей за минуту. "
    "Найти величину оплаты за T минут разговоров в месяц при заданных  значениях A,B,C. \n"

    "3. Написать программу, в которой вводятся два действительных числа x и y и номер арифметического действия, "
    "которое следует выполнить над этими числами: 1 – сложение, 2 – вычитание, 3 – умножение, 4 – деление. "
    "В программе следует выполнить указанное действие и выдать результат. \n"

    "4. Дан массив a[N]. Элементы массива отсортированы в порядке возрастания. "
    "Используя метод двоичного поиска, найти в массиве элемент со значением key. "
    "Выдать индекс найденного элемента или -1, если такого элемента в массиве нет. "
    "Если таких элементов несколько, выдать индекс первого из них.  "
    "Количество и значения элементов массива и значение искомого элемента key ввести с клавиатуры. "
    "Ограничения: N<=100, диапазон значений элементов [-50; 50], тип элементов – целые. \n"

    "5.Дана прямоугольная матрица b[M][N]. Определить индекс строки, "
    "среднее арифметическое элементов которой максимально. "
    "Если таких строк несколько, то выдать наименьший из их индексов. "
    "Элементы матрицы задать с помощью генератора случайных чисел. "
    "Значения  M, N ввести с клавиатуры. Ограничения: M<=10, N<=10, "
    "значения элементов из диапазона [-20; 20]. \n"
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
    printf("Вычисление площади треугольника.\nВведите через пробел длины двух сторон треугольника (см): ");
    scanf("%lf%lf", &longA, &longB); //qualifier %lf for double
    printf("Введите величину угла между этими сторонами: ");
    scanf("%lf", &angleAB); 

    AreaT = 0.5 * longA * longB * sin(angleAB * M_PI / 180); // 1/2ABsin(alpha), Angle degrees to radians * pi / 180
    printf("Площадь треугольника: %lf кв.см.", AreaT);
}

void PayPhone()
{
    double Limit, PriceB, PriceC, Time;
    printf("Вычисление стоимости разговора.\nВведите лимит разговоров по сниженной цене в минутах: ");
    scanf("%lf", &Limit);
    printf("Введите стоимость минуты разговора до лимита: ");
    scanf("%lf", &PriceB);
    printf("Введите стоимость минуты разговора после лимита: ");
    scanf("%lf", &PriceC);
    printf("Введите время разговора: ");
    scanf("%lf", &Time);
    if (Limit > Time) //if talk time exceeds the limit
    {
        printf("стоимость разговора: %lf", Time * PriceB);
    }else
    {
        printf("стоимость разговора: %0.*lf", 2, Limit * PriceB + (Time - Limit) * PriceC); //modifier output with arg *
    }
}

void Calc()
{
    double NumA, NumB, ans;
    short choice;
    printf("Введите 2 дейсвительных числа через пробел: ");
    scanf("%lf%lf", &NumA, &NumB);
    printf("Выберите действие 1 – сложение, 2 – вычитание, 3 – умножение, 4 – деление: ");
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
    printf("Ответ: %lf", ans);
}

void Search()
{
    int SearchMas[100], count;
    printf("Введите количество элементов массива: ");
    do{
        scanf("%d", &count);
        if (count > 100)
            printf("Количество элементов в массиве должно быть <=100");
    }while (count >= 100 || count <= 0);
    printf("Введите %d элементов массива\n", count);

    for (int i = 0; i < count; i++){
        do{
            scanf("%d", &SearchMas[i]);
            if (SearchMas[i] > 50 || SearchMas[i] < -50)
                printf("Элемент массива должен быть [-50; 50]\n");
        }while (SearchMas[i] > 50 || SearchMas[i] < -50);
    }
    
    printf("Массив из %d элементов: \n", count);
    for (int i = 0; i < count; i++) printf("%d ", SearchMas[i]);

    int first = 0, last = count, key, it = 0;
    printf("\nВведите искомое значение: ");
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
        printf("Индекс искомого элемента: %d, найден за %d итераций", last, it);
    } else
        printf("Индекс искомого элемента: %d", -1);
}

void Average()
{
    int AveMass[10][10], m, n;
    srand(time(0));
    printf("Введите размер прямоугольной матрицы: ");
    do{
        scanf("%d%d", &m, &n);
        if ((m <= 0 || m > 10) && (n <= 0 || n > 10))
            printf("Неверно задан размер матрицы");
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
    printf("Среднее арифметическое элементов максимально в %d строке", index + 1);
}