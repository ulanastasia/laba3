#include <iostream>
#include <vector>
#include <sstream>
#include <cassert>
using namespace std;

char Scale[] = "KFC";
struct temperature
{
    char scale;
    double temp;
};

istream &operator>>(istream& stream, temperature& temp)
{
    cout << "Vvedite temperatyry";
    stream >> temp.temp >> temp.scale;
    return stream;
}

void test_temperature_input()
{
    temperature tempr;
    istringstream issK("10K");
    issK>>tempr;
    assert (tempr.temp == 10);
    assert (tempr.scale == 'K');
    istringstream issF("10F");
    issF>>tempr;
    assert (tempr.temp = 10);
    assert (tempr.scale == 'F');
    istringstream issC("10C");
    issC>>tempr;
    assert (tempr.temp == 10);
    assert (tempr.scale =='C');
}
double convert (double input,char from,char to)
{
    if (tempr.scale=='F')

}

int
main()
{

    temperature tempr;
    cin>>tempr;10k
    cout<<tempr.temp;
    cout<<tempr.scale;

    c
    tempr.temp = convert(tempr.temp,tempr.scale,'c')
    tempr.scale = 'c'



    size_t number_count;
    cerr << "Enter number count: ";
    cin >> number_count;

    cerr << "Enter numbers: ";
    vector<double> numbers(number_count);
    for (size_t i = 0; i < number_count; i++) {
        cin >> numbers[i];
    }

    size_t column_count;
    cerr << "Enter column count: ";
    cin >> column_count;

    double min = numbers[0];
    double max = numbers[0];
    for (double number : numbers) {
        if (number < min) {
            min = number;
        }
        if (number > max) {
            max = number;
        }
    }

    vector<size_t> counts(column_count);
    for (double number : numbers) {
        size_t column = (size_t)((number - min) / (max - min) * column_count);
        if (column == column_count) {
            column--;
        }
        counts[column]++;
    }

    const size_t screen_width = 80;
    const size_t axis_width = 4;
    const size_t chart_width = screen_width - axis_width;

    // Можно было бы считать в предыдущем цикле, но так более наглядно.
    size_t max_count = 0;
    for (size_t count : counts) {
        if (count > max_count) {
            max_count = count;
        }
    }
    const bool scaling_needed = max_count > chart_width;

    for (size_t count : counts) {
        if (count < 100) {
            cout << ' ';
        }
        if (count < 10) {
            cout << ' ';
        }
        cout << count << "|";

        size_t height = count;
        if (scaling_needed) {
            // Point: код должен быть в первую очередь понятным.
            const double scaling_factor = (double)chart_width / max_count;
            height = (size_t)(count * scaling_factor);
        }

        for (size_t i = 0; i < height; i++) {
            cout << '*';
        }
        cout << '\n';
    }

    return 0;
}