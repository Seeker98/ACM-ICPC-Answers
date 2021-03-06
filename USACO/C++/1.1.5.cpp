/*
ID: lxdlam1
PROG: beads
LANG: C++11
*/

#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream fin("beads.in");
    ofstream fout("beads.out");

    int length, numMaxbeads = 0, i, left, right, j, flag = 1, m;
    string necklace;
    fin >> length >> necklace;
    necklace += necklace;
    for (i = 0; i < 2 * length; i++)
    {
        numMaxbeads++;
        if (necklace[i] != necklace[i + 1] && necklace[i + 1] != 0)
        {
            numMaxbeads = flag = 0;
            break;
        }
    }
    for (i = 0; i < 2 * length; i++)
    {
        if (necklace[i] == necklace[i + 1])
            continue;
        else if (necklace[i + 1] == '\0')
            break;
        else if (flag)
            break;
        left = right = 0;
        m = i;
        while (necklace[m] == 'w' && m > 0)
        {
            m--;
        }
        for (j = i;; j--)
        {
            if (necklace[j] == necklace[m])
                left++;
            else if (necklace[j] == 'w')
                left++;
            else
                break;
        }
        m = i + 1;
        while (necklace[m] == 'w' && m < length)
        {
            m++;
        }
        for (j = i + 1;; j++)
        {
            if (necklace[j] == necklace[m])
                right++;
            else if (necklace[j] == 'w')
                right++;
            else
                break;
        }
        numMaxbeads = (left + right) > numMaxbeads ? (left + right) : numMaxbeads;
    }
    if (numMaxbeads >= length)
        fout << length << endl;
    else
        fout << numMaxbeads << endl;

    fin.close();
    fout.close();
    return 0;
}