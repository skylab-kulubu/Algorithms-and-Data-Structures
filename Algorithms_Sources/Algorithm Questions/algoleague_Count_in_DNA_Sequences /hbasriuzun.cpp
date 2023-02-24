#include <bits/stdc++.h>
using namespace std;
// You are given a DNA sequence, called S, in a length of N. You can think of these DNA sequences as strings composed of Adenine (A), Guanine (G), Cytosine (C), and Thymine (T). As we know from Biology courses, Adenine is the counterpart of Thymine, while Guanine is Cytosine's correspondence. How many (i,j,k) triples 1≤i≤j≤k≤N, in this DNA sequence, such that Si=A,Sj=T,Sk=A or Si=G,Sj=C,Sk=G ?
int main(){
    string S;
    cin >> S;
    int N = S.length();
    int A[N], T[N], G[N], C[N];
    for(int i = 0; i < N; i++){
        A[i] = 0;
        T[i] = 0;
        G[i] = 0;
        C[i] = 0;
    }
    for(int i = 0; i < N; i++){
        if(S[i] == 'A'){
            A[i] = 1;
        }
        else if(S[i] == 'T'){
            T[i] = 1;
        }
        else if(S[i] == 'G'){
            G[i] = 1;
        }
        else if(S[i] == 'C'){
            C[i] = 1;
        }
    }
    for(int i = 1; i < N; i++){
        A[i] += A[i-1];
        T[i] += T[i-1];
        G[i] += G[i-1];
        C[i] += C[i-1];
    }
    int count = 0;
    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            if(S[i] == 'A' && S[j] == 'T'){
                count += A[j-1] - A[i];
            }
            else if(S[i] == 'G' && S[j] == 'C'){
                count += G[j-1] - G[i];
            }
        }
    }
    cout << count << endl;
}