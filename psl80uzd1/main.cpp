#include <iostream>
#include <fstream>


using namespace std;

void searchmin(int inpArr[], int &minNum, int &minInd, int n){
    bool flag;
    for (int i = 0; i < n; i++){
        if(inpArr[i] > 0 && !flag){
            minNum = inpArr[i];
            minInd = i;
            flag = 1;
        }
        else{
            continue;
        }
        if((inpArr[i] <= 0) && (minNum > inpArr[i])){
            minNum = inpArr[i];
            minInd = i;
        }
    }
}

int main()
{
    int minNum, minInd;
    int n1, n2, dropped;
    int flag2;
    dropped = 0;
    ifstream in("inp.txt");
    in >> n1;
    int a[n1];
    for (int i = 0; i < n1; i++){
        in >> a[i];
        cout << a[i] << " ";
    }
    cout << endl;
    in >> n2;
    int b[n2];
    for (int i = 0; i < n2; i++){
        in >> b[i];
        cout << b[i] << " ";
    }
    cout << endl << endl;
    int c[(n1 * n2 + 1)];
    for (int i = 0; i < n1; i++){
        c[i] = a[i];
    }
    for (int i = 0; i < n2; i++){
        searchmin(b, minNum, minInd, n2);
        b[minInd] = -1;
        cout << minNum << " ";
        cout << minInd <<  endl;
        dropped--;
        for (int j = 0; j < n1; j++){
            if((minNum % a[j]) == 0){
                cout << "found divisor at " << j << endl;
                cout << "divisor: " << a[j] << endl;
                /*int currIndPrime = (n1 + i + dropped);
                while (currIndPrime != j){
                    cout << c[currIndPrime] << endl;
                    c[currIndPrime + 1] = c[currIndPrime];
                    currIndPrime--;
                }
                c[j+1] = minNum;
                cout << "tmp c: ";
                for (int i = 0; i < (n1 + n2 + dropped); i++){
                    cout << c[i] << " ";
                }
                cout << endl;
                dropped++;
                cout << dropped << " dropped" << endl;*/
                int k = 0;
                while (a[j] != c[k]){
                    k++;
                }
                cout << "div2 found at " << k << endl;
                int currIndPrime = (n1 + i + dropped);
                while (currIndPrime != k){
                    cout << c[currIndPrime] << endl;
                    c[currIndPrime + 1] = c[currIndPrime];
                    currIndPrime--;
                }
                cout << c[currIndPrime] << endl;
                c[j+1] = minNum;
                cout << "tmp c: ";
                for (int i = 0; i < (n1 + n2 + dropped); i++){
                    cout << c[i] << " ";
                }
                cout << endl;
                dropped++;
                cout << dropped << " dropped" << endl;
            }
        }

        if (flag2 < 0){
            cout << "no div found " << endl;
        }
        cout << "curr c: ";
        for (int i = 0; i < (n1 + n2 + dropped); i++){
            cout << c[i] << " ";
        }
        cout << endl << endl;
    }
    cout << endl;
    for (int i = 0; i < (n1 + n2 + dropped); i++){
        cout << c[i] << " " << endl;
    }

    return 0;
}


