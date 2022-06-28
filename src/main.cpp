#include <iostream>
#include <fstream>


using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    const int size = 10;     //Размер массива
    int M;                   //Номер элемента преобразованного массива, на который мы и будеи делить положительные элементы этого массива.
    int N;                   //Количесство первых элементов, среди которых и ищем максимальный отрицательный элемент
    int i = 0;               //Счетчик циклов
    int max_neg_i[size];     //номера максимального отрицательного числа из первых N элементов преобразованного массива
    double VEC[size];        //Имя исходного массива
    double NEWVEC[size];     //Имя нового массива
    double sum;              //Сумма нечетных элементов преобразованного массива   
    double max_neg;          //Максимальный отрицательный элемент из первых N элементов преобразованного массива   
    double del;              //Делитель
    double temp;             //Временная переменная для хранения данных
    bool max_N = false;      //Метка, говорящая нам о том, найден ли хотя бы 1 отрицательный элемент из первых N элементов
    string f_name;           //переменная, в которой хранится имя открываемого файла. 
    //f_name = "input_ERR_404.txt";
    f_name = "input.txt";
    //f_name = "input1.txt";
    //f_name = "input2.txt";
    //f_name = "input3.txt";
    //f_name = "input4.txt";
    //f_name = "input5.txt";
    //f_name = "input6.txt";
    //f_name = "input7.txt";
    //f_name = "input8.txt";
    //f_name = "input9.txt";
    //f_name = "input10.txt";
    ifstream ifs(f_name);    //Открываем файл


    /***************************************************
    ОТКРЫТИЕ ФАЙЛА И ПРОВЕРКА ЕГО НА КОРРЕКТНОСТЬ ДАННЫХ
    ***************************************************/
    if (!ifs)                                                //Проверка открытия файла
    {
        cout << "Ошибка открытия файла." << endl;
        exit(1);
    }//Конец if

    while (!ifs.eof()) {                                     //проверка содержания файла
        ifs >> temp;

        if (ifs.fail()) {
            if (temp) {
                cout << "Файл пуст." << endl;
                ifs.close();
                exit(2);
            }
            else {
                cout << "Обнаружены некорректные символы.\nПроверьте исходный файл с данными " << f_name << endl;
                ifs.close();
                exit(2);
            }
        }
        i++;
    }
    ifs.seekg(0, ios::beg);                                  //Возращение в начало файла

   /***********************************
   ---ВВОД ДАННЫХ И ВХОДНОЙ КОНТРОЛЬ---
   ***********************************/
    if (i != size + 2) {
        if (i == 2) {
            cout << "Где массив, жмотяра?" << endl;
            exit(3);
        }
        cout << "Неверное количество элементов в файле" << endl;
        exit(3);
    }
    ifs >> M;
    M = M - 1;
    if (M < 0 || M >= size) {
        cout << "M д.б. целым положительным числом, которое меньше либо равно размеру массивов." << endl;
        exit(1);
    }//Конец if
    ifs >> N;
    N = N - 1;
    if (N < 0 || N >= size) {
        cout << "N д.б. целым положительным числом, которое меньше либо равно размеру массивов. " << endl;
        exit(1);
    }//Конец if
    cout << "M = " << M + 1 << "\nN = " << N + 1 << endl;
    cout << "Исходный массив:" << endl;
    for (i = 0; i < size; i++)                                 //Считываем массив и задаем новый
    {
        ifs >> VEC[i];
        NEWVEC[size - i - 1] = VEC[i];
        cout << VEC[i] << " ";
    }
    cout << endl;
    if (NEWVEC[M] == 0) {
        cout << "Делить на ноль не стоит..." << endl;
        exit(-1);
    }//Конец if
    del = NEWVEC[M];
    ifs.close();                                            //Закрываем файл
    cout << endl << "Преобразованный массив" << endl;
    max_neg = 0;
    int b = 0;
    for (i = 0; i < size; i++)                                 //Преобразуем новый массив
    {
        if (NEWVEC[i] >= 0) {
            NEWVEC[i] /= del;
        }
        else if (i < N && (max_neg <= NEWVEC[i] || !max_N)) // и ищем максимальное отрицательное среди первых N
        {
            max_N = true;
            max_neg = NEWVEC[i];
        }//Конец if else if
        cout << NEWVEC[i] << " ";
    }
    cout << endl;
    sum = 0;
    for (i = 1; i < size; i += 2)                              //Считаем сумму элементов с нечетными номерами
    {
        sum += NEWVEC[i];
    }
    cout << "\nsum: " << sum << endl;
    if (max_N) {
        cout << "max_neg = " << max_neg << endl;
        for (i = 0; i < N; i++) {
            if (max_neg == NEWVEC[i]) {
                max_neg_i[b] = i;
                cout << "\nmax_neg_" << b << " = " << max_neg_i[b] << endl;
                b++;
            }
        }
    }
    else {
        cout << "Отрицательных элементов в заданой зоне не обнаружено." << endl;
    }//Конец if else
    return 0;
}