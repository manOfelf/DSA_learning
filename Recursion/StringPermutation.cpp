#include <iostream>
#include <string>
using namespace std;

// T.C. O(Time to print 1 Permutation * No. of Permutations)
void Permutations(string str, int l, int r)
{
    if (l == r)
        cout << str << endl;
    else
    {
        for (int i = l; i <= r; i++)
        {
            swap(str[i], str[l]); // making combinations

            Permutations(str, l + 1, r); // performing same operation for rest of the string

            swap(str[i], str[l]); // recovering swapped string by backtraching
        }
    }
}

int main()
{
    Permutations("ABC", 0, 2);
}
//INPUT : ABC
//OUTPUT : ABC ACB BAC BCA CAB CBA
