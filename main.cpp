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
            //cout << minNum << " min" << endl;
        }
        else{
            continue;
        }
        if((inpArr[i] <= 0) && (minNum > inpArr[i])){
            minNum = inpArr[i];
            minInd = i;
        }
    }
    //cout << minNum << "lmaaoooo " << endl;
}

int main()
{
    int minNum, minInd;
    int n1, n2, tempInt, tempInd, tempReloc, dropped;
    bool flag2;
    dropped = 0;
    ifstream in("inp.txt");
    in >> n1;
    int a[n1];
    int divisors[n1][2];
    for (int i = 0; i < n1; i++){
        in >> a[i];
        divisors[i][0] = a[i];
        divisors[i][1] = 0;
        cout << a[i] << " ";
    }
    cout << endl;
    in >> n2;
    int b[n2];
    for (int i = 0; i < n2; i++){
        in >> b[i];
        cout << b[i] << " ";
    }
    cout << endl;
    int c[(n1 + n2 + 1)];
    for (int i = 0; i < n1; i++){
        c[i] = a[i];
        //cout << c[i] << " ";
    }
    for (int i = 0; i < n2; i++){
        searchmin(b, minNum, minInd, n2);
        b[minInd] = -1;
        cout << minNum << " ";
        cout << minInd << endl;
        flag2 = 1;
        for (int j = 0; j < n1; j++){
            cout << minNum % a[j] << " div leftovers" << endl;
            if((minNum % a[j]) == 0){
                cout << j << " a index" << endl;
                divisors[j][1]++;
                for (int k = (n1 + i + dropped); k > (j + 1 + divisors[j][i]); k--){
                    c[k + 1] = c[k];
                }
                c[j+1] = minNum;
                flag2 = 0;
                break;
            }
        }
        if (flag2){
            dropped--;
        }
    }
    for (auto x: c){
        cout << x << " " << endl;
    }

    return 0;
}


