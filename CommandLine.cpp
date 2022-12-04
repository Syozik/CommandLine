/* File CommandLine.cpp
Командний рядок
Зробив Рубанський Сергій
група комп'ютерна математика 2
*/

#include "../CommandLine_CPP/CommandLine.h"

void func1(int argc, string argv[]){
    ofstream file;
    file.open(output_filename, ios::app);
    cout << "\n1) ";
    file << "\n1) ";
    if (argc == 1){
        string s = argv[0];
        int x = stof(s);
        cout << x*x;
        file << x*x;
    }
    else{
        cout << "Error.";
        file << "Error.";
    }
    file.close();
}

void func2(int argc, string argv[]){
    ofstream file;
    file.open(output_filename, ios::app);
    cout << "\n2) ";
    file << "\n2) ";
    if (argc == 3){
        float a[3] = {};
        float res = 0;
        for (int i = 0; i<3; i++){
            string s = argv[i];
            a[i] = stof(s);
            if (a[i] == 0){
                cout << "Error. Here is 0.";
                file << "Error. Here is 0.";
                return;
            }
            res += 1/a[i];
        }
        res = 3/res;
        cout << res;
    }
    else{
        cout << "Error.";
        file << "Error.";
    }
    file.close();
}
void func3(int argc, string argv[]){
    ofstream file;
    file.open(output_filename, ios::app);
    cout << "\n3) ";
    file << "\n3) ";
    if (argc != 1){
        cout << "Error.";
        file << "Error.";
        return;
    }
    char *str = new char [1024];
    int i=0;
    ifstream base(argv[0]);
    while (!base.eof())
    {
        base.getline(str, 1024, '\n');
        i++;
    }
    base.close();
    delete str;
    cout << i << '\n';
    file.close();
}
void func4(int argc, string argv[]){\
    ofstream file;
    file.open(output_filename, ios::app);
    cout << "\n4) ";
    file << "\n4) ";
    if (argc == 0){
        cout << "Error.";
        file << "Error.";
        return;
    }
    float sum = 0;
    for (int i = 0; i<argc; i++){
        float res = 0;
        int j = 0;
        ifstream base(argv[i]);
        string line;
        while (getline(base, line))
        {
            res += line.length();
            j += 1;
        }
        res /= j;
        sum += res;
        base.close();
        cout << argv[i] << " " << res << endl; 
    }
    sum /= argc;
    cout << sum;
    file.close();
}
void func5(int argc, string argv[]){
    ofstream file;
    file.open(output_filename, ios::app);
    cout << "\n5) ";
    file << "\n5) ";
    if (argc != 4){
        cout << "Error. Input a line like this: -filename name -rows rows";
        file << "Error. Input a line like this: -filename name -rows rows";
    }
    else{
        int j =0;
        string t1 = "-filename";
        string t2 = "-rows";
        if (t1.compare(argv[0]) != 0 || t2.compare(argv[2]) != 0){
            cout << "Error. Input a line like this: -filename name -rows rows";
            file << "Error. Input a line like this: -filename name -rows rows";
        }
        else{
            ofstream base(argv[1],ios::binary);
            string s = argv[3];
            int rows;
            rows = stof(s);
            for (int i = 0; i < rows; i++){
                base << i << "\n";
            }
            cout << "Created successfully";
            file << "Created successfully";
            base.close();
        }
    }
    file.close();
}

void func6(int argc, string argv[]){
    ofstream file;
    file.open(output_filename, ios::app);
    cout << "\n6) ";
    file << "\n6) ";
    if (argc != 6){
        cout << "Error. Input a line like this: -filename name -rows rows -cols cols";
        file << "Error. Input a line like this: -filename name -rows rows -cols cols";
    }
    else{
        int j =0;
        string t1 = "-filename";
        string t2 = "-rows";
        string t3 = "-cols";
        if (t1.compare(argv[0]) != 0 || t2.compare(argv[2]) != 0 || t3.compare(argv[4]) != 0){
            cout << "Error. Input a line like this: -filename name -rows rows -cols cols";
            file << "Error. Input a line like this: -filename name -rows rows -cols cols";
        }
        else{
            ofstream base(argv[1]);
            string s = argv[3];
            string t = argv[5];
            int rows, cols;
            rows = stof( s);
            cols = stof( t);
            for (int i = 0; i < rows; i++){
                for (int j = 0; j < cols; j++)
                    base << "0" << "\t";
                base << endl;
            }
            cout << "Created successfully";
            file << "Created successfully";
            base.close();
            
        }
    }
    file.close();
}

void func7(int argc, string argv[]){
    ofstream file;
    file.open(output_filename, ios::app);
    cout << "\n7) ";
    file << "\n7) ";
    if (argc != 6 && argc != 4){
        cout << "Error. Input a line like this: -filename1 name1 -filename2 name2 -rows rows. -rows is optional argument";
        file << "Error. Input a line like this: -filename1 name1 -filename2 name2 -rows rows. -rows is optional argument";
    }
    else{
        int j =0;
        string t1 = "-filename1";
        string t2 = "-filename2";
        string t3 = "-rows";
        if (t1.compare(argv[0]) != 0 || t2.compare(argv[2]) != 0){
            cout << "Error. Input a line like this: -filename1 name1 -filename2 name2 -rows rows. -rows is optional argument";
            file << "Error. Input a line like this: -filename1 name1 -filename2 name2 -rows rows. -rows is optional argument";    
        }
        else{
            bool is_rows = (argc == 6);
            if (is_rows){
                if (t3.compare(argv[4]) != 0){
                    cout << "Error. Input a line like this: -filename1 name1 -filename2 name2 -rows rows. -rows is optional argument";
                    file << "Error. Input a line like this: -filename1 name1 -filename2 name2 -rows rows. -rows is optional argument";
                    return;

                }
            }
            ifstream base1(argv[1]);
            ifstream base2(argv[3]);
            int rows = 0;
            if (is_rows){
                string t = argv[5];
                rows = stof(t);
            }
            string s1, s2;
            int i = 0;
            while (getline(base1, s1) && getline(base2, s2)){
                i += 1;
                if (s1.compare(s2) != 0){
                    cout << "False";
                    file << "False";
                    base1.close();
                    base2.close();
                    return;
                }
                if (is_rows){
                    if (rows == i){
                        cout << "True";
                        file << "True";
                        base1.close();
                        base2.close();
                        return;
                    }
                }
            }
            if (getline(base1, s1) || getline(base2, s2)){
                cout << "False";
                file << "False";
            }
            else{
                cout << "True";
                file << "True";
            }
            base1.close();
            base2.close();
        }
    }
    file.close();
}

void run(int numb, int argc, string argv[]){
    switch (numb){
        case 1:
            func1(argc, argv);
            break;
        case 2:
            func2(argc, argv);
            break;
        case 3:
            func3(argc, argv);
            break;
        case 4:
            func4(argc, argv);
            break;
        case 5:
            func5(argc, argv);
            break;
        case 6:
            func6(argc, argv);
            break;
        case 7:
            func7(argc, argv);
            break;
    }
}
void parse(int numb, string s){
    
    s.push_back(' ');
    string argv[s.length()];
    int j = 0;
    int k = 0;
    cout << "Words: \n" ;
    for (int i=0;i<s.length(); i++){
        if (s[i] == ' '){
            argv[k] = s.substr(j, i-j);
            k++;
            j = i+1;
            cout << argv[k-1] << " " << endl;
        }
    }
    int argc = k;
    // run(numb, argc, argv);
}

int main(){
    string s;
    getline(cin, s);
    parse(1, s);
}