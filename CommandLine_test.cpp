/* File CommandLine.cpp
Командний рядок
Зробив Рубанський Сергій
група комп'ютерна математика 2
*/

#include "CommandLine.cpp"

int main(){
    cout << "Input from console: \n";
    string c,s, input_filename, output_filename;
    cout << "Do you want to input data? (Y) or (N): ";
    cin >> c;
    output_filename = "CommandLine_output.data";
    while (c == "Y"){
        char n;
        cout << "Select the number of function(1-7): ";
        cin >> n;
        cin.get();
        int numb = n - '0'; 
        cout << "Input the line:\n";
        getline(cin, s);
        parse(numb, s);
        
        cout << "\nDo you want to input data? (Y) or (N): ";
        cin >> s;
    }
    input_filename = "CommandLine_testdata.txt";
    cout << "Input from testfile " << input_filename;
    ifstream file(input_filename);
    while (getline(file, s)){
        char n = s[0];
        int numb = n - '0';
        if (s.length() > 3)
            s = s.substr(2);
        else
            continue;
        cout << "\n-----------\nfunction number " << numb << ".The line: " << s << endl;
        parse(numb, s);
    }
}