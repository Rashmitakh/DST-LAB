/*
10 Given a File of N employee records with a set K of Keys(4-
digit) which uniquely determine the records in file F.
Assume that file F is maintained in memory by a Hash
Table (HT) of m memory locations with L as the set of
memory addresses (2-digit) of locations in HT. Let the keys
in K and addresses in L are integers.
Design and develop a Program in C that uses Hash
function H: K -> L as H(K)=K mod m (remainder method),
and implement hashing technique to map a given key K to
the address space L.
Resolve the collision (if any) using linear probing.
*/

#include <stdio.h>

#define MAX 20

int main() {
    int HT[MAX];
    int N, m, key;

    for (int i = 0; i < MAX; i++)
        HT[i] = -1; // empty slot

    printf("Enter number of keys: ");
    scanf("%d", &N);

    printf("Enter size of hash table: ");
    scanf("%d", &m);

    for (int i = 0; i < N; i++) {
        printf("Enter key %d: ", i + 1);
        scanf("%d", &key);

        int index = key % m;

        // Linear probing for collision
        int originalIndex = index;
        while (HT[index] != -1) {
            index = (index + 1) % m;
            if (index == originalIndex) {
                printf("Hash table is full!\n");
                break;
            }
        }
        HT[index] = key;
    }

    printf("Hash Table:\n");
    for (int i = 0; i < m; i++) {
        if (HT[i] != -1)
            printf("HT[%d] = %d\n", i, HT[i]);
        else
            printf("HT[%d] = -\n", i);
    }

    return 0;
}

/*
Sample Output:
Enter number of keys: 5
Enter size of hash table: 10
Enter key 1: 1001
Enter key 2: 1012
Enter key 3: 1023
Enter key 4: 1034
Enter key 5: 1045
Hash Table:
HT[0] = 1001
HT[1] = 1012
HT[2] = 1023
HT[3] = 1034
HT[4] = 1045
HT[5] = -
HT[6] = -
HT[7] = -
HT[8] = -
HT[9] = -
*/
